
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

void sferica()
{
    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 1500, 900);

    c1->SetGrid();
    c1->SetFillColor(0);

    ifstream fab("../File/aberr_sferica_l_f.txt");
    double val;
    double f = 1;
    vector<double> sferica_f;
    vector<double> err_sferica_f;
    while (fab >> val)
    {
        if (f == 1)
            sferica_f.push_back(val);
        if (f == 2)
        {
            err_sferica_f.push_back(val);
            f = 0;
        }
        f++;
    }

    vector<double> err_asse_x(10);
    for (int i = 0; i < err_sferica_f.size(); i++)
    {
        err_asse_x.push_back(0);
    }
    TVectorD root_err_asse_x(err_asse_x.size(), err_asse_x.data());

    TVectorD root_sferica_f(sferica_f.size(), sferica_f.data());
    TVectorD root_err_sferica_f(err_sferica_f.size(), err_sferica_f.data());
    TVectorD asse_x_f(sferica_f.size());
    for (int i = 0; i < sferica_f.size(); i++)
        asse_x_f(i) = i + 1;

    asse_x_f.Print();

    TGraphErrors *fabio = new TGraphErrors(asse_x_f, root_sferica_f, root_err_asse_x, root_err_sferica_f);

    fabio->SetMarkerColor(2);
    fabio->SetMarkerStyle(20);
    fabio->SetMarkerSize(0.8);
    fabio->SetTitle("Operatore A");
    fabio->GetXaxis()->SetTitle("Numero della misurazione");
    fabio->GetYaxis()->SetTitle("L [1/m]");
    fabio->GetXaxis()->SetAxisColor(14);
    fabio->GetYaxis()->SetAxisColor(14);
    fabio->GetXaxis()->SetLimits(0, 11);
    //fabio->GetYaxis()->SetRangeUser(3, 15);

    fabio->Draw("AP");

    //------------------Mark-------------
<<<<<<< HEAD
    ifstream mar("../File/aberr_sferica_l_m.txt");
=======
    ifstream mar("../File/aberr_sferica_l_f.txt");
>>>>>>> 2ef5b76249cee7383e50ff8ea5e106f364d99dd5
    double val1;
    double m = 1;
    vector<double> sferica_m;
    vector<double> err_sferica_m;
    while (mar >> val1)
    {
<<<<<<< HEAD
        if (m == 1)
            sferica_m.push_back(val1);
        if (m == 2)
        {
            err_sferica_m.push_back(val1);
            m = 0;
        }
        m++;
    }
    vector<double> asse_x_m;
    for (int i = 1; i <= err_sferica_m.size(); i++)
    {
        asse_x_m.push_back(i + 0.1);
    }
    TVectorD root_asse_x_m(asse_x_m.size(), asse_x_m.data());

    TVectorD root_sferica_m(sferica_m.size(), sferica_m.data());
    TVectorD root_err_sferica_m(err_sferica_m.size(), err_sferica_m.data());

    TGraphErrors *marco = new TGraphErrors(root_asse_x_m, root_sferica_m, root_err_asse_x, root_err_sferica_m);
=======
        if (i == 0)
            sferica_m.push_back(val1);
        if (i == 1)
            err_sferica_m.push_back(val1);
    }

    TVectorD root_sferica_m(sferica_m.size(), sferica_m.data());
    TVectorD root_err_sferica_m(err_sferica_m.size(), err_sferica_m.data());
    TVectorD asse_x_m(sferica_f.size());
    for (int i = 0; i < sferica_m.size(); i++)
        asse_x_m(i) = i + 1;

    TGraphErrors *marco = new TGraphErrors(asse_x_m, root_sferica_m, root_err_sferica_m);
>>>>>>> 2ef5b76249cee7383e50ff8ea5e106f364d99dd5

    marco->SetMarkerColor(3);
    marco->SetMarkerStyle(20);
    marco->SetMarkerSize(0.8);
    marco->SetTitle("Operatore B");
    marco->GetXaxis()->SetTitle("Numero della misurazione");
    marco->GetYaxis()->SetTitle("l [1/m]");
    marco->GetXaxis()->SetAxisColor(14);
    marco->GetYaxis()->SetAxisColor(14);
<<<<<<< HEAD
    marco->GetXaxis()->SetLimits(0, 11);

=======
 
>>>>>>> 2ef5b76249cee7383e50ff8ea5e106f364d99dd5
    marco->Draw("Psame");
    //----------------Tom-------------
    ifstream tom("../File/aberr_sferica_l_t.txt");
    double val2;
    double t = 1;
    vector<double> sferica_t;
    vector<double> err_sferica_t;
    while (tom >> val2)
    {
        if (t == 1)
            sferica_t.push_back(val2);
        if (t == 2)
        {
            err_sferica_t.push_back(val2);
            t = 0;
        }
        t++;
    }
    vector<double> asse_x_t;
    for (int i = 1; i <= err_sferica_t.size(); i++)
    {
        asse_x_t.push_back(i + 0.2);
    }
    TVectorD root_asse_x_t(asse_x_t.size(), asse_x_t.data());

    TVectorD root_sferica_t(sferica_t.size(), sferica_t.data());
    TVectorD err_root_sferica_t(err_sferica_t.size(), err_sferica_t.data());

    TGraphErrors *tommaso = new TGraphErrors(root_asse_x_t, root_sferica_t, root_err_asse_x, err_root_sferica_t);

    tommaso->SetMarkerColor(4);
    tommaso->SetMarkerStyle(20);
    tommaso->SetMarkerSize(0.8);
    tommaso->SetTitle("Operatore C");
    tommaso->GetXaxis()->SetTitle("Numero della misurazione");
    tommaso->GetYaxis()->SetTitle(" [1/m]");
    tommaso->GetXaxis()->SetAxisColor(14);
    tommaso->GetYaxis()->SetAxisColor(14);

    tommaso->Draw("Psame");

    TLegend *legend = new TLegend(0.15, 0.15, 0.5, 0.3);
    legend->SetHeader("Aberrazione sferica", "C");
    legend->AddEntry(fabio, "Operatore A", "P");
    legend->AddEntry(marco, "Operatore B", "P");
    legend->AddEntry(tommaso, "Operatore C", "P");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(1);
    legend->Draw();
}