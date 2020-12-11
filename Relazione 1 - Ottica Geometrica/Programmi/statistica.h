/*
includere tutte le funzioni per analisi statistica già conosciute
*/
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;

//Media aritmetica semplice
double media(vector<double> dati, int inizio = 0, int fine = 0)
{
    double media_ = 0;
    if (fine != 0)
    {
        double counter_parz = 0, sum_parz = 0;
        for (int i = inizio; i < fine; i++) // Attenzione a <, la funzione non tiene in considerazione l'ultimo elemento, come i vettori.
        {
            sum_parz = sum_parz + dati[i];
            counter_parz++;
        }
        media_ = sum_parz / counter_parz;
    }
    else if (fine == 0)
    {
        double sum = 0;
        for (auto c : dati)
        {
            sum = sum + c;
        }
        media_ = sum / dati.size();
    }
    return media_;
}

//Deviazione Standard del CAMPIONE (N a denominatore)
double dev_stand_campione(vector<double> dati, int inizio = 0, int fine = 0)
{
    double squad;
    double media_camp;
    double somma_camp;
    int counter = 0;

    if (fine != 0)
    {
        media_camp = media(dati, inizio, fine);
        for (int j = inizio; j < fine; j++)
        {
            somma_camp = somma_camp + (media_camp - dati[j]) * (media_camp - dati[j]);
            counter++;
        }
        squad = sqrt(somma_camp / counter);
    }
    else if (fine == 0)
    {
        media_camp = media(dati);
        for (auto d : dati)
        {
            somma_camp = somma_camp + (media_camp - d) * (media_camp - d);
        }
        counter = dati.size();
        squad = sqrt(somma_camp / counter);
    }

    return squad;
}

//Deviazione standard della POPOLAZIONE (N-1 a denominatore)
double dstd(vector<double> dati, int inizio = 0, int fine = 0)
{
    double dstd_camp;
    double media_camp;
    double somma_camp;
    int counter = 0;
    media_camp = media(dati, inizio, fine);
    if (fine != 0)
    {
        for (int j = inizio; j < fine; j++)
        {
            somma_camp = somma_camp + (media_camp - dati[j]) * (media_camp - dati[j]);
            counter++;
        }
        dstd_camp = sqrt(somma_camp / (counter - 1));
    }
    else if (fine == 0)
    {
        for (auto c : dati)
        {
            somma_camp = somma_camp + (media_camp - c) * (media_camp - c);
        }
        counter = dati.size();
        dstd_camp = sqrt(somma_camp / (counter - 1));
    }
    return dstd_camp;
}

//Deviazione standard della media (restituisce dstd/sqrt(Numero dati))
double dstd_media(vector<double> dati, int inizio = 0, int fine = 0)
{
    double dstd_media_;
    if (fine != 0)
    {
        dstd_media_ = dstd(dati, inizio, fine) / sqrt(fine - inizio);
    }
    else if (fine == 0)
    {
        dstd_media_ = dstd(dati) / sqrt(dati.size());
    }
    return dstd_media_;
}

//Errore distribuzione triangolare
double sigma_dist_tri(double ptl, double coeff_aff)
{
    return abs(ptl / coeff_aff) / sqrt(24); //ptl con il coeff aff � doppio di err max
}

//Errore distribuzione uniforme
double sigma_dist_uni(double ptl, double coeff_aff)
{
    return abs(ptl / coeff_aff) / sqrt(12); //ptl con il suo coeff aff è il doppio di err max
}

//Compatibilità
double comp(double a, double b, double sigma_a, double sigma_b)
{
    return abs(a - b) / sqrt(pow(sigma_a, 2) + pow(sigma_b, 2));
}

