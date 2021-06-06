#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TFitResult.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TGraphErrors.h"
#include "TPaveStats.h"
#ifndef DATACLASS
#include "../Programmi/dataclass.h"
#endif

//Metta nella struttura fit_resuts tutti i parametri del fit e crea un file .json dove scrivere i parametri calcolati
void fit_on_json(TF1 *f, Double_t number_of_parameters, TGraph *graf, vector<double> &asse_x, vector<double> &asse_y, fit_results &fit_res_str, string folder, string filename, double asse_x_inizio = -__DBL_MAX__, double asse_x_fine = __DBL_MAX__)
{
    //TFitResultPtr fit_res = graf->Fit(f, "S");
    TFitResultPtr fit_res = graf->Fit(f, "+S", "", asse_x_inizio, asse_x_fine);
    TMatrixD cov = fit_res->GetCovarianceMatrix();

    fit_res_str.a.push_back(f->GetParameter(0));
    fit_res_str.err_a.push_back(f->GetParError(0));
    fit_res_str.chi_square.push_back(f->GetChisquare());
    fit_res_str.dof.push_back(f->GetNDF());

    if (number_of_parameters == 2)
    {
        fit_res_str.b.push_back(f->GetParameter(1));
        fit_res_str.err_b.push_back(f->GetParError(1));
        fit_res_str.rho.push_back(pearson(asse_x, asse_y));
        fit_res_str.t_student.push_back(student(asse_x, asse_y));
        fit_res_str.sigma_post.push_back(sigma_y_posteriori(asse_x, asse_y));
        fit_res_str.covariance_matrix[0][1] = cov[0][1];
        fit_res_str.covariance_matrix[1][0] = cov[0][1];
    }

    if (number_of_parameters == 3)
    {
        fit_res_str.b.push_back(f->GetParameter(1));
        fit_res_str.err_b.push_back(f->GetParError(1));
        fit_res_str.rho.push_back(pearson(asse_x, asse_y));
        fit_res_str.t_student.push_back(student(asse_x, asse_y));
        fit_res_str.sigma_post.push_back(sigma_y_posteriori(asse_x, asse_y));
        fit_res_str.c.push_back(f->GetParameter(2));
        fit_res_str.err_c.push_back(f->GetParError(2));

        fit_res_str.covariance_matrix[0][1] = cov[0][1];
        fit_res_str.covariance_matrix[1][2] = cov[1][2];
        fit_res_str.covariance_matrix[2][0] = cov[2][0];
  
        fit_res_str.covariance_matrix[1][0] = cov[0][1];
        fit_res_str.covariance_matrix[2][1] = cov[1][2];
        fit_res_str.covariance_matrix[0][2] = cov[2][0];
    }
    if (number_of_parameters == 4) //AGGIUSTARE LA MATRICE DI COVARIANZE
    {
        fit_res_str.b.push_back(f->GetParameter(1));
        fit_res_str.err_b.push_back(f->GetParError(1));
        fit_res_str.c.push_back(f->GetParameter(2));
        fit_res_str.err_c.push_back(f->GetParError(2));
        fit_res_str.d.push_back(f->GetParameter(3));
        fit_res_str.err_d.push_back(f->GetParError(3));
        //fit_res_str.e.push_back(f->GetParameter(4));
        //fit_res_str.err_e.push_back(f->GetParError(4));

        fit_res_str.covariance_matrix[0][1] = cov[0][1];
        fit_res_str.covariance_matrix[1][2] = cov[1][2];
        fit_res_str.covariance_matrix[2][0] = cov[2][0];
        fit_res_str.covariance_matrix[0][3] = cov[0][3];
        fit_res_str.covariance_matrix[1][3] = cov[1][3];
        fit_res_str.covariance_matrix[2][3] = cov[2][3];
        //Failsafe (chiedere a tom)
        fit_res_str.covariance_matrix[1][0] = cov[0][1];
        fit_res_str.covariance_matrix[2][1] = cov[1][2];
        fit_res_str.covariance_matrix[0][2] = cov[2][0];
        fit_res_str.covariance_matrix[3][0] = cov[0][3];
        fit_res_str.covariance_matrix[3][1] = cov[1][3];
        fit_res_str.covariance_matrix[3][2] = cov[2][3];
    }

    fit_res_str.root_to_json(folder, filename);
}

