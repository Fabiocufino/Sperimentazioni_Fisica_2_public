#include <vector>
#include <cmath>
#ifndef STATISTICA
#include "statistica.h"
#endif

using namespace std;

double err_res_cap(double resistenza, double perc, double digit, double lsd)
{
    double gain = perc / 100. * resistenza * 1. / sqrt(3);
    double read = digit * lsd * 1. / sqrt(3);
    return sqrt(pow(gain, 2) + pow(read, 2));
}

//Agilent
double r_ag = 2.737;                                //kOhm
double err_r_ag = err_res_cap(r_ag, 0.9, 3, 0.001); //kOhm
//Metrix
double r_me = 2.7385;                                 //kOhm
double err_r_me = err_res_cap(r_me, 0.07, 8, 0.0001); //kOhm
//Fluke
double r_fl = 2.738;                                //kOhm
double err_r_fl = err_res_cap(r_fl, 0.9, 1, 0.001); //kOhm

vector<double> resistenze = {r_ag, r_me, r_fl};
vector<double> err_resistenze = {err_r_ag, err_r_me, err_r_fl};

//double media_r = media(resistenze);
//double err_media_r = dstd_media(resistenze);
double media_pond_r = media_ponderata(resistenze, err_resistenze);
double err_media_pond_r = errore_media_ponderata(err_resistenze);

double cap = 9.7;
double err_cap = err_res_cap(cap, 1, 8, 0.001);

//agilent 0.9%+3digit a 6kohm
//metrix  0.07%+8digit 10kohm
//fluke 0.9%+1digit 6kohm