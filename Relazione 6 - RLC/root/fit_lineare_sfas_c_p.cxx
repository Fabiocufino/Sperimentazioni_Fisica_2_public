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

double retta(double *x, double *par)
{
    double a = par[0];
    double b = par[1];

    double ret = a + b * x[0];
    return ret;
}

void fit_lineare_sfas_c_p()
{
    d_frequenza df;
    df.from_json("../Json", "fit_lineare_c_p.json");

    //TVectorD root_freq(df.freq.size(), df.freq.data());
    vector<double> err_freq(df.freq.size(), 0);
    TVectorD root_err_freq(err_freq.size(), err_freq.data());

    vector<double> sfasamento;
    vector<double> frequenza;
    vector<double> err_sfasamento;
    for (int i = 0; i < df.freq.size(); i++)
    {
        sfasamento.push_back(df.delta_phi[i]);
        err_sfasamento.push_back(0);
        frequenza.push_back(df.freq[i] * 1000);
    }

    TVectorD root_sfasamento(sfasamento.size(), sfasamento.data());
    TVectorD root_freq(frequenza.size(), frequenza.data());

    TVectorD root_err_sfasamento(err_sfasamento.size(), err_sfasamento.data());

    TCanvas *c2 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico_sfas = new TGraphErrors(root_freq, root_sfasamento, root_err_freq, root_err_sfasamento);
    grafico_sfas->SetMarkerColor(kAzure - 3);
    grafico_sfas->SetMarkerStyle(20);
    grafico_sfas->SetMarkerSize(0.6);
    grafico_sfas->SetTitle("Fit Linere su Sfasamento C, frequenza taglio (-)");
    grafico_sfas->GetXaxis()->SetTitle("f [kHz]");
    grafico_sfas->GetYaxis()->SetTitle("DeltaPhi");
    grafico_sfas->GetXaxis()->SetAxisColor(14);
    grafico_sfas->GetYaxis()->SetAxisColor(14);
    grafico_sfas->Draw("AP");

    TF1 *fit_lin = new TF1("f2", retta, 0, 200000, 2);
    fit_lin->SetLineColor(kRed);
    fit_lin->SetLineStyle(2);
    fit_lin->SetLineWidth(1);

    fit_lin->SetParameter(0, 1);
    fit_lin->SetParameter(1, 1);

    fit_results df_r;
    fit_on_json(fit_lin, 2, grafico_sfas, df.freq, sfasamento, df_r, "../Fit_results", "lin_c_p_sfasamento.json", 20e03, 100e03);

    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_sfas, "Dati sfasamento su C", "PE");
    legend->AddEntry(fit_lin, "Retta interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();
}