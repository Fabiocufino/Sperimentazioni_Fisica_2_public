#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TF2.h"
#include "TLegend.h"
#include "TCanvas.h"
#include <fstream>
#include <cmath>
#include "TFitResult.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TStyle.h"
#include "TGraphErrors.h"
#include <vector>
#ifndef DATACLASS
#include "../Programmi/dataclass.h"
#include "root_function.h"
#endif

using namespace std;
using json = nlohmann::json;

struct all_vectors
{
    string description;
    vector<double> t;
    vector<double> vt;
    vector<double> err_vt;

    //Lettura dei dati
    void read(string folder, string fname)
    {
        ifstream fin(folder + "/" + fname);
        if (!fin)
        {
            cout << "Errore lettura file: " + folder + fname << endl;
        }

        string temp_line;
        while (getline(fin, temp_line))
        {
            if (temp_line.rfind("#", 0) == 0 || temp_line.size() < 5)
            {
                continue;
            }
            else
            {
                istringstream iss(temp_line);
                vector<double> measures(9);
                iss >> measures[0] >> measures[1] >> measures[2];
                t.push_back(measures[0]);
                vt.push_back(measures[1]);
                err_vt.push_back(measures[2]);
            }
        }
        description += fname;
    }
};
//1* asse_x[i] * 2 * M_PI / sqrt(pow(asse_x[i] * 2 * M_PI, 4) - (2 * pow(asse_x[i] * 2 * M_PI, 2) * (pow(1 / sqrt(L * C), 2) - 2 * pow(R / (2 * L), 2))) + pow(1 / sqrt(L * C), 4)));

double func_lc(double *x, double *par)
{
    all_vectors lc;
    lc.read("../Dati", "onda_rlc_smorzata.txt");

    double R = par[0];
    double L = x[0];
    double C = x[1];

    double chi = 0;
    for (int i = 0; i < lc.t.size(); i++)
    {
        double v_th = ((1 * exp(-1 * (R * lc.t[i]) / (2 * L))) / sqrt((1 / (C * L)) - R * R / (2 * L * L))) * (R / (2 * L)) * (sin(lc.t[i] * sqrt((1 / (C * L)) - R * R / (2 * L * L))) + sqrt((4 * L) / (C * R * R)) * cos(lc.t[i] * sqrt((1 / (C * L)) - R * R / (2 * L * L))));

        double chi_i = pow(((v_th - lc.vt[i]) / (lc.err_vt[i])), 2);
        chi = chi + chi_i;
    }
    return chi;
}

double func_rc(double *x, double *par)
{
    all_vectors rc;
    rc.read("../Dati", "onda_rlc_smorzata.txt");

    double L = par[0];
    double R = x[0];
    double C = x[1];

    double chi = 0;
    for (int i = 0; i < rc.t.size(); i++)
    {

        double v_th = ((1 * exp(-1 * (R * rc.t[i]) / (2 * L))) / sqrt((1 / (C * L)) - R * R / (2 * L * L))) * (R / (2 * L)) * (sin(rc.t[i] * sqrt((1 / (C * L)) - R * R / (2 * L * L))) + sqrt((4 * L) / (C * R * R)) * cos(rc.t[i] * sqrt((1 / (C * L)) - R * R / (2 * L * L))));
        //double v_th = ((1 * exp(-1 * (x[0] * rc.t[i]) / (2 * L))) / sqrt((1 / (x[1] * L)) - x[0] * x[0] / (2 * L * L))) * (x[0] / (2 * L)) * (sin(rc.t[i] * sqrt((1 / (x[1] * L)) - x[0] * x[0] / (2 * L * L))) + sqrt((4 * L) / (x[1] * x[0] * x[0])) * cos(rc.t[i] * sqrt((1 / (x[1] * L)) - x[0] * x[0] / (2 * L * L))));
        double chi_i = pow(((v_th - rc.vt[i]) / (rc.err_vt[i])), 2);
        chi = chi + chi_i;
    }
    return chi;
}

double func_rl(double *x, double *par)
{
    all_vectors rc;
    rc.read("../Dati", "onda_rlc_smorzata.txt");

    double L = x[1];
    double R = x[0];
    double C = par[0];

    double chi = 0;
    for (int i = 0; i < rc.t.size(); i++)
    {

        double v_th = ((1 * exp(-1 * (R * rc.t[i]) / (2 * L))) / sqrt((1 / (C * L)) - R * R / (2 * L * L))) * (R / (2 * L)) * (sin(rc.t[i] * sqrt((1 / (C * L)) - R * R / (2 * L * L))) + sqrt((4 * L) / (C * R * R)) * cos(rc.t[i] * sqrt((1 / (C * L)) - R * R / (2 * L * L))));
        //double v_th = ((1 * exp(-1 * (x[0] * rc.t[i]) / (2 * L))) / sqrt((1 / (x[1] * L)) - x[0] * x[0] / (2 * L * L))) * (x[0] / (2 * L)) * (sin(rc.t[i] * sqrt((1 / (x[1] * L)) - x[0] * x[0] / (2 * L * L))) + sqrt((4 * L) / (x[1] * x[0] * x[0])) * cos(rc.t[i] * sqrt((1 / (x[1] * L)) - x[0] * x[0] / (2 * L * L))));
        double chi_i = pow(((v_th - rc.vt[i]) / (rc.err_vt[i])), 2);
        chi = chi + chi_i;
    }
    return chi;
}

void chi_rlc_frequenza()
{
    //Double_t R = 64.7;
    //auto c1 = new TCanvas("c1", "c1", 200, 10, 1000, 600);
    //c1->SetGrid();
    //c1->SetLogz();
    //TF2 *chi = new TF2("Minimizzazione del chi quadro fissando R", func_lc, 0.0001, 0.0015, 0, 35E-09, 1);
    //chi->SetParNames("R");
    //chi->SetParameter(0, R);
    //chi->GetXaxis()->SetTitle("L [H]");
    //chi->GetYaxis()->SetTitle("C [F]");
    //chi->SetNpx(200);
    //chi->SetNpy(200);
    //gStyle->SetPalette(kRainBow);
    //chi->Draw("COLZ2");

    //---------------------------------------------------------------

    //Double_t L = 0.00098;
    //auto c2 = new TCanvas("c2", "c2", 200, 10, 1000, 600);
    //c2->SetGrid();
    //c2->SetLogz();
    //
    //TF2 *chi1 = new TF2("Minimizzazione del chi quadro fissando L", func_rc, 20, 100, 0, 20e-09, 1);
    //chi1->SetParNames("L");
    //chi1->SetParameter(0, L);
    //chi1->GetXaxis()->SetTitle("R [#Omega]");
    //chi1->GetYaxis()->SetTitle("C [F]");
    //chi1->SetNpx(200);
    //chi1->SetNpy(200);
    //gStyle->SetPalette(kRainBow);
    //chi1->Draw("COLZ2");

    //---------------------------------------------------------------

    Double_t C = 9.73e-09;
    auto c3 = new TCanvas("c3", "c3", 200, 10, 1000, 600);
    c3->SetGrid();
    c3->SetLogz();

    TF2 *chi2 = new TF2("Minimizzazione del chi quadro fissando C", func_rl, 15, 100, 0.0001, 0.0015, 1);
    chi2->SetParNames("C");
    chi2->SetParameter(0, C);
    chi2->GetXaxis()->SetTitle("R [#Omega]");
    chi2->GetYaxis()->SetTitle("L [H]");
    chi2->SetNpx(200);
    chi2->SetNpy(200);
    gStyle->SetPalette(kRainBow);
    chi2->Draw("COLZ2");
}