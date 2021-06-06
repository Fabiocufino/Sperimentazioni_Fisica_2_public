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
#include "json.hpp"
#ifndef ROOTDATACLASS
#include "../root/root_dataclass.h"
#endif
#include "resistenza.h"

using namespace std;
using json = nlohmann::json;

//Struct gestione carica scarica in DC
struct d_tempo
{
    string description;
    vector<double> n_max;
    vector<double> t_p;     //tempi +
    vector<double> t_max;   //tempi massimi
    vector<double> v_max;   //voltaggi massimi
    vector<double> fst_p;   //
    vector<double> fsv_p;   //
    vector<double> fst_max; //
    vector<double> fsv_max; //

    vector<double> n_min;
    vector<double> t_m;     //tempi +
    vector<double> t_min;   //tempi minimi
    vector<double> v_min;   //voltaggi minmi
    vector<double> fst_m;   //
    vector<double> fsv_m;   //
    vector<double> fst_min; //
    vector<double> fsv_min; //

    vector<double> err_t_max; //
    vector<double> err_v_max; //
    vector<double> err_t_p;   //
    vector<double> err_t_min; //
    vector<double> err_v_min; //
    vector<double> err_t_m;   //

    double periodo_p; //periodi in sec
    double err_periodo_p;
    double periodo_m;
    double err_periodo_m;
    double periodo_max;
    double err_periodo_max;
    double periodo_min;
    double err_periodo_min;
    double periodo_intercette;
    double err_periodo_intercette;
    double periodo_stazionari;
    double err_periodo_stazionari;
    double periodo; //periodo scelto
    double err_periodo;

    double omega_d_p;
    double err_omega_d_p;
    double omega_d_m;
    double err_omega_d_m;
    double omega_d_max;
    double err_omega_d_max;
    double omega_d_min;
    double err_omega_d_min;
    double omega_d_intercette;
    double err_omega_d_intercette;
    double omega_d_stazionari;
    double err_omega_d_stazionari;
    double omega_d; //omega_g scelta
    double err_omega_d;

    double delta_exp_max;
    double err_delta_exp_max;
    double delta_exp_min;
    double err_delta_exp_min;
    double delta_exp; //media
    double err_delta_exp;

    double delta_lin_max;
    double err_delta_lin_max;
    double delta_lin_min;
    double err_delta_lin_min;
    double delta_lin; //media
    double err_delta_lin;

    double delta;
    double err_delta;

    double omega_0;
    double err_omega_0;
    double l;
    double err_l;
    double q_value;
    double err_q_value;

    double c = 9.73 * pow(10, -9); //Inserire capacità dalla rel. scorsa
    double err_c = 0.08 * pow(10, -9);

    double r_tot;
    double err_r_tot;

    double r_t;
    double err_r_t;
    double r_p = 512.5; //resistenza potenziometro misurata con multimetro in lab
    double err_r_p = err_res_cap(512.5, 0.9, 3, 0.1);
    double l_p;
    double err_l_p;

    //Lettura dei dati per i massimi
    void read_max(string folder, string fname)
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
                iss >> measures[0] >> measures[1] >> measures[2] >> measures[3] >> measures[4] >> measures[5] >> measures[6] >> measures[7] >> measures[8];

