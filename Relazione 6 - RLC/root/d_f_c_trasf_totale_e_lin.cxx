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
    double R = par[1];
    double L = par[2];
    double C = par[3];

    double delta = R / (2 * L);
    //double delta = par[2];

    double omega = 1 / sqrt(L * C);
    //double omega = par[1];
    //double a = par[0];    

    double ret = a * pow(omega, 2) / sqrt(pow(x[0] * 2 * M_PI, 4) - (2 * pow(x[0] * 2 * M_PI, 2) * (pow(omega, 2) - 2 * pow(delta, 2))) + pow(omega, 4));
    return ret;
}

double parabola(double *x, double *par)
{

    double a = par[0];
    double b = par[1];
    double c = par[2];

    double ret = a + b * x[0] + c * x[0] * x[0];
    return ret;
}

void d_f_c_trasf_totale_e_lin()
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
    c2->Divide(2, 1);
    c2->cd(1);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico_trasf = new TGraphErrors(root_freq, root_trasferimento, root_err_freq, root_err_trasferimento);
    //TGraphErrors *grafico_trasf = new TGraphErrors("../../../dati_amp_R.txt", "%lg %lg %lg");
    grafico_trasf->SetMarkerColor(kAzure - 3);
    grafico_trasf->SetMarkerStyle(20);
    grafico_trasf->SetMarkerSize(0.8);
    grafico_trasf->SetTitle("Fit Onda");
    grafico_trasf->GetXaxis()->SetTitle("f [kHz]");
    grafico_trasf->GetYaxis()->SetTitle("V");
    grafico_trasf->GetXaxis()->SetAxisColor(14);
    grafico_trasf->GetYaxis()->SetAxisColor(14);
    grafico_trasf->Draw("AP");

    TF1 *lorentz = new TF1("f2", lorentziana, 0, 200000, 4);
    lorentz->SetLineColor(kRed);
    lorentz->SetLineStyle(2);
    lorentz->SetLineWidth(1);

    lorentz->SetParameter(0, 1.77);
    lorentz->SetParameter(1, 32);
    lorentz->SetParameter(2, 0.00094);
    lorentz->SetParameter(3, 9.9e-9);

    fit_results df_r;
    fit_on_json(lorentz, 4, grafico_trasf, df.freq, trasferimento, df_r, "../Fit_results", "df_c_trasferimento.json", 5000, 110000);

    TPaveStats *ptstats1;
    TText *ptstats_LaTex1;
    informazioni_fit_RLC_sfas(ptstats1,
                              ptstats_LaTex1,
                              to_string((int)lorentz->GetChisquare()),
                              to_string((int)lorentz->GetNDF()),
                              "1.82596e+01",
                              "2.27972",
                              "9.98347e-04",
                              "1.24340e-04",
                              "9.72500e-09",
                              "1.21121e-09",
                              "Trasferimento");

    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_trasf, "Dati trasferimento su R", "PE");
    legend->AddEntry(lorentz, "Lorentziana interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    //--------------------------------------------------------------------------------------RESIDUI-----------------------------------------------
    c2->cd(2);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> scarti;
    run_test_trasf_C(scarti, frequenza, trasferimento, lorentz->GetParameter(0), lorentz->GetParameter(1), lorentz->GetParameter(2), lorentz->GetParameter(3));
    TVectorD root_scarti(scarti.size(), scarti.data());

    TGraphErrors *grafico_scarti = new TGraphErrors(root_freq, root_scarti, root_err_freq, root_err_trasferimento);
    grafico_scarti->SetMarkerColor(kAzure - 3);
    grafico_scarti->SetMarkerStyle(20);
    grafico_scarti->SetMarkerSize(0.8);
    grafico_scarti->SetTitle("Scarti per lo sfasamento su C");
    grafico_scarti->GetXaxis()->SetTitle("frequenza [Hz]");
    grafico_scarti->GetYaxis()->SetTitle("non mostrare");
    grafico_scarti->GetXaxis()->SetAxisColor(14);
    grafico_scarti->GetYaxis()->SetAxisColor(14);
    grafico_scarti->Draw("ap");

    //LEGENDA
    TLegend *legends = new TLegend(0.15, 0.15, 0.5, 0.3);
    legends->AddEntry(grafico_scarti, "Dati con errore", "PE");
    legends->SetTextSize(0.04);
    legends->SetBorderSize(1);
    legends->SetTextFont(22);
    legends->Draw();

    TLine *zero = new TLine(10000, 0, 110000, 0);
    zero->SetLineColor(kRed);
    zero->Draw("same");
}