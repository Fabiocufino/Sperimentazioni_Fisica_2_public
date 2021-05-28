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

    double ret = TMath::Exp((-1./b) * (x[0]) + a);
    return ret;
}

void carica_altern()
{

    dc carica;
    carica.from_json("../Json/", "scarica_c.json");

    TVectorD root_tempo(carica.t.size(), carica.t.data());
    TVectorD root_v_v0(carica.v_v0.size(), carica.v_v0.data());
    TVectorD root_err_tempo(carica.err_t.size(), carica.err_t.data());
    TVectorD root_err_v_v0(carica.err_v_v0.size(), carica.err_v_v0.data());

    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->SetGrid();
    c1->SetFillColor(0);

    TGraphErrors *grafico = new TGraphErrors(root_tempo, root_v_v0, root_err_tempo, root_err_v_v0);
    grafico->SetMarkerColor(kAzure - 3);
    grafico->SetMarkerStyle(20);
    grafico->SetMarkerSize(0.4);
    grafico->SetTitle("Carica R");
    grafico->GetXaxis()->SetTitle("tempo [us]");
    grafico->GetYaxis()->SetTitle("Voltaggio [mV]");
    grafico->GetXaxis()->SetAxisColor(14);
    grafico->GetYaxis()->SetAxisColor(14);
    grafico->Draw("AP");

    TF1 *f1 = new TF1("f1", func, 0, 45, 2);
    f1->SetLineColor(kRed);
    f1->SetLineStyle(2);
    f1->SetLineWidth(2);

    f1->SetParameter(0, 0.01);
    f1->SetParameter(1, 27);

    fit_results carica_results;
    fit_on_json(f1, 2, grafico, carica.t, carica.v_v0, carica_results, "../Fit_results", "scarica_c_altern.json");
}
