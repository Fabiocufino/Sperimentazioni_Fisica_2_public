#define DATACLASS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
#include "statistica.h"
#include "../root/root_dataclass.h"
#include "json.hpp"
#include "resistenza.h"

using namespace std;
using json = nlohmann::json;

//Struct gestione carica scarica in DC
struct dc
{
    double fst;         //fondo scala tempo
    double fsv;         //fondo scala volt
    string unit_time;   //unità di misura
    string unit_volts;  //unità di misura
    string description; //
    vector<double> t;   //valori sperimentali, traslati
    vector<double> t_temp;
    vector<double> v;           //valori sperimentali
    vector<double> err_v;       //
    vector<double> err_t;       //
    vector<double> ln_v;        //
    vector<double> err_ln_v;    //
    vector<double> ln_v_v0;     // in questo modo qui si semplifica l'errore di guadagno
    vector<double> err_ln_v_v0; //
    double v_0;                 //posizione cursore 1
    double t_0;                 //posizione cursore 1

    //Parametri da interpolazioni per tau e c
    double tau_exp;
    double err_tau_exp;
    double c_exp;
    double err_c_exp;
    double ln_v_0;
    double tau_lin;
    double err_tau_lin;
    double c_lin;
    double err_c_lin;

    double r_g;
    double err_r_g;
    double c_exp_rg;
    double err_c_exp_rg;
    double c_lin_rg;
    double err_c_lin_rg;

