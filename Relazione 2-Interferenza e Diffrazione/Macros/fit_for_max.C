void fit_for_max()
{
   //=========Macro generated from canvas: c1/Canvas
   //=========  (Sat Dec 26 11:20:32 2020) by ROOT version 6.22/06
   TCanvas *c1 = new TCanvas("c1", "Canvas", 475, 56, 1000, 700);
   gStyle->SetOptFit(1);
   c1->Range(-190.2649, 135261.5, 179.8543, 218886.4);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetLeftMargin(0.08717435);
   c1->SetRightMargin(0.00501002);
   c1->SetTopMargin(0.04148148);
   c1->SetBottomMargin(0.07407407);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);

   Double_t Graph0_fx1001[20] = {
       -130,
       -120,
       -110,
       -100,
       -90,
       -80,
       -70,
       -60.22778,
       -50,
       -40,
       60,
       70,
       80,
       90,
       100,
       110,
       120,
       130,
       140,
       150};
   Double_t Graph0_fy1001[20] = {
       145740,
       150895,
       155165,
       159325,
       163525,
       168171,
       171273,
       174601.3,
       179820,
       184158,
       186319,
       184447,
       180299,
       175719,
       172497,
       169588,
       165059,
       160157,
       155663,
       151382};
   Double_t Graph0_fex1001[20] = {
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
   Double_t Graph0_fey1001[20] = {
       145.74,
       150.895,
       155.165,
       159.325,
       163.525,
       168.171,
       171.273,
       174.517,
       179.82,
       184.158,
       186.319,
       184.447,
       180.299,
       175.719,
       172.497,
       169.588,
       165.059,
       160.157,
       155.663,
       151.382};
   TGraphErrors *gre = new TGraphErrors(20, Graph0_fx1001, Graph0_fy1001, Graph0_fex1001, Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Ricerca del Massimo");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0066ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.9);

   TH1F *Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001 = new TH1F("Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001", "Ricerca del Massimo", 100, -158, 178);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->SetMinimum(141455.9);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->SetMaximum(215417.5);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->SetLineColor(ci);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetXaxis()->SetTitle("Passi Motore");
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetXaxis()->SetLabelFont(22);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetXaxis()->SetTitleFont(22);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetYaxis()->SetTitle("Intensita' [u.a.]");
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetYaxis()->SetLabelFont(22);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetYaxis()->SetTitleFont(22);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph_Graph_Graph_Graph010011001100110011001);

   TF1 *f11002 = new TF1("*f1", -200, 50, 2);
   //The original function : f1 had originally been created by:
   //TF1 *f1 = new TF1("f1",f1,-200,50,2, 1, TF1::EAddToList::kNo);
   f11002->SetRange(-200, 50);
   f11002->SetName("f1");
   f11002->SetTitle("f1");
   f11002->SetSavedPoint(0, 117358.4);
   f11002->SetSavedPoint(1, 118399.7);
   f11002->SetSavedPoint(2, 119441);
   f11002->SetSavedPoint(3, 120482.2);
   f11002->SetSavedPoint(4, 121523.5);
   f11002->SetSavedPoint(5, 122564.7);
   f11002->SetSavedPoint(6, 123606);
   f11002->SetSavedPoint(7, 124647.3);
   f11002->SetSavedPoint(8, 125688.5);
   f11002->SetSavedPoint(9, 126729.8);
   f11002->SetSavedPoint(10, 127771);
   f11002->SetSavedPoint(11, 128812.3);
   f11002->SetSavedPoint(12, 129853.5);
   f11002->SetSavedPoint(13, 130894.8);
   f11002->SetSavedPoint(14, 131936.1);
   f11002->SetSavedPoint(15, 132977.3);
   f11002->SetSavedPoint(16, 134018.6);
   f11002->SetSavedPoint(17, 135059.8);
   f11002->SetSavedPoint(18, 136101.1);
   f11002->SetSavedPoint(19, 137142.4);
   f11002->SetSavedPoint(20, 138183.6);
   f11002->SetSavedPoint(21, 139224.9);
   f11002->SetSavedPoint(22, 140266.1);
   f11002->SetSavedPoint(23, 141307.4);
   f11002->SetSavedPoint(24, 142348.6);
   f11002->SetSavedPoint(25, 143389.9);
   f11002->SetSavedPoint(26, 144431.2);
   f11002->SetSavedPoint(27, 145472.4);
   f11002->SetSavedPoint(28, 146513.7);
   f11002->SetSavedPoint(29, 147554.9);
   f11002->SetSavedPoint(30, 148596.2);
   f11002->SetSavedPoint(31, 149637.4);
   f11002->SetSavedPoint(32, 150678.7);
   f11002->SetSavedPoint(33, 151720);
   f11002->SetSavedPoint(34, 152761.2);
   f11002->SetSavedPoint(35, 153802.5);
   f11002->SetSavedPoint(36, 154843.7);
   f11002->SetSavedPoint(37, 155885);
   f11002->SetSavedPoint(38, 156926.3);
   f11002->SetSavedPoint(39, 157967.5);
   f11002->SetSavedPoint(40, 159008.8);
   f11002->SetSavedPoint(41, 160050);
   f11002->SetSavedPoint(42, 161091.3);
   f11002->SetSavedPoint(43, 162132.5);
   f11002->SetSavedPoint(44, 163173.8);
   f11002->SetSavedPoint(45, 164215.1);
   f11002->SetSavedPoint(46, 165256.3);
   f11002->SetSavedPoint(47, 166297.6);
   f11002->SetSavedPoint(48, 167338.8);
   f11002->SetSavedPoint(49, 168380.1);
   f11002->SetSavedPoint(50, 169421.4);
   f11002->SetSavedPoint(51, 170462.6);
   f11002->SetSavedPoint(52, 171503.9);
   f11002->SetSavedPoint(53, 172545.1);
   f11002->SetSavedPoint(54, 173586.4);
   f11002->SetSavedPoint(55, 174627.6);
   f11002->SetSavedPoint(56, 175668.9);
   f11002->SetSavedPoint(57, 176710.2);
   f11002->SetSavedPoint(58, 177751.4);
   f11002->SetSavedPoint(59, 178792.7);
   f11002->SetSavedPoint(60, 179833.9);
   f11002->SetSavedPoint(61, 180875.2);
   f11002->SetSavedPoint(62, 181916.4);
   f11002->SetSavedPoint(63, 182957.7);
   f11002->SetSavedPoint(64, 183999);
   f11002->SetSavedPoint(65, 185040.2);
   f11002->SetSavedPoint(66, 186081.5);
   f11002->SetSavedPoint(67, 187122.7);
   f11002->SetSavedPoint(68, 188164);
   f11002->SetSavedPoint(69, 189205.3);
   f11002->SetSavedPoint(70, 190246.5);
   f11002->SetSavedPoint(71, 191287.8);
   f11002->SetSavedPoint(72, 192329);
   f11002->SetSavedPoint(73, 193370.3);
   f11002->SetSavedPoint(74, 194411.5);
   f11002->SetSavedPoint(75, 195452.8);
   f11002->SetSavedPoint(76, 196494.1);
   f11002->SetSavedPoint(77, 197535.3);
   f11002->SetSavedPoint(78, 198576.6);
   f11002->SetSavedPoint(79, 199617.8);
   f11002->SetSavedPoint(80, 200659.1);
   f11002->SetSavedPoint(81, 201700.4);
   f11002->SetSavedPoint(82, 202741.6);
   f11002->SetSavedPoint(83, 203782.9);
   f11002->SetSavedPoint(84, 204824.1);
   f11002->SetSavedPoint(85, 205865.4);
   f11002->SetSavedPoint(86, 206906.6);
   f11002->SetSavedPoint(87, 207947.9);
   f11002->SetSavedPoint(88, 208989.2);
   f11002->SetSavedPoint(89, 210030.4);
   f11002->SetSavedPoint(90, 211071.7);
   f11002->SetSavedPoint(91, 212112.9);
   f11002->SetSavedPoint(92, 213154.2);
   f11002->SetSavedPoint(93, 214195.4);
   f11002->SetSavedPoint(94, 215236.7);
   f11002->SetSavedPoint(95, 216278);
   f11002->SetSavedPoint(96, 217319.2);
   f11002->SetSavedPoint(97, 218360.5);
   f11002->SetSavedPoint(98, 219401.7);
   f11002->SetSavedPoint(99, 220443);
   f11002->SetSavedPoint(100, 221484.3);
   f11002->SetSavedPoint(101, -200);
   f11002->SetSavedPoint(102, 50);
   f11002->SetFillColor(19);
   f11002->SetFillStyle(0);
   f11002->SetLineColor(2);
   f11002->SetLineWidth(2);
   f11002->SetLineStyle(2);
   f11002->SetChisquare(113.6958);
   f11002->SetNDF(8);
   f11002->GetXaxis()->SetLabelFont(42);
   f11002->GetXaxis()->SetTitleOffset(1);
   f11002->GetXaxis()->SetTitleFont(42);
   f11002->GetYaxis()->SetLabelFont(42);
   f11002->GetYaxis()->SetTitleFont(42);
   f11002->SetParameter(0, 416.5032);
   f11002->SetParError(0, 1.810487);
   f11002->SetParLimits(0, 0, 0);
   f11002->SetParameter(1, 200659.1);
   f11002->SetParError(1, 169.5733);
   f11002->SetParLimits(1, 0, 0);
   f11002->SetParent(gre);
   gre->GetListOfFunctions()->Add(f11002);

   TF1 *f21003 = new TF1("*f2", -20, 200, 2);
   //The original function : f2 had originally been created by:
   //TF1 *f2 = new TF1("f2",f2,-20,200,2, 1, TF1::EAddToList::kNo);
   f21003->SetRange(-20, 200);
   f21003->SetName("f2");
   f21003->SetTitle("f2");
   f21003->SetSavedPoint(0, 219806.2);
   f21003->SetSavedPoint(1, 218931.5);
   f21003->SetSavedPoint(2, 218056.8);
   f21003->SetSavedPoint(3, 217182.1);
   f21003->SetSavedPoint(4, 216307.4);
   f21003->SetSavedPoint(5, 215432.7);
   f21003->SetSavedPoint(6, 214558);
   f21003->SetSavedPoint(7, 213683.3);
   f21003->SetSavedPoint(8, 212808.6);
   f21003->SetSavedPoint(9, 211933.9);
   f21003->SetSavedPoint(10, 211059.2);
   f21003->SetSavedPoint(11, 210184.5);
   f21003->SetSavedPoint(12, 209309.8);
   f21003->SetSavedPoint(13, 208435.1);
   f21003->SetSavedPoint(14, 207560.4);
   f21003->SetSavedPoint(15, 206685.7);
   f21003->SetSavedPoint(16, 205811);
   f21003->SetSavedPoint(17, 204936.3);
   f21003->SetSavedPoint(18, 204061.6);
   f21003->SetSavedPoint(19, 203186.9);
   f21003->SetSavedPoint(20, 202312.2);
   f21003->SetSavedPoint(21, 201437.5);
   f21003->SetSavedPoint(22, 200562.8);
   f21003->SetSavedPoint(23, 199688.1);
   f21003->SetSavedPoint(24, 198813.4);
   f21003->SetSavedPoint(25, 197938.7);
   f21003->SetSavedPoint(26, 197064);
   f21003->SetSavedPoint(27, 196189.3);
   f21003->SetSavedPoint(28, 195314.6);
   f21003->SetSavedPoint(29, 194439.9);
   f21003->SetSavedPoint(30, 193565.2);
   f21003->SetSavedPoint(31, 192690.5);
   f21003->SetSavedPoint(32, 191815.8);
   f21003->SetSavedPoint(33, 190941.1);
   f21003->SetSavedPoint(34, 190066.4);
   f21003->SetSavedPoint(35, 189191.7);
   f21003->SetSavedPoint(36, 188317);
   f21003->SetSavedPoint(37, 187442.3);
   f21003->SetSavedPoint(38, 186567.6);
   f21003->SetSavedPoint(39, 185692.9);
   f21003->SetSavedPoint(40, 184818.1);
   f21003->SetSavedPoint(41, 183943.4);
   f21003->SetSavedPoint(42, 183068.7);
   f21003->SetSavedPoint(43, 182194);
   f21003->SetSavedPoint(44, 181319.3);
   f21003->SetSavedPoint(45, 180444.6);
   f21003->SetSavedPoint(46, 179569.9);
   f21003->SetSavedPoint(47, 178695.2);
   f21003->SetSavedPoint(48, 177820.5);
   f21003->SetSavedPoint(49, 176945.8);
   f21003->SetSavedPoint(50, 176071.1);
   f21003->SetSavedPoint(51, 175196.4);
   f21003->SetSavedPoint(52, 174321.7);
   f21003->SetSavedPoint(53, 173447);
   f21003->SetSavedPoint(54, 172572.3);
   f21003->SetSavedPoint(55, 171697.6);
   f21003->SetSavedPoint(56, 170822.9);
   f21003->SetSavedPoint(57, 169948.2);
   f21003->SetSavedPoint(58, 169073.5);
   f21003->SetSavedPoint(59, 168198.8);
   f21003->SetSavedPoint(60, 167324.1);
   f21003->SetSavedPoint(61, 166449.4);
   f21003->SetSavedPoint(62, 165574.7);
   f21003->SetSavedPoint(63, 164700);
   f21003->SetSavedPoint(64, 163825.3);
   f21003->SetSavedPoint(65, 162950.6);
   f21003->SetSavedPoint(66, 162075.9);
   f21003->SetSavedPoint(67, 161201.2);
   f21003->SetSavedPoint(68, 160326.5);
   f21003->SetSavedPoint(69, 159451.8);
   f21003->SetSavedPoint(70, 158577.1);
   f21003->SetSavedPoint(71, 157702.4);
   f21003->SetSavedPoint(72, 156827.7);
   f21003->SetSavedPoint(73, 155953);
   f21003->SetSavedPoint(74, 155078.3);
   f21003->SetSavedPoint(75, 154203.6);
   f21003->SetSavedPoint(76, 153328.9);
   f21003->SetSavedPoint(77, 152454.2);
   f21003->SetSavedPoint(78, 151579.5);
   f21003->SetSavedPoint(79, 150704.8);
   f21003->SetSavedPoint(80, 149830.1);
   f21003->SetSavedPoint(81, 148955.4);
   f21003->SetSavedPoint(82, 148080.7);
   f21003->SetSavedPoint(83, 147206);
   f21003->SetSavedPoint(84, 146331.3);
   f21003->SetSavedPoint(85, 145456.6);
   f21003->SetSavedPoint(86, 144581.9);
   f21003->SetSavedPoint(87, 143707.2);
   f21003->SetSavedPoint(88, 142832.5);
   f21003->SetSavedPoint(89, 141957.8);
   f21003->SetSavedPoint(90, 141083.1);
   f21003->SetSavedPoint(91, 140208.4);
   f21003->SetSavedPoint(92, 139333.7);
   f21003->SetSavedPoint(93, 138459);
   f21003->SetSavedPoint(94, 137584.3);
   f21003->SetSavedPoint(95, 136709.5);
   f21003->SetSavedPoint(96, 135834.8);
   f21003->SetSavedPoint(97, 134960.1);
   f21003->SetSavedPoint(98, 134085.4);
   f21003->SetSavedPoint(99, 133210.7);
   f21003->SetSavedPoint(100, 0);
   f21003->SetSavedPoint(101, -20);
   f21003->SetSavedPoint(102, 200);
   f21003->SetFillColor(19);
   f21003->SetFillStyle(0);
   f21003->SetLineColor(2);
   f21003->SetLineWidth(2);
   f21003->SetLineStyle(2);
   f21003->SetChisquare(245.6029);
   f21003->SetNDF(8);
   f21003->GetXaxis()->SetLabelFont(42);
   f21003->GetXaxis()->SetTitleOffset(1);
   f21003->GetXaxis()->SetTitleFont(42);
   f21003->GetYaxis()->SetLabelFont(42);
   f21003->GetYaxis()->SetTitleFont(42);
   f21003->SetParameter(0, -397.5917);
   f21003->SetParError(0, 1.8607);
   f21003->SetParLimits(0, 0, 0);
   f21003->SetParameter(1, 211854.4);
   f21003->SetParError(1, 209.5193);
   f21003->SetParLimits(1, 0, 0);
   f21003->SetParent(gre);
   gre->GetListOfFunctions()->Add(f21003);

   TPaveStats *ptstats = new TPaveStats(0.1993988, 0.7740741, 0.3026052, 0.8525926, "brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 113.7 / 8");
   ptstats_LaTex = ptstats->AddText("p0       = 416.5 #pm  1.81 ");
   ptstats_LaTex = ptstats->AddText("p1       = 2.007e+05 #pm 169.6 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");

   ptstats = new TPaveStats(0.1012024, 0.7333333, 0.4599198, 0.8933333, "brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 113.7 / 8");
   ptstats_LaTex = ptstats->AddText("b1       = 416.5 #pm  1.81 ");
   ptstats_LaTex = ptstats->AddText("a1       = 2.007e+05 #pm 169.6 ");
   ptstats_LaTex = ptstats->AddText("#rho       = 0.999");
   ptstats_LaTex = ptstats->AddText("T_Student       = 61.0");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();

   ptstats = new TPaveStats(0.6292585, 0.7333333, 0.987976, 0.8933333, "brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   TText *ptstats_LaTex1 = ptstats->AddText("#chi^{2} / ndf = 245.6 / 8");
   ptstats_LaTex1 = ptstats->AddText("b2      = -397.6 #pm 1.861 ");
   ptstats_LaTex1 = ptstats->AddText("a2       = 2.119e+05 #pm 209.5 ");
   ptstats_LaTex1 = ptstats->AddText("#rho       = -0.997");
   ptstats_LaTex1 = ptstats->AddText("T_Student       = -37.7");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   TLine *line = new TLine(13.752, 141400, 13.752, 209874);

   ci = TColor::GetColor("#0066ff");
   line->SetLineColor(ci);
   line->SetLineStyle(3);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *tex = new TLatex(10, 148261.4, "x_{center}#pm#sigma_{x_center} = (13.8 #pm 0.3) p.m.");
   tex->SetTextFont(32);
   tex->SetTextSize(0.03259259);
   tex->SetTextAngle(90.63191);
   tex->SetLineWidth(2);
   tex->Draw();

   TPaveText *pt = new TPaveText(0.3171543, 0.94, 0.6828457, 0.995, "blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(22);
   pt->Draw();

   Double_t Graph0_fx1[628] = {
       -3000,
       -2990,
       -2980,
       -2970,
       -2960,
       -2950,
       -2940,
       -2930,
       -2920,
       -2910,
       -2900,
       -2890,
       -2880,
       -2870,
       -2860,
       -2850,
       -2840,
       -2830,
       -2820,
       -2810,
       -2800,
       -2790,
       -2780,
       -2770,
       -2760,
       -2750,
       -2740,
       -2730,
       -2720,
       -2710,
       -2700,
       -2690,
       -2680,
       -2670,
       -2660,
       -2650,
       -2640,
       -2630,
       -2620,
       -2610,
       -2600,
       -2590,
       -2580,
       -2570,
       -2560,
       -2550,
       -2540,
       -2530,
       -2520,
       -2510,
       -2500,
       -2490,
       -2480,
       -2470,
       -2460,
       -2450,
       -2440,
       -2430,
       -2420,
       -2410,
       -2400,
       -2390,
       -2380,
       -2370,
       -2360,
       -2350,
       -2340,
       -2330,
       -2320,
       -2310,
       -2300,
       -2290,
       -2280,
       -2270,
       -2260,
       -2250,
       -2240,
       -2230,
       -2220,
       -2210,
       -2200,
       -2190,
       -2180,
       -2170,
       -2160,
       -2150,
       -2140,
       -2130,
       -2120,
       -2110,
       -2100,
       -2090,
       -2080,
       -2070,
       -2060,
       -2050,
       -2040,
       -2030,
       -2020,
       -2010,
       -2000,
       -1990,
       -1980,
       -1970,
       -1960,
       -1950,
       -1940,
       -1930,
       -1920,
       -1910,
       -1900,
       -1890,
       -1880,
       -1870,
       -1860,
       -1850,
       -1840,
       -1830,
       -1820,
       -1810,
       -1800,
       -1790,
       -1780,
       -1770,
       -1760,
       -1750,
       -1740,
       -1730,
       -1720,
       -1710,
       -1700,
       -1690,
       -1680,
       -1670,
       -1660,
       -1650,
       -1640,
       -1630,
       -1620,
       -1610,
       -1600,
       -1590,
       -1580,
       -1570,
       -1560,
       -1550,
       -1540,
       -1530,
       -1520,
       -1510,
       -1500,
       -1490,
       -1480,
       -1470,
       -1460,
       -1450,
       -1440,
       -1430,
       -1420,
       -1410,
       -1400,
       -1390,
       -1380,
       -1370,
       -1360,
       -1350,
       -1340,
       -1330,
       -1320,
       -1310,
       -1300,
       -1290,
       -1280,
       -1270,
       -1260,
       -1250,
       -1240,
       -1230,
       -1220,
       -1210,
       -1200,
       -1190,
       -1180,
       -1170,
       -1160,
       -1150,
       -1140,
       -1130,
       -1120,
       -1110,
       -1100,
       -1090,
       -1080,
       -1070,
       -1060,
       -1050,
       -1040,
       -1030,
       -1020,
       -1010,
       -1000,
       -990,
       -980,
       -970,
       -960,
       -950,
       -940,
       -930,
       -920,
       -910,
       -900,
       -890,
       -880,
       -870,
       -860,
       -850,
       -840,
       -830,
       -820,
       -810,
       -800,
       -790,
       -780,
       -770,
       -760,
       -750,
       -740,
       -730,
       -720,
       -710,
       -700,
       -690,
       -680,
       -670,
       -660,
       -650,
       -640,
       -630,
       -620,
       -610,
       -600,
       -590,
       -580,
       -570,
       -560,
       -550,
       -540,
       -530,
       -520,
       -510,
       -500,
       -490,
       -480,
       -470,
       -460,
       -450,
       -440,
       -430,
       -420,
       -410,
       -400,
       -390,
       -380,
       -370,
       -360,
       -350,
       -340,
       -330,
       -320,
       -310,
       -300,
       -290,
       -280,
       -270,
       -260,
       -250,
       -240,
       -230,
       -220,
       -210,
       -200,
       -190,
       -180,
       -170,
       -160,
       -150,
       -140,
       -30,
       -20,
       -10,
       0,
       10,
       20,
       30,
       40,
       50,
       170,
       180,
       190,
       200,
       210,
       220,
       230,
       240,
       250,
       260,
       270,
       280,
       290,
       300,
       310,
       320,
       330,
       340,
       350,
       360,
       370,
       380,
       390,
       400,
       410,
       420,
       430,
       440,
       450,
       460,
       470,
       480,
       490,
       500,
       510,
       520,
       530,
       540,
       550,
       560,
       570,
       580,
       590,
       600,
       610,
       620,
       630,
       640,
       650,
       660,
       670,
       680,
       690,
       700,
       710,
       720,
       730,
       740,
       750,
       760,
       770,
       780,
       790,
       800,
       810,
       820,
       830,
       840,
       850,
       860,
       870,
       880,
       890,
       900,
       910,
       920,
       930,
       940,
       950,
       960,
       970,
       980,
       990,
       1000,
       1010,
       1020,
       1030,
       1040,
       1050,
       1060,
       1070,
       1080,
       1090,
       1100,
       1110,
       1120,
       1130,
       1140,
       1150,
       1160,
       1170,
       1180,
       1190,
       1200,
       1210,
       1220,
       1230,
       1240,
       1250,
       1260,
       1270,
       1280,
       1290,
       1300,
       1310,
       1320,
       1330,
       1340,
       1350,
       1360,
       1370,
       1380,
       1390,
       1400,
       1410,
       1420,
       1430,
       1440,
       1450,
       1460,
       1470,
       1480,
       1490,
       1500,
       1510,
       1520,
       1530,
       1540,
       1550,
       1560,
       1570,
       1580,
       1590,
       1600,
       1610,
       1620,
       1630,
       1640,
       1650,
       1660,
       1670,
       1680,
       1690,
       1700,
       1710,
       1720,
       1730,
       1740,
       1750,
       1760,
       1770,
       1780,
       1790,
       1800,
       1810,
       1820,
       1830,
       1840,
       1850,
       1860,
       1870,
       1880,
       1890,
       1900,
       1910,
       1920,
       1930,
       1940,
       1950,
       1960,
       1970,
       1980,
       1990,
       2000,
       2010,
       2020,
       2030,
       2040,
       2050,
       2060,
       2070,
       2080,
       2090,
       2100,
       2110,
       2120,
       2130,
       2140,
       2150,
       2160,
       2170,
       2180,
       2190,
       2200,
       2210,
       2220,
       2230,
       2240,
       2250,
       2260,
       2270,
       2280,
       2290,
       2300,
       2310,
       2320,
       2330,
       2340,
       2350,
       2360,
       2370,
       2380,
       2390,
       2400,
       2410,
       2420,
       2430,
       2440,
       2450,
       2460,
       2470,
       2480,
       2490,
       2500,
       2510,
       2520,
       2530,
       2540,
       2550,
       2560,
       2570,
       2580,
       2590,
       2600,
       2610,
       2620,
       2630,
       2640,
       2650,
       2660,
       2670,
       2680,
       2690,
       2700,
       2710,
       2720,
       2730,
       2740,
       2750,
       2760,
       2770,
       2780,
       2790,
       2800,
       2810,
       2820,
       2830,
       2840,
       2850,
       2860,
       2870,
       2880,
       2890,
       2900,
       2910,
       2920,
       2930,
       2940,
       2950,
       2960,
       2970,
       2980,
       2990,
       3000,
       3010,
       3020,
       3030,
       3040,
       3050,
       3060,
       3070,
       3080,
       3090,
       3100,
       3110,
       3120,
       3130,
       3140,
       3150,
       3160,
       3170,
       3180,
       3190,
       3200,
       3210,
       3220,
       3230,
       3240,
       3250,
       3260,
       3270,
       3280,
       3290,
       3300,
       3310,
       3320,
       3330,
       3340,
       3350,
       3360,
       3370,
       3380,
       3390,
       3400,
       3410,
       3420,
       3430,
       3440,
       3450,
       3460,
       3470,
       3480};
   Double_t Graph0_fy1[628] = {
       7829,
       8289,
       8290,
       8268,
       8237,
       8224,
       8179,
       8153,
       8127,
       8103,
       8104,
       8064,
       8070,
       8059,
       8059,
       8074,
       8081,
       8105,
       8129,
       8148,
       8177,
       8199,
       8232,
       8266,
       8320,
       8366,
       8416,
       8464,
       8517,
       8535,
       8569,
       8609,
       8637,
       8674,
       8694,
       8703,
       8687,
       8690,
       8674,
       8647,
       8615,
       8588,
       8545,
       8500,
       8446,
       8386,
       8341,
       8282,
       8215,
       8191,
       8142,
       8121,
       8082,
       8058,
       8046,
       8046,
       8050,
       8078,
       8115,
       8158,
       8217,
       8272,
       8338,
       8413,
       8509,
       8608,
       8711,
       8809,
       8925,
       9012,
       9111,
       9193,
       9294,
       9374,
       9437,
       9475,
       9517,
       9538,
       9524,
       9522,
       9493,
       9442,
       9382,
       9304,
       9217,
       9129,
       9007,
       8889,
       8780,
       8665,
       8552,
       8437,
       8342,
       8222,
       8124,
       8044,
       7993,
       7963,
       7955,
       7983,
       8030,
       8097,
       8199,
       8332,
       8502,
       8717,
       8939,
       9179,
       9418,
       9687,
       9939,
       10204,
       10473,
       10739,
       10976,
       11192,
       11390,
       11562,
       11714,
       11818,
       11885,
       11904,
       11897,
       11863,
       11768,
       11646,
       11465,
       11254,
       11027,
       10807,
       10570,
       10334,
       10072,
       9771,
       9488,
       9203,
       8963,
       8734,
       8551,
       8407,
       8309,
       8274,
       8259,
       8301,
       8379,
       8547,
       8764,
       9027,
       9353,
       9707,
       10109,
       10575,
       11052,
       11552,
       12073,
       12604,
       13152,
       13705,
       14203,
       14616,
       15082,
       15498,
       15801,
       16064,
       16281,
       16414,
       16468,
       16459,
       16371,
       16211,
       15976,
       15721,
       15377,
       14961,
       14499,
       14007,
       13460,
       12924,
       12432,
       11931,
       11528,
       11171,
       10867,
       10610,
       10446,
       10387,
       10425,
       10594,
       10863,
       11257,
       11749,
       12400,
       13133,
       13956,
       14881,
       15908,
       16983,
       18090,
       19160,
       20128,
       21354,
       22673,
       23710,
       24713,
       25629,
       26475,
       27221,
       27866,
       28386,
       28757,
       28975,
       29112,
       29153,
       29004,
       28703,
       28299,
       27765,
       27153,
       26451,
       25751,
       25019,
       24306,
       23597,
       22870,
       22169,
       21558,
       21080,
       20736,
       20516,
       20472,
       20614,
       20949,
       21496,
       22247,
       23218,
       24401,
       25790,
       27390,
       28949,
       30523,
       32725,
       35412,
       37769,
       40258,
       42789,
       45490,
       48146,
       50898,
       53664,
       56184,
       58565,
       60753,
       63021,
       65334,
       67452,
       69484,
       71465,
       73377,
       75012,
       76330,
       77477,
       78648,
       79688,
       80787,
       81909,
       83027,
       84077,
       85093,
       86254,
       87643,
       89044,
       90554,
       92357,
       94334,
       96577,
       99055,
       101768,
       104722,
       107606,
       110422,
       114296,
       118940,
       123250,
       127343,
       132057,
       136260,
       141303,
       185689,
       186060,
       186495,
       186840,
       187235,
       187393,
       187262,
       186968,
       186859,
       141622,
       136527,
       133093,
       128058,
       123163,
       119024,
       115231,
       111714,
       108189,
       105115,
       102051,
       99233,
       96837,
       94809,
       93268,
       91600,
       90139,
       88739,
       87545,
       86410,
       85387,
       84365,
       83450,
       82607,
       81824,
       80971,
       79750,
       78335,
       76791,
       75187,
       73466,
       71614,
       69674,
       67618,
       65305,
       62825,
       60136,
       57377,
       54550,
       51718,
       48888,
       46238,
       43885,
       41109,
       37939,
       35402,
       33009,
       30815,
       28789,
       26937,
       25270,
       23784,
       22572,
       21655,
       20970,
       20392,
       20003,
       19878,
       19895,
       20154,
       20528,
       21024,
       21648,
       22280,
       22945,
       23626,
       24353,
       25091,
       25777,
       26389,
       26925,
       27330,
       27596,
       27710,
       27660,
       27546,
       27230,
       26871,
       26369,
       25732,
       24978,
       24136,
       23284,
       22334,
       21082,
       20060,
       18870,
       17822,
       16815,
       15783,
       14786,
       13823,
       13010,
       12327,
       11736,
       11177,
       10686,
       10351,
       10122,
       10022,
       10010,
       10121,
       10304,
       10584,
       10909,
       11316,
       11794,
       12282,
       12825,
       13366,
       13904,
       14387,
       14839,
       15260,
       15661,
       15977,
       16220,
       16377,
       16469,
       16497,
       16462,
       16352,
       16179,
       15966,
       15580,
       15234,
       14819,
       14384,
       13885,
       13405,
       12868,
       12349,
       11811,
       11343,
       10916,
       10473,
       10029,
       9639,
       9293,
       8990,
       8750,
       8566,
       8458,
       8377,
       8356,
       8373,
       8429,
       8516,
       8643,
       8809,
       8987,
       9155,
       9343,
       9520,
       9730,
       9926,
       10104,
       10267,
       10399,
       10512,
       10613,
       10663,
       10696,
       10710,
       10694,
       10650,
       10583,
       10500,
       10390,
       10269,
       10136,
       9982,
       9819,
       9666,
       9517,
       9356,
       9177,
       8998,
       8830,
       8682,
       8525,
       8396,
       8285,
       8189,
       8115,
       8047,
       8010,
       7975,
       7954,
       7953,
       7950,
       7991,
       8029,
       8051,
       8105,
       8164,
       8199,
       8250,
       8307,
       8380,
       8424,
       8453,
       8497,
       8546,
       8573,
       8606,
       8606,
       8617,
       8623,
       8614,
       8602,
       8571,
       8550,
       8519,
       8469,
       8434,
       8393,
       8355,
       8306,
       8243,
       8190,
       8144,
       8106,
       8056,
       8031,
       8009,
       7993,
       7967,
       7956,
       7950,
       7931,
       7960,
       7945,
       7965,
       7984,
       7999,
       8018,
       8044,
       8074,
       8089,
       8106,
       8124,
       8164,
       8185,
       8206,
       8236,
       8248,
       8261,
       8277,
       8284,
       8266,
       8258,
       8261,
       8237,
       8235,
       8210,
       8209,
       8179,
       8163,
       8139,
       8138,
       8110,
       8090,
       8082,
       8069,
       8070,
       8068,
       8046,
       8045,
       8031,
       8029,
       8040,
       8034,
       8039,
       8039,
       8037,
       8052,
       8074,
       8084,
       8092,
       8084,
       8088,
       8100,
       8105,
       8124,
       8113,
       8128,
       8125,
       8117,
       8125,
       8103,
       8121,
       8092,
       8088,
       8076,
       8076,
       8063,
       8047,
       8034,
       8028,
       8038,
       8017,
       8000,
       8003,
       7992,
       7994,
       7984,
       7969,
       7956,
       7952,
       7957,
       7962,
       7959,
       7966,
       7972,
       7988,
       7988,
       8007,
       8013,
       8032,
       8047,
       8060,
       8072,
       8081,
       8099,
       8116,
       8127,
       8134,
       8127,
       8145,
       8133,
       8135};
   TGraph *graph = new TGraph(628, Graph0_fx1, Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Grafico 1f_10p_sgnbkg.xls");
   graph->SetFillStyle(1000);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(5);
   graph->SetMarkerSize(0.8);

   TH1F *Graph_Graph_Graph_Graph_Graph01111 = new TH1F("Graph_Graph_Graph_Graph_Graph01111", "Grafico 1f_10p_sgnbkg.xls", 649, -3648, 4128);
   Graph_Graph_Graph_Graph_Graph01111->SetMinimum(7046.1);
   Graph_Graph_Graph_Graph_Graph01111->SetMaximum(205349.4);
   Graph_Graph_Graph_Graph_Graph01111->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph01111->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_Graph01111->SetLineColor(ci);
   Graph_Graph_Graph_Graph_Graph01111->GetXaxis()->SetTitle("Passi Motore");
   Graph_Graph_Graph_Graph_Graph01111->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph_Graph_Graph01111->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph01111->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph_Graph_Graph01111->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_Graph01111->GetYaxis()->SetTitle("Intensità [Boh]");
   Graph_Graph_Graph_Graph_Graph01111->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph_Graph_Graph01111->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph01111->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_Graph01111->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph01111->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph_Graph_Graph01111->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph_Graph_Graph01111);

   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);

   TLegend *leg = new TLegend(0.15,0.15,0.5,0.3,NULL,"brNDC");
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
   entry=leg->AddEntry("Graph","Dati Misurati con errore","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   Int_t aa;      // for color index setting
   TColor *color2; // for color definition with alpha
   aa = TColor::GetColor("#0066ff");
   entry->SetMarkerColor(aa);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("f2","a+bx interpolante","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
}
