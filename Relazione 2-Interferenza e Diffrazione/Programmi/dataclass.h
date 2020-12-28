#define DATACLASS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include "statistica.h"

using namespace std;

class Dataset
{
public:
    //Dati letti e traslati
    vector<double> asse_x;
    vector<double> asse_x_traslato;
    vector<double> err_x_traslato;
    vector<double> asse_y;
    vector<double> err_asse_y;
    double x_center, err_x_center;

    //Per printare cose
    vector<double> asse_x_temp;
    vector<double> asse_y_temp;

    //Indici dei minimi
    vector<int> positions;

    //Interpolazioni centro
    vector<double> a_int_lin;
    vector<double> err_a_int_lin;
    vector<double> b_ang_lin;
    vector<double> err_b_ang_lin;
    vector<double> cov_a_b_lin;
    vector<double> chi_squared_lin;

    //INterpolazioni paraboliche
    vector<double> range;
    vector<double> a_par;
    vector<double> err_a_par;
    vector<double> b_par;
    vector<double> err_b_par;
    vector<double> c_par;
    vector<double> err_c_par;
    vector<double> cov_b_c;
    vector<double> chi_squared_par;
    vector<double> minima_par;
    vector<double> err_minima_par;
    vector<double> minima_par_trans;
    vector<double> err_minima_par_trans;

    //Angoli
    vector<double> angoli;
    vector<double> err_angoli;
    vector<double> angoli_par;
    vector<double> err_angoli_par;
    vector<double> m = {-7, -6, -5, -4, -3, -2, 2, 3, 4, 5, 6, 7, 8};
    vector<double> sin_theta;
    vector<double> sin_theta_par;
    vector<double> err_sin_theta;
    vector<double> err_sin_theta_par;
    vector<double> l;
    vector<double> l_par;
    vector<double> err_l;
    vector<double> err_l_par;

    //Interpolazione last
    vector<double> a_int_sin;
    vector<double> b_ang_sin;
    vector<double> err_a_int_sin;
    vector<double> err_b_ang_sin;
    vector<double> cov_a_b_sin;
    vector<double> chi_sin;

    //Valori fenditura
    double lambda_laser;
    double err_lambda_laser;
    double fenditura_par;
    double err_fenditura_par;
    double fenditura;
    double err_fenditura;