//Media ponderata con errori
double media_ponderata(vector<double> valori, vector<double> errori, int inizio = 0, int fine = 0)
{
    double num = 0, den = 0;
    if (fine == 0)
    {
        fine = valori.size();
    }
    if (valori.size() != errori.size())
    {
        cout << "dimensione di vettore valori non è uguale a quella di vettore errori" << endl;
        return 1;
    }
    for (int i = inizio; i < fine; i++)
    {
        num += valori[i] * pow((1 / errori[i]), 2);
        den += pow((1 / errori[i]), 2);
    }
    return num / den;
}

//Errore medio (media ponderata)
double errore_media_ponderata(vector<double> errori)
{
    double sum = 0;
    for (auto d : errori)
    {
        sum += pow((1 / d), 2);
    }
    return (1 / sqrt(sum));
}

//Calcolo di Delta con errori tutti diversi
double delta(vector<double> dati_x, vector<double> errori_y)
{
    double delta_d_ = 0;
    double sum_1 = 0, sum_2 = 0, sum_3 = 0;
    for (int i = 0; i < dati_x.size(); i++)
    {
        sum_1 = sum_1 + (1. / pow(errori_y[i], 2));
        sum_2 = sum_2 + (pow(dati_x[i], 2) / pow(errori_y[i], 2));
        sum_3 = sum_3 + (dati_x[i] / pow(errori_y[i], 2));
    }
    delta_d_ = sum_1 * sum_2 - pow(sum_3, 2);
    return delta_d_;
}

//Coeff. a di y=a+bx con errori tutti diversi (intercetta)
double a_intercetta(vector<double> dati_x, vector<double> dati_y, vector<double> errori_y)
{
    double a_intercetta_d_ = 0;
    double sum_1 = 0, sum_2 = 0, sum_3 = 0, sum_4 = 0;
    for (int i = 0; i < dati_x.size(); i++)
    {
        sum_1 = sum_1 + pow((dati_x[i] / errori_y[i]), 2);
        sum_2 = sum_2 + (dati_y[i] / pow(errori_y[i], 2));
        sum_3 = sum_3 + (dati_x[i] / pow(errori_y[i], 2));
        sum_4 = sum_4 + ((dati_x[i] * dati_y[i]) / pow(errori_y[i], 2));
    }
    a_intercetta_d_ = (1. / delta(dati_x, errori_y)) * (sum_1 * sum_2 - sum_3 * sum_4);
    return a_intercetta_d_;
}
//Coeff. b di y=a+bx con errori tutti diversi (coeff. ang.)
double b_angolare(vector<double> dati_x, vector<double> dati_y, vector<double> errori_y)
{
    double b_angolare_d_ = 0;
    double sum_1 = 0, sum_2 = 0, sum_3 = 0, sum_4 = 0;
    for (int i = 0; i < dati_x.size(); i++)
    {
        sum_1 = sum_1 + (1 / pow(errori_y[i], 2));
        sum_2 = sum_2 + ((dati_x[i] * dati_y[i]) / (pow(errori_y[i], 2)));
        sum_3 = sum_3 + ((dati_x[i]) / (pow(errori_y[i], 2)));
        sum_4 = sum_4 + (dati_y[i] / pow(errori_y[i], 2));
    }
    b_angolare_d_ = (1 / delta(dati_x, errori_y)) * (sum_1 * sum_2 - sum_3 * sum_4);
    return b_angolare_d_;
}

//Test CHi quadro per interpolazione lineare
double test_chi(vector<double> dati_x, vector<double> dati_y, vector<double> err_dati_y)
{
    double somma_contributi = 0;
    double a = a_intercetta(dati_x, dati_y, err_dati_y);
    double b = b_angolare(dati_x, dati_y, err_dati_y);
    for (int i = 0; i < dati_x.size(); i++)
    {
        somma_contributi = somma_contributi + (pow(((dati_y[i] - a - b * dati_x[i]) / err_dati_y[i]), 2)); //aggiunta di scarto normalizzato
    }
    return somma_contributi;
}

