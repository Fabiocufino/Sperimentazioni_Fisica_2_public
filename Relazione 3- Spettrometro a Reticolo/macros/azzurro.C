void azzurro()
{
//=========Macro generated from canvas: c2/Canvas
//=========  (Thu Dec 31 12:30:21 2020) by ROOT version 6.22/06
   TCanvas *c2 = new TCanvas("c2", "Canvas",842,107,700,600);
   c2->Range(-6.007947,-0.8068493,5.086093,0.7289178);
   c2->SetFillColor(0);
   c2->SetBorderMode(0);
   c2->SetBorderSize(2);
   c2->SetGridx();
   c2->SetGridy();
   c2->SetRightMargin(0.02578797);
   c2->SetTopMargin(0.02434783);
   c2->SetBottomMargin(0.07478261);
   c2->SetFrameBorderMode(0);
   c2->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1005[8] = {
   4,
   3,
   2,
   0.9854305,
   -1,
   -2,
   -3,
   -4};
   Double_t Graph0_fy1005[8] = {
   0.5759568,
   0.4318234,
   0.2879177,
   0.1466618,
   -0.1434926,
   -0.2879177,
   -0.4326103,
   -0.5764323};
   Double_t Graph0_fex1005[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1005[8] = {
   0.0002745824,
   0.0003029576,
   0.0003216656,
   0.0003323847,
   0.0003324128,
   0.0003216656,
   0.0003028309,
   0.0002744698};
   TGraphErrors *gre = new TGraphErrors(8,Graph0_fx1005,Graph0_fy1005,Graph0_fex1005,Graph0_fey1005);
   gre->SetName("Graph0");
   gre->SetTitle("Azzurro");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0066ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph01005 = new TH1F("Graph_Graph01005","Azzurro",100,-4.8,4.8);
   Graph_Graph01005->SetMinimum(-0.6920006);
   Graph_Graph01005->SetMaximum(0.6915252);
   Graph_Graph01005->SetDirectory(0);
   Graph_Graph01005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph01005->SetLineColor(ci);
   Graph_Graph01005->GetXaxis()->SetTitle("Ordine");
   Graph_Graph01005->GetXaxis()->SetAxisColor(14);
   Graph_Graph01005->GetXaxis()->SetLabelFont(22);
   Graph_Graph01005->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01005->GetXaxis()->SetTitleFont(22);
   Graph_Graph01005->GetYaxis()->SetTitle("sin(#theta)  [rad]");
   Graph_Graph01005->GetYaxis()->SetAxisColor(14);
   Graph_Graph01005->GetYaxis()->SetLabelFont(22);
   Graph_Graph01005->GetYaxis()->SetTitleFont(22);
   Graph_Graph01005->GetZaxis()->SetLabelFont(42);
   Graph_Graph01005->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01005);
   
   
   TF1 *f21006 = new TF1("f2","pol1",-4.8,4.8, TF1::EAddToList::kNo);
   f21006->SetFillColor(19);
   f21006->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   f21006->SetLineColor(ci);
   f21006->SetLineWidth(1);
   f21006->SetLineStyle(2);
   f21006->SetChisquare(7.246845);
   f21006->SetNDF(6);
   f21006->GetXaxis()->SetLabelFont(42);
   f21006->GetXaxis()->SetTitleOffset(1);
   f21006->GetXaxis()->SetTitleFont(42);
   f21006->GetYaxis()->SetLabelFont(42);
   f21006->GetYaxis()->SetTitleFont(42);
   f21006->SetParameter(0,-0.000112836);
   f21006->SetParError(0,0.0001079785);
   f21006->SetParLimits(0,0,0);
   f21006->SetParameter(1,0.1440387);
   f21006->SetParError(1,3.736606e-05);
   f21006->SetParLimits(1,0,0);
   f21006->SetParent(gre);
   gre->GetListOfFunctions()->Add(f21006);
   gre->Draw("ap");
   
   TLegend *leg = new TLegend(0.1561605,0.7773913,0.5071633,0.9269565,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","Legenda","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextAlign(22);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","Dati con errore","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0066ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("f2","a+bx interpolante","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveStats *ptstats = new TPaveStats(0.4856734,0.1113043,0.9527221,0.3982609,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 7.247 / 6");
   ptstats_LaTex = ptstats->AddText("a        = -0.0001128 #pm 0.000108 ");
   ptstats_LaTex = ptstats->AddText("b        = 0.144 #pm 3.737e-05 ");
   ptstats_LaTex = ptstats->AddText("Pearson        =  0.9999997");
   ptstats_LaTex = ptstats->AddText("T_Student        = 3184");
   ptstats_LaTex = ptstats->AddText("#sigma_{post}        =  0.000350");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   TPaveText *pt = new TPaveText(0.3137536,0.5530435,0.4928367,0.6086957,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt->Draw();
   c2->Modified();
   c2->cd();
   c2->SetSelected(c2);
}