    //Analisi dati alternativa con il rapporto
    vector<double> v_v0;     //voltaggi alternativi con il rapporto
    vector<double> err_v_v0; //errori con il rapporto

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
                vector<double> measures(2);
                iss >> measures[0] >> measures[1];
                t_temp.push_back(measures[0]);
                v.push_back(measures[1]);
            }
        }
        description += fname;
    }
    //Trasla i tempi dai file letti
    void translate_time()
    {
        for (int i = 0; i < t_temp.size(); i++)
        {
            t.push_back(t_temp[i] - t_0);
        }
    }

    //Salva in file json per interpoalzione ordini
    void to_json(string directory, string fname)
    {
        json j;
        ofstream fout(directory + "/" + fname);
        if (!fout)
        {
            cout << "Errore scrittura json " + directory + "/" + fname << endl;
        }
        j = json{
            {"a_description", description},
            {"fondo scala tempo", fst},
            {"fondo scala voltaggio", fsv},
            {"tempo", t},
            {"unit misura tempo", unit_time},
            {"voltaggio", v},
            {"unit misura volt", unit_volts},
            {"errore voltaggio", err_v},
            {"errore tempo", err_t},
            {"v_0 primo cursore", v_0},
            {"t_0 primo cursore", t_0},
            {"v_v0", v_v0},
            {"err_v_v0", err_v_v0},
            {"ln_v", ln_v},
            {"err_ln_v", err_ln_v},
            {"ln_v_v0", ln_v_v0},
            {"err_ln_v_v0", err_ln_v_v0}};

        fout << setw(4) << j << endl;
    }
    void from_json(string directory, string fname)
    {
        json j;
        ifstream fin(directory + fname);
        fin >> j;
        j.at("a_description").get_to(description);
        j.at("fondo scala tempo").get_to(fst);
        j.at("fondo scala voltaggio").get_to(fsv);
        j.at("tempo").get_to(t);
        j.at("unit misura tempo").get_to(unit_time);
        j.at("voltaggio").get_to(v);
        j.at("unit misura volt").get_to(unit_volts);
        j.at("errore voltaggio").get_to(err_v);
        j.at("errore tempo").get_to(err_t);
        j.at("v_0 primo cursore").get_to(v_0);
        j.at("t_0 primo cursore").get_to(t_0);
        j.at("v_v0").get_to(v_v0);
        j.at("err_v_v0").get_to(err_v_v0);
        j.at("ln_v").get_to(ln_v);
        j.at("err_ln_v").get_to(err_ln_v);
        j.at("ln_v_v0").get_to(ln_v_v0);
        j.at("err_ln_v_v0").get_to(err_ln_v_v0);
    }

    //Calcola errori di cursore 2 per plot esponenziale
    void calcolo_errori()
    {
        //Parte inutile
        // VOLTAGGIO (0.3* 1/25 * scala) a cui si aggiunge in quadratura (3/100 * v.misurato) /sqrt(3)
        //Prende in considerazione errori di lettura (1/25 FS trasforamto in gaussiano) assumendo uniforme
        //e guadagno su valori del cursore 2 (3% * v.misurato convertito in gaussiano) assumento Uniforme
        for (auto c : v)
        {
            err_v.push_back(sqrt(pow(0.3 * 1. / 25. * fsv, 2) + pow(3. / 100. * c / sqrt(12), 2)));
        }

        //Parte utile
        //TEMPO sqrt(2)*(1/25 * scala) * sqrt(6) con il tempo è solo conversione a pdf triangolare
        for (auto c : t)
        {
            err_t.push_back(sqrt(2) * (1. / 25.) * fst / sqrt(24));
        }
    }

    //calcola il rapporto tra v e v0
    void calcolo_v_v0()
    {
        for (auto c : v)
        {
            v_v0.push_back(c / v_0);
        }
    }
    //Calcolo di errori, usa il rapporto e dunque si include solo errore lettura
    //serve per fit exp in root e anche grafico
    void calcolo_errori_rapporto()
    {
        double sigma_v = 1. / 25. * 0.3 * fsv; //errore sul voltaggio dato da errore lettura con coeff magico (errore uniforme quasi)
        for (auto c : v)
        {
            err_v_v0.push_back(sigma_v / v_0 * sqrt(1. + pow(c / v_0, 2)));
        }
    }

    void resistenza_generatore()
    {
        double v = 3.56;
        double v_0 = 7.64;
        double r = 0.04686;
        double err_v = 1. / (25. * sqrt(12));
        double err_v_0 = 1. / (25. * sqrt(12));
        double err_r = err_res_cap(r * 1000, 0.2, 10, 0.01) / 1000.0; //0.2% + 10 d
        r_g = r * (v_0 - v) / v;
        err_r_g = sqrt(pow((v_0 - v) * err_r / v, 2) + pow(r * err_v_0 / v, 2) + pow(r * err_v * v_0 / pow(v, 2), 2));
        cout << "Resistenza generatore: " << r_g << " +- " << err_r_g << endl;
        cout << "Resistenza: " << r << " +- " << err_r << endl;
        cout << "V_0: " << v_0 << " +- " << err_v_0 << endl;
        cout << "V: " << v << " +- " << err_v << endl;
    }

    void calcolo_capacity_fit_exp(string folder, string fname, double r, double err_r)
    {
        fit_results fit_exp;
        fit_exp.root_from_json(folder, fname);
        tau_exp = -1.0 / fit_exp.b[0];
        err_tau_exp = fit_exp.err_b[0] / pow(fit_exp.b[0], 2);
        c_exp = tau_exp / r;
        err_c_exp = sqrt(pow(err_tau_exp / r, 2) + pow(err_r * tau_exp / pow(r, 2), 2));
        c_exp_rg = tau_exp / (r + r_g);
        err_c_exp_rg = sqrt(pow(err_tau_exp / (r + r_g), 2) + pow(err_r * tau_exp / pow(r + r_g, 2), 2) + pow(err_r_g * tau_exp / pow(r + r_g, 2), 2));
        cout << "Tau da fit exp su " + fname << ": " << tau_exp << "+-" << err_tau_exp << endl;
        cout << "C da fit exp su " + fname << ": " << c_exp << " +/- " << err_c_exp << endl;
        cout << "C da fit exp con r_g su " + fname << ": " << c_exp_rg << " +/- " << err_c_exp_rg << endl
             << endl;
    }

    //Restituisce lo stesso valore che con la propagazione
    void calcolo_capacity_fit_exp_altern(string folder, string fname)
    {
        fit_results fit_exp;
        fit_exp.root_from_json(folder, fname);
        cout << "Tau alternativo da fit exp su" + fname;
        cout << ": " << fit_exp.b[0] << "+-" << fit_exp.err_b[0] << endl;
    }

    //Inizio fit lienarizzato
    void compute_ln()
    {
        ln_v_0 = log(v_0);
        cout << "Il logaritmo di V0 per vedere se l'intercetta del fit è corretta:  " << ln_v_0 << endl;
        for (int i = 0; i < v.size(); i++)
        {
            double sigma_v = 1. / 25. * 0.3 * fsv; //errore sul voltaggio dato da errore lettura con coeff magico
            ln_v.push_back(log(v[i]));
            err_ln_v.push_back(err_v[i] / v[i]);
            //Metodo che abbiamo visto essere migliore e dare chi quadro buono
            ln_v_v0.push_back(log(v[i] / v_0));
            err_ln_v_v0.push_back(sigma_v * sqrt((pow(v_0, 2) + pow(v[i], 2)) / (pow(v[i], 2) * pow(v_0, 2)))); // occio che l'errore su v prende solo quello di lettura
        }
    }

    void calcolo_capacity_fit_lineare(string folder, string name, double r, double err_r)
    {
        fit_results fit_lin;
        fit_lin.root_from_json(folder, name);
        tau_lin = -1 / fit_lin.b[0];
        err_tau_lin = fit_lin.err_b[0] / pow(fit_lin.b[0], 2);
        c_lin = -1. / (fit_lin.b[0] * r);
        err_c_lin = sqrt(pow(fit_lin.err_b[0] / (r * pow(fit_lin.b[0], 2)), 2) + pow(err_r / (fit_lin.b[0] * pow(r, 2)), 2));
        c_lin_rg = -1. / (fit_lin.b[0] * (r + r_g));
        err_c_lin_rg = sqrt(pow(fit_lin.err_b[0] / ((r + r_g) * pow(fit_lin.b[0], 2)), 2) + pow(err_r / (fit_lin.b[0] * pow((r + r_g), 2)), 2) + pow(err_r_g / (fit_lin.b[0] * pow((r + r_g), 2)), 2));
        cout << "Tau da fit lin su " + name << ": " << tau_lin << "+-" << err_tau_lin << endl;
        cout << "C da fit lin su " + name << ": " << c_lin << " +/- " << err_c_lin << endl;
        cout << "C da fit lin con r_g su " + name << ": " << c_lin_rg << " +/- " << err_c_lin_rg << endl
             << endl;
    }
};