//Crea il TPave dove scrivere gli estimatori del fit
void informazioni_fit_lineare(TPaveStats *ptstats1, TText *ptstats_LaTex1, string chi_s, string dof, string par_0, string err_par_0, string par_1, string err_par_1, string pear, string stu, string sigma_p, string title = "")
{
    ptstats1 = new TPaveStats(0.5, 0.65, 0.95, 0.95, "brNDC");
    ptstats1->SetName("stats");
    ptstats1->SetBorderSize(1);
    ptstats1->SetFillColor(0);
    ptstats1->SetTextAlign(12);
    ptstats1->SetTextFont(22);

    if (title.size() != 0)
    {
        const char *title_c = title.c_str();
        ptstats_LaTex1 = ptstats1->AddText(title_c);
    }

    string first = "#chi^{2} / ndf =" + chi_s + "/" + dof;
    const char *first_c = first.c_str();
    ptstats_LaTex1 = ptstats1->AddText(first_c);

    string second = "a        = " + par_0 + "#pm" + err_par_0;
    const char *second_c = second.c_str();
    ptstats_LaTex1 = ptstats1->AddText(second_c);

    string third = "b        = " + par_1 + "#pm" + err_par_1;
    const char *third_c = third.c_str();
    ptstats_LaTex1 = ptstats1->AddText(third_c);

    string fourth = "Pearson        = " + pear;
    const char *fourth_c = fourth.c_str();
    ptstats_LaTex1 = ptstats1->AddText(fourth_c);

    string fiveth = "T_Student        = " + stu;
    const char *fiveth_c = fiveth.c_str();
    ptstats_LaTex1 = ptstats1->AddText(fiveth_c);

    string sixth = "#sigma_{post}        = " + sigma_p;
    const char *sixth_c = sixth.c_str();
    ptstats_LaTex1 = ptstats1->AddText(sixth_c);

    ptstats1->SetOptStat(0);
    ptstats1->SetOptFit(111);
    ptstats1->Draw();
}

void informazioni_fit_parabolico(TPaveStats *ptstats1, TText *ptstats_LaTex1, string chi_s, string dof, string par_0, string err_par_0, string par_1, string err_par_1, string par_2, string err_par_2, string title = "")
{
    ptstats1 = new TPaveStats(0.5, 0.65, 0.95, 0.95, "brNDC");
    ptstats1->SetName("stats");
    ptstats1->SetBorderSize(1);
    ptstats1->SetFillColor(0);
    ptstats1->SetTextAlign(12);
    ptstats1->SetTextFont(22);

    if (title.size() != 0)
    {
        const char *title_c = title.c_str();
        ptstats_LaTex1 = ptstats1->AddText(title_c);
    }

    string first = "#chi^{2} / ndf =" + chi_s + "/" + dof;
    const char *first_c = first.c_str();
    ptstats_LaTex1 = ptstats1->AddText(first_c);

    string second = "a        = " + par_0 + "#pm" + err_par_0;
    const char *second_c = second.c_str();
    ptstats_LaTex1 = ptstats1->AddText(second_c);

    string third = "b        = " + par_1 + "#pm" + err_par_1;
    const char *third_c = third.c_str();
    ptstats_LaTex1 = ptstats1->AddText(third_c);

    string third_2 = "c        = " + par_2 + "#pm" + err_par_2;
    const char *third_2_c = third_2.c_str();
    ptstats_LaTex1 = ptstats1->AddText(third_2_c);

    ptstats1->SetOptStat(0);
    ptstats1->SetOptFit(111);
    ptstats1->Draw();
}

void informazioni_fit_nl_2_param(TPaveStats *ptstats1, TText *ptstats_LaTex1, string chi_s, string dof, string par_0, string err_par_0, string par_1, string err_par_1, string title = "")
{
    ptstats1 = new TPaveStats(0.5, 0.65, 0.95, 0.95, "brNDC");
    ptstats1->SetName("stats");
    ptstats1->SetBorderSize(1);
    ptstats1->SetFillColor(0);
    ptstats1->SetTextAlign(12);
    ptstats1->SetTextFont(22);

    if (title.size() != 0)
    {
        const char *title_c = title.c_str();
        ptstats_LaTex1 = ptstats1->AddText(title_c);
    }

    string first = "#chi^{2} / ndf =" + chi_s + "/" + dof;
    const char *first_c = first.c_str();
    ptstats_LaTex1 = ptstats1->AddText(first_c);

    string second = "a        = " + par_0 + "#pm" + err_par_0;
    const char *second_c = second.c_str();
    ptstats_LaTex1 = ptstats1->AddText(second_c);

    string third = "b        = " + par_1 + "#pm" + err_par_1;
    const char *third_c = third.c_str();
    ptstats_LaTex1 = ptstats1->AddText(third_c);

    ptstats1->SetOptStat(0);
    ptstats1->SetOptFit(111);
    ptstats1->Draw();
}

