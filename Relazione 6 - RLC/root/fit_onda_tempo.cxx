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

//double fitf(double *x, double *par)
//{
//
//    double R = par[0];
//    double L = par[1];
//    double C = par[2];
//
//    double v_th = 1 * TMath::Exp(-1. * C * x[0]) * (C * TMath::Sin(x[0] * TMath::Sqrt(pow(L, 2) - pow(C, 2))) + TMath::Sqrt(pow(L, 2) - pow(C, 2)) * TMath::Cos(x[0] * TMath::Sqrt(pow(L, 2) - pow(C, 2)))) / TMath::Sqrt(pow(L, 2) - pow(C, 2)); //funzione
//    return v_th;
//}

double fitf2(double *x, double *par)
{

    double R = par[0];
    double L = par[1];
    double C = par[2];
    double a = 1.02109e+00;

    //x[0]--> (x[0]-a)

    double k = TMath::Sqrt(pow((1 / sqrt(L * C)), 2) - pow((R / (2. * L)), 2));
    double val;
    val = (a / k) * TMath::Exp(-(R / (2. * L)) * x[0]) * ((R / (2. * L)) * TMath::Sin(k * x[0]) + k * TMath::Cos(k * x[0]));

    return val;
}

void fit_onda_tempo()
{

    TCanvas *c2 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico_somma = new TGraphErrors("../Dati/onda_rlc_smorzata2.txt", "%lg %lg %lg");
    grafico_somma->SetMarkerColor(kAzure - 3);
    grafico_somma->SetMarkerStyle(20);
    grafico_somma->SetMarkerSize(0.6);
    grafico_somma->SetTitle("Fit Onda");
    grafico_somma->GetXaxis()->SetTitle("Tempo [s]");
    grafico_somma->GetYaxis()->SetTitle("V");
    grafico_somma->GetXaxis()->SetAxisColor(14);
    grafico_somma->GetYaxis()->SetAxisColor(14);
    grafico_somma->Draw("AP");

    TF1 *fun = new TF1("myfit", fitf2, 0, 10, 3);
    fun->SetParameter(0, 6.84014e+01);
    fun->SetParameter(1, 9.86442e-04);
    fun->SetParameter(2, 9.80211e-09);

    //fun->SetParLimits(4, 0.9, 1.1);
    TFitResultPtr fit_res = grafico_somma->Fit(fun, "+S", "", 0, 0.04e-03);

    TPaveStats *ptstats1;
    TText *ptstats_LaTex1;
    informazioni_fit_RLC_totale(ptstats1,
                                ptstats_LaTex1,
                                to_string((int)fun->GetChisquare()),
                                to_string((int)fun->GetNDF()),
                                "6.57331e+01",
                                "2.75283",
                                "9.80236e-04",
                                "4.10453e-05",
                                "9.88536e-09",
                                "4.13925e-10",
                                "1.02109e+00",
                                "3.17877e-03",
                                "Parametri Stimati");
    //LEGENDA
    TLegend *legend2 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend2->AddEntry(grafico_somma, "Dati con errore", "PE");
    legend2->AddEntry(fun, "Curva interpolante", "l");
    legend2->SetTextSize(0.04);
    legend2->SetBorderSize(1);
    legend2->SetTextFont(22);
    legend2->Draw();

    //---------------------------------------------RESIDUI
    TCanvas *c3 = new TCanvas("c3", "Canvas", 200, 10, 2000, 900);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    //Legge i  dati in maniera barbara
    ifstream fin("../Dati/onda_rlc_smorzata2.txt");
    vector<double> t;
    vector<double> v;
    vector<double> err_v;
    double temp, temp1, temp2;
    while (fin >> temp >> temp1 >> temp2)
    {
        if (temp <= 0.04e-3)
        {
            t.push_back(temp);
            v.push_back(temp1);
            err_v.push_back(temp2);
        }
    }

    vector<double> scarti;
    run_test_onda_tempo(scarti, t, v, 1.02109e+00, fun->GetParameter(0), fun->GetParameter(1), fun->GetParameter(2));
    TVectorD root_scarti(scarti.size(), scarti.data());
    TVectorD root_temp(t.size(), t.data());
    TVectorD root_err_v(err_v.size(), err_v.data());
    vector<double> err_t(t.size(), 0);
    TVectorD root_err_tempo(err_t.size(), err_t.data());

    TGraphErrors *grafico_scarti = new TGraphErrors(root_temp, root_scarti, root_err_tempo, root_err_v);
    grafico_scarti->SetMarkerColor(kAzure - 3);
    grafico_scarti->SetMarkerStyle(20);
    grafico_scarti->SetMarkerSize(0.6);
    grafico_scarti->SetTitle("Scarti della fit totale");
    grafico_scarti->GetXaxis()->SetTitle("Tempo [s]");
    grafico_scarti->GetYaxis()->SetTitle("V");
    grafico_scarti->GetXaxis()->SetAxisColor(14);
    grafico_scarti->GetYaxis()->SetAxisColor(14);
    grafico_scarti->Draw("AP");

    //LEGENDA
    TLegend *legend3 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend3->AddEntry(grafico_scarti, "Dati con errore", "PE");
    legend3->SetTextSize(0.04);
    legend3->SetBorderSize(1);
    legend3->SetTextFont(22);
    legend3->Draw();
}