    string description;
    Dataset(){};
    Dataset(string folder, string fname) { lettura(folder, fname); };
    void set_description(string desc)
    {
        description = description + desc;
    };
    //Carica nella classe i dati grezzi e imposta la descrizione
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
                istringstream iss(temp_line); //spezza la stringa in valori "22 33 44"-> 22 poi 33 poi 44
                vector<double> measures(2);
                iss >> measures[0] >> measures[1];
                asse_x.push_back(measures[0]); //se non metti le referenze qua fa il push_b siolamente nei vettori della funzione
                asse_y.push_back(measures[1]);
            }
        }
    };
    //Stampa asse_x e asse_y non traslato
    void print()
    {
        cout << "Printing: " << description << endl;
        for (int i = 0; i < asse_x.size(); i++)
        {
            cout << asse_x[i] << " " << asse_y[i] << endl;
        }
    };
    void compute_err_asse_y(double err_y)
    {
        for (int i = 0; i < asse_y.size(); i++)
        {
            err_asse_y.push_back(asse_y[i] * err_y);
        }
    }
    //Trova la posizione del valore massimo di un vettore
    int find_maximum(vector<double> &vec)
    {
        return max_element(vec.begin(), vec.end()) - vec.begin();
    };

    //Restituisce in referenza i vettori con x e y dei punti per fit per trovare centro
    void erase_and_take(int del_sx, int del_dx, int take, string fname)
    {
        ofstream fout(fname);
        asse_x_temp = asse_x; //salva una copia di quelli orignali
        asse_y_temp = asse_y; //salva una copia di quelli orignali
        int max_y1;
        int max_y2;
        int max_y;

        for (int i = 0; i < abs(del_sx); i++)
        {
            max_y1 = find_maximum(asse_y_temp);
            asse_y_temp.erase(asse_y_temp.begin() + (max_y1 - 1));
            asse_x_temp.erase(asse_x_temp.begin() + (max_y1 - 1));
        }

        for (int i = 0; i < abs(del_dx) - 1; i++) //occhio al meno 1
        {
            max_y2 = find_maximum(asse_y_temp);
            asse_y_temp.erase(asse_y_temp.begin() + (max_y2 + 1));
            asse_x_temp.erase(asse_x_temp.begin() + (max_y2 + 1));
        }

        max_y = find_maximum(asse_y_temp);
        asse_y_temp.erase(asse_y_temp.begin(), asse_y_temp.begin() + max_y - take);
        asse_x_temp.erase(asse_x_temp.begin(), asse_x_temp.begin() + max_y - take);

        max_y = find_maximum(asse_y_temp);
        asse_y_temp.erase(asse_y_temp.begin() + max_y + take + 1, asse_y_temp.begin() + asse_y_temp.size());
        asse_x_temp.erase(asse_x_temp.begin() + max_y + take + 1, asse_x_temp.begin() + asse_x_temp.size());

        asse_y_temp.erase(asse_y_temp.begin() + max_y);
        asse_x_temp.erase(asse_x_temp.begin() + max_y);

        for (int i = 0; i < asse_x_temp.size(); i++)
        {
            fout << asse_x_temp[i] << "\t" << asse_y_temp[i] << "\t 0 \t" << asse_y_temp[i] * 0.001 << endl;
        }
    };

    //Calcola il valore del centro dopo aver letto i risultati del fit da file
    void compute_center()
    {
        ifstream lettura_fit("../Fit_results/results_fit_for_max.txt");
        if (!lettura_fit)
        {
            cout << "Errore lettura file results_fit_for_max.txt";
        }

        string temp_line;
        while (getline(lettura_fit, temp_line))
        {
            if (temp_line.rfind("#", 0) == 0 || temp_line.size() < 5)
            {
                continue;
            }
            else
            {
                istringstream iss(temp_line); //spezza la stringa in valori "22 33 44"-> 22 poi 33 poi 44
                vector<double> measures(6);
                iss >> measures[0] >> measures[1] >> measures[2] >> measures[3] >> measures[4] >> measures[5];
                b_ang_lin.push_back(measures[0]);
                err_b_ang_lin.push_back(measures[1]);
                a_int_lin.push_back(measures[2]);
                err_a_int_lin.push_back(measures[3]);
                chi_squared_lin.push_back(measures[4]);
                cov_a_b_lin.push_back(measures[5]); /*CORREGGERE INSERENDO LA POSIZIONE OPPORTUNA DELLA COVARIANZA*/
            }
        }
        x_center = ((a_int_lin[0] - a_int_lin[1]) / (b_ang_lin[1] - b_ang_lin[0]));
        err_x_center = sqrt(
            pow((err_a_int_lin[1] / (b_ang_lin[0] - b_ang_lin[1])), 2) +
            pow((err_a_int_lin[0] / (b_ang_lin[0] - b_ang_lin[1])), 2) +
            pow(((a_int_lin[1] - a_int_lin[0]) * err_b_ang_lin[0] / pow((b_ang_lin[0] - b_ang_lin[1]), 2)), 2) +
            pow(((a_int_lin[1] - a_int_lin[0]) * err_b_ang_lin[1] / pow((b_ang_lin[0] - b_ang_lin[1]), 2)), 2) +
            2.0 * ((a_int_lin[1] - a_int_lin[0]) / (pow((b_ang_lin[0] - b_ang_lin[1]), 3))) * cov_a_b_lin[0] +
            2.0 * ((a_int_lin[1] - a_int_lin[0]) / (pow((b_ang_lin[0] - b_ang_lin[1]), 3))) * cov_a_b_lin[1]);
    }

    //Archivia nel vettore positions l'indice dei valori minimi, indipendente da traslazione
    void find_minimum(int n)
    {
        //controlla tutti i punti
        for (int i = n; i < asse_y.size() - n; i++)
        {
            //controllo del minimo: se è minimo è il minore dei valori nel range
            bool verifica = true;
            for (int j = -1 * n; j < n; j++)
            {
                if (asse_y[i] > asse_y[i + j])
                {
                    verifica = false; //invalida ipotesi di minimo
                }
            }
            if (verifica)
            {
                if (positions.size() != 0)
                {
                    //controllo se ultima posizione minimo registrato non corrisponda a nuovo valore minimo (possono verificarsi casi di uguaglianza)
                    if (asse_y[i] != asse_y[positions[positions.size() - 1]])
                    {
                        positions.push_back(i);
                    }
                }
                else
                {
                    positions.push_back(i);
                }
            }
            //if(asse_y[i]<asse_y[i+1] && asse_y[i]<asse_y[i+2] && asse_y[i]<asse_y[i+3]&& asse_y[i]<asse_y[i-1] && asse_y[i]<asse_y[i-2] && asse_y[i]<asse_y[i-3])
        }
    }

    //Trasla asse_x con x_centro in asse_x_traslato
    void translate_x()
    {
        string path = "../File/minimum_points.txt";
        for (int i = 0; i < asse_x.size(); i++)
        {
            asse_x_traslato.push_back(asse_x[i] - x_center);
            err_x_traslato.push_back(sqrt(pow(10 / sqrt(12), 2) + pow(err_x_center, 2)));
        }
        ofstream fminimum(path);
        for (int i = 0; i < positions.size(); i++)
        {
            fminimum << asse_x_traslato[positions[i]] << "\t" << asse_y[positions[i]] << endl;
        }
    };

    //Restituisce in range i valori x per fare i range parabolici
    void compute_range_parabolic_fit(int n_selected_point)
    {
        //Questa funzione ha bisogno di find_minimum(5); translate_x();
        for (int i = 0; i < positions.size(); i++)
        {
            range.push_back(asse_x_traslato[positions[i] - n_selected_point]);
            range.push_back(asse_x_traslato[positions[i] + n_selected_point]);
        }
    }

    //Archivia valori fit parabolici
    void read_fit_results()
    {
        for (int i = 0; i < 13; i++)
        {
            ifstream lettura_fit("../Fit_results/results_parabolic_fit_" + to_string(i) + ".txt");
            if (!lettura_fit)
            {
                cout << "Errore lettura file results_parabolic_fit_" + to_string(i) + ".txt";
            }

            string temp_line;
            while (getline(lettura_fit, temp_line))
            {
                if (temp_line.rfind("#", 0) == 0 || temp_line.size() < 5)
                {
                    continue;
                }
                else
                {
                    istringstream iss(temp_line);
                    vector<double> measures(10);
                    iss >> measures[0] >> measures[1] >> measures[2] >> measures[3] >> measures[4] >> measures[5] >> measures[6] >> measures[7] >> measures[8] >> measures[9];
                    a_par.push_back(measures[0]);
                    err_a_par.push_back(measures[1]);
                    b_par.push_back(measures[2]);
                    err_b_par.push_back(measures[3]);
                    c_par.push_back(measures[4]);
                    err_c_par.push_back(measures[5]);
                    chi_squared_par.push_back(measures[6]);
                    cov_b_c.push_back(measures[9]);
                }
            }
        }
    }

    //Calcola i valori x dei minimi delle parabole
    void compute_minima_par()
    {
        for (int i = 0; i < a_par.size(); i++)
        {
            minima_par.push_back(-b_par[i] / (2.0 * c_par[i]));
            err_minima_par.push_back(sqrt(
                pow((err_b_par[i] / (2.0 * c_par[i])), 2) +
                pow((b_par[i] * err_c_par[i]) / (2.0 * pow(c_par[i], 2)), 2) +
                2.0 * (-1.0 / (2.0 * c_par[i])) * (b_par[i] / (2.0 * pow(c_par[i], 2))) * cov_b_c[i]));
        }
    };
    void translate_x_par()
    {
        for (int i = 0; i < a_par.size(); i++)
        {
            minima_par_trans.push_back(minima_par[i] - x_center);
            err_minima_par_trans.push_back(sqrt(pow(err_minima_par[i], 2) + pow(err_x_center, 2)));
        }
    }

    //Calcola i seni degli angoli corrispondenti ai minimo
    void compute_sin()
    {
        double dist_perno_vite = 65.5e-3;
        double err_dist_perno_vite = 0.5e-3 / sqrt(3.0); //2x/sqrt(12) da errore massimo a errore statistico
        double avanzamento_per_passo = 1.25e-6;
        double err_avanzamento_per_passo = 5e-6 / (sqrt(3.0) * 400.0); //propagazione e err statistico

        for (int i = 0; i < minima_par_trans.size(); i++)
        {
            l_par.push_back(avanzamento_per_passo * minima_par_trans[i]);
            err_l_par.push_back(sqrt(
                pow(minima_par_trans[i] * err_avanzamento_per_passo, 2) +
                pow(avanzamento_per_passo * err_minima_par_trans[i], 2)));
            l.push_back(avanzamento_per_passo * asse_x_traslato[positions[i]]);
            err_l.push_back(sqrt(
                pow(asse_x_traslato[positions[i]] * err_avanzamento_per_passo, 2) +
                pow(avanzamento_per_passo * err_x_traslato[i], 2)));

            sin_theta_par.push_back(l_par[i] / sqrt(pow(l_par[i], 2) + pow(dist_perno_vite, 2)));
            err_sin_theta_par.push_back(sqrt(
                pow((pow(dist_perno_vite, 2)) / pow(pow(l_par[i], 2) + pow(dist_perno_vite, 2), 1.5), 2) * pow(err_l_par[i], 2) +
                pow(-dist_perno_vite * l_par[i] / (pow(pow(l_par[i], 2) + pow(dist_perno_vite, 2), 1.5)), 2) * pow(err_dist_perno_vite, 2)));
            sin_theta.push_back(l[i] / sqrt(pow(l[i], 2) + pow(dist_perno_vite, 2)));
            err_sin_theta.push_back(sqrt(
                pow((pow(dist_perno_vite, 2)) / pow(pow(l[i], 2) + pow(dist_perno_vite, 2), 1.5), 2) * pow(err_l[i], 2) +
                pow(-dist_perno_vite * l[i] * err_dist_perno_vite / pow((pow(l[i], 2) + pow(dist_perno_vite, 2)), 1.5), 2)));
        }
    };

    //Legge i parametri di interpolazione di root per grafico m vs. sin(theta)
    void read_m_sin()
    {
        ifstream lettura_fit("../Fit_results/results_fit_m_sin.txt");
        if (!lettura_fit)
        {
            cout << "Errore lettura file m sin";
        }

        string temp_line;
        while (getline(lettura_fit, temp_line))
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
                b_ang_sin.push_back(measures[0]);
                err_b_ang_sin.push_back(measures[1]);
                a_int_sin.push_back(measures[2]);
                err_a_int_sin.push_back(measures[3]);
                chi_sin.push_back(measures[4]);
                cov_a_b_sin.push_back(measures[5]);
            }
        }
    };
    void compute_comp_par_alg()
    {
        cout << "Calcolo di compatibilità coeff ang e intercetta fra algebrico e parab fit m vs. sin theta" << endl;
        cout << comp(b_ang_sin[0], b_ang_sin[1], err_b_ang_sin[0], err_b_ang_sin[1]) << endl;
        cout << comp(a_int_sin[0], a_int_sin[1], err_a_int_sin[0], err_a_int_sin[1]) << endl;
    }

    void compute_fenditura()
    {
        lambda_laser = 670e-9;
        err_lambda_laser = 5e-9;
        fenditura_par = lambda_laser / b_ang_sin[0];
        err_fenditura_par = sqrt(
            pow(err_lambda_laser / b_ang_sin[0], 2) +
            pow(lambda_laser * err_b_ang_sin[0] / pow(b_ang_sin[0], 2), 2));
        fenditura = lambda_laser / b_ang_sin[1];
        err_fenditura = sqrt(
            pow(err_lambda_laser / b_ang_sin[1], 2) +
            pow(lambda_laser * err_b_ang_sin[1] / pow(b_ang_sin[1], 2), 2));
    };
};

