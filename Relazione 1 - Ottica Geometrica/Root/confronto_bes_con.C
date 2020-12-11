void confronto_bes_con()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Thu Dec 10 00:09:55 2020) by ROOT version 6.22/02
   TCanvas *c1 = new TCanvas("c1", "Canvas",970,566,920,484);
   gStyle->SetOptFit(1);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: c1_1
   TPad *c1_1 = new TPad("c1_1", "c1_1",1e-05,1e-05,0.49999,0.99999);
   c1_1->Draw();
   c1_1->cd();
   c1_1->Range(63.5,-1.875,68.5,16.875);
   c1_1->SetFillColor(0);
   c1_1->SetBorderMode(0);
   c1_1->SetBorderSize(2);
   c1_1->SetGridx();
   c1_1->SetGridy();
   c1_1->SetFrameBorderMode(0);
   c1_1->SetFrameBorderMode(0);
   
   TH1D *Coniugati__4 = new TH1D("Coniugati","",20,64,68);
   Coniugati__4->SetBinContent(4,1);
   Coniugati__4->SetBinContent(7,3);
   Coniugati__4->SetBinContent(8,2);
   Coniugati__4->SetBinContent(9,8);
   Coniugati__4->SetBinContent(10,9);
   Coniugati__4->SetBinContent(11,8);
   Coniugati__4->SetBinContent(12,9);
   Coniugati__4->SetBinContent(13,7);
   Coniugati__4->SetBinContent(14,5);
   Coniugati__4->SetBinContent(15,4);
   Coniugati__4->SetBinContent(16,3);
   Coniugati__4->SetBinContent(17,2);
   Coniugati__4->SetBinContent(18,1);
   Coniugati__4->SetBinContent(21,62);
   Coniugati__4->SetMinimum(0);
   Coniugati__4->SetMaximum(15);
   Coniugati__4->SetEntries(124);
   
   TPaveStats *ptstats = new TPaveStats(0.6470647,0.6619698,0.9695177,0.9250185,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("Coniugati");
   ptstats_LaTex->SetTextSize(0.06050121);
   ptstats_LaTex = ptstats->AddText("Entries = 62    ");
   ptstats_LaTex = ptstats->AddText("Mean  =  66.23");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.5413");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   Coniugati__4->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Coniugati__4);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = 1197;
   color = new TColor(ci, 1, 0, 0, " ", 0.65);
   Coniugati__4->SetFillColor(ci);
   Coniugati__4->GetXaxis()->SetTitle("f_{i} [mm]");
   Coniugati__4->GetXaxis()->SetLabelFont(42);
   Coniugati__4->GetXaxis()->SetTitleOffset(1);
   Coniugati__4->GetXaxis()->SetTitleFont(42);
   Coniugati__4->GetYaxis()->SetTitle("frequenza");
   Coniugati__4->GetYaxis()->SetLabelFont(42);
   Coniugati__4->GetYaxis()->SetTitleFont(42);
   Coniugati__4->GetZaxis()->SetLabelFont(42);
   Coniugati__4->GetZaxis()->SetTitleOffset(1);
   Coniugati__4->GetZaxis()->SetTitleFont(42);
   Coniugati__4->Draw("");
   
   TLegend *leg = new TLegend(0.1372404,0.7195696,0.4880169,0.8695726,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","Punti Coniugati","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextAlign(22);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Coniugati","Istogramma","F");

   ci = 1197;
   color = new TColor(ci, 1, 0, 0, " ", 0.65);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1_1->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_2
   TPad *c1_2 = new TPad("c1_2", "c1_2",0.50001,1e-05,0.99999,0.99999);
   c1_2->Draw();
   c1_2->cd();
   c1_2->Range(63.5,-1.675881,68.5,16.8696);
   c1_2->SetFillColor(0);
   c1_2->SetBorderMode(0);
   c1_2->SetBorderSize(2);
   c1_2->SetGridx();
   c1_2->SetGridy();
   c1_2->SetFrameBorderMode(0);
   c1_2->SetFrameBorderMode(0);
   
   TH1D *Bessel__5 = new TH1D("Bessel","",20,64,68);
   Bessel__5->SetBinContent(8,2);
   Bessel__5->SetBinContent(9,2);
   Bessel__5->SetBinContent(10,1);
   Bessel__5->SetBinContent(11,11);
   Bessel__5->SetBinContent(12,5);
   Bessel__5->SetBinContent(13,2);
   Bessel__5->SetBinContent(14,5);
   Bessel__5->SetBinContent(15,3);
   Bessel__5->SetMinimum(0.1786672);
   Bessel__5->SetMaximum(15.01505);
   Bessel__5->SetEntries(31);
   
   ptstats = new TPaveStats(0.6492434,0.6565249,0.9499091,0.9173997,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("Bessel");
   ptstats_LaTex->SetTextSize(0.0600012);
   ptstats_LaTex = ptstats->AddText("Entries = 31     ");
   ptstats_LaTex = ptstats->AddText("Mean  =  66.27");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.3693");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   Bessel__5->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Bessel__5);

   ci = 1198;
   color = new TColor(ci, 0, 0, 1, " ", 0.65);
   Bessel__5->SetFillColor(ci);
   Bessel__5->GetXaxis()->SetTitle("f_{i} [mm]");
   Bessel__5->GetXaxis()->SetLabelFont(42);
   Bessel__5->GetXaxis()->SetTitleOffset(1);
   Bessel__5->GetXaxis()->SetTitleFont(42);
   Bessel__5->GetYaxis()->SetTitle("frequenza");
   Bessel__5->GetYaxis()->SetLabelFont(42);
   Bessel__5->GetYaxis()->SetTitleFont(42);
   Bessel__5->GetZaxis()->SetLabelFont(42);
   Bessel__5->GetZaxis()->SetTitleOffset(1);
   Bessel__5->GetZaxis()->SetTitleFont(42);
   Bessel__5->Draw("");
   
   leg = new TLegend(0.1307042,0.7065259,0.4814807,0.8565289,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","Bessel","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextAlign(22);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Bessel","Istogramma","F");

   ci = 1198;
   color = new TColor(ci, 0, 0, 1, " ", 0.65);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1_2->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
