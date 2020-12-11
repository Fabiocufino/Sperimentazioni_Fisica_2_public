#pragma once

#include "containers.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string data_folder = "../Dati";

int read_coniugati(string operatore, Coniugati &coniugato)
{
    ifstream fin(data_folder + "/coniugati" + operatore);
    if (!fin)
    {
        cout << "Errore lettura file: " + data_folder + "/coniugati" + operatore;
        return 1;
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
            vector<double> measures(3);
            iss >> measures[0] >> measures[1] >> measures[2];
            coniugato.add(measures);
        }
    }
    coniugato.name = coniugato.name + operatore; 
    return coniugato.check_consistency();
};

int read_bessel(string operatore, Bessel &bessel, double pos_luce, double pos_schermo)
{
    ifstream fin(data_folder + "/bessel" + operatore);
    if (!fin)
    {
        cout << "Errore lettura file: " + data_folder + "/bessel" + operatore;
        return 1;
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
            vector<double> measures(2);
            iss >> measures[0] >> measures[1];
            bessel.add(measures, pos_luce, pos_schermo);
        }
    }
    bessel.name = bessel.name + operatore; 
    return bessel.check_consistency();
};

int read_cromatica(string operatore, Cromatica &cromatica)
{

    ifstream fin(data_folder + "/cromatica" + operatore);
    if (!fin)
    {
        cout << "Errore lettura file: " + data_folder + "/cromatica" + operatore;
        return 1;
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
            vector<double> measures(2);
            iss >> measures[0] >> measures[1];
            cromatica.add(measures);
        }
    }
    cromatica.name = cromatica.name + operatore;
    return cromatica.check_consistency();
};

int read_sferica(string operatore, Sferica &sferico)
{
    ifstream fin(data_folder + "/sferica" + operatore);
    if (!fin)
    {
        cout << "Errore lettura file: " + data_folder + "/sferico" + operatore;
        return 1;
    }

    //Check whether or not it's a comment, otherwise add to struct
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
            vector<double> measures(3);
            iss >> measures[0] >> measures[1] >> measures[2];
            sferico.add(measures);
        }
    }
    sferico.name = sferico.name + operatore;
    return sferico.check_consistency();
};