                n_max.push_back(measures[0]);
                t_p.push_back(measures[1]);
                t_max.push_back(measures[2]);
                v_max.push_back(measures[3]);
                fst_p.push_back(measures[4]);
                fsv_p.push_back(measures[5]);
                fst_max.push_back(measures[6]);
                fsv_max.push_back(measures[7]);
            }
        }
        description += fname;
    }
    void read_min(string folder, string fname)
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
                iss >> measures[0] >> measures[1] >> measures[2] >> measures[3] >> measures[4] >> measures[5] >> measures[6] >> measures[7] >> measures[8];

                n_min.push_back(measures[0]);
                t_m.push_back(measures[1]);
                t_min.push_back(measures[2]);
                v_min.push_back(measures[3]);
                fst_m.push_back(measures[4]);
                fsv_m.push_back(measures[5]);
                fst_min.push_back(measures[6]);
                fsv_min.push_back(measures[7]);
            }
        }
        description += fname;
    }

    //Salva in file json per interpoalzione ordini
    void to_json_max(string directory, string fname)
    {
        json j;
        ofstream fout(directory + "/" + fname);
        if (!fout)
        {
            cout << "Errore scrittura json " + directory + "/" + fname << endl;
        }
        j = json{
            {"description", description},
            {"n_max", n_max},
            {"t_p", t_p},
            {"t_max", t_max},
            {"v_max", v_max},
            {"fst_p", fst_p},
            {"fsv_p", fsv_p},
            {"fst_max", fst_max},
            {"fsv_max", fsv_max},
            {"err_t_max", err_t_max},
            {"err_v_max", err_v_max},
            {"err_t_p", err_t_p}};

        fout << setw(4) << j << endl;
    }

    void to_json_min(string directory, string fname)
    {
        json j;
        ofstream fout(directory + "/" + fname);
        if (!fout)
        {
            cout << "Errore scrittura json " + directory + "/" + fname << endl;
        }
        j = json{
            {"description", description},
            {"n_min", n_min},
            {"t_m", t_m},
            {"t_min", t_min},
            {"v_min", v_min},
            {"fst_m", fst_m},
            {"fsv_m", fsv_m},
            {"fst_min", fst_min},
            {"fsv_min", fsv_min},
            {"err_t_min", err_t_min},
            {"err_v_min", err_v_min},
            {"err_t_m", err_t_m}};

        fout << setw(4) << j << endl;
    }

    void from_json_max(string directory, string fname)
    {
        json j;
        ifstream fin(directory + "/" + fname);
        if (!fin)
            cout << "Errore lettura from_json_max " << fname << endl;
        fin >> j;
        j.at("description").get_to(description);
        j.at("n_max").get_to(n_max);
        j.at("t_p").get_to(t_p);
        j.at("t_max").get_to(t_max);
        j.at("v_max").get_to(v_max);
        j.at("fst_p").get_to(fst_p);
        j.at("fsv_p").get_to(fsv_p);
        j.at("fst_max").get_to(fst_max);
        j.at("fsv_max").get_to(fsv_max);
        j.at("err_t_max").get_to(err_t_max);
        j.at("err_v_max").get_to(err_v_max);
        j.at("err_t_p").get_to(err_t_p);
    }

    void from_json_min(string directory, string fname)
    {
        json j;
        ifstream fin(directory + "/" + fname);
        if (!fin)
            cout << "Errore lettura " << __FUNCTION__ << fname << endl;
        fin >> j;
        j.at("description").get_to(description);
        j.at("n_min").get_to(n_min);
        j.at("t_m").get_to(t_m);
        j.at("t_min").get_to(t_min);
        j.at("v_min").get_to(v_min);
        j.at("fst_m").get_to(fst_m);
        j.at("fsv_m").get_to(fsv_m);
        j.at("fst_min").get_to(fst_min);
        j.at("fsv_min").get_to(fsv_min);
        j.at("err_t_min").get_to(err_t_min);
        j.at("err_v_min").get_to(err_v_min);
        j.at("err_t_m").get_to(err_t_m);
    }

    void errori()
    {
        int uniforme = 12;
        int distribuzione = 12;

        for (int i = 0; i < t_m.size(); i++)
        {
            err_t_m.push_back(sqrt(2) * (1. / 25.) * fst_m[i] / sqrt(distribuzione));
            err_t_min.push_back(sqrt(2) * (1. / 25.) * fst_min[i] / sqrt(distribuzione));
            err_v_min.push_back(sqrt(pow(0.3 * 1. / 25. * fsv_min[i], 2) + pow(3. / 100. * v_min[i] / sqrt(uniforme), 2)));
        }
        for (int i = 0; i < t_p.size(); i++)
        {
            err_t_p.push_back(sqrt(2) * (1. / 25.) * fst_p[i] / sqrt(distribuzione));
            err_t_max.push_back(sqrt(2) * (1. / 25.) * fst_max[i] / sqrt(distribuzione));
            err_v_max.push_back(sqrt(pow(0.3 * 1. / 25. * fsv_max[i], 2) + pow(3. / 100. * v_max[i] / sqrt(uniforme), 2)));
        }
    }
    /*
    Calcolo dei periodi in diversi metodi
    4 interpolazioni su m, p, min, max
        m e p non compatibili
    2 inteprolaz su m-p(intercette) e min-max(stazionari)
        tra loro compatibili, però se usiamo la media ponderata su questa, non teniamo conto che m-p sono incompatibili
    -> prendiamo solo min e max(un fit su due "campioni")

    omega_d
    usando la stima precedente calcolo omega_d con periodo da min e max (stazionari)
    
    */
    void periodi(string dir, vector<string> fnames)
    {
        fit_results gr_m, gr_p, gr_min, gr_max, gr_intercette, gr_stazionari;
        gr_m.root_from_json(dir, fnames[0]);
        gr_p.root_from_json(dir, fnames[1]);
        gr_min.root_from_json(dir, fnames[2]);
        gr_max.root_from_json(dir, fnames[3]);
        gr_intercette.root_from_json(dir, fnames[4]);
        gr_stazionari.root_from_json(dir, fnames[5]);
        cout << "compatibilità MENO e PIU" << endl
             << comp(gr_m.b[0], gr_p.b[0], gr_m.err_b[0], gr_p.err_b[0]) << endl
             << endl
             << "compatibilità MAX e MIN" << endl
             << comp(gr_max.b[0], gr_min.b[0], gr_max.err_b[0], gr_min.err_b[0]) << endl;

        //Stime dai 4 fit
        periodo_p = gr_p.b[0] / pow(10, 6); //periodi in sec
        err_periodo_p = gr_p.err_b[0] / pow(10, 6);
        periodo_m = gr_m.b[0] / pow(10, 6);
        err_periodo_m = gr_m.err_b[0] / pow(10, 6);
        periodo_max = gr_max.b[0] / pow(10, 6);
        err_periodo_max = gr_max.err_b[0] / pow(10, 6);
        periodo_min = gr_min.b[0] / pow(10, 6);
        err_periodo_min = gr_min.err_b[0] / pow(10, 6);

        //Stime derivanti da fit su min-max e p-m
        periodo_intercette = gr_intercette.b[0] / pow(10, 6);
        periodo_stazionari = gr_stazionari.b[0] / pow(10, 6);
        err_periodo_intercette = gr_intercette.err_b[0] / pow(10, 6);
        err_periodo_stazionari = gr_stazionari.err_b[0] / pow(10, 6);

        cout << "Possibli periodi [us]" << endl
             << "-----------" << endl
             << "p_m    \t" << periodo_p * pow(10, 6) << " +- " << err_periodo_p * pow(10, 6) << endl
             << "p_p    \t" << periodo_m * pow(10, 6) << " +- " << err_periodo_m * pow(10, 6) << endl
             << "p_max  \t" << periodo_max * pow(10, 6) << " +- " << err_periodo_max * pow(10, 6) << endl
             << "p_min  \t" << periodo_min * pow(10, 6) << " +- " << err_periodo_min * pow(10, 6) << endl
             << "p_staz \t" << periodo_stazionari * pow(10, 6) << " +- " << err_periodo_stazionari * pow(10, 6) << endl
             << "p_inter\t" << periodo_intercette * pow(10, 6) << " +- " << err_periodo_intercette * pow(10, 6) << endl
             << endl;

        cout << "Comp di max-min vs m-p: " << comp(periodo_intercette, periodo_stazionari, err_periodo_intercette, err_periodo_stazionari) << endl;
        cout << "Periodo da min-max vs m-p: "
             << media_ponderata({periodo_intercette, periodo_stazionari}, {err_periodo_intercette, err_periodo_stazionari})
             << " +-" << errore_media_ponderata({err_periodo_intercette, err_periodo_stazionari}) << endl;

        //!!!!!!!!
        //Poichè m e p non sono compatibili, li buttiamo e teniamo solo stazionari. Da discurtere in relazione e motivare la questione di offset
        periodo = periodo_stazionari;
        err_periodo = err_periodo_stazionari;
    }

    void compute_omega_d()
    {
        //Stime dai 4 fit
        omega_d_p = 2. * M_PI / periodo_p;
        err_omega_d_p = 2. * M_PI * err_periodo_p / pow(periodo_p, 2);
        omega_d_m = 2. * M_PI / periodo_m;
        err_omega_d_m = 2. * M_PI * err_periodo_m / pow(periodo_m, 2);
        omega_d_max = 2. * M_PI / periodo_max;
        err_omega_d_max = 2. * M_PI * err_periodo_max / pow(periodo_max, 2);
        omega_d_min = 2. * M_PI / periodo_min;
        err_omega_d_min = 2. * M_PI * err_periodo_min / pow(periodo_min, 2);

        //Stime derivanti da fit su min-max e p-m
        omega_d_intercette = 2. * M_PI / periodo_intercette;
        err_omega_d_intercette = 2. * M_PI * err_periodo_intercette / pow(periodo_intercette, 2);
        omega_d_stazionari = 2. * M_PI / periodo_stazionari;
        err_omega_d_stazionari = 2. * M_PI * err_periodo_stazionari / pow(periodo_stazionari, 2);

        cout << "Omega_d_p: " << omega_d_p << " +/- " << err_omega_d_p << endl;
        cout << "Omega_d_m: " << omega_d_m << " +/- " << err_omega_d_m << endl;
        cout << "Omega_d_max: " << omega_d_max << " +/- " << err_omega_d_max << endl;
        cout << "Omega_d_min: " << omega_d_min << " +/- " << err_omega_d_min << endl;
        cout << "Omega_d_intercette: " << omega_d_intercette << " +/- " << err_omega_d_intercette << endl;
        cout << "Omega_d_stazionari: " << omega_d_stazionari << " +/- " << err_omega_d_stazionari << endl;

        omega_d = 2. * M_PI / periodo;
        err_omega_d = 2. * M_PI * err_periodo / pow(periodo, 2);
    }

    /*
    calcolo di delta
    1- esponenziale su vmin e vmax
    2- exp su vmin+vmax
    3- lin su vmin e vmax
    4- lin su vmin+vmax
    
    
    */

    void compute_delta_exp(string dir, string fname1, string fname2)
    {
        fit_results d_max, d_min;
        d_max.root_from_json(dir, fname1);
        delta_exp_max = -1. * d_max.b[0] / periodo;
        err_delta_exp_max = sqrt(pow(d_max.err_b[0] / periodo, 2) + pow(err_periodo * d_max.b[0] / pow(periodo, 2), 2));

        d_min.root_from_json(dir, fname2);
        delta_exp_min = -1 * d_min.b[0] / periodo;
        err_delta_exp_min = sqrt(pow(d_min.err_b[0] / periodo, 2) + pow(err_periodo * d_min.b[0] / pow(periodo, 2), 2));

        cout << "Delta_exp_max: " << delta_exp_max << " +/- " << err_delta_exp_max << endl;
        cout << "Delta_exp_min: " << delta_exp_min << " +/- " << err_delta_exp_min << endl;
        cout << "Compatibilità: " << comp(delta_exp_max, delta_exp_min, err_delta_exp_max, err_delta_exp_min) << endl;
    }

    void compute_delta_lin(string dir, string fname1, string fname2)
    {
        fit_results d_max, d_min;
        d_max.root_from_json(dir, fname1);
        delta_lin_max = -1. * d_max.b[0] / periodo;
        err_delta_lin_max = sqrt(pow(d_max.err_b[0] / periodo, 2) + pow(err_periodo * d_max.b[0] / pow(periodo, 2), 2));

        d_min.root_from_json(dir, fname2);
        delta_lin_min = -1. * d_min.b[0] / periodo;
        err_delta_lin_min = sqrt(pow(d_min.err_b[0] / periodo, 2) + pow(err_periodo * d_min.b[0] / pow(periodo, 2), 2));

        cout << "Delta_lin_max: " << delta_lin_max << " +/- " << err_delta_lin_max << endl;
        cout << "Delta_lin_min: " << delta_lin_min << " +/- " << err_delta_lin_min << endl;
        cout << "Compatibilità: " << comp(delta_lin_max, delta_lin_min, err_delta_lin_max, err_delta_lin_min) << endl;
    }

    void compute_delta_unico(string dir, string fname_exp, string fname_lin)
    {
        fit_results d_exp, d_lin;
        d_exp.root_from_json(dir, fname_exp);
        delta_exp = -1. * d_exp.b[0] / periodo;
        err_delta_exp = sqrt(pow(d_exp.err_b[0] / periodo, 2) + pow(err_periodo * d_exp.b[0] / pow(periodo, 2), 2));

        d_lin.root_from_json(dir, fname_lin);
        delta_lin = -1. * d_lin.b[0] / periodo;
        err_delta_lin = sqrt(pow(d_lin.err_b[0] / periodo, 2) + pow(err_periodo * d_lin.b[0] / pow(periodo, 2), 2));

        cout << "Delta_exp: " << delta_exp << " +/- " << err_delta_exp << endl;
        cout << "Delta_lin: " << delta_lin << " +/- " << err_delta_lin << endl;
        cout << "Compatibilità: " << comp(delta_exp, delta_lin, err_delta_exp, err_delta_lin) << endl;

        //OCCHIO QUI
        delta = delta_exp;
        err_delta = err_delta_exp;
    }

    void compute_omega_0()
    {
        omega_0 = sqrt(pow(delta, 2) + pow(omega_d, 2));
        err_omega_0 = sqrt(pow(err_omega_d * omega_d / omega_0, 2) + pow(err_delta * delta / omega_0, 2));
        cout << "Omega_0: " << omega_0 << " +/- " << err_omega_0 << "Hz" << endl;
    }
    void compute_l()
    {
        l = 1 / (pow(omega_0, 2) * c);
        err_l = sqrt(pow(err_c / (pow(omega_0, 2) * pow(c, 2)), 2) + pow(2. * err_omega_0 / (pow(omega_0, 3) * c), 2));
        cout << "L: " << l << " +/- " << err_l << endl;
    }
    void compute_q_value()
    {
        q_value = omega_0 / (2 * delta);
        err_q_value = sqrt(pow(err_omega_0 / (2. * delta), 2) + pow(err_delta * omega_0 / (2. * pow(delta, 2)), 2));
        cout << "Q: " << q_value << " +/- " << err_q_value << endl;
    }
    void compute_r_tot()
    {
        r_tot = sqrt(l / (c * pow(q_value, 2)));
        err_r_tot = sqrt(pow(err_l, 2) / (4 * l * c * pow(q_value, 2)) + pow(err_c, 2) * l / (4 * pow(c, 3) * pow(q_value, 2)) + pow(err_q_value, 2) * l / (c * pow(q_value, 4)));
        cout << "R_tot: " << r_tot << " +/- " << err_r_tot << endl;
    }

    void potenziometro()
    {
        r_t = r_tot + r_p;
        err_r_t = sqrt(pow(err_r_tot, 2) + pow(err_r_p, 2));
        double q_p = 0.5;

        l_p = pow(q_p * r_t, 2) * c;
        err_l_p = sqrt(pow(err_c * pow(q_p * r_t, 2), 2) + pow(2 * err_r_t * r_t * c * pow(q_p, 2), 2));
        cout << "L potenziometro: " << l_p << " +/- " << err_l_p << endl;
        cout << "Comp L-L_p: " << comp(l, l_p, err_l, err_l_p) << endl;
    }
};

