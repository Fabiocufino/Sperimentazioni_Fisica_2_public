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

    double ret = TMath::ATan((-1 / (x[0] * 2 * M_PI * C) + x[0] * 2 * M_PI * L) / R);
    return ret;
}

void d_f_r_sfas_totale_e_lin()
{

    d_frequenza_tempi lin;
    lin.read("../Dati", "sfasamenti_r_delta_tempi");
    vector<double> delta_tempi, sfasamento_rad, err_delta_tempi, err_sfas, freq_hz;
    for (int i = 0; i < lin.freq.size(); i++)
    {
        delta_tempi.push_back(lin.t_2[i] - lin.t_1[i]);
        err_delta_tempi.push_back(sqrt(2) * lin.fst[i] / 25 * 1 / sqrt(12) / 1000); //propagazione di differenza su lettura e dist unif
        sfasamento_rad.push_back(-2. * M_PI * lin.freq[i] * delta_tempi[i] / 1000); //Il diviso 100 permette di convertire in giusta unità di misura
        err_sfas.push_back(2. * M_PI * lin.freq[i] * err_delta_tempi[i] / 1000);    //propagazione su conversione in rad
        freq_hz.push_back(lin.freq[i] * 1000);
    }

    TVectorD root_freq(freq_hz.size(), freq_hz.data());
    TVectorD root_sfasamento(sfasamento_rad.size(), sfasamento_rad.data());

    vector<double> err_freq(lin.freq.size(), 0);
    TVectorD root_err_freq(lin.freq.size(), 0);

    TVectorD root_err_sfas(err_sfas.size(), err_sfas.data());

    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->Divide(2, 1);
    c1->cd(1);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    //--------------------MASSIMI-----------------------------------//
    TGraphErrors *grafico_all = new TGraphErrors(root_freq, root_sfasamento, root_err_freq, root_err_sfas);
    grafico_all->SetMarkerColor(kAzure - 3);
    grafico_all->SetMarkerStyle(20);
    grafico_all->SetMarkerSize(0.8);
    grafico_all->SetTitle("Fit per lo sfasamento su R");
    grafico_all->GetXaxis()->SetTitle("frequenza [Hz]");
    grafico_all->GetYaxis()->SetTitle("#Delta#phi [rad]");
    grafico_all->GetXaxis()->SetAxisColor(14);
    grafico_all->GetYaxis()->SetAxisColor(14);
    grafico_all->Draw("ap");

    TF1 *f_center = new TF1("f1", func, 0, 10, 2);
    f_center->SetLineColor(kRed);
    f_center->SetLineStyle(2);
    f_center->SetLineWidth(2);

    fit_results fit_center;
    fit_on_json(f_center, 2, grafico_all, freq_hz, sfasamento_rad, fit_center, "../Fit_results", "sfasamento_fit_center.json", 50.8 * 1000, 51.45 * 1000);

    TF1 *f_before = new TF1("f2", func, 0, 10, 2);
    f_before->SetLineColor(kRed);
    f_before->SetLineStyle(2);
    f_before->SetLineWidth(2);

    fit_results fit_before;
    fit_on_json(f_before, 2, grafico_all, freq_hz, sfasamento_rad, fit_before, "../Fit_results", "sfasamento_fit_before.json", 48.6 * 1000, 49.3 * 1000);

    TF1 *f_after = new TF1("f3", func, 0, 10, 2);
    f_after->SetLineColor(kRed);
    f_after->SetLineStyle(2);
    f_after->SetLineWidth(2);

    fit_results fit_after;
    fit_on_json(f_after, 2, grafico_all, freq_hz, sfasamento_rad, fit_after, "../Fit_results", "sfasamento_fit_after.json", 53.2 * 1000, 53.7 * 1000);

    //-----------------------lsfasamentro totalee---------------------
    TF1 *curva = new TF1("ftot", curva_sfas, 0, 200000, 3);
    curva->SetLineColor(kRed);
    curva->SetLineStyle(2);
    curva->SetLineWidth(1);
    
    curva->SetParameter(0, 120);
    curva->SetParameter(1, 1);
    curva->SetParameter(2, 9.8e-9);
    
    fit_results df_r;
    fit_on_json(curva, 3, grafico_all, freq_hz, sfasamento_rad, df_r, "../Fit_results", "df_r_sfasamento_tot.json", 10e03, 100e03);
    
    TPaveStats *ptstats1;
    TText *ptstats_LaTex1;
    informazioni_fit_RLC_sfas(ptstats1,
                              ptstats_LaTex1,
                              to_string((int)curva->GetChisquare()),
                              to_string((int)curva->GetNDF()),
                              to_string(curva->GetParameter(0)),
                              to_string(curva->GetParError(0)),
                              "9.85798e-04",
                              "9.97842e-08",
                              "9.83671e-09",
                              "9.95697e-13",
                              "Sfasamento");
    
    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_all, "Dati con errore", "PE");
    //legend->AddEntry(curva, "Curva interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    //--------------------------------------------------------------------------------------RESIDUI-----------------------------------------------
    //c1->cd(2);
    //gPad->SetGrid();
    //gPad->SetFillColor(0);
    //
    //vector<double> scarti;
    //run_test_sfas_R(scarti, freq_hz, sfasamento_rad, curva->GetParameter(0), curva->GetParameter(1), curva->GetParameter(2));
    //TVectorD root_scarti(scarti.size(), scarti.data());
    //
    //TGraphErrors *grafico_scarti = new TGraphErrors(root_freq, root_scarti, root_err_freq, root_err_sfas);
    //grafico_scarti->SetMarkerColor(kAzure - 3);
    //grafico_scarti->SetMarkerStyle(20);
    //grafico_scarti->SetMarkerSize(0.8);
    //grafico_scarti->SetTitle("Scarti per lo sfasamento su R");
    //grafico_scarti->GetXaxis()->SetTitle("frequenza [Hz]");
    //grafico_scarti->GetYaxis()->SetTitle("#Delta#phi [rad]");
    //grafico_scarti->GetXaxis()->SetAxisColor(14);
    //grafico_scarti->GetYaxis()->SetAxisColor(14);
    //grafico_scarti->Draw("ap");
    //
    ////LEGENDA
    //TLegend *legends = new TLegend(0.15, 0.15, 0.5, 0.3);
    //legends->AddEntry(grafico_scarti, "Dati con errore", "PE");
    //legends->SetTextSize(0.04);
    //legends->SetBorderSize(1);
    //legends->SetTextFont(22);
    //legends->Draw();
    //
    //TLine *zero = new TLine(10000, 0, 110000, 0);
    //zero->SetLineColor(kRed);
    //zero->Draw("same");
}