void informazioni_fit_RLC_sfas(TPaveStats *ptstats1, TText *ptstats_LaTex1, string chi_s, string dof, string par_0, string err_par_0, string par_1, string err_par_1, string par_2, string err_par_2, string title = "")
{
    ptstats1 = new TPaveStats(0.5, 0.65, 0.95, 0.95, "brNDC");
    ptstats1->SetName("stats");
    ptstats1->SetBorderSize(1);
    ptstats1->SetFillColor(0);
    ptstats1->SetTextAlign(12);
    ptstats1->SetTextFont(22);

    if (title.size() != 0)
    {
        const char *title_c = title.c_str();
        ptstats_LaTex1 = ptstats1->AddText(title_c);
    }

    string first = "#chi^{2} / ndf =" + chi_s + "/" + dof;
    const char *first_c = first.c_str();
    ptstats_LaTex1 = ptstats1->AddText(first_c);

    string second = "R        = " + par_0 + "#pm" + err_par_0;
    const char *second_c = second.c_str();
    ptstats_LaTex1 = ptstats1->AddText(second_c);

    string third = "L        = " + par_1 + "#pm" + err_par_1;
    const char *third_c = third.c_str();
    ptstats_LaTex1 = ptstats1->AddText(third_c);

    string fourth = "C        = " + par_2 + "#pm" + err_par_2;
    const char *fourth_c = fourth.c_str();
    ptstats_LaTex1 = ptstats1->AddText(fourth_c);

    ptstats1->SetOptStat(0);
    ptstats1->SetOptFit(111);
    ptstats1->Draw();
}
void informazioni_fit_RLC_totale(TPaveStats *ptstats1, TText *ptstats_LaTex1, string chi_s, string dof, string par_0, string err_par_0, string par_1, string err_par_1, string par_2, string err_par_2, string par_3, string err_par_3, string title = "")
{
    ptstats1 = new TPaveStats(0.5, 0.65, 0.95, 0.95, "brNDC");
    ptstats1->SetName("stats");
    ptstats1->SetBorderSize(1);
    ptstats1->SetFillColor(0);
    ptstats1->SetTextAlign(12);
    ptstats1->SetTextFont(22);

    if (title.size() != 0)
    {
        const char *title_c = title.c_str();
        ptstats_LaTex1 = ptstats1->AddText(title_c);
    }

    string first = "#chi^{2} / ndf =" + chi_s + "/" + dof;
    const char *first_c = first.c_str();
    ptstats_LaTex1 = ptstats1->AddText(first_c);

    string second = "R        = " + par_0 + "#pm" + err_par_0;
    const char *second_c = second.c_str();
    ptstats_LaTex1 = ptstats1->AddText(second_c);

    string third = "L        = " + par_1 + "#pm" + err_par_1;
    const char *third_c = third.c_str();
    ptstats_LaTex1 = ptstats1->AddText(third_c);

    string fourth = "C        = " + par_2 + "#pm" + err_par_2;
    const char *fourth_c = fourth.c_str();
    ptstats_LaTex1 = ptstats1->AddText(fourth_c);

    string cin = "a        = " + par_3 + "#pm" + err_par_3;
    const char *cin_c = cin.c_str();
    ptstats_LaTex1 = ptstats1->AddText(cin_c);

    ptstats1->SetOptStat(0);
    ptstats1->SetOptFit(111);
    ptstats1->Draw();
}

