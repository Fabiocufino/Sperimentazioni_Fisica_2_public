void sferica_misure()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Wed Dec  9 23:02:49 2020) by ROOT version 6.22/02
   TCanvas *c1 = new TCanvas("c1", "Canvas",177,64,1500,900);
   gStyle->SetOptFit(1);
   c1->Range(-0.6168831,2.902529,11.05584,8.614436);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetLeftMargin(0.06141522);
   c1->SetRightMargin(0.01335113);
   c1->SetTopMargin(0.02054795);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1[10] = {
   0.9939919,
   1.994326,
   2.99466,
   3.994993,
   4.995327,
   5.995661,
   6.995995,
   7.996328,
   8.996662,
   9.996996};
   Double_t Graph0_fy1[10] = {
   4.876232,
   6.502527,
   6.645813,
   6.746113,
   7.011193,
   7.175971,
   7.398065,
   6.860742,
   6.839249,
   7.734787};
   TGraph *graph = new TGraph(10,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Operatore A");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Operatore A",100,0.1,10.9);
   Graph_Graph01->SetMinimum(3.476328);
   Graph_Graph01->SetMaximum(8.497068);
   Graph_Graph01->SetDirectory(0);
   Graph_Graph01->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01->SetLineColor(ci);
   Graph_Graph01->GetXaxis()->SetTitle("Numero della misurazione");
   Graph_Graph01->GetXaxis()->SetAxisColor(14);
   Graph_Graph01->GetXaxis()->SetLabelFont(42);
   Graph_Graph01->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01->GetXaxis()->SetTitleFont(42);
   Graph_Graph01->GetYaxis()->SetTitle("L [1/m]");
   Graph_Graph01->GetYaxis()->SetAxisColor(14);
   Graph_Graph01->GetYaxis()->SetLabelFont(42);
   Graph_Graph01->GetYaxis()->SetTitleFont(42);
   Graph_Graph01->GetZaxis()->SetLabelFont(42);
   Graph_Graph01->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph01);
   
   graph->Draw("APL");
   
   Double_t Graph1_fx2[10] = {
   1,
   1.994326,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10};
   Double_t Graph1_fy2[10] = {
   5.37,
   6.237448,
   6.295,
   6.24,
   6,
   6.05,
   6.9,
   6.2,
   6.59,
   6.485};
   graph = new TGraph(10,Graph1_fx2,Graph1_fy2);
   graph->SetName("Graph1");
   graph->SetTitle("Operatore B");
   graph->SetFillStyle(1000);
   graph->SetLineColor(3);
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(3);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","Operatore B",100,0.1,10.9);
   Graph_Graph12->SetMinimum(5.217);
   Graph_Graph12->SetMaximum(7.053);
   Graph_Graph12->SetDirectory(0);
   Graph_Graph12->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph12->SetLineColor(ci);
   Graph_Graph12->GetXaxis()->SetTitle("Numero della misurazione");
   Graph_Graph12->GetXaxis()->SetAxisColor(14);
   Graph_Graph12->GetXaxis()->SetLabelFont(42);
   Graph_Graph12->GetXaxis()->SetTitleOffset(1);
   Graph_Graph12->GetXaxis()->SetTitleFont(42);
   Graph_Graph12->GetYaxis()->SetTitle("l [1/m]");
   Graph_Graph12->GetYaxis()->SetAxisColor(14);
   Graph_Graph12->GetYaxis()->SetLabelFont(42);
   Graph_Graph12->GetYaxis()->SetTitleFont(42);
   Graph_Graph12->GetZaxis()->SetLabelFont(42);
   Graph_Graph12->GetZaxis()->SetTitleOffset(1);
   Graph_Graph12->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph12);
   
   graph->Draw("PL");
   
   Double_t Graph2_fx3[10] = {
   0.9939919,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10};
   Double_t Graph2_fy3[10] = {
   4.568167,
   4.33,
   5.275,
   5.875,
   4.735,
   5.975,
   4.92,
   4.125,
   4.62,
   4.615};
   graph = new TGraph(10,Graph2_fx3,Graph2_fy3);
   graph->SetName("Graph2");
   graph->SetTitle("Operatore C");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(4);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph23 = new TH1F("Graph_Graph23","Operatore C",100,0.1,10.9);
   Graph_Graph23->SetMinimum(3.94);
   Graph_Graph23->SetMaximum(6.16);
   Graph_Graph23->SetDirectory(0);
   Graph_Graph23->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph23->SetLineColor(ci);
   Graph_Graph23->GetXaxis()->SetTitle("Numero della misurazione");
   Graph_Graph23->GetXaxis()->SetAxisColor(14);
   Graph_Graph23->GetXaxis()->SetLabelFont(42);
   Graph_Graph23->GetXaxis()->SetTitleOffset(1);
   Graph_Graph23->GetXaxis()->SetTitleFont(42);
   Graph_Graph23->GetYaxis()->SetTitle(" [1/m]");
   Graph_Graph23->GetYaxis()->SetAxisColor(14);
   Graph_Graph23->GetYaxis()->SetLabelFont(42);
   Graph_Graph23->GetYaxis()->SetTitleFont(42);
   Graph_Graph23->GetZaxis()->SetLabelFont(42);
   Graph_Graph23->GetZaxis()->SetTitleOffset(1);
   Graph_Graph23->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph23);
   
   graph->Draw("PL");
   
   TLegend *leg = new TLegend(0.1068091,0.7328767,0.3497997,0.9452055,NULL,"brNDC");
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
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Operatore B","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(3);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2","Operatore C","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
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