//Delta (chi-quadro) [errori tutti uguali o del tutto assenti]
double delta_err_uguali(vector<double> dati_x, int inizio = 0, int fine = 0)
{
    double delta_;
    double size = 0;
    double sum_1 = 0, sum_2 = 0;
    if (fine == 0)
    {
        size = dati_x.size();
        for (auto d : dati_x)
        {
            sum_1 = sum_1 + pow(d, 2);
            sum_2 = sum_2 + d;
        }
        delta_ = size * sum_1 - pow(sum_2, 2);
    }
    else if (fine != 0)
    {
        for (int i = inizio; i < fine; i++)
        {
            size++;
            sum_1 = sum_1 + pow(dati_x.at(i), 2);
            sum_2 = sum_2 + dati_x.at(i);
        }
        delta_ = size * sum_1 - pow(sum_2, 2);
    }

    return delta_;
}

//Coefficiente a di y=a+bx (intercetta)
double a_intercetta_err_uguali(vector<double> dati_x, vector<double> dati_y)
{
    double coeff_a;
    double delta_;
    double sum_1 = 0, sum_2 = 0, sum_3 = 0, sum_4 = 0;

    if (dati_y.size() != dati_x.size())
    {
        cout << endl
             << "Dimensione di vettore per dati ascisse è diversa da dimensione vettore dati ordinate" << endl;
    }

    for (int i = 0; i < dati_x.size(); i++)
    {
        sum_1 = sum_1 + pow(dati_x.at(i), 2);
        sum_2 = sum_2 + dati_y.at(i);
        sum_3 = sum_3 + dati_x.at(i);
        sum_4 = sum_4 + (dati_x.at(i) * dati_y.at(i));
    }
    delta_ = delta_err_uguali(dati_x);
    coeff_a = (1 / delta_) * (sum_1 * sum_2 - sum_3 * sum_4);
    return coeff_a;
}

//Coefficiente b di y=a+bx (coeff. angolare)
double b_angolare_err_uguali(vector<double> dati_x, vector<double> dati_y)
{
    double coeff_b;
    double delta_;
    int size = 0;
    double sum_1 = 0, sum_2 = 0, sum_3 = 0;
    if (dati_y.size() != dati_x.size())
    {
        cout << endl
             << "Dimensione di vettore per dati ascisse è diversa da dimensione vettore dati ordinate" << endl;
    }

    for (int i = 0; i < dati_x.size(); i++)
    {
        sum_1 = sum_1 + dati_x.at(i) * dati_y.at(i);
        sum_2 = sum_2 + dati_x.at(i);
        sum_3 = sum_3 + dati_y.at(i);
    }
    delta_ = delta_err_uguali(dati_x);
    size = dati_x.size();
    coeff_b = (1 / delta_) * (size * sum_1 - sum_2 * sum_3);

    return coeff_b;
}

/*
SIGMA Y A POSTERIORI
*/

//Sigma y a posteriori
double sigma_y_posteriori(vector<double> dati_x, vector<double> dati_y, int inizio = 0, int fine = 0)
{
    double sigma_y;
    double a, b;
    int size = 0;
    double numeratore = 0;
    if (dati_x.size() != dati_y.size())
    {
        cout << "Vettori forniti non della stessa dimensione" << endl;
    }
    a = a_intercetta_err_uguali(dati_x, dati_y);
    b = b_angolare_err_uguali(dati_x, dati_y);
    size = dati_x.size();
    for (int i = 0; i < dati_x.size(); i++)
    {
        numeratore = numeratore + pow((dati_y.at(i) - a - b * dati_x.at(i)), 2);
    }
    sigma_y = sqrt(numeratore / (size - 2));

    return sigma_y;
}

//Errore su coeff. a di y=a+bx con sigma y a posteriori (intercetta)
double sigma_a_posteriori(vector<double> dati_x, vector<double> dati_y)
{
    double sigma_a_;
    double sigma_y;
    double delta_;
    double sum = 0;

    sigma_y = sigma_y_posteriori(dati_x, dati_y);
    delta_ = delta_err_uguali(dati_x);
    for (auto d : dati_x)
    {
        sum = sum + pow(d, 2);
    }
    sigma_a_ = sigma_y * sqrt(sum / delta_);

    return sigma_a_;
}

