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

void fit_lineari_sfasam_r()
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
    gPad->SetGrid();
    gPad->SetFillColor(0);

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

    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_all, "Dati con errore", "PE");
    legend->AddEntry(f_after, "Rette interpolanti", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    //--------------------------------------------------------------------------------------RESIDUI-----------------------------------------------
    //c1->cd(2);
    //gPad->SetGrid();
    //gPad->SetFillColor(0);
    //
    //vector<double> freq1, freq2, freq3;
    //vector<double> efreq1, efreq2, efreq3;
    //vector<double> sfas1, sfas2, sfas3;
    //vector<double> esfas1, esfas2, esfas3;
    //for (int i = 0; i < freq_hz.size(); i++)
    //{
    //    if (freq_hz[i] >= 48500 && freq_hz[i] <= 49500)
    //    {
    //        freq1.push_back(freq_hz[i]);
    //        sfas1.push_back(sfasamento_rad[i]);
    //        efreq1.push_back(0);
    //        esfas1.push_back(err_sfas[i]);
    //    }
    //    if (freq_hz[i] >= 50800 && freq_hz[i] <= 51450)
    //    {
    //        freq2.push_back(freq_hz[i]);
    //        sfas2.push_back(sfasamento_rad[i]);
    //        efreq2.push_back(0);
    //        esfas2.push_back(err_sfas[i]);
    //    }
    //    if (freq_hz[i] >= 53000 && freq_hz[i] <= 54000)
    //    {
    //        freq3.push_back(freq_hz[i]);
    //        sfas3.push_back(sfasamento_rad[i]);
    //        efreq3.push_back(0);
    //        esfas3.push_back(err_sfas[i]);
    //    }
    //}
    //TVectorD root_freq1(freq1.size(), freq1.data());
    //TVectorD root_freq2(freq2.size(), freq2.data());
    //TVectorD root_freq3(freq3.size(), freq3.data());
    //
    //vector<double> scarti1, scarti2, scarti3;
    //run_test(scarti1, freq1, sfas1, f_before->GetParameter(0), f_before->GetParameter(1));
    //run_test(scarti2, freq2, sfas2, f_center->GetParameter(0), f_center->GetParameter(1));
    //run_test(scarti3, freq3, sfas3, f_after->GetParameter(0), f_after->GetParameter(1));
    //TVectorD root_scarti1(scarti1.size(), scarti1.data());
    //TVectorD root_scarti2(scarti2.size(), scarti2.data());
    //TVectorD root_scarti3(scarti3.size(), scarti3.data());
    //
    //TVectorD root_err_freq_1(efreq1.size(), efreq1.data());
    //TVectorD root_err_freq_2(efreq2.size(), efreq2.data());
    //TVectorD root_err_freq_3(efreq3.size(), efreq3.data());
    //
    //TVectorD root_err_sfas_1(esfas1.size(), esfas1.data());
    //TVectorD root_err_sfas_2(esfas2.size(), esfas2.data());
    //TVectorD root_err_sfas_3(esfas3.size(), esfas3.data());
    //
    //TGraphErrors *grafico_scarti1 = new TGraphErrors(root_freq1, root_scarti1, root_err_freq_1, root_err_sfas_1);
    //grafico_scarti1->SetMarkerColor(kOrange);
    //grafico_scarti1->SetMarkerStyle(20);
    //grafico_scarti1->SetMarkerSize(0.8);
    //grafico_scarti1->SetTitle("Scarti per lo sfasamento su R");
    //grafico_scarti1->GetXaxis()->SetTitle("frequenza [Hz]");
    //grafico_scarti1->GetYaxis()->SetTitle("#Delta#phi [rad]");
    //grafico_scarti1->GetXaxis()->SetAxisColor(14);
    //grafico_scarti1->GetYaxis()->SetAxisColor(14);
    //grafico_scarti1->Draw("ap");
    //
    //TGraphErrors *grafico_scarti2 = new TGraphErrors(root_freq2, root_scarti2, root_err_freq_2, root_err_sfas_2);
    //grafico_scarti2->SetMarkerColor(kAzure);
    //grafico_scarti2->SetMarkerStyle(20);
    //grafico_scarti2->SetMarkerSize(0.8);
    //grafico_scarti2->Draw("Psame");
    //
    //TGraphErrors *grafico_scarti3 = new TGraphErrors(root_freq3, root_scarti3, root_err_freq_3, root_err_sfas_3);
    //grafico_scarti3->SetMarkerColor(kGreen);
    //grafico_scarti3->SetMarkerStyle(20);
    //grafico_scarti3->SetMarkerSize(0.8);
    //grafico_scarti3->Draw("Psame");
    //
    ////LEGENDA
    ////TLegend *legends = new TLegend(0.15, 0.15, 0.5, 0.3);
    ////legends->AddEntry(grafico_scarti, "Dati con errore", "PE");
    ////legends->SetTextSize(0.04);
    ////legends->SetBorderSize(1);
    ////legends->SetTextFont(22);
    ////legends->Draw();
    //
    //TLine *zero = new TLine(10000, 0, 110000, 0);
    //zero->SetLineColor(kRed);
    //zero->Draw("same");
}