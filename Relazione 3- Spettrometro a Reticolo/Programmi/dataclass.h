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
#include "../root/root_dataclass.h"
#include "functions.h"

using namespace std;
using json = nlohmann::json;

struct Misure
{
    string description;
    //Ordine di diffraz e interferenza
    vector<double> ordine;

    //Valori del reticolo (metri)
    double d = 3.33e-6;
    double err_d = 0.03e-6 / sqrt(3.0); //conversione in err statistico

    //Errori tacche lettura
    double err_max_nonio = 2; //primi di grado
    double err_nonio_rad = err_max_nonio / sqrt(3) * M_PI / (180.0 * 60.0);

    //Dati grezzi
    vector<double> primo_nonio_angolo_gradi;
    vector<double> primo_nonio_angolo_primi;
    vector<double> secondo_nonio_angolo_gradi;
    vector<double> secondo_nonio_angolo_primi;

    //Prima elaborazione
    vector<double> primo_nonio_radianti;
    vector<double> secondo_nonio_radianti;

    //Senza err eccentricità
    vector<double> media_noni;
    vector<double> err_media_noni;

    //Err eccentricita
    vector<double> err_ecc_1;
    vector<double> err_ecc_2;

    //Traslati
    vector<double> media_t_noni;
    vector<double> err_media_t_noni;

    //Seno tehta
    vector<double> sin_theta;
    vector<double> err_sin_theta;

    //Err ortogonalizzazione
    double err_orto, err_err_orto;

    //Lunghezza d'onda proprie
    vector<double> lambda;
    vector<double> err_lambda;
    double lambda_media;
    double err_lambda_media;

    //Archivio i valori di fit
    fit_results fit;
    fit_results fit_forzato;

    //Lugnhezze donda da fit
    double lambda_fit;
    double err_lambda_fit;
    double lambda_fit_forced;
    double err_lambda_fit_forced;

    //Imposta la descrizione della struct letta
    void set_description(string desc) { description = desc; };