//Errore su coeff. b con sigma y a posteriori(coeff. angolare)
double sigma_b_posteriori(vector<double> dati_x, vector<double> dati_y)
{
    double sigma_b_p;
    double sigma_y;
    double delta_;
    int size = 0;

    sigma_y = sigma_y_posteriori(dati_x, dati_y);
    size = dati_x.size();
    delta_ = delta_err_uguali(dati_x);
    sigma_b_p = sigma_y * sqrt(size / delta_);

    return sigma_b_p;
}

//ERRORI COEFFICIENTE ANGOLARE E INTERCETTA -> CASO GENERICO

//Errore su coeff. a di y=a+bx con errori tutti diversi (intercetta)
double sigma_a(vector<double> dati_x, vector<double> dati_y, vector<double> errori_y)
{
    double sum = 0;
    for (int i = 0; i < dati_x.size(); i++)
    {
        sum = sum + (pow(dati_x[i], 2) / pow(errori_y[i], 2)); //ho cambiato FABIO
    }
    return sqrt((1 / delta(dati_x, errori_y)) * sum);
}

//Errore su coeff. b di y=a+bx con errori tutti diversi (coeff. ang.)
double sigma_b(vector<double> dati_x, vector<double> dati_y, vector<double> errori_y)
{
    double sum = 0;
    for (int i = 0; i < dati_x.size(); i++)
    {
        sum = sum + (1 / pow(errori_y[i], 2));
    }
    return sqrt((1 / delta(dati_x, errori_y)) * sum);
}

//covarianza fra parametri, errori tutti uguali
double cov_a_b(vector<double> dati_x, vector<double> dati_y, double err_y)
{
    return (-1.0 * media(dati_x) / (dati_x.size()) * pow(err_y, 2) / dev_stand_campione(dati_x));
}

//covarianza compionaria di due set di dati (x*y)-x*y
double cov_campionaria(vector<double> x, vector<double> y)
{
    vector<double> xy;
    for (int i = 0; i < x.size(); i++)
    {
        xy.push_back(x[i] * y[i]);
    }
    return media(xy) - media(x) * media(y);
}

/*
FINE TUTTI I CHI QUADRO POSSIBILI 
*/

//Calcola la rho di Pearson, coefficiente di correlazione lineare
double pearson(vector<double> x, vector<double> y)
{
    double mean_x = media(x);
    double mean_y = media(y);
    double sum_1 = 0;
    double sum_2 = 0;
    double sum_3 = 0;
    for (int i = 0; i < y.size(); i++)
    {
        sum_1 = sum_1 + ((y[i] - mean_y) * (x[i] - mean_x));
        sum_2 = sum_2 + pow((x[i] - mean_x), 2);
        sum_3 = sum_3 + pow((y[i] - mean_y), 2);
    }
    double pearson = sum_1 / (sqrt(sum_2) * sqrt(sum_3));

    return pearson;
}

//Computa variabile di t-Student su rho di Pearson
double student(vector<double> x, vector<double> y)
{
    double pearson_1 = pearson(x, y);
    double t = pearson_1 * sqrt(y.size() - 2) / sqrt(1. - pow(pearson_1, 2));
    return t;
}

//Una cosa che serve per tstudent_campioni
double dstd_cumulativa(vector<double> x, vector<double> y)
{
    double cumulative = ((x.size() - 1) * pow(dstd(x), 2) + (y.size() - 1) * pow(dstd(y), 2)) / (x.size() + y.size() - 2);
    return sqrt(cumulative);
}

//Test di Pearson su due campioni anche di dimensioni diverse per verificare che appartenganpo a stessa distribuzione
double tstudent_campioni(vector<double> x, vector<double> y)
{
    double t = (media(x) - media(y)) / (dstd_cumulativa(x, y) * sqrt(1. / x.size() + 1. / y.size()));
    return t;
}