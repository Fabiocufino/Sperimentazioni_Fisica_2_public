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
#include "dataclass.h"
#include "json.hpp"
//#include "resistenza.h"

using namespace std;
using json = nlohmann::json;

int main()
{
     ///Calcolo delle resistenze e loro media ponderata
     cout << "Agilent: " << r_ag << " +/- " << err_r_ag << endl;
     cout << "Metrix: " << r_me << " +/- " << err_r_me << endl;
     cout << "Fluke: " << r_fl << " +/- " << err_r_fl << endl;
     cout << "Media Ponderata: " << media_pond_r << " +/- " << err_media_pond_r << endl;
     cout << "Capacità" << cap << " +/- " << err_cap << endl;

     //Legge i dati grezzi
     dc carica_r, scarica_c;
     carica_r.read("../Dati", "carica_r");
     scarica_c.read("../Dati", "scarica_c");

     //Definizione dei fondo scala per il calcolo degli errori

     //--------------CARICA
     carica_r.unit_time = "us";
     carica_r.unit_volts = "mV";
     carica_r.fst = 5;
     carica_r.fsv = 136;
     //Cursore 1
     carica_r.v_0 = 957;
     carica_r.t_0 = 0.2;

     //-------------SCARICA
     scarica_c.unit_time = "us";
     scarica_c.unit_volts = "mV";
     scarica_c.fsv = 136;
     scarica_c.fst = 10;
     //Cursore 1
     scarica_c.v_0 = 1000;
     scarica_c.t_0 = -5.6;

     //Traslazione tempi
     scarica_c.translate_time();
     carica_r.translate_time();

     //Salva i dati della curva in json per interpolazioni su root
     scarica_c.calcolo_errori();
     carica_r.calcolo_errori();

     //Calcolo del rapporto v/v_0
     carica_r.calcolo_v_v0();
     scarica_c.calcolo_v_v0();

     scarica_c.calcolo_errori_rapporto();
     carica_r.calcolo_errori_rapporto();

     //root

     //Calcolo dei valori per eseguire fit lineare
     carica_r.compute_ln();
     scarica_c.compute_ln();

     carica_r.to_json("../Json", "carica_r.json");
     scarica_c.to_json("../Json", "scarica_c.json");

     carica_r.resistenza_generatore();
     scarica_c.resistenza_generatore();

     //Stampa la costante di tempo e la capacità
     carica_r.calcolo_capacity_fit_exp("../Fit_results", "carica_r_esponenziale.json", media_pond_r, err_media_pond_r);
     carica_r.calcolo_capacity_fit_lineare("../Fit_results", "carica_r_lineare.json", media_pond_r, err_media_pond_r);
     scarica_c.calcolo_capacity_fit_exp("../Fit_results", "scarica_c_esponenziale.json", media_pond_r, err_media_pond_r);
     scarica_c.calcolo_capacity_fit_lineare("../Fit_results", "scarica_c_lineare.json", media_pond_r, err_media_pond_r);

     //Compatibilità tau
     cout << "Comp tau exp: " << comp(carica_r.tau_exp, scarica_c.tau_exp, carica_r.err_tau_exp, scarica_c.err_tau_exp) << endl;
     cout << "Comp tau lin: " << comp(carica_r.tau_lin, scarica_c.tau_lin, carica_r.err_tau_lin, scarica_c.err_tau_lin) << endl
          << endl;

     //Compatibilità C
     cout << "Comp C exp: " << comp(carica_r.c_exp, scarica_c.c_exp, carica_r.err_c_exp, scarica_c.err_c_exp) << endl;
     cout << "Comp C lin: " << comp(carica_r.c_lin, scarica_c.c_lin, carica_r.err_c_lin, scarica_c.err_c_lin) << endl
          << endl;

     //Compatibilità C_g
     cout << "Comp C_g exp: " << comp(carica_r.c_exp_rg, scarica_c.c_exp_rg, carica_r.err_c_exp_rg, scarica_c.err_c_exp_rg) << endl;
     cout << "Comp C_g lin: " << comp(carica_r.c_lin_rg, scarica_c.c_lin_rg, carica_r.err_c_lin_rg, scarica_c.err_c_lin_rg) << endl
          << endl;

     //---------------------------------------------------------------
     //CORRENTE ALTERNATA
     ac passa_alto, passa_basso;

     //Stima della frequenza di taglio teorica
     passa_alto.f_taglio(media_pond_r, err_media_pond_r, 9.73, 0.08);

     //Legge i dati grezzi
     passa_alto.read("../Dati", "passa_alto");
     passa_basso.read("../Dati", "passa_basso");

     //Salva le unita di misura
     passa_alto.unit_time = "us";
     passa_alto.unit_volts = "mV";
     passa_basso.unit_time = "us";
     passa_basso.unit_volts = "mV";

     //Calcola anche tutti gli erroriassociati
     passa_alto.trasferimento();
     passa_basso.trasferimento();
     passa_alto.sfasamento_assey();
     passa_basso.sfasamento_assey();

     //Salva i dati in json
     passa_alto.to_json("../Json", "passa_alto.json");
     passa_basso.to_json("../Json", "passa_basso.json");

     //Metodo minimizzazione di chi quadri (serve che fabio abbia eseguito i fit delle parabole con min_chi.cxx)
     //
     //
     //Non può farlo per lo sfasamento in passa alto perchè mancano i dati
     compute_minimization_trasf(5.5, 1000, 0.001, passa_alto, trasferimento_atteso_pa, "../Json", "min_chi_passa_alto.json");
     compute_minimization_trasf(5.5, 1000, 0.001, passa_basso, trasferimento_atteso_pb, "../Json", "min_chi_passa_basso.json");
     compute_minimization_sfasamento(5.5, 1000, 0.001, passa_basso, sfasamento_atteso_pb, "../Json", "min_chi_passa_basso_sfasamento.json");
     compute_minimization_sfasamento(5.5, 1000, 0.001, passa_alto, sfasamento_atteso_pa, "../Json", "min_chi_passa_alto_sfasamento.json");

     freq_min_chi("../Fit_results", "chi_min_passa_basso.json");
     freq_min_chi("../Fit_results", "chi_min_passa_alto.json");
     freq_min_chi("../Fit_results", "chi_min_passa_basso_sfasamento.json");

     //Stima f taglio con trasf e sfas
     f_taglio_fit_line_tr("../Fit_results", "pb_trasf_linearizzato.json");
     f_taglio_fit_line_sf("../Fit_results", "pb_sfas_linearizzato.json");

     return 0;
}
