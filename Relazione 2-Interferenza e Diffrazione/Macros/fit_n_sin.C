void fit_n_sin()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Sun Dec 27 15:43:50 2020) by ROOT version 6.22/06
   TCanvas *c1 = new TCanvas("c1", "Canvas",337,16,2000,700);
   gStyle->SetOptFit(1);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: c1_1
   TPad *c1_1 = new TPad("c1_1", "c1_1",1e-05,1e-05,0.3333233,0.99999);
   c1_1->Draw();
   c1_1->cd();
   c1_1->Range(-26.70154,-0.08231513,26.74462,0.07833088);
   c1_1->SetFillColor(0);
   c1_1->SetBorderMode(0);
   c1_1->SetBorderSize(2);
   c1_1->SetGridx();
   c1_1->SetGridy();
   c1_1->SetLeftMargin(0.1366148);
   c1_1->SetFrameBorderMode(0);
   c1_1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[35] = {
   -16,
   -15.00441,
   -14,
   -13,
   -12,
   -11,
   -10,
   -9,
   -8,
   -7,
   -6,
   -5,
   -4,
   -3,
   -2,
   -1,
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12,
   13,
   14,
   15,
   16,
   17,
   18};
   Double_t Graph0_fy1001[35] = {
   -0.0538501,
   -0.05074511,
   -0.0477777,
   -0.04384074,
   -0.04098935,
   -0.0367728,
   -0.03400326,
   -0.03126827,
   -0.02974318,
   -0.02694052,
   -0.02404451,
   -0.01994024,
   -0.01689059,
   -0.01360836,
   -0.01004319,
   -0.006767438,
   -0.003295751,
   -5.848701e-07,
   0.003304016,
   0.00675494,
   0.01003794,
   0.01352155,
   0.0169841,
   0.02003643,
   0.02399607,
   0.02693663,
   0.02965846,
   0.03129664,
   0.03403666,
   0.03687589,
   0.0410293,
   0.04396593,
   0.04818377,
   0.0509654,
   0.05380063};
   Double_t Graph0_fex1001[35] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fey1001[35] = {
   0.0003903755,
   0.0003676982,
   0.0003476584,
   0.0003178947,
   0.0003,
   0.0002667822,
   0.0003,
   0.0002269703,
   0.0002166534,
   0.0001955404,
   0.0003,
   0.0001447953,
   0.0001226591,
   9.888111e-05,
   7.296597e-05,
   4.918919e-05,
   2.40118e-05,
   2.400896e-06,
   2.413084e-05,
   4.909994e-05,
   7.294449e-05,
   9.822692e-05,
   0.0001233388,
   0.0001454869,
   0.0001742093,
   0.0001955155,
   0.0002154014,
   0.0002272148,
   0.0002469938,
   0.0002675051,
   0.0002976017,
   0.0003187681,
   0.0003,
   0.0003,
   0.0003905052};
   TGraphErrors *gre = new TGraphErrors(35,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("2 Fenditure");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0066ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph_Graph010011001 = new TH1F("Graph_Graph_Graph010011001","2 Fenditure",100,-19.4,21.4);
   Graph_Graph_Graph010011001->SetMinimum(-0.06625053);
   Graph_Graph_Graph010011001->SetMaximum(0.06226628);
   Graph_Graph_Graph010011001->SetDirectory(0);
   Graph_Graph_Graph010011001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph010011001->SetLineColor(ci);
   Graph_Graph_Graph010011001->GetXaxis()->SetTitle("n");
   Graph_Graph_Graph010011001->GetXaxis()->SetRange(1,100);
   Graph_Graph_Graph010011001->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph010011001->GetXaxis()->SetLabelFont(22);
   Graph_Graph_Graph010011001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010011001->GetXaxis()->SetTitleFont(22);
   Graph_Graph_Graph010011001->GetYaxis()->SetTitle("sin(#theta)");
   Graph_Graph_Graph010011001->GetYaxis()->SetRange(1,1);
   Graph_Graph_Graph010011001->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph010011001->GetYaxis()->SetLabelFont(22);
   Graph_Graph_Graph010011001->GetYaxis()->SetTitleFont(22);
   Graph_Graph_Graph010011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph010011001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010011001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph010011001);
   
   
   TF1 *f1_21002 = new TF1("*f1_2",-20,20,2);
    //The original function : f1_2 had originally been created by:
    //TF1 *f1_2 = new TF1("f1_2",f1_2,-20,20,2, 1, TF1::EAddToList::kNo);
   f1_21002->SetRange(-20,20);
   f1_21002->SetName("f1_2");
   f1_21002->SetTitle("f1_2");
   f1_21002->SetSavedPoint(0,-0.06835756);
   f1_21002->SetSavedPoint(1,-0.06705552);
   f1_21002->SetSavedPoint(2,-0.06575348);
   f1_21002->SetSavedPoint(3,-0.06445144);
   f1_21002->SetSavedPoint(4,-0.06314939);
   f1_21002->SetSavedPoint(5,-0.06184735);
   f1_21002->SetSavedPoint(6,-0.06054531);
   f1_21002->SetSavedPoint(7,-0.05924327);
   f1_21002->SetSavedPoint(8,-0.05794123);
   f1_21002->SetSavedPoint(9,-0.05663919);
   f1_21002->SetSavedPoint(10,-0.05533715);
   f1_21002->SetSavedPoint(11,-0.05403511);
   f1_21002->SetSavedPoint(12,-0.05273307);
   f1_21002->SetSavedPoint(13,-0.05143103);
   f1_21002->SetSavedPoint(14,-0.05012899);
   f1_21002->SetSavedPoint(15,-0.04882695);
   f1_21002->SetSavedPoint(16,-0.04752491);
   f1_21002->SetSavedPoint(17,-0.04622287);
   f1_21002->SetSavedPoint(18,-0.04492083);
   f1_21002->SetSavedPoint(19,-0.04361878);
   f1_21002->SetSavedPoint(20,-0.04231674);
   f1_21002->SetSavedPoint(21,-0.0410147);
   f1_21002->SetSavedPoint(22,-0.03971266);
   f1_21002->SetSavedPoint(23,-0.03841062);
   f1_21002->SetSavedPoint(24,-0.03710858);
   f1_21002->SetSavedPoint(25,-0.03580654);
   f1_21002->SetSavedPoint(26,-0.0345045);
   f1_21002->SetSavedPoint(27,-0.03320246);
   f1_21002->SetSavedPoint(28,-0.03190042);
   f1_21002->SetSavedPoint(29,-0.03059838);
   f1_21002->SetSavedPoint(30,-0.02929634);
   f1_21002->SetSavedPoint(31,-0.0279943);
   f1_21002->SetSavedPoint(32,-0.02669226);
   f1_21002->SetSavedPoint(33,-0.02539022);
   f1_21002->SetSavedPoint(34,-0.02408817);
   f1_21002->SetSavedPoint(35,-0.02278613);
   f1_21002->SetSavedPoint(36,-0.02148409);
   f1_21002->SetSavedPoint(37,-0.02018205);
   f1_21002->SetSavedPoint(38,-0.01888001);
   f1_21002->SetSavedPoint(39,-0.01757797);
   f1_21002->SetSavedPoint(40,-0.01627593);
   f1_21002->SetSavedPoint(41,-0.01497389);
   f1_21002->SetSavedPoint(42,-0.01367185);
   f1_21002->SetSavedPoint(43,-0.01236981);
   f1_21002->SetSavedPoint(44,-0.01106777);
   f1_21002->SetSavedPoint(45,-0.009765728);
   f1_21002->SetSavedPoint(46,-0.008463687);
   f1_21002->SetSavedPoint(47,-0.007161646);
   f1_21002->SetSavedPoint(48,-0.005859606);
   f1_21002->SetSavedPoint(49,-0.004557565);
   f1_21002->SetSavedPoint(50,-0.003255524);
   f1_21002->SetSavedPoint(51,-0.001953484);
   f1_21002->SetSavedPoint(52,-0.000651443);
   f1_21002->SetSavedPoint(53,0.0006505977);
   f1_21002->SetSavedPoint(54,0.001952638);
   f1_21002->SetSavedPoint(55,0.003254679);
   f1_21002->SetSavedPoint(56,0.00455672);
   f1_21002->SetSavedPoint(57,0.00585876);
   f1_21002->SetSavedPoint(58,0.007160801);
   f1_21002->SetSavedPoint(59,0.008462842);
   f1_21002->SetSavedPoint(60,0.009764882);
   f1_21002->SetSavedPoint(61,0.01106692);
   f1_21002->SetSavedPoint(62,0.01236896);
   f1_21002->SetSavedPoint(63,0.013671);
   f1_21002->SetSavedPoint(64,0.01497304);
   f1_21002->SetSavedPoint(65,0.01627509);
   f1_21002->SetSavedPoint(66,0.01757713);
   f1_21002->SetSavedPoint(67,0.01887917);
   f1_21002->SetSavedPoint(68,0.02018121);
   f1_21002->SetSavedPoint(69,0.02148325);
   f1_21002->SetSavedPoint(70,0.02278529);
   f1_21002->SetSavedPoint(71,0.02408733);
   f1_21002->SetSavedPoint(72,0.02538937);
   f1_21002->SetSavedPoint(73,0.02669141);
   f1_21002->SetSavedPoint(74,0.02799345);
   f1_21002->SetSavedPoint(75,0.02929549);
   f1_21002->SetSavedPoint(76,0.03059753);
   f1_21002->SetSavedPoint(77,0.03189957);
   f1_21002->SetSavedPoint(78,0.03320161);
   f1_21002->SetSavedPoint(79,0.03450365);
   f1_21002->SetSavedPoint(80,0.0358057);
   f1_21002->SetSavedPoint(81,0.03710774);
   f1_21002->SetSavedPoint(82,0.03840978);
   f1_21002->SetSavedPoint(83,0.03971182);
   f1_21002->SetSavedPoint(84,0.04101386);
   f1_21002->SetSavedPoint(85,0.0423159);
   f1_21002->SetSavedPoint(86,0.04361794);
   f1_21002->SetSavedPoint(87,0.04491998);
   f1_21002->SetSavedPoint(88,0.04622202);
   f1_21002->SetSavedPoint(89,0.04752406);
   f1_21002->SetSavedPoint(90,0.0488261);
   f1_21002->SetSavedPoint(91,0.05012814);
   f1_21002->SetSavedPoint(92,0.05143018);
   f1_21002->SetSavedPoint(93,0.05273222);
   f1_21002->SetSavedPoint(94,0.05403426);
   f1_21002->SetSavedPoint(95,0.05533631);
   f1_21002->SetSavedPoint(96,0.05663835);
   f1_21002->SetSavedPoint(97,0.05794039);
   f1_21002->SetSavedPoint(98,0.05924243);
   f1_21002->SetSavedPoint(99,0.06054447);
   f1_21002->SetSavedPoint(100,0.06184651);
   f1_21002->SetSavedPoint(101,-20);
   f1_21002->SetSavedPoint(102,20);
   f1_21002->SetFillColor(19);
   f1_21002->SetFillStyle(0);
   f1_21002->SetLineColor(2);
   f1_21002->SetLineWidth(2);
   f1_21002->SetLineStyle(2);
   f1_21002->SetChisquare(704.741);
   f1_21002->SetNDF(33);
   f1_21002->GetXaxis()->SetLabelFont(42);
   f1_21002->GetXaxis()->SetTitleOffset(1);
   f1_21002->GetXaxis()->SetTitleFont(42);
   f1_21002->GetYaxis()->SetLabelFont(42);
   f1_21002->GetYaxis()->SetTitleFont(42);
   f1_21002->SetParameter(0,0.003255102);
   f1_21002->SetParError(0,4.393007e-06);
   f1_21002->SetParLimits(0,0,0);
   f1_21002->SetParameter(1,-0.003255524);
   f1_21002->SetParError(1,4.995502e-06);
   f1_21002->SetParLimits(1,0,0);
   f1_21002->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1_21002);
   
   TPaveStats *ptstats = new TPaveStats(0.5961319,0.1377805,0.9565138,0.2977837,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 704.7 / 33");
   ptstats_LaTex = ptstats->AddText("p0       = 0.003255 #pm 4.393e-06 ");
   ptstats_LaTex = ptstats->AddText("p1       = -0.003256 #pm 4.996e-06 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   
   ptstats = new TPaveStats(0.5961319,0.3466636,0.9565138,0.5066668,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 771.8 / 33");
   ptstats_LaTex = ptstats->AddText("p0       = 0.003241 #pm 4.232e-06 ");
   ptstats_LaTex = ptstats->AddText("p1       = -0.003235 #pm 1.689e-05 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   Double_t Graph1_fx1004[35] = {
   -16,
   -15,
   -14,
   -13,
   -12,
   -11.05355,
   -10,
   -9,
   -8,
   -7,
   -6.077784,
   -5,
   -4,
   -3,
   -2,
   -1,
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12,
   13,
   14,
   15,
   16,
   17,
   18};
   Double_t Graph1_fy1004[35] = {
   -0.05385948,
   -0.05072353,
   -0.04787137,
   -0.0438193,
   -0.04102153,
   -0.03677167,
   -0.03399444,
   -0.03130791,
   -0.02976427,
   -0.02690512,
   -0.02400058,
   -0.01992617,
   -0.01689337,
   -0.01363115,
   -0.01002505,
   -0.006762037,
   -0.003269808,
   -6.466765e-06,
   0.003314126,
   0.006749105,
   0.01001212,
   0.01356099,
   0.0169949,
   0.02002768,
   0.02397519,
   0.02694939,
   0.02957982,
   0.03129499,
   0.03409583,
   0.03689588,
   0.04100863,
   0.04397766,
   0.0482008,
   0.05093877,
   0.0538466};
   Double_t Graph1_fex1004[35] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph1_fey1004[35] = {
   0.0003914558,
   0.0003689515,
   0.0003484744,
   0.0003193731,
   0.000299278,
   0.0002689243,
   0.0002488295,
   0.0002295662,
   0.0002185084,
   0.0001980553,
   0.0001776491,
   0.0001484008,
   0.0001270433,
   0.0001043639,
   7.996336e-05,
   5.920568e-05,
   4.071076e-05,
   3.30659e-05,
   4.089937e-05,
   5.91278e-05,
   7.987788e-05,
   0.000103881,
   0.0001277548,
   0.0001491188,
   0.0001771496,
   0.0001983716,
   0.0002171877,
   0.0002294737,
   0.0002495569,
   0.000269652,
   0.0002991854,
   0.0003205106,
   0.0003508399,
   0.0003704964,
   0.0003913635};
   gre = new TGraphErrors(35,Graph1_fx1004,Graph1_fy1004,Graph1_fex1004,Graph1_fey1004);
   gre->SetName("Graph1");
   gre->SetTitle("Grafico fit (m,sin(#theta)");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(23);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph_Graph110041004 = new TH1F("Graph_Graph_Graph110041004","Grafico fit (m,sin(#theta)",100,-19.4,21.4);
   Graph_Graph_Graph110041004->SetMinimum(-0.06509982);
   Graph_Graph_Graph110041004->SetMaximum(0.06508685);
   Graph_Graph_Graph110041004->SetDirectory(0);
   Graph_Graph_Graph110041004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph110041004->SetLineColor(ci);
   Graph_Graph_Graph110041004->GetXaxis()->SetTitle("n");
   Graph_Graph_Graph110041004->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph110041004->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph110041004->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph110041004->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph110041004->GetYaxis()->SetTitle("sin(#theta)");
   Graph_Graph_Graph110041004->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph110041004->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph110041004->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph110041004->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph110041004->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph110041004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph110041004);
   
   
   TF1 *f2_21005 = new TF1("*f2_2",-20,20,2);
    //The original function : f2_2 had originally been created by:
    //TF1 *f2_2 = new TF1("f2_2",f2_2,-20,20,2, 1, TF1::EAddToList::kNo);
   f2_21005->SetRange(-20,20);
   f2_21005->SetName("f2_2");
   f2_21005->SetTitle("f2_2");
   f2_21005->SetSavedPoint(0,-0.06805204);
   f2_21005->SetSavedPoint(1,-0.06675569);
   f2_21005->SetSavedPoint(2,-0.06545934);
   f2_21005->SetSavedPoint(3,-0.06416299);
   f2_21005->SetSavedPoint(4,-0.06286664);
   f2_21005->SetSavedPoint(5,-0.0615703);
   f2_21005->SetSavedPoint(6,-0.06027395);
   f2_21005->SetSavedPoint(7,-0.0589776);
   f2_21005->SetSavedPoint(8,-0.05768125);
   f2_21005->SetSavedPoint(9,-0.0563849);
   f2_21005->SetSavedPoint(10,-0.05508855);
   f2_21005->SetSavedPoint(11,-0.05379221);
   f2_21005->SetSavedPoint(12,-0.05249586);
   f2_21005->SetSavedPoint(13,-0.05119951);
   f2_21005->SetSavedPoint(14,-0.04990316);
   f2_21005->SetSavedPoint(15,-0.04860681);
   f2_21005->SetSavedPoint(16,-0.04731047);
   f2_21005->SetSavedPoint(17,-0.04601412);
   f2_21005->SetSavedPoint(18,-0.04471777);
   f2_21005->SetSavedPoint(19,-0.04342142);
   f2_21005->SetSavedPoint(20,-0.04212507);
   f2_21005->SetSavedPoint(21,-0.04082872);
   f2_21005->SetSavedPoint(22,-0.03953238);
   f2_21005->SetSavedPoint(23,-0.03823603);
   f2_21005->SetSavedPoint(24,-0.03693968);
   f2_21005->SetSavedPoint(25,-0.03564333);
   f2_21005->SetSavedPoint(26,-0.03434698);
   f2_21005->SetSavedPoint(27,-0.03305063);
   f2_21005->SetSavedPoint(28,-0.03175429);
   f2_21005->SetSavedPoint(29,-0.03045794);
   f2_21005->SetSavedPoint(30,-0.02916159);
   f2_21005->SetSavedPoint(31,-0.02786524);
   f2_21005->SetSavedPoint(32,-0.02656889);
   f2_21005->SetSavedPoint(33,-0.02527255);
   f2_21005->SetSavedPoint(34,-0.0239762);
   f2_21005->SetSavedPoint(35,-0.02267985);
   f2_21005->SetSavedPoint(36,-0.0213835);
   f2_21005->SetSavedPoint(37,-0.02008715);
   f2_21005->SetSavedPoint(38,-0.0187908);
   f2_21005->SetSavedPoint(39,-0.01749446);
   f2_21005->SetSavedPoint(40,-0.01619811);
   f2_21005->SetSavedPoint(41,-0.01490176);
   f2_21005->SetSavedPoint(42,-0.01360541);
   f2_21005->SetSavedPoint(43,-0.01230906);
   f2_21005->SetSavedPoint(44,-0.01101271);
   f2_21005->SetSavedPoint(45,-0.009716366);
   f2_21005->SetSavedPoint(46,-0.008420018);
   f2_21005->SetSavedPoint(47,-0.00712367);
   f2_21005->SetSavedPoint(48,-0.005827322);
   f2_21005->SetSavedPoint(49,-0.004530973);
   f2_21005->SetSavedPoint(50,-0.003234625);
   f2_21005->SetSavedPoint(51,-0.001938277);
   f2_21005->SetSavedPoint(52,-0.0006419287);
   f2_21005->SetSavedPoint(53,0.0006544195);
   f2_21005->SetSavedPoint(54,0.001950768);
   f2_21005->SetSavedPoint(55,0.003247116);
   f2_21005->SetSavedPoint(56,0.004543464);
   f2_21005->SetSavedPoint(57,0.005839812);
   f2_21005->SetSavedPoint(58,0.007136161);
   f2_21005->SetSavedPoint(59,0.008432509);
   f2_21005->SetSavedPoint(60,0.009728857);
   f2_21005->SetSavedPoint(61,0.01102521);
   f2_21005->SetSavedPoint(62,0.01232155);
   f2_21005->SetSavedPoint(63,0.0136179);
   f2_21005->SetSavedPoint(64,0.01491425);
   f2_21005->SetSavedPoint(65,0.0162106);
   f2_21005->SetSavedPoint(66,0.01750695);
   f2_21005->SetSavedPoint(67,0.01880329);
   f2_21005->SetSavedPoint(68,0.02009964);
   f2_21005->SetSavedPoint(69,0.02139599);
   f2_21005->SetSavedPoint(70,0.02269234);
   f2_21005->SetSavedPoint(71,0.02398869);
   f2_21005->SetSavedPoint(72,0.02528504);
   f2_21005->SetSavedPoint(73,0.02658138);
   f2_21005->SetSavedPoint(74,0.02787773);
   f2_21005->SetSavedPoint(75,0.02917408);
   f2_21005->SetSavedPoint(76,0.03047043);
   f2_21005->SetSavedPoint(77,0.03176678);
   f2_21005->SetSavedPoint(78,0.03306313);
   f2_21005->SetSavedPoint(79,0.03435947);
   f2_21005->SetSavedPoint(80,0.03565582);
   f2_21005->SetSavedPoint(81,0.03695217);
   f2_21005->SetSavedPoint(82,0.03824852);
   f2_21005->SetSavedPoint(83,0.03954487);
   f2_21005->SetSavedPoint(84,0.04084121);
   f2_21005->SetSavedPoint(85,0.04213756);
   f2_21005->SetSavedPoint(86,0.04343391);
   f2_21005->SetSavedPoint(87,0.04473026);
   f2_21005->SetSavedPoint(88,0.04602661);
   f2_21005->SetSavedPoint(89,0.04732296);
   f2_21005->SetSavedPoint(90,0.0486193);
   f2_21005->SetSavedPoint(91,0.04991565);
   f2_21005->SetSavedPoint(92,0.051212);
   f2_21005->SetSavedPoint(93,0.05250835);
   f2_21005->SetSavedPoint(94,0.0538047);
   f2_21005->SetSavedPoint(95,0.05510105);
   f2_21005->SetSavedPoint(96,0.05639739);
   f2_21005->SetSavedPoint(97,0.05769374);
   f2_21005->SetSavedPoint(98,0.05899009);
   f2_21005->SetSavedPoint(99,0.06028644);
   f2_21005->SetSavedPoint(100,0.06158279);
   f2_21005->SetSavedPoint(101,-20);
   f2_21005->SetSavedPoint(102,20);
   f2_21005->SetFillColor(19);
   f2_21005->SetFillStyle(0);

   ci = TColor::GetColor("#0066ff");
   f2_21005->SetLineColor(ci);
   f2_21005->SetLineWidth(2);
   f2_21005->SetLineStyle(2);
   f2_21005->SetChisquare(771.8289);
   f2_21005->SetNDF(33);
   f2_21005->GetXaxis()->SetLabelFont(42);
   f2_21005->GetXaxis()->SetTitleOffset(1);
   f2_21005->GetXaxis()->SetTitleFont(42);
   f2_21005->GetYaxis()->SetLabelFont(42);
   f2_21005->GetYaxis()->SetTitleFont(42);
   f2_21005->SetParameter(0,0.003240871);
   f2_21005->SetParError(0,4.231631e-06);
   f2_21005->SetParLimits(0,0,0);
   f2_21005->SetParameter(1,-0.003234625);
   f2_21005->SetParError(1,1.689112e-05);
   f2_21005->SetParLimits(1,0,0);
   f2_21005->SetParent(gre);
   gre->GetListOfFunctions()->Add(f2_21005);
   
   ptstats = new TPaveStats(0.5961319,0.3466636,0.9565138,0.5066668,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 771.8 / 33");
   ptstats_LaTex = ptstats->AddText("p0       = 0.003241 #pm 4.232e-06 ");
   ptstats_LaTex = ptstats->AddText("p1       = -0.003235 #pm 1.689e-05 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("p");
   
   TLegend *leg = new TLegend(0.1501292,0.6844481,0.492492,0.8740816,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.02814871);
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
   entry=leg->AddEntry("Graph0","Minimi x^{par}_{min}","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0066ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Minimi x^{alg}_{min}","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","a_{par}+b_{par}x interpolante","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","a_{alg}+b_{alg}x interpolante","l");

   ci = TColor::GetColor("#0066ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   ptstats = new TPaveStats(0.5758604,0.3377745,0.9767853,0.5511121,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 704.7 / 33");
   ptstats_LaTex = ptstats->AddText("b_{par}  = 0.003255 #pm 4.393e-06 ");
   ptstats_LaTex = ptstats->AddText("a_{par}  = -0.003256 #pm 4.996e-06 ");
   ptstats_LaTex = ptstats->AddText("#rho  = 0.956319 ");
   ptstats_LaTex = ptstats->AddText("T_Student  = 19.0754");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   ptstats = new TPaveStats(0.5751096,0.1125848,0.9775361,0.3244409,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 771.8 / 33");
   ptstats_LaTex = ptstats->AddText("b_{alg}  = 0.003241 #pm 4.232e-06 ");
   ptstats_LaTex = ptstats->AddText("b_{alg}  = -0.003235 #pm 1.689-05 ");
   ptstats_LaTex = ptstats->AddText("#rho  =  0.956364 ");
   ptstats_LaTex = ptstats->AddText("T_Student  = 19.0861 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   TPaveText *pt = new TPaveText(0.3526044,0.94,0.6473956,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(22);
   TText *pt_LaTex = pt->AddText("2 Fenditure");
   pt->Draw();
   c1_1->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_2
   TPad *c1_2 = new TPad("c1_2", "c1_2",0.3333433,1e-05,0.6666567,0.99999);
   c1_2->Draw();
   c1_2->cd();
   c1_2->Range(-26.29513,-0.08550036,25.47724,0.08146449);
   c1_2->SetFillColor(0);
   c1_2->SetBorderMode(0);
   c1_2->SetBorderSize(2);
   c1_2->SetGridx();
   c1_2->SetGridy();
   c1_2->SetLeftMargin(0.1351132);
   c1_2->SetFrameBorderMode(0);
   c1_2->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1007[34] = {
   -16.00618,
   -15,
   -14,
   -13,
   -12,
   -11,
   -10,
   -9,
   -8,
   -7,
   -6,
   -5,
   -4,
   -3,
   -2,
   -1,
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12,
   13,
   14,
   15,
   16,
   17};
   Double_t Graph0_fy1007[34] = {
   -0.05578124,
   -0.05406978,
   -0.05063377,
   -0.0475413,
   -0.04389168,
   -0.04076571,
   -0.03696303,
   -0.03387051,
   -0.0307694,
   -0.02689558,
   -0.02366835,
   -0.02006608,
   -0.01677722,
   -0.01340142,
   -0.009966917,
   -0.006629218,
   -0.003228011,
   0.0001281527,
   0.003502491,
   0.006904548,
   0.0102335,
   0.01362483,
   0.01708649,
   0.02032786,
   0.02398409,
   0.02719105,
   0.03084112,
   0.03401806,
   0.03711766,
   0.04087936,
   0.04405997,
   0.04793565,
   0.05098076,
   0.05460235};
   Double_t Graph0_fex1007[34] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fey1007[34] = {
   0.0004039921,
   0.0003,
   0.0003668444,
   0.0003445468,
   0.0003182002,
   0.0002956168,
   0.000268114,
   0.0003,
   0.0002233028,
   0.000195217,
   0.0001718191,
   0.0001456927,
   0.0001218313,
   9.733216e-05,
   7.239517e-05,
   4.816243e-05,
   2.347163e-05,
   1.62387e-06,
   2.547676e-05,
   5.015933e-05,
   7.433065e-05,
   9.89534e-05,
   0.0001240762,
   0.0001475931,
   0.0001741109,
   0.0001973577,
   0.0002238528,
   0.0003,
   0.0002692336,
   0.0002964295,
   0.0003194067,
   0.0003473814,
   0.0003693462,
   0.0003955697};
   gre = new TGraphErrors(34,Graph0_fx1007,Graph0_fy1007,Graph0_fex1007,Graph0_fey1007);
   gre->SetName("Graph0");
   gre->SetTitle("3 Fenditure");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0066ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph_Graph010071007 = new TH1F("Graph_Graph_Graph010071007","3 Fenditure",100,-19.3,20.3);
   Graph_Graph_Graph010071007->SetMinimum(-0.06880388);
   Graph_Graph_Graph010071007->SetMaximum(0.064768);
   Graph_Graph_Graph010071007->SetDirectory(0);
   Graph_Graph_Graph010071007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph010071007->SetLineColor(ci);
   Graph_Graph_Graph010071007->GetXaxis()->SetTitle("n");
   Graph_Graph_Graph010071007->GetXaxis()->SetRange(1,100);
   Graph_Graph_Graph010071007->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph010071007->GetXaxis()->SetLabelFont(22);
   Graph_Graph_Graph010071007->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010071007->GetXaxis()->SetTitleFont(22);
   Graph_Graph_Graph010071007->GetYaxis()->SetTitle("sin(#theta)");
   Graph_Graph_Graph010071007->GetYaxis()->SetRange(1,1);
   Graph_Graph_Graph010071007->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph010071007->GetYaxis()->SetLabelFont(22);
   Graph_Graph_Graph010071007->GetYaxis()->SetTitleFont(22);
   Graph_Graph_Graph010071007->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph010071007->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010071007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph010071007);
   
   
   TF1 *f1_31008 = new TF1("*f1_3",-20,20,2);
    //The original function : f1_3 had originally been created by:
    //TF1 *f1_3 = new TF1("f1_3",f1_3,-20,20,2, 1, TF1::EAddToList::kNo);
   f1_31008->SetRange(-20,20);
   f1_31008->SetName("f1_3");
   f1_31008->SetTitle("f1_3");
   f1_31008->SetSavedPoint(0,-0.07091082);
   f1_31008->SetSavedPoint(1,-0.06955769);
   f1_31008->SetSavedPoint(2,-0.06820457);
   f1_31008->SetSavedPoint(3,-0.06685144);
   f1_31008->SetSavedPoint(4,-0.06549832);
   f1_31008->SetSavedPoint(5,-0.06414519);
   f1_31008->SetSavedPoint(6,-0.06279206);
   f1_31008->SetSavedPoint(7,-0.06143894);
   f1_31008->SetSavedPoint(8,-0.06008581);
   f1_31008->SetSavedPoint(9,-0.05873269);
   f1_31008->SetSavedPoint(10,-0.05737956);
   f1_31008->SetSavedPoint(11,-0.05602643);
   f1_31008->SetSavedPoint(12,-0.05467331);
   f1_31008->SetSavedPoint(13,-0.05332018);
   f1_31008->SetSavedPoint(14,-0.05196706);
   f1_31008->SetSavedPoint(15,-0.05061393);
   f1_31008->SetSavedPoint(16,-0.0492608);
   f1_31008->SetSavedPoint(17,-0.04790768);
   f1_31008->SetSavedPoint(18,-0.04655455);
   f1_31008->SetSavedPoint(19,-0.04520143);
   f1_31008->SetSavedPoint(20,-0.0438483);
   f1_31008->SetSavedPoint(21,-0.04249517);
   f1_31008->SetSavedPoint(22,-0.04114205);
   f1_31008->SetSavedPoint(23,-0.03978892);
   f1_31008->SetSavedPoint(24,-0.0384358);
   f1_31008->SetSavedPoint(25,-0.03708267);
   f1_31008->SetSavedPoint(26,-0.03572954);
   f1_31008->SetSavedPoint(27,-0.03437642);
   f1_31008->SetSavedPoint(28,-0.03302329);
   f1_31008->SetSavedPoint(29,-0.03167017);
   f1_31008->SetSavedPoint(30,-0.03031704);
   f1_31008->SetSavedPoint(31,-0.02896391);
   f1_31008->SetSavedPoint(32,-0.02761079);
   f1_31008->SetSavedPoint(33,-0.02625766);
   f1_31008->SetSavedPoint(34,-0.02490454);
   f1_31008->SetSavedPoint(35,-0.02355141);
   f1_31008->SetSavedPoint(36,-0.02219828);
   f1_31008->SetSavedPoint(37,-0.02084516);
   f1_31008->SetSavedPoint(38,-0.01949203);
   f1_31008->SetSavedPoint(39,-0.01813891);
   f1_31008->SetSavedPoint(40,-0.01678578);
   f1_31008->SetSavedPoint(41,-0.01543265);
   f1_31008->SetSavedPoint(42,-0.01407953);
   f1_31008->SetSavedPoint(43,-0.0127264);
   f1_31008->SetSavedPoint(44,-0.01137328);
   f1_31008->SetSavedPoint(45,-0.01002015);
   f1_31008->SetSavedPoint(46,-0.008667023);
   f1_31008->SetSavedPoint(47,-0.007313897);
   f1_31008->SetSavedPoint(48,-0.005960771);
   f1_31008->SetSavedPoint(49,-0.004607645);
   f1_31008->SetSavedPoint(50,-0.003254519);
   f1_31008->SetSavedPoint(51,-0.001901393);
   f1_31008->SetSavedPoint(52,-0.0005482671);
   f1_31008->SetSavedPoint(53,0.0008048589);
   f1_31008->SetSavedPoint(54,0.002157985);
   f1_31008->SetSavedPoint(55,0.003511111);
   f1_31008->SetSavedPoint(56,0.004864237);
   f1_31008->SetSavedPoint(57,0.006217363);
   f1_31008->SetSavedPoint(58,0.007570489);
   f1_31008->SetSavedPoint(59,0.008923615);
   f1_31008->SetSavedPoint(60,0.01027674);
   f1_31008->SetSavedPoint(61,0.01162987);
   f1_31008->SetSavedPoint(62,0.01298299);
   f1_31008->SetSavedPoint(63,0.01433612);
   f1_31008->SetSavedPoint(64,0.01568924);
   f1_31008->SetSavedPoint(65,0.01704237);
   f1_31008->SetSavedPoint(66,0.0183955);
   f1_31008->SetSavedPoint(67,0.01974862);
   f1_31008->SetSavedPoint(68,0.02110175);
   f1_31008->SetSavedPoint(69,0.02245487);
   f1_31008->SetSavedPoint(70,0.023808);
   f1_31008->SetSavedPoint(71,0.02516113);
   f1_31008->SetSavedPoint(72,0.02651425);
   f1_31008->SetSavedPoint(73,0.02786738);
   f1_31008->SetSavedPoint(74,0.0292205);
   f1_31008->SetSavedPoint(75,0.03057363);
   f1_31008->SetSavedPoint(76,0.03192676);
   f1_31008->SetSavedPoint(77,0.03327988);
   f1_31008->SetSavedPoint(78,0.03463301);
   f1_31008->SetSavedPoint(79,0.03598613);
   f1_31008->SetSavedPoint(80,0.03733926);
   f1_31008->SetSavedPoint(81,0.03869239);
   f1_31008->SetSavedPoint(82,0.04004551);
   f1_31008->SetSavedPoint(83,0.04139864);
   f1_31008->SetSavedPoint(84,0.04275176);
   f1_31008->SetSavedPoint(85,0.04410489);
   f1_31008->SetSavedPoint(86,0.04545802);
   f1_31008->SetSavedPoint(87,0.04681114);
   f1_31008->SetSavedPoint(88,0.04816427);
   f1_31008->SetSavedPoint(89,0.04951739);
   f1_31008->SetSavedPoint(90,0.05087052);
   f1_31008->SetSavedPoint(91,0.05222365);
   f1_31008->SetSavedPoint(92,0.05357677);
   f1_31008->SetSavedPoint(93,0.0549299);
   f1_31008->SetSavedPoint(94,0.05628302);
   f1_31008->SetSavedPoint(95,0.05763615);
   f1_31008->SetSavedPoint(96,0.05898928);
   f1_31008->SetSavedPoint(97,0.0603424);
   f1_31008->SetSavedPoint(98,0.06169553);
   f1_31008->SetSavedPoint(99,0.06304865);
   f1_31008->SetSavedPoint(100,0.06440178);
   f1_31008->SetSavedPoint(101,-20);
   f1_31008->SetSavedPoint(102,20);
   f1_31008->SetFillColor(19);
   f1_31008->SetFillStyle(0);
   f1_31008->SetLineColor(2);
   f1_31008->SetLineWidth(2);
   f1_31008->SetLineStyle(2);
   f1_31008->SetChisquare(31.74791);
   f1_31008->SetNDF(32);
   f1_31008->GetXaxis()->SetLabelFont(42);
   f1_31008->GetXaxis()->SetTitleOffset(1);
   f1_31008->GetXaxis()->SetTitleFont(42);
   f1_31008->GetYaxis()->SetLabelFont(42);
   f1_31008->GetYaxis()->SetTitleFont(42);
   f1_31008->SetParameter(0,0.003382815);
   f1_31008->SetParError(0,4.480966e-06);
   f1_31008->SetParLimits(0,0,0);
   f1_31008->SetParameter(1,-0.003254519);
   f1_31008->SetParError(1,4.757693e-06);
   f1_31008->SetParLimits(1,0,0);
   f1_31008->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1_31008);
   
   ptstats = new TPaveStats(0.6351432,0.1125848,0.9955252,0.272588,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 31.75 / 32");
   ptstats_LaTex = ptstats->AddText("p0       = 0.003383 #pm 4.481e-06 ");
   ptstats_LaTex = ptstats->AddText("p1       = -0.003255 #pm 4.758e-06 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   
   ptstats = new TPaveStats(0.6156526,0.3570442,0.9760345,0.5170474,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 32.82 / 32");
   ptstats_LaTex = ptstats->AddText("p0       = 0.003385 #pm 4.485e-06 ");
   ptstats_LaTex = ptstats->AddText("p1       = -0.003254 #pm 1.7e-05 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   Double_t Graph1_fx1010[34] = {
   -16.03487,
   -15.02424,
   -14.01361,
   -13.00298,
   -12.07009,
   -11.05945,
   -10.04882,
   -9.03819,
   -8.027558,
   -7.016926,
   -6.006294,
   -5.073403,
   -4.062771,
   -3.052138,
   -2.041506,
   -1.030874,
   -0.02024188,
   0.9903903,
   1.923281,
   2.933914,
   3.944546,
   4.955178,
   5.96581,
   6.976442,
   7.987074,
   8.997707,
   9.930598,
   10.94123,
   11.95186,
   12.96249,
   13.97313,
   14.98376,
   15.99439,
   16.92728};
   Double_t Graph1_fy1010[34] = {
   -0.05557209,
   -0.05384248,
   -0.05038327,
   -0.04741824,
   -0.04371194,
   -0.04049982,
   -0.03679353,
   -0.03382849,
   -0.03061637,
   -0.02666299,
   -0.02345087,
   -0.01999166,
   -0.01653245,
   -0.01332033,
   -0.009861121,
   -0.006401913,
   -0.003189791,
   0.000269417,
   0.003728625,
   0.006940747,
   0.01039996,
   0.01385916,
   0.01731837,
   0.02053049,
   0.0239897,
   0.02720182,
   0.03090812,
   0.03412024,
   0.03733236,
   0.04103866,
   0.04425078,
   0.04820416,
   0.05116919,
   0.05487549};
   Double_t Graph1_fex1010[34] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph1_fey1010[34] = {
   0.0004053553,
   0.0003930916,
   0.0003681327,
   0.0003460161,
   0.0003197831,
   0.0002972272,
   0.0002701548,
   0.0002480095,
   0.0002258795,
   0.0001980553,
   0.0001747973,
   0.0001492102,
   0.0001262415,
   0.000102789,
   7.958511e-05,
   5.851779e-05,
   4.04696e-05,
   3.307518e-05,
   4.164574e-05,
   6.016582e-05,
   8.139421e-05,
   0.0001042749,
   0.0001285572,
   0.0001511432,
   0.0001771496,
   0.0002000065,
   0.0002261965,
   0.0002491469,
   0.0002712927,
   0.0002983651,
   0.0003213306,
   0.0003492012,
   0.0003709058,
   0.000397088};
   gre = new TGraphErrors(34,Graph1_fx1010,Graph1_fy1010,Graph1_fex1010,Graph1_fey1010);
   gre->SetName("Graph1");
   gre->SetTitle("Grafico fit (m,sin(#theta)");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(23);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph_Graph110101010 = new TH1F("Graph_Graph_Graph110101010","Grafico fit (m,sin(#theta)",100,-19.3,20.3);
   Graph_Graph_Graph110101010->SetMinimum(-0.06732705);
   Graph_Graph_Graph110101010->SetMaximum(0.06616611);
   Graph_Graph_Graph110101010->SetDirectory(0);
   Graph_Graph_Graph110101010->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph110101010->SetLineColor(ci);
   Graph_Graph_Graph110101010->GetXaxis()->SetTitle("n");
   Graph_Graph_Graph110101010->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph110101010->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph110101010->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph110101010->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph110101010->GetYaxis()->SetTitle("sin(#theta)");
   Graph_Graph_Graph110101010->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph110101010->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph110101010->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph110101010->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph110101010->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph110101010->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph110101010);
   
   
   TF1 *f2_31011 = new TF1("*f2_3",-20,20,2);
    //The original function : f2_3 had originally been created by:
    //TF1 *f2_3 = new TF1("f2_3",f2_3,-20,20,2, 1, TF1::EAddToList::kNo);
   f2_31011->SetRange(-20,20);
   f2_31011->SetName("f2_3");
   f2_31011->SetTitle("f2_3");
   f2_31011->SetSavedPoint(0,-0.07095192);
   f2_31011->SetSavedPoint(1,-0.06959796);
   f2_31011->SetSavedPoint(2,-0.068244);
   f2_31011->SetSavedPoint(3,-0.06689004);
   f2_31011->SetSavedPoint(4,-0.06553607);
   f2_31011->SetSavedPoint(5,-0.06418211);
   f2_31011->SetSavedPoint(6,-0.06282815);
   f2_31011->SetSavedPoint(7,-0.06147419);
   f2_31011->SetSavedPoint(8,-0.06012023);
   f2_31011->SetSavedPoint(9,-0.05876627);
   f2_31011->SetSavedPoint(10,-0.05741231);
   f2_31011->SetSavedPoint(11,-0.05605835);
   f2_31011->SetSavedPoint(12,-0.05470439);
   f2_31011->SetSavedPoint(13,-0.05335043);
   f2_31011->SetSavedPoint(14,-0.05199647);
   f2_31011->SetSavedPoint(15,-0.05064251);
   f2_31011->SetSavedPoint(16,-0.04928855);
   f2_31011->SetSavedPoint(17,-0.04793458);
   f2_31011->SetSavedPoint(18,-0.04658062);
   f2_31011->SetSavedPoint(19,-0.04522666);
   f2_31011->SetSavedPoint(20,-0.0438727);
   f2_31011->SetSavedPoint(21,-0.04251874);
   f2_31011->SetSavedPoint(22,-0.04116478);
   f2_31011->SetSavedPoint(23,-0.03981082);
   f2_31011->SetSavedPoint(24,-0.03845686);
   f2_31011->SetSavedPoint(25,-0.0371029);
   f2_31011->SetSavedPoint(26,-0.03574894);
   f2_31011->SetSavedPoint(27,-0.03439498);
   f2_31011->SetSavedPoint(28,-0.03304102);
   f2_31011->SetSavedPoint(29,-0.03168706);
   f2_31011->SetSavedPoint(30,-0.0303331);
   f2_31011->SetSavedPoint(31,-0.02897913);
   f2_31011->SetSavedPoint(32,-0.02762517);
   f2_31011->SetSavedPoint(33,-0.02627121);
   f2_31011->SetSavedPoint(34,-0.02491725);
   f2_31011->SetSavedPoint(35,-0.02356329);
   f2_31011->SetSavedPoint(36,-0.02220933);
   f2_31011->SetSavedPoint(37,-0.02085537);
   f2_31011->SetSavedPoint(38,-0.01950141);
   f2_31011->SetSavedPoint(39,-0.01814745);
   f2_31011->SetSavedPoint(40,-0.01679349);
   f2_31011->SetSavedPoint(41,-0.01543953);
   f2_31011->SetSavedPoint(42,-0.01408557);
   f2_31011->SetSavedPoint(43,-0.01273161);
   f2_31011->SetSavedPoint(44,-0.01137764);
   f2_31011->SetSavedPoint(45,-0.01002368);
   f2_31011->SetSavedPoint(46,-0.008669723);
   f2_31011->SetSavedPoint(47,-0.007315762);
   f2_31011->SetSavedPoint(48,-0.005961802);
   f2_31011->SetSavedPoint(49,-0.004607841);
   f2_31011->SetSavedPoint(50,-0.00325388);
   f2_31011->SetSavedPoint(51,-0.001899919);
   f2_31011->SetSavedPoint(52,-0.0005459587);
   f2_31011->SetSavedPoint(53,0.000808002);
   f2_31011->SetSavedPoint(54,0.002161963);
   f2_31011->SetSavedPoint(55,0.003515923);
   f2_31011->SetSavedPoint(56,0.004869884);
   f2_31011->SetSavedPoint(57,0.006223845);
   f2_31011->SetSavedPoint(58,0.007577806);
   f2_31011->SetSavedPoint(59,0.008931766);
   f2_31011->SetSavedPoint(60,0.01028573);
   f2_31011->SetSavedPoint(61,0.01163969);
   f2_31011->SetSavedPoint(62,0.01299365);
   f2_31011->SetSavedPoint(63,0.01434761);
   f2_31011->SetSavedPoint(64,0.01570157);
   f2_31011->SetSavedPoint(65,0.01705553);
   f2_31011->SetSavedPoint(66,0.01840949);
   f2_31011->SetSavedPoint(67,0.01976345);
   f2_31011->SetSavedPoint(68,0.02111741);
   f2_31011->SetSavedPoint(69,0.02247137);
   f2_31011->SetSavedPoint(70,0.02382533);
   f2_31011->SetSavedPoint(71,0.0251793);
   f2_31011->SetSavedPoint(72,0.02653326);
   f2_31011->SetSavedPoint(73,0.02788722);
   f2_31011->SetSavedPoint(74,0.02924118);
   f2_31011->SetSavedPoint(75,0.03059514);
   f2_31011->SetSavedPoint(76,0.0319491);
   f2_31011->SetSavedPoint(77,0.03330306);
   f2_31011->SetSavedPoint(78,0.03465702);
   f2_31011->SetSavedPoint(79,0.03601098);
   f2_31011->SetSavedPoint(80,0.03736494);
   f2_31011->SetSavedPoint(81,0.0387189);
   f2_31011->SetSavedPoint(82,0.04007286);
   f2_31011->SetSavedPoint(83,0.04142682);
   f2_31011->SetSavedPoint(84,0.04278079);
   f2_31011->SetSavedPoint(85,0.04413475);
   f2_31011->SetSavedPoint(86,0.04548871);
   f2_31011->SetSavedPoint(87,0.04684267);
   f2_31011->SetSavedPoint(88,0.04819663);
   f2_31011->SetSavedPoint(89,0.04955059);
   f2_31011->SetSavedPoint(90,0.05090455);
   f2_31011->SetSavedPoint(91,0.05225851);
   f2_31011->SetSavedPoint(92,0.05361247);
   f2_31011->SetSavedPoint(93,0.05496643);
   f2_31011->SetSavedPoint(94,0.05632039);
   f2_31011->SetSavedPoint(95,0.05767435);
   f2_31011->SetSavedPoint(96,0.05902831);
   f2_31011->SetSavedPoint(97,0.06038227);
   f2_31011->SetSavedPoint(98,0.06173624);
   f2_31011->SetSavedPoint(99,0.0630902);
   f2_31011->SetSavedPoint(100,0.06444416);
   f2_31011->SetSavedPoint(101,-20);
   f2_31011->SetSavedPoint(102,20);
   f2_31011->SetFillColor(19);
   f2_31011->SetFillStyle(0);

   ci = TColor::GetColor("#0066ff");
   f2_31011->SetLineColor(ci);
   f2_31011->SetLineWidth(2);
   f2_31011->SetLineStyle(2);
   f2_31011->SetChisquare(32.82111);
   f2_31011->SetNDF(32);
   f2_31011->GetXaxis()->SetLabelFont(42);
   f2_31011->GetXaxis()->SetTitleOffset(1);
   f2_31011->GetXaxis()->SetTitleFont(42);
   f2_31011->GetYaxis()->SetLabelFont(42);
   f2_31011->GetYaxis()->SetTitleFont(42);
   f2_31011->SetParameter(0,0.003384902);
   f2_31011->SetParError(0,4.485326e-06);
   f2_31011->SetParLimits(0,0,0);
   f2_31011->SetParameter(1,-0.00325388);
   f2_31011->SetParError(1,1.700309e-05);
   f2_31011->SetParLimits(1,0,0);
   f2_31011->SetParent(gre);
   gre->GetListOfFunctions()->Add(f2_31011);
   
   ptstats = new TPaveStats(0.6156526,0.3570442,0.9760345,0.5170474,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 32.82 / 32");
   ptstats_LaTex = ptstats->AddText("p0       = 0.003385 #pm 4.485e-06 ");
   ptstats_LaTex = ptstats->AddText("p1       = -0.003254 #pm 1.7e-05 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("p");
   
   leg = new TLegend(0.1531323,0.6800036,0.4969968,0.8711185,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.02814871);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","Legenda","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextAlign(22);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","Minimi x^{par}_{min}","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0066ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Minimi x^{alg}_{min}","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","a_{par}+b_{par}x interpolante","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","a_{alg}+b_{alg}x interpolante","l");

   ci = TColor::GetColor("#0066ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   ptstats = new TPaveStats(0.5961319,0.3318485,0.9955552,0.5437046,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 31.75 / 32");
   ptstats_LaTex = ptstats->AddText("b_{par}  = 0.003383 #pm 4.481e-06 ");
   ptstats_LaTex = ptstats->AddText("a_{par}  = -0.003255 #pm 4.758e-06 ");
   ptstats_LaTex = ptstats->AddText("#rho  =  0.999991 ");
   ptstats_LaTex = ptstats->AddText("T_Student  = 1311.96 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   ptstats = new TPaveStats(0.5976035,0.1111033,0.9955252,0.3214779,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 32.82 / 32");
   ptstats_LaTex = ptstats->AddText("b_{alg}  = 0.003385 #pm 4.485e-06 ");
   ptstats_LaTex = ptstats->AddText("a_{alg}  = -0.003254 #pm 1.7e-05 ");
   ptstats_LaTex = ptstats->AddText("#rho  = 0.99999 ");
   ptstats_LaTex = ptstats->AddText("T_Student  = 1269.53 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   pt = new TPaveText(0.3526044,0.94,0.6473956,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(22);
   pt_LaTex = pt->AddText("3 Fenditure");
   pt->Draw();
   c1_2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_3
   TPad *c1_3 = new TPad("c1_3", "c1_3",0.6666767,1e-05,0.99999,0.99999);
   c1_3->Draw();
   c1_3->cd();
   c1_3->Range(-25.71861,-0.079056,24.19096,0.07835134);
   c1_3->SetFillColor(0);
   c1_3->SetBorderMode(0);
   c1_3->SetBorderSize(2);
   c1_3->SetGridx();
   c1_3->SetGridy();
   c1_3->SetLeftMargin(0.1306085);
   c1_3->SetFrameBorderMode(0);
   c1_3->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1013[33] = {
   -16,
   -15.00425,
   -14,
   -13,
   -12,
   -11,
   -10,
   -9,
   -8,
   -7,
   -6,
   -5,
   -4,
   -3,
   -2,
   -1,
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12,
   13,
   14,
   15,
   16};
   Double_t Graph0_fy1013[33] = {
   -0.05446365,
   -0.0509427,
   -0.04767489,
   -0.04416376,
   -0.04084435,
   -0.03723091,
   -0.03399756,
   -0.03055066,
   -0.02708259,
   -0.02374853,
   -0.02021522,
   -0.0169594,
   -0.01349777,
   -0.01007909,
   -0.006750116,
   -0.003357906,
   -7.251938e-07,
   0.003354025,
   0.006742767,
   0.01014822,
   0.01350025,
   0.01692441,
   0.0202823,
   0.02374304,
   0.02705762,
   0.03054013,
   0.03389228,
   0.03714419,
   0.04078077,
   0.0440301,
   0.04763833,
   0.05094494,
   0.05445852};
   Double_t Graph0_fex1013[33] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fey1013[33] = {
   0.0003944335,
   0.0003691728,
   0.0003454969,
   0.0003201558,
   0.0002961753,
   0.0002700528,
   0.0003,
   0.0002216967,
   0.0003,
   0.0001723992,
   0.0001467723,
   0.0001231487,
   9.80245e-05,
   7.320309e-05,
   4.902996e-05,
   2.439734e-05,
   5.427034e-07,
   2.43674e-05,
   4.897704e-05,
   7.370657e-05,
   9.804181e-05,
   0.0001228952,
   0.0001472594,
   0.0001723595,
   0.0001963874,
   0.0003,
   0.0003,
   0.000269425,
   0.0003,
   0.0003191904,
   0.0003452351,
   0.0003690748,
   0.0003943907};
   gre = new TGraphErrors(33,Graph0_fx1013,Graph0_fy1013,Graph0_fex1013,Graph0_fey1013);
   gre->SetName("Graph0");
   gre->SetTitle("4 Fenditure");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0066ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph_Graph010131013 = new TH1F("Graph_Graph_Graph010131013","4 Fenditure",100,-19.2,19.2);
   Graph_Graph_Graph010131013->SetMinimum(-0.06331526);
   Graph_Graph_Graph010131013->SetMaximum(0.0626106);
   Graph_Graph_Graph010131013->SetDirectory(0);
   Graph_Graph_Graph010131013->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph010131013->SetLineColor(ci);
   Graph_Graph_Graph010131013->GetXaxis()->SetTitle("n");
   Graph_Graph_Graph010131013->GetXaxis()->SetRange(1,100);
   Graph_Graph_Graph010131013->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph010131013->GetXaxis()->SetLabelFont(22);
   Graph_Graph_Graph010131013->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010131013->GetXaxis()->SetTitleFont(22);
   Graph_Graph_Graph010131013->GetYaxis()->SetTitle("sin(#theta)");
   Graph_Graph_Graph010131013->GetYaxis()->SetRange(1,1);
   Graph_Graph_Graph010131013->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph010131013->GetYaxis()->SetLabelFont(22);
   Graph_Graph_Graph010131013->GetYaxis()->SetTitleFont(22);
   Graph_Graph_Graph010131013->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph010131013->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010131013->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph010131013);
   
   
   TF1 *f1_41014 = new TF1("*f1_4",-20,20,2);
    //The original function : f1_4 had originally been created by:
    //TF1 *f1_4 = new TF1("f1_4",f1_4,-20,20,2, 1, TF1::EAddToList::kNo);
   f1_41014->SetRange(-20,20);
   f1_41014->SetName("f1_4");
   f1_41014->SetTitle("f1_4");
   f1_41014->SetSavedPoint(0,-0.0676997);
   f1_41014->SetSavedPoint(1,-0.06634572);
   f1_41014->SetSavedPoint(2,-0.06499174);
   f1_41014->SetSavedPoint(3,-0.06363776);
   f1_41014->SetSavedPoint(4,-0.06228378);
   f1_41014->SetSavedPoint(5,-0.0609298);
   f1_41014->SetSavedPoint(6,-0.05957582);
   f1_41014->SetSavedPoint(7,-0.05822184);
   f1_41014->SetSavedPoint(8,-0.05686786);
   f1_41014->SetSavedPoint(9,-0.05551388);
   f1_41014->SetSavedPoint(10,-0.0541599);
   f1_41014->SetSavedPoint(11,-0.05280592);
   f1_41014->SetSavedPoint(12,-0.05145194);
   f1_41014->SetSavedPoint(13,-0.05009797);
   f1_41014->SetSavedPoint(14,-0.04874399);
   f1_41014->SetSavedPoint(15,-0.04739001);
   f1_41014->SetSavedPoint(16,-0.04603603);
   f1_41014->SetSavedPoint(17,-0.04468205);
   f1_41014->SetSavedPoint(18,-0.04332807);
   f1_41014->SetSavedPoint(19,-0.04197409);
   f1_41014->SetSavedPoint(20,-0.04062011);
   f1_41014->SetSavedPoint(21,-0.03926613);
   f1_41014->SetSavedPoint(22,-0.03791215);
   f1_41014->SetSavedPoint(23,-0.03655817);
   f1_41014->SetSavedPoint(24,-0.03520419);
   f1_41014->SetSavedPoint(25,-0.03385021);
   f1_41014->SetSavedPoint(26,-0.03249623);
   f1_41014->SetSavedPoint(27,-0.03114225);
   f1_41014->SetSavedPoint(28,-0.02978827);
   f1_41014->SetSavedPoint(29,-0.02843429);
   f1_41014->SetSavedPoint(30,-0.02708031);
   f1_41014->SetSavedPoint(31,-0.02572634);
   f1_41014->SetSavedPoint(32,-0.02437236);
   f1_41014->SetSavedPoint(33,-0.02301838);
   f1_41014->SetSavedPoint(34,-0.0216644);
   f1_41014->SetSavedPoint(35,-0.02031042);
   f1_41014->SetSavedPoint(36,-0.01895644);
   f1_41014->SetSavedPoint(37,-0.01760246);
   f1_41014->SetSavedPoint(38,-0.01624848);
   f1_41014->SetSavedPoint(39,-0.0148945);
   f1_41014->SetSavedPoint(40,-0.01354052);
   f1_41014->SetSavedPoint(41,-0.01218654);
   f1_41014->SetSavedPoint(42,-0.01083256);
   f1_41014->SetSavedPoint(43,-0.009478581);
   f1_41014->SetSavedPoint(44,-0.008124602);
   f1_41014->SetSavedPoint(45,-0.006770623);
   f1_41014->SetSavedPoint(46,-0.005416643);
   f1_41014->SetSavedPoint(47,-0.004062664);
   f1_41014->SetSavedPoint(48,-0.002708684);
   f1_41014->SetSavedPoint(49,-0.001354705);
   f1_41014->SetSavedPoint(50,-7.251798e-07);
   f1_41014->SetSavedPoint(51,0.001353254);
   f1_41014->SetSavedPoint(52,0.002707234);
   f1_41014->SetSavedPoint(53,0.004061213);
   f1_41014->SetSavedPoint(54,0.005415193);
   f1_41014->SetSavedPoint(55,0.006769172);
   f1_41014->SetSavedPoint(56,0.008123152);
   f1_41014->SetSavedPoint(57,0.009477131);
   f1_41014->SetSavedPoint(58,0.01083111);
   f1_41014->SetSavedPoint(59,0.01218509);
   f1_41014->SetSavedPoint(60,0.01353907);
   f1_41014->SetSavedPoint(61,0.01489305);
   f1_41014->SetSavedPoint(62,0.01624703);
   f1_41014->SetSavedPoint(63,0.01760101);
   f1_41014->SetSavedPoint(64,0.01895499);
   f1_41014->SetSavedPoint(65,0.02030897);
   f1_41014->SetSavedPoint(66,0.02166295);
   f1_41014->SetSavedPoint(67,0.02301693);
   f1_41014->SetSavedPoint(68,0.02437091);
   f1_41014->SetSavedPoint(69,0.02572488);
   f1_41014->SetSavedPoint(70,0.02707886);
   f1_41014->SetSavedPoint(71,0.02843284);
   f1_41014->SetSavedPoint(72,0.02978682);
   f1_41014->SetSavedPoint(73,0.0311408);
   f1_41014->SetSavedPoint(74,0.03249478);
   f1_41014->SetSavedPoint(75,0.03384876);
   f1_41014->SetSavedPoint(76,0.03520274);
   f1_41014->SetSavedPoint(77,0.03655672);
   f1_41014->SetSavedPoint(78,0.0379107);
   f1_41014->SetSavedPoint(79,0.03926468);
   f1_41014->SetSavedPoint(80,0.04061866);
   f1_41014->SetSavedPoint(81,0.04197264);
   f1_41014->SetSavedPoint(82,0.04332662);
   f1_41014->SetSavedPoint(83,0.0446806);
   f1_41014->SetSavedPoint(84,0.04603458);
   f1_41014->SetSavedPoint(85,0.04738856);
   f1_41014->SetSavedPoint(86,0.04874254);
   f1_41014->SetSavedPoint(87,0.05009652);
   f1_41014->SetSavedPoint(88,0.05145049);
   f1_41014->SetSavedPoint(89,0.05280447);
   f1_41014->SetSavedPoint(90,0.05415845);
   f1_41014->SetSavedPoint(91,0.05551243);
   f1_41014->SetSavedPoint(92,0.05686641);
   f1_41014->SetSavedPoint(93,0.05822039);
   f1_41014->SetSavedPoint(94,0.05957437);
   f1_41014->SetSavedPoint(95,0.06092835);
   f1_41014->SetSavedPoint(96,0.06228233);
   f1_41014->SetSavedPoint(97,0.06363631);
   f1_41014->SetSavedPoint(98,0.06499029);
   f1_41014->SetSavedPoint(99,0.06634427);
   f1_41014->SetSavedPoint(100,0.06769825);
   f1_41014->SetSavedPoint(101,-20);
   f1_41014->SetSavedPoint(102,20);
   f1_41014->SetFillColor(19);
   f1_41014->SetFillStyle(0);
   f1_41014->SetLineColor(2);
   f1_41014->SetLineWidth(2);
   f1_41014->SetLineStyle(2);
   f1_41014->SetChisquare(9.381359);
   f1_41014->SetNDF(31);
   f1_41014->GetXaxis()->SetLabelFont(42);
   f1_41014->GetXaxis()->SetTitleOffset(1);
   f1_41014->GetXaxis()->SetTitleFont(42);
   f1_41014->GetYaxis()->SetLabelFont(42);
   f1_41014->GetYaxis()->SetTitleFont(42);
   f1_41014->SetParameter(0,0.003384949);
   f1_41014->SetParError(0,4.726791e-06);
   f1_41014->SetParLimits(0,0,0);
   f1_41014->SetParameter(1,-7.251798e-07);
   f1_41014->SetParError(1,5.42287e-07);
   f1_41014->SetParLimits(1,0,0);
   f1_41014->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1_41014);
   
   ptstats = new TPaveStats(0.6351432,0.3511181,0.9955252,0.5111213,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 9.381 / 31");
   ptstats_LaTex = ptstats->AddText("p0       = 0.003385 #pm 4.727e-06 ");
   ptstats_LaTex = ptstats->AddText("p1       = -7.252e-07 #pm 5.423e-07 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   
   ptstats = new TPaveStats(0.6216289,0.1125848,0.9820109,0.272588,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 6.409 / 31");
   ptstats_LaTex = ptstats->AddText("p0       = 0.003389 #pm 4.567e-06 ");
   ptstats_LaTex = ptstats->AddText("p1       = 7.014e-06 #pm 1.65e-05 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   Double_t Graph1_fx1016[33] = {
   -16,
   -15.00315,
   -14,
   -13,
   -12,
   -11,
   -10,
   -9,
   -8,
   -7,
   -6,
   -5,
   -4,
   -3,
   -2,
   -1,
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12,
   13,
   14,
   15,
   16};
   Double_t Graph1_fy1016[33] = {
   -0.05447466,
   -0.05083636,
   -0.04768837,
   -0.04414998,
   -0.04083836,
   -0.03723974,
   -0.03398259,
   -0.03055284,
   -0.02706483,
   -0.02374744,
   -0.02020039,
   -0.01693873,
   -0.01350481,
   -0.01007042,
   -0.006750165,
   -0.003372437,
   5.406212e-06,
   0.003383249,
   0.006760977,
   0.01013847,
   0.01351562,
   0.01694954,
   0.02026842,
   0.02375824,
   0.02707563,
   0.03056364,
   0.03387908,
   0.03713626,
   0.04079204,
   0.04404659,
   0.04764209,
   0.05095059,
   0.05448542};
   Double_t Graph1_fex1016[33] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph1_fey1016[33] = {
   0.0003958683,
   0.0003705032,
   0.0003471594,
   0.0003217473,
   0.0002979615,
   0.0002721195,
   0.0002487433,
   0.0002241549,
   0.0001991951,
   0.0001755258,
   0.0001503388,
   0.0001273588,
   0.0001034916,
   8.025975e-05,
   5.912918e-05,
   4.114285e-05,
   3.305694e-05,
   4.118965e-05,
   5.91943e-05,
   8.071029e-05,
   0.000103566,
   0.0001274345,
   0.0001508202,
   0.0001756027,
   0.0001992723,
   0.0002242322,
   0.0002480008,
   0.0002713766,
   0.0002976288,
   0.0003210047,
   0.0003468271,
   0.0003705805,
   0.0003959455};
   gre = new TGraphErrors(33,Graph1_fx1016,Graph1_fy1016,Graph1_fex1016,Graph1_fey1016);
   gre->SetName("Graph1");
   gre->SetTitle("Grafico fit (n,sin(#theta)");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(23);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph_Graph110161016 = new TH1F("Graph_Graph_Graph110161016","Grafico fit (n,sin(#theta)",100,-19.2,19.2);
   Graph_Graph_Graph110161016->SetMinimum(-0.06584571);
   Graph_Graph_Graph110161016->SetMaximum(0.06585655);
   Graph_Graph_Graph110161016->SetDirectory(0);
   Graph_Graph_Graph110161016->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph110161016->SetLineColor(ci);
   Graph_Graph_Graph110161016->GetXaxis()->SetTitle("n");
   Graph_Graph_Graph110161016->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph110161016->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph110161016->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph110161016->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph110161016->GetYaxis()->SetTitle("sin(#theta)");
   Graph_Graph_Graph110161016->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph110161016->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph110161016->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph110161016->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph110161016->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph110161016->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph110161016);
   
   
   TF1 *f2_41017 = new TF1("*f2_4",-20,20,2);
    //The original function : f2_4 had originally been created by:
    //TF1 *f2_4 = new TF1("f2_4",f2_4,-20,20,2, 1, TF1::EAddToList::kNo);
   f2_41017->SetRange(-20,20);
   f2_41017->SetName("f2_4");
   f2_41017->SetTitle("f2_4");
   f2_41017->SetSavedPoint(0,-0.06777149);
   f2_41017->SetSavedPoint(1,-0.06641592);
   f2_41017->SetSavedPoint(2,-0.06506035);
   f2_41017->SetSavedPoint(3,-0.06370478);
   f2_41017->SetSavedPoint(4,-0.06234921);
   f2_41017->SetSavedPoint(5,-0.06099364);
   f2_41017->SetSavedPoint(6,-0.05963807);
   f2_41017->SetSavedPoint(7,-0.0582825);
   f2_41017->SetSavedPoint(8,-0.05692693);
   f2_41017->SetSavedPoint(9,-0.05557136);
   f2_41017->SetSavedPoint(10,-0.05421579);
   f2_41017->SetSavedPoint(11,-0.05286022);
   f2_41017->SetSavedPoint(12,-0.05150465);
   f2_41017->SetSavedPoint(13,-0.05014908);
   f2_41017->SetSavedPoint(14,-0.04879351);
   f2_41017->SetSavedPoint(15,-0.04743794);
   f2_41017->SetSavedPoint(16,-0.04608237);
   f2_41017->SetSavedPoint(17,-0.0447268);
   f2_41017->SetSavedPoint(18,-0.04337123);
   f2_41017->SetSavedPoint(19,-0.04201566);
   f2_41017->SetSavedPoint(20,-0.04066009);
   f2_41017->SetSavedPoint(21,-0.03930452);
   f2_41017->SetSavedPoint(22,-0.03794895);
   f2_41017->SetSavedPoint(23,-0.03659338);
   f2_41017->SetSavedPoint(24,-0.03523781);
   f2_41017->SetSavedPoint(25,-0.03388224);
   f2_41017->SetSavedPoint(26,-0.03252667);
   f2_41017->SetSavedPoint(27,-0.0311711);
   f2_41017->SetSavedPoint(28,-0.02981553);
   f2_41017->SetSavedPoint(29,-0.02845996);
   f2_41017->SetSavedPoint(30,-0.02710439);
   f2_41017->SetSavedPoint(31,-0.02574882);
   f2_41017->SetSavedPoint(32,-0.02439325);
   f2_41017->SetSavedPoint(33,-0.02303768);
   f2_41017->SetSavedPoint(34,-0.02168211);
   f2_41017->SetSavedPoint(35,-0.02032654);
   f2_41017->SetSavedPoint(36,-0.01897097);
   f2_41017->SetSavedPoint(37,-0.0176154);
   f2_41017->SetSavedPoint(38,-0.01625983);
   f2_41017->SetSavedPoint(39,-0.01490426);
   f2_41017->SetSavedPoint(40,-0.01354869);
   f2_41017->SetSavedPoint(41,-0.01219312);
   f2_41017->SetSavedPoint(42,-0.01083755);
   f2_41017->SetSavedPoint(43,-0.009481976);
   f2_41017->SetSavedPoint(44,-0.008126406);
   f2_41017->SetSavedPoint(45,-0.006770836);
   f2_41017->SetSavedPoint(46,-0.005415266);
   f2_41017->SetSavedPoint(47,-0.004059696);
   f2_41017->SetSavedPoint(48,-0.002704126);
   f2_41017->SetSavedPoint(49,-0.001348556);
   f2_41017->SetSavedPoint(50,7.014232e-06);
   f2_41017->SetSavedPoint(51,0.001362584);
   f2_41017->SetSavedPoint(52,0.002718154);
   f2_41017->SetSavedPoint(53,0.004073724);
   f2_41017->SetSavedPoint(54,0.005429295);
   f2_41017->SetSavedPoint(55,0.006784865);
   f2_41017->SetSavedPoint(56,0.008140435);
   f2_41017->SetSavedPoint(57,0.009496005);
   f2_41017->SetSavedPoint(58,0.01085157);
   f2_41017->SetSavedPoint(59,0.01220714);
   f2_41017->SetSavedPoint(60,0.01356272);
   f2_41017->SetSavedPoint(61,0.01491829);
   f2_41017->SetSavedPoint(62,0.01627386);
   f2_41017->SetSavedPoint(63,0.01762943);
   f2_41017->SetSavedPoint(64,0.018985);
   f2_41017->SetSavedPoint(65,0.02034057);
   f2_41017->SetSavedPoint(66,0.02169614);
   f2_41017->SetSavedPoint(67,0.02305171);
   f2_41017->SetSavedPoint(68,0.02440728);
   f2_41017->SetSavedPoint(69,0.02576285);
   f2_41017->SetSavedPoint(70,0.02711842);
   f2_41017->SetSavedPoint(71,0.02847399);
   f2_41017->SetSavedPoint(72,0.02982956);
   f2_41017->SetSavedPoint(73,0.03118513);
   f2_41017->SetSavedPoint(74,0.0325407);
   f2_41017->SetSavedPoint(75,0.03389627);
   f2_41017->SetSavedPoint(76,0.03525184);
   f2_41017->SetSavedPoint(77,0.03660741);
   f2_41017->SetSavedPoint(78,0.03796298);
   f2_41017->SetSavedPoint(79,0.03931855);
   f2_41017->SetSavedPoint(80,0.04067412);
   f2_41017->SetSavedPoint(81,0.04202969);
   f2_41017->SetSavedPoint(82,0.04338526);
   f2_41017->SetSavedPoint(83,0.04474083);
   f2_41017->SetSavedPoint(84,0.0460964);
   f2_41017->SetSavedPoint(85,0.04745197);
   f2_41017->SetSavedPoint(86,0.04880754);
   f2_41017->SetSavedPoint(87,0.05016311);
   f2_41017->SetSavedPoint(88,0.05151868);
   f2_41017->SetSavedPoint(89,0.05287425);
   f2_41017->SetSavedPoint(90,0.05422982);
   f2_41017->SetSavedPoint(91,0.05558539);
   f2_41017->SetSavedPoint(92,0.05694096);
   f2_41017->SetSavedPoint(93,0.05829653);
   f2_41017->SetSavedPoint(94,0.0596521);
   f2_41017->SetSavedPoint(95,0.06100767);
   f2_41017->SetSavedPoint(96,0.06236324);
   f2_41017->SetSavedPoint(97,0.06371881);
   f2_41017->SetSavedPoint(98,0.06507438);
   f2_41017->SetSavedPoint(99,0.06642995);
   f2_41017->SetSavedPoint(100,0.06778552);
   f2_41017->SetSavedPoint(101,-20);
   f2_41017->SetSavedPoint(102,20);
   f2_41017->SetFillColor(19);
   f2_41017->SetFillStyle(0);

   ci = TColor::GetColor("#0066ff");
   f2_41017->SetLineColor(ci);
   f2_41017->SetLineWidth(2);
   f2_41017->SetLineStyle(2);
   f2_41017->SetChisquare(6.408659);
   f2_41017->SetNDF(31);
   f2_41017->GetXaxis()->SetLabelFont(42);
   f2_41017->GetXaxis()->SetTitleOffset(1);
   f2_41017->GetXaxis()->SetTitleFont(42);
   f2_41017->GetYaxis()->SetLabelFont(42);
   f2_41017->GetYaxis()->SetTitleFont(42);
   f2_41017->SetParameter(0,0.003388925);
   f2_41017->SetParError(0,4.566614e-06);
   f2_41017->SetParLimits(0,0,0);
   f2_41017->SetParameter(1,7.014232e-06);
   f2_41017->SetParError(1,1.649817e-05);
   f2_41017->SetParLimits(1,0,0);
   f2_41017->SetParent(gre);
   gre->GetListOfFunctions()->Add(f2_41017);
   
   ptstats = new TPaveStats(0.6216289,0.1125848,0.9820109,0.272588,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 6.409 / 31");
   ptstats_LaTex = ptstats->AddText("p0       = 0.003389 #pm 4.567e-06 ");
   ptstats_LaTex = ptstats->AddText("p1       = 7.014e-06 #pm 1.65e-05 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("p");
   
   leg = new TLegend(0.1591387,0.6844481,0.5045048,0.8726,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.02814871);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","Legenda","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextAlign(22);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","Minimi x^{par}_{min}","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0066ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Minimi x^{alg}_{min}","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","a_{par}+b_{par}x interpolante","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","a_{alg}+b_{alg}x interpolante","l");

   ci = TColor::GetColor("#0066ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   ptstats = new TPaveStats(0.5796144,0.1111033,0.9940536,0.3111073,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 9.381 / 31");
   ptstats_LaTex = ptstats->AddText("b_{par}  = 0.003385 #pm 4.393e-06 ");
   ptstats_LaTex = ptstats->AddText("a_{par}  = -7.252e-07 #pm 5.423e-07 ");
   ptstats_LaTex = ptstats->AddText("#rho  = 0.999997 ");
   ptstats_LaTex = ptstats->AddText("T_Student  = 2124.99 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   ptstats = new TPaveStats(0.5788636,0.3259224,0.9948044,0.536297,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 6.409 / 31");
   ptstats_LaTex = ptstats->AddText("b_{alg}  = 0.003389 #pm 4.567e-06 ");
   ptstats_LaTex = ptstats->AddText("a_{alg}  =6.345e-06 #pm 1.13e-05  ");
   ptstats_LaTex = ptstats->AddText("#rho  = 0.999996 ");
   ptstats_LaTex = ptstats->AddText("T_Student  = 2048.36 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   pt = new TPaveText(0.3526044,0.94,0.6473956,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(22);
   pt_LaTex = pt->AddText("4 Fenditure");
   pt->Draw();
   c1_3->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
