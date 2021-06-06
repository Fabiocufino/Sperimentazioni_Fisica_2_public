#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
//#include "statistica.h"
#include "dataclass.h"
//#include "json.hpp"

using namespace std;
int main()
{
    d_tempo dt;
    dt.read_max("../Dati", "max");
    dt.read_min("../Dati", "min");

    //Calcolo errori per fondi scala tempi
    dt.errori();
    //scrittura file
    dt.to_json_max("../Json", "max.json");
    dt.to_json_min("../Json", "min.json");

    //calcola compatibilità coeff angolari per vedere se min-max e m-p sono compatibili
    dt.periodi("../Fit_results", {"gr_m.json", "gr_p.json", "gr_min.json", "gr_max.json", "gr_intercette.json", "gr_stazionari.json"});
    dt.compute_omega_d();

    secondo_metodo_periodi("../Dati", "periodi");
    dt.compute_delta_exp("../Fit_results", "exp_max.json", "exp_min.json");
    dt.compute_delta_lin("../Fit_results", "lin_max.json", "lin_min.json");
    dt.compute_delta_unico("../Fit_results", "exp_somma.json", "lin_somma.json");

    dt.compute_omega_0();
    dt.compute_l();
    dt.compute_q_value();
    dt.compute_r_tot();

    dt.potenziometro();

    //--------------------------------------------------------------------------------------------------------Analisi RLC in FREQUENZA
    //--------------------------------------------------------------------------------------------------------Analisi RLC in FREQUENZA
    //--------------------------------------------------------------------------------------------------------Analisi RLC in FREQUENZA
    //--------------------------------------------------------------------------------------------------------Analisi RLC in FREQUENZA
    //--------------------------------------------------------------------------------------------------------Analisi RLC in FREQUENZA
    //--------------------------------------------------------------------------------------------------------Analisi RLC in FREQUENZA

    d_frequenza df_r, df_c, fit_lin_r_m, fit_lin_r_p, fit_lin_c_m, fit_lin_c_p;
    df_r.read("../Dati", "d_f_r.txt");
    df_r.to_json("../Json", "d_f_r.json");

    df_c.read("../Dati", "d_f_c.txt");
    df_c.to_json("../Json", "d_f_c.json");

    fit_lin_r_m.read("../Dati", "fit_lineare_r_m");
    fit_lin_r_m.to_json("../Json", "fit_lineare_r_m.json");
    fit_lin_r_p.read("../Dati", "fit_lineare_r_p");
    fit_lin_r_p.to_json("../Json", "fit_lineare_r_p.json");

    fit_lin_c_m.read("../Dati", "fit_lineare_c_m");
    fit_lin_c_m.to_json("../Json", "fit_lineare_c_m.json");
    fit_lin_c_p.read("../Dati", "fit_lineare_c_p");
    fit_lin_c_p.to_json("../Json", "fit_lineare_c_p.json");

    df_r.compute_a_max_r("../Fit_results", "fit_parabolico_r.json");
    df_c.compute_a_max_c("../Fit_results", "fit_parabolico_c.json");
    df_r.compute_f_taglio_trasf_r_m("../Fit_results", "lin_r_m_trasferimento.json");
    df_r.compute_f_taglio_trasf_r_p("../Fit_results", "lin_r_p_trasferimento.json");
    df_c.compute_f_taglio_trasf_c_m("../Fit_results", "lin_c_m_trasferimento.json");
    df_c.compute_f_taglio_trasf_c_p("../Fit_results", "lin_c_p_trasferimento.json");

    df_r.compute_f_taglio_sfas_r_m("../Fit_results", "sfasamento_fit_before.json");
    df_r.compute_f_taglio_sfas_r_p("../Fit_results", "sfasamento_fit_after.json");
    df_c.compute_f_taglio_sfas_c_m("../Fit_results", "lin_c_m_sfasamento.json");
    df_c.compute_f_taglio_sfas_c_p("../Fit_results", "lin_c_p_sfasamento.json");
    df_r.compute_q_r_trasf();
    df_c.compute_q_c_trasf();
    df_r.compute_q_r_sfas();
    df_c.compute_q_c_sfas();

    df_r.f_ris_lin_r("../Fit_results", "sfasamento_fit_center.json");
    df_r.larghezza_banda_r();
    df_c.larghezza_banda_c();

    compute_from_fit_non_lineari_trasf("../Fit_results", "df_r_trasferimento.json");
    compute_from_fit_non_lineari_trasf("../Fit_results", "df_c_trasferimento.json");
    compute_from_fit_non_lineari_sfas("../Fit_results", "df_r_sfasamento_tot.json");
    compute_from_fit_non_lineari_sfas("../Fit_results", "df_c_sfasamento.json");

    v_in("../Fit_results", "fit_parabolico_v_in_R.json");
    v_in("../Fit_results", "fit_parabolico_v_in_C.json");

    return 0;
}