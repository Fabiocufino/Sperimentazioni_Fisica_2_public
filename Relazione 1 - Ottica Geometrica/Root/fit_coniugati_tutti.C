void fit_coniugati_tutti()
{
//=========Macro generated from canvas: c1/Canvas
//=========  (Fri Dec 11 17:21:16 2020) by ROOT version 6.22/02
   TCanvas *c1 = new TCanvas("c1", "Canvas",51,194,2000,700);
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
   c1_1->Range(4.735499,3.328435,11.54045,10.23526);
   c1_1->SetFillColor(0);
   c1_1->SetBorderMode(0);
   c1_1->SetBorderSize(2);
   c1_1->SetGridx();
   c1_1->SetGridy();
   c1_1->SetRightMargin(0.004474773);
   c1_1->SetBottomMargin(0.07691462);
   c1_1->SetFrameBorderMode(0);
   c1_1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[20] = {
   11.3658,
   10.74999,
   10.2058,
   9.71031,
   9.26069,
   8.85086,
   8.47577,
   8.13118,
   7.81352,
   7.51974,
   7.24725,
   6.99382,
   6.75752,
   6.53666,
   6.32978,
   6.1356,
   5.95297,
   5.7809,
   5.6185,
   5.46498};
   Double_t Graph0_fy1001[20] = {
   3.94192,
   4.283588,
   4.99542,
   5.40005,
   5.9994,
   6.34182,
   6.76666,
   7.08299,
   7.3701,
   7.53674,
   7.77101,
   8.11798,
   8.47577,
   8.53364,
   8.68181,
   8.91398,
   9.07578,
   9.07578,
   9.24357,
   9.46223};
   Double_t Graph0_fex1001[20] = {
   0.0915983,
   0.0820121,
   0.0738556,
   0.0668581,
   0.0608099,
   0.0555468,
   0.0509386,
   0.0468809,
   0.0432894,
   0.0400953,
   0.0372422,
   0.034683,
   0.0323789,
   0.030297,
   0.0284096,
   0.0266933,
   0.0251279,
   0.0236962,
   0.0223836,
   0.021177};
   Double_t Graph0_fey1001[20] = {
   0.011018,
   0.0129847,
   0.0176943,
   0.0206768,
   0.0255214,
   0.0285178,
   0.0324666,
   0.0355731,
   0.0385155,
   0.0402768,
   0.0428197,
   0.0467287,
   0.0509386,
   0.0516364,
   0.0534452,
   0.0563419,
   0.0584058,
   0.0584058,
   0.0605853,
   0.0634856};
   TGraphErrors *gre = new TGraphErrors(20,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Operatore A");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","Operatore A",100,0,11.51);
   Graph_Graph01001->SetMinimum(3.859671);
   Graph_Graph01001->SetMaximum(9.550764);
   Graph_Graph01001->SetDirectory(0);
   Graph_Graph01001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01001->SetLineColor(ci);
   Graph_Graph01001->GetXaxis()->SetTitle("1/p [1/m]");
   Graph_Graph01001->GetXaxis()->SetRange(48,100);
   Graph_Graph01001->GetXaxis()->SetAxisColor(14);
   Graph_Graph01001->GetXaxis()->SetLabelFont(22);
   Graph_Graph01001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetXaxis()->SetTitleFont(22);
   Graph_Graph01001->GetYaxis()->SetTitle("1/q [1/m]");
   Graph_Graph01001->GetYaxis()->SetAxisColor(14);
   Graph_Graph01001->GetYaxis()->SetLabelFont(22);
   Graph_Graph01001->GetYaxis()->SetTitleFont(22);
   Graph_Graph01001->GetZaxis()->SetLabelFont(42);
   Graph_Graph01001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01001);
   
   
   TF1 *f11002 = new TF1("*f1",0,11.51,2);
    //The original function : f1 had originally been created by:
    //TF1 *f1 = new TF1("f1",f1,0,11.51,2, 1, TF1::EAddToList::kNo);
   f11002->SetRange(0,11.51);
   f11002->SetName("f1");
   f11002->SetTitle("f1");
   f11002->SetSavedPoint(0,14.70812);
   f11002->SetSavedPoint(1,14.59895);
   f11002->SetSavedPoint(2,14.48978);
   f11002->SetSavedPoint(3,14.3806);
   f11002->SetSavedPoint(4,14.27143);
   f11002->SetSavedPoint(5,14.16225);
   f11002->SetSavedPoint(6,14.05308);
   f11002->SetSavedPoint(7,13.9439);
   f11002->SetSavedPoint(8,13.83473);
   f11002->SetSavedPoint(9,13.72555);
   f11002->SetSavedPoint(10,13.61638);
   f11002->SetSavedPoint(11,13.5072);
   f11002->SetSavedPoint(12,13.39803);
   f11002->SetSavedPoint(13,13.28885);
   f11002->SetSavedPoint(14,13.17968);
   f11002->SetSavedPoint(15,13.0705);
   f11002->SetSavedPoint(16,12.96133);
   f11002->SetSavedPoint(17,12.85215);
   f11002->SetSavedPoint(18,12.74298);
   f11002->SetSavedPoint(19,12.6338);
   f11002->SetSavedPoint(20,12.52463);
   f11002->SetSavedPoint(21,12.41545);
   f11002->SetSavedPoint(22,12.30628);
   f11002->SetSavedPoint(23,12.1971);
   f11002->SetSavedPoint(24,12.08793);
   f11002->SetSavedPoint(25,11.97875);
   f11002->SetSavedPoint(26,11.86958);
   f11002->SetSavedPoint(27,11.7604);
   f11002->SetSavedPoint(28,11.65123);
   f11002->SetSavedPoint(29,11.54205);
   f11002->SetSavedPoint(30,11.43288);
   f11002->SetSavedPoint(31,11.3237);
   f11002->SetSavedPoint(32,11.21453);
   f11002->SetSavedPoint(33,11.10535);
   f11002->SetSavedPoint(34,10.99618);
   f11002->SetSavedPoint(35,10.887);
   f11002->SetSavedPoint(36,10.77783);
   f11002->SetSavedPoint(37,10.66865);
   f11002->SetSavedPoint(38,10.55948);
   f11002->SetSavedPoint(39,10.45031);
   f11002->SetSavedPoint(40,10.34113);
   f11002->SetSavedPoint(41,10.23196);
   f11002->SetSavedPoint(42,10.12278);
   f11002->SetSavedPoint(43,10.01361);
   f11002->SetSavedPoint(44,9.904431);
   f11002->SetSavedPoint(45,9.795256);
   f11002->SetSavedPoint(46,9.686081);
   f11002->SetSavedPoint(47,9.576906);
   f11002->SetSavedPoint(48,9.467731);
   f11002->SetSavedPoint(49,9.358557);
   f11002->SetSavedPoint(50,9.249382);
   f11002->SetSavedPoint(51,9.140207);
   f11002->SetSavedPoint(52,9.031032);
   f11002->SetSavedPoint(53,8.921857);
   f11002->SetSavedPoint(54,8.812682);
   f11002->SetSavedPoint(55,8.703507);
   f11002->SetSavedPoint(56,8.594332);
   f11002->SetSavedPoint(57,8.485158);
   f11002->SetSavedPoint(58,8.375983);
   f11002->SetSavedPoint(59,8.266808);
   f11002->SetSavedPoint(60,8.157633);
   f11002->SetSavedPoint(61,8.048458);
   f11002->SetSavedPoint(62,7.939283);
   f11002->SetSavedPoint(63,7.830108);
   f11002->SetSavedPoint(64,7.720934);
   f11002->SetSavedPoint(65,7.611759);
   f11002->SetSavedPoint(66,7.502584);
   f11002->SetSavedPoint(67,7.393409);
   f11002->SetSavedPoint(68,7.284234);
   f11002->SetSavedPoint(69,7.175059);
   f11002->SetSavedPoint(70,7.065884);
   f11002->SetSavedPoint(71,6.95671);
   f11002->SetSavedPoint(72,6.847535);
   f11002->SetSavedPoint(73,6.73836);
   f11002->SetSavedPoint(74,6.629185);
   f11002->SetSavedPoint(75,6.52001);
   f11002->SetSavedPoint(76,6.410835);
   f11002->SetSavedPoint(77,6.30166);
   f11002->SetSavedPoint(78,6.192486);
   f11002->SetSavedPoint(79,6.083311);
   f11002->SetSavedPoint(80,5.974136);
   f11002->SetSavedPoint(81,5.864961);
   f11002->SetSavedPoint(82,5.755786);
   f11002->SetSavedPoint(83,5.646611);
   f11002->SetSavedPoint(84,5.537436);
   f11002->SetSavedPoint(85,5.428261);
   f11002->SetSavedPoint(86,5.319087);
   f11002->SetSavedPoint(87,5.209912);
   f11002->SetSavedPoint(88,5.100737);
   f11002->SetSavedPoint(89,4.991562);
   f11002->SetSavedPoint(90,4.882387);
   f11002->SetSavedPoint(91,4.773212);
   f11002->SetSavedPoint(92,4.664037);
   f11002->SetSavedPoint(93,4.554863);
   f11002->SetSavedPoint(94,4.445688);
   f11002->SetSavedPoint(95,4.336513);
   f11002->SetSavedPoint(96,4.227338);
   f11002->SetSavedPoint(97,4.118163);
   f11002->SetSavedPoint(98,4.008988);
   f11002->SetSavedPoint(99,3.899813);
   f11002->SetSavedPoint(100,3.790639);
   f11002->SetSavedPoint(101,0);
   f11002->SetSavedPoint(102,11.51);
   f11002->SetFillColor(19);
   f11002->SetFillStyle(0);
   f11002->SetLineColor(2);
   f11002->SetLineWidth(2);
   f11002->SetLineStyle(2);
   f11002->SetChisquare(42.03934);
   f11002->SetNDF(18);
   f11002->GetXaxis()->SetLabelFont(42);
   f11002->GetXaxis()->SetTitleOffset(1);
   f11002->GetXaxis()->SetTitleFont(42);
   f11002->GetYaxis()->SetLabelFont(42);
   f11002->GetYaxis()->SetTitleFont(42);
   f11002->SetParameter(0,-0.9485218);
   f11002->SetParError(0,0.008835438);
   f11002->SetParLimits(0,0,0);
   f11002->SetParameter(1,14.70812);
   f11002->SetParError(1,0.06817422);
   f11002->SetParLimits(1,0,0);
   f11002->SetParent(gre);
   gre->GetListOfFunctions()->Add(f11002);
   
   TPaveStats *ptstats = new TPaveStats(0.5210223,0.6701217,0.9790077,0.9363993,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 42.04 / 18");
   ptstats_LaTex = ptstats->AddText("b        = -0.9485 #pm 0.008835 ");
   ptstats_LaTex = ptstats->AddText("a        = 14.71 #pm 0.06817 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   
   TLegend *leg = new TLegend(0.15,0.15,0.5,0.3,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","Coniugati","h");
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
   entry->SetLineWidth(2);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("f1","ax+b","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.342844,0.9346438,0.657156,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Operatore A");
   pt->Draw();
   c1_1->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_2
   TPad *c1_2 = new TPad("c1_2", "c1_2",0.3333433,1e-05,0.6666567,0.99999);
   c1_2->Draw();
   c1_2->cd();
   c1_2->Range(0.1920688,4.202948,10.17346,15.0136);
   c1_2->SetFillColor(0);
   c1_2->SetBorderMode(0);
   c1_2->SetBorderSize(2);
   c1_2->SetGridx();
   c1_2->SetGridy();
   c1_2->SetRightMargin(0.004474773);
   c1_2->SetBottomMargin(0.07691462);
   c1_2->SetFrameBorderMode(0);
   c1_2->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1004[21] = {
   9.990065,
   7.407521,
   5.870292,
   4.871094,
   4.163968,
   3.625938,
   3.210886,
   2.888068,
   2.62674,
   2.396155,
   2.211688,
   2.057965,
   1.919614,
   1.796636,
   1.68903,
   1.596796,
   1.504563,
   1.427701,
   1.366212,
   1.304723,
   1.243234};
   Double_t Graph0_fy1004[21] = {
   5.115574,
   7.711713,
   9.042234,
   10.56747,
   11.1516,
   11.2814,
   11.96289,
   12.10892,
   12.40099,
   12.70928,
   12.88776,
   13.05002,
   13.05002,
   13.22851,
   13.22851,
   13.58548,
   13.76396,
   13.39077,
   13.58548,
   13.76396,
   13.76396};
   Double_t Graph0_fex1004[21] = {
   0.0709305,
   0.038916,
   0.02454,
   0.0168753,
   0.0123119,
   0.00937725,
   0.00737924,
   0.00595788,
   0.00491088,
   0.00411743,
   0.00350183,
   0.00301463,
   0.00262246,
   0.00230212,
   0.00203708,
   0.00181531,
   0.00162788,
   0.00146804,
   0.00133064,
   0.00121167,
   0.00110797};
   Double_t Graph0_fey1004[21] = {
   0.0185174,
   0.0421619,
   0.0578793,
   0.0790935,
   0.0881586,
   0.0901579,
   0.101254,
   0.103718,
   0.108923,
   0.114531,
   0.117499,
   0.120583,
   0.120583,
   0.123791,
   0.123791,
   0.130602,
   0.13422,
   0.127128,
   0.130602,
   0.13422,
   0.13422};
   gre = new TGraphErrors(21,Graph0_fx1004,Graph0_fy1004,Graph0_fex1004,Graph0_fey1004);
   gre->SetName("Graph0");
   gre->SetTitle("Operatore B");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph01004 = new TH1F("Graph_Graph01004","Operatore B",100,0,11.51);
   Graph_Graph01004->SetMinimum(5.034444);
   Graph_Graph01004->SetMaximum(13.92622);
   Graph_Graph01004->SetDirectory(0);
   Graph_Graph01004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph01004->SetLineColor(ci);
   Graph_Graph01004->GetXaxis()->SetTitle("1/p [1/m]");
   Graph_Graph01004->GetXaxis()->SetRange(11,88);
   Graph_Graph01004->GetXaxis()->SetAxisColor(14);
   Graph_Graph01004->GetXaxis()->SetLabelFont(22);
   Graph_Graph01004->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01004->GetXaxis()->SetTitleFont(22);
   Graph_Graph01004->GetYaxis()->SetTitle("1/q [1/m]");
   Graph_Graph01004->GetYaxis()->SetAxisColor(14);
   Graph_Graph01004->GetYaxis()->SetLabelFont(22);
   Graph_Graph01004->GetYaxis()->SetTitleFont(22);
   Graph_Graph01004->GetZaxis()->SetLabelFont(42);
   Graph_Graph01004->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01004);
   
   
   TF1 *f21005 = new TF1("*f2",0,11.51,2);
    //The original function : f2 had originally been created by:
    //TF1 *f2 = new TF1("f2",f2,0,11.51,2, 1, TF1::EAddToList::kNo);
   f21005->SetRange(0,11.51);
   f21005->SetName("f2");
   f21005->SetTitle("f2");
   f21005->SetSavedPoint(0,15.04412);
   f21005->SetSavedPoint(1,14.93006);
   f21005->SetSavedPoint(2,14.81601);
   f21005->SetSavedPoint(3,14.70196);
   f21005->SetSavedPoint(4,14.58791);
   f21005->SetSavedPoint(5,14.47385);
   f21005->SetSavedPoint(6,14.3598);
   f21005->SetSavedPoint(7,14.24575);
   f21005->SetSavedPoint(8,14.1317);
   f21005->SetSavedPoint(9,14.01764);
   f21005->SetSavedPoint(10,13.90359);
   f21005->SetSavedPoint(11,13.78954);
   f21005->SetSavedPoint(12,13.67549);
   f21005->SetSavedPoint(13,13.56143);
   f21005->SetSavedPoint(14,13.44738);
   f21005->SetSavedPoint(15,13.33333);
   f21005->SetSavedPoint(16,13.21927);
   f21005->SetSavedPoint(17,13.10522);
   f21005->SetSavedPoint(18,12.99117);
   f21005->SetSavedPoint(19,12.87712);
   f21005->SetSavedPoint(20,12.76306);
   f21005->SetSavedPoint(21,12.64901);
   f21005->SetSavedPoint(22,12.53496);
   f21005->SetSavedPoint(23,12.42091);
   f21005->SetSavedPoint(24,12.30685);
   f21005->SetSavedPoint(25,12.1928);
   f21005->SetSavedPoint(26,12.07875);
   f21005->SetSavedPoint(27,11.9647);
   f21005->SetSavedPoint(28,11.85064);
   f21005->SetSavedPoint(29,11.73659);
   f21005->SetSavedPoint(30,11.62254);
   f21005->SetSavedPoint(31,11.50849);
   f21005->SetSavedPoint(32,11.39443);
   f21005->SetSavedPoint(33,11.28038);
   f21005->SetSavedPoint(34,11.16633);
   f21005->SetSavedPoint(35,11.05228);
   f21005->SetSavedPoint(36,10.93822);
   f21005->SetSavedPoint(37,10.82417);
   f21005->SetSavedPoint(38,10.71012);
   f21005->SetSavedPoint(39,10.59607);
   f21005->SetSavedPoint(40,10.48201);
   f21005->SetSavedPoint(41,10.36796);
   f21005->SetSavedPoint(42,10.25391);
   f21005->SetSavedPoint(43,10.13986);
   f21005->SetSavedPoint(44,10.0258);
   f21005->SetSavedPoint(45,9.91175);
   f21005->SetSavedPoint(46,9.797697);
   f21005->SetSavedPoint(47,9.683645);
   f21005->SetSavedPoint(48,9.569592);
   f21005->SetSavedPoint(49,9.45554);
   f21005->SetSavedPoint(50,9.341487);
   f21005->SetSavedPoint(51,9.227434);
   f21005->SetSavedPoint(52,9.113382);
   f21005->SetSavedPoint(53,8.999329);
   f21005->SetSavedPoint(54,8.885277);
   f21005->SetSavedPoint(55,8.771224);
   f21005->SetSavedPoint(56,8.657171);
   f21005->SetSavedPoint(57,8.543119);
   f21005->SetSavedPoint(58,8.429066);
   f21005->SetSavedPoint(59,8.315014);
   f21005->SetSavedPoint(60,8.200961);
   f21005->SetSavedPoint(61,8.086908);
   f21005->SetSavedPoint(62,7.972856);
   f21005->SetSavedPoint(63,7.858803);
   f21005->SetSavedPoint(64,7.744751);
   f21005->SetSavedPoint(65,7.630698);
   f21005->SetSavedPoint(66,7.516646);
   f21005->SetSavedPoint(67,7.402593);
   f21005->SetSavedPoint(68,7.28854);
   f21005->SetSavedPoint(69,7.174488);
   f21005->SetSavedPoint(70,7.060435);
   f21005->SetSavedPoint(71,6.946383);
   f21005->SetSavedPoint(72,6.83233);
   f21005->SetSavedPoint(73,6.718277);
   f21005->SetSavedPoint(74,6.604225);
   f21005->SetSavedPoint(75,6.490172);
   f21005->SetSavedPoint(76,6.37612);
   f21005->SetSavedPoint(77,6.262067);
   f21005->SetSavedPoint(78,6.148014);
   f21005->SetSavedPoint(79,6.033962);
   f21005->SetSavedPoint(80,5.919909);
   f21005->SetSavedPoint(81,5.805857);
   f21005->SetSavedPoint(82,5.691804);
   f21005->SetSavedPoint(83,5.577752);
   f21005->SetSavedPoint(84,5.463699);
   f21005->SetSavedPoint(85,5.349646);
   f21005->SetSavedPoint(86,5.235594);
   f21005->SetSavedPoint(87,5.121541);
   f21005->SetSavedPoint(88,5.007489);
   f21005->SetSavedPoint(89,4.893436);
   f21005->SetSavedPoint(90,4.779383);
   f21005->SetSavedPoint(91,4.665331);
   f21005->SetSavedPoint(92,4.551278);
   f21005->SetSavedPoint(93,4.437226);
   f21005->SetSavedPoint(94,4.323173);
   f21005->SetSavedPoint(95,4.20912);
   f21005->SetSavedPoint(96,4.095068);
   f21005->SetSavedPoint(97,3.981015);
   f21005->SetSavedPoint(98,3.866963);
   f21005->SetSavedPoint(99,3.75291);
   f21005->SetSavedPoint(100,3.638858);
   f21005->SetSavedPoint(101,0);
   f21005->SetSavedPoint(102,11.51);
   f21005->SetFillColor(19);
   f21005->SetFillStyle(0);
   f21005->SetLineColor(2);
   f21005->SetLineWidth(2);
   f21005->SetLineStyle(2);
   f21005->SetChisquare(49.38379);
   f21005->SetNDF(19);
   f21005->GetXaxis()->SetLabelFont(42);
   f21005->GetXaxis()->SetTitleOffset(1);
   f21005->GetXaxis()->SetTitleFont(42);
   f21005->GetYaxis()->SetLabelFont(42);
   f21005->GetYaxis()->SetTitleFont(42);
   f21005->SetParameter(0,-0.9909);
   f21005->SetParError(0,0.008021535);
   f21005->SetParLimits(0,0,0);
   f21005->SetParameter(1,15.04412);
   f21005->SetParError(1,0.04096872);
   f21005->SetParLimits(1,0,0);
   f21005->SetParent(gre);
   gre->GetListOfFunctions()->Add(f21005);
   
   ptstats = new TPaveStats(0.4939936,0.6789977,0.9790077,0.9363993,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 49.38 / 19");
   ptstats_LaTex = ptstats->AddText("b        = -0.9909 #pm 0.008022 ");
   ptstats_LaTex = ptstats->AddText("a        = 15.04 #pm 0.04097 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   
   leg = new TLegend(0.15,0.15,0.5,0.3,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextFont(12);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","Coniugati","h");
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
   entry->SetLineWidth(2);
   entry->SetMarkerColor(3);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("f2","ax+b","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   pt = new TPaveText(0.3435948,0.9346438,0.6564052,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("Operatore B");
   pt->Draw();
   c1_2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_3
   TPad *c1_3 = new TPad("c1_3", "c1_3",0.6666767,1e-05,0.99999,0.99999);
   c1_3->Draw();
   c1_3->cd();
   c1_3->Range(4.230509,5.646269,9.237926,10.8642);
   c1_3->SetFillColor(0);
   c1_3->SetBorderMode(0);
   c1_3->SetBorderSize(2);
   c1_3->SetGridx();
   c1_3->SetGridy();
   c1_3->SetRightMargin(0.005976364);
   c1_3->SetBottomMargin(0.07691462);
   c1_3->SetFrameBorderMode(0);
   c1_3->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1007[21] = {
   9.09229,
   8.69691,
   8.327109,
   8.00107,
   7.69329,
   7.40832,
   7.14371,
   6.89734,
   6.66741,
   6.45231,
   6.25065,
   6.06122,
   5.88293,
   5.71483,
   5.55607,
   5.40589,
   5.26362,
   5.12864,
   5.00042,
   4.87845,
   4.76228};
   Double_t Graph0_fy1007[21] = {
   6.10936,
   6.3823,
   6.60005,
   7.10816,
   7.48036,
   7.83188,
   8.15107,
   8.28615,
   8.49738,
   8.64429,
   8.95389,
   9.03478,
   9.28649,
   9.46223,
   9.64475,
   9.64475,
   9.83445,
   9.93213,
   10.1334,
   10.2372,
   10.2372};
   Double_t Graph0_fex1007[21] = {
   0.0586184,
   0.0536313,
   0.0492545,
   0.0453925,
   0.0419675,
   0.038916,
   0.0361856,
   0.0337328,
   0.0315211,
   0.0295201,
   0.0277037,
   0.02605,
   0.02454,
   0.0231577,
   0.0218889,
   0.0207216,
   0.0196452,
   0.0186506,
   0.0177297,
   0.0168753,
   0.0160812};
   Double_t Graph0_fey1007[21] = {
   0.0264654,
   0.028883,
   0.0308186,
   0.0358264,
   0.0396765,
   0.043493,
   0.0471104,
   0.0486848,
   0.0511986,
   0.0529842,
   0.0568475,
   0.0578793,
   0.0611492,
   0.0634856,
   0.0659584,
   0.0659584,
   0.0685786,
   0.0699476,
   0.0728116,
   0.07431,
   0.07431};
   gre = new TGraphErrors(21,Graph0_fx1007,Graph0_fy1007,Graph0_fex1007,Graph0_fey1007);
   gre->SetName("Graph0");
   gre->SetTitle("Operatore C");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph01007 = new TH1F("Graph_Graph01007","Operatore C",100,0,11.51);
   Graph_Graph01007->SetMinimum(6.047604);
   Graph_Graph01007->SetMaximum(10.34708);
   Graph_Graph01007->SetDirectory(0);
   Graph_Graph01007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph01007->SetLineColor(ci);
   Graph_Graph01007->GetXaxis()->SetTitle("1/p [1/m]");
   Graph_Graph01007->GetXaxis()->SetRange(42,80);
   Graph_Graph01007->GetXaxis()->SetAxisColor(14);
   Graph_Graph01007->GetXaxis()->SetLabelFont(22);
   Graph_Graph01007->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01007->GetXaxis()->SetTitleFont(22);
   Graph_Graph01007->GetYaxis()->SetTitle("1/q [1/m]");
   Graph_Graph01007->GetYaxis()->SetAxisColor(14);
   Graph_Graph01007->GetYaxis()->SetLabelFont(22);
   Graph_Graph01007->GetYaxis()->SetTitleFont(22);
   Graph_Graph01007->GetZaxis()->SetLabelFont(42);
   Graph_Graph01007->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01007);
   
   
   TF1 *f31008 = new TF1("*f3",0,11.51,2);
    //The original function : f3 had originally been created by:
    //TF1 *f3 = new TF1("f3",f3,0,11.51,2, 1, TF1::EAddToList::kNo);
   f31008->SetRange(0,11.51);
   f31008->SetName("f3");
   f31008->SetTitle("f3");
   f31008->SetSavedPoint(0,15.12386);
   f31008->SetSavedPoint(1,15.00896);
   f31008->SetSavedPoint(2,14.89407);
   f31008->SetSavedPoint(3,14.77917);
   f31008->SetSavedPoint(4,14.66427);
   f31008->SetSavedPoint(5,14.54938);
   f31008->SetSavedPoint(6,14.43448);
   f31008->SetSavedPoint(7,14.31959);
   f31008->SetSavedPoint(8,14.20469);
   f31008->SetSavedPoint(9,14.08979);
   f31008->SetSavedPoint(10,13.9749);
   f31008->SetSavedPoint(11,13.86);
   f31008->SetSavedPoint(12,13.74511);
   f31008->SetSavedPoint(13,13.63021);
   f31008->SetSavedPoint(14,13.51532);
   f31008->SetSavedPoint(15,13.40042);
   f31008->SetSavedPoint(16,13.28552);
   f31008->SetSavedPoint(17,13.17063);
   f31008->SetSavedPoint(18,13.05573);
   f31008->SetSavedPoint(19,12.94084);
   f31008->SetSavedPoint(20,12.82594);
   f31008->SetSavedPoint(21,12.71104);
   f31008->SetSavedPoint(22,12.59615);
   f31008->SetSavedPoint(23,12.48125);
   f31008->SetSavedPoint(24,12.36636);
   f31008->SetSavedPoint(25,12.25146);
   f31008->SetSavedPoint(26,12.13657);
   f31008->SetSavedPoint(27,12.02167);
   f31008->SetSavedPoint(28,11.90677);
   f31008->SetSavedPoint(29,11.79188);
   f31008->SetSavedPoint(30,11.67698);
   f31008->SetSavedPoint(31,11.56209);
   f31008->SetSavedPoint(32,11.44719);
   f31008->SetSavedPoint(33,11.33229);
   f31008->SetSavedPoint(34,11.2174);
   f31008->SetSavedPoint(35,11.1025);
   f31008->SetSavedPoint(36,10.98761);
   f31008->SetSavedPoint(37,10.87271);
   f31008->SetSavedPoint(38,10.75782);
   f31008->SetSavedPoint(39,10.64292);
   f31008->SetSavedPoint(40,10.52802);
   f31008->SetSavedPoint(41,10.41313);
   f31008->SetSavedPoint(42,10.29823);
   f31008->SetSavedPoint(43,10.18334);
   f31008->SetSavedPoint(44,10.06844);
   f31008->SetSavedPoint(45,9.953544);
   f31008->SetSavedPoint(46,9.838648);
   f31008->SetSavedPoint(47,9.723752);
   f31008->SetSavedPoint(48,9.608856);
   f31008->SetSavedPoint(49,9.493961);
   f31008->SetSavedPoint(50,9.379065);
   f31008->SetSavedPoint(51,9.264169);
   f31008->SetSavedPoint(52,9.149273);
   f31008->SetSavedPoint(53,9.034377);
   f31008->SetSavedPoint(54,8.919481);
   f31008->SetSavedPoint(55,8.804585);
   f31008->SetSavedPoint(56,8.68969);
   f31008->SetSavedPoint(57,8.574794);
   f31008->SetSavedPoint(58,8.459898);
   f31008->SetSavedPoint(59,8.345002);
   f31008->SetSavedPoint(60,8.230106);
   f31008->SetSavedPoint(61,8.11521);
   f31008->SetSavedPoint(62,8.000314);
   f31008->SetSavedPoint(63,7.885418);
   f31008->SetSavedPoint(64,7.770523);
   f31008->SetSavedPoint(65,7.655627);
   f31008->SetSavedPoint(66,7.540731);
   f31008->SetSavedPoint(67,7.425835);
   f31008->SetSavedPoint(68,7.310939);
   f31008->SetSavedPoint(69,7.196043);
   f31008->SetSavedPoint(70,7.081147);
   f31008->SetSavedPoint(71,6.966252);
   f31008->SetSavedPoint(72,6.851356);
   f31008->SetSavedPoint(73,6.73646);
   f31008->SetSavedPoint(74,6.621564);
   f31008->SetSavedPoint(75,6.506668);
   f31008->SetSavedPoint(76,6.391772);
   f31008->SetSavedPoint(77,6.276876);
   f31008->SetSavedPoint(78,6.161981);
   f31008->SetSavedPoint(79,6.047085);
   f31008->SetSavedPoint(80,5.932189);
   f31008->SetSavedPoint(81,5.817293);
   f31008->SetSavedPoint(82,5.702397);
   f31008->SetSavedPoint(83,5.587501);
   f31008->SetSavedPoint(84,5.472605);
   f31008->SetSavedPoint(85,5.35771);
   f31008->SetSavedPoint(86,5.242814);
   f31008->SetSavedPoint(87,5.127918);
   f31008->SetSavedPoint(88,5.013022);
   f31008->SetSavedPoint(89,4.898126);
   f31008->SetSavedPoint(90,4.78323);
   f31008->SetSavedPoint(91,4.668334);
   f31008->SetSavedPoint(92,4.553439);
   f31008->SetSavedPoint(93,4.438543);
   f31008->SetSavedPoint(94,4.323647);
   f31008->SetSavedPoint(95,4.208751);
   f31008->SetSavedPoint(96,4.093855);
   f31008->SetSavedPoint(97,3.978959);
   f31008->SetSavedPoint(98,3.864063);
   f31008->SetSavedPoint(99,3.749168);
   f31008->SetSavedPoint(100,3.634272);
   f31008->SetSavedPoint(101,0);
   f31008->SetSavedPoint(102,11.51);
   f31008->SetFillColor(19);
   f31008->SetFillStyle(0);
   f31008->SetLineColor(2);
   f31008->SetLineWidth(1);
   f31008->SetLineStyle(2);
   f31008->SetChisquare(36.32035);
   f31008->SetNDF(19);
   f31008->GetXaxis()->SetLabelFont(42);
   f31008->GetXaxis()->SetTitleOffset(1);
   f31008->GetXaxis()->SetTitleFont(42);
   f31008->GetYaxis()->SetLabelFont(42);
   f31008->GetYaxis()->SetTitleFont(42);
   f31008->SetParameter(0,-0.9982264);
   f31008->SetParError(0,0.01100172);
   f31008->SetParLimits(0,0,0);
   f31008->SetParameter(1,15.12386);
   f31008->SetParError(1,0.0748391);
   f31008->SetParLimits(1,0,0);
   f31008->SetParent(gre);
   gre->GetListOfFunctions()->Add(f31008);
   
   ptstats = new TPaveStats(0.4909905,0.6834356,0.9790077,0.9363993,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(22);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 36.32 / 19");
   ptstats_LaTex = ptstats->AddText("b        = -0.9982 #pm 0.011 ");
   ptstats_LaTex = ptstats->AddText("a        = 15.12 #pm 0.07484 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   
   leg = new TLegend(0.15,0.15,0.5,0.3,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","Coniugati","h");
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
   entry->SetLineWidth(2);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("f3","ax+b","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   pt = new TPaveText(0.342844,0.9346438,0.657156,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("Operatore C");
   pt->Draw();
   c1_3->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