class Dataset2
{
public:
    //Vettori lettura
    string description;
    vector<double> asse_x;
    vector<double> asse_y;
    vector<double> err_asse_y;

    //Indici dei minimi
    vector<double> positions;

    //Massimo centrale
    double a_par_max;
    double err_a_par_max;
    double b_par_max;
    double err_b_par_max;
    double c_par_max;
    double err_c_par_max;
    double chi_squared_par_max;
    double cov_b_c_max;
    vector<double> a_par;
    vector<double> err_a_par;
    vector<double> b_par;
    vector<double> err_b_par;
    vector<double> c_par;
    vector<double> err_c_par;
    vector<double> cov_b_c;
    vector<double> chi_squared_par;

    //Calcolo del centro
    double x_center;
    double err_x_center;
    vector<double> range;

    //Riempie vettore posizione dei massimi principali
    vector<double> maxima_par;
    vector<double> err_maxima_par;
    vector<double> maxima_par_trans;
    vector<double> err_maxima_par_trans;

    //Traslazione
    vector<double> asse_x_traslato;
    vector<double> err_x_traslato;

    //Sin
    vector<double> n;
    vector<double> sin_theta;
    vector<double> sin_theta_par;
    vector<double> err_sin_theta;
    vector<double> err_sin_theta_par;
    vector<double> l;
    vector<double> l_par;
    vector<double> err_l;
    vector<double> err_l_par;