//void resistenza_tot()
//{
//    double r_gen;
//    double err_r_gen;
//    double r_l;
//    double err_r_l;
//}

void secondo_metodo_periodi(string dir, string fname)
{
    vector<double> periodi_p;
    vector<double> periodi_m;
    double p_p;
    double err_p_p;
    double p_m;
    double err_p_m;
    double omega_d_p;
    double err_omega_d_p;
    double omega_d_m;
    double err_omega_d_m;
    double p_medio;
    double err_p_medio;
    double omega_d_medio;
    double err_omega_d_medio;

    ifstream fin(dir + "/" + fname);
    if (!fin)
    {
        cout << "Errore lettura file: " + dir + fname << endl;
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
            iss >> measures[0] >> measures[1];
            periodi_p.push_back(measures[0]);
            periodi_m.push_back(measures[1]);
        }
    }
    p_p = media(periodi_p) / pow(10, 6);
    err_p_p = dstd_media(periodi_p) / pow(10, 6);
    p_m = media(periodi_m) / pow(10, 6);
    err_p_m = dstd_media(periodi_m) / pow(10, 6);
    p_medio = (p_p + p_m) / 2;
    err_p_medio = (p_p - p_m) / 2.;
    cout << "(secondo metodo) Periodo medio p: " << p_p << " +/- " << err_p_p << endl;
    cout << "(secondo metodo) Periodo medio m: " << p_m << " +/- " << err_p_m << endl;
    cout << "(secondo metodo) Compatibilità: " << comp(p_p, p_m, err_p_p, err_p_m) << endl;
    cout << "(secondo metodo) Periodo medio: " << p_medio << " +/- " << err_p_medio << endl;
    //cout <<
    omega_d_p = 2. * M_PI / p_p;
    err_omega_d_p = 2. * M_PI * err_p_p / pow(p_p, 2);
    omega_d_m = 2. * M_PI / p_m;
    err_omega_d_m = 2. * M_PI * err_p_m / pow(p_m, 2);
    omega_d_medio = 2. * M_PI / p_medio;
    err_omega_d_medio = 2. * M_PI * err_p_medio / pow(p_medio, 2);
    cout << "(secondo metodo) Omega_d p: " << omega_d_p << " +/- " << err_omega_d_p << endl;
    cout << "(secondo metodo) Omega_d m: " << omega_d_m << " +/- " << err_omega_d_m << endl;
    cout << "(secondo metodo) Compatibilità: " << comp(omega_d_p, omega_d_m, err_omega_d_p, err_omega_d_m) << endl;
    cout << "(secondo metodo) Omega_d medio: " << omega_d_medio << " +/- " << err_omega_d_medio << endl;
}

