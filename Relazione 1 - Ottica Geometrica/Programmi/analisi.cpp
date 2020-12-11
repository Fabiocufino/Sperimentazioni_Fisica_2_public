#include <iostream>
#include "containers.h"
#include "statistica.h"
#include "input.h"
#include "analisi.h"
using namespace std;

int main()
{

     vector<std::string> operatori = {"_f.txt", "_t.txt", "_m.txt"};
     const double sp_lente = 7.0;        //millimetri, spessore totale
     const double err_sp_lente = 0.1;    //
     const double sp_limatura = 2.30;    //millimetri, spalla
     const double err_sp_limatura = 0.1; //
     const double err_posizione = 0.5;   //
     const double err_r_diaframma = 0.5; //
     const double R = 14.0;
     const double err_R = 0.5;
     double f_star;                   //Archivio di tutte le stime finali
     double err_f_star;               //
     double f_star_bessel;            //
     double err_f_star_bessel;        //
     double f_from_s_star_bessel;     //
     double err_f_from_s_star_bessel; //
     double c_star;                   //
     double err_c_star;               //
     double v_star;                   //
     double err_v_star;               //

     /* CONIUGATI */

     Coniugati all_data_fabio;
     read_coniugati("_f.txt", all_data_fabio);
     all_data_fabio.compute_diffs(sp_lente, sp_limatura, err_posizione, err_sp_lente, err_sp_limatura);
     all_data_fabio.print_unbiased_coniugati("coniugati_fabio.txt");
     all_data_fabio.compute_f();
     all_data_fabio.compute_f_algebrico(sp_lente, sp_limatura);

     Coniugati all_data_tommaso;
     read_coniugati("_t.txt", all_data_tommaso);
     all_data_tommaso.compute_diffs(sp_lente, sp_limatura, err_posizione, err_sp_lente, err_sp_limatura);
     all_data_tommaso.print_unbiased_coniugati("coniugati_tommaso.txt");
     all_data_tommaso.compute_f();
     all_data_tommaso.compute_f_algebrico(sp_lente, sp_limatura);

     Coniugati all_data_marco;
     read_coniugati("_m.txt", all_data_marco);
     all_data_marco.compute_diffs(sp_lente, sp_limatura, err_posizione, err_sp_lente, err_sp_limatura);
     all_data_marco.print_unbiased_coniugati("coniugati_marco.txt");
     all_data_marco.compute_f();
     all_data_marco.compute_f_algebrico(sp_lente, sp_limatura);

     vector<double> f_1_operatori = {all_data_fabio.f_1, all_data_marco.f_1, all_data_tommaso.f_1};
     vector<double> f_2_operatori = {all_data_fabio.f_2, all_data_marco.f_2, all_data_tommaso.f_2};

     cout << "********" << endl
          << "Coniugati" << endl
          << "********" << endl;

     cout << "Compatibilità coeff angolari con -1" << endl;
     cout << "f\t" << comp(all_data_fabio.b_ang, -1.0, all_data_fabio.err_b_ang, 0) << endl;
     cout << "m\t" << comp(all_data_marco.b_ang, -1.0, all_data_marco.err_b_ang, 0) << endl;
     cout << "t\t" << comp(all_data_tommaso.b_ang, -1.0, all_data_tommaso.err_b_ang, 0) << endl
          << endl;

     cout << "Metodo 1 - Interpolazione Root" << endl
          << "N\tf1\tf2" << endl;
     cout << "f\t" << all_data_fabio.f_1 << "+-" << all_data_fabio.err_f_1 << "\t" << all_data_fabio.f_2 << "+-" << all_data_fabio.err_f_2 << endl;
     cout << "m\t" << all_data_marco.f_1 << "+-" << all_data_marco.err_f_1 << "\t" << all_data_marco.f_2 << "+-" << all_data_marco.err_f_2 << endl;
     cout << "t\t" << all_data_tommaso.f_1 << "+-" << all_data_tommaso.err_f_1 << "\t" << all_data_tommaso.f_2 << "+-" << all_data_tommaso.err_f_2 << endl;
     cout << endl
          << "Media f1 f2 per 'colonna'" << endl
          << endl;
     cout << "media f_1 " << media(f_1_operatori) << "+-" << dstd_media(f_1_operatori) << endl;
     cout << "media f_2 " << media(f_2_operatori) << "+-" << dstd_media(f_2_operatori) << endl;
     cout << "media f_12 " << media({media(f_1_operatori), media(f_2_operatori)}) << "+-" << (media(f_1_operatori) - media(f_2_operatori)) / 2 << "(errore è semidisperione fra due misure)" << endl;

     cout << endl
          << "Metodo 2 - Algebrico" << endl;
     cout << "Media di f_algebrici per operatore" << endl;
     cout << "N\tf_alg +- err_f_alg" << endl;
     cout << "f\t" << all_data_fabio.f_alg << " +- " << all_data_fabio.err_f_alg << endl;
     cout << "m\t" << all_data_marco.f_alg << " +- " << all_data_marco.err_f_alg << endl;
     cout << "t\t" << all_data_tommaso.f_alg << " +- " << all_data_tommaso.err_f_alg << endl;

     cout << endl
          << "Compatibilità per fouchi algebrici" << endl
          << "f-m\t" << comp(all_data_fabio.f_alg, all_data_marco.f_alg, all_data_fabio.err_f_alg, all_data_marco.err_f_alg) << endl
          << "f-t\t" << comp(all_data_fabio.f_alg, all_data_tommaso.f_alg, all_data_fabio.err_f_alg, all_data_tommaso.err_f_alg) << endl
          << "t-m\t" << comp(all_data_tommaso.f_alg, all_data_marco.f_alg, all_data_tommaso.err_f_alg, all_data_marco.err_f_alg) << endl;

     cout << "media pond f_alg " << media_ponderata({all_data_tommaso.f_alg, all_data_marco.f_alg, all_data_fabio.f_alg}, {all_data_tommaso.err_f_alg, all_data_marco.err_f_alg, all_data_fabio.err_f_alg})
          << " +- " << errore_media_ponderata({all_data_tommaso.err_f_alg, all_data_marco.err_f_alg, all_data_fabio.err_f_alg}) << endl;

     //cout << endl
     //     << "Compatibilità possibili interpolazione" << endl
     //     << "f-m \t" << comp(all_data_fabio.f_12, all_data_marco.f_12, all_data_fabio.err_f_12, all_data_marco.err_f_12) << endl
     //     << "f-t \t" << comp(all_data_fabio.f_12, all_data_tommaso.f_12, all_data_fabio.err_f_12, all_data_tommaso.err_f_12) << endl
     //     << "t-m \t" << comp(all_data_tommaso.f_12, all_data_marco.f_12, all_data_tommaso.err_f_12, all_data_marco.err_f_12) << endl;
     //err_f_star = dstd_media({all_data_tommaso.f_12, all_data_marco.f_12, all_data_fabio.f_12});
     //f_star = media({all_data_tommaso.f_12, all_data_marco.f_12, all_data_fabio.f_12});

     //Focale definitiva da media di f_m,t,f
     //cout << "(coniugati) focale definitiva interpolazione: " << f_star << "+/-" << err_f_star << " err_pomd " << errore_media_ponderata({all_data_tommaso.err_f_12, all_data_marco.err_f_12, all_data_fabio.err_f_12}) << endl
     //     << endl;

     //cout << "comp f_1 e f_2 per riga per operatore" << comp(all_data_fabio.f_1, all_data_fabio.f_2, all_data_fabio.err_f_1, all_data_fabio.err_f_2) << endl;
     //cout << "comp f_1 e f_2 per riga per operatore" << comp(all_data_marco.f_1, all_data_marco.f_2, all_data_marco.err_f_1, all_data_marco.err_f_2) << endl;
     //cout << "comp f_1 e f_2 per riga per operatore" << comp(all_data_tommaso.f_1, all_data_tommaso.f_2, all_data_tommaso.err_f_1, all_data_tommaso.err_f_2) << endl;

     /* BESSEL */

     //Metodo 2 e 1 (da f calcolati da media di s)
     Bessel bessel_m, bessel_t, bessel_f;
     read_bessel("_t.txt", bessel_t, 200, 500);
     read_bessel("_f.txt", bessel_f, 172, 475);
     read_bessel("_m.txt", bessel_m, 200, 500);
     bessel_f.compute_s(err_posizione);
     bessel_t.compute_s(err_posizione);
     bessel_m.compute_s(err_posizione);
     bessel_f.compute_l(sp_lente, err_sp_lente, err_posizione, err_posizione);
     bessel_t.compute_l(sp_lente, err_sp_lente, err_posizione, err_posizione);
     bessel_m.compute_l(sp_lente, err_sp_lente, err_posizione, err_posizione);
     bessel_f.compute_f_from_s(err_posizione); //metodo 2, da media di s
     bessel_t.compute_f_from_s(err_posizione); //
     bessel_m.compute_f_from_s(err_posizione); //
     bessel_f.compute_f();                     //metodo 1, da media di f
     bessel_t.compute_f();                     //
     bessel_m.compute_f();                     //

     f_star_bessel = media({bessel_f.f_complessivo, bessel_t.f_complessivo, bessel_m.f_complessivo});
     err_f_star_bessel = dstd_media({bessel_f.f_complessivo, bessel_t.f_complessivo, bessel_m.f_complessivo});

     f_from_s_star_bessel = media({bessel_f.f_from_s, bessel_m.f_from_s});
     err_f_from_s_star_bessel = dstd_media({bessel_f.f_from_s, bessel_m.f_from_s});

     cout << endl
          << "*******" << endl
          << "Bessel" << endl
          << "******" << endl;
     cout << endl
          << "f da f_i" << endl
          << "N\tf+-err_f" << endl
          << "f\t" << bessel_f.f_complessivo << " +- " << bessel_f.err_f_complessivo << endl
          << "m\t" << bessel_m.f_complessivo << " +- " << bessel_f.err_f_complessivo << endl
          << "t\t" << bessel_t.f_complessivo << " +- " << bessel_t.err_f_complessivo << endl;
     cout << "Compatibilità f da f_i" << endl;
     cout << "f-m " << comp(bessel_f.f_complessivo, bessel_m.f_complessivo, bessel_f.err_f_complessivo, bessel_m.err_f_complessivo)
          << endl
          << "f-t " << comp(bessel_f.f_complessivo, bessel_t.f_complessivo, bessel_f.err_f_complessivo, bessel_t.err_f_complessivo)
          << endl
          << "m-t " << comp(bessel_m.f_complessivo, bessel_t.f_complessivo, bessel_m.err_f_complessivo, bessel_t.err_f_complessivo) << endl;

     cout << endl
          << "f da f_i complessiva" << endl
          << "f " << f_star_bessel << " +- " << err_f_star_bessel << endl;

     cout << "f da media S" << endl;
     cout << "N\tL\tS\tf" << endl
          << "f\t000\t" << bessel_f.s_ << " +- " << bessel_f.err_s_ << "\t" << bessel_f.f_from_s << " +- " << bessel_f.err_f_from_s << endl
          << "m\t000\t" << bessel_m.s_ << " +- " << bessel_m.err_s_ << "\t" << bessel_m.f_from_s << " +- " << bessel_m.err_f_from_s << endl
          << "t\t000\t" << bessel_t.s_ << " +- " << bessel_t.err_s_ << "\t" << bessel_t.f_from_s << " +- " << bessel_t.err_f_from_s << endl;

     cout << endl
          << "Compatibilità f from S" << endl;
     cout << "f-m " << comp(bessel_f.f_from_s, bessel_m.f_from_s, bessel_f.err_f_from_s, bessel_m.err_f_from_s) << endl
          << "f-t " << comp(bessel_f.f_from_s, bessel_t.f_from_s, bessel_f.err_f_from_s, bessel_t.err_f_from_s) << endl
          << "m-t " << comp(bessel_m.f_from_s, bessel_t.f_from_s, bessel_m.err_f_from_s, bessel_t.err_f_from_s) << endl;

     cout << endl
          << "f da S complessiva" << endl
          << "f " << f_from_s_star_bessel << " +- " << err_f_from_s_star_bessel << endl;

     /* SFERICA */

     Sferica sferica_f, sferica_t, sferica_m;
     read_sferica("_f.txt", sferica_f);
     read_sferica("_t.txt", sferica_t);
     read_sferica("_m.txt", sferica_m);
     sferica_f.compute_l(err_posizione);
     sferica_t.compute_l(err_posizione);
     sferica_m.compute_l(err_posizione);
     sferica_f.compute_c(R, err_R, f_star_bessel);
     sferica_t.compute_c(R, err_R, f_star_bessel);
     sferica_m.compute_c(R, err_R, f_star_bessel);

     cout << "*****" << endl
          << "Sferica" << endl
          << "*******" << endl
          << endl;
     cout << "Computo per operatore singolo" << endl;
     cout << "l\tc" << endl;
     cout << "f\t" << media(sferica_f.l) << "+-" << dstd_media(sferica_f.l) << "\t" << sferica_f.c_complessiva << " +- " << sferica_f.err_c_complessiva << endl
          << "m\t" << media(sferica_m.l) << "+-" << dstd_media(sferica_m.l) << "\t" << sferica_m.c_complessiva << " +- " << sferica_m.err_c_complessiva << endl
          << "t\t" << media(sferica_t.l) << "+-" << dstd_media(sferica_t.l) << "\t" << sferica_t.c_complessiva << " +- " << sferica_t.err_c_complessiva << endl;

     cout << "Compatibilità possibili" << endl
          << "f-m \t" << comp(sferica_f.c_complessiva, sferica_m.c_complessiva, sferica_f.err_c_complessiva, sferica_m.err_c_complessiva) << endl
          << "f-t \t" << comp(sferica_f.c_complessiva, sferica_t.c_complessiva, sferica_f.err_c_complessiva, sferica_t.err_c_complessiva) << endl
          << "t-m \t" << comp(sferica_t.c_complessiva, sferica_m.c_complessiva, sferica_t.err_c_complessiva, sferica_m.err_c_complessiva) << endl;

     cout << endl
          << "valori complessivi sferica (solo fab marc)" << endl;
     c_star = media({sferica_f.c_complessiva, sferica_m.c_complessiva});
     err_c_star = dstd_media({sferica_f.c_complessiva, sferica_m.c_complessiva});
     cout << c_star << " +- " << err_c_star << endl;

     /* CROMATICA */

     Cromatica cromatica_f, cromatica_t, cromatica_m;
     read_cromatica("_f.txt", cromatica_f);
     read_cromatica("_t.txt", cromatica_t);
     read_cromatica("_m.txt", cromatica_m);
     cromatica_f.compute_a();
     cromatica_t.compute_a();
     cromatica_m.compute_a();
     cromatica_f.compute_v(f_star_bessel);
     cromatica_t.compute_v(f_star_bessel);
     cromatica_m.compute_v(f_star_bessel);

     cout << "******" << endl
          << "Cromatica" << endl
          << "*****" << endl;

     cout << "Numero abbe reiettato" << endl;
     cout << "N\tA\tV" << endl
          << "f\t" << media(cromatica_f.a) << " +- " << dstd_media(cromatica_f.a) << "\t" << cromatica_f.v_complessivo << " +- " << cromatica_f.err_v_complessivo << endl
          << "m\t" << media(cromatica_m.a) << " +- " << dstd_media(cromatica_m.a) << "\t" << cromatica_m.v_complessivo << " +- " << cromatica_m.err_v_complessivo << endl
          << "t\t" << media(cromatica_t.a) << " +- " << dstd_media(cromatica_t.a) << "\t" << cromatica_t.v_complessivo << " +- " << cromatica_t.err_v_complessivo << endl;

     cout << "Compatibilità possibili" << endl
          << "f-m \t" << comp(cromatica_f.v_complessivo, cromatica_m.v_complessivo, cromatica_f.err_v_complessivo, cromatica_m.err_v_complessivo) << endl
          << "f-t \t" << comp(cromatica_f.v_complessivo, cromatica_t.v_complessivo, cromatica_f.err_v_complessivo, cromatica_t.err_v_complessivo) << endl
          << "t-m \t" << comp(cromatica_t.v_complessivo, cromatica_m.v_complessivo, cromatica_t.err_v_complessivo, cromatica_m.err_v_complessivo) << endl;
     v_star = media({cromatica_f.v_complessivo, cromatica_t.v_complessivo});
     err_v_star = dstd_media({cromatica_f.v_complessivo, cromatica_t.v_complessivo});
     cout << endl
          << "abbe definitivo (solo tom e fab)" << endl
          << v_star << "+/-" << err_v_star << endl;

     return 0;
}