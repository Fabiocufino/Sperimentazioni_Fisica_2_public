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

double lorentziana(double *x, double *par)
{

    double a = par[0];
    double omega = par[1];
    double delta = par[2];

    double ret = a * pow(omega, 2) / sqrt(pow(x[0] * 2 * M_PI, 4) - (2 * pow(x[0] * 2 * M_PI, 2) * (pow(omega, 2) - 2 * pow(delta, 2))) + pow(omega, 4));
    return ret;
}

void serve()
{
    d_frequenza df;
    df.from_json("../Json", "d_f_c.json");

    //TVectorD root_freq(df.freq.size(), df.freq.data());
    vector<double> err_freq(df.freq.size(), 0);
    TVectorD root_err_freq(err_freq.size(), err_freq.data());

    vector<double> trasferimento;
    vector<double> frequenza;
    vector<double> err_trasferimento;
    for (int i = 0; i < df.v_in.size(); i++)
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
    //TGraphErrors *grafico_trasf = new TGraphErrors("../../../dati_amp_R.txt", "%lg %lg %lg");
    grafico_trasf->SetMarkerColor(kAzure - 3);
    grafico_trasf->SetMarkerStyle(20);
    grafico_trasf->SetMarkerSize(0.8);
    grafico_trasf->SetTitle(" ");
    grafico_trasf->GetXaxis()->SetTitle("f [kHz]");
    grafico_trasf->GetYaxis()->SetTitle("V");
    grafico_trasf->GetXaxis()->SetAxisColor(14);
    grafico_trasf->GetYaxis()->SetAxisColor(14);
    grafico_trasf->Draw("AP");

    TF1 *lorentz = new TF1("f2", lorentziana, 0, 200000, 3);
    lorentz->SetLineColor(kRed);
    lorentz->SetLineStyle(2);
    lorentz->SetLineWidth(1);

    lorentz->SetParName(0, "a");
    lorentz->SetParName(2, "#delta");
    lorentz->SetParName(1, "#Omega");

    lorentz->SetParameter(0, 1);
    lorentz->SetParameter(1, 33854);
    lorentz->SetParameter(2, 336718);

    fit_results df_r;
    fit_on_json(lorentz, 3, grafico_trasf, df.freq, trasferimento, df_r, "../Fit_results", "serve.json", 5000, 110000);


    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_trasf, "Dati trasferimento su C", "PE");
    legend->AddEntry(lorentz, "Lorentziana interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();
}