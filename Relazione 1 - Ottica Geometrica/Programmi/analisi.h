/*
Contiene le definizioni di tutte le funzioni e elaborazione dei dati
*/
#pragma once
#include "containers.h"
#include "statistica.h"

void Coniugati::compute_diffs(double sp_lente, double sp_limatura, double err_posizioni, double err_sp_lente, double err_sp_lim) //:: definire una funzione dichiarata dentro una struttura coniugati
{
    for (int i = 0; i < p0.size(); i++)
    {
        p.push_back(pl[i] - p0[i] + (sp_limatura / 2.0) - (sp_lente / 6.0));
        q.push_back(ps[i] - pl[i] - (sp_limatura / 2.0) - (sp_lente / 6.0));
        err_p.push_back(sqrt(pow(err_posizioni, 2) + pow(err_posizioni, 2) + pow((0.5 * err_sp_lim), 2) + pow(((1.0 / 6.0) * err_sp_lente), 2)));
        err_q.push_back(sqrt(pow(err_posizioni, 2) + pow(err_posizioni, 2) + pow((0.5 * err_sp_lim), 2) + pow(((1.0 / 6.0) * err_sp_lente), 2)));

        //Calcolo e propagazione dei reciproci sigma=sqrt(sigma^2/(p^4))
        p_1.push_back(1.0 / p[i]);
        q_1.push_back(1.0 / q[i]);
        err_p_1.push_back((err_p[i] / pow(p[i], 2)));
        err_q_1.push_back((err_q[i] / pow(q[i], 2)));
    }
}

//Legge dati stampati da root
void Coniugati::leggo_root()
{
    string temp_line;
    ifstream fin("../File/risultati_fit" + name);
    if (!fin)
    {
        cout << "Errore lettura parametri da root ../File/risultati_fit" + name << endl;
    }
    while (getline(fin, temp_line))
    {
        if (temp_line.rfind("#", 0) == 0 || temp_line.size() < 5)
        {
            continue;
        }
        else
        {
            istringstream iss(temp_line);
            vector<double> measures;
            double temp_num;
            while (iss >> temp_num)
            {
                measures.push_back(temp_num);
            }
            b_ang = measures[0];
            err_b_ang = measures[1];
            a_int = measures[2] / 1000;
            err_a_int = measures[3] / 1000;
            chi_f = measures[4];
            cov_ab = measures[5];
        }
    }
};

//Calcolo di fuoco per ogni operatore da dati root
void Coniugati::compute_f()
{
    leggo_root();
    f_1 = 1.0 / a_int;
    err_f_1 = err_a_int / pow(a_int, 2);
    f_2 = -1.0 * b_ang / a_int;
    err_f_2 = sqrt(pow(b_ang / pow(a_int, 2) * err_a_int, 2) + pow(err_b_ang / a_int, 2) + 2.0 * b_ang / pow(a_int, 3) * cov_ab);
    f_12 = (f_1 + f_2) / 2.0;
    err_f_12 = abs(f_1 - f_2) / 2.0;
};

void Coniugati::compute_f_algebrico(double sp_lente, double sp_limatura)
{
    ofstream fout("../File/f_alg" + name);
    for (int i = 0; i < p0.size(); i++)
    {
        f.push_back((pl[i] - p0[i] + sp_limatura / 2.0 - sp_lente / 6.0) * (ps[i] - pl[i] - sp_limatura / 2.0 - sp_lente / 6.0) / (ps[i] - p0[i] - sp_lente / 3.0));
        err_f.push_back(__DBL_MAX__);
        fout << f[i] << "\t" << err_f[i] << endl;
    }
    f_alg = media(f);
    err_f_alg = dstd_media(f);
};

//
//FINE CONIUGATI-------------------------------------------------------------------------------------------------
//
void Bessel::compute_s(double err_posizione)
{
    for (int i = 0; i < pm.size(); i++)
    {
        s.push_back(pp[i] - pm[i]);
        err_s.push_back(sqrt(pow(err_posizione, 2) * 2.0));
    }
}

void Bessel::compute_l(double sp_lente, double err_sp_lente, double err_p0, double err_ps)
{
    for (int i = 0; i < p0.size(); i++)
    {
        l.push_back(ps[i] - p0[i] - (sp_lente / 3.0));
        err_l.push_back(sqrt(pow(err_p0, 2) + pow(err_ps, 2) + (pow(err_sp_lente, 2) / 9.0)));
    }
}

void Bessel::compute_f()
{
    for (int i = 0; i < l.size(); i++)
    {
        f.push_back((pow(l[i], 2) - pow(s[i], 2)) / (4.0 * l[i]));
        err_f.push_back(sqrt(pow(((pow(l[i], 2) + pow(s[i], 2)) * (pow(err_l[i], 2))) / (16.0 * pow(l[i], 2)), 2) + pow(((pow(s[i], 2) * pow(err_s[i], 2)) / (4.0 * pow(l[i], 2))), 2)));
    }
    f_complessivo = media(f);
    err_f_complessivo = dstd_media(f);
}

void Bessel::compute_f_from_s(double err_posizione)
{
    s_ = media(s);
    err_s_ = dstd_media(s);
    if (l.size() == 0)
    {
        cout << "Errore: calcolare l in vettore." << endl;
    }
    double l_ = l[0];
    double err_l_ = sqrt(2) * err_posizione;
    f_from_s = (pow(l_, 2) - pow(s_, 2)) / (4.0 * l_);
    err_f_from_s = sqrt(pow(((pow(l_, 2) + pow(s_, 2)) * (pow(err_l_, 2))) / (16.0 * pow(l_, 2)), 2) + pow(((pow(s_, 2) * pow(err_s_, 2)) / (4.0 * pow(l_, 2))), 2)); //qui serve la piacevole sorpresa
}
//
//FINE BESSEL-------------------------------------------------------------------------------------------------
//

void Sferica::compute_l(double err_posizione)
{
    ofstream fout("../File/aberr_sferica_l" + name);
    for (int i = 0; i < fpf.size(); i++)
    {
        l.push_back((fpf[i] + fpi[i]) / 2.0 - fm[i]);
    }
    for (int i = 0; i < fpf.size(); i++)
    {
        err_l.push_back(dstd(l));
        fout << l[i] << "\t" << err_l[i] << endl;
    }
}

void Sferica::compute_c(double R, double err_R, double f)
{
    for (int i = 0; i < l.size(); i++)
    {
        c.push_back((l[i] * f) / pow(R, 2));
    }
    c_complessiva = media(c);
    err_c_complessiva = dstd_media(c);
}
//
//FINE SFERICA-------------------------------------------------------------------------------------------------
//

void Cromatica::compute_a()
{
    for (int i = 0; i < fb.size(); i++)
    {
        a.push_back(fr[i] - fb[i]);
        err_a.push_back(__DBL_MAX__);
    }
}

void Cromatica::compute_v(double f)
{
    ofstream fout("../File/cromatica_v" + name);
    for (int i = 0; i < a.size(); i++)
    {
        v.push_back(f / a[i]);
    }
    for (int i = 0; i < a.size(); i++)
    {
        err_v.push_back(dstd(v));
    }
    v_complessivo = media(v);
    err_v_complessivo = dstd_media(v);
}