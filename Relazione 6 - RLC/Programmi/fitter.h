#define DATACLASS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
//#include "TMath.h"
#include <string.h>
#include <iomanip>
#include "statistica.h"
#include "json.hpp"
#ifndef ROOTDATACLASS
#include "../root/root_dataclass.h"
#endif

double smorzamento(double omega, double delta, double a, double t)
{
    double v = a * exp(-1. * delta * t) * (delta * sin(t * sqrt(pow(omega, 2) - pow(delta, 2))) + sqrt(pow(omega, 2) - pow(delta, 2)) * cos(t * sqrt(pow(omega, 2) - pow(delta, 2)))) / sqrt(pow(omega, 2) - pow(delta, 2)); //funzione
    return v;
}

double chi_quadro(double omega, double delta, double a, vector<double> t, vector<double> v, vector<double> err_v, double (*function)(double, double, double, double))
{
    double sum_chi;
    for (int i = 0; i < t.size(); i++)
    {
        sum_chi += pow((function(omega, delta, a, t[i]) - v[i]) / err_v[i], 2);
    }
    return sum_chi;
}

void compute_chi(double omega_start, double omega_step, double omega_points, double delta_start, double delta_step, double delta_points, double a, vector<double> x, vector<double> y, vector<double> err_y, double (*function)(double, double, double, double), string dir, string fname)
{
    vector<double> plane_omega, plane_delta;
    vector<double> chi;
    ofstream fout(dir + "/" + fname);
    double omega_end = omega_start + omega_step * omega_points;
    for (int i = 0; i < omega_points; i++) //omega
    {
        double omega_i = omega_start + omega_step * i;
        for (int j = 0; j < delta_points; j++) //delta
        {
            double delta_i = delta_start + delta_step * j;
            chi.push_back(chi_quadro(omega_i, delta_i, a, x, y, err_y, function));
            plane_omega.push_back(omega_i);
            plane_delta.push_back(delta_i);
            fout << omega_i <<"\t"<< delta_i <<"\t"<< chi_quadro(omega_i, delta_i, a, x, y, err_y, function) << endl;
            cout << "Computing" << omega_i << "\t" << delta_i << endl;
        }
    }
}
