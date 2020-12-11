
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

//auto change_vector(TVectorD &r_x, vector<double> x){
//
//    //TVectorD r_x(x.size());
//    for (int i = 0; i < x.size(); i++)
//    {
//        r_x(i) = x[i];
//    }
//}

void errori_coniugati()
{

    TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 900);
    c1->SetGrid();

    vector<double> err_p_fabio;
    vector<double> err_q_fabio;
    vector<double> p_1_fabio;
    ifstream fab("../File/coniugati_fabio.txt");
    double f;
    int i = 1;
    while (fab >> f)
    {
        if (i == 1)
            p_1_fabio.push_back(f);

        if (i == 3)
            err_p_fabio.push_back(f);
        if (i == 4)
        {
            err_q_fabio.push_back(f);
            i = 0;
        }
        i++;
    }

    //TVectorD root_p_1_fabio(p_1_fabio.size());
    //for (int q = 0; q < p_1_fabio.size(); q++)
    //{
    //    root_p_1_fabio(q) = p_1_fabio[q];
    //}
    TVectorD root_p_1_fabio(p_1_fabio.size(),p_1_fabio.data());

    //-----------------------------MARCO----------------------------------
    vector<double> err_p_marco;
    vector<double> err_q_marco;
    vector<double> p_1_marco;
    ifstream mar("../File/coniugati_marco.txt");
    double k;
    int m = 1;
    while (mar >> k)
    {
        if (m == 1)
            p_1_marco.push_back(k);
        if (m == 3)
            err_p_marco.push_back(k);
        if (m == 4)
        {
            err_q_marco.push_back(k);
            m = 0;
        }
        m++;
    }
    TVectorD root_p_1_marco(p_1_marco.size());
    for (int q = 0; q < p_1_marco.size(); q++)
    {
        root_p_1_marco(q) = p_1_marco[q];
    }

    //----------------------------TOMMASO-----------------------------
    vector<double> err_p_tommaso;
    vector<double> err_q_tommaso;
    vector<double> p_1_tommaso;
    ifstream tom("../File/coniugati_tommaso.txt");
    double t;
    int n = 1;
    while (tom >> t)
    {
        if (n == 1)
            p_1_tommaso.push_back(t);
        if (n == 3)
            err_p_tommaso.push_back(t);
        if (n == 4)
        {
            err_q_tommaso.push_back(t);
            n = 0;
        }
        n++;
    }
    TVectorD root_p_1_tommaso(p_1_tommaso.size());
    for (int q = 0; q < p_1_tommaso.size(); q++)
    {
        root_p_1_tommaso(q) = p_1_tommaso[q];
    }
    //---------------------------------Inizia il tutto----------------------
    vector<double> asse_y_fab;
    vector<double> asse_y_marc;
    vector<double> asse_y_tom;
    for (int i = 0; i < err_q_fabio.size(); i++)
    {
        asse_y_fab.push_back(sqrt(err_p_fabio[i] * err_p_fabio[i] + err_q_fabio[i] * err_q_fabio[i]));
    }
    for (int i = 0; i < err_q_marco.size(); i++)
    {
        asse_y_marc.push_back(sqrt(err_p_marco[i] * err_p_marco[i] + err_q_marco[i] * err_q_marco[i]));
    }

    for (int i = 0; i < err_q_tommaso.size(); i++)
    {
        asse_y_tom.push_back(sqrt(err_p_tommaso[i] * err_p_tommaso[i] + err_q_tommaso[i] * err_q_tommaso[i]));
    }
    //asse y

    TVectorD r_asse_y_fab(asse_y_fab.size());
    for (int i = 0; i < asse_y_fab.size(); i++)
    {
        r_asse_y_fab(i) = asse_y_fab[i];
    }

    TVectorD r_asse_y_marc(asse_y_marc.size());
    for (int i = 0; i < asse_y_marc.size(); i++)
    {
        r_asse_y_marc(i) = asse_y_marc[i];
    }

    TVectorD r_asse_y_tom(asse_y_tom.size());
    for (int i = 0; i < asse_y_tom.size(); i++)
    {
        r_asse_y_tom(i) = asse_y_tom[i];
    }

    TGraph *grafico = new TGraph(root_p_1_fabio, r_asse_y_fab);
    grafico->GetXaxis()->SetLimits(0, 16);
    grafico->GetYaxis()->SetRangeUser(0.04, 0.14);
    grafico->SetMarkerColor(2);
    grafico->SetMarkerStyle(20);
    grafico->SetMarkerSize(0.8);
    grafico->SetTitle("Operatore A");
    grafico->GetXaxis()->SetTitle("1/p [1/m]");
    grafico->GetYaxis()->SetTitle("#sigma [1/m]");
    grafico->GetXaxis()->SetAxisColor(14);
    grafico->GetYaxis()->SetAxisColor(14);
    grafico->Draw("AP");

    TGraph *grafico2 = new TGraph(root_p_1_marco, r_asse_y_marc);
    grafico2->SetMarkerColor(4);
    grafico2->SetMarkerStyle(20);
    grafico2->SetMarkerSize(0.8);
    grafico2->SetTitle("Operatore B");
    grafico2->GetXaxis()->SetTitle("1/p [1/m]");
    grafico2->GetYaxis()->SetTitle("#sigma [1/m]");
    grafico2->GetXaxis()->SetAxisColor(14);
    grafico2->GetYaxis()->SetAxisColor(14);
    grafico2->Draw("Psame");

    TGraph *grafico3 = new TGraph(root_p_1_tommaso, r_asse_y_tom);
    grafico3->SetMarkerColor(5);
    grafico3->SetMarkerStyle(20);
    grafico3->SetMarkerSize(0.8);
    grafico3->SetTitle("Operatore C");
    grafico3->GetXaxis()->SetTitle("1/p [1/m]");
    grafico3->GetYaxis()->SetTitle("#sigma [1/m]");
    grafico3->GetXaxis()->SetAxisColor(14);
    grafico3->GetYaxis()->SetAxisColor(14);
    grafico3->Draw("Psame");

    //c1->BuildLegend();

    TLegend *legend3 = new TLegend(0.8, 0.7, 0.9, 0.8);
    legend3->SetHeader("Grafico Errori Coniugati", "C");
    legend3->AddEntry(grafico, "Operatore A", "P");
    legend3->AddEntry(grafico2, "Operatore B", "P");
    legend3->AddEntry(grafico3, "Operatore C", "P");
    //legend3->AddEntry(f3, "ax+b", "l");
    legend3->SetTextSize(0.04);
    legend3->SetBorderSize(1);
    legend3->Draw();

    //for(int i =0; i<asse_y_marc.size(); i++)
    //cout<<asse_y_marc[i]<<endl;
}
