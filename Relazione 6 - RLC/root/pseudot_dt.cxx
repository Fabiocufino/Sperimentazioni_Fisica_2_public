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
#include "../Programmi/json.hpp"
#ifndef DATACLASS
#include "root_dataclass.h"
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

void pseudot_dt()
{
    d_tempo pseudo_min, pseudo_max;
    pseudo_max.from_json_max("../Json", "max.json");
    pseudo_min.from_json_min("../Json", "min.json");

    TVectorD root_n_min(pseudo_min.n_min.size(), pseudo_min.n_min.data());
    TVectorD root_n_max(pseudo_max.n_max.size(), pseudo_max.n_max.data());
    TVectorD root_t_p(pseudo_max.t_p.size(), pseudo_max.t_p.data());
    TVectorD root_t_m(pseudo_min.t_m.size(), pseudo_min.t_m.data());
    TVectorD root_t_max(pseudo_max.t_max.size(), pseudo_max.t_max.data());
    TVectorD root_t_min(pseudo_min.t_min.size(), pseudo_min.t_min.data());

    TVectorD root_err_t_p(pseudo_max.err_t_p.size(), pseudo_max.err_t_p.data());
    TVectorD root_err_t_m(pseudo_min.err_t_m.size(), pseudo_min.err_t_m.data());
    TVectorD root_err_t_max(pseudo_max.err_t_max.size(), pseudo_max.err_t_max.data());
    TVectorD root_err_t_min(pseudo_min.err_t_min.size(), pseudo_min.err_t_min.data());
    vector<double> err_n_max(pseudo_max.err_t_max.size(), 0);
    vector<double> err_n_min(pseudo_min.err_t_min.size(), 0);

    TVectorD root_err_n_max(err_n_max.size(), err_n_max.data());
    TVectorD root_err_n_min(err_n_min.size(), err_n_min.data());

    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->Divide(2, 1, 0.00001, 0.00001);
    c1->cd(1);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    //Grafico per massimi
    TGraphErrors *gr_max = new TGraphErrors(root_n_max, root_t_max, root_err_n_max, root_err_t_max);
    gr_max->SetMarkerColor(kRed);
    gr_max->SetMarkerStyle(20);
    gr_max->SetMarkerSize(0.8);
    gr_max->SetTitle("Fit lineari a campioni separati");
    gr_max->GetXaxis()->SetTitle("Ordine n");
    gr_max->GetYaxis()->SetTitle("Tempo [us]");
    gr_max->GetXaxis()->SetAxisColor(14);
    gr_max->GetYaxis()->SetAxisColor(14);
    gr_max->Draw("AP");

    //Grafico per minimi
    TGraphErrors *gr_min = new TGraphErrors(root_n_min, root_t_min, root_err_n_min, root_err_t_min);
    gr_min->SetMarkerColor(kRed);
    gr_min->SetMarkerStyle(24);
    gr_min->SetMarkerSize(0.8);
    gr_min->GetXaxis()->SetAxisColor(14);
    gr_min->GetYaxis()->SetAxisColor(14);
    gr_min->Draw("Psame");

    //Grafico per derivate positive
    TGraphErrors *gr_p = new TGraphErrors(root_n_max, root_t_p, root_err_n_max, root_err_t_p);
    gr_p->SetMarkerColor(kAzure);
    gr_p->SetMarkerStyle(20);
    gr_p->SetMarkerSize(0.8);
    gr_p->GetXaxis()->SetAxisColor(14);
    gr_p->GetYaxis()->SetAxisColor(14);
    gr_p->Draw("Psame");

    //Grafico derivate negative
    TGraphErrors *gr_m = new TGraphErrors(root_n_min, root_t_m, root_err_n_min, root_err_t_m);
    gr_m->SetMarkerColor(kAzure);
    gr_m->SetMarkerStyle(24);
    gr_m->SetMarkerSize(0.8);
    gr_m->GetXaxis()->SetAxisColor(14);
    gr_m->GetYaxis()->SetAxisColor(14);
    gr_m->Draw("Psame");

    TF1 *ret_t_m = new TF1("ret_t_m", func, 0, 10, 2);
    ret_t_m->SetLineColor(kRed);
    ret_t_m->SetLineStyle(2);
    ret_t_m->SetLineWidth(1);

    TF1 *ret_t_p = new TF1("ret_t_p", func, 0, 10, 2);
    ret_t_p->SetLineColor(kAzure);
    ret_t_p->SetLineStyle(2);
    ret_t_p->SetLineWidth(1);

    TF1 *ret_t_max = new TF1("ret_t_max", func, 0, 10, 2);
    ret_t_max->SetLineColor(kRed);
    ret_t_max->SetLineStyle(2);
    ret_t_max->SetLineWidth(1);

    TF1 *ret_t_min = new TF1("ret_t_min", func, 0, 10, 2);
    ret_t_min->SetLineColor(kAzure);
    ret_t_min->SetLineStyle(2);
    ret_t_min->SetLineWidth(1);

    //Salviamo i risultati dei 4 fit separatamente
    fit_results ps_t_min, ps_t_max, ps_t_m, ps_t_p;
    fit_on_json(ret_t_max, 2, gr_max, pseudo_max.n_max, pseudo_max.t_max, ps_t_max, "../Fit_results", "gr_max.json");
    fit_on_json(ret_t_min, 2, gr_min, pseudo_min.n_min, pseudo_min.t_min, ps_t_min, "../Fit_results", "gr_min.json");
    fit_on_json(ret_t_p, 2, gr_p, pseudo_max.n_max, pseudo_max.t_p, ps_t_p, "../Fit_results", "gr_p.json");
    fit_on_json(ret_t_m, 2, gr_m, pseudo_min.n_min, pseudo_min.t_m, ps_t_m, "../Fit_results", "gr_m.json");

    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(gr_max, "Dati t^{MAX} con errore", "PE");
    legend->AddEntry(gr_min, "Dati t^{MIN} con errore", "PE");
    legend->AddEntry(gr_p, "Dati t^{+} con errore", "PE");
    legend->AddEntry(gr_m, "Dati t^{-} con errore", "PE");
    legend->AddEntry(ret_t_max, "a + bx interpolante t^{MAX}", "l");
    legend->AddEntry(ret_t_min, "a + bx interpolante t^{MIN}", "l");
    legend->AddEntry(ret_t_p, "a + bx interpolante t^{+}", "l");
    legend->AddEntry(ret_t_m, "a + bx interpolante t^{-}", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    //----------------------------------------------------------------------INTERPOLAZIONE DOPPIA

    c1->cd(2);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> somma_x_intercette, somma_x_stazionari, somma_y_intercette, somma_y_stazionari, err_somma_y_stazionari, err_somma_y_intercette;
    //Intercette
    for (int i = 0; i < pseudo_max.t_p.size(); i++)
    {
        somma_y_intercette.push_back(pseudo_max.t_p[i]);
        somma_x_intercette.push_back(pseudo_max.n_max[i]);
        err_somma_y_intercette.push_back(pseudo_max.err_t_p[i]);
    }
    for (int i = 0; i < pseudo_min.t_m.size(); i++)
    {
        somma_y_intercette.push_back(pseudo_min.t_m[i]);
        somma_x_intercette.push_back(pseudo_min.n_min[i]);
        err_somma_y_intercette.push_back(pseudo_min.err_t_m[i]);
    }

    //Stazionari
    for (int i = 0; i < pseudo_max.t_max.size(); i++)
    {
        somma_y_stazionari.push_back(pseudo_max.t_max[i]);
        somma_x_stazionari.push_back(pseudo_max.n_max[i]);
        err_somma_y_stazionari.push_back(pseudo_max.err_t_max[i]);
    }
    for (int i = 0; i < pseudo_min.t_min.size(); i++)
    {
        somma_y_stazionari.push_back(pseudo_min.t_min[i]);
        somma_x_stazionari.push_back(pseudo_min.n_min[i]);
        err_somma_y_stazionari.push_back(pseudo_min.err_t_min[i]);
    }

    TVectorD root_x_intercette(somma_x_intercette.size(), somma_x_intercette.data());
    TVectorD root_y_intercette(somma_y_intercette.size(), somma_y_intercette.data());
    TVectorD root_x_stazionari(somma_x_stazionari.size(), somma_x_stazionari.data());
    TVectorD root_y_stazionari(somma_y_stazionari.size(), somma_y_stazionari.data());
    TVectorD root_err_y_stazionari(err_somma_y_stazionari.size(), err_somma_y_stazionari.data());
    TVectorD root_err_y_intercette(err_somma_y_intercette.size(), err_somma_y_intercette.data());
    vector<double> err_x_intercetta(err_somma_y_intercette.size(), 0);
    vector<double> err_x_stazionari(err_somma_y_stazionari.size(), 0);
    TVectorD root_err_x_intercette(err_x_intercetta.size(), err_x_intercetta.data());
    TVectorD root_err_x_stazionari(err_x_stazionari.size(), err_x_stazionari.data());

    TGraphErrors *gr_intercept = new TGraphErrors(root_x_intercette, root_y_intercette, root_err_x_intercette, root_err_y_intercette);
    gr_intercept->SetMarkerColor(kRed);
    gr_intercept->SetMarkerStyle(20);
    gr_intercept->SetMarkerSize(0.8);
    gr_intercept->SetTitle("Fit lineari a campioni uniti");
    gr_intercept->GetXaxis()->SetTitle("Ordine n");
    gr_intercept->GetYaxis()->SetTitle("Tempo [us]");
    gr_intercept->GetXaxis()->SetAxisColor(14);
    gr_intercept->GetYaxis()->SetAxisColor(14);
    gr_intercept->Draw("AP");

    TGraphErrors *gr_maxima = new TGraphErrors(root_x_stazionari, root_y_stazionari, root_err_x_stazionari, root_err_y_stazionari);
    gr_maxima->SetMarkerColor(kAzure);
    gr_maxima->SetMarkerStyle(20);
    gr_maxima->SetMarkerSize(0.8);
    gr_maxima->GetXaxis()->SetAxisColor(14);
    gr_maxima->GetYaxis()->SetAxisColor(14);
    gr_maxima->Draw("Psame");

    TF1 *ret_stazionari = new TF1("ret_stazionari", func, 0, 10, 2);
    ret_stazionari->SetLineColor(kRed);
    ret_stazionari->SetLineStyle(2);
    ret_stazionari->SetLineWidth(1);

    TF1 *ret_intercette = new TF1("ret_intercette", func, 0, 10, 2);
    ret_intercette->SetLineColor(kAzure);
    ret_intercette->SetLineStyle(2);
    ret_intercette->SetLineWidth(1);

    //Salviamo i risultati dei 2 fit separatamente
    fit_results ps_stazionari, ps_intercette;
    fit_on_json(ret_stazionari, 2, gr_maxima, somma_x_stazionari, somma_y_stazionari, ps_stazionari, "../Fit_results", "gr_stazionari.json");
    fit_on_json(ret_intercette, 2, gr_intercept, somma_x_intercette, somma_y_intercette, ps_intercette, "../Fit_results", "gr_intercette.json");

    //LEGENDA
    TLegend *legend1 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend1->AddEntry(gr_intercept, "Dati t^{+} e t^{-}", "PE");
    legend1->AddEntry(gr_maxima, "Dati t^{MAX} e t^{MIN}", "PE");
    legend1->AddEntry(ret_stazionari, "a + bx interpolante", "l");
    legend1->AddEntry(ret_intercette, "a + bx interpolante", "l");
    legend1->SetTextSize(0.04);
    legend1->SetBorderSize(1);
    legend1->SetTextFont(22);
    legend1->Draw();

    //-----------------------------------------------------------------------------SCARTI
    //Scarti m e p
    TCanvas *c3 = new TCanvas("c3", "Canvas3", 200, 10, 2000, 900);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> scarti_m;
    run_test(scarti_m, pseudo_min.n_min, pseudo_min.t_m, ret_t_m->GetParameter(0), ret_t_m->GetParameter(1));
    TVectorD root_scarti_m(scarti_m.size(), scarti_m.data());

    vector<double> scarti_p;
    run_test(scarti_p, pseudo_max.n_max, pseudo_max.t_p, ret_t_p->GetParameter(0), ret_t_p->GetParameter(1));
    TVectorD root_scarti_p(scarti_p.size(), scarti_p.data());

    TGraphErrors *gr_scarti_p = new TGraphErrors(root_n_max, root_scarti_p, root_err_n_max, root_err_t_p);
    gr_scarti_p->SetMarkerColor(kAzure);
    gr_scarti_p->SetMarkerStyle(20);
    gr_scarti_p->SetMarkerSize(0.8);
    gr_scarti_p->GetXaxis()->SetAxisColor(14);
    gr_scarti_p->GetYaxis()->SetAxisColor(14);
    gr_scarti_p->Draw("AP");

    TGraphErrors *gr_scarti_m = new TGraphErrors(root_n_min, root_scarti_m, root_err_n_min, root_err_t_m);
    gr_scarti_m->SetMarkerColor(kRed);
    gr_scarti_m->SetMarkerStyle(20);
    gr_scarti_m->SetMarkerSize(0.8);
    gr_scarti_m->GetXaxis()->SetAxisColor(14);
    gr_scarti_m->GetYaxis()->SetAxisColor(14);
    gr_scarti_m->Draw("Psame");

    //LEGENDA
    TLegend *legend2 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend2->AddEntry(gr_scarti_p, "Scarti t^{+}", "PE");
    legend2->AddEntry(gr_scarti_m, "Scarti t^{-}", "PE");
    legend2->SetTextSize(0.04);
    legend2->SetBorderSize(1);
    legend2->SetTextFont(22);
    legend2->Draw();

    //Scarti max e min
    TCanvas *c4 = new TCanvas("c4", "Canvas4", 200, 10, 2000, 900);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> scarti_max;
    run_test(scarti_max, pseudo_max.n_max, pseudo_max.t_max, ret_t_max->GetParameter(0), ret_t_max->GetParameter(1));
    TVectorD root_scarti_max(scarti_max.size(), scarti_max.data());

    vector<double> scarti_min;
    run_test(scarti_min, pseudo_min.n_min, pseudo_min.t_min, ret_t_min->GetParameter(0), ret_t_min->GetParameter(1));
    TVectorD root_scarti_min(scarti_min.size(), scarti_min.data());

    TGraphErrors *gr_scarti_max = new TGraphErrors(root_n_max, root_scarti_max, root_err_n_max, root_err_t_max);
    gr_scarti_max->SetMarkerColor(kAzure);
    gr_scarti_max->SetMarkerStyle(20);
    gr_scarti_max->SetMarkerSize(0.8);
    gr_scarti_max->GetXaxis()->SetAxisColor(14);
    gr_scarti_max->GetYaxis()->SetAxisColor(14);
    gr_scarti_max->Draw("AP");

    TGraphErrors *gr_scarti_min = new TGraphErrors(root_n_min, root_scarti_min, root_err_n_min, root_err_t_min);
    gr_scarti_min->SetMarkerColor(kRed);
    gr_scarti_min->SetMarkerStyle(20);
    gr_scarti_min->SetMarkerSize(0.8);
    gr_scarti_min->GetXaxis()->SetAxisColor(14);
    gr_scarti_min->GetYaxis()->SetAxisColor(14);
    gr_scarti_min->Draw("Psame");

    //LEGENDA
    TLegend *legend3 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend3->AddEntry(gr_scarti_max, "Scarti t^{MAX}", "PE");
    legend3->AddEntry(gr_scarti_min, "Scarti t^{MIN}", "PE");
    legend3->SetTextSize(0.04);
    legend3->SetBorderSize(1);
    legend3->SetTextFont(22);
    legend3->Draw();
}