//--------------------------------------------------------------------------------------------------------Struct RLC in FREQUENZA
//--------------------------------------------------------------------------------------------------------Struct RLC in FREQUENZA
//--------------------------------------------------------------------------------------------------------Struct RLC in FREQUENZA
//--------------------------------------------------------------------------------------------------------Struct RLC in FREQUENZA
//--------------------------------------------------------------------------------------------------------Struct RLC in FREQUENZA
//--------------------------------------------------------------------------------------------------------Struct RLC in FREQUENZA

struct d_frequenza
{
    string description;
    vector<double> freq;      //kHz
    vector<double> v_in;      //mv
    vector<double> v_out;     //mV
    vector<double> fsv_out;   //mV
    vector<double> fsv_in;    //mV
    vector<double> delta_phi; //angolo sessagesimale, ocnvertito in radiante in lettura

    double r;
    double c;
    double l;

    double a_c;
    double a_r;
    double f_0_c_par;
    double f_0_r_par;
    double err_a_c;
    double err_a_r;
    double err_f_0_c_par;
    double err_f_0_r_par;

    double f_t_r_p;
    double err_f_t_r_p;
    double f_t_r_m;
    double err_f_t_r_m;
    double f_t_c_p;
    double err_f_t_c_p;
    double f_t_c_m;
    double err_f_t_c_m;
    double f_t_r_p_sfas;
    double err_f_t_r_p_sfas;
    double f_t_r_m_sfas;
    double err_f_t_r_m_sfas;
    double f_t_c_p_sfas;
    double err_f_t_c_p_sfas;
    double f_t_c_m_sfas;
    double err_f_t_c_m_sfas;
    double f_ris_r_sfas;
    double err_f_ris_r_sfas;
    double f_ris_c_sfas;
    double err_f_ris_c_sfas;

    double delta_f_r_trasf;
    double err_delta_f_r_trasf;
    double delta_f_r_sfas;
    double err_delta_f_r_sfas;
    double delta_f_c_trasf;
    double err_delta_f_c_trasf;
    double delta_f_c_sfas;
    double err_delta_f_c_sfas;

    double q_r_trasf;
    double err_q_r_trasf;
    double q_c_trasf;
    double err_q_c_trasf;
    double q_r_sfas;
    double err_q_r_sfas;
    double q_c_sfas;
    double err_q_c_sfas;

    double err_k_y = 0.012 * sqrt(2);

    /*double f_t_c_trasf_p;
    double f_t_c_trasf_m;
    double f_t_r_trasf_p;
    double f_t_r_trasf_m;
    double f_t_c_sfas_p;
    double f_t_c_sfas_m;
    double f_t_r_sfas_p;
    double f_t_r_sfas_m;
    double err_f_t_c_trasf_p;
    double err_f_t_c_trasf_m;
    double err_f_t_r_trasf_p;
    double err_f_t_r_trasf_m;
    double err_f_t_c_sfas_p;
    double err_f_t_c_sfas_m;
    double err_f_t_r_sfas_p;
    double err_f_t_r_sfas_m;*/

