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

void scarica_c_lin()
{

    dc scarica;
    scarica.from_json("../Json/", "scarica_c.json");

    TVectorD root_tempo(scarica.t.size(), scarica.t.data());
    TVectorD root_ln_v_v0(scarica.ln_v_v0.size(), scarica.ln_v_v0.data());
    TVectorD root_err_tempo(scarica.err_t.size(), scarica.err_t.data());
    TVectorD root_err_ln_v_v0(scarica.err_ln_v_v0.size(), scarica.err_ln_v_v0.data());

    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->Divide(2, 1, 0.00001, 0.00001);
    c1->cd(1);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TGraphErrors *grafico = new TGraphErrors(root_tempo, root_ln_v_v0, root_err_tempo, root_err_ln_v_v0);
    grafico->SetMarkerColor(kAzure - 3);
    grafico->SetMarkerStyle(20);
    grafico->SetMarkerSize(0.6);
    grafico->SetTitle("Scarica C Fit Lineare");
    grafico->GetXaxis()->SetTitle("tempo [us]");
    grafico->GetYaxis()->SetTitle("Ln[V/V_{0}]");
    grafico->GetXaxis()->SetAxisColor(14);
    grafico->GetYaxis()->SetAxisColor(14);
    grafico->Draw("AP");

    TF1 *f1 = new TF1("f1", func, 0, 93, 2);
    f1->SetLineColor(kRed);
    f1->SetLineStyle(2);
    f1->SetLineWidth(1);

    //f1->SetParameter(0, 7);
    //f1->SetParameter(1, -4);

    fit_results carica_results;
    fit_on_json(f1, 2, grafico, scarica.t, scarica.ln_v_v0, carica_results, "../Fit_results", "scarica_c_lineare.json");

    TPaveStats *ptstats;
    TText *ptstats_LaTex;
    fit_results fit_results;
    fit_results.root_from_json("../Fit_results", "scarica_c_lineare.json");
    informazioni_fit_lineare(ptstats, ptstats_LaTex, to_string(fit_results.chi_square[0]), to_string((int)fit_results.dof[0]), to_string(fit_results.a[0]), to_string(fit_results.err_a[0]), to_string(fit_results.b[0]), to_string(fit_results.err_b[0]), to_string(fit_results.rho[0]), to_string(fit_results.t_student[0]), to_string(fit_results.sigma_post[0]), "Fit Lineare");

    //LEGENDA

    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    //legend->SetHeader("Legenda", "C");
    legend->AddEntry(grafico, "Dati con errore", "PE");
    legend->AddEntry(f1, "a + bx interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    //------------------------SCARTI
    c1->cd(2);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> err_t(scarica.err_ln_v.size(), 0);
    TVectorD root_err_t(err_t.size(), err_t.data());

    vector<double> scarti;

    run_test(scarti, scarica.t, scarica.ln_v_v0, fit_results.b[0], fit_results.a[0]);

    TVectorD root_scarti(scarti.size(), scarti.data());

    TGraphErrors *grafico1 = new TGraphErrors(root_tempo, root_scarti, root_err_t, root_err_ln_v_v0);
    grafico1->SetMarkerColor(kAzure - 3);
    grafico1->SetMarkerStyle(20);
    grafico1->SetMarkerSize(0.8);
    grafico1->SetTitle("Residui Scarica C");
    grafico1->GetXaxis()->SetTitle("tempo [us]");
    grafico1->GetYaxis()->SetTitle("Voltaggio [mV]");
    grafico1->GetXaxis()->SetAxisColor(14);
    grafico1->GetYaxis()->SetAxisColor(14);
    grafico1->Draw("AP");

    TLine *line = new TLine(0, 0, 93, 0);

    line->SetLineColor(kRed);
    line->Draw("same");

    TLegend *legend1 = new TLegend(0.15, 0.15, 0.5, 0.3);
    //legend->SetHeader("Legenda", "C");
    legend1->AddEntry(grafico, "Dati con errore", "PE");
    legend1->AddEntry(f1, "a + bx interpolante", "l");
    legend1->SetTextSize(0.04);
    legend1->SetBorderSize(1);
    legend1->SetTextFont(22);
    legend1->Draw();
}
