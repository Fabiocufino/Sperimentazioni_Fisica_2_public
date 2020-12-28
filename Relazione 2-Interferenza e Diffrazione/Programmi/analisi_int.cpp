#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "dataclass.h"

using namespace std;

int main()
{
    Dataset2 *int_2 = new Dataset2();
    Dataset2 *int_3 = new Dataset2();
    Dataset2 *int_4 = new Dataset2();

    //Legge i file
    int_2->lettura("../Dati", "/2f_3p_sgn.xls");
    int_3->lettura("../Dati", "/3f_3p_sgn.xls");
    int_4->lettura("../Dati", "/4f_3p_sgn.xls");

    int_2->compute_err_asse_y(0.1 / 100.0);
    int_3->compute_err_asse_y(0.1 / 100.0);
    int_4->compute_err_asse_y(0.1 / 100.0);

    //Legge interpolazione root in preparazione per x_centro
    int_2->read_fit_maximum(2);
    int_3->read_fit_maximum(3);
    int_4->read_fit_maximum(4);

    //Calcola x_center ed errore
    int_2->compute_center();
    int_3->compute_center();
    int_4->compute_center();

    cout << "x_center\t" << int_2->x_center << "\t" << int_3->x_center << "\t" << int_4->x_center << endl;
    cout << "x_center\t" << int_2->err_x_center << "\t" << int_3->err_x_center << "\t" << int_4->err_x_center << endl;

    //Trova i massimi
    int_2->find_maxima(8);
    int_3->find_maxima(15);
    int_4->find_maxima(15);

    int_3->positions.erase(int_3->positions.begin());
    int_4->positions.pop_back();

    //Trasla asse x di x_centro
    int_2->translate_x();
    int_3->translate_x();
    int_4->translate_x();

    //Interpreta i fit parabolici delle parabole di root dei massimi
    int_2->read_fit_results(2);
    int_3->read_fit_results(3);
    int_4->read_fit_results(4);

    //Trova il massimo dalle parabole
    int_2->compute_maxima_par();
    int_3->compute_maxima_par();
    int_4->compute_maxima_par();

    //Trasla i massimi delle parabole
    int_2->translate_x_par();
    int_3->translate_x_par();
    int_4->translate_x_par();

    //Rimuove il dato in posizione n-esima
    int_3->maxima_par_trans.erase(int_3->maxima_par_trans.begin());
    int_3->err_maxima_par_trans.erase(int_3->err_maxima_par_trans.begin());
    int_4->maxima_par_trans.pop_back();
    int_4->err_maxima_par_trans.pop_back();

    //Calcola il seno
    int_2->compute_sin();
    int_3->compute_sin();
    int_4->compute_sin();

    int_2->n = {-16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int_3->n = {-16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int_4->n = {-16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    //Legge parametri fit
    int_2->read_n_sin(2);
    int_3->read_n_sin(3);
    int_4->read_n_sin(4);

    //Cmlcola distanza fenditure
    int_2->compute_dist_fenditure();
    int_3->compute_dist_fenditure();
    int_4->compute_dist_fenditure();

    cout << int_2->dist_fenditura_par << "\t" << int_2->err_dist_fenditura_par << "\t" << int_2->dist_fenditura << "\t" << int_2->err_dist_fenditura << endl;
    cout << int_3->dist_fenditura_par << "\t" << int_3->err_dist_fenditura_par << "\t" << int_3->dist_fenditura << "\t" << int_3->err_dist_fenditura << endl;
    cout << int_4->dist_fenditura_par << "\t" << int_4->err_dist_fenditura_par << "\t" << int_4->dist_fenditura << "\t" << int_4->err_dist_fenditura << endl;

    cout << "Test sui fit n,sin" << endl;
    cout << pearson(int_2->n, int_2->sin_theta_par) << "\t" << student(int_2->n, int_2->sin_theta_par) << endl;
    cout << pearson(int_3->n, int_3->sin_theta_par) << "\t" << student(int_3->n, int_3->sin_theta_par) << endl;
    cout << pearson(int_4->n, int_4->sin_theta_par) << "\t" << student(int_4->n, int_4->sin_theta_par) << endl;
    cout << "ALGEBRICI" << endl;
    cout << pearson(int_2->n, int_2->sin_theta) << "\t" << student(int_2->n, int_2->sin_theta) << endl;
    cout << pearson(int_3->n, int_3->sin_theta) << "\t\t" << student(int_3->n, int_3->sin_theta) << endl;
    cout << pearson(int_4->n, int_4->sin_theta) << "\t" << student(int_4->n, int_4->sin_theta) << endl;

    for (int i = 0; i < int_4->maxima_par_trans.size(); i++)
    {
        cout << int_4->asse_x_traslato[int_4->positions[i]] << "\t" << int_4->err_x_traslato[int_4->positions[i]]
             << "\t" << int_4->maxima_par_trans[i] << "\t" << int_4->err_maxima_par_trans[i] << endl;
    }
     /*
    int_2->compute_comp_par_alg();
    int_3->compute_comp_par_alg();
    int_4->compute_comp_par_alg();
     
    cout << "Dimensioni d dist fenditura: 2 FENDITURE" << endl
         << "PARABOLICA: " << int_2->dist_fenditura << "\t" << int_2->err_dist_fenditura << endl
         << "ASSOLUTA: " << int_2->dist_fenditura_par << "\t" << int_2->err_dist_fenditura_par << endl;
    cout << "Comp apertura " << comp(int_2->dist_fenditura, int_2->dist_fenditura_par, int_2->err_dist_fenditura, int_2->err_dist_fenditura_par) << endl
         << endl;

    cout << "Dimensioni d dist fenditura: 3 FENDITURE" << endl
         << "PARABOLICA: " << int_3->dist_fenditura << "\t" << int_3->err_dist_fenditura << endl
         << "ASSOLUTA: " << int_3->dist_fenditura_par << "\t" << int_3->err_dist_fenditura_par << endl;
    cout << "Comp apertura " << comp(int_3->dist_fenditura, int_3->dist_fenditura_par, int_3->err_dist_fenditura, int_3->err_dist_fenditura_par) << endl
         << endl;

    cout << "Dimensioni d dist fenditura: 4 FENDITURE" << endl
         << "PARABOLICA: " << int_4->dist_fenditura << "\t" << int_4->err_dist_fenditura << endl
         << "ASSOLUTA: " << int_4->dist_fenditura_par << "\t" << int_4->err_dist_fenditura_par << endl;
    cout << "Comp apertura " << comp(int_4->dist_fenditura, int_4->dist_fenditura_par, int_4->err_dist_fenditura, int_4->err_dist_fenditura_par) << endl;

    cout << "Compatibilità dist paraboliche" << endl
         << "2-3: " << comp(int_2->dist_fenditura_par, int_3->dist_fenditura_par, int_2->err_dist_fenditura_par, int_3->err_dist_fenditura_par) << endl
         << "2-4: " << comp(int_2->dist_fenditura_par, int_4->dist_fenditura_par, int_2->err_dist_fenditura_par, int_4->err_dist_fenditura_par) << endl
         << "3-4: " << comp(int_4->dist_fenditura_par, int_3->dist_fenditura_par, int_4->err_dist_fenditura_par, int_3->err_dist_fenditura_par) << endl;

    cout << "Compatibilità dist alg" << endl
         << "2-3: " << comp(int_2->dist_fenditura, int_3->dist_fenditura, int_2->err_dist_fenditura, int_3->err_dist_fenditura) << endl
         << "2-4: " << comp(int_2->dist_fenditura, int_4->dist_fenditura, int_2->err_dist_fenditura, int_4->err_dist_fenditura) << endl
         << "3-4: " << comp(int_4->dist_fenditura, int_3->dist_fenditura, int_4->err_dist_fenditura, int_3->err_dist_fenditura) << endl;
    cout << "Pondereata 3 4 fenditure:"
         << media_ponderata({int_3->dist_fenditura_par, int_4->dist_fenditura_par}, {int_3->err_dist_fenditura_par, int_4->err_dist_fenditura_par})
         << "+-" << errore_media_ponderata({int_3->err_dist_fenditura_par, int_4->err_dist_fenditura_par}) << endl;
    */
    return 0;
}
