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

    double ret = TMath::Exp(b * (x[0]) + a);
    return ret;
}

void delta_exp()
{

    d_tempo exp;
    exp.from_json_max("../Json", "max.json");
    exp.from_json_min("../Json", "min.json");

    TVectorD root_n_min(exp.n_min.size(), exp.n_min.data());
    //Qui è un modo malvagio per renderli positivi
    vector<double> new_v_min;
    for (auto c : exp.v_min)
    {
        new_v_min.push_back(-c);
    }
    TVectorD root_v_min(new_v_min.size(), new_v_min.data());

    TVectorD root_n_max(exp.n_max.size(), exp.n_max.data());
    TVectorD root_v_max(exp.v_max.size(), exp.v_max.data());

    TVectorD root_err_v_min(exp.err_v_max.size(), exp.err_v_max.data());
    TVectorD root_err_v_max(exp.err_v_min.size(), exp.err_v_min.data());

    vector<double> err_n_max(exp.err_v_max.size(), 0);
    vector<double> err_n_min(exp.err_v_min.size(), 0);
    TVectorD root_err_n_min(err_n_min.size(), err_n_min.data());
    TVectorD root_err_n_max(err_n_max.size(), err_n_max.data());

    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->Divide(2, 1, 0.00001, 0.00001);
    c1->cd(1);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    //--------------------MASSIMI-----------------------------------//
    TGraphErrors *grafico_exp_max = new TGraphErrors(root_n_max, root_v_max, root_err_n_max, root_err_v_max);
    grafico_exp_max->SetMarkerColor(kAzure - 3);
    grafico_exp_max->SetMarkerStyle(20);
    grafico_exp_max->SetMarkerSize(0.8);
    grafico_exp_max->SetTitle("Esponenziale");
    grafico_exp_max->GetXaxis()->SetTitle("Ordine n");
    grafico_exp_max->GetYaxis()->SetTitle("Voltaggio [mV]");
    grafico_exp_max->GetXaxis()->SetAxisColor(14);
    grafico_exp_max->GetYaxis()->SetAxisColor(14);
    grafico_exp_max->Draw("ap");

    TF1 *f1 = new TF1("f1", func, 0, 10, 2);
    f1->SetLineColor(kAzure - 3);
    f1->SetLineStyle(2);
    f1->SetLineWidth(1);

    fit_results delta_results;
    fit_on_json(f1, 2, grafico_exp_max, exp.n_max, exp.v_max, delta_results, "../Fit_results", "exp_max.json");

    TPaveStats *ptstats1;
    TText *ptstats_LaTex1;
    informazioni_fit_nl_2_param(ptstats1, ptstats_LaTex1, to_string(f1->GetChisquare()), to_string((int)f1->GetNDF()), to_string(f1->GetParameter(0)), to_string(f1->GetParError(0)), to_string(f1->GetParameter(1)), to_string(f1->GetParError(1)), "MAX");

    //---------------------------MINIMI
    TGraphErrors *grafico_exp_min = new TGraphErrors(root_n_min, root_v_min, root_err_n_min, root_err_v_min);
    grafico_exp_min->SetMarkerColor(kRed);
    grafico_exp_min->SetMarkerStyle(20);
    grafico_exp_min->SetMarkerSize(0.8);
    grafico_exp_min->SetTitle("Esponenziale");
    grafico_exp_min->GetXaxis()->SetTitle("Ordine n");
    grafico_exp_min->GetYaxis()->SetTitle("Voltaggio [mV]");
    grafico_exp_min->GetXaxis()->SetAxisColor(14);
    grafico_exp_min->GetYaxis()->SetAxisColor(14);
    grafico_exp_min->Draw("Psame");

    TF1 *f2 = new TF1("f2", func, 0, 10, 2);
    f2->SetLineColor(kRed);
    f2->SetLineStyle(2);
    f2->SetLineWidth(1);

    fit_results delta_results_min;
    fit_on_json(f2, 2, grafico_exp_min, exp.n_min, exp.v_min, delta_results_min, "../Fit_results", "exp_min.json");

    TPaveStats *ptstats2;
    TText *ptstats_LaTex2;
    informazioni_fit_nl_2_param(ptstats2,
                                ptstats_LaTex2,
                                to_string(f2->GetChisquare()),
                                to_string((int)f2->GetNDF()),
                                to_string(f2->GetParameter(0)),
                                to_string(f2->GetParError(0)),
                                to_string(f2->GetParameter(1)),
                                to_string(f2->GetParError(1)),
                                "MIN");

    //LEGENDA
    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->AddEntry(grafico_exp_max, "V_min", "PE");
    legend->AddEntry(grafico_exp_min, "V_max", "PE");
    legend->AddEntry(f1, "e^{a+b*x} interpolante", "l");
    legend->AddEntry(f2, "e^{a+b*x} interpolante", "l");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->SetTextFont(22);
    legend->Draw();

    //--------------------------------------QUA INIZIANO I RESIDUI
    c1->cd(2);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    vector<double> scarti_max;
    run_test_exp(scarti_max, exp.n_max, exp.v_max, f1->GetParameter(0), f1->GetParameter(1));
    TVectorD root_scarti_max(scarti_max.size(), scarti_max.data());

    vector<double> scarti_min;
    run_test_exp(scarti_min, exp.n_min, new_v_min, f2->GetParameter(0), f2->GetParameter(1));
    TVectorD root_scarti_min(scarti_min.size(), scarti_min.data());

    TGraphErrors *grafico_scarti_min = new TGraphErrors(root_n_min, root_scarti_min, root_err_n_min, root_err_v_min);
    grafico_scarti_min->SetMarkerColor(kRed);
    grafico_scarti_min->SetMarkerStyle(20);
    grafico_scarti_min->SetMarkerSize(0.8);
    grafico_scarti_min->SetTitle("Residui");
    grafico_scarti_min->GetXaxis()->SetTitle("Ordine n");
    grafico_scarti_min->GetYaxis()->SetTitle("Voltaggio [mV]");
    grafico_scarti_min->GetXaxis()->SetAxisColor(14);
    grafico_scarti_min->GetYaxis()->SetAxisColor(14);
    grafico_scarti_min->Draw("ap");

    TGraphErrors *grafico_scarti_max = new TGraphErrors(root_n_max, root_scarti_max, root_err_n_max, root_err_v_max);
    grafico_scarti_max->SetMarkerColor(kAzure - 3);
    grafico_scarti_max->SetMarkerStyle(20);
    grafico_scarti_max->SetMarkerSize(0.8);
    grafico_scarti_max->SetTitle("Residui");
    grafico_scarti_max->GetXaxis()->SetTitle("Ordine n");
    grafico_scarti_max->GetYaxis()->SetTitle("Voltaggio [mV]");
    grafico_scarti_max->GetXaxis()->SetAxisColor(14);
    grafico_scarti_max->GetYaxis()->SetAxisColor(14);
    grafico_scarti_max->Draw("Psame");

    //LEGENDA

    TLegend *legend1 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend1->AddEntry(grafico_scarti_max, "Scarti V_max", "PE");
    legend1->AddEntry(grafico_scarti_min, "Scarti V_min", "PE");
    legend1->SetTextSize(0.04);
    legend1->SetBorderSize(1);
    legend1->SetTextFont(22);
    legend1->Draw();

    //-------------------------------------------------------------UNIAMO I CAMPIONI
    
    TCanvas *c2 = new TCanvas("c2", "Canvas", 200, 10, 2000, 900);
    c2->Divide(2, 1, 0.00001, 0.00001);
    c2->cd(1);
    gPad->SetGrid();
    gPad->SetFillColor(0);
    
    ////Joino i vettori di v_max e v_min
    vector<double> somma_x, somma_y, err_somma_y, err_somma_x;
    for (int i = 0; i < exp.n_max.size(); i++)
    {
        somma_x.push_back(exp.n_max[i]);
        somma_y.push_back(exp.v_max[i]);
        err_somma_y.push_back(exp.err_v_max[i]);
        err_somma_x.push_back(0);
    }
    for (int i = 0; i < exp.n_min.size(); i++)
    {
        somma_x.push_back(exp.n_min[i]);
        somma_y.push_back(new_v_min[i]);
        err_somma_y.push_back(exp.err_v_min[i]);
        err_somma_x.push_back(0);
    }
    
    TVectorD root_somma_x(somma_x.size(), somma_x.data());
    TVectorD root_somma_y(somma_y.size(), somma_y.data());
    TVectorD root_err_somma_y(err_somma_y.size(), err_somma_y.data());
    TVectorD root_err_somma_x(err_somma_x.size(), err_somma_x.data());
    
    TGraphErrors *grafico_somma = new TGraphErrors(root_somma_x, root_somma_y, root_err_somma_x, root_err_somma_y);
    grafico_somma->SetMarkerColor(kAzure - 3);
    grafico_somma->SetMarkerStyle(20);
    grafico_somma->SetMarkerSize(0.8);
    grafico_somma->SetTitle("Esponenziale");
    grafico_somma->GetXaxis()->SetTitle("Ordine n");
    grafico_somma->GetYaxis()->SetTitle("Voltaggio [mV]");
    grafico_somma->GetXaxis()->SetAxisColor(14);
    grafico_somma->GetYaxis()->SetAxisColor(14);
    grafico_somma->Draw("AP");
    
    TF1 *f_somma = new TF1("f_somma", func, 0, 10, 2);
    f_somma->SetLineColor(kAzure - 3);
    f_somma->SetLineStyle(2);
    f_somma->SetLineWidth(1);
    
    fit_results delta_results_somma;
    fit_on_json(f_somma, 2, grafico_somma, somma_x, somma_y, delta_results_somma, "../Fit_results", "exp_somma.json");
    
    TPaveStats *ptstats_somma;
    TText *ptstats_LaTex_somma;
    informazioni_fit_nl_2_param(ptstats_somma,
                                ptstats_LaTex_somma,
                                to_string(f_somma->GetChisquare()),
                                to_string((int)f_somma->GetNDF()),
                                to_string(f_somma->GetParameter(0)),
                                to_string(f_somma->GetParError(0)),
                                to_string(f_somma->GetParameter(1)),
                                to_string(f_somma->GetParError(1)),
                                "Exp Somma");
    
    vector<double> scarti_somma;
    run_test_exp(scarti_somma, somma_x, somma_y, f_somma->GetParameter(0), f_somma->GetParameter(1));
    TVectorD root_scarti_exp_somma(scarti_somma.size(), scarti_somma.data());
    
    c2->cd(2);
    gPad->SetGrid();
    gPad->SetFillColor(0);
    
    TGraphErrors *grafico_scarti_somma = new TGraphErrors(root_somma_x, root_scarti_exp_somma, root_err_somma_x, root_err_somma_y);
    grafico_scarti_somma->SetMarkerColor(kAzure -3);
    grafico_scarti_somma->SetMarkerStyle(20);
    grafico_scarti_somma->SetMarkerSize(0.8);
    grafico_scarti_somma->SetTitle("Residui");
    grafico_scarti_somma->GetXaxis()->SetTitle("Ordine n");
    grafico_scarti_somma->GetYaxis()->SetTitle("Voltaggio [mV]");
    grafico_scarti_somma->GetXaxis()->SetAxisColor(14);
    grafico_scarti_somma->GetYaxis()->SetAxisColor(14);
    grafico_scarti_somma->Draw("ap");
}