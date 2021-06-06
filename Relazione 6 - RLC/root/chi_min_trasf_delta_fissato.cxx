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
        double l = df.v_out[i] / df.v_in[i];
        double sigma_vin = 1. / 25 * 0.3 * df.fsv_in[i];   //magico
        double sigma_vout = 1. / 25 * 0.3 * df.fsv_out[i]; //magico
        double sigma_kin = perc;
        double sigma_kout = perc;
        trasferimento.push_back(l);
        err_trasferimento.push_back(l * sqrt(pow(sigma_vin / df.v_in[i], 2) + pow(sigma_vout / df.v_out[i], 2) + pow(sigma_kin, 2) + pow(sigma_kout, 2)));
        freq.push_back(df.freq[i] * 1000);
    }

    double a = x[0];
    double omega = x[1];
    double delta = par[0];

    double chi = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        double trasf_teorica = a * pow(omega, 2) / sqrt(pow(freq[i] * 2 * M_PI, 4) - (2 * pow(freq[i] * 2 * M_PI, 2) * (pow(omega, 2) - 2 * pow(delta, 2))) + pow(omega, 4));
        double chi_i = pow(((trasf_teorica - trasferimento[i]) / (err_trasferimento[i])), 2);
        chi = chi + chi_i;
    }
    return chi;
}

void chi_min_trasf_delta_fissato()
{

    Double_t delta = 9145;
    auto c3 = new TCanvas("c3", "c3", 200, 10, 1000, 600);
    c3->SetGrid();
    c3->SetLogz();

    TF2 *chi2 = new TF2("Minimizzazione del chi fissando #delta", min_chi_variando_delta, 0.95, 1.05, 320000, 322000, 1);
    chi2->SetParNames("#delta");
    chi2->SetParameter(0, delta);
    chi2->GetXaxis()->SetTitle("a");
    chi2->GetYaxis()->SetTitle("#Omega [Hz]");
    chi2->SetNpx(160);
    chi2->SetNpy(160);
    gStyle->SetPalette(kRainBow);
    chi2->Draw("COLZ2");
    c3->SaveAs("delta_fixed.png");
}