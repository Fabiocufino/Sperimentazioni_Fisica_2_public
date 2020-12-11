
#include "TH1.h"
#include "TMath.h"
#include <cmath>
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "fstream"
#include "TFitResult.h"
#include "TMatrixD.h"
#include "vector"
#include "iostream"
using namespace std;

void hist_f_i()
{
    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->Divide(3, 1, 0.00001, 0.00001);
    c1->cd(1);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TH1D *fab = new TH1D("Operatore A", "", 10, 64, 68);
    ifstream fabio("../File/f_alg_f.txt");
    double x;
    while (fabio >> x)
    {
        fab->Fill(x);
    }
    fab->GetYaxis()->SetRangeUser(0, 10);
    fab->SetFillColorAlpha(2, 0.65);
    fab->GetYaxis()->SetTitle("frequenza");
    fab->GetXaxis()->SetTitle("f_{i} [mm]");
    fab->SetLineColor(1);
    fab->Draw();
    fab->Fit("gaus");

    c1->cd(2);
    gPad->SetGrid();
    gPad->SetFillColor(0);
    TH1D *mar = new TH1D("Operatore B", "", 10, 64, 68);
    ifstream marco("../File/f_alg_m.txt");
    double y;
    while (marco >> y)
    {
        mar->Fill(y);
    }
    mar->GetYaxis()->SetRangeUser(0, 10);
    mar->SetFillColorAlpha(3, 0.65);
    mar->GetYaxis()->SetTitle("frequenza");
    mar->GetXaxis()->SetTitle("f_{i} [mm]");
    mar->SetLineColor(1);
    mar->Draw();
    mar->Fit("gaus");

    c1->cd(3);
    gPad->SetGrid();
    gPad->SetFillColor(0);
    TH1D *tom = new TH1D("Operatore C", "", 10, 64, 68);
    ifstream tommaso("../File/f_alg_t.txt");
    double z;
    while (tommaso >> z)
    {
        tom->Fill(z);
    }
    tom->GetYaxis()->SetRangeUser(0, 10);
    //tom->SetFillColor(4);
    tom->SetFillColorAlpha(4, 0.65);
    tom->GetYaxis()->SetTitle("frequenza");
    tom->GetXaxis()->SetTitle("f_{i} [mm]");
    tom->SetLineColor(1);
    tom->Draw();
    tom->Fit("gaus");
}