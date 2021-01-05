void verde()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Thu Dec 31 12:29:21 2020) by ROOT version 6.22/06
   TCanvas *c1 = new TCanvas("c1", "Canvas",967,240,700,600);
   c1->Range(-5.990083,-0.8585931,5.08562,0.7694394);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetRightMargin(0.02578797);
   c1->SetTopMargin(0.0226087);
   c1->SetBottomMargin(0.07652174);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1003[8] = {
   4,
   3,
   1.991405,
   1,
   -1,
   -2,
   -3,
   -4};
   Double_t Graph0_fy1003[8] = {
   0.6101452,
   0.4576153,
   0.3079276,
   0.1529858,
   -0.1526984,
   -0.3054183,
   -0.4578739,
   -0.611527};
   Double_t Graph0_fex1003[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1003[8] = {
   0.0002661212,
   0.0002986556,
   0.0003198394,
   0.0003319348,
   0.0003319498,
   0.0003198394,
   0.0002986109,
   0.0002657631};
   TGraphErrors *gre = new TGraphErrors(8,Graph0_fx1003,Graph0_fy1003,Graph0_fex1003,Graph0_fey1003);
   gre->SetName("Graph0");
   gre->SetTitle("Verde");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0066ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph_Graph010011003 = new TH1F("Graph_Graph_Graph010011003","Verde",100,-4.8,4.8);
   Graph_Graph_Graph010011003->SetMinimum(-0.7340132);
   Graph_Graph_Graph010011003->SetMaximum(0.7326317);
   Graph_Graph_Graph010011003->SetDirectory(0);
   Graph_Graph_Graph010011003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph010011003->SetLineColor(ci);
   Graph_Graph_Graph010011003->GetXaxis()->SetTitle("Ordine");
   Graph_Graph_Graph010011003->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph010011003->GetXaxis()->SetLabelFont(22);
   Graph_Graph_Graph010011003->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010011003->GetXaxis()->SetTitleFont(22);
   Graph_Graph_Graph010011003->GetYaxis()->SetTitle("sin(#theta)  [rad]");
   Graph_Graph_Graph010011003->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph010011003->GetYaxis()->SetLabelFont(22);
   Graph_Graph_Graph010011003->GetYaxis()->SetTitleFont(22);
   Graph_Graph_Graph010011003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph010011003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010011003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph010011003);
   
   
   TF1 *f11004 = new TF1("f1","pol1",-4.8,4.8, TF1::EAddToList::kNo);
   f11004->SetFillColor(19);
   f11004->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   f11004->SetLineColor(ci);
   f11004->SetLineWidth(1);
   f11004->SetLineStyle(2);
   f11004->SetChisquare(12.68537);
   f11004->SetNDF(6);
   f11004->GetXaxis()->SetLabelFont(42);
   f11004->GetXaxis()->SetTitleOffset(1);
   f11004->GetXaxis()->SetTitleFont(42);
   f11004->GetYaxis()->SetLabelFont(42);
   f11004->GetYaxis()->SetTitleFont(42);
   f11004->SetParameter(0,-0.0002243417);
   f11004->SetParError(0,0.0001063549);
   f11004->SetParLimits(0,0,0);
   f11004->SetParameter(1,0.1526781);
   f11004->SetParError(1,3.649914e-05);
   f11004->SetParLimits(1,0,0);
   f11004->SetParent(gre);
   gre->GetListOfFunctions()->Add(f11004);
   gre->Draw("ap");
   
   TLegend *leg = new TLegend(0.1819484,0.7895652,0.5329513,0.9391304,NULL,"brNDC");
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
   entry=leg->AddEntry("f1","a+bx interpolante","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveStats *ptstats = new TPaveStats(0.4856734,0.12,0.9541547,0.4034783,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 12.69 / 6");
   ptstats_LaTex = ptstats->AddText("a        = -0.0002243 #pm 0.0001064 ");
   ptstats_LaTex = ptstats->AddText("b        = 0.1527 #pm 3.65e-05 ");
   ptstats_LaTex = ptstats->AddText("Pearson        = 0.9999996");
   ptstats_LaTex = ptstats->AddText("T_Student        = 2813");
   ptstats_LaTex = ptstats->AddText("#sigma_{post}        = 0.000420 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   TPaveText *pt = new TPaveText(0.2063037,0.5217391,0.3452722,0.5773913,"blNDC");
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