    //Legge interpolazione di n vs sin e archivia per algebrico e parabolico
    vector<double> b_ang_sin;
    vector<double> err_b_ang_sin;
    vector<double> a_int_sin;
    vector<double> err_a_int_sin;
    vector<double> chi_sin;
    vector<double> cov_a_b_sin;

    //Valori finali estrapolati da fit n vs sin
    double lambda_laser;
    double err_lambda_laser;
    double dist_fenditura_par;
    double err_dist_fenditura_par;
    double dist_fenditura;
    double err_dist_fenditura;

    void set_description(string desc)
    {
        description = description + desc;
    };
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
                istringstream iss(temp_line); //spezza la stringa in valori "22 33 44"-> 22 poi 33 poi 44
                vector<double> measures(2);
                iss >> measures[0] >> measures[1];
                asse_x.push_back(measures[0]); //se non metti le referenze qua fa il push_b siolamente nei vettori della funzione
                asse_y.push_back(measures[1]);
            }
        }
    };

    void compute_err_asse_y(double err_y)
    {
        for (int i = 0; i < asse_y.size(); i++)
        {
            err_asse_y.push_back(asse_y[i] * err_y);
        }
    }

    //Legge parametri fit parabolico per centrale
    void read_fit_maximum(int i)
    {
        ifstream lettura_fit("../Fit_results/results_find_max_" + to_string(i) + ".txt");
        if (!lettura_fit)
        {
            cout << "Errore lettura file masismo centrale interferenza" + to_string(i) + ".txt";
        }

        string temp_line;
        while (getline(lettura_fit, temp_line))
        {
            if (temp_line.rfind("#", 0) == 0 || temp_line.size() < 5)
            {
                continue;
            }
            else
            {
                istringstream iss(temp_line);
                vector<double> measures(8);
                iss >> measures[0] >> measures[1] >> measures[2] >> measures[3] >> measures[4] >> measures[5] >> measures[6] >> measures[7];
                a_par_max = measures[0];
                err_a_par_max = measures[1];
                b_par_max = measures[2];
                err_b_par_max = measures[3];
                c_par_max = measures[4];
                err_c_par_max = measures[5];
                chi_squared_par_max = measures[6];
                cov_b_c_max = measures[7];
            }
        }
    }
    //Calcola il centro del grafico per poi allinearlo correttamente
    void compute_center()
    {
        x_center = -b_par_max / (2.0 * c_par_max);
        err_x_center = sqrt(
            pow((err_b_par_max / (2.0 * c_par_max)), 2) +
            pow((b_par_max * err_c_par_max) / (2.0 * pow(c_par_max, 2)), 2) +
            2.0 * (-1.0 / (2.0 * c_par_max)) * (b_par_max / (2.0 * pow(c_par_max, 2))) * cov_b_c_max);
    }

    //Trova gli indici dei massimi assoluti
    void find_maxima(int n) //per rendere più selettivo, usare 10 ad argomento
    {
        //controlla tutti i punti
        for (int i = n; i < asse_y.size() - n; i++)
        {
            //controllo del minimo: se è minimo è il minore dei valori nel range
            bool verifica = true;
            for (int j = -1 * n; j < n; j++)
            {
                if (asse_y[i] < asse_y[i + j])
                {
                    verifica = false; //invalida ipotesi di minimo
                }
            }
            if (verifica)
            {
                if (positions.size() != 0)
                {
                    //controllo se ultima posizione minimo registrato non corrisponda a nuovo valore minimo (possono verificarsi casi di uguaglianza)
                    if (asse_y[i] != asse_y[positions[positions.size() - 1]])
                    {
                        positions.push_back(i);
                    }
                }
                else
                {
                    positions.push_back(i);
                }
            }
            //if(asse_y[i]<asse_y[i+1] && asse_y[i]<asse_y[i+2] && asse_y[i]<asse_y[i+3]&& asse_y[i]<asse_y[i-1] && asse_y[i]<asse_y[i-2] && asse_y[i]<asse_y[i-3])
        }
    }

    //Trasla l'asse delle x della quantittà trovata precedentemente per il centro
    void translate_x()
    {
        string path = "../File/maxima_points.txt";
        for (int i = 0; i < asse_x.size(); i++)
        {
            asse_x_traslato.push_back(asse_x[i] - x_center);
            err_x_traslato.push_back(sqrt(pow(3 / sqrt(12), 2) + pow(err_x_center, 2)));
        }
        ofstream fminimum(path);
        for (int i = 0; i < positions.size(); i++)
        {
            fminimum << asse_x_traslato[positions[i]] << "\t" << asse_y[positions[i]] << endl;
        }
    };

    //Restituisce in range i valori x per fare i range parabolici
    void compute_range_parabolic_fit(int n_selected_point)
    {
        for (int i = 0; i < positions.size(); i++)
        {
            range.push_back(asse_x_traslato[positions[i] - n_selected_point]);
            range.push_back(asse_x_traslato[positions[i] + n_selected_point]);
        }
    }

    void read_fit_results(int i) //specifico il numero di file da controllare
    {
        ifstream lettura_fit("../Fit_results/results_parabolic_fit_int_" + to_string(i) + ".txt");
        if (!lettura_fit)
        {
            cout << "Errore lettura file results_parabolic_fit_int_" + to_string(i) + ".txt";
        }

        string temp_line;
        while (getline(lettura_fit, temp_line))
        {
            if (temp_line.rfind("#", 0) == 0 || temp_line.size() < 5)
            {
                continue;
            }
            else
            {
                istringstream iss(temp_line);
                vector<double> measures(10);
                iss >> measures[0] >> measures[1] >> measures[2] >> measures[3] >> measures[4] >> measures[5] >> measures[6] >> measures[7] >> measures[8] >> measures[9];
                a_par.push_back(measures[0]);
                err_a_par.push_back(measures[1]);
                b_par.push_back(measures[2]);
                err_b_par.push_back(measures[3]);
                c_par.push_back(measures[4]);
                err_c_par.push_back(measures[5]);
                chi_squared_par.push_back(measures[6]);
                cov_b_c.push_back(measures[9]);
            }
        }
    };

    void compute_maxima_par()
    {
        for (int i = 0; i < a_par.size(); i++)
        {
            maxima_par.push_back(-b_par[i] / (2.0 * c_par[i]));
            err_maxima_par.push_back(sqrt(
                pow((err_b_par[i] / (2.0 * c_par[i])), 2) +
                pow((b_par[i] * err_c_par[i]) / (2.0 * pow(c_par[i], 2)), 2) +
                2.0 * (-1.0 / (2.0 * c_par[i])) * (b_par[i] / (2.0 * pow(c_par[i], 2))) * cov_b_c[i]));
        }
    };

    void translate_x_par()
    {
        for (int i = 0; i < a_par.size(); i++)
        {
            maxima_par_trans.push_back(maxima_par[i] - x_center);
            err_maxima_par_trans.push_back(sqrt(pow(err_maxima_par[i], 2) + pow(err_x_center, 2)));
        }
    };

    //Calcola i seni degli angoli corrispondenti ai minimo
    void compute_sin()
    {
        double dist_perno_vite = 65.5e-3;
        double err_dist_perno_vite = 0.5e-3 / sqrt(3.0); //2x/sqrt(12) da errore massimo a errore statistico
        double avanzamento_per_passo = 1.25e-6;
        double err_avanzamento_per_passo = 5e-6 / (sqrt(3.0) * 400.0); //propagazione e err statistico

        for (int i = 0; i < maxima_par_trans.size(); i++)
        {
            l_par.push_back(avanzamento_per_passo * maxima_par_trans[i]);
            err_l_par.push_back(sqrt(
                pow(maxima_par_trans[i] * err_avanzamento_per_passo, 2) +
                pow(avanzamento_per_passo * err_maxima_par_trans[i], 2)));
            l.push_back(avanzamento_per_passo * asse_x_traslato[positions[i]]);
            err_l.push_back(sqrt(
                pow(asse_x_traslato[positions[i]] * err_avanzamento_per_passo, 2) +
                pow(avanzamento_per_passo * err_x_traslato[i], 2)));

            sin_theta_par.push_back(l_par[i] / sqrt(pow(l_par[i], 2) + pow(dist_perno_vite, 2)));
            err_sin_theta_par.push_back(sqrt(
                pow((pow(dist_perno_vite, 2)) / pow(pow(l_par[i], 2) + pow(dist_perno_vite, 2), 1.5), 2) * pow(err_l_par[i], 2) +
                pow(-dist_perno_vite * l_par[i] / (pow(pow(l_par[i], 2) + pow(dist_perno_vite, 2), 1.5)), 2) * pow(err_dist_perno_vite, 2)));
            sin_theta.push_back(l[i] / sqrt(pow(l[i], 2) + pow(dist_perno_vite, 2)));
            err_sin_theta.push_back(sqrt(
                pow((pow(dist_perno_vite, 2)) / pow(pow(l[i], 2) + pow(dist_perno_vite, 2), 1.5), 2) * pow(err_l[i], 2) +
                pow(-dist_perno_vite * l[i] * err_dist_perno_vite / pow((pow(l[i], 2) + pow(dist_perno_vite, 2)), 1.5), 2)));
        }
    };

    void read_n_sin(int i)
    {
        ifstream lettura_fit("../Fit_results/results_fit_m_sin_" + to_string(i) + ".txt");
        if (!lettura_fit)
        {
            cout << "Errore lettura file m sin";
        }

        string temp_line;
        while (getline(lettura_fit, temp_line))
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
                b_ang_sin.push_back(measures[0]); //0esimo è _par
                err_b_ang_sin.push_back(measures[1]);
                a_int_sin.push_back(measures[2]);
                err_a_int_sin.push_back(measures[3]);
                chi_sin.push_back(measures[4]);
                cov_a_b_sin.push_back(measures[5]);
            }
        }
    };
    void compute_comp_par_alg()
    {
        cout << "Calcolo di compatibilità coeff ang e intercetta fra algebrico e parab fit n vs. sin theta" << endl;
        cout << comp(b_ang_sin[0], b_ang_sin[1], err_b_ang_sin[0], err_b_ang_sin[1]) << endl;
        cout << comp(a_int_sin[0], a_int_sin[1], err_a_int_sin[0], err_a_int_sin[1]) << endl;
    }
    void compute_dist_fenditure()
    {
        lambda_laser = 670e-9;
        err_lambda_laser = 5e-9;
        dist_fenditura_par = lambda_laser / b_ang_sin[0];
        err_dist_fenditura_par = sqrt(
            pow(err_lambda_laser / b_ang_sin[0], 2) +
            pow(lambda_laser * err_b_ang_sin[0] / pow(b_ang_sin[0], 2), 2));
        dist_fenditura = lambda_laser / b_ang_sin[1];
        err_dist_fenditura = sqrt(
            pow(err_lambda_laser / b_ang_sin[1], 2) +
            pow(lambda_laser * err_b_ang_sin[1] / pow(b_ang_sin[1], 2), 2));
    };
};