struct ac
{
    string unit_time;
    string unit_volts;
    string description;

    //Dati in input
    vector<double> freq;
    vector<double> vin;
    vector<double> vout;
    vector<double> fsv;
    vector<double> fst;
    vector<double> delta_t;
    vector<double> err_v;
    vector<double> trasf;
    vector<double> err_trasf;
    vector<double> sfasamento;
    vector<double> err_sfasamento;

    //Stima di ftaglio da valori iniziali
    void f_taglio(double res, double err_res, double cap, double err_cap)
    {
        //correzione last minute per prendere il valore della capcità di domnio del tempo
        double fsc = 10.0;
        double distribuzione = 12; //Assumiamo trangolare, cambia in 6 se vuoi uniforme
        //double err_cap_lettura = 8. * 0.01 * 1. / sqrt(distribuzione);    //8 digit su cifra meno significativa
        //double err_cap_gain = 1. / 100. * cap * 1. / sqrt(distribuzione); //guadagno di 1%
        double ft_th = 1. / (2 * M_PI * res * cap);
        double err_ft_th = sqrt(pow(err_res / (2 * M_PI * pow(res, 2) * cap), 2) + pow(err_cap / (2 * M_PI * res * pow(cap, 2)), 2)); //+ pow(err_cap_gain / (2 * M_PI * res * cap), 2));
        cout << "Ft_th: " << ft_th * 1000. << " +- " << err_ft_th * 1000. << " kHz" << endl;
    }

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
                vector<double> measures(6);
                iss >> measures[0] >> measures[1] >> measures[2] >> measures[3] >> measures[4] >> measures[5];
                freq.push_back(measures[0]);
                vin.push_back(measures[1]);
                vout.push_back(measures[2]);
                fsv.push_back(measures[3]);
                delta_t.push_back(measures[4]);
                fst.push_back(measures[5]);
            }
        }
        description += fname;
    }

    //Salva in file json per interpoalzione ordini
    void to_json(string directory, string fname)
    {
        json j;
        ofstream fout(directory + "/" + fname);
        if (!fout)
        {
            cout << "Errore scrittura json " + directory + "/" + fname << endl;
        }
        j = json{
            {"a_description", description},
            {"frequenza", freq},
            {"fondo scala tempo", fst},
            {"fondo scala voltaggio", fsv},
            {"delta tempo", delta_t},
            {"unit misura tempo", unit_time},
            {"voltaggio ingresso", vin},
            {"voltaggio uscita", vout},
            {"unit misura volt", unit_volts},
            {"vout_vin", trasf},
            {"err_vout_vin", err_trasf},
            {"sfasamento", sfasamento},
            {"err_sfasamento", err_sfasamento}};

        fout << setw(4) << j << endl;
    }
    void from_json(string directory, string fname)
    {
        json j;
        ifstream fin(directory + fname);
        fin >> j;
        j.at("a_description").get_to(description);
        j.at("frequenza").get_to(freq);
        j.at("fondo scala tempo").get_to(fst);
        j.at("fondo scala voltaggio").get_to(fsv);
        j.at("delta tempo").get_to(delta_t);
        j.at("unit misura tempo").get_to(unit_time);
        j.at("voltaggio ingresso").get_to(vin);
        j.at("voltaggio uscita").get_to(vout);
        j.at("unit misura volt").get_to(unit_volts);
        j.at("vout_vin").get_to(trasf);
        j.at("err_vout_vin").get_to(err_trasf);
        j.at("sfasamento").get_to(sfasamento);
        j.at("err_sfasamento").get_to(err_sfasamento);
    }

    void trasferimento()
    {
        double perc = 1.5 / 100.; //errore su guadagno sonde, fisso a 1.5%
        for (int i = 0; i < vin.size(); i++)
        {
            double a = vout[i] / vin[i];
            double sigma_vin = 1. / 25 * 0.3 * fsv[i];  //magico
            double sigma_vout = 1. / 25 * 0.3 * fsv[i]; //magico
            double sigma_kin = perc;
            double sigma_kout = perc;
            trasf.push_back(a);
            err_trasf.push_back(a * sqrt(pow(sigma_vin / vin[i], 2) + pow(sigma_vout / vout[i], 2) + pow(sigma_kin, 2) + pow(sigma_kout, 2)));
        }
    }

    void sfasamento_assey()
    {
        for (int i = 0; i < freq.size(); i++)
        {
            double err_delta_t = fst[i] * 1. / 25. * 1. / sqrt(12) * sqrt(2);
            sfasamento.push_back((2 * M_PI * freq[i] * delta_t[i]) / 1000.);
            err_sfasamento.push_back(2 * M_PI / 1000. * sqrt(pow(freq[i] * err_delta_t, 2)));
        }
    }
};

