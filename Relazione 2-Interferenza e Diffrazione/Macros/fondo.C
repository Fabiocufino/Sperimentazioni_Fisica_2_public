void fondo()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Sat Dec 26 13:15:17 2020) by ROOT version 6.22/06
   TCanvas *c1 = new TCanvas("c1", "Canvas",36,97,2000,900);
   gStyle->SetOptFit(1);
   c1->Range(7780.875,-24.08663,8032.125,216.7797);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetTopMargin(0.01942857);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *Istogramma__1__1 = new TH1D("Parametri Istogramma e Fit","Analsi Del Fondo",100,7800,8100);
   Istogramma__1__1->SetBinContent(7,2);
   Istogramma__1__1->SetBinContent(8,3);
   Istogramma__1__1->SetBinContent(9,14);
   Istogramma__1__1->SetBinContent(10,26);
   Istogramma__1__1->SetBinContent(11,71);
   Istogramma__1__1->SetBinContent(12,98);
   Istogramma__1__1->SetBinContent(13,153);
   Istogramma__1__1->SetBinContent(14,187);
   Istogramma__1__1->SetBinContent(15,202);
   Istogramma__1__1->SetBinContent(16,178);
   Istogramma__1__1->SetBinContent(17,140);
   Istogramma__1__1->SetBinContent(18,86);
   Istogramma__1__1->SetBinContent(19,53);
   Istogramma__1__1->SetBinContent(20,37);
   Istogramma__1__1->SetBinContent(21,19);
   Istogramma__1__1->SetBinContent(22,8);
   Istogramma__1__1->SetBinContent(23,1);
   Istogramma__1__1->SetBinContent(24,1);
   Istogramma__1__1->SetBinContent(101,2);
   Istogramma__1__1->SetEntries(1281);
   
   TF1 *gaus1 = new TF1("gaus","gaus",7800,8100, TF1::EAddToList::kNo);
   gaus1->SetNpx(400);
   gaus1->SetFillColor(19);
   gaus1->SetFillStyle(0);
   gaus1->SetLineColor(2);
   gaus1->SetLineWidth(2);
   gaus1->SetLineStyle(2);
   gaus1->SetChisquare(12.66799);
   gaus1->SetNDF(15);
   gaus1->GetXaxis()->SetLabelFont(42);
   gaus1->GetXaxis()->SetTitleOffset(1);
   gaus1->GetXaxis()->SetTitleFont(42);
   gaus1->GetYaxis()->SetLabelFont(42);
   gaus1->GetYaxis()->SetTitleFont(42);
   gaus1->SetParameter(0,195.8543);
   gaus1->SetParError(0,6.844006);
   gaus1->SetParLimits(0,0,0);
   gaus1->SetParameter(1,7843.393);
   gaus1->SetParError(1,0.2212928);
   gaus1->SetParLimits(1,0,0);
   gaus1->SetParameter(2,7.742817);
   gaus1->SetParError(2,0.1619098);
   gaus1->SetParLimits(2,0,78.47481);
   gaus1->SetParent(Istogramma__1__1);
   Istogramma__1__1->GetListOfFunctions()->Add(gaus1);
   
   TPaveStats *ptstats = new TPaveStats(0.6296296,0.6342857,0.9094094,0.9977143,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   TText *ptstats_LaTex = ptstats->AddText("Istogramma__1");
   ptstats_LaTex->SetTextSize(0.0477649);
   ptstats_LaTex = ptstats->AddText("Entries = 1281   ");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  7.847");
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 12.67 / 15");
   ptstats_LaTex = ptstats->AddText("Constant = 195.9 ");
   ptstats_LaTex = ptstats->AddText("Mean     =  7843 ");
   ptstats_LaTex = ptstats->AddText("Sigma    = 7.743 ");
   ptstats->SetOptStat(1011);
   ptstats->SetOptFit(101);
   ptstats->Draw();
   Istogramma__1__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Istogramma__1__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0066ff");
   Istogramma__1__1->SetFillColor(ci);

   ci = TColor::GetColor("#0066ff");
   Istogramma__1__1->SetLineColor(ci);
   Istogramma__1__1->GetXaxis()->SetTitle("Passi Motore");
   Istogramma__1__1->GetXaxis()->SetRange(3,69);
   Istogramma__1__1->GetXaxis()->SetLabelFont(22);
   Istogramma__1__1->GetXaxis()->SetTitleOffset(1);
   Istogramma__1__1->GetXaxis()->SetTitleFont(22);
   Istogramma__1__1->GetYaxis()->SetTitle("Frequenza Assoluta");
   Istogramma__1__1->GetYaxis()->SetLabelFont(22);
   Istogramma__1__1->GetYaxis()->SetTitleFont(22);
   Istogramma__1__1->GetZaxis()->SetLabelFont(42);
   Istogramma__1__1->GetZaxis()->SetTitleOffset(1);
   Istogramma__1__1->GetZaxis()->SetTitleFont(42);
   Istogramma__1__1->Draw("");
   TLine *line = new TLine(7931,0,7931,190);

   ci = TColor::GetColor("#0066ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   line = new TLine(7928.003,0.1376374,7928.003,190.0779);
   line->SetLineColor(2);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(7917.692,183.196,"+11#sigma");
   tex->SetTextFont(32);
   tex->SetTextSize(0.04342857);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(7935.045,46.65925,"Minimo N'5 = 7931");
   tex->SetTextFont(32);
   tex->SetTextSize(0.04571429);
   tex->SetTextAngle(90);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TPaveText *pt = new TPaveText(0.3984084,0.94,0.6015916,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
