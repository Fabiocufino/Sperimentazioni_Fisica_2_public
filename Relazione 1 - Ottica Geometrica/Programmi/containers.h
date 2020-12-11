#pragma once
#include <vector>
#include "statistica.h"
using namespace std;
struct Coniugati
{
    string name;
    vector<double> p0;
    vector<double> pl;
    vector<double> ps;
    //Misure unbiased con propagazione relativa
    vector<double> p;     //corrected values, unbiased from lens depth
    vector<double> err_p; //
    vector<double> q;     //corrected values
    vector<double> err_q; //

    vector<double> p_1;     // reciproco di p, q ed err
    vector<double> q_1;     //
    vector<double> err_p_1; //
    vector<double> err_q_1; //

    //Calcolo di f da ciascuna singola misura
    vector<double> f;
    vector<double> err_f;

    //Parametri risultanti da interpoalz lineare di 1/p o da lettura di file da root
    double a_int;
    double err_a_int;
    double b_ang;
    double err_b_ang;
    double chi_f;
    double cov_ab;

    //usati da interpolazione e da root per archivio varaibili
    double f_1;
    double err_f_1;
    double f_2;
    double err_f_2;
    double f_12;
    double err_f_12;
    double f_2_inv;
    double err_f_2_inv;

    //algebrico
    double f_alg;
    double err_f_alg;

    //Stores in the right oreder every value
    void add(vector<double> temp_vec)
    {
        p0.push_back(temp_vec[0] * 10.0);
        pl.push_back(temp_vec[1] * 10.0);
        ps.push_back(temp_vec[2] * 10.0);
    }

    //controlla che i dati letti siano coerenti fra loro e non ci siano misssing values
    int check_consistency() 
    {
        if (p0.size() != ps.size() || ps.size() != pl.size())
        {
            return 1;
        }
        return 0;
    }

    //for quick debugging, prints every data inside the object
    void print_raw()
    {
        cout << "Printing info for " << name << endl;
        cout << "p0\tpl\tps" << endl;
        for (int i = 0; i < ps.size(); i++)
        {
            cout << p0[i] << "\t" << pl[i] << "\t" << ps[i] << endl;
        }
    }
    void print_unbiased()
    {
        cout << "Printing info for " << name << endl;
        cout << "p\terr_p\tq\terr_q" << endl;
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i] << "\t" << err_p[i] << "\t" << q[i] << "\t" << err_q[i] << endl;
        }
    }
    void print_unbiased_coniugati(string fname = "")
    {
        if (fname != "")
        {
            ofstream fout("../File/" + fname);
            for (int j = 0; j < p_1.size(); j++)
            {

                fout << p_1[j] * 1000 << "\t" << q_1[j] * 1000 << "\t" << err_p_1[j] * 1000 << "\t" << err_q_1[j] * 1000 << endl; //ATTENZIONE AL *1000 L'HA AGGIUNTO FABIO
            }
        }
    }

    //corregge le misure dallo spessore della lente e esegue le relative propagazioni di errore
    void compute_diffs(double sp_lente, double sp_limatura, double err_p, double err_sp_lente, double err_sp_lim);

    //Legge parametri root 
    void leggo_root();
    void compute_f();
    void compute_f_algebrico(double sp_lente, double sp_limatura);
};

struct Bessel
{
    string name;
    vector<double> p0;
    vector<double> ps;
    vector<double> pm;
    vector<double> pp;

    vector<double> s;
    vector<double> err_s;
    double s_;
    double err_s_;
    vector<double> l;
    vector<double> err_l;
    vector<double> f;
    vector<double> err_f;

    //Metodo (1) calcolo di f da media di f
    double f_complessivo = 0;
    double err_f_complessivo = 0;

    //Metodo (2) calcolo di f da media di s
    double f_from_s;
    double err_f_from_s;

    void add(vector<double> temp_vec, double pos_luce, double pos_schermo)
    {
        pm.push_back(temp_vec[0] * 10.0);
        pp.push_back(temp_vec[1] * 10.0);
        p0.push_back(pos_luce);
        ps.push_back(pos_schermo);
    }
    int check_consistency()
    {
        if (pm.size() != pp.size())
        {
            return 1;
        }
        return 0;
    }

    //Compute difference of focal points' positions
    void compute_s(double err_posizione);
    void compute_l(double sp_lente, double err_sp_lente, double err_p0, double err_ps);

    //Metodo che calcola la media delle f
    void compute_f();
    void compute_f_from_s(double err_posizione);
};

struct Sferica
{
    string name;
    vector<double> fm;
    vector<double> fpi;
    vector<double> fpf;
    vector<double> l;
    vector<double> err_l;
    vector<double> c;
    vector<double> err_c;
    double c_complessiva;
    double err_c_complessiva;
    void add(vector<double> temp_vec)
    {
        fm.push_back(temp_vec[0]);
        fpi.push_back(temp_vec[1]);
        fpf.push_back(temp_vec[2]);
    }
    int check_consistency()
    {
        if (fm.size() != fpi.size() || fpf.size() != fpi.size())
        {
            return 1;
        }
        return 0;
    }

    void compute_l(double err_posizione);
    void compute_c(double R, double err_R, double f);
};

struct Cromatica
{
    string name;
    vector<double> fb;
    vector<double> fr;
    vector<double> a;
    vector<double> err_a;
    vector<double> v;
    vector<double> err_v;
    double v_complessivo;
    double err_v_complessivo;
    void add(vector<double> temp_vec)
    {
        fb.push_back(temp_vec[0]);
        fr.push_back(temp_vec[1]);
    }
    int check_consistency()
    {
        if (fb.size() != fr.size())
        {
            return 1;
        }
        return 0;
    }
    void compute_a());
    void compute_v(double f);
};