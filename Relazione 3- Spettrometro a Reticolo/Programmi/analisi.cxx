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
//#include "functions.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
     const double lambda_azz = 479.99123e-9;
     const double lambda_ver = 508.58217e-9;
     const double err_th = 1e-11;

     Misure azz, ver;
     double err_orto;
     azz.lettura("../Dati/", "azzurro.txt");
     ver.lettura("../Dati/", "verde.txt");

     azz.convert_in_rad();
     ver.convert_in_rad();

     azz.media_angoli_noni();
     ver.media_angoli_noni();

     azz.err_eccentricity();
     ver.err_eccentricity();

     ver.err_ortogonalizzazione();
     azz.err_ortogonalizzazione();

     ver.translate_zero();
     azz.translate_zero();

     ver.compute_sin();
     azz.compute_sin();

     ver.to_json("../Json/", "verde.json");
     azz.to_json("../Json/", "azzurro.json");

     ver.compute_lambda();
     azz.compute_lambda();

     azz.parse_fit("../Fit_results/", "azzurro_results.json", "../Fit_results/", "azzurro_results_forzato.json");
     ver.parse_fit("../Fit_results/", "verde_results.json", "../Fit_results/", "verde_results_forzato.json");

     cout << "Err eccentricità" << endl;
     print_v(ver.ordine);
     print_v(ver.err_ecc_1);
     cout << endl;
     print_v(ver.err_ecc_2);
     cout << endl;
     print_v(azz.err_ecc_1);
     cout << endl;
     print_v(azz.err_ecc_2);
     cout << endl;

     cout << "verde" << endl
          << "(alg): " << ver.lambda_media << "\t" << ver.err_lambda_media << endl
          << "(fit): " << ver.lambda_fit << "\t" << ver.err_lambda_fit << endl
          << "(fit_for): " << ver.lambda_fit_forced << "\t" << ver.err_lambda_fit_forced << endl;
     cout << "azzurro" << endl
          << "(alg): " << azz.lambda_media << "\t" << azz.err_lambda_media << endl
          << "(fit): " << azz.lambda_fit << "\t" << azz.err_lambda_fit << endl
          << "(fit_for): " << azz.lambda_fit_forced << "\t" << azz.err_lambda_fit_forced << endl;

     cout << "compatibilità" << endl
          << "verde alg-fit: " << comp(ver.lambda_media, ver.lambda_fit, ver.err_lambda_media, ver.err_lambda_fit) << endl
          << "azz alg-fit: " << comp(azz.lambda_media, azz.lambda_fit, azz.err_lambda_media, azz.err_lambda_fit) << endl
          << "verde fit-fit_f: " << comp(ver.lambda_fit, ver.lambda_fit_forced, ver.err_lambda_fit, ver.err_lambda_fit_forced) << endl
          << "azz fit-fit: " << comp(azz.lambda_fit, azz.lambda_fit_forced, azz.err_lambda_fit, azz.err_lambda_fit_forced) << endl
          << "verde alg-fit_f: " << comp(ver.lambda_media, ver.lambda_fit_forced, ver.err_lambda_media, ver.err_lambda_fit_forced) << endl
          << "azz alg-fit: " << comp(azz.lambda_media, azz.lambda_fit_forced, azz.err_lambda_media, azz.err_lambda_fit_forced) << endl;
     cout << endl
          << "compatibilità teorica" << endl
          << "verde alg-th: " << comp(ver.lambda_media, lambda_ver, ver.err_lambda_media, err_th) << endl
          << "azz alg-th: " << comp(azz.lambda_media, lambda_azz, azz.err_lambda_media, err_th) << endl
          << "verde fit-th: " << comp(ver.lambda_fit, lambda_ver, ver.err_lambda_fit, err_th) << endl
          << "azz fit-th: " << comp(azz.lambda_fit, lambda_azz, azz.err_lambda_fit, err_th) << endl
          << "verde fit_f-th: " << comp(ver.lambda_fit_forced, lambda_ver, ver.err_lambda_fit_forced, err_th) << endl
          << "azz fit_t-th: " << comp(azz.lambda_fit_forced, lambda_azz, azz.err_lambda_fit_forced, err_th) << endl;
     cout << endl
          << "Compatibilita fit con zero" << endl
          << "comp fit_0 azz: " << comp(azz.fit.a[0], 0, azz.fit.err_a[0], 0) << endl
          << "comp fit_0 ver: " << comp(ver.fit.a[0], 0, ver.fit.err_a[0], 0) << endl;


     //Stapo un attimo le lambda per vedere come vengono
     json l;
     l["verde"]["lambda"] = ver.lambda;
     l["verde"]["err_lambda"] = ver.err_lambda;
     l["azzurro"]["lambda"] = azz.lambda;
     l["azzurro"]["err_lambda"] = azz.err_lambda;

     ofstream fout_l("../Json/all_lambda.json");
     fout_l << setw(4) << l << endl;

     /*cout<<endl;
     print_v(ver.lambda);
     print_v(ver.err_lambda);
     cout<<endl<<ver.lambda_media<<"\t"<<ver.err_lambda_media<<endl;
     print_v(azz.lambda);
     print_v(azz.err_lambda);
     cout<<endl<<azz.lambda_media<<"\t"<<azz.err_lambda_media<<endl;*/

     return 0;
}