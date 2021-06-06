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
#include "root_function.h"
#include <vector>
#ifndef DATACLASS
#include "../Programmi/dataclass.h"
#endif

using namespace std;
using json = nlohmann::json;

double func(double *x, double *par)
{

    double a = par[0];
    double b = par[1];

    double ret = a + b * x[0];
    return ret;
}

double curva_sfas(double *x, double *par)
{
    double R = par[0];
    double L = par[1];
    double C = par[2];

    double ret = M_PI_2 + TMath::ATan((-1 / (x[0] * 2 * M_PI * C) + x[0] * 2 * M_PI * L) / R);
    return ret;
}

void fit_lineari_sfasam_c()
{
    d_frequenza df;
    df.from_json("../Json", "d_f_c.json");

    //TVectorD root_freq(df.freq.size(), df.freq.data());
    vector<double> err_freq(df.freq.size(), 0);
    TVectorD root_err_freq(err_freq.size(), err_freq.data());

    vector<double> sfasamento_rad;
    vector<double> freq_hz;
    vector<double> err_sfasamento;
    for (int i = 0; i < df.delta_phi.size(); i++)
    {
        sfasamento_rad.push_back(-df.delta_phi[i]);
        err_sfasamento.push_back(0);
        freq_hz.push_back(df.freq[i] * 1000);
    }

    TVectorD root_sfasamento(sfasamento_rad.size(), sfasamento_rad.data());
    TVectorD root_freq(freq_hz.size(), freq_hz.data());
    TVectorD root_err_sfasamento(err_sfasamento.size(), err_sfasamento.data());

    TCanvas *c1 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico_all = new TGraphErrors(root_freq, root_sfasamento, root_err_freq, root_err_sfasamento);
    //TGraphErrors *grafico_trasf = new TGraphErrors("../../../dati_amp_R.txt", "%lg %lg %lg");
    grafico_all->SetMarkerColor(kAzure - 3);
    grafico_all->SetMarkerStyle(20);
    grafico_all->SetMarkerSize(0.8);
    grafico_all->SetTitle("Fit Sfasamento ai capi di C");
    grafico_all->GetXaxis()->SetTitle("f [Hz]");
    grafico_all->GetYaxis()->SetTitle("#Delta#phi [rad]");
    grafico_all->GetXaxis()->SetAxisColor(14);
    grafico_all->GetYaxis()->SetAxisColor(14);
    grafico_all->Draw("AP");

    TF1 *f_center = new TF1("f1", func, 0, 10, 2);
    f_center->SetLineColor(kRed);
    f_center->SetLineStyle(2);
    f_center->SetLineWidth(2);

    fit_results fit_center;
    fit_on_json(f_center, 2, grafico_all, freq_hz, sfasamento_rad, fit_center, "../Fit_results", "sfasamento_fit_centerC.json", 50.8 * 1000, 51.45 * 1000);

    TF1 *f_before = new TF1("f2", func, 0, 10, 2);
    f_before->SetLineColor(kRed);
    f_before->SetLineStyle(2);
    f_before->SetLineWidth(2);

    fit_results fit_before;
    fit_on_json(f_before, 2, grafico_all, freq_hz, sfasamento_rad, fit_before, "../Fit_results", "sfasamento_fit_beforeC.json", 49.40 * 1000, 50.1 * 1000);

    TF1 *f_after = new TF1("f3", func, 0, 10, 2);
    f_after->SetLineColor(kRed);
    f_after->SetLineStyle(2);
    f_after->SetLineWidth(2);

    fit_results fit_after;
    fit_on_json(f_after, 2, grafico_all, freq_hz, sfasamento_rad, fit_after, "../Fit_results", "sfasamento_fit_afterC.json", 51.79 * 1000, 52.5 * 1000);

    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_all, "Dati con errore", "PE");
    legend->AddEntry(f_center, "Rette interpolanti", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();
}