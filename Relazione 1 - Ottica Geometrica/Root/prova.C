void prova()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Wed Dec  9 22:54:22 2020) by ROOT version 6.22/02
   TCanvas *c1 = new TCanvas("c1", "Canvas",137,84,2000,900);
   gStyle->SetOptFit(1);
   c1->Range(-53.68367,-1.977175,713.0475,17.70471);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetLeftMargin(0.06056056);
   c1->SetRightMargin(0.01701702);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *ParametrisPIstogramma__1 = new TH1D("ParametrisPIstogramma__1","Aberrazione Cromatica",40,10,700);
   ParametrisPIstogramma__1->SetBinContent(2,7);
   ParametrisPIstogramma__1->SetBinContent(3,15);
   ParametrisPIstogramma__1->SetBinContent(4,6);
   ParametrisPIstogramma__1->SetBinContent(5,2);
   ParametrisPIstogramma__1->SetBinContent(6,1);
   ParametrisPIstogramma__1->SetBinContent(8,1);
   ParametrisPIstogramma__1->SetBinContent(13,1);
   ParametrisPIstogramma__1->SetBinContent(38,1);
   ParametrisPIstogramma__1->SetEntries(34);
   
   TF1 *gaus1 = new TF1("gaus","gaus",-7.25,700, TF1::EAddToList::kNo);
   gaus1->SetFillColor(19);
   gaus1->SetFillStyle(0);
   gaus1->SetLineColor(2);
   gaus1->SetLineWidth(2);
   gaus1->SetChisquare(4.651843);
   gaus1->SetNDF(5);
   gaus1->GetXaxis()->SetLabelFont(42);
   gaus1->GetXaxis()->SetTitleOffset(1);
   gaus1->GetXaxis()->SetTitleFont(42);
   gaus1->GetYaxis()->SetLabelFont(42);
   gaus1->GetYaxis()->SetTitleFont(42);
   gaus1->SetParameter(0,12.77797);
   gaus1->SetParError(0,4.10312);
   gaus1->SetParLimits(0,0,0);
   gaus1->SetParameter(1,52.88699);
   gaus1->SetParError(1,3.625121);
   gaus1->SetParLimits(1,0,0);
   gaus1->SetParameter(2,16.70805);
   gaus1->SetParError(2,5.644227);
   gaus1->SetParLimits(2,0,1061.617);
   gaus1->SetParent(ParametrisPIstogramma__1);
   ParametrisPIstogramma__1->GetListOfFunctions()->Add(gaus1);
   
   TPaveStats *ptstats = new TPaveStats(0.7132132,0.5844749,0.9944945,0.9372146,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("Parametri Istogramma");
   ptstats_LaTex->SetTextSize(0.04056507);
   ptstats_LaTex = ptstats->AddText("Entries = 34     ");
   ptstats_LaTex = ptstats->AddText("Mean  =  81.54");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  106.2");
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 4.652 / 5");
   ptstats_LaTex = ptstats->AddText("Constant = 12.78 #pm 4.10 ");
   ptstats_LaTex = ptstats->AddText("Mean     = 52.89 #pm 3.63 ");
   ptstats_LaTex = ptstats->AddText("Sigma    = 16.71 #pm 5.64 ");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(1);
   ptstats->Draw();
   ParametrisPIstogramma__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(ParametrisPIstogramma__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = 1180;
   color = new TColor(ci, 1, 0, 0, " ", 0.65);
   ParametrisPIstogramma__1->SetFillColor(ci);
   ParametrisPIstogramma__1->GetXaxis()->SetTitle("v_{i}");
   ParametrisPIstogramma__1->GetXaxis()->SetRange(0,40);
   ParametrisPIstogramma__1->GetXaxis()->SetLabelFont(42);
   ParametrisPIstogramma__1->GetXaxis()->SetTitleOffset(1);
   ParametrisPIstogramma__1->GetXaxis()->SetTitleFont(42);
   ParametrisPIstogramma__1->GetYaxis()->SetTitle("frequenza");
   ParametrisPIstogramma__1->GetYaxis()->SetLabelFont(42);
   ParametrisPIstogramma__1->GetYaxis()->SetTitleFont(42);
   ParametrisPIstogramma__1->GetZaxis()->SetLabelFont(42);
   ParametrisPIstogramma__1->GetZaxis()->SetTitleOffset(1);
   ParametrisPIstogramma__1->GetZaxis()->SetTitleFont(42);
   ParametrisPIstogramma__1->Draw("");
   TLine *line = new TLine(103.02,0,103.02,14);
   line->SetLineColor(2);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   line = new TLine(2.76,0,2.76,14);
   line->SetLineColor(2);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   
   TLegend *leg = new TLegend(0.2112112,0.7420091,0.2832833,0.8047945,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("TLine","+3#sigma","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.3668769,0.94,0.6331231,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Aberrazione Cromatica");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
