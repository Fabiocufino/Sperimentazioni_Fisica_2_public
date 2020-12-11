void istogramma_confronto_bes_con()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Fri Dec 11 17:53:11 2020) by ROOT version 6.22/02
   TCanvas *c1 = new TCanvas("c1", "Canvas",320,237,920,484);
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
   c1_1->Range(63.47404,-1.920793,68.02969,16.87992);
   c1_1->SetFillColor(0);
   c1_1->SetBorderMode(0);
   c1_1->SetBorderSize(2);
   c1_1->SetGridx();
   c1_1->SetGridy();
   c1_1->SetLeftMargin(0.115453);
   c1_1->SetRightMargin(0.006516208);
   c1_1->SetFrameBorderMode(0);
   c1_1->SetFrameBorderMode(0);
   
   TH1D *Coniugati__1 = new TH1D("Coniugati__1","",20,64,68);
   Coniugati__1->SetBinContent(4,1);
   Coniugati__1->SetBinContent(7,3);
   Coniugati__1->SetBinContent(8,2);
   Coniugati__1->SetBinContent(9,8);
   Coniugati__1->SetBinContent(10,9);
   Coniugati__1->SetBinContent(11,8);
   Coniugati__1->SetBinContent(12,9);
   Coniugati__1->SetBinContent(13,7);
   Coniugati__1->SetBinContent(14,5);
   Coniugati__1->SetBinContent(15,4);
   Coniugati__1->SetBinContent(16,3);
   Coniugati__1->SetBinContent(17,2);
   Coniugati__1->SetBinContent(18,1);
   Coniugati__1->SetBinContent(21,62);
   Coniugati__1->SetMinimum(0);
   Coniugati__1->SetMaximum(15);
   Coniugati__1->SetEntries(124);
   
   TPaveStats *ptstats = new TPaveStats(0.6470647,0.6619698,0.9695177,0.9250185,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   TText *ptstats_LaTex = ptstats->AddText("Coniugati");
   ptstats_LaTex->SetTextSize(0.0605012);
   ptstats_LaTex = ptstats->AddText("Entries = 124    ");
   ptstats_LaTex = ptstats->AddText("Mean  =  66.22");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.5534");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   Coniugati__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Coniugati__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = 1197;
   color = new TColor(ci, 1, 0, 0, " ", 0.65);
   Coniugati__1->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   Coniugati__1->SetLineColor(ci);
   Coniugati__1->GetXaxis()->SetTitle("f_{i} [mm]");
   Coniugati__1->GetXaxis()->SetLabelFont(22);
   Coniugati__1->GetXaxis()->SetTitleSize(0.05);
   Coniugati__1->GetXaxis()->SetTitleOffset(1);
   Coniugati__1->GetXaxis()->SetTitleFont(22);
   Coniugati__1->GetYaxis()->SetTitle("frequenza");
   Coniugati__1->GetYaxis()->SetLabelFont(22);
   Coniugati__1->GetYaxis()->SetTitleSize(0.05);
   Coniugati__1->GetYaxis()->SetTitleFont(22);
   Coniugati__1->GetZaxis()->SetLabelFont(42);
   Coniugati__1->GetZaxis()->SetTitleOffset(1);
   Coniugati__1->GetZaxis()->SetTitleFont(42);
   Coniugati__1->Draw("");
   
   TLegend *leg = new TLegend(0.1372404,0.7195696,0.4880169,0.8695726,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextFont(22);
   leg->SetTextSize(0.03913122);
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

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
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
   c1_2->Range(63.36092,-1.721174,68.09269,16.87446);
   c1_2->SetFillColor(0);
   c1_2->SetBorderMode(0);
   c1_2->SetBorderSize(2);
   c1_2->SetGridx();
   c1_2->SetGridy();
   c1_2->SetLeftMargin(0.1350617);
   c1_2->SetRightMargin(0.01958863);
   c1_2->SetFrameBorderMode(0);
   c1_2->SetFrameBorderMode(0);
   
   TH1D *Bessel__2 = new TH1D("Bessel__2","",20,64,68);
   Bessel__2->SetBinContent(8,2);
   Bessel__2->SetBinContent(9,2);
   Bessel__2->SetBinContent(10,1);
   Bessel__2->SetBinContent(11,11);
   Bessel__2->SetBinContent(12,5);
   Bessel__2->SetBinContent(13,2);
   Bessel__2->SetBinContent(14,5);
   Bessel__2->SetBinContent(15,3);
   Bessel__2->SetMinimum(0.1786672);
   Bessel__2->SetMaximum(15.01505);
   Bessel__2->SetEntries(31);
   
   ptstats = new TPaveStats(0.6492434,0.6565249,0.9499091,0.9173997,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("Bessel");
   ptstats_LaTex->SetTextSize(0.06000121);
   ptstats_LaTex = ptstats->AddText("Entries = 31     ");
   ptstats_LaTex = ptstats->AddText("Mean  =  66.26");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.3816");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   Bessel__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Bessel__2);

   ci = TColor::GetColor("#3366ff");
   Bessel__2->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   Bessel__2->SetLineColor(ci);
   Bessel__2->GetXaxis()->SetTitle("f_{i} [mm]");
   Bessel__2->GetXaxis()->SetLabelFont(22);
   Bessel__2->GetXaxis()->SetTitleSize(0.05);
   Bessel__2->GetXaxis()->SetTitleOffset(1);
   Bessel__2->GetXaxis()->SetTitleFont(22);
   Bessel__2->GetYaxis()->SetTitle("frequenza");
   Bessel__2->GetYaxis()->SetLabelFont(22);
   Bessel__2->GetYaxis()->SetTitleSize(0.05);
   Bessel__2->GetYaxis()->SetTitleFont(22);
   Bessel__2->GetZaxis()->SetLabelFont(42);
   Bessel__2->GetZaxis()->SetTitleOffset(1);
   Bessel__2->GetZaxis()->SetTitleFont(42);
   Bessel__2->Draw("");
   
   leg = new TLegend(0.1546703,0.7108738,0.5054468,0.8608768,NULL,"brNDC");
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

   ci = TColor::GetColor("#3366ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
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
