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

double min_chi_variando_delta(double *x, double *par) //le x sono le delta e le y sono le omega, restituisce una z.
{
    d_frequenza df;
    df.from_json("../Json", "d_f_c.json");
    vector<double> trasferimento, err_trasferimento, freq;
    for (int i = 0; i < df.v_in.size(); i++)
    {
        double perc = 1.5 / 100.; //errore su guadagno sonde, fisso a 1.5%
        double tr = df.v_out[i] / df.v_in[i];
        double sigma_vin = 1. / 25 * 0.3 * df.fsv_in[i];   //magico
        double sigma_vout = 1. / 25 * 0.3 * df.fsv_out[i]; //magico
        double sigma_kin = perc;
        double sigma_kout = perc;
        trasferimento.push_back(tr);
        err_trasferimento.push_back(tr * sqrt(pow(sigma_vin / df.v_in[i], 2) + pow(sigma_vout / df.v_out[i], 2) + pow(sigma_kin, 2) + pow(sigma_kout, 2)));
        freq.push_back(df.freq[i] * 1000);
    }

    double a = x[0];
    double omega = x[1];

    double delta_min = 9000;
    double delta_max = 11000;
    double delta_step = 10;

    double chi = 0;
    vector<double> chi_per_ogni_a;

    for (double delta = delta_min; delta < delta_max; delta = delta + delta_step)
    {
        for (int i = 0; i < freq.size(); i++)
        {
            double trasf_teorica = a * pow(omega, 2) / sqrt(pow(freq[i] * 2 * M_PI, 4) - (2 * pow(freq[i] * 2 * M_PI, 2) * (pow(omega, 2) - 2 * pow(delta, 2))) + pow(omega, 4));
            double chi_i = pow(((trasf_teorica - trasferimento[i]) / (err_trasferimento[i])), 2);
            chi = chi + chi_i;
        }
        chi_per_ogni_a.push_back(chi);
    }

    double min;
    min = chi_per_ogni_a[0];
    for (int i = 0; i < chi_per_ogni_a.size(); i++)
    {
        if (chi_per_ogni_a[i] < min)
        {
            min = chi_per_ogni_a[i];
        }
    }

    double p = par[0];
    cout <<"hello"<< p << endl;
    return min;
}

void profilingD()
{
    auto c3 = new TCanvas("c3", "c3", 200, 10, 1000, 600);
    c3->SetGrid();
    c3->SetLogz();

    TF2 *chi2 = new TF2("Minimizzazione del chi quadro variando #delta", min_chi_variando_delta, 0.93, 1.07, 318000, 324000, 1);
    chi2->GetXaxis()->SetTitle("a");
    chi2->GetYaxis()->SetTitle("#Omega");

    Double_t p = 9;
    //chi2->SetParNames("a_step");
    chi2->SetParameter(0, p);

    //chi2->SetNpx(200);
    //chi2->SetNpy(200);
    gStyle->SetPalette(kRainBow);
    chi2->Draw("COLZ2");
}