    //Lettura dei dati per i massimi
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
                iss >> measures[0] >> measures[1] >> measures[2] >> measures[3] >> measures[4] >> measures[5];
                freq.push_back(measures[0]);
                v_in.push_back(measures[1]);
                v_out.push_back(measures[2]);
                fsv_out.push_back(measures[3]);
                fsv_in.push_back(measures[4]);
                delta_phi.push_back(measures[5] * M_PI / 180.);
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
            {"description", description},
            {"freq", freq},
            {"v_in", v_in},
            {"v_out", v_out},
            {"fsv_out", fsv_out},
            {"fsv_in", fsv_in},
            {"delta_phi", delta_phi}};

        fout << setw(4) << j << endl;
    }

    void from_json(string directory, string fname)
    {
        json j;
        ifstream fin(directory + "/" + fname);
        if (!fin)
            cout << "Errore lettura " << __FUNCTION__ << fname << endl;
        fin >> j;
        j.at("description").get_to(description);
        j.at("freq").get_to(freq);
        j.at("v_in").get_to(v_in);
        j.at("v_out").get_to(v_out);
        j.at("fsv_out").get_to(fsv_out);
        j.at("fsv_in").get_to(fsv_in);
        j.at("delta_phi").get_to(delta_phi);
    }

    /*
    Calcolo di A_r e A_c con A_c (è Q_c) 
                            A_r (non è Q)
                            f_R (giusta)
                            f_C (stima sbagliata)
    */

    void compute_a_max_c(string directory, string fname)
    {
        fit_results dati_par;
        dati_par.root_from_json(directory, fname);
        double A = dati_par.a[0], B = dati_par.b[0], C = dati_par.c[0];
        double err_A = dati_par.err_a[0], err_B = dati_par.err_b[0], err_C = dati_par.err_c[0];
        double cov_AB = dati_par.covariance_matrix[0][1];
        double cov_BC = dati_par.covariance_matrix[1][2];
        double cov_CA = dati_par.covariance_matrix[2][0];
        f_0_c_par = -B / (2 * C);
        err_f_0_c_par = sqrt(pow(err_B / (2 * C), 2) + pow(B * err_C / (2 * pow(C, 2)), 2) + 2 * (-1 / (2 * C)) * (-B / (2 * pow(C, 2))) * cov_BC);
        a_c = -(pow(B, 2) - 4 * A * C) / (4 * C);
        err_a_c = sqrt(pow(err_A, 2) + pow(err_B * B / (2. * C), 2) + pow(err_C * pow(B / (2. * C), 2), 2) - cov_AB * B / C + cov_CA * pow(B / C, 2) / 2. - cov_BC * pow(B / C, 3) / 4.);
        cout << "F_max_c_par: " << f_0_c_par << " +/- " << err_f_0_c_par << "\t ricordo che è una stima errata su C" << endl;
        cout << "A_c: " << a_c << " +/- " << err_a_c << endl;
    }

    void compute_a_max_r(string directory, string fname)
    {
        fit_results dati_par;
        dati_par.root_from_json(directory, fname);
        double A = dati_par.a[0], B = dati_par.b[0], C = dati_par.c[0];
        double err_A = dati_par.err_a[0], err_B = dati_par.err_b[0], err_C = dati_par.err_c[0];
        double cov_AB = dati_par.covariance_matrix[0][1];
        double cov_BC = dati_par.covariance_matrix[1][2];
        double cov_CA = dati_par.covariance_matrix[2][0];

        f_0_r_par = -B / (2 * C);
        err_f_0_r_par = sqrt(pow(err_B / (2 * C), 2) + pow(B * err_C / (2 * pow(C, 2)), 2) + 2 * (-1 / (2 * C)) * (-B / (2 * pow(C, 2))) * cov_BC);
        //a_r = a_c = A - pow(B, 2) / (4. * C);
        a_r = -(pow(B, 2) - 4 * A * C) / (4 * C);
        err_a_r = sqrt(pow(err_A, 2) + pow(err_B * B / (2. * C), 2) + pow(err_C * pow(B / (2. * C), 2), 2) - cov_AB * B / C + cov_CA * pow(B / C, 2) / 2. - cov_BC * pow(B / C, 3) / 4.);
        //calcola la f risonanza
        cout << "F_ris_r_par: " << f_0_r_par << " +/- " << err_f_0_r_par << endl;
        cout << "A_r: " << a_r << " +/- " << err_a_r << endl;
    }

    /*
    Calcolo di freq taglio da interpolazione lineare su trasferimento per R e per C
    */

    void compute_f_taglio_trasf_r_p(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0],
               err_B = sqrt(pow(dati_lin.err_b[0], 2) + pow(B * err_k_y, 2));
        double cov_AB = dati_lin.covariance_matrix[0][1];
        f_t_r_p = (a_r / sqrt(2) - A) / B;
        err_f_t_r_p = sqrt(pow(err_a_r / (B * sqrt(2)), 2) + pow(err_A / B, 2) + pow(err_B * (-a_r / sqrt(2) + A) / pow(B, 2), 2) + 2 * (a_r / sqrt(2) - A) * cov_AB / pow(B, 3));
        cout << "F_taglio " << fname << " : " << f_t_r_p << "+/-" << err_f_t_r_p << endl;
    }

    void compute_f_taglio_trasf_r_m(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0],
               err_B = sqrt(pow(dati_lin.err_b[0], 2) + pow(B * err_k_y, 2));
        double cov_AB = dati_lin.covariance_matrix[0][1];
        f_t_r_m = (a_r / sqrt(2) - A) / B;
        err_f_t_r_m = sqrt(pow(err_a_r / (B * sqrt(2)), 2) + pow(err_A / B, 2) + pow(err_B * (-a_r / sqrt(2) + A) / pow(B, 2), 2) + 2 * (a_r / sqrt(2) - A) * cov_AB / pow(B, 3));
        cout << "F_taglio " << fname << " : " << f_t_r_m << "+/-" << err_f_t_r_m << endl;
    }

    void compute_f_taglio_trasf_c_p(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0],
               err_B = sqrt(pow(dati_lin.err_b[0], 2) + pow(B * err_k_y, 2));
        double cov_AB = dati_lin.covariance_matrix[0][1];
        f_t_c_p = (a_c / sqrt(2) - A) / B;
        err_f_t_c_p = sqrt(pow(err_a_c / (B * sqrt(2)), 2) + pow(err_A / B, 2) + pow(err_B * (-a_c / sqrt(2) + A) / pow(B, 2), 2) + 2 * (a_c / sqrt(2) - A) * cov_AB / pow(B, 3));
        cout << "F_taglio " << fname << " : " << f_t_c_p << "+/-" << err_f_t_c_p << endl;
    }

    void compute_f_taglio_trasf_c_m(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0],
               err_B = sqrt(pow(dati_lin.err_b[0], 2) + pow(B * err_k_y, 2));
        double cov_AB = dati_lin.covariance_matrix[0][1];
        f_t_c_m = (a_c / sqrt(2) - A) / B;
        err_f_t_c_m = sqrt(pow(err_a_c / (B * sqrt(2)), 2) + pow(err_A / B, 2) + pow(err_B * (-a_c / sqrt(2) + A) / pow(B, 2), 2) + 2 * (a_c / sqrt(2) - A) * cov_AB / pow(B, 3));
        cout << "F_taglio " << fname << " : " << f_t_c_m << "+/-" << err_f_t_c_m << endl;
    }

    /*
    Calcolo di Q da freq taglio per R e per C
    Calcolo di un ulteriore stima di f_risonanza come media geometrica
    */

    void compute_q_r_trasf()
    {
        double f_0 = sqrt(f_t_r_m * f_t_r_p);
        double err_f_0 = sqrt(pow(err_f_t_r_m * f_t_r_p / (2 * sqrt(f_t_r_m * f_t_r_p)), 2) + pow(err_f_t_r_p * f_t_r_m / (2 * sqrt(f_t_r_m * f_t_r_p)), 2));
        q_r_trasf = f_0 / (f_t_r_p - f_t_r_m);
        err_q_r_trasf = sqrt(pow(-(f_t_r_m * (f_t_r_p + f_t_r_m)) / (2 * pow(f_t_r_p - f_t_r_m, 2) * sqrt(f_t_r_p * f_t_r_m)) * err_f_t_r_p, 2) + pow(err_f_t_r_m * f_t_r_p * (f_t_r_p + f_t_r_m) / (2. * pow(f_t_r_p - f_t_r_m, 2) * sqrt(f_t_r_p * f_t_r_m)), 2));
        cout << "F_ris_media_geometrica_r_interpo_lin_trasf: " << f_0 << " +- " << err_f_0 << endl;
        cout << "Q_r_trasf: " << q_r_trasf << " +/- " << err_q_r_trasf << endl;
    }

    void compute_q_c_trasf()
    {
        double f_0 = sqrt(f_t_c_m * f_t_c_p);
        double err_f_0 = sqrt(pow(err_f_t_c_m * f_t_c_p / (2 * sqrt(f_t_c_m * f_t_c_p)), 2) + pow(err_f_t_c_p * f_t_c_m / (2 * sqrt(f_t_c_m * f_t_c_p)), 2));
        q_c_trasf = f_0 / (f_t_c_p - f_t_c_m);
        err_q_c_trasf = sqrt(pow(-(f_t_c_m * (f_t_c_p + f_t_c_m)) / (2 * pow(f_t_c_p - f_t_c_m, 2) * sqrt(f_t_c_p * f_t_c_m)) * err_f_t_c_p, 2) + pow(err_f_t_c_m * f_t_c_p * (f_t_c_p + f_t_c_m) / (2. * pow(f_t_c_p - f_t_c_m, 2) * sqrt(f_t_c_p * f_t_c_m)), 2));
        cout << "F_ris_media_geometrica_c_interpo_lin_trasf: " << f_0 << " +- " << err_f_0 << endl;
        cout << "Q_c_trasf: " << q_c_trasf << " +/- " << err_q_c_trasf << endl;
    }

    /*
    Frequenze di taglio da sfasamenti delta tempi per lineare R
    */
    void compute_f_taglio_sfas_r_p(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0], err_B = dati_lin.err_b[0];
        double cov_AB = dati_lin.covariance_matrix[0][1];

        f_t_r_p_sfas = (M_PI / 4. - A) / B;
        err_f_t_r_p_sfas = sqrt(pow(err_A / B, 2) + pow(err_B * (-M_PI / 4. + A) / pow(B, 2), 2) + 2 * (M_PI / 4. - A) * cov_AB / pow(B, 3));
        cout << "F_taglio " << fname << " : " << f_t_r_p_sfas << "+/-" << err_f_t_r_p_sfas << endl;
    }

    void compute_f_taglio_sfas_r_m(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0], err_B = dati_lin.err_b[0];
        double cov_AB = dati_lin.covariance_matrix[0][1];

        f_t_r_m_sfas = (-M_PI / 4. - A) / B;
        err_f_t_r_m_sfas = sqrt(pow(err_A / B, 2) + pow(err_B * (M_PI / 4. + A) / pow(B, 2), 2) + 2 * (-M_PI / 4. - A) * cov_AB / pow(B, 3));
        cout << "F_taglio " << fname << " : " << f_t_r_m_sfas << "+/-" << err_f_t_r_m_sfas << endl;
    }

    void compute_f_taglio_sfas_c_p(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0], err_B = dati_lin.err_b[0];
        double cov_AB = dati_lin.covariance_matrix[0][1];

        f_t_c_p_sfas = (-3. * M_PI / 4. - A) / B;
        err_f_t_c_p_sfas = sqrt(pow(err_A / B, 2) + pow(err_B * (-3. * M_PI / 4. + A) / pow(B, 2), 2) + 2 * (3. * M_PI / 4. - A) * cov_AB / pow(B, 3));
        cout << "F_taglio " << fname << " : " << f_t_c_p_sfas << "+/-" << err_f_t_c_p_sfas << endl;
    }

    void compute_f_taglio_sfas_c_m(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0], err_B = dati_lin.err_b[0];
        double cov_AB = dati_lin.covariance_matrix[0][1];

        f_t_c_m_sfas = (-M_PI / 4. - A) / B;
        err_f_t_c_m_sfas = sqrt(pow(err_A / B, 2) + pow(err_B * (-M_PI / 4. + A) / pow(B, 2), 2) + 2 * (M_PI / 4. - A) * cov_AB / pow(B, 3));
        cout << "F_taglio " << fname << " : " << f_t_c_m_sfas << "+/-" << err_f_t_c_m_sfas << endl;
    }

    void compute_q_c_sfas()
    {
        double f_0 = sqrt(f_t_c_m_sfas * f_t_c_p_sfas);
        double err_f_0 = sqrt(pow(err_f_t_c_m_sfas * f_t_c_p_sfas / (2 * sqrt(f_t_c_m_sfas * f_t_c_p_sfas)), 2) + pow(err_f_t_c_p_sfas * f_t_c_m_sfas / (2 * sqrt(f_t_c_m_sfas * f_t_c_p_sfas)), 2));
        q_c_sfas = f_0 / (f_t_c_p_sfas - f_t_c_m_sfas);
        err_q_c_sfas = sqrt(pow(-(f_t_c_m_sfas * (f_t_c_p_sfas + f_t_c_m_sfas)) / (2 * pow(f_t_c_p_sfas - f_t_c_m_sfas, 2) * sqrt(f_t_c_p_sfas * f_t_c_m_sfas)) * err_f_t_c_p_sfas, 2) + pow(err_f_t_c_m_sfas * f_t_c_p_sfas * (f_t_c_p_sfas + f_t_c_m_sfas) / (2. * pow(f_t_c_p_sfas - f_t_c_m_sfas, 2) * sqrt(f_t_c_p_sfas * f_t_c_m_sfas)), 2));
        cout << "F_ris_media_geometrica_c_interpo_lin_sfas: " << f_0 << " +/- " << err_f_0 << endl;
        cout << "Q_c_sfas: " << q_c_sfas << " +/- " << err_q_c_sfas << endl;
    }
    

    void compute_q_r_sfas()
    {
        double f_0 = sqrt(f_t_r_m_sfas * f_t_r_p_sfas);
        double err_f_0 = sqrt(pow(err_f_t_r_m_sfas * f_t_r_p_sfas / (2 * sqrt(f_t_r_m_sfas * f_t_r_p_sfas)), 2) + pow(err_f_t_r_p_sfas * f_t_r_m_sfas / (2 * sqrt(f_t_r_m_sfas * f_t_r_p_sfas)), 2));
        q_r_sfas = f_0 / (f_t_r_p_sfas - f_t_r_m_sfas);
        err_q_r_sfas = sqrt(pow(-(f_t_r_m_sfas * (f_t_r_p_sfas + f_t_r_m_sfas)) / (2 * pow(f_t_r_p_sfas - f_t_r_m_sfas, 2) * sqrt(f_t_r_p_sfas * f_t_r_m_sfas)) * err_f_t_r_p_sfas, 2) + pow(err_f_t_r_m_sfas * f_t_r_p_sfas * (f_t_r_p_sfas + f_t_r_m_sfas) / (2. * pow(f_t_r_p_sfas - f_t_r_m_sfas, 2) * sqrt(f_t_r_p_sfas * f_t_r_m_sfas)), 2));
        cout << "F_ris_media_geometrica_r_interpo_lin_sfas: " << f_0 << " +/- " << err_f_0 << endl;
        cout << "Q_r_sfas: " << q_r_sfas << " +/- " << err_q_r_sfas << endl;
    }
    /*
    Freq risonanza da interp lin su R sfasamento
    */
    void f_ris_lin_r(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0], err_B = dati_lin.err_b[0];
        double cov_AB = dati_lin.covariance_matrix[0][1];

        f_ris_r_sfas = (-A) / B;
        err_f_ris_r_sfas = sqrt(pow(err_A / B, 2) + pow(err_B * (A) / pow(B, 2), 2) + 2 * (A)*cov_AB / pow(B, 3));
        cout << "F_ris " << fname << " : " << f_ris_r_sfas << "+/-" << err_f_ris_r_sfas << endl;
    }

    /*NON ANCORA ESEGUIBILE*/
    void f_ris_lin_c(string directory, string fname)
    {
        fit_results dati_lin;
        dati_lin.root_from_json(directory, fname);
        double A = dati_lin.a[0], B = dati_lin.b[0];
        double err_A = dati_lin.err_a[0], err_B = dati_lin.err_b[0];
        double cov_AB = dati_lin.covariance_matrix[0][1];

        f_ris_c_sfas = (-A) / B;
        err_f_ris_c_sfas = sqrt(pow(err_A / B, 2) + pow(err_B * (A) / pow(B, 2), 2) + 2 * (A)*cov_AB / pow(B, 3));
        cout << "F_ris " << fname << " : " << f_ris_r_sfas << "+/-" << err_f_ris_r_sfas << endl;
    }

    void larghezza_banda_r()
    {
        delta_f_r_trasf = f_t_r_p - f_t_r_m;
        err_delta_f_r_trasf = sqrt(pow(err_f_t_r_p, 2) + pow(err_f_t_r_m, 2));
        cout << "Larghezza banda r in trasf: " << delta_f_r_trasf << " +/- " << err_delta_f_r_trasf << endl;
        delta_f_r_sfas = f_t_r_p_sfas - f_t_r_m_sfas;
        err_delta_f_r_sfas = sqrt(pow(err_f_t_r_p_sfas, 2) + pow(err_f_t_r_m_sfas, 2));
        cout << "Larghezza banda r in sfas: " << delta_f_r_sfas << " +/- " << err_delta_f_r_sfas << endl;
    }

    void larghezza_banda_c()
    {
        delta_f_c_trasf = f_t_c_p - f_t_c_m;
        err_delta_f_c_trasf = sqrt(pow(err_f_t_c_p, 2) + pow(err_f_t_c_m, 2));
        cout << "Larghezza banda c in trasf: " << delta_f_c_trasf << " +/- " << err_delta_f_c_trasf << endl;
        delta_f_c_sfas=f_t_c_p_sfas-f_t_c_m_sfas;
        err_delta_f_c_sfas=sqrt(pow(err_f_t_c_p_sfas,2)+pow(err_f_t_c_m_sfas,2));
        cout<<"Larghezza banda c in sfas: "<<delta_f_c_sfas<<" +/- "<<err_delta_f_c_sfas<<endl;
    }
};