    //Legge i file di dati e crea vettori con misure
    void lettura(string folder, string fname)
    {
        set_description(fname);
        ifstream fin(folder + fname);
        if (!fin)
        {
            cout << "Errore lettura file: " + folder + fname;
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
                vector<double> measures(5);
                iss >> measures[0] >> measures[1] >> measures[2] >> measures[3] >> measures[4];
                ordine.push_back(measures[0]);
                primo_nonio_angolo_gradi.push_back(measures[1]);
                primo_nonio_angolo_primi.push_back(measures[2]);
                secondo_nonio_angolo_gradi.push_back(measures[3]);
                secondo_nonio_angolo_primi.push_back(measures[4]);
            }
        }
    };

    //converte in radaianti tutte le misure prese
    void convert_in_rad()
    {
        if (ordine.size() == 0)
        {
            cout << "Manca lettura" << endl;
        }
        for (int i = 0; i < ordine.size(); i++)
        {
            primo_nonio_radianti.push_back(((primo_nonio_angolo_gradi[i] + (primo_nonio_angolo_primi[i] / 60.0)) * M_PI) / 180.0);
            secondo_nonio_radianti.push_back(((secondo_nonio_angolo_gradi[i] + (secondo_nonio_angolo_primi[i] / 60.0)) * M_PI) / 180.0);
            //Riporta tutto in modo che non ci siano valori di angoli troopo elevati
            if (primo_nonio_radianti[i] > M_PI)
            {
                primo_nonio_radianti[i] = primo_nonio_radianti[i] - 2 * M_PI;
            }
        }
    };

    //angolo vero e proprio
    void media_angoli_noni()
    {
        if (primo_nonio_radianti.size() == 0)
        {
            cout << "Manca convert_in_rad" << endl;
        }
        for (int i = 0; i < primo_nonio_radianti.size(); i++)
        {
            media_noni.push_back((primo_nonio_radianti[i] + secondo_nonio_radianti[i]) / 2.0 - M_PI / 2.0);
            err_media_noni.push_back(err_nonio_rad / sqrt(2)); //propagazione completata
        }
    };

    //valuto differenza fra ordini 1 e posizione centrale
    void err_ortogonalizzazione()
    {
        if (media_noni.size() == 0)
        {
            cout << "Manca media_angoli_noni" << endl;
        }
        err_orto = media({media_noni[3], media_noni[5]}) - media_noni[4];
        err_err_orto = sqrt((3.0 / 2.0) * pow((err_media_noni[0]), 2)); //VINCOLATO AL FATTO CHE ABBIAMO ERRORE UGUALE SU TUTTI-> Cambiare lo [0]
        cout << "Errore ortogonalizzazione (radianti," << description << "): " << err_orto << "+-" << err_err_orto << endl;
    }

    //valuto errore di eccentricità
    void err_eccentricity()
    {
        for (int i = 0; i < media_noni.size(); i++)
        {
            err_ecc_1.push_back(media_noni[i] - primo_nonio_radianti[i]);
            err_ecc_2.push_back(media_noni[i] - secondo_nonio_radianti[i]+M_PI);
        }
    }

    //Riporta tutto a ordine centrale
    void translate_zero()
    {
        for (int i = 0; i < media_noni.size(); i++)
        {
            media_t_noni.push_back(media_noni[i] - media_noni[4]);
            err_media_t_noni.push_back(sqrt(pow(err_media_noni[i], 2) + pow(err_media_noni[4], 2)));
        }
    }

    //Calcola sin_theta
    void compute_sin()
    {
        for (int i = 0; i < media_t_noni.size(); i++)
        {
            sin_theta.push_back(sin(media_t_noni[i]));
            err_sin_theta.push_back(cos(media_t_noni[i]) * err_media_t_noni[i]);
        }
    }

    //Calcola la lunghezza d'onda da campione
    void compute_lambda()
    {
        for (int i = 0; i < ordine.size(); i++)
        {
            if (i != 4)
            {
                lambda.push_back(abs(d * sin(media_t_noni[i]) / ordine[i]));
                err_lambda.push_back(sqrt(
                    pow(sin(media_t_noni[i]) * err_d / ordine[i], 2) +
                    pow(d * cos(media_t_noni[i]) * err_media_t_noni[i] / ordine[i], 2)));
            }
        }
        lambda_media = media_ponderata(lambda, err_lambda);
        err_lambda_media = errore_media_ponderata(err_lambda);
    }

    //legge fit lineare e forzato
    void parse_fit(string directory, string fname, string directory_forzato, string fname_forzato)
    {
        fit.root_from_json(directory, fname);
        fit_forzato.root_from_json(directory_forzato, fname_forzato);
        //butta dentro in struttura Misure i conti per trovare lambda da fit
        lambda_fit = fit.b[0] * d;
        err_lambda_fit = sqrt(pow(fit.err_b[0] * d, 2) +
                              pow(fit.b[0] * err_d, 2));
        lambda_fit_forced = fit_forzato.b[0] * d;
        err_lambda_fit_forced = sqrt(pow(fit_forzato.err_b[0] * d, 2) +
                                     pow(fit_forzato.b[0] * err_d, 2));
    }

    //Salva in file json per interpoalzione ordini
    void to_json(string directory, string fname)
    {
        json j;
        ofstream fout(directory + fname);
        if (!fout)
        {
            cout << "Errore scrittura json" << endl;
        }
        j = json{
            {"description", description},
            {"ordine", ordine},
            {"sin_theta", sin_theta},
            {"err_sin_theta", err_sin_theta}};

        fout << setw(4) << j << endl;
    }
    void from_json(string directory, string fname)
    {
        json j;
        ifstream fin(directory + fname);
        fin >> j;
        j.at("description").get_to(description);
        j.at("ordine").get_to(ordine);
        j.at("sin_theta").get_to(sin_theta);
        j.at("err_sin_theta").get_to(err_sin_theta);
    }
};