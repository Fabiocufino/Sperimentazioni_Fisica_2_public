
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
#include "usual.h"
using namespace std;

void cromatica_histo()
{
    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);

    c1->SetGrid();
    c1->SetFillColor(0);

    TH1D *crom = new TH1D("Parametri Istogramma", "Aberrazione Cromatica", 40, 10, 700);
    crom->GetXaxis()->SetRangeUser(-20, 700);
    crom->SetFillColorAlpha(2, 0.65);
    crom->GetYaxis()->SetTitle("frequenza");
    crom->GetXaxis()->SetTitle("v_{i}");
    crom->SetLineColor(1);

    ifstream fabio("../File/cromatica_v_f.txt");
    double x;
    while (fabio >> x)
    {
        crom->Fill(x);
    }
    ifstream marco("../File/cromatica_v_m.txt");
    double y;
    while (marco >> y)
    {
        crom->Fill(y);
    }
    ifstream tommaso("../File/cromatica_v_t.txt");
    double z;
    while (tommaso >> z)
    {
        crom->Fill(z);
    }
    crom->Draw();
    crom->Fit("gaus");

    TLine *tre_p = new TLine(103.02, 0, 103.02, 14);
    tre_p->SetLineColor(2);
    tre_p->Draw("same");

    TLine *tre_m = new TLine(2.76, 0, 2.76, 14);
    tre_m->SetLineColor(2);
    tre_m->Draw("same");

    //TBox *sig=new TBox(200, 6, 300, 14);
    //sig->Draw();

    TLegend *legend3 = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend3->AddEntry(tre_p,"+3#sigma","l");
    legend3->SetTextSize(0.04);
    legend3->SetBorderSize(0);
    legend3->Draw();
}