void compute_from_fit_non_lineari_trasf(string dir, string fname)
{
    fit_results fit_trasf;
    fit_trasf.root_from_json(dir, fname);
    double a = fit_trasf.a[0];
    double r = fit_trasf.b[0];
    double l = fit_trasf.c[0];
    double c = fit_trasf.d[0];
    double err_a = fit_trasf.err_a[0];
    double err_r = fit_trasf.err_b[0];
    double err_l = fit_trasf.err_c[0];
    double err_c = fit_trasf.err_d[0];
    double cov_lc = fit_trasf.covariance_matrix[2][3];
    double cov_lr = fit_trasf.covariance_matrix[1][2];
    double cov_rc = fit_trasf.covariance_matrix[1][3];

    double f_0 = 1. / (2 * M_PI * sqrt(l * c)); //freuqenza risonanza
    double err_f_0 = sqrt(pow(err_c * l/ (4 * M_PI * pow(l * c, 1.5)), 2) +
                          pow(err_l * c / (4 * M_PI *  pow(l * c, 1.5)), 2) +
                          2 * cov_lc * l * c / ((4 * M_PI * pow(l * c, 1.5)) * (4 * M_PI * pow(l * c, 1.5))));
    double q = sqrt(l / (pow(r, 2) * c)); //q valore
    double err_q = sqrt(pow(q * err_l / (2 * l), 2) +
                        pow(q * err_r / r, 2) +
                        pow(q * err_c / (2 * c), 2) +
                        2 * cov_lc * (q / (2 * l)) * (-q / (2 * c)) +
                        2 * cov_lr * (q / (2 * l)) * (-q / r) +
                        2 * cov_rc * (-q / r) * (-q / (2 * c)));
    double delta_omega = r / (2 * M_PI * l); //banda passante
    double err_delta_omega = sqrt(pow(err_r / (2 * M_PI * l), 2) +
                                  pow(r * err_l / pow((2 * M_PI * l), 2), 2) +
                                  2 * cov_lr * (err_r / (2 * M_PI * l)) * (-r * err_l / pow((2 * M_PI * l), 2))); //errore banda passante
    cout << "Valori fit non lineari " + fname << endl;
    cout << "q: " << q << " +- " << err_q << endl;
    cout << "f_0: " << f_0 << " +- " << err_f_0 << endl;
    cout << "delta_omega: " << delta_omega << " +- " << err_delta_omega << endl
         << endl;
}

