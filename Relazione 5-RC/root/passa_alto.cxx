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
#include "TGaxis.h"
#include <vector>
#ifndef DATACLASS
#include "../Programmi/dataclass.h"
#include "root_function.h"
#endif

using namespace std;
using json = nlohmann::json;

double func_trasferimento(double *x, double *par)
{

    double a = par[0];

    double ret = 1 / sqrt(1 + pow(a / x[0], 2));
    return ret;
};

double func_sfasamento(double *x, double *par)
{

    double a = par[0];

    double ret = sqrt(pow(TMath::ATan(a / x[0]), 2)) / M_PI_2;
    return ret;
};

//double func_due(double *x, double *par)
//{
//
//    double a = par[0];
//    double b = par[1];
//
//    double ret = a + b * x[0];
//    return ret;
//}

void passa_alto()
{

    ac alto;
    alto.from_json("../Json/", "passa_alto.json");
    TVectorD root_freq(alto.freq.size(), alto.freq.data());
    TVectorD root_trasf(alto.trasf.size(), alto.trasf.data());
    vector<double> err_freq(alto.freq.size(), 0);
    TVectorD root_err_freq(err_freq.size(), err_freq.data());
    TVectorD root_err_trasf(alto.err_trasf.size(), alto.err_trasf.data());

    vector<double> sfasamento_normalizzato;
    vector<double> err_sfasamento_normalizzato;
    for (int i = 0; i < alto.sfasamento.size(); i++)
    {
        sfasamento_normalizzato.push_back(alto.sfasamento[i] / M_PI_2);
        err_sfasamento_normalizzato.push_back(alto.err_sfasamento[i] / M_PI_2);
    }
    TVectorD root_sfas(sfasamento_normalizzato.size(), sfasamento_normalizzato.data());
    TVectorD root_err_sfas(err_sfasamento_normalizzato.size(), err_sfasamento_normalizzato.data());
    //TVectorD root_err_sfas(alto.err_sfasamento.size(), alto.err_sfasamento.data());

    vector<double> vin_normalizzato;
    for (int i = 0; i < alto.vin.size(); i++)
    {
        vin_normalizzato.push_back(alto.vin[i] / 3.02);
    }
    TVectorD root_vin(vin_normalizzato.size(), vin_normalizzato.data());

    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->SetGrid();
    c1->SetFillColor(0);
    gPad->SetLogx();
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico = new TGraphErrors(root_freq, root_trasf, root_err_freq, root_err_trasf);
    grafico->SetMarkerColor(kAzure - 3);
    grafico->SetMarkerStyle(20);
    grafico->SetMarkerSize(0.5);
    grafico->SetTitle("Passa alto");
    grafico->GetXaxis()->SetTitle("Frequenza [kHz]");
    grafico->GetYaxis()->SetTitle("A [V_{out} / V_{in}]");
    grafico->GetXaxis()->SetAxisColor(14);
    grafico->GetYaxis()->SetAxisColor(14);
    grafico->GetXaxis()->SetLimits(0., 5.);
    grafico->Draw("AP");

    TGraphErrors *grafico_sfas = new TGraphErrors(root_freq, root_sfas, root_err_freq, root_err_sfas);
    grafico_sfas->SetMarkerColor(kGreen);
    grafico_sfas->SetMarkerStyle(20);
    grafico_sfas->SetMarkerSize(0.5);
    grafico_sfas->SetTitle("Passa alto");
    grafico_sfas->GetXaxis()->SetTitle("Frequenza [kHz]");
    grafico_sfas->GetYaxis()->SetTitle("Sfasamento [#Delta #phi]");
    grafico_sfas->GetXaxis()->SetAxisColor(14);
    grafico_sfas->GetYaxis()->SetAxisColor(14);
    grafico_sfas->GetXaxis()->SetLimits(0., 5.);
    grafico_sfas->Draw("Psame");

    TGraphErrors *grafico_vin = new TGraphErrors(root_freq, root_vin, root_err_freq, root_err_freq);
    grafico_vin->SetMarkerColor(kAzure);
    grafico_vin->SetMarkerStyle(20);
    grafico_vin->SetMarkerSize(0.7);
    grafico_vin->SetTitle("Passa alto");
    grafico_vin->GetXaxis()->SetTitle("");
    grafico_vin->GetYaxis()->SetTitle("");
    grafico_vin->GetXaxis()->SetAxisColor(14);
    grafico_vin->GetYaxis()->SetAxisColor(14);
    grafico_vin->GetXaxis()->SetLimits(0., 5.);
    grafico_vin->Draw("Psame");

    //TAxis *axis = grafico_sfas->GetXaxis();
    //axis->SetRangeUser(0, 20);

    TF1 *f1 = new TF1("f1", func_trasferimento, 0, 45, 1);
    f1->SetLineColor(kRed);
    f1->SetLineStyle(2);
    f1->SetLineWidth(2);

    f1->SetParameter(0, 5.9);

    TF1 *f2 = new TF1("f2", func_sfasamento, 0, 45, 1);
    f2->SetLineColor(kRed);
    f2->SetLineStyle(3);
    f2->SetLineWidth(2);

    f2->SetParameter(0, 10);

    fit_results alto_results_trasferimento;
    fit_results alto_results_sfasamento;
    fit_on_json(f1, 1, grafico, alto.freq, alto.trasf, alto_results_trasferimento, "../Fit_results", "passa_alto_trasferimento.json");

    fit_on_json(f2, 1, grafico_sfas, alto.freq, alto.sfasamento, alto_results_sfasamento, "../Fit_results", "passa_alto_sfasamento.json");

    TPaveStats *ptstats;
    TText *ptstats_LaTex;
    informazioni_fit_nl_1_param(ptstats, ptstats_LaTex, to_string(f1->GetChisquare()), to_string((int)f1->GetNDF()), to_string(f1->GetParameter(0)), to_string(f1->GetParError(0)), "Trasferimento");

    TPaveStats *ptstats1;
    TText *ptstats_LaTex1;
    informazioni_fit_nl_1_param(ptstats1, ptstats_LaTex1, to_string(f2->GetChisquare()), to_string((int)f2->GetNDF()), to_string(f2->GetParameter(0)), to_string(f2->GetParError(0)), "Sfasamento");

    //TGaxis *A1 = new TGaxis(110, 0, 110, 1., 0, 1, 3, "+RB");

    TGaxis *A1 = new TGaxis(110, 0., 110, 1., 0, 1, 410, "+U");

    A1->SetTitle("Sfasamento [#Delta#phi / #pi/2]");
    A1->ChangeLabel(-1, -1, -1, -1, -1, -1, "1");
    A1->ChangeLabel(1, -1, -1, -1, -1, -1, "0");
    A1->ChangeLabel(2, -1, -1, -1, -1, -1, "0.5");
    A1->SetLabelFont(42);
    A1->SetTitleFont(42);
    A1->SetLabelSize(0.03);
    A1->Draw();
    A1->SetLabelOffset(99);

    //LEGENDA

    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico, "Dati Trasferimento", "PE");
    legend->AddEntry(grafico_sfas, "Dati Sfasamento", "PE");
    legend->AddEntry(grafico_vin, "Dati V_{in}", "PE");
    legend->AddEntry(f1, "y = 1/ #sqrt{1 + (#frac{a}{x})^{2}} interpolante", "l");
    legend->AddEntry(f2, "y = ArcTan(#frac{a}{x})/(#pi/2)  interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    //------------------------------------------------------------------INIZIO RESIDUI-----------

    TCanvas *c2 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    c2->SetGrid();
    c2->SetFillColor(0);
    gPad->SetLogx();
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> scarti_trasf;
    run_test_passa_alto_trasf(scarti_trasf, alto.freq, alto.trasf, f1->GetParameter(0));
    TVectorD root_scarti(scarti_trasf.size(), scarti_trasf.data());

    TGraphErrors *grafico1 = new TGraphErrors(root_freq, root_scarti, root_err_freq, root_err_trasf); //, root_err_freq, root_err_);
    grafico1->SetMarkerColor(kAzure - 3);
    grafico1->SetMarkerStyle(20);
    grafico1->SetMarkerSize(0.9);
    grafico1->SetTitle("Scarti Passa-alto Trasferimento");
    grafico1->GetXaxis()->SetTitle("Frequenza [kHz]");
    grafico1->GetYaxis()->SetTitle("Scarti");
    grafico1->GetXaxis()->SetAxisColor(14);
    grafico1->GetYaxis()->SetAxisColor(14);
    grafico1->Draw("ap");

    TLine *line = new TLine(0, 0, 110, 0);

    line->SetLineColor(kRed);
    line->Draw("same");

    //LEGENDA

    TLegend *legendt = new TLegend(0.15, 0.15, 0.5, 0.3);
    legendt->AddEntry(grafico1, "Dati con errore", "PE");
    legendt->SetTextSize(0.04);
    legendt->SetBorderSize(1);
    legendt->SetTextFont(22);
    legendt->Draw();

    //RESIDUI SFASAMENTO
    TCanvas *c3 = new TCanvas("c3", "Canvas", 200, 10, 2000, 900);
    c3->SetGrid();
    c3->SetFillColor(0);
    gPad->SetLogx();
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> scarti_sfas;
    run_test_passa_alto_sfas(scarti_sfas, alto.freq, sfasamento_normalizzato, f1->GetParameter(0));
    TVectorD root_scarti_sfas(scarti_sfas.size(), scarti_sfas.data());

    TGraphErrors *grafico2 = new TGraphErrors(root_freq, root_scarti_sfas, root_err_freq, root_err_sfas); //, root_err_freq, root_err_);
    grafico2->SetMarkerColor(kGreen);
    grafico2->SetMarkerStyle(20);
    grafico2->SetMarkerSize(0.9);
    grafico2->SetTitle("Scarti Passa-alto Sfasamento");
    grafico2->GetXaxis()->SetTitle("Frequenza [kHz]");
    grafico2->GetYaxis()->SetTitle("Scarti");
    grafico2->GetXaxis()->SetAxisColor(14);
    grafico2->GetYaxis()->SetAxisColor(14);
    grafico2->Draw("ap");

    TLine *line2 = new TLine(0, 0, 110, 0);

    line2->SetLineColor(kRed);
    line2->Draw("same");

    //LEGENDA

    TLegend *legends = new TLegend(0.15, 0.15, 0.5, 0.3);
    legends->AddEntry(grafico2, "Dati con errore", "PE");
    legends->SetTextSize(0.04);
    legends->SetBorderSize(1);
    legends->SetTextFont(22);
    legends->Draw();
}