//Funzione valore atteso in passa basso per fx trasferimento
double trasferimento_atteso_pb(double f, double f_th)
{
    return sqrt(1 / (1 + pow(f / f_th, 2)));
}

//Funzione valore atteso in passa basso per fx sfasamento
double sfasamento_atteso_pb(double f, double f_th)
{
    return sqrt(pow(atan(-f / f_th), 2));
}

//Funzione valore atteso in passa alto per fx trasferimento
double trasferimento_atteso_pa(double f, double f_th)
{
    return sqrt(1 / (1 + pow(f_th / f, 2)));
}
//Funzione valore atteso in passa alto per fx sfasamento
double sfasamento_atteso_pa(double f, double f_th)
{
    return atan(f_th / f);
}

//Calcola il valore di chi quadro per vettore di osservati e parametri proposti
double chi_quadro(double f_th, vector<double> &x, vector<double> &y, vector<double> &err_y, double (*function)(double, double))
{
    double sum_chi = 0;
    for (int i = 0; i < x.size(); i++)
    {
        sum_chi += pow((y[i] - function(x[i], f_th)) / err_y[i], 2);
    }
    return sum_chi;
}

//Salva file con dalori di chiquadro corrispondenti a modelli con diversi parametri teorici proposti
void compute_minimization_trasf(double start, int npoints, double step, ac dataset, double (*function)(double, double), string dir, string fname)
{
    vector<double> frequenze;
    vector<double> chi_q;
    ofstream fout(dir + "/" + fname);
    ofstream fout2(dir + "/" + fname + ".txt");
    for (int i = 0; i < npoints; i++)
    {
        double freq = start + step * i;
        frequenze.push_back(freq);
        chi_q.push_back(chi_quadro(freq, dataset.freq, dataset.trasf, dataset.err_trasf, function));
        fout2 << frequenze[i] << "\t" << chi_q[i] << endl;
    }
    json j;
    if (!fout)
    {
        cout << "Errore scrittura json " + dir + "/" + fname << endl;
    }
    j = json{
        {"frequenze", frequenze},
        {"chi_q", chi_q}};
    fout << setw(4) << j << endl;
}

