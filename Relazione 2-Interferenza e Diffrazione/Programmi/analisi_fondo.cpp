#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "input.h"
#ifndef DATACLASS
#include "dataclass.h"
#endif
#include "statistica.h"

using namespace std;

int main()
{
    Dataset *bkg1 = new Dataset();
    Dataset *bkg2 = new Dataset();
    Dataset *bkg12 = new Dataset();
    bkg1->lettura("../Dati/", "1f_10p_bkg1.xls");
    bkg2->lettura("../Dati/", "1f_10p_bkg2.xls");
    bkg12->lettura("../Dati/", "1f_10p_bkg1.xls");
    bkg12->lettura("../Dati/", "1f_10p_bkg2.xls");
    double media1, media2, dstd1, dstd2, lambda, media12, dstd12;
    double media_unica, dstd_unica_campionaria;

    media1 = media(bkg1->asse_y);
    dstd1 = dstd_media(bkg1->asse_y);
    media2 = media(bkg2->asse_y);
    dstd2 = dstd_media(bkg2->asse_y);
    lambda = comp(media1, media2, dstd1, dstd2);
    media12 = media({media1, media2});
    dstd12 = dstd_media({media1, media2});

    //cout << media1 << "\t" << dstd1 << "\t" << media2 << "\t" << dstd2 << "\t" << lambda << "\t" << media12 << "\t" << dstd12 << endl;
    cout << "Primo campione" << endl;
    cout << media(bkg1->asse_y) << "\t" << dstd(bkg1->asse_y) << "\t" << dstd_media(bkg1->asse_y) << "\t" << bkg1->asse_y.size() << endl;
    cout << "secondo campione" << endl;
    cout << media(bkg2->asse_y) << "\t" << dstd(bkg2->asse_y) << "\t" << dstd_media(bkg2->asse_y) << "\t" << bkg2->asse_y.size() << endl;
    cout << "Compatibilità con dstd delle medie" << endl;
    cout << comp(media(bkg1->asse_y), media(bkg2->asse_y), dstd_media(bkg1->asse_y), dstd_media(bkg1->asse_y)) << endl;
    cout << "Campione unico" << endl;
    cout << media(bkg12->asse_y) << "\t" << dstd(bkg12->asse_y) << "\t" << dstd_media(bkg12->asse_y) << "\t" << bkg12->asse_y.size() << endl;
    cout << "Significanza: " << (7931 - media(bkg12->asse_y)) / dstd(bkg12->asse_y) << endl;
    //campione unico
    //cout<<bkg1->asse_y.size()<<"\t" <<bkg2->asse_y.size()<<"\t" <<bkg12->asse_y.size();
    //media_unica = media(bkg12->asse_y);

    //dstd_unica_campionaria = dstd(bkg12->asse_y);
    //cout << media_unica << "\t" << dstd_unica_campionaria;
    return 0;
}