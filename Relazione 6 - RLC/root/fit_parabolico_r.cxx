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
#include <vector>
#ifndef DATACLASS
#include "../Programmi/dataclass.h"
#include "root_function.h"
#endif

using namespace std;
using json = nlohmann::json;

double parabola(double *x, double *par)
{
    double a = par[0];
    double b = par[1];
    double c = par[2];

    double ret = a + b * x[0] + c * x[0] * x[0];
    return ret;
}

void fit_parabolico_r()
{
    d_frequenza df;
    df.from_json("../Json", "d_f_r.json");

    //TVectorD root_freq(df.freq.size(), df.freq.data());
    vector<double> err_freq(df.freq.size(), 0);
    TVectorD root_err_freq(err_freq.size(), err_freq.data());

    vector<double> trasferimento;
    vector<double> frequenza;
    vector<double> err_trasferimento;
    for (int i = 0; i < df.freq.size(); i++)
    {
        double perc = 1.5 / 100.; //errore su guadagno sonde, fisso a 1.5%
        double a = df.v_out[i] / df.v_in[i];
        double sigma_vin = 1. / 25 * 0.3 * df.fsv_in[i];   //magico
        double sigma_vout = 1. / 25 * 0.3 * df.fsv_out[i]; //magico
        double sigma_kin = perc;
        double sigma_kout = perc;
        trasferimento.push_back(a);
        err_trasferimento.push_back(a * sqrt(pow(sigma_vin / df.v_in[i], 2) + pow(sigma_vout / df.v_out[i], 2) + pow(sigma_kin, 2) + pow(sigma_kout, 2)));
        frequenza.push_back(df.freq[i] * 1000);
    }

    TVectorD root_trasferimento(trasferimento.size(), trasferimento.data());
    TVectorD root_freq(frequenza.size(), frequenza.data());

    TVectorD root_err_trasferimento(err_trasferimento.size(), err_trasferimento.data());

    TCanvas *c2 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico_trasf = new TGraphErrors(root_freq, root_trasferimento, root_err_freq, root_err_trasferimento);
    grafico_trasf->SetMarkerColor(kAzure - 3);
    grafico_trasf->SetMarkerStyle(20);
    grafico_trasf->SetMarkerSize(0.8);
    grafico_trasf->SetTitle("Fit Parabolico su Trasferimento R");
    grafico_trasf->GetXaxis()->SetTitle("f [kHz]");
    grafico_trasf->GetYaxis()->SetTitle("A=V_{out}/V_{in}");
    grafico_trasf->GetXaxis()->SetAxisColor(14);
    grafico_trasf->GetYaxis()->SetAxisColor(14);
    grafico_trasf->Draw("AP");

    TF1 *fit_lin = new TF1("f2", parabola, 0, 200000, 3);
    fit_lin->SetLineColor(kRed);
    fit_lin->SetLineStyle(2);
    fit_lin->SetLineWidth(1);

    fit_lin->SetParameter(0, 1);
    fit_lin->SetParameter(1, 1);
    fit_lin->SetParameter(2, 1);

    fit_results df_r;
    fit_on_json(fit_lin, 3, grafico_trasf, df.freq, trasferimento, df_r, "../Fit_results", "fit_parabolico_r.json", 50000, 52000);

    TPaveStats *ptstats1;
    TText *ptstats_LaTex1;
    informazioni_fit_parabolico(ptstats1,
                                ptstats_LaTex1,
                                to_string(fit_lin->GetChisquare()),
                                to_string((int)fit_lin->GetNDF()),
                                to_string(fit_lin->GetParameter(0)),
                                to_string(fit_lin->GetParError(0)),
                                to_string(fit_lin->GetParameter(1)),
                                "4.45249e-07",
                                "-3.74057e-08",
                                "8.41238e-12",
                                "Fit Parabolico R");

    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_trasf, "Dati trasferimento su R", "PE");
    legend->AddEntry(fit_lin, "Parabola interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();
}