void compute_minimization_sfasamento(double start, int npoints, double step, ac dataset, double (*function)(double, double), string dir, string fname)
{
    vector<double> frequenze;
    vector<double> chi_q;
    ofstream fout(dir + "/" + fname);
    ofstream fout2(dir + "/" + fname + ".txt");
    for (int i = 0; i < npoints; i++)
    {
        double freq = start + step * i;
        frequenze.push_back(freq);
        chi_q.push_back(chi_quadro(freq, dataset.freq, dataset.sfasamento, dataset.err_sfasamento, function));
        fout2 << frequenze[i] << "\t" << chi_q[i] << endl;
    }
    json j;
    if (!fout)
    {
        cout << "Errore scrittura json " + dir + "/" + fname << endl;
    }
    j = json{
        {"frequenze", frequenze},
        {"chi_q", chi_q}};
    fout << setw(4) << j << endl;
}

//Funzione per leggere da file
void compute_minimization_from_json(string dir, string fname, vector<double> &freq, vector<double> &chi_q)
{
    json j;
    ifstream fin(dir + "/" + fname);
    fin >> j;
    j.at("frequenze").get_to(freq);
    j.at("chi_q").get_to(chi_q);
}
//Calcola la minimizzazione del chi quadro per studiare la freq
void freq_min_chi(string dir, string fname)
{
    fit_results fit_chi;
    fit_chi.root_from_json(dir, fname);
    double a = fit_chi.c[0];
    double b = fit_chi.b[0];
    double c = fit_chi.a[0];
    double freq_chi = -b / (2. * a);
    double freq_chi_y = a * pow(freq_chi, 2) + b * freq_chi + c;
    double freq_delta_plus = (-b + sqrt(pow(b, 2) - 4. * a * (c - freq_chi_y - 1.))) / (2. * a) - freq_chi;
    double freq_delta_minus = freq_chi - (-b - sqrt(pow(b, 2) - 4. * a * (c - freq_chi_y - 1.))) / (2. * a);
    cout << fname + ": " << freq_chi << " kHz\t +StErr: " << freq_delta_plus << " -StErr" << freq_delta_minus << endl;
}

void f_taglio_fit_line_tr(string dir_tr, string fname_tr)
{
    fit_results fit_input_tr, fit_input_sf;
    fit_input_tr.root_from_json(dir_tr, fname_tr);

    double k_tr = 1. / sqrt(2);
    //y=a+x*b
    //per il trasferimento
    double b_tr = fit_input_tr.b[0];
    double a_tr = fit_input_tr.a[0];
    double sigma_k_y = 3. / (100. * sqrt(24.));
    double err_b_tr = sqrt(pow(fit_input_tr.err_b[0], 2) + pow(b_tr * sigma_k_y, 2));
    double err_a_tr = fit_input_tr.err_a[0];
    double cov_ab_tr = fit_input_tr.covariance_matrix[0][1];

    double f_tr = (k_tr - a_tr) / b_tr;
    double err_f_tr = sqrt(pow(err_a_tr / b_tr, 2) + pow((k_tr - a_tr) * err_b_tr / pow(b_tr, 2), 2) + 2. * (k_tr - a_tr) * cov_ab_tr / pow(b_tr, 3));

    cout << "F_taglio in trasferimento: " << fname_tr << ": " << f_tr << " +- " << err_f_tr << endl;
}

void f_taglio_fit_line_sf(string dir_tr, string fname_tr)
{
    fit_results fit_input_tr, fit_input_sf;
    fit_input_tr.root_from_json(dir_tr, fname_tr);

    double k_tr = 0.5;
    //y=a+x*b
    //per il trasferimento
    double b_tr = fit_input_tr.b[0];
    double a_tr = fit_input_tr.a[0];
    double err_b_tr = fit_input_tr.err_b[0];
    double err_a_tr = fit_input_tr.err_a[0];
    double cov_ab_tr = fit_input_tr.covariance_matrix[0][1];

    double f_tr = (k_tr - a_tr) / b_tr;
    double err_f_tr = sqrt(pow(err_a_tr / b_tr, 2) + pow((k_tr - a_tr) * err_b_tr / pow(b_tr, 2), 2) + 2. * (k_tr - a_tr) * cov_ab_tr / pow(b_tr, 3));

    cout << "F_taglio in sfasamento: " << fname_tr << ": " << f_tr << " +- " << err_f_tr << endl;
}
