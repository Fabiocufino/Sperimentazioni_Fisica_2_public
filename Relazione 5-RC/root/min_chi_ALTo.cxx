#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include <fstream>
#include <cmath>
#include "TFitResult.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TGraphErrors.h"
#include "TLatex.h"
#include <vector>
#ifndef DATACLASS
#include "../Programmi/dataclass.h"
#include "root_function.h"
#endif

using namespace std;
using json = nlohmann::json;

double func(double *x, double *par)
{

    double a = par[0];
    double b = par[1];
    double c = par[2];

    double ret = a + b * x[0] + c * x[0] * x[0];
    return ret;
}

void min_chi_ALTo()
{
    vector<double> chi_trasf, chi_sfas;
    vector<double> freq_trasf, freq_sfas;
    compute_minimization_from_json("../Json/", "min_chi_passa_alto.json", freq_trasf, chi_trasf);
    compute_minimization_from_json("../Json/", "min_chi_passa_alto_sfasamento.json", freq_sfas, chi_sfas);

    TVectorD root_freq_trasf(freq_trasf.size(), freq_trasf.data());
    TVectorD root_chi_trasf(chi_trasf.size(), chi_trasf.data());
    TVectorD root_freq_sfas(freq_sfas.size(), freq_sfas.data());
    TVectorD root_chi_sfas(chi_sfas.size(), chi_sfas.data());

    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->SetGrid();
    c1->SetFillColor(0);

    TGraph *grafico = new TGraph(root_freq_trasf, root_chi_trasf);
    grafico->SetMarkerColor(kAzure - 3);
    grafico->SetMarkerStyle(20);
    grafico->SetMarkerSize(0.4);
    grafico->SetTitle("Minimizzazione chi quadro");
    grafico->GetXaxis()->SetTitle("Frequenza [kHz]");
    grafico->GetYaxis()->SetTitle("#Delta#chi^{2}");
    grafico->GetXaxis()->SetAxisColor(14);
    grafico->GetYaxis()->SetAxisColor(14);
    grafico->Draw("AP");

    TF1 *f1 = new TF1("f1", func, 5.9, 6.05, 3);
    f1->SetLineColor(kRed);
    f1->SetLineStyle(2);
    f1->SetLineWidth(2);

    fit_results chi_results;
    fit_on_json(f1, 3, grafico, freq_trasf, chi_trasf, chi_results, "../Fit_results", "min_chi_passa_alto.json", 5.9, 6.05);

    double x_min2 = (-f1->GetParameter(1) / (2 * f1->GetParameter(2)));
    cout << "Trasferimento: " << x_min2 << endl;

    double chi_one = 1 + (f1->GetParameter(0) + f1->GetParameter(1) * x_min2 + f1->GetParameter(2) * pow(x_min2, 2));
    TLine *tr = new TLine(5.85, chi_one, 6.05, chi_one);
    tr->SetLineColor(kRed);
    tr->Draw("same");

    TLine *mint = new TLine(x_min2, 28, x_min2, chi_one);
    mint->SetLineColor(kAzure - 3);
    mint->SetLineStyle(2);
    mint->SetLineWidth(2);
    mint->Draw("same");

    TLatex latex;
    latex.SetTextSize(0.025);
    latex.SetTextAlign(13); //align at top
    latex.DrawLatex(6, 100, "#Delta#chi^{2}+1");
    latex.DrawLatex(6, 150, "f_{taglio} #approx 6.10");

    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico, "Dati #chi^{2}", "PE");
    legend->AddEntry(f1, "a + bx +cx^{2} interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    TPaveStats *ptstats;
    TText *ptstats_LaTex;
    informazioni_fit_parabolico(ptstats, ptstats_LaTex, to_string(f1->GetChisquare()), to_string((int)f1->GetNDF()), to_string(f1->GetParameter(0)), to_string(f1->GetParError(0)), to_string(f1->GetParameter(1)), to_string(f1->GetParError(1)), to_string(f1->GetParameter(2)), to_string(f1->GetParError(2)), "Trasferimento");

    //-----------------------------------------------------------------------------------------------------------------------------------
    TCanvas *c2 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    c2->SetGrid();
    c2->SetFillColor(0);

    TGraph *grafico1 = new TGraph(root_freq_sfas, root_chi_sfas);
    grafico1->SetMarkerColor(kGreen);
    grafico1->SetMarkerStyle(20);
    grafico1->SetMarkerSize(0.4);
    grafico1->SetTitle("Minimizzazione chi quadro");
    grafico1->GetXaxis()->SetTitle("Frequenza [kHz]");
    grafico1->GetYaxis()->SetTitle("Chi quadro");
    grafico1->GetXaxis()->SetAxisColor(14);
    grafico1->GetYaxis()->SetAxisColor(14);
    grafico1->Draw("AP");

    TF1 *f2 = new TF1("f2", func, 5.94, 6.02, 3);
    f2->SetLineColor(kRed);
    f2->SetLineStyle(2);
    f2->SetLineWidth(2);

    fit_results chi_results_sfas;
    fit_on_json(f2, 3, grafico1, freq_sfas, chi_sfas, chi_results_sfas, "../Fit_results", "min_chi_passa_alto_sfasamento.json", 5.94, 6.02);

    double x_min = (-f2->GetParameter(1) / (2 * f2->GetParameter(2)));

    double chi_two = 1 + (f2->GetParameter(0) + f2->GetParameter(1) * x_min + f2->GetParameter(2) * pow(x_min, 2));
    TLine *min = new TLine(5.94, chi_two, 6.02, chi_two);
    min->SetLineColor(kRed);
    min->Draw("same");

    TLine *mint1 = new TLine(x_min, 280, x_min, chi_two);
    mint1->SetLineColor(kGreen);
    mint1->SetLineStyle(2);
    mint1->SetLineWidth(2);
    mint1->Draw("same");

    TLatex latex1;
    latex1.SetTextSize(0.025);
    latex1.SetTextAlign(13); //align at top
    latex1.DrawLatex(6, 400, "#Delta#chi^{2}+1");
    latex1.DrawLatex(6, 500, "f_{taglio} #approx 6.031");

    TLegend *legend2 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend2->AddEntry(grafico1, "Dati #chi^{2}", "PE");
    legend2->AddEntry(f1, "a + bx +cx^{2} interpolante", "l");
    legend2->SetTextSize(0.04);
    legend2->SetBorderSize(1);
    legend2->SetTextFont(22);
    legend2->Draw();

    TPaveStats *ptstats2;
    TText *ptstats_LaTex2;
    informazioni_fit_parabolico(ptstats2, ptstats_LaTex2, to_string(f2->GetChisquare()), to_string((int)f2->GetNDF()), to_string(f2->GetParameter(0)), to_string(f2->GetParError(0)), to_string(f2->GetParameter(1)), to_string(f2->GetParError(1)), to_string(f2->GetParameter(2)), to_string(f2->GetParError(2)), "Sfasamento");
}