void informazioni_fit_nl_1_param(TPaveStats *ptstats1, TText *ptstats_LaTex1, string chi_s, string dof, string par_0, string err_par_0, string title = "")
{
    ptstats1 = new TPaveStats(0.5, 0.65, 0.95, 0.95, "brNDC");
    ptstats1->SetName("stats");
    ptstats1->SetBorderSize(1);
    ptstats1->SetFillColor(0);
    ptstats1->SetTextAlign(12);
    ptstats1->SetTextFont(22);

    if (title.size() != 0)
    {
        const char *title_c = title.c_str();
        ptstats_LaTex1 = ptstats1->AddText(title_c);
    }

    string first = "#chi^{2} / ndf =" + chi_s + "/" + dof;
    const char *first_c = first.c_str();
    ptstats_LaTex1 = ptstats1->AddText(first_c);

    string second = "a        = " + par_0 + "#pm" + err_par_0;
    const char *second_c = second.c_str();
    ptstats_LaTex1 = ptstats1->AddText(second_c);

    ptstats1->SetOptStat(0);
    ptstats1->SetOptFit(111);
    ptstats1->Draw();
}

//void legenda(TGraph *graf, TF1 *f, string func_tipe, string title)
//{
//    TLegend *leg = new TLegend(0.4335485, 0.6810381, 0.8649383, 0.859921, NULL, "brNDC");
//    leg->SetHeader("The Legend Title", "C");
//    TLegendEntry *entry1 = leg->AddEntry("NULL", title, "h");
//    TLegendEntry *entry2 = leg->AddEntry(graf, "Dati con errore", "p");
//    TLegendEntry *entry3 = leg->AddEntry(f, func_tipe + "interpolante", "l");
//    leg->Draw();
//}

//Fa il run test per una retta del tipo a+bx
void run_test(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double a_int, double b_ang)
{
    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - (a_int + (b_ang * asse_x[i])));
    }
}

//Fa il run test per l'esponenziale
void run_test_exp(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double a, double b)
{
    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - (TMath::Exp(b * asse_x[i] + a)));
    }
}

//Fa il run test per il passa alto
void run_test_passa_alto_trasf(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double a)
{
    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - 1 / sqrt(1 + pow(a / asse_x[i], 2)));
    }
}
void run_test_passa_alto_sfas(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double a)
{
    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - sqrt(pow(TMath::ATan(a / asse_x[i]), 2)) / M_PI_2);
    }
}

//Fa il run test per il passa basso TRASFERIMENTO
void run_test_passa_basso_trasf(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double a)
{
    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - 1 / sqrt(1 + pow(asse_x[i] / a, 2)));
    }
}
//Fa il run test per il passa basso Sfasamento
void run_test_passa_basso_sfas(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double a)
{
    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - sqrt(pow(TMath::ATan(-asse_x[i] / a), 2)) / M_PI_2);
    }
}
void run_test_sfas_R(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double R, double L, double C)
{
    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - TMath::ATan((-1 / (asse_x[i] * 2 * M_PI * C) + asse_x[i] * 2 * M_PI * L) / R));
    }
}
void run_test_sfas_C(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double R, double L, double C)
{
    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - (M_PI_2 + TMath::ATan((-1 / (asse_x[i] * 2 * M_PI * C) + asse_x[i] * 2 * M_PI * L) / R)));
    }
}
void run_test_trasf_R(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double a, double R, double L, double C)
{
    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - a * asse_x[i] * 2 * M_PI / sqrt(pow(asse_x[i] * 2 * M_PI, 4) - (2 * pow(asse_x[i] * 2 * M_PI, 2) * (pow(1 / sqrt(L * C), 2) - 2 * pow(R / (2 * L), 2))) + pow(1 / sqrt(L * C), 4)));
    }
}
void run_test_trasf_C(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double a, double R, double L, double C)
{
    double delta = R / (2 * L);
    double omega = 1 / sqrt(L * C);

    for (int i = 0; i < asse_x.size(); i++)
    {
        scarti.push_back(asse_y[i] - a * pow(omega, 2) / sqrt(pow(asse_x[i] * 2 * M_PI, 4) - (2 * pow(asse_x[i] * 2 * M_PI, 2) * (pow(omega, 2) - 2 * pow(delta, 2))) + pow(omega, 4)));
    }
}
void run_test_onda_tempo(vector<double> &scarti, vector<double> &asse_x, vector<double> &asse_y, double a, double R, double L, double C)
{

    for (int i = 0; i < asse_x.size(); i++)
    {
        double k = TMath::Sqrt(pow((1 / sqrt(L * C)), 2) - pow((R / (2. * L)), 2));
        scarti.push_back(asse_y[i] - (1 / k) * TMath::Exp(-(R / (2. * L)) * asse_x[i]) * ((R / (2. * L)) * TMath::Sin(k * asse_x[i]) + k * TMath::Cos(k * asse_x[i])));
    }
}