void compute_from_fit_non_lineari_sfas(string dir, string fname)
{
    fit_results fit_trasf;
    fit_trasf.root_from_json(dir, fname);
    double r = fit_trasf.a[0];
    double l = fit_trasf.b[0];
    double c = fit_trasf.c[0];
    double err_r = fit_trasf.err_a[0];
    double err_l = fit_trasf.err_b[0];
    double err_c = fit_trasf.err_c[0];
    double cov_lc = fit_trasf.covariance_matrix[2][1];
    double cov_lr = fit_trasf.covariance_matrix[1][0];
    double cov_rc = fit_trasf.covariance_matrix[0][2];

    double f_0 = 1. / (2 * M_PI * sqrt(l * c)); //freuqenza risonanza
    double err_f_0 = sqrt(pow(err_c * l/ (4 * M_PI * pow(l * c, 1.5)), 2) +
                          pow(err_l * c / (4 * M_PI *  pow(l * c, 1.5)), 2) +
                          2 * cov_lc * l * c / ((4 * M_PI * pow(l * c, 1.5)) * (4 * M_PI * pow(l * c, 1.5))));
    double q = sqrt(l / (pow(r, 2) * c)); //q valore
    double err_q = sqrt(pow(q * err_l / (2 * l), 2) +
                        pow(q * err_r / r, 2) +
                        pow(q * err_c / (2 * c), 2) +
                        2 * cov_lc * (q / (2 * l)) * (-q / (2 * c)) +
                        2 * cov_lr * (q / (2 * l)) * (-q / r) +
                        2 * cov_rc * (-q / r) * (-q / (2 * c)));
    double delta_omega = r / (2 * M_PI * l); //banda passante
    double err_delta_omega = sqrt(pow(err_r / (2 * M_PI * l), 2) +
                                  pow(r * err_l / pow((2 * M_PI * l), 2), 2) +
                                  2 * cov_lr * (err_r / (2 * M_PI * l)) * (-r * err_l / pow((2 * M_PI * l), 2))); //errore banda passante
    cout << "Valori fit non lineari " + fname << endl;
    cout << "q: " << q << " +- " << err_q << endl;
    cout << "f_0: " << f_0 << " +- " << err_f_0 << endl;
    cout << "delta_omega: " << delta_omega << " +- " << err_delta_omega << endl
         << endl;
}

