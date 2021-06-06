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

double curva_sfas(double *x, double *par)
{
    double R = par[0];
    double L = par[1];
    double C = par[2];

    double ret = M_PI_2 + TMath::ATan((-1 / (x[0] * 2 * M_PI * C) + x[0] * 2 * M_PI * L) / R);
    return ret;
}

void d_f_c_sfas_totale()
{
    d_frequenza df, df_confronto;
    df.from_json("../Json", "d_f_c.json");
    df_confronto.from_json("../Json", "d_f_r.json");

    //TVectorD root_freq(df.freq.size(), df.freq.data());
    vector<double> err_freq(df.freq.size(), 0);
    TVectorD root_err_freq(err_freq.size(), err_freq.data());

    vector<double> sfasamento;
    vector<double> frequenza;
    vector<double> err_sfasamento;
    for (int i = 0; i < df.delta_phi.size(); i++)
    {
        sfasamento.push_back(-df.delta_phi[i]);  
        err_sfasamento.push_back(0);
        frequenza.push_back(df.freq[i] * 1000);
    }

    TVectorD root_sfasamento(sfasamento.size(), sfasamento.data());
    TVectorD root_freq(frequenza.size(), frequenza.data());

    TVectorD root_err_sfasamento(err_sfasamento.size(), err_sfasamento.data());

    TCanvas *c1 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    c1->Divide(2, 1);
    c1->cd(1);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico_sfas = new TGraphErrors(root_freq, root_sfasamento, root_err_freq, root_err_sfasamento);
    //TGraphErrors *grafico_trasf = new TGraphErrors("../../../dati_amp_R.txt", "%lg %lg %lg");
    grafico_sfas->SetMarkerColor(kAzure - 3);
    grafico_sfas->SetMarkerStyle(20);
    grafico_sfas->SetMarkerSize(0.8);
    grafico_sfas->SetTitle("Fit Sfasamento ai capi di C");
    grafico_sfas->GetXaxis()->SetTitle("f [Hz]");
    grafico_sfas->GetYaxis()->SetTitle("#Delta#phi [rad]");
    grafico_sfas->GetXaxis()->SetAxisColor(14);
    grafico_sfas->GetYaxis()->SetAxisColor(14);
    grafico_sfas->Draw("AP");

    TF1 *curva = new TF1("f2", curva_sfas, 0, 200000, 3);
    curva->SetLineColor(kRed);
    curva->SetLineStyle(2);
    curva->SetLineWidth(1);

    curva->SetParameter(0, 100);
    curva->SetParameter(1, 0.00098);
    curva->SetParameter(2, 9.7e-9);

    fit_results df_c;
    fit_on_json(curva, 3, grafico_sfas, df.freq, sfasamento, df_c, "../Fit_results", "df_c_sfasamento.json", 10000, 90000);

    TPaveStats *ptstats1;
    TText *ptstats_LaTex1;
    informazioni_fit_RLC_sfas(ptstats1,
                              ptstats_LaTex1,
                              to_string(0.0456),
                              to_string(49),
                              to_string(18.11),
                              to_string(1.21),
                              "9.90914e-04",
                              "6.49379e-05",
                              "9.80e-09",
                              "9.80343e-09",
                              "Sfasamento");

    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_sfas, "Dati sfasamento su C", "PE");
    legend->AddEntry(curva, "Curva interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    //--------------------------------------------------------------------------------------RESIDUI-----------------------------------------------
    c1->cd(2);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> scarti;
    run_test_sfas_C(scarti, frequenza, sfasamento, curva->GetParameter(0), curva->GetParameter(1), curva->GetParameter(2));
    TVectorD root_scarti(scarti.size(), scarti.data());

    TGraphErrors *grafico_scarti = new TGraphErrors(root_freq, root_scarti, root_err_freq, root_err_sfasamento);
    grafico_scarti->SetMarkerColor(kAzure - 3);
    grafico_scarti->SetMarkerStyle(20);
    grafico_scarti->SetMarkerSize(0.8);
    grafico_scarti->SetTitle("Scarti per lo sfasamento ai capi di C");
    grafico_scarti->GetXaxis()->SetTitle("frequenza [Hz]");
    grafico_scarti->GetYaxis()->SetTitle("#Delta#phi [rad]");
    grafico_scarti->GetXaxis()->SetAxisColor(14);
    grafico_scarti->GetYaxis()->SetAxisColor(14);
    grafico_scarti->Draw("ap");

    //LEGENDA
    TLegend *legends = new TLegend(0.15, 0.15, 0.5, 0.3);
    legends->AddEntry(grafico_scarti, "Dati", "PE");
    legends->SetTextSize(0.04);
    legends->SetBorderSize(1);
    legends->SetTextFont(22);
    legends->Draw();

    TLine *zero = new TLine(10000, 0, 110000, 0);
    zero->SetLineColor(kRed);
    zero->Draw("same");
}