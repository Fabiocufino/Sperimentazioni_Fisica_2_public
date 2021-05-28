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

double func(double *x, double *par)
{

    double a = par[0];
    double b = par[1];

    double ret = a + b * x[0];
    return ret;
};

double func_due(double *x, double *par)
{

    double a = par[0];
    double b = par[1];

    double ret = a + b * x[0];
    return ret;
};

void passa_alto_linearizzato()
{

    ac alto;
    alto.from_json("../Json/", "passa_alto.json");

    vector<double> freq_new, trasf_new, sfas_new, err_trasf_new, err_sfas_new;
    for (int i = 0; i < alto.freq.size(); i++)
    {
        if (alto.freq[i] <= 7.7 && alto.freq[i] >= 4)
        {
            freq_new.push_back(alto.freq[i]);
            trasf_new.push_back(alto.trasf[i]);
            sfas_new.push_back(alto.sfasamento[i]);
            err_trasf_new.push_back(alto.err_trasf[i]);
            err_sfas_new.push_back(alto.err_sfasamento[i] / M_PI_2);
        }
    }

    TVectorD root_freq(freq_new.size(), freq_new.data());
    TVectorD root_trasf(trasf_new.size(), trasf_new.data());
    vector<double> err_freq(alto.freq.size(), 0);
    TVectorD root_err_freq(err_freq.size(), err_freq.data());
    TVectorD root_err_trasf(err_trasf_new.size(), err_trasf_new.data());

    vector<double> sfasamento_normalizzato;
    vector<double> err_sfasamento_normalizzato;
    for (int i = 0; i < sfas_new.size(); i++)
    {
        sfasamento_normalizzato.push_back(sfas_new[i] / M_PI_2);
        //err_sfasamento_normalizzato.push_back(alto.err_sfasamento[i] / M_PI_2);
    }
    TVectorD root_sfas(sfasamento_normalizzato.size(), sfasamento_normalizzato.data());
    //TVectorD root_err_sfas(err_sfasamento_normalizzato.size(), err_sfasamento_normalizzato.data());
    TVectorD root_err_sfas(alto.err_sfasamento.size(), alto.err_sfasamento.data());

    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->SetGrid();
    c1->SetFillColor(0);
    //gPad->SetLogx();
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico_trasf = new TGraphErrors(root_freq, root_trasf, root_err_freq, root_err_trasf);
    grafico_trasf->SetMarkerColor(kAzure - 3);
    grafico_trasf->SetMarkerStyle(20);
    grafico_trasf->SetMarkerSize(0.4);
    grafico_trasf->SetTitle("Passa alto");
    grafico_trasf->GetXaxis()->SetTitle("Frequenza [kHz]");
    grafico_trasf->GetYaxis()->SetTitle("A [V_{out} / V_{in}]");
    grafico_trasf->GetXaxis()->SetAxisColor(14);
    grafico_trasf->GetYaxis()->SetAxisColor(14);
    grafico_trasf->GetXaxis()->SetLimits(5, 7.7);
    grafico_trasf->Draw("AP");

    TGraphErrors *grafico_sfas = new TGraphErrors(root_freq, root_sfas, root_err_freq, root_err_sfas);
    grafico_sfas->SetMarkerColor(kGreen);
    grafico_sfas->SetMarkerStyle(20);
    grafico_sfas->SetMarkerSize(0.4);
    grafico_sfas->SetTitle("Passa alto");
    grafico_sfas->GetXaxis()->SetTitle("Frequenza [kHz]");
    grafico_sfas->GetYaxis()->SetTitle("Sfasamento []");
    grafico_sfas->GetXaxis()->SetAxisColor(14);
    grafico_sfas->GetYaxis()->SetAxisColor(14);
    grafico_sfas->GetXaxis()->SetLimits(5, 7.7);
    grafico_sfas->Draw("Psame");

    TF1 *f1 = new TF1("f1", func, 3, 9, 2);
    f1->SetLineColor(kRed);
    f1->SetLineStyle(2);
    f1->SetLineWidth(2);

    TF1 *f2 = new TF1("f2", func_due, 3, 9, 2);
    f2->SetLineColor(kRed);
    f2->SetLineStyle(2);
    f2->SetLineWidth(2);

    fit_results pb_trasf;
    fit_results pb_sfas;

    fit_on_json(f1, 2, grafico_trasf, freq_new, trasf_new, pb_trasf, "../Fit_results", "pa_trasf_linearizzato.json", 4, 7.7);
    fit_on_json(f2, 2, grafico_sfas, freq_new, sfasamento_normalizzato, pb_sfas, "../Fit_results", "pa_sfas_linearizzato.json", 4, 7.7);

    cout << f1->GetParameter(0) << " " << f1->GetParameter(1) << " " << f2->GetParameter(0) << " " << f2->GetParameter(1) << endl;

    TPaveStats *ptstats1;
    TText *ptstats_LaTex1;
    informazioni_fit_lineare(ptstats1, ptstats_LaTex1, to_string(f1->GetChisquare()), to_string((int)f1->GetNDF()), to_string(f1->GetParameter(0)), to_string(f1->GetParError(0)), to_string(f1->GetParameter(1)), to_string(f1->GetParError(1)), to_string(pearson(freq_new, trasf_new)), to_string(student(freq_new, trasf_new)), to_string(sigma_y_posteriori(freq_new, trasf_new)), "Trasferimento");

    TPaveStats *ptstats2;
    TText *ptstats_LaTex2;
    informazioni_fit_lineare(ptstats2, ptstats_LaTex2, to_string(f2->GetChisquare()), to_string((int)f2->GetNDF()), to_string(f2->GetParameter(0)), to_string(f2->GetParError(0)), to_string(f2->GetParameter(1)), to_string(f2->GetParError(1)), to_string(pearson(freq_new, sfasamento_normalizzato)), to_string(student(freq_new, sfasamento_normalizzato)), to_string(sigma_y_posteriori(freq_new, sfasamento_normalizzato)), "Sfasamento");

    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_sfas, "Dati Sfasamento", "PE");
    legend->AddEntry(grafico_trasf, "Dati Trasferimento", "PE");
    legend->AddEntry(f1, "a + bx interpolante", "l");
    legend->AddEntry(f2, "a + bx interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    TGaxis *A1 = new TGaxis(7.7, 0.3, 7.7, 0.8, 0, 0.8, 505, "+U");

    A1->SetTitle("Sfasamento [#Delta#phi / #pi/2]");
    A1->ChangeLabel(-1, -1, -1, -1, -1, -1, "1");
    A1->ChangeLabel(1, -1, -1, -1, -1, -1, "0");
    A1->ChangeLabel(2, -1, -1, -1, -1, -1, "0.5");
    A1->SetLabelFont(42);
    A1->SetTitleFont(42);
    A1->SetLabelSize(0.03);
    A1->Draw();
    A1->SetLabelOffset(99);

    //------------------------------------------------------------------INIZIO RESIDUI-----------

    TCanvas *c2 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    c2->SetGrid();
    c2->SetFillColor(0);
    gPad->SetLogx();
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> scarti_trasf;
    run_test(scarti_trasf, freq_new, trasf_new, f1->GetParameter(1), f1->GetParameter(0));
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

    TLine *line = new TLine(0, 0, 7.85, 0);

    line->SetLineColor(kRed);
    line->Draw("same");

    cout << f1->GetParameter(0) << " " << f1->GetParameter(1) << " " << f2->GetParameter(0) << " " << f2->GetParameter(1) << endl;
    //LEGENDA

    TLegend *legendt = new TLegend(0.15, 0.15, 0.5, 0.3);
    legendt->AddEntry(grafico1, "Dati con errore", "PE");
    legendt->SetTextSize(0.04);
    legendt->SetBorderSize(1);
    legendt->SetTextFont(22);
    legendt->Draw();

    //.-----------------------------------RESIDUI SFASAMENTO
    TCanvas *c3 = new TCanvas("c3", "Canvas", 200, 10, 2000, 900);
    c3->SetGrid();
    c3->SetFillColor(0);
    gPad->SetLogx();
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> scarti_sfas;
    run_test(scarti_sfas, freq_new, sfasamento_normalizzato, f2->GetParameter(1), f2->GetParameter(0));
    for (int i = 0; i < scarti_sfas.size(); i++)
    {
        cout << scarti_sfas[i] << "\t" << freq_new[i] << "\t" << sfasamento_normalizzato[i] << endl;
    }

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

    TLine *line2 = new TLine(0, 0, 7.85, 0);

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
