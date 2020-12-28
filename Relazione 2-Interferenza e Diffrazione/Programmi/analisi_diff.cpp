#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "input.h"
#ifndef DATACLASS
#include "dataclass.h"
#endif
#include "statistica.h"

using namespace std;

int main()
{
    /*
    Legge da file dati grezzi                           ->lettura
    Cerca intervallo per fare fit linare per centro     ->erase_and_take
    Salva su file intervalli per fit centro             ->erase_and_take
    Fit lineare per centro                              ->ROOT
    Calcola il valore del centro                        ->compute center
    Calcola errori asse_y                               ->compute_err_asse_y
    Trova gli indici dei minimi                         ->find_minimum
    Trasla tutto asse_x di x_centro                     ->translate_x
    Stampa su file i valori dei minimi                  ->translate_x
    Calcola range per fit parabolici                    ->compute_range_parabolic_fit
    Stima interpo pararbolica                           ->ROOT
    Legge range parabolici                              ->read_fit_results
    Calcola la posizione del minimo parabolico          ->compute_minima_par
    Calcola il valore del seno dell'angolo, stampa su file 
    Interpolazione lineare seni
    Legge parametri fit
    Restituisce dimensione di a
    */

    int points_to_check = 5; //numero di punti prima e dopo il massimo per ottenere range
    Dataset *diff = new Dataset();
    diff->lettura("../Dati/", "1f_10p_sgnbkg.xls");
    diff->erase_and_take(5, 4, 10, "../File/points_fit.txt");
    diff->compute_center();
    diff->compute_err_asse_y(0.1 / 100.0);
    diff->find_minimum(5);
    diff->translate_x();
    diff->compute_range_parabolic_fit(points_to_check);
    diff->read_fit_results();
    diff->compute_minima_par();
    diff->translate_x_par();
    diff->compute_sin();
    diff->read_m_sin();
    diff->compute_fenditura();

    //cout << "Punto di massimo di grafico diffrazione"
    //     << "\t" << diff->x_center << "\t" << diff->err_x_center << endl;

    //cout << "Errore di posizione traslato" << endl;

    // cout << "Minimi e sin theta in funzione di ordine" << endl;
    //cout << "m\tminimo_alg\terr_minimo_alg\tminimo_par\terr_minimo_par\tsin_theta\terr_sin_theta\tsin_theta_par\terr_sin_theta_par" << endl;
    for (int i = 0; i < diff->sin_theta.size(); i++)
    {
        cout << diff->m[i] << "\t"
             << diff->asse_x_traslato[diff->positions[i]] << "\t" << diff->err_x_traslato[diff->positions[i]] << "\t"
             << diff->minima_par[i] << "\t" << diff->err_minima_par[i] << "\t\t"
             << diff->sin_theta[i] << "\t" << diff->err_sin_theta[i] << "\t"
             << diff->sin_theta_par[i] << "\t" << diff->err_sin_theta_par[i] << endl;
    }
    cout << "COse tabella" << endl;
    for (int i = 0; i < diff->sin_theta.size(); i++)
    {
        cout << diff->asse_x_traslato[diff->positions[i]] << "\t" << diff->err_x_traslato[diff->positions[i]] << "\t" << diff->minima_par_trans[i] << "\t" << diff->err_minima_par_trans[i] << endl;
    }
    vector<double> prima_retta_x;
    vector<double> prima_retta_y;
    for (int i = 0; i < 10; i++)
    {
        prima_retta_x.push_back(diff->asse_x_temp[i]);
        prima_retta_y.push_back(diff->asse_y_temp[i]);
    }

    vector<double> seconda_retta_x;
    vector<double> seconda_retta_y;
    for (int i = 10; i < 20; i++)
    {
        seconda_retta_x.push_back(diff->asse_x_temp[i]);
        seconda_retta_y.push_back(diff->asse_y_temp[i]);
    }

    cout << "Pearson e student fit_for_max" << endl;
    cout << pearson(prima_retta_x, prima_retta_y) << "\t" << student(prima_retta_x, prima_retta_y) << endl;
    cout << pearson(seconda_retta_x, seconda_retta_y) << "\t" << student(seconda_retta_x, seconda_retta_y) << endl;

    diff->compute_comp_par_alg();

    cout << "Err posteriori di m vs. sin(theta)" << endl;
    cout << "Ass " << sigma_y_posteriori(diff->m, diff->sin_theta) << endl;
    cout << "Par " << sigma_y_posteriori(diff->m, diff->sin_theta_par) << endl;
    cout << "Dimensione vettore per gdl " << diff->m.size() << endl;
    cout << "Pearson algebrico:" << pearson(diff->m, diff->sin_theta) << "\t" << student(diff->m, diff->sin_theta) << endl;
    cout << "Pearson parabola:" << pearson(diff->m, diff->sin_theta_par) << "\t" << student(diff->m, diff->sin_theta_par) << endl;

    cout << "Dimensioni a apertura singola fenditura:" << endl
         << "PARABOLICA: " << diff->fenditura_par << "\t" << diff->err_fenditura_par << endl
         << "ASSOLUTA: " << diff->fenditura << "\t" << diff->err_fenditura << endl;
    cout << "Comp apertura " << comp(diff->fenditura_par, diff->fenditura, diff->err_fenditura_par, diff->err_fenditura) << endl;

    cout << "ERRORI SENI" << endl;
    for (int i = 0; i < diff->err_sin_theta.size(); i++)
        cout << diff->err_sin_theta[i] << "\t" << diff->err_sin_theta_par[i] << endl;
    return 0;
}