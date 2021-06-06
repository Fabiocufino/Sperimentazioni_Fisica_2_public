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

void v_in_out_c()
{
    d_frequenza df;
    df.from_json("../Json", "d_f_c.json");

    vector<double> err_freq(df.freq.size(), 0);
    TVectorD root_err_freq(err_freq.size(), err_freq.data());

    vector<double> err_v_in;
    vector<double> err_v_out;

    for (int i = 0; i < df.freq.size(); i++)
    {
        double perc = 1.5 / 100.; //errore su guadagno sonde, fisso a 1.5%
        err_v_in.push_back(sqrt(pow(perc * df.v_in[i], 2) + pow(1. / 25. * 1 / sqrt(12) * df.fsv_in[i], 2)));
        err_v_out.push_back(sqrt(pow(perc * df.v_out[i], 2) + pow(1. / 25. * 1 / sqrt(12) * df.fsv_out[i], 2)));
    }

    TVectorD root_freq(df.freq.size(), df.freq.data());
    TVectorD root_v_in(df.v_in.size(), df.v_in.data());
    TVectorD root_v_out(df.v_out.size(), df.v_out.data());
    TVectorD root_err_v_in(err_v_in.size(), err_v_in.data());
    TVectorD root_err_v_out(err_v_out.size(), err_v_out.data());

    TCanvas *c2 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico_vin = new TGraphErrors(root_freq, root_v_in, root_err_freq, root_err_v_in);
    grafico_vin->SetMarkerColor(kAzure - 3);
    grafico_vin->SetMarkerStyle(20);
    grafico_vin->SetMarkerSize(0.6);
    grafico_vin->SetTitle("V-in e V-out");
    grafico_vin->GetXaxis()->SetTitle("f [kHz]");
    grafico_vin->GetYaxis()->SetTitle("V [mV]");
    grafico_vin->GetXaxis()->SetAxisColor(14);
    grafico_vin->GetYaxis()->SetAxisColor(14);
    grafico_vin->Draw("AP");

    TF1 *fit_parab = new TF1("f2", parabola, 0, 200000, 3);
    fit_parab->SetLineColor(kRed);
    fit_parab->SetLineStyle(2);
    fit_parab->SetLineWidth(1);

    fit_results df_r;
    fit_on_json(fit_parab, 3, grafico_vin, df.freq, df.v_in, df_r, "../Fit_results", "fit_parabolico_v_in_C.json", 49.5, 53);

    TPaveStats *cubo;
    TText *latex;
    informazioni_fit_parabolico(cubo, latex, to_string(fit_parab->GetChisquare()), to_string((int)fit_parab->GetNDF()),
                                to_string(fit_parab->GetParameter(0)), to_string(fit_parab->GetParError(0)),
                                to_string(fit_parab->GetParameter(1)), to_string(fit_parab->GetParError(1)),
                                to_string(fit_parab->GetParameter(2)), to_string(fit_parab->GetParError(2)), "Fit parabola su V_{in}");

    //-----------------------------------VOUT
    TGraphErrors *grafico_vout = new TGraphErrors(root_freq, root_v_out, root_err_freq, root_err_v_out);
    grafico_vout->SetMarkerColor(kOrange);
    grafico_vout->SetMarkerStyle(20);
    grafico_vout->SetMarkerSize(0.6);
    grafico_vout->SetTitle("V-in e V-out");
    grafico_vout->GetXaxis()->SetTitle("f [kHz]");
    grafico_vout->GetYaxis()->SetTitle("A");
    grafico_vout->GetXaxis()->SetAxisColor(14);
    grafico_vout->GetYaxis()->SetAxisColor(14);
    grafico_vout->Draw("Psame");

    TF1 *fit_parab2 = new TF1("f3", parabola, 0, 200000, 3);
    fit_parab2->SetLineColor(kRed);
    fit_parab2->SetLineStyle(2);
    fit_parab2->SetLineWidth(1);

    fit_results df_r2;
    fit_on_json(fit_parab2, 3, grafico_vout, df.freq, df.v_out, df_r2, "../Fit_results", "fit_parabolico_v_out_C.json", 49.5, 53);

    TPaveStats *cubo1;
    TText *latex1;
    informazioni_fit_parabolico(cubo1, latex1, to_string(fit_parab2->GetChisquare()), to_string((int)fit_parab2->GetNDF()),
                                to_string(fit_parab2->GetParameter(0)), to_string(fit_parab->GetParError(0)),
                                to_string(fit_parab2->GetParameter(1)), to_string(fit_parab->GetParError(1)),
                                to_string(fit_parab2->GetParameter(2)), to_string(fit_parab->GetParError(2)), "Fit parabola su V_{out}");

    //LEGENDA
    TLegend *legend2 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend2->AddEntry(grafico_vin, "Dati V_{in}", "PE");
    legend2->AddEntry(grafico_vout, "Dati V_{out}", "PE");
    legend2->AddEntry(fit_parab, "Parabola interpolante", "l");
    legend2->SetTextSize(0.04);
    legend2->SetBorderSize(1);
    legend2->SetTextFont(22);
    legend2->Draw();
}