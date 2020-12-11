void sferica()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Fri Dec 11 19:09:40 2020) by ROOT version 6.22/02
   TCanvas *c1 = new TCanvas("c1", "Canvas",231,48,1500,900);
   c1->Range(-0.7249282,2.397316,11.0788,8.943949);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetLeftMargin(0.06141521);
   c1->SetRightMargin(0.006675566);
   c1->SetTopMargin(0.005707762);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[10] = {
   1,
   2,
   3,
   3.994986,
   5,
   6,
   7,
   8,
   9,
   10};
   Double_t Graph0_fy1001[10] = {
   4.875,
   6.5,
   6.64,
   6.745877,
   7.01,
   7.175,
   7.395,
   6.86,
   6.835,
   7.73};
   Double_t Graph0_fex1001[10] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[10] = {
   0.762127,
   0.762127,
   0.762127,
   0.762127,
   0.762127,
   0.762127,
   0.762127,
   0.762127,
   0.762127,
   0.762127};
   TGraphErrors *gre = new TGraphErrors(10,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Operatore A");
   gre->SetFillStyle(1000);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","Operatore A",100,0,11);
   Graph_Graph01001->SetMinimum(3.054968);
   Graph_Graph01001->SetMaximum(8.906582);
   Graph_Graph01001->SetDirectory(0);
   Graph_Graph01001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01001->SetLineColor(ci);
   Graph_Graph01001->GetXaxis()->SetTitle("Numero della misurazione");
   Graph_Graph01001->GetXaxis()->SetAxisColor(14);
   Graph_Graph01001->GetXaxis()->SetLabelFont(22);
   Graph_Graph01001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetXaxis()->SetTitleFont(22);
   Graph_Graph01001->GetYaxis()->SetTitle("L [1/m]");
   Graph_Graph01001->GetYaxis()->SetAxisColor(14);
   Graph_Graph01001->GetYaxis()->SetLabelFont(22);
   Graph_Graph01001->GetYaxis()->SetTitleFont(22);
   Graph_Graph01001->GetZaxis()->SetLabelFont(42);
   Graph_Graph01001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01001);
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1002[10] = {
   1.1,
   2.1,
   3.096705,
   4.097421,
   5.1,
   6.1,
   7.1,
   8.1,
   9.1,
   10.1};
   Double_t Graph1_fy1002[10] = {
   5.37,
   6.235,
   6.299568,
   6.242893,
   6,
   6.05,
   6.9,
   6.2,
   6.59,
   6.485};
   Double_t Graph1_fex1002[10] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph1_fey1002[10] = {
   0.404592,
   0.404592,
   0.404592,
   0.404592,
   0.404592,
   0.404592,
   0.404592,
   0.404592,
   0.404592,
   0.404592};
   gre = new TGraphErrors(10,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Operatore B");
   gre->SetFillStyle(1000);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph11002 = new TH1F("Graph_Graph11002","Operatore B",100,0,11);
   Graph_Graph11002->SetMinimum(4.73149);
   Graph_Graph11002->SetMaximum(7.53851);
   Graph_Graph11002->SetDirectory(0);
   Graph_Graph11002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph11002->SetLineColor(ci);
   Graph_Graph11002->GetXaxis()->SetTitle("Numero della misurazione");
   Graph_Graph11002->GetXaxis()->SetAxisColor(14);
   Graph_Graph11002->GetXaxis()->SetLabelFont(42);
   Graph_Graph11002->GetXaxis()->SetTitleOffset(1);
   Graph_Graph11002->GetXaxis()->SetTitleFont(42);
   Graph_Graph11002->GetYaxis()->SetTitle("l [1/m]");
   Graph_Graph11002->GetYaxis()->SetAxisColor(14);
   Graph_Graph11002->GetYaxis()->SetLabelFont(42);
   Graph_Graph11002->GetYaxis()->SetTitleFont(42);
   Graph_Graph11002->GetZaxis()->SetLabelFont(42);
   Graph_Graph11002->GetZaxis()->SetTitleOffset(1);
   Graph_Graph11002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph11002);
   
   gre->Draw("p");
   
   Double_t Graph2_fx1003[10] = {
   1.2,
   2.198424,
   3.199141,
   4.2,
   5.2,
   6.2,
   7.2,
   8.2,
   9.2,
   10.2};
   Double_t Graph2_fy1003[10] = {
   4.565,
   4.330138,
   5.279432,
   5.875,
   4.735,
   5.975,
   4.92,
   4.125,
   4.62,
   4.615};
   Double_t Graph2_fex1003[10] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fey1003[10] = {
   0.621088,
   0.621088,
   0.621088,
   0.621088,
   0.621088,
   0.621088,
   0.621088,
   0.621088,
   0.621088,
   0.621088};
   gre = new TGraphErrors(10,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Operatore C");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#3366ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0066ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph21003 = new TH1F("Graph_Graph21003","Operatore C",100,0.3,11.1);
   Graph_Graph21003->SetMinimum(3.194694);
   Graph_Graph21003->SetMaximum(6.905306);
   Graph_Graph21003->SetDirectory(0);
   Graph_Graph21003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph21003->SetLineColor(ci);
   Graph_Graph21003->GetXaxis()->SetTitle("Numero della misurazione");
   Graph_Graph21003->GetXaxis()->SetAxisColor(14);
   Graph_Graph21003->GetXaxis()->SetLabelFont(42);
   Graph_Graph21003->GetXaxis()->SetTitleOffset(1);
   Graph_Graph21003->GetXaxis()->SetTitleFont(42);
   Graph_Graph21003->GetYaxis()->SetTitle(" [1/m]");
   Graph_Graph21003->GetYaxis()->SetAxisColor(14);
   Graph_Graph21003->GetYaxis()->SetLabelFont(42);
   Graph_Graph21003->GetYaxis()->SetTitleFont(42);
   Graph_Graph21003->GetZaxis()->SetLabelFont(42);
   Graph_Graph21003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph21003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph21003);
   
   gre->Draw("p");
   
   TLegend *leg = new TLegend(0.09078772,0.7739726,0.3344459,0.966895,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","Aberrazione sferica","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextAlign(22);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","Operatore A","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Operatore B","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(3);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2","Operatore C","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0066ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.4032176,0.934726,0.5967824,0.995,"blNDC");
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
