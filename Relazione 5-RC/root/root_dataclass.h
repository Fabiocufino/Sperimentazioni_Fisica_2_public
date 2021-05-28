#define ROOTDATACLASS
#include <fstream>
#include <cmath>
#include <vector>
#include <iostream>
#include "../Programmi/json.hpp"
#include "../Programmi/statistica.h"
#include <iomanip>

using namespace std;
using json = nlohmann::json;

class fit_results
{
public:
    vector<double> a;
    vector<double> err_a;
    vector<double> b;
    vector<double> err_b;
    vector<double> c;
    vector<double> err_c;
    vector<double> chi_square;
    vector<double> rho;
    vector<double> t_student;
    vector<double> sigma_post;
    vector<double> dof;

    double covariance_matrix[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    fit_results(){};

    //usando statistica.h calcola Perason Student e Chi Squared
    fit_results(vector<double> &asse_x, vector<double> &asse_y)
    {
        rho.push_back(pearson(asse_x, asse_y));
        t_student.push_back(student(asse_x, asse_y));
        sigma_post.push_back(sigma_y_posteriori(asse_x, asse_y));
    }

    //Utilizzata da root e salva in file json qualsiasi tipo di interpolazione a 3 parametri
    void root_to_json(string directory, string fname)
    {
        json j;
        ofstream fout(directory + "/" + fname);
        if (!fout)
        {
            cout << "Errore scrittura json" << endl;
        }
        j = json{
            {"a", a},
            {"b", b},
            {"c", c},
            {"err_a", err_a},
            {"err_b", err_b},
            {"err_c", err_c},
            {"a-b covariance", covariance_matrix[0][1]},
            {"b-c covariance", covariance_matrix[1][2]},
            {"c-a covariance", covariance_matrix[2][0]},
            {"chi_square", chi_square},
            {"t_student", t_student},
            {"sigma_post", sigma_post},
            {"pearson", rho},
            {"dof", dof}};

        fout << setw(4) << j << endl;
    }

    //Utilizzata da analisi.cxx per leggere i file json creati da root con i parametri del fit
    void root_from_json(string directory, string fname)
    {
        json j;
        ifstream fin(directory + "/" + fname);
        fin >> j;
        j.at("a").get_to(a);
        j.at("b").get_to(b);
        j.at("c").get_to(c);
        j.at("err_a").get_to(err_a);
        j.at("err_b").get_to(err_b);
        j.at("err_c").get_to(err_c);
        j.at("a-b covariance").get_to(covariance_matrix[0][1]);
        j.at("b-c covariance").get_to(covariance_matrix[1][2]);
        j.at("c-a covariance").get_to(covariance_matrix[2][0]);
        j.at("chi_square").get_to(chi_square);
        j.at("t_student").get_to(t_student);
        j.at("sigma_post").get_to(sigma_post);
        j.at("pearson").get_to(rho);
        j.at("dof").get_to(dof);
    }
};