struct d_frequenza_tempi
{
    string description;
    vector<double> freq; //kHz
    vector<double> t_1;  //us
    vector<double> t_2;  //us
    vector<double> fst;  //ns

    //Lettura dei dati per i massimi
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
                vector<double> measures(4);
                iss >> measures[0] >> measures[1] >> measures[2] >> measures[3];
                freq.push_back(measures[0]);
                t_1.push_back(measures[1]);
                t_2.push_back(measures[2]);
                fst.push_back(measures[3]);
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
            {"description", description},
            {"freq", freq},
            {"t_1", t_1},
            {"t_2", t_2},
            {"fst", fst}};

        fout << setw(4) << j << endl;
    }

    void from_json(string directory, string fname)
    {
        json j;
        ifstream fin(directory + "/" + fname);
        if (!fin)
            cout << "Errore lettura " << __FUNCTION__ << fname << endl;
        fin >> j;
        j.at("description").get_to(description);
        j.at("freq").get_to(freq);
        j.at("t_1").get_to(t_1);
        j.at("t_2").get_to(t_2);
        j.at("fst").get_to(fst);
    }
};

void v_in(string dir, string fname)
{
    double v_in = 7000; //quella che ho messo in entrata
    double r_10 = 9.90; //la resistenza che ho usato per sta cosa
    double r_50 = 46.86;
    double err_r_50 = err_res_cap(r_50, 0.07, 8, 0.0001); //con metrix
    double err_r_10 = err_res_cap(r_10, 0.07, 8, 0.0001); //da parametri fondo scala che ho usato per la resistenza da 10, con metrix
    fit_results fit_par;
    fit_par.root_from_json(dir, fname);
    double f_min = -fit_par.b[0] / (2 * fit_par.c[0]);
    double v_min = fit_par.a[0] + fit_par.b[0] * f_min + fit_par.c[0] * pow(f_min, 2);
    double a = v_min / v_in;
    //double err_a=
    double v_scarica = 7640,
           v_carica = 3560,
           err_v_carica = 1000 / (25 * sqrt(12)),
           err_v_scarica = 1000 / (25 * sqrt(12));
    double r_gen = r_50 * (v_scarica - v_carica) / v_carica; //r(e-V)/V
    double err_r_gen = sqrt(pow((v_scarica - v_carica) * err_r_50 / v_carica, 2) + pow(r_50 * err_v_scarica / v_carica, 2) + pow(r_50 * err_v_carica * v_scarica / pow(v_carica, 2), 2));

    double r_tot = -r_gen / (a - 1);
    double r_l = a / (1 - a) * r_gen - r_10;
    double err_r_l = 123456;
    cout << "V_min di V-in " << v_min << endl;
    cout << "Resistenza generatore " << r_gen << " +- " << err_r_gen << endl;
    cout << "Resistenza totale circuito " << r_tot << " " + fname << endl;
    cout << "Resistenza induzione da rlc frequenza " << r_l << " +- " << err_r_l << " " + fname << endl;
}