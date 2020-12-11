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
//#include "usual.h"
using namespace std;

void bessel_f()
{
    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 1500, 900);
    c1->Divide(2, 1, 0.00001, 0.00001);
    c1->cd(1);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TH1D *coniugati = new TH1D("Coniugati", "", 20, 64, 68);
    ifstream fabio("../File/f_alg_f.txt");
    double x;
    while (fabio >> x)
    {
        coniugati->Fill(x);
    }
    ifstream marco("../File/f_alg_m.txt");
    double y;
    while (marco >> y)
    {
        coniugati->Fill(y);
    }
    ifstream tommaso("../File/f_alg_t.txt");
    double z;
    while (tommaso >> z)
    {
        coniugati->Fill(z);
    }

    coniugati->GetYaxis()->SetRangeUser(0, 15);
    coniugati->SetFillColor(2);
    coniugati->GetYaxis()->SetTitle("frequenza");
    coniugati->GetXaxis()->SetTitle("f_{i} [mm]");
    coniugati->SetLineColor(1);
    coniugati->SetFillColorAlpha(2, 0.65);
    coniugati->Draw();

    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->SetHeader("Punti Coniugati", "C");
    legend->AddEntry(coniugati, "Istogramma", "F");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->Draw();

    c1->cd(2);
    gPad->SetGrid();
    gPad->SetFillColor(0);

    TH1D *bessel = new TH1D("Bessel", "", 20, 64, 68);
    ifstream fabio2("../File/bessel_f_f.txt");
    double x2;
    while (fabio2 >> x2)
    {
        bessel->Fill(x2);
    }
    ifstream marco2("../File/bessel_f_m.txt");
    double y2;
    while (marco2 >> y2)
    {
        bessel->Fill(y2);
    }
    ifstream tommaso2("../File/bessel_f_t.txt");
    double z2;
    while (tommaso2 >> z2)
    {
        bessel->Fill(z2);
    }

    bessel->GetYaxis()->SetLimits(0, 15);
    bessel->SetFillColor(4);
    bessel->GetYaxis()->SetTitle("frequenza");
    bessel->GetXaxis()->SetTitle("f_{i} [mm]");
    bessel->SetLineColor(1);
    bessel->SetFillColorAlpha(4, 0.65);
    bessel->Draw();

    TLegend *legend2 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend2->SetHeader("Bessel", "C");
    legend2->AddEntry(bessel, "Istogramma", "F");
    legend2->SetTextSize(0.04);
    legend2->SetBorderSize(1);
    legend2->Draw();
}