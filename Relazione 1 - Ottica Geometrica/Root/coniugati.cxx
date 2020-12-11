
#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "fstream"
#include "TFitResult.h"
#include "TMatrixD.h"
using namespace std;

double func(double *x, double *par)
{
  double a = par[0];
  double b = par[1];

  double ret = (a * x[0]) + b;
  return ret;
}

void coniugati()
{

  TCanvas *c1 = new TCanvas("c1", "Canvas", 200, 10, 2000, 700); //creo il canvas sul quale mettere il grafico (TGraph)
  c1->Divide(3, 1, 0.00001, 0.00001);

  //-----------------------------------------------FABIO------------------------------------------
  c1->cd(1);
  gPad->SetGrid();
  gPad->SetFillColor(0);

  TGraphErrors *fileInput1 = new TGraphErrors("../File/coniugati_fabio.txt", "%lg %lg %lg %lg");

  fileInput1->SetMarkerColor(2);
  fileInput1->SetMarkerStyle(20);
  fileInput1->SetMarkerSize(0.8);
  fileInput1->SetTitle("Operatore A");
  fileInput1->GetXaxis()->SetTitle("1/p [1/m]");
  fileInput1->GetYaxis()->SetTitle("1/q [1/m]");
  fileInput1->GetXaxis()->SetAxisColor(14);
  fileInput1->GetYaxis()->SetAxisColor(14);
  fileInput1->GetXaxis()->SetLimits(0, 11.51);
  fileInput1->GetYaxis()->SetRangeUser(3, 15);

  fileInput1->Draw("AP");

  TF1 *f1 = new TF1("f1", func, 5, 12, 2);
  f1->SetParNames("b", "a");

  f1->SetParameter(0, -0.96); //a
  f1->SetParameter(1, 14.83); //b

  fileInput1->Fit("f1", "R");
  TFitResultPtr uno = fileInput1->Fit("f1", "S");

  ofstream fout1("risultati_fit_f.txt");

  fout1 << "#a "
        << "\t"
        << "#b "
        << "\t"
        << "#chi2"
        << "\t"
        << "cov"
        << "\t"
        << "corr" << endl;
  fout1 << f1->GetParameter(0) << "\t" << f1->GetParError(0) << "\t" << f1->GetParameter(1) << "\t" << f1->GetParError(1) << "\t" << f1->GetChisquare() << "\t"
        << "-0.0005898"
        << "\t"
        << "-0.9791 " << endl;

  TMatrixD cov1 = uno->GetCorrelationMatrix();
  TMatrixD cor1 = uno->GetCovarianceMatrix();
  cov1.Print();
  cor1.Print();

  TLegend *legend1 = new TLegend(0.15, 0.15, 0.5, 0.3);
  legend1->SetHeader("Coniugati", "C");
  legend1->AddEntry(fileInput1, "Dati con errore", "PE");
  legend1->AddEntry(f1, "ax+b", "l");
  legend1->SetTextSize(0.04);
  legend1->SetBorderSize(1);
  legend1->Draw();
  //-----------------------------------------------MARCO------------------------------------------

  c1->cd(2);
  gPad->SetGrid();
  gPad->SetFillColor(0);

  TGraphErrors *fileInput2 = new TGraphErrors("../File/coniugati_marco.txt", "%lg %lg %lg %lg");

  fileInput2->SetMarkerColor(3);
  fileInput2->SetMarkerStyle(20);
  fileInput2->SetMarkerSize(0.8);
  fileInput2->SetTitle("Operatore B");
  fileInput2->GetXaxis()->SetTitle("1/p [1/m]");
  fileInput2->GetYaxis()->SetTitle("1/q [1/m]");
  fileInput2->GetXaxis()->SetAxisColor(14);
  fileInput2->GetYaxis()->SetAxisColor(14);
  fileInput2->GetXaxis()->SetLimits(0, 11.51);
  fileInput2->GetYaxis()->SetRangeUser(3, 15);

  fileInput2->Draw("AP");

  TF1 *f2 = new TF1("f2", func, 3, 12, 2);
  f2->SetParNames("b", "a");

  f2->SetParameter(0, -0.99); //a
  f2->SetParameter(1, 15);    //b

  fileInput2->Fit("f2", "R");
  TFitResultPtr due = fileInput2->Fit("f2", "S");

  ofstream fout2("risultati_fit_m.txt");
  fout2 << "#a "
        << "\t"
        << "#b "
        << "\t"
        << "#chi2"
        << "\t"
        << "cov"
        << "\t"
        << "corr" << endl;
  fout2 << f2->GetParameter(0) << "\t" << f2->GetParError(0) << "\t" << f2->GetParameter(1) << "\t" << f2->GetParError(1) << "\t" << f2->GetChisquare() << "\t"
        << "-0.0002803"
        << "\t"
        << "-0.8529" << endl;

  TMatrixD cov2 = due->GetCorrelationMatrix();
  TMatrixD cor2 = due->GetCovarianceMatrix();
  cov2.Print();
  cor2.Print();

  TLegend *legend2 = new TLegend(0.15, 0.15, 0.5, 0.3);
  legend2->SetHeader("Coniugati", "C");
  legend2->AddEntry(fileInput2, "Dati con errore", "PE");
  legend2->AddEntry(f2, "ax+b", "l");
  legend2->SetTextSize(0.04);
  legend2->SetBorderSize(1);
  legend2->Draw();
  //-----------------------------------------------TOMMASO------------------------------------------

  c1->cd(3);
  gPad->SetGrid();
  gPad->SetFillColor(0);

  TGraphErrors *fileInput3 = new TGraphErrors("../File/coniugati_tommaso.txt", "%lg %lg %lg %lg");

  fileInput3->SetMarkerColor(4);
  fileInput3->SetMarkerStyle(20);
  fileInput3->SetMarkerSize(0.8);
  fileInput3->SetTitle("Operatore C");
  fileInput3->GetXaxis()->SetTitle("1/p [1/m]");
  fileInput3->GetYaxis()->SetTitle("1/q [1/m]");
  fileInput3->GetXaxis()->SetAxisColor(14);
  fileInput3->GetYaxis()->SetAxisColor(14);
    fileInput3->GetXaxis()->SetLimits(0, 11.51);
  fileInput3->GetYaxis()->SetRangeUser(3, 15);

  fileInput3->Draw("AP");

  TF1 *f3 = new TF1("f3", func, 0, 12, 2);
  f3->SetParNames("b", "a");

  f3->SetParameter(0, -0.99); //a
  f3->SetParameter(1, 15);    //b

  fileInput3->Fit("f3", "R");

  TFitResultPtr tre = fileInput3->Fit("f3", "S");

  ofstream fout3("risultati_fit_t.txt");
  fout3 << "#a "
        << "\t"
        << "#b "
        << "\t"
        << "#chi2"
        << "\t"
        << "cov"
        << "\t"
        << "corr" << endl;
  fout3 << f3->GetParameter(0) << "\t" << f3->GetParError(0) << "\t" << f3->GetParameter(1) << "\t" << f3->GetParError(1) << "\t" << f3->GetChisquare() << "\t"
        << "-0.0008088"
        << "\t"
        << "-0.9823 " << endl;

  TMatrixD cov3 = tre->GetCorrelationMatrix();
  TMatrixD cor3 = tre->GetCovarianceMatrix();
  cov3.Print();
  cor3.Print();

  TLegend *legend3 = new TLegend(0.15, 0.15, 0.5, 0.3);
  legend3->SetHeader("Coniugati", "C");
  legend3->AddEntry(fileInput3, "Dati con errore", "PE");
  legend3->AddEntry(f3, "ax+b", "l");
  legend3->SetTextSize(0.04);
  legend3->SetBorderSize(1);
  legend3->Draw();
}
