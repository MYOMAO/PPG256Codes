void Compare_PYTHIA_ALICE_PHENIX_LHCb()
{

	bool IncludeLHCb = true;
	TLatex *lat = new TLatex();
	lat->SetNDC();
	lat->SetTextSize(0.05);

	const int nset = 2;
	string setname[nset] = {"Monash", "Detroit"};

	TFile *infile = new TFile("outfile_PYTHIA_1S2Sratio.root", "read");
	TFile *infile1 = new TFile("result_output.root", "read");

	TGraphErrors *g1d_svx_scaled[nset];
	TGraphErrors *g1d_fvtxn_scaled[nset];
	TGraphErrors *g1d_svx_scaled_re[nset];
	TGraphErrors *g1d_fvtxn_scaled_re[nset];
	TGraphErrors *g1d_fvtxs_scaled[nset];
	TGraphErrors *g1d_same_result[2];
	TGraphErrors *g1d_svx_result[2];
	TGraphErrors *g1d_oppo_result[2];
	TGraphErrors *g1d_alice_result[2];

	const int NLHCb = 5;
	float XValue[NLHCb] = {0.5157609299226299, 1.1052826416910375, 1.8152463628623257, 2.548115722059749, 3.7567004775478474};
	float YValue[NLHCb] = {1.2930496427645948, 1.1147771443379115, 1.0096527597823273, 0.9203068892755342,  0.8364750305408509};
	float YValueH[NLHCb] = {1.3389886351016178, 1.154968903861104, 1.0512854921704367, 0.9447090289860438,  0.8537000703365049};
	float YValueStat[NLHCb] = {0.05,0.05,0.05,0.05,0.8436521304557068 - 0.8364750305408509};
	float XValueErr[NLHCb] = {0.01,0.01,0.01,0.01,0.01};
	float XValueErrSyst[NLHCb] = {0.05,0.05,0.05,0.05,0.05};
	float YValueSyst[NLHCb];

	for(int i = 0; i < NLHCb; i++){


		YValueSyst[i] = YValueH[i] - YValue[i];
		
	}

	TGraphErrors * LHCbJpsiPrompt = new TGraphErrors(NLHCb,XValue,YValue,XValueErr,YValueStat);
	LHCbJpsiPrompt->SetMarkerStyle(24);
	LHCbJpsiPrompt->SetMarkerSize(1);
	LHCbJpsiPrompt->SetMarkerColor(kOrange);
	LHCbJpsiPrompt->SetLineColor(kOrange);

	TGraphErrors * LHCbJpsiPromptSyst = new TGraphErrors(NLHCb,XValue,YValue,XValueErrSyst,YValueSyst);
	LHCbJpsiPromptSyst->SetMarkerColor(kOrange);
	LHCbJpsiPromptSyst->SetLineColor(kOrange);


	float XValueNP[NLHCb] = {0.5157609299226299, 1.1052826416910375, 1.8152463628623257, 2.548115722059749, 3.7567004775478474};
	float YValueNP[NLHCb] = {1.0727179064496188, 1.0163939831032351, 1.0054440552235733, 0.9717123428806926,  0.9771234288069238};
	float YValueHNP[NLHCb] = {1.0911930764475584, 1.0263548320626419, 1.0125530599629098, 0.9802513908922319,  0.9870842777663303};
	float YValueStatHNP[NLHCb] = {1.125324541520709, 1.0590562538635897 , 1.0509499278796621, 1.000156604162374, 0.9998887286214715};
	float XValueErrNP[NLHCb] = {0.01,0.01,0.01,0.01,0.01};
	float YValueStatNP[NLHCb];
	float YValueSystNP[NLHCb];
	float XValueErrNPSyst[NLHCb] = {0.05,0.05,0.05,0.05,0.05};

	for(int i = 0; i < NLHCb; i++){


		YValueSystNP[i] = YValueHNP[i] - YValueNP[i];
		YValueStatNP[i] = YValueStatHNP[i] - YValueNP[i];
		
	}


	TGraphErrors * LHCbJpsiNP = new TGraphErrors(NLHCb,XValueNP,YValueNP,XValueErrNP,YValueStatNP);
	LHCbJpsiNP->SetMarkerStyle(25);
	LHCbJpsiNP->SetMarkerSize(1);
	LHCbJpsiNP->SetMarkerColor(kBlack);
	LHCbJpsiNP->SetLineColor(kBlack);


	TGraphErrors * LHCbJpsiNPSyst = new TGraphErrors(NLHCb,XValueNP,YValueNP,XValueErrNPSyst,YValueSystNP);
	LHCbJpsiNPSyst->SetMarkerColor(kBlack);
	LHCbJpsiNPSyst->SetLineColor(kBlack);



	for (int iset = 0; iset < nset; iset++)
	{
		g1d_svx_scaled[iset] = (TGraphErrors *)infile->Get(Form("g1d_svx_scaled_set%d", iset));
		g1d_svx_scaled_re[iset] = (TGraphErrors *)infile->Get(Form("g1d_svx_scaled_set%d_rescattering", iset));

		g1d_fvtxn_scaled[iset] = (TGraphErrors *)infile->Get(Form("g1d_fvtxn_scaled_set%d", iset));
		g1d_fvtxn_scaled_re[iset] = (TGraphErrors *)infile->Get(Form("g1d_fvtxn_scaled_set%d_rescattering", iset));

		g1d_fvtxs_scaled[iset] = (TGraphErrors *)infile->Get(Form("g1d_fvtxs_scaled_set%d", iset));
	}

	g1d_same_result[0] = (TGraphErrors *)infile1->Get("same_data");
	g1d_same_result[1] = (TGraphErrors *)infile1->Get("same_err_data");
	g1d_same_result[0]->SetMarkerStyle(20);
	g1d_same_result[1]->SetMarkerStyle(20);

	g1d_svx_result[0] = (TGraphErrors *)infile1->Get("svx_data");
	g1d_svx_result[1] = (TGraphErrors *)infile1->Get("svx_err_data");
	g1d_svx_result[0]->SetMarkerStyle(20);
	g1d_svx_result[1]->SetMarkerStyle(20);
	g1d_svx_result[0]->SetMarkerSize(1);
	g1d_svx_result[1]->SetMarkerSize(1);

	g1d_oppo_result[0] = (TGraphErrors *)infile1->Get("oppo_data");
	g1d_oppo_result[1] = (TGraphErrors *)infile1->Get("oppo_sys_data");
	g1d_oppo_result[0]->SetMarkerStyle(20);
	g1d_oppo_result[1]->SetMarkerStyle(20);


	g1d_alice_result[0] = (TGraphErrors *)infile1->Get("alice_data");
	g1d_alice_result[1] = (TGraphErrors *)infile1->Get("alice_sys");
	g1d_alice_result[0]->SetMarkerColor(kGreen+2);
	g1d_alice_result[0]->SetLineColor(kGreen+2);
	g1d_alice_result[1]->SetLineColorAlpha(kGreen+2,0.5);


	const int NALICEPoints = 9;

	float XALICE[NALICEPoints];
	float YALICE[NALICEPoints];
	float XErrALICE[NALICEPoints];
	float YErrALICE[NALICEPoints];

	for(int i = 0; i < NALICEPoints; i++){

		XALICE[i] = g1d_alice_result[1]->GetPointX(i);
		YALICE[i] = g1d_alice_result[1]->GetPointY(i);
		XErrALICE[i] = g1d_alice_result[1]->GetErrorX(i);
		YErrALICE[i] = g1d_alice_result[1]->GetErrorY(i);

	}

	TGraphErrors * ALICESyst = new TGraphErrors(NALICEPoints,XALICE,YALICE,XErrALICE,YErrALICE);
	ALICESyst->SetLineColor(kGreen + 2);
	ALICESyst->SetFillColorAlpha(kGreen + 2,0.5);

	g1d_alice_result[0]->SetMarkerStyle(28);



	const int NPHENIXPoints = 8;

	float XPHENIX[NPHENIXPoints];
	float YPHENIX[NPHENIXPoints];
	float XErrPHENIX[NPHENIXPoints];
	float YErrPHENIX[NPHENIXPoints];

	for(int i = 0; i < NPHENIXPoints; i++){

		XPHENIX[i] = g1d_same_result[1]->GetPointX(i);
		YPHENIX[i] = g1d_same_result[1]->GetPointY(i);
		XErrPHENIX[i] = g1d_same_result[1]->GetErrorX(i);
		YErrPHENIX[i] = g1d_same_result[1]->GetErrorY(i);

	}

	TGraphErrors * PHENIXSameSyst = new TGraphErrors(NPHENIXPoints,XPHENIX,YPHENIX,XErrPHENIX,YErrPHENIX);
	PHENIXSameSyst->SetLineColor(kRed-9);
	PHENIXSameSyst->SetFillColorAlpha(kRed-9,0.5);


	const int NPHENIXPoints2 = 8;

	float XPHENIX2[NPHENIXPoints2];
	float YPHENIX2[NPHENIXPoints2];
	float XErrPHENIX2[NPHENIXPoints2];
	float YErrPHENIX2[NPHENIXPoints2];

	for(int i = 0; i < NALICEPoints; i++){

		XPHENIX2[i] = g1d_oppo_result[1]->GetPointX(i);
		YPHENIX2[i] = g1d_oppo_result[1]->GetPointY(i);
		XErrPHENIX2[i] = g1d_oppo_result[1]->GetErrorX(i);
		YErrPHENIX2[i] = g1d_oppo_result[1]->GetErrorY(i);

	}

	TGraphErrors * PHENIXOppSyst = new TGraphErrors(NPHENIXPoints2,XPHENIX2,YPHENIX2,XErrPHENIX2,YErrPHENIX2);
	PHENIXOppSyst->SetLineColor(kBlue-9);
	PHENIXOppSyst->SetFillColorAlpha(kBlue-9,0.5);








	TCanvas *c3 = new TCanvas("c3", "c3", 1.2 * 500 * 3, 500);
	gPad->SetMargin(0,0,0,0);
	TCanvas *c2 = new TCanvas("c2", "c2", 1.2 * 3 * 500, 500);
	gPad->SetMargin(0,0,0,0);
	c2->Divide(3, 1);
	c3->Divide(3, 1);

	TCanvas *cZZ = new TCanvas("cZZ", "cZZ",600 * 3, 600);

	cZZ->cd();

	TPad *pad[3];

	pad[0] = new TPad("pad1","left pad",0.0,0.0,0.36,1.0);
	pad[0]->SetTopMargin(0.04);
	pad[0]->SetBottomMargin(0.14);
	pad[0]->SetRightMargin(0.0);
	pad[0]->SetLeftMargin(0.17);
	pad[0]->Draw();

	pad[1] = new TPad("pad2","middle pad",0.36,0.0,0.670,1.0);
	pad[1]->SetTopMargin(0.04);
	pad[1]->SetBottomMargin(0.14);
	pad[1]->SetRightMargin(0.00);
	pad[1]->SetLeftMargin(0.0);
	pad[1]->Draw();


	pad[2] = new TPad("pad3","right pad",0.670,0.0,0.99,1.0);
	pad[2]->SetTopMargin(0.04);
	pad[2]->SetBottomMargin(0.14);
	pad[2]->SetRightMargin(0.02);
	pad[2]->SetLeftMargin(0.0);
	pad[2]->Draw();
	cZZ->cd();


	for (int iset = 0; iset < 3; iset++)
	{
		if (iset == 0)
		{

			// oppo ALICE to PHENIX
			//	c2->cd(3);
			cZZ->cd();

			pad[2]->cd();
			//gPad->SetMargin(0.14, 0.01, 0.13, 0.03);
			//gPad->SetTicks();

			TH1D *htmp = (TH1D *)gPad->DrawFrame(0.001, 0, 6.5, 2.5);
			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
			htmp->GetXaxis()->SetLabelSize(0.05);
			htmp->GetXaxis()->SetTitleSize(0.06);
			htmp->GetXaxis()->SetNdivisions(9,4,0);
			htmp->GetXaxis()->SetTitleOffset(1.0);
			htmp->GetYaxis()->SetTitle("");
			htmp->GetYaxis()->SetLabelSize(0.00);
			htmp->GetYaxis()->SetTitleSize(0.00);
			htmp->GetYaxis()->SetTitleOffset(1111.05);


			htmp->GetYaxis()->SetNdivisions(9,5,0);
			htmp->GetXaxis()->CenterTitle();
			htmp->GetYaxis()->CenterTitle();

			TLine *line = new TLine(0.0,1,6.5,1);
			line->SetLineStyle(7);
			line->Draw();


			g1d_oppo_result[0]->SetMarkerSize(1);

			g1d_oppo_result[0]->Draw("p");
			g1d_oppo_result[1]->Draw("5SAME");

			
			g1d_alice_result[0]->Draw("p");
			g1d_alice_result[1]->Draw("5SAME");

			TLegend *leg = new TLegend(0.00, 0.95-0.06*4, 0.45, 0.95);

			leg->SetFillStyle(0);
			leg->SetTextSize(0.05);
			leg->SetBorderSize(0);
			leg->AddEntry(g1d_oppo_result[0], "PHENIX", "p");
			leg->AddEntry("", "p+p #sqrt{s} = 200 GeV", "");
			leg->AddEntry("", "N_{#psi}: 1.2 < |y| < 2.2", "");
			leg->AddEntry("", "N_{ch}: #LT|#Delta#eta|#GT = 3.4", "");
			leg->Draw();
			//leg1->Draw();
			cZZ->Update();

		}
		else if (iset == 1)
		{
			// same ALICE to PHENIX

			//	c2->cd(1);

			pad[0]->cd();

			//gPad->SetMargin(0.14, 0.01, 0.13, 0.03);
			//gPad->SetTicks();

			TH1D *htmp = (TH1D *)gPad->DrawFrame(0, 0, 6.5, 2.5);
			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
			htmp->GetXaxis()->SetLabelSize(0.05);
			htmp->GetXaxis()->SetTitleSize(0.06);
			htmp->GetXaxis()->SetNdivisions(9,4,0);
			htmp->GetXaxis()->SetTitleOffset(1.0);
			htmp->GetYaxis()->SetTitle("(N_{#psi(2S)}/N_{J/#psi}) #scale[1.5]{/} #LTN_{#psi(2S)}/N_{J/#psi}#GT");
			htmp->GetYaxis()->SetLabelSize(0.05);
			htmp->GetYaxis()->SetTitleSize(0.06);
			htmp->GetYaxis()->SetTitleOffset(1.2);
			htmp->GetYaxis()->SetNdivisions(9,5,0);
			htmp->GetXaxis()->CenterTitle();
			htmp->GetYaxis()->CenterTitle();

			TLine *line = new TLine(0.0,1,6.5,1);
			line->SetLineStyle(7);
			line->Draw();

			g1d_alice_result[0]->Draw("p");
			g1d_alice_result[1]->Draw("e2");

			g1d_same_result[0]->Draw("p");
			g1d_same_result[1]->Draw("e2");

			TLegend *leg1 = new TLegend(0.18, 0.95-0.06*4+0.01, 0.45, 0.95);
			leg1->SetFillStyle(0);
			leg1->SetTextSize(0.05);
			leg1->SetBorderSize(0);
			leg1->AddEntry(g1d_alice_result[0], "ALICE", "p");
			leg1->AddEntry("", "p+p #sqrt{s} = 13 TeV", "");
			leg1->AddEntry("", "N_{#psi}: 2.5 < y < 4.0", "");
			leg1->AddEntry("", "N_{ch}: |#eta| < 1", "");



			// same
			TLegend *leg = new TLegend(0.53, 0.95-0.06*4, 0.95, 0.95);
			leg->SetFillStyle(0);
			leg->SetTextSize(0.05);
			leg->SetBorderSize(0);
			leg->AddEntry(g1d_same_result[0], "PHENIX", "p");
			leg->AddEntry("", "p+p #sqrt{s} = 200 GeV", "");
			leg->AddEntry("", "N_{#psi}: 1.2 < |y| < 2.2", "");
			leg->AddEntry("", "N_{ch}: #LT|#Delta#eta|#GT = 0", "");
			leg->Draw();
			leg1->Draw();
			cZZ->Update();

		}
		else if (iset == 2)
		{
			// svx ALICE to PHENIX
			c2->cd(2);

			pad[1]->cd();

			//gPad->SetMargin(0.14, 0.01, 0.13, 0.03);
			//gPad->SetTicks();

			TH1D *htmp = (TH1D *)gPad->DrawFrame(0.001, 0, 6.5, 2.5); // alice
			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
			htmp->GetXaxis()->SetLabelSize(0.05);
			htmp->GetXaxis()->SetTitleSize(0.06);
			htmp->GetXaxis()->SetNdivisions(9,4,0);
			htmp->GetXaxis()->SetTitleOffset(1.0);
			htmp->GetYaxis()->SetTitle("");
			htmp->GetYaxis()->SetLabelSize(0.05);
			htmp->GetYaxis()->SetLabelSize(0.00);			
			htmp->GetYaxis()->SetTitleSize(0.06);
			htmp->GetYaxis()->SetTitleOffset(1.05);
			htmp->GetYaxis()->SetTitleOffset(1111.05);
			htmp->GetYaxis()->SetNdivisions(9,5,0);
			htmp->GetXaxis()->CenterTitle();
			htmp->GetYaxis()->CenterTitle();

			TLine *line = new TLine(0.0,1,6.5,1);
			line->SetLineStyle(7);
			line->Draw();

			g1d_alice_result[0]->Draw("p");
			g1d_alice_result[1]->Draw("5SAME");

			g1d_svx_result[0]->Draw("p");
			g1d_svx_result[1]->Draw("e2");

			// svx
			TLegend *leg = new TLegend(0.00, 0.95-0.06*4, 0.45, 0.95);

			leg->SetFillStyle(0);
			leg->SetTextSize(0.05);
			leg->SetBorderSize(0);
			leg->AddEntry(g1d_svx_result[0], "PHENIX", "p");
			leg->AddEntry("", "p+p #sqrt{s} = 200 GeV", "");
			leg->AddEntry("", "N_{#psi}: 1.2 < |y| < 2.2", "");
			leg->AddEntry("", "N_{ch}: #LT|#Delta#eta|#GT = 1.7", "");
			leg->Draw();
			//leg1->Draw();
			cZZ->Update();
		}
	} // iset
	cZZ->SaveAs("DataNew.png");
	cZZ->SaveAs("DataNew.pdf");

	c2->SaveAs("Data.png");

	TCanvas *cZZ2 = new TCanvas("cZZ", "cZZ",600 * 3, 600);

	cZZ2->cd();

	TPad *pad2[3];
	pad2[0] = new TPad("pad12","left pad",0.0,0.0,0.36,1.0);
	pad2[0]->SetTopMargin(0.04);
	pad2[0]->SetBottomMargin(0.14);
	pad2[0]->SetRightMargin(0.0);
	pad2[0]->SetLeftMargin(0.17);
	pad2[0]->Draw();

	pad2[1] = new TPad("pad22","middle pad",0.36,0.0,0.670,1.0);
	pad2[1]->SetTopMargin(0.04);
	pad2[1]->SetBottomMargin(0.14);
	pad2[1]->SetRightMargin(0.00);
	pad2[1]->SetLeftMargin(0.0);
	pad2[1]->Draw();


	pad2[2] = new TPad("pad32","right pad",0.670,0.0,0.99,1.0);
	pad2[2]->SetTopMargin(0.04);
	pad2[2]->SetBottomMargin(0.14);
	pad2[2]->SetRightMargin(0.02);
	pad2[2]->SetLeftMargin(0.0);
	pad2[2]->Draw();
	cZZ2->cd();




	for (int pset = 0; pset < 3; pset++)
	{
		if (pset == 0)
		{
			// oppo PYTHIA to PHENIX
			//c3->cd(3);
			pad2[2]->cd();
			
			//gPad->SetMargin(0.14, 0.01, 0.13, 0.03);
			//gPad->SetTicks();


			TH1D *htmp = (TH1D *)gPad->DrawFrame(0.001, 0, 6.5, 2.5);
			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
			htmp->GetXaxis()->SetLabelSize(0.05);
			htmp->GetXaxis()->SetTitleSize(0.06);
			htmp->GetXaxis()->SetNdivisions(9,4,0);
			htmp->GetXaxis()->SetTitleOffset(1.0);
			htmp->GetYaxis()->SetTitle("");
			htmp->GetYaxis()->SetLabelSize(0.00);
			htmp->GetYaxis()->SetTitleSize(0.00);
			htmp->GetYaxis()->SetTitleOffset(1111.05);


			htmp->GetYaxis()->SetNdivisions(9,5,0);
			htmp->GetXaxis()->CenterTitle();
			htmp->GetYaxis()->CenterTitle();

			TLine *line = new TLine(0.0,1,6.5,1);
			line->SetLineStyle(7);
			line->Draw();

			g1d_fvtxs_scaled[0]->SetLineColorAlpha(kMagenta + 1, 0.3);
			g1d_fvtxs_scaled[0]->SetLineWidth(4);
			g1d_fvtxs_scaled[0]->SetFillColorAlpha(kMagenta + 1, 0.3);
			g1d_fvtxs_scaled[0]->Draw("L3");

			g1d_fvtxs_scaled[1]->SetLineColorAlpha(kGreen + 2, 0.3);
			g1d_fvtxs_scaled[1]->SetLineWidth(4);
			g1d_fvtxs_scaled[1]->SetFillColorAlpha(kGreen + 2, 0.3);
			g1d_fvtxs_scaled[1]->Draw("L3");

			g1d_oppo_result[0]->Draw("p");
			g1d_oppo_result[1]->Draw("5SAME");

			// oppo
			TLegend *leg1 = new TLegend(0.08, 0.95-0.06*3, 0.4, 0.95);
			leg1->SetFillStyle(0);
			leg1->SetTextSize(0.05);
			leg1->SetBorderSize(0);
			leg1->AddEntry("", "p+p #sqrt{s} = 200 GeV", "h");
			leg1->AddEntry("", "N_{#psi}: 1.2 < |y| < 2.2", "h");
			leg1->AddEntry("", "N_{ch}: #LT|#Delta#eta|#GT = 3.4", "h");
			leg1->Draw();

			TLegend *leg = new TLegend(0.48, 0.95-0.06*3, 0.95, 0.95);
			leg->SetFillStyle(0);
			leg->SetTextSize(0.05);
			leg->SetBorderSize(0);
			leg->AddEntry(g1d_oppo_result[0], "PHENIX", "p");
			leg->AddEntry(g1d_fvtxs_scaled[0], "PYTHIA8 Monash", "lf");
			leg->AddEntry(g1d_fvtxs_scaled[1], "PYTHIA8 Detroit", "lf");
			leg->Draw();
			cZZ2->Update();
			
		}
		else if (pset == 1)
		{
			// same PYTHIA to PHENIX
			//c3->cd(1);
			//gPad->SetMargin(0.14, 0.01, 0.13, 0.03);
			//gPad->SetTicks();

			pad2[0]->cd();
			

			TH1D *htmp = (TH1D *)gPad->DrawFrame(0, 0, 6.5, 2.5);
			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
			htmp->GetXaxis()->SetLabelSize(0.05);
			htmp->GetXaxis()->SetTitleSize(0.06);
			htmp->GetXaxis()->SetNdivisions(9,4,0);
			htmp->GetXaxis()->SetTitleOffset(1.0);
			htmp->GetYaxis()->SetTitle("(N_{#psi(2S)}/N_{J/#psi}) #scale[1.5]{/} #LTN_{#psi(2S)}/N_{J/#psi}#GT");
			htmp->GetYaxis()->SetLabelSize(0.05);
			htmp->GetYaxis()->SetTitleSize(0.06);
			htmp->GetYaxis()->SetTitleOffset(1.2);
			htmp->GetYaxis()->SetNdivisions(9,5,0);
			htmp->GetXaxis()->CenterTitle();
			htmp->GetYaxis()->CenterTitle();

			TLine *line = new TLine(0.0,1,6.5,1);
			line->SetLineStyle(7);
			line->Draw();
/*
			g1d_fvtxn_scaled[0]->SetLineColorAlpha(kMagenta + 1, 0.3);
			g1d_fvtxn_scaled[0]->SetLineWidth(4);
			g1d_fvtxn_scaled[0]->SetFillColorAlpha(kMagenta + 1, 0.3);
			g1d_fvtxn_scaled[0]->Draw("L3");
*/
			g1d_fvtxn_scaled[1]->SetLineColorAlpha(kGreen + 2, 0.5);
			g1d_fvtxn_scaled[1]->SetLineWidth(4);
			g1d_fvtxn_scaled[1]->SetFillColorAlpha(kGreen + 2, 0.5);
			g1d_fvtxn_scaled[1]->Draw("L3");

			g1d_same_result[0]->Draw("p");
			g1d_same_result[1]->Draw("5SAME");

			// same
			TLegend *leg1 = new TLegend(0.22, 0.95-0.06*3, 0.4, 0.95);
			leg1->SetFillStyle(0);
			leg1->SetTextSize(0.05);
			leg1->SetBorderSize(0);
			leg1->AddEntry("", "p+p #sqrt{s} = 200 GeV", "h");
			leg1->AddEntry("", "N_{#psi}: 1.2 < |y| < 2.2", "h");
			leg1->AddEntry("", "N_{ch}: #LT|#Delta#eta|#GT = 0", "h");
			leg1->Draw();

			TLegend *leg = new TLegend(0.56, 0.95-0.06*3, 0.95, 0.95);
			leg->SetFillStyle(0);
			leg->SetTextSize(0.05);
			leg->SetBorderSize(0);
			leg->AddEntry(g1d_same_result[0], "PHENIX", "Lp");
			leg->AddEntry(g1d_fvtxs_scaled[0], "PYTHIA8 Monash", "lf");
			leg->AddEntry(g1d_fvtxs_scaled[1], "PYTHIA8 Detroit", "lf");
			leg->Draw();
	//		lat->DrawLatex(0.23,0.62,"With MPI");
			cZZ2->Update();
		

		}
		else if (pset == 2)
		{

			// svx PYTHIA to PHENIX
//			c3->cd(2);

			pad2[1]->cd();

			TH1D *htmp = (TH1D *)gPad->DrawFrame(0.001, 0, 6.5, 2.5); // alice
			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
			htmp->GetXaxis()->SetLabelSize(0.05);
			htmp->GetXaxis()->SetTitleSize(0.06);
			htmp->GetXaxis()->SetNdivisions(9,4,0);
			htmp->GetXaxis()->SetTitleOffset(1.0);
			htmp->GetYaxis()->SetTitle("");
			htmp->GetYaxis()->SetLabelSize(0.05);
			htmp->GetYaxis()->SetLabelSize(0.00);			
			htmp->GetYaxis()->SetTitleSize(0.06);
			htmp->GetYaxis()->SetTitleOffset(1.05);
			htmp->GetYaxis()->SetTitleOffset(1111.05);
			htmp->GetYaxis()->SetNdivisions(9,5,0);
			htmp->GetXaxis()->CenterTitle();
			htmp->GetYaxis()->CenterTitle();


			TLine *line = new TLine(0.0,1,6.5,1);
			line->SetLineStyle(7);
			line->Draw();

			g1d_svx_scaled[0]->SetLineColorAlpha(kMagenta + 1, 0.3);
			g1d_svx_scaled[0]->SetLineWidth(4);
			g1d_svx_scaled[0]->SetFillColorAlpha(kMagenta + 1, 0.3);
			g1d_svx_scaled[0]->Draw("L3");

			g1d_svx_scaled[1]->SetLineColorAlpha(kGreen + 2, 0.3);
			g1d_svx_scaled[1]->SetLineWidth(4);
			g1d_svx_scaled[1]->SetFillColorAlpha(kGreen + 2, 0.3);
			g1d_svx_scaled[1]->Draw("L3");

			g1d_svx_result[0]->Draw("p");
			g1d_svx_result[1]->Draw("e2");

			TLegend *leg1 = new TLegend(0.08, 0.95-0.06*3, 0.4, 0.95);
			leg1->SetFillStyle(0);
			leg1->SetTextSize(0.05);
			leg1->SetBorderSize(0);
			leg1->AddEntry("", "p+p #sqrt{s} = 200 GeV", "h");
			leg1->AddEntry("", "N_{#psi}: 1.2 < |y| < 2.2", "h");
			leg1->AddEntry("", "N_{ch}: #LT|#Delta#eta|#GT = 1.7", "h");
			leg1->Draw();

			TLegend *leg = new TLegend(0.48, 0.95-0.06*3, 0.95, 0.95);
			leg->SetFillStyle(0);
			leg->SetTextSize(0.05);
			leg->SetBorderSize(0);
			leg->AddEntry(g1d_svx_result[0], "PHENIX", "p");
			leg->AddEntry(g1d_fvtxs_scaled[0], "PYTHIA8 Monash", "lf");
			leg->AddEntry(g1d_fvtxs_scaled[1], "PYTHIA8 Detroit", "lf");
			leg->Draw();
			cZZ2->Update();
		


		}
	}
		

	cZZ2->SaveAs("PYTHIANew.png");
	cZZ2->SaveAs("PYTHIANew.pdf");
	
	c3->SaveAs("PYTHIA.png");


	TCanvas *cZZ3 = new TCanvas("cZZ3", "cZZ3",600 * 2, 600);

	cZZ3->cd();

	TPad *pad3[2];
	pad3[0] = new TPad("pad13","left pad",0.0,0.0,0.542,1.0);
	pad3[0]->SetTopMargin(0.04);
	pad3[0]->SetBottomMargin(0.14);
	pad3[0]->SetRightMargin(0.0);
	pad3[0]->SetLeftMargin(0.17);
	pad3[0]->Draw();

	pad3[1] = new TPad("pad23","middle pad",0.542,0.0,1.0,1.0);
	pad3[1]->SetTopMargin(0.04);
	pad3[1]->SetBottomMargin(0.14);
	pad3[1]->SetRightMargin(0.00);
	pad3[1]->SetLeftMargin(0.0);
	pad3[1]->Draw();





	for (int pset = 0; pset < 2; pset++)
	{
		if (pset == 0)
		{
			// oppo PYTHIA to PHENIX
			//c3->cd(3);
			pad3[1]->cd();
		
			//gPad->SetMargin(0.14, 0.01, 0.13, 0.03);
			//gPad->SetTicks();


			TH1D *htmp = (TH1D *)gPad->DrawFrame(0.001, 0, 6.5, 2.5);
			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
			htmp->GetXaxis()->SetLabelSize(0.05);
			htmp->GetXaxis()->SetTitleSize(0.06);
			htmp->GetXaxis()->SetNdivisions(9,4,0);
			htmp->GetXaxis()->SetTitleOffset(1.0);
			htmp->GetYaxis()->SetTitle("");
			htmp->GetYaxis()->SetLabelSize(0.00);
			htmp->GetYaxis()->SetTitleSize(0.00);
			htmp->GetYaxis()->SetTitleOffset(1111.05);


			htmp->GetYaxis()->SetNdivisions(9,5,0);
			htmp->GetXaxis()->CenterTitle();
			htmp->GetYaxis()->CenterTitle();

			TLine *line = new TLine(0.0,1,6.5,1);
			line->SetLineStyle(7);
			line->Draw();
/*
			g1d_fvtxs_scaled[0]->SetLineColorAlpha(kMagenta + 1, 0.3);
			g1d_fvtxs_scaled[0]->SetLineWidth(4);
			g1d_fvtxs_scaled[0]->SetFillColorAlpha(kMagenta + 1, 0.3);
			g1d_fvtxs_scaled[0]->Draw("L3");
*/
		//	g1d_fvtxs_scaled[1]->SetLineColorAlpha(kGreen + 2, 0.3);
			g1d_fvtxs_scaled[1]->SetLineColorAlpha(kCyan + 2, 0.3);

			g1d_fvtxs_scaled[1]->SetLineWidth(4);
		//	g1d_fvtxs_scaled[1]->SetFillColorAlpha(kGreen + 2, 0.3);
			g1d_fvtxs_scaled[1]->SetFillColorAlpha(kCyan + 2, 0.3);
			
			g1d_fvtxs_scaled[1]->Draw("L3");


			g1d_oppo_result[0]->SetMarkerStyle(21);
			
			g1d_oppo_result[0]->Draw("p");
			
			//g1d_oppo_result[1]->Draw("e2");
			PHENIXOppSyst->Draw("5SAME");


		
			g1d_alice_result[0]->Draw("p");
		//	g1d_alice_result[1]->SetFillColorAlpha(kGreen+2, 0.5);
//			g1d_alice_result[1]->Draw("5SAME");
			ALICESyst->SetLineColor(kGreen -7);	
			//ALICESyst[1]->SetFillStyle(0);
			ALICESyst->SetFillColorAlpha(kGreen -7,0.5);

			ALICESyst->Draw("5SAME");

			// oppo
			TLegend *leg1 = new TLegend(0.08, 0.95-0.06*4, 0.44, 0.95);
			leg1->SetFillStyle(0);
			leg1->SetTextSize(0.05);
			leg1->SetBorderSize(0);
			leg1->AddEntry(g1d_oppo_result[0], "PHENIX", "lp");

			leg1->AddEntry("", "p+p #sqrt{s} = 200 GeV", "h");
			leg1->AddEntry("", "N_{#psi}: 1.2 < y < 2.2", "h");
			//leg1->AddEntry("", "N_{ch}: #LT|#Delta#eta|#GT = 3.4", "h");
			leg1->AddEntry("", "N_{ch}: -2.4 < #eta < -1.2", "h");
	
			leg1->Draw();

			TLegend *leg = new TLegend(0.48, 0.95-0.06*1, 0.95, 0.95);
			leg->SetFillStyle(0);
			leg->SetTextSize(0.05);
			leg->SetBorderSize(0);
	//		leg->AddEntry(g1d_oppo_result[0], "PHENIX", "p");
	//		leg->AddEntry(g1d_fvtxs_scaled[0], "PYTHIA8 Monash", "lf");
	//		leg->AddEntry(g1d_fvtxs_scaled[1], "PYTHIA8 Detroit", "lf");
	//		leg->Draw();
			cZZ3->Update();
	

			TLegend *leg2 = new TLegend(0.48, 0.95-0.06*4, 0.88, 0.95);

		//	TLegend *leg2 = new TLegend(0.18, 0.1, 0.45, 0.34);
			leg2->SetFillStyle(0);
			leg2->SetTextSize(0.05);
			leg2->SetBorderSize(0);
			leg2->AddEntry(g1d_alice_result[0], "ALICE", "lp");
			leg2->AddEntry("", "p+p #sqrt{s} = 13 TeV", "");
			leg2->AddEntry("", "N_{#psi}: 2.5 < y < 4.0", "");
			leg2->AddEntry("", "N_{ch}: |#eta| < 1", "");

			leg2->Draw();


		}
		else if (pset == 1)
		{
			// same PYTHIA to PHENIX
			//c3->cd(1);
			//gPad->SetMargin(0.14, 0.01, 0.13, 0.03);
			//gPad->SetTicks();

			pad3[0]->cd();
		

			TH1D *htmp = (TH1D *)gPad->DrawFrame(0, 0, 6.5, 2.5);
			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
			htmp->GetXaxis()->SetLabelSize(0.05);
			htmp->GetXaxis()->SetTitleSize(0.06);
			htmp->GetXaxis()->SetNdivisions(9,4,0);
			htmp->GetXaxis()->SetTitleOffset(1.0);
			htmp->GetYaxis()->SetTitle("(N_{#psi(2S)}/N_{J/#psi}) #scale[1.5]{/} #LTN_{#psi(2S)}/N_{J/#psi}#GT");
			htmp->GetYaxis()->SetLabelSize(0.05);
			htmp->GetYaxis()->SetTitleSize(0.06);
			htmp->GetYaxis()->SetTitleOffset(1.2);
			htmp->GetYaxis()->SetNdivisions(9,5,0);
			htmp->GetXaxis()->CenterTitle();
			htmp->GetYaxis()->CenterTitle();

			TLine *line = new TLine(0.0,1,6.5,1);
			line->SetLineStyle(7);
			line->Draw();
/*
			g1d_fvtxn_scaled[0]->SetLineColorAlpha(kMagenta + 1, 0.3);
			g1d_fvtxn_scaled[0]->SetLineWidth(4);
			g1d_fvtxn_scaled[0]->SetFillColorAlpha(kMagenta + 1, 0.3);
			g1d_fvtxn_scaled[0]->Draw("L3");
*/
//			g1d_fvtxn_scaled[1]->SetLineColorAlpha(kGreen + 2, 0.3);
			g1d_fvtxn_scaled[1]->SetLineColorAlpha(kCyan + 2, 0.3);
	
			g1d_fvtxn_scaled[1]->SetLineWidth(4);
	//		g1d_fvtxn_scaled[1]->SetFillColorAlpha(kGreen + 2, 0.3);
			g1d_fvtxn_scaled[1]->SetFillColorAlpha(kCyan + 2, 0.3);
	
			g1d_fvtxn_scaled[1]->Draw("L3");

			g1d_same_result[0]->Draw("p");
				
		//	g1d_same_result[1]->SetLineColor(kRed -9);	
			//g1d_same_result[1]->SetFillStyle(3002);
		//	g1d_same_result[1]->SetFillColorAlpha(kRed -9,0.5);
	
		//	g1d_same_result[1]->Draw("5SAME");

			PHENIXSameSyst->Draw("5SAME");
			
			g1d_alice_result[0]->Draw("pSAME");

			ALICESyst->SetLineColor(kGreen -7);	
			//ALICESyst[1]->SetFillStyle(0);
			ALICESyst->SetFillColorAlpha(kGreen -7,0.5);

			ALICESyst->Draw("5SAME");



			if(IncludeLHCb){
	
				LHCbJpsiPrompt->Draw("epSAME");
				LHCbJpsiPromptSyst->SetLineColor(kOrange - 9);					
				LHCbJpsiPromptSyst->SetFillColorAlpha(kOrange - 9, 0.5);
				LHCbJpsiPromptSyst->Draw("5SAME");

				LHCbJpsiNP->Draw("epSAME");
				LHCbJpsiNPSyst->SetLineColor(kBlack);
				LHCbJpsiNPSyst->SetFillColorAlpha(kBlack, 0.5);
		
				LHCbJpsiNPSyst->Draw("5SAME");
			}

			// same
			TLegend *leg1 = new TLegend(0.20, 0.95-0.06*4, 0.50, 0.95);
			leg1->SetFillStyle(0);
			leg1->SetTextSize(0.05);
			leg1->SetBorderSize(0);
			leg1->AddEntry(g1d_same_result[0], "PHENIX", "lp");
			
			leg1->AddEntry("", "p+p #sqrt{s} = 200 GeV", "h");
			leg1->AddEntry("", "N_{#psi}: 1.2 < y < 2.2", "h");
			leg1->AddEntry("", "N_{ch}: 1.2 < #eta < 2.4", "h");
			leg1->Draw();

			TLegend *leg = new TLegend(0.22, 0.2, 0.60, 0.27);
			leg->SetFillStyle(0);
			leg->SetTextSize(0.05);
			leg->SetBorderSize(0);
	//		leg->AddEntry(g1d_same_result[0], "PHENIX", "p");
	//		leg->AddEntry(g1d_fvtxn_scaled[0], "PYTHIA8 Monash", "lf");
			leg->AddEntry(g1d_fvtxn_scaled[1], "PYTHIA8 (Detroit) with MPI", "lf");
			leg->Draw();
	//		lat->DrawLatex(0.23,0.62,"With MPI");


			TLegend *leg2 = new TLegend(0.57, 0.95-0.06*6, 0.87, 0.95);

		//	TLegend *leg2 = new TLegend(0.18, 0.1, 0.45, 0.34);
			leg2->SetFillStyle(0);
			leg2->SetTextSize(0.05);
			leg2->SetBorderSize(0);
			leg2->AddEntry("", "LHCb", "");
			leg2->AddEntry(LHCbJpsiPrompt, "Prompt J/#psi", "lp");
			leg2->AddEntry(LHCbJpsiNP, "Non-Prompt J/#psi", "lp");			
			leg2->AddEntry("", "p+p #sqrt{s} = 13 TeV", "");
			leg2->AddEntry("", "N_{#psi}: 2.0 < y < 4.5", "");
			leg2->AddEntry("", "N_{ch}: 1.5 < #eta < 5.2", "");

			leg2->Draw();
			//lat->DrawLatex(0.23,0.62,"With MPI");
			cZZ3->Update();
		


		}
		/*
		else if (pset == 2)
		{

			// svx PYTHIA to PHENIX
//			c3->cd(2);

			pad3[1]->cd();

			TH1D *htmp = (TH1D *)gPad->DrawFrame(0.001, 0, 6.5, 2.5); // alice
			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
			htmp->GetXaxis()->SetLabelSize(0.05);
			htmp->GetXaxis()->SetTitleSize(0.06);
			htmp->GetXaxis()->SetNdivisions(9,4,0);
			htmp->GetXaxis()->SetTitleOffset(1.0);
			htmp->GetYaxis()->SetTitle("");
			htmp->GetYaxis()->SetLabelSize(0.05);
			htmp->GetYaxis()->SetLabelSize(0.00);			
			htmp->GetYaxis()->SetTitleSize(0.06);
			htmp->GetYaxis()->SetTitleOffset(1.05);
			htmp->GetYaxis()->SetTitleOffset(1111.05);
			htmp->GetYaxis()->SetNdivisions(9,5,0);
			htmp->GetXaxis()->CenterTitle();
			htmp->GetYaxis()->CenterTitle();


			TLine *line = new TLine(0.0,1,6.5,1);
			line->SetLineStyle(7);
			line->Draw();

			g1d_svx_scaled[0]->SetLineColorAlpha(kMagenta + 1, 0.3);
			g1d_svx_scaled[0]->SetLineWidth(4);
			g1d_svx_scaled[0]->SetFillColorAlpha(kMagenta + 1, 0.3);
			g1d_svx_scaled[0]->Draw("L3");

//			g1d_svx_scaled[1]->SetLineColorAlpha(kGreen + 2, 0.3);
			g1d_svx_scaled[1]->SetFillColorAlpha(kCyan + 2, 0.3);
		
			g1d_svx_scaled[1]->SetLineWidth(4);
			//g1d_svx_scaled[1]->SetFillColorAlpha(kGreen + 2, 0.3);
			g1d_svx_scaled[1]->SetLineColorAlpha(kCyan + 2, 0.3);

		
			g1d_svx_scaled[1]->Draw("L3");

			g1d_svx_result[0]->Draw("p");
			g1d_svx_result[1]->Draw("e2");
			g1d_alice_result[0]->Draw("pSAME");
			g1d_alice_result[1]->Draw("e2SAME");


			TLegend *leg1 = new TLegend(0.08, 0.95-0.06*4, 0.4, 0.95);
			leg1->SetFillStyle(0);
			leg1->SetTextSize(0.05);
			leg1->SetBorderSize(0);
			leg1->AddEntry(g1d_svx_result[0], "PHENIX", "p");
			leg1->AddEntry("", "p+p #sqrt{s} = 200 GeV", "h");
			leg1->AddEntry("", "N_{#psi}: 1.2 < |y| < 2.2", "h");
			leg1->AddEntry("", "N_{ch}: #LT|#Delta#eta|#GT = 1.7", "h");
			leg1->Draw();

			:w
			TLegend *leg = new TLegend(0.48, 0.95-0.06*1, 0.95, 0.95);
			leg->SetFillStyle(0);
			leg->SetTextSize(0.05);
			leg->SetBorderSize(0);
	//		leg->AddEntry(g1d_svx_result[0], "PHENIX", "p");
	//		leg->AddEntry(g1d_svx_scaled[0], "PYTHIA8 Monash", "lf");
	//		leg->AddEntry(g1d_svx_scaled[1], "PYTHIA8 Detroit", "lf");
			leg->Draw();
			cZZ3->Update();
		


		}
	*/
	}
		


	if(!IncludeLHCb){
		cZZ3->SaveAs("BothNew.png");
		cZZ3->SaveAs("BothNew.pdf");

	}

	if(IncludeLHCb){
		cZZ3->SaveAs("BothNew-LHCb.png");
		cZZ3->SaveAs("BothNew-LHCb.pdf");

	}


}
