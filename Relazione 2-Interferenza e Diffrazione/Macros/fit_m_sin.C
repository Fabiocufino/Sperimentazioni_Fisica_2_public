void fit_m_sin()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Sat Dec 26 14:52:41 2020) by ROOT version 6.22/06
   TCanvas *c1 = new TCanvas("c1", "Canvas",699,-104,1000,700);
   c1->Range(-10.67491,-0.07948434,9.997123,0.07822442);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetRightMargin(0.0240481);
   c1->SetTopMargin(0.0237037);
   c1->SetBottomMargin(0.07851852);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[13] = {
   -7,
   -6,
   -5,
   -4,
   -3,
   -2,
   2,
   3,
   4,
   5,
   6,
   7,
   8};
   Double_t Graph0_fy1001[13] = {
   -0.05489984,
   -0.04699003,
   -0.03885262,
   -0.03048788,
   -0.02220338,
   -0.01389152,
   0.0139217,
   0.02199018,
   0.03048205,
   0.03900175,
   0.04686615,
   0.05464622,
   0.06216462};
   Double_t Graph0_fex1001[13] = {
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
   Double_t Graph0_fey1001[13] = {
   0.0004024803,
   0.0003439514,
   0.0002820112,
   0.0002213863,
   0.0001613655,
   0.0001011452,
   0.0001013694,
   0.000159793,
   0.0002213729,
   0.0002832772,
   0.0003452908,
   0.0004627943,
   0.0005225695};
   TGraphErrors *gre = new TGraphErrors(13,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.4);
   
   TH1F *Graph_Graph_Graph010011001 = new TH1F("Graph_Graph_Graph010011001","Graph",100,-8.5,9.5);
   Graph_Graph_Graph010011001->SetMinimum(-0.06710128);
   Graph_Graph_Graph010011001->SetMaximum(0.07448614);
   Graph_Graph_Graph010011001->SetDirectory(0);
   Graph_Graph_Graph010011001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph010011001->SetLineColor(ci);
   Graph_Graph_Graph010011001->GetXaxis()->SetTitle("m");
   Graph_Graph_Graph010011001->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph010011001->GetXaxis()->SetLabelFont(22);
   Graph_Graph_Graph010011001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010011001->GetXaxis()->SetTitleFont(22);
   Graph_Graph_Graph010011001->GetYaxis()->SetTitle("sin(#theta)");
   Graph_Graph_Graph010011001->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph010011001->GetYaxis()->SetLabelFont(22);
   Graph_Graph_Graph010011001->GetYaxis()->SetTitleFont(22);
   Graph_Graph_Graph010011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph010011001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010011001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph010011001);
   
   
   TF1 *f11002 = new TF1("*f1",-10,10,2);
    //The original function : f1 had originally been created by:
    //TF1 *f1 = new TF1("f1",f1,-10,10,2, 1, TF1::EAddToList::kNo);
   f11002->SetRange(-10,10);
   f11002->SetName("f1");
   f11002->SetTitle("f1");
   f11002->SetSavedPoint(0,-0.07541662);
   f11002->SetSavedPoint(1,-0.07390842);
   f11002->SetSavedPoint(2,-0.07240022);
   f11002->SetSavedPoint(3,-0.07089201);
   f11002->SetSavedPoint(4,-0.06938381);
   f11002->SetSavedPoint(5,-0.06787561);
   f11002->SetSavedPoint(6,-0.06636741);
   f11002->SetSavedPoint(7,-0.0648592);
   f11002->SetSavedPoint(8,-0.063351);
   f11002->SetSavedPoint(9,-0.0618428);
   f11002->SetSavedPoint(10,-0.06033459);
   f11002->SetSavedPoint(11,-0.05882639);
   f11002->SetSavedPoint(12,-0.05731819);
   f11002->SetSavedPoint(13,-0.05580999);
   f11002->SetSavedPoint(14,-0.05430178);
   f11002->SetSavedPoint(15,-0.05279358);
   f11002->SetSavedPoint(16,-0.05128538);
   f11002->SetSavedPoint(17,-0.04977717);
   f11002->SetSavedPoint(18,-0.04826897);
   f11002->SetSavedPoint(19,-0.04676077);
   f11002->SetSavedPoint(20,-0.04525256);
   f11002->SetSavedPoint(21,-0.04374436);
   f11002->SetSavedPoint(22,-0.04223616);
   f11002->SetSavedPoint(23,-0.04072796);
   f11002->SetSavedPoint(24,-0.03921975);
   f11002->SetSavedPoint(25,-0.03771155);
   f11002->SetSavedPoint(26,-0.03620335);
   f11002->SetSavedPoint(27,-0.03469514);
   f11002->SetSavedPoint(28,-0.03318694);
   f11002->SetSavedPoint(29,-0.03167874);
   f11002->SetSavedPoint(30,-0.03017054);
   f11002->SetSavedPoint(31,-0.02866233);
   f11002->SetSavedPoint(32,-0.02715413);
   f11002->SetSavedPoint(33,-0.02564593);
   f11002->SetSavedPoint(34,-0.02413772);
   f11002->SetSavedPoint(35,-0.02262952);
   f11002->SetSavedPoint(36,-0.02112132);
   f11002->SetSavedPoint(37,-0.01961312);
   f11002->SetSavedPoint(38,-0.01810491);
   f11002->SetSavedPoint(39,-0.01659671);
   f11002->SetSavedPoint(40,-0.01508851);
   f11002->SetSavedPoint(41,-0.0135803);
   f11002->SetSavedPoint(42,-0.0120721);
   f11002->SetSavedPoint(43,-0.0105639);
   f11002->SetSavedPoint(44,-0.009055695);
   f11002->SetSavedPoint(45,-0.007547492);
   f11002->SetSavedPoint(46,-0.006039289);
   f11002->SetSavedPoint(47,-0.004531087);
   f11002->SetSavedPoint(48,-0.003022884);
   f11002->SetSavedPoint(49,-0.001514681);
   f11002->SetSavedPoint(50,-6.477828e-06);
   f11002->SetSavedPoint(51,0.001501725);
   f11002->SetSavedPoint(52,0.003009928);
   f11002->SetSavedPoint(53,0.004518131);
   f11002->SetSavedPoint(54,0.006026334);
   f11002->SetSavedPoint(55,0.007534537);
   f11002->SetSavedPoint(56,0.00904274);
   f11002->SetSavedPoint(57,0.01055094);
   f11002->SetSavedPoint(58,0.01205915);
   f11002->SetSavedPoint(59,0.01356735);
   f11002->SetSavedPoint(60,0.01507555);
   f11002->SetSavedPoint(61,0.01658375);
   f11002->SetSavedPoint(62,0.01809196);
   f11002->SetSavedPoint(63,0.01960016);
   f11002->SetSavedPoint(64,0.02110836);
   f11002->SetSavedPoint(65,0.02261657);
   f11002->SetSavedPoint(66,0.02412477);
   f11002->SetSavedPoint(67,0.02563297);
   f11002->SetSavedPoint(68,0.02714117);
   f11002->SetSavedPoint(69,0.02864938);
   f11002->SetSavedPoint(70,0.03015758);
   f11002->SetSavedPoint(71,0.03166578);
   f11002->SetSavedPoint(72,0.03317399);
   f11002->SetSavedPoint(73,0.03468219);
   f11002->SetSavedPoint(74,0.03619039);
   f11002->SetSavedPoint(75,0.03769859);
   f11002->SetSavedPoint(76,0.0392068);
   f11002->SetSavedPoint(77,0.040715);
   f11002->SetSavedPoint(78,0.0422232);
   f11002->SetSavedPoint(79,0.04373141);
   f11002->SetSavedPoint(80,0.04523961);
   f11002->SetSavedPoint(81,0.04674781);
   f11002->SetSavedPoint(82,0.04825602);
   f11002->SetSavedPoint(83,0.04976422);
   f11002->SetSavedPoint(84,0.05127242);
   f11002->SetSavedPoint(85,0.05278062);
   f11002->SetSavedPoint(86,0.05428883);
   f11002->SetSavedPoint(87,0.05579703);
   f11002->SetSavedPoint(88,0.05730523);
   f11002->SetSavedPoint(89,0.05881344);
   f11002->SetSavedPoint(90,0.06032164);
   f11002->SetSavedPoint(91,0.06182984);
   f11002->SetSavedPoint(92,0.06333804);
   f11002->SetSavedPoint(93,0.06484625);
   f11002->SetSavedPoint(94,0.06635445);
   f11002->SetSavedPoint(95,0.06786265);
   f11002->SetSavedPoint(96,0.06937086);
   f11002->SetSavedPoint(97,0.07087906);
   f11002->SetSavedPoint(98,0.07238726);
   f11002->SetSavedPoint(99,0.07389546);
   f11002->SetSavedPoint(100,0.07540367);
   f11002->SetSavedPoint(101,-10);
   f11002->SetSavedPoint(102,10);
   f11002->SetFillColor(19);
   f11002->SetFillStyle(0);
   f11002->SetLineColor(2);
   f11002->SetLineWidth(2);
   f11002->SetLineStyle(2);
   f11002->SetChisquare(437.4746);
   f11002->SetNDF(11);
   f11002->GetXaxis()->SetLabelFont(42);
   f11002->GetXaxis()->SetTitleOffset(1);
   f11002->GetXaxis()->SetTitleFont(42);
   f11002->GetYaxis()->SetLabelFont(42);
   f11002->GetYaxis()->SetTitleFont(42);
   f11002->SetParameter(0,0.007541015);
   f11002->SetParError(0,1.556416e-05);
   f11002->SetParLimits(0,0,0);
   f11002->SetParameter(1,-6.477828e-06);
   f11002->SetParError(1,5.200636e-05);
   f11002->SetParLimits(1,0,0);
   f11002->SetParent(gre);
   gre->GetListOfFunctions()->Add(f11002);
   gre->Draw("ap");
   
   TPaveStats *ptstats = new TPaveStats(0.5621242,0.1037037,0.9569138,0.2859259,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 275.6 / 11");
   ptstats_LaTex = ptstats->AddText("b_{alg}       = 0.007616 #pm 1.731e-05 ");
   ptstats_LaTex = ptstats->AddText("a_{alg}       = 1.093e-05 #pm 6.611e-05 ");
   ptstats_LaTex = ptstats->AddText("#rho       = 0.99975");
   ptstats_LaTex = ptstats->AddText("T_Student       = 149.5");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   ptstats = new TPaveStats(0.5621242,0.3214815,0.9569138,0.5037037,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 437.5 / 11");
   ptstats_LaTex = ptstats->AddText("b_{par}       = 0.007541 #pm 1.556e-05 ");
   ptstats_LaTex = ptstats->AddText("a_{par}      = -6.478e-06 #pm 5.201e-05 ");
   ptstats_LaTex = ptstats->AddText("#rho       = 0.99977");
   ptstats_LaTex = ptstats->AddText("T_Student       = 154.4");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   
   Double_t Graph1_fx1003[13] = {
   -7,
   -6,
   -5,
   -4,
   -3,
   -2,
   2,
   3,
   4,
   5,
   6,
   7,
   8};
   Double_t Graph1_fy1003[13] = {
   -0.05495027,
   -0.04715648,
   -0.03878285,
   -0.03040105,
   -0.02220352,
   -0.01381073,
   0.01385837,
   0.02206044,
   0.03044863,
   0.03921121,
   0.04682356,
   0.05442776,
   0.06183277};
   Double_t Graph1_fex1003[13] = {
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
   Double_t Graph1_fey1003[13] = {
   0.0004128085,
   0.0003590195,
   0.0003020571,
   0.0002466068,
   0.0001953068,
   0.0001491013,
   0.000149334,
   0.0001944518,
   0.000246915,
   0.0003049412,
   0.0003567353,
   0.0004091867,
   0.0004606592};
   gre = new TGraphErrors(13,Graph1_fx1003,Graph1_fy1003,Graph1_fex1003,Graph1_fey1003);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0066ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph_Graph110031003 = new TH1F("Graph_Graph_Graph110031003","Graph",100,-8.5,9.5);
   Graph_Graph_Graph110031003->SetMinimum(-0.06712873);
   Graph_Graph_Graph110031003->SetMaximum(0.07405908);
   Graph_Graph_Graph110031003->SetDirectory(0);
   Graph_Graph_Graph110031003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph110031003->SetLineColor(ci);
   Graph_Graph_Graph110031003->GetXaxis()->SetTitle("m");
   Graph_Graph_Graph110031003->GetXaxis()->SetAxisColor(14);
   Graph_Graph_Graph110031003->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph110031003->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph110031003->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph110031003->GetYaxis()->SetTitle("sin(#theta)");
   Graph_Graph_Graph110031003->GetYaxis()->SetAxisColor(14);
   Graph_Graph_Graph110031003->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph110031003->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph110031003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph110031003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph110031003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph110031003);
   
   
   TF1 *f21004 = new TF1("*f2",-10,10,2);
    //The original function : f2 had originally been created by:
    //TF1 *f2 = new TF1("f2",f2,-10,10,2, 1, TF1::EAddToList::kNo);
   f21004->SetRange(-10,10);
   f21004->SetName("f2");
   f21004->SetTitle("f2");
   f21004->SetSavedPoint(0,-0.07614533);
   f21004->SetSavedPoint(1,-0.0746222);
   f21004->SetSavedPoint(2,-0.07309908);
   f21004->SetSavedPoint(3,-0.07157595);
   f21004->SetSavedPoint(4,-0.07005283);
   f21004->SetSavedPoint(5,-0.0685297);
   f21004->SetSavedPoint(6,-0.06700658);
   f21004->SetSavedPoint(7,-0.06548345);
   f21004->SetSavedPoint(8,-0.06396033);
   f21004->SetSavedPoint(9,-0.0624372);
   f21004->SetSavedPoint(10,-0.06091408);
   f21004->SetSavedPoint(11,-0.05939095);
   f21004->SetSavedPoint(12,-0.05786783);
   f21004->SetSavedPoint(13,-0.0563447);
   f21004->SetSavedPoint(14,-0.05482158);
   f21004->SetSavedPoint(15,-0.05329845);
   f21004->SetSavedPoint(16,-0.05177533);
   f21004->SetSavedPoint(17,-0.0502522);
   f21004->SetSavedPoint(18,-0.04872908);
   f21004->SetSavedPoint(19,-0.04720595);
   f21004->SetSavedPoint(20,-0.04568283);
   f21004->SetSavedPoint(21,-0.0441597);
   f21004->SetSavedPoint(22,-0.04263657);
   f21004->SetSavedPoint(23,-0.04111345);
   f21004->SetSavedPoint(24,-0.03959032);
   f21004->SetSavedPoint(25,-0.0380672);
   f21004->SetSavedPoint(26,-0.03654407);
   f21004->SetSavedPoint(27,-0.03502095);
   f21004->SetSavedPoint(28,-0.03349782);
   f21004->SetSavedPoint(29,-0.0319747);
   f21004->SetSavedPoint(30,-0.03045157);
   f21004->SetSavedPoint(31,-0.02892845);
   f21004->SetSavedPoint(32,-0.02740532);
   f21004->SetSavedPoint(33,-0.0258822);
   f21004->SetSavedPoint(34,-0.02435907);
   f21004->SetSavedPoint(35,-0.02283595);
   f21004->SetSavedPoint(36,-0.02131282);
   f21004->SetSavedPoint(37,-0.0197897);
   f21004->SetSavedPoint(38,-0.01826657);
   f21004->SetSavedPoint(39,-0.01674345);
   f21004->SetSavedPoint(40,-0.01522032);
   f21004->SetSavedPoint(41,-0.0136972);
   f21004->SetSavedPoint(42,-0.01217407);
   f21004->SetSavedPoint(43,-0.01065095);
   f21004->SetSavedPoint(44,-0.009127823);
   f21004->SetSavedPoint(45,-0.007604698);
   f21004->SetSavedPoint(46,-0.006081573);
   f21004->SetSavedPoint(47,-0.004558448);
   f21004->SetSavedPoint(48,-0.003035323);
   f21004->SetSavedPoint(49,-0.001512198);
   f21004->SetSavedPoint(50,1.092712e-05);
   f21004->SetSavedPoint(51,0.001534052);
   f21004->SetSavedPoint(52,0.003057177);
   f21004->SetSavedPoint(53,0.004580302);
   f21004->SetSavedPoint(54,0.006103427);
   f21004->SetSavedPoint(55,0.007626552);
   f21004->SetSavedPoint(56,0.009149678);
   f21004->SetSavedPoint(57,0.0106728);
   f21004->SetSavedPoint(58,0.01219593);
   f21004->SetSavedPoint(59,0.01371905);
   f21004->SetSavedPoint(60,0.01524218);
   f21004->SetSavedPoint(61,0.0167653);
   f21004->SetSavedPoint(62,0.01828843);
   f21004->SetSavedPoint(63,0.01981155);
   f21004->SetSavedPoint(64,0.02133468);
   f21004->SetSavedPoint(65,0.0228578);
   f21004->SetSavedPoint(66,0.02438093);
   f21004->SetSavedPoint(67,0.02590405);
   f21004->SetSavedPoint(68,0.02742718);
   f21004->SetSavedPoint(69,0.0289503);
   f21004->SetSavedPoint(70,0.03047343);
   f21004->SetSavedPoint(71,0.03199655);
   f21004->SetSavedPoint(72,0.03351968);
   f21004->SetSavedPoint(73,0.0350428);
   f21004->SetSavedPoint(74,0.03656593);
   f21004->SetSavedPoint(75,0.03808905);
   f21004->SetSavedPoint(76,0.03961218);
   f21004->SetSavedPoint(77,0.0411353);
   f21004->SetSavedPoint(78,0.04265843);
   f21004->SetSavedPoint(79,0.04418155);
   f21004->SetSavedPoint(80,0.04570468);
   f21004->SetSavedPoint(81,0.0472278);
   f21004->SetSavedPoint(82,0.04875093);
   f21004->SetSavedPoint(83,0.05027405);
   f21004->SetSavedPoint(84,0.05179718);
   f21004->SetSavedPoint(85,0.0533203);
   f21004->SetSavedPoint(86,0.05484343);
   f21004->SetSavedPoint(87,0.05636655);
   f21004->SetSavedPoint(88,0.05788968);
   f21004->SetSavedPoint(89,0.0594128);
   f21004->SetSavedPoint(90,0.06093593);
   f21004->SetSavedPoint(91,0.06245906);
   f21004->SetSavedPoint(92,0.06398218);
   f21004->SetSavedPoint(93,0.06550531);
   f21004->SetSavedPoint(94,0.06702843);
   f21004->SetSavedPoint(95,0.06855156);
   f21004->SetSavedPoint(96,0.07007468);
   f21004->SetSavedPoint(97,0.07159781);
   f21004->SetSavedPoint(98,0.07312093);
   f21004->SetSavedPoint(99,0.07464406);
   f21004->SetSavedPoint(100,0.07616718);
   f21004->SetSavedPoint(101,-10);
   f21004->SetSavedPoint(102,10);
   f21004->SetFillColor(19);
   f21004->SetFillStyle(0);

   ci = TColor::GetColor("#0066ff");
   f21004->SetLineColor(ci);
   f21004->SetLineWidth(2);
   f21004->SetLineStyle(2);
   f21004->SetChisquare(275.5639);
   f21004->SetNDF(11);
   f21004->GetXaxis()->SetLabelFont(42);
   f21004->GetXaxis()->SetTitleOffset(1);
   f21004->GetXaxis()->SetTitleFont(42);
   f21004->GetYaxis()->SetLabelFont(42);
   f21004->GetYaxis()->SetTitleFont(42);
   f21004->SetParameter(0,0.007615625);
   f21004->SetParError(0,1.73052e-05);
   f21004->SetParLimits(0,0,0);
   f21004->SetParameter(1,1.092712e-05);
   f21004->SetParError(1,6.611385e-05);
   f21004->SetParLimits(1,0,0);
   f21004->SetParent(gre);
   gre->GetListOfFunctions()->Add(f21004);
   gre->Draw("p");
   
   TLegend *leg = new TLegend(0.1472946,0.6874074,0.4098196,0.9392593,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextFont(22);
   leg->SetTextSize(0.03111111);
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
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Minimi x^{alg}_{min}","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0066ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
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
   entry=leg->AddEntry("NULL","a+bx interpolante","l");

   ci = TColor::GetColor("#0066ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.4393988,0.9327778,0.5606012,0.995,"blNDC");
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
