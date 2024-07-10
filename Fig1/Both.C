#ifndef __CINT__
#include "TROOT.h"
#include "TH1.h"
#include "TTree.h"
#include "TH2.h"
#include "TF1.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TVector2.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TRandom.h"
#include <iostream>
#include <fstream>
using namespace std;

using std::cout;
using std::endl;
#endif



void Both(){




	TLatex *lat = new TLatex();
	lat->SetNDC();
	lat->SetTextSize(0.034);




	gStyle->SetOptStat(0);
	TCanvas * c = new TCanvas("c","c",600,600);
	c->cd();


	c->SetTopMargin(0.04);
	c->SetBottomMargin(0.14);
	c->SetRightMargin(0.08);
	c->SetLeftMargin(0.17);


	const int NTypes = 2;
	const int NDir = 2;

	TString OutFileName[NTypes]={"FVTXN","FVTXS"};
	TString DataName = "PHENIX: #sqrt{s} = 200 GeV, 1.2 < |y| < 2.2";
	TString DataName2 = "PHENIX: Muon Subtracted";

	int Color[NTypes] = {2,4};



	float Min[NTypes] = {0,0};
	float Max[NTypes] = {20,20};


	//STAR Reference//

	const int NPointSTAR = 4;
	float XSTAR[NPointSTAR] = {0.4553571428571437,1.321428571428572,2.1875,3.0982142857142865};	
	float XSTARErr[NPointSTAR] = {0,0,0,0};	
	float XSTARSystErr[NPointSTAR] = {0.1,0.1,0.1,0.1};	

	float YSTAR[NPointSTAR] = {0.4210526315789451,1.6842105263157876,3.0526315789473664,5.210526315789473};
	float YSTARStatLow[NPointSTAR] = {0.4210526315789451,0.9999999999999964,2.6842105263157876,4.263157894736839};
	float YSTARSystLow[NPointSTAR] = {0.4210526315789451,1.3157894736842088,2.7894736842105274,3.3684210526315788};

	float StatErrorSTAR[NPointSTAR];
	float SystErrorSTAR[NPointSTAR];

	for(int i = 0; i < NPointSTAR; i++){

		StatErrorSTAR[i] = YSTAR[i] - YSTARStatLow[i];
		SystErrorSTAR[i] = YSTAR[i] - YSTARSystLow[i];

	}


	const int NPointALICE = 10;
	float XALICE[NPointALICE];
	float XALICEErr[NPointALICE] = {0,0,0,0,0};	
	float YALICE[NPointALICE] = {0.081,	0.387,1.230,2.498,4.201,6.208, 7.974, 10.071, 13.274, 14.968};
	float YALICECorr[NPointALICE] = {0.355,	0.640,1.003,1.186,1.411,1.642, 1.740, 1.871, 2.153, 2.100};


	//	float YALICEStatLow[NPointALICE] = {0.4210526315789451,1.0526315789473664,2.315789473684209,3.1052631578947327,6.473684210526315};
	//	float YALICESystLow[NPointALICE] = {0.4210526315789451,0.8947368421052637,2.0526315789473664,2.7894736842105274,7.7368421052631575};
	float XALICESystError[NPointALICE] = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};	

	float StatErrorALICE[NPointALICE] = {0.011,0.029,0.054,0.120,0.182,0.229,0.314,0.480,0.836,1.420};
	float SystErrorALICE[NPointALICE] = {0.004,0.019,0.035,0.080,0.143,0.169,0.216,0.506,0.794,1.056};

	for(int i = 0; i < NPointALICE; i++){
		XALICE[i] = YALICE[i]/YALICECorr[i];

		//		StatErrorALICE = YALICE[i] - YALICEStatLow[i];
		//		SystErrorALICE = YALICE[i] - YALICESystLow[i];

	}



	const int NPointALICE2 = 9;
	float XALICE2[NPointALICE2] = {0.37777171317459235,1.0115985535921403,2.025243910759364,2.557412840281095,3.229037320051852,3.913283755202292,4.6734666029883325,5.674421777990039,7.270450979054377};
	float XALICEErr2[NPointALICE2] = {0,0,0,0,0};	
	float YALICE2[NPointALICE2] = {0.32673807736917837,	0.8711878283414087 ,2.1186463805690146,2.7695299174455883,3.5294398580882884,4.343248959541519, 5.31916490414137, 6.566487002797299, 8.89547656409907};



	float YALICEStatLow2[NPointALICE2] = {0.32673807736917837,	0.8711878283414087 ,2.1186463805690146,2.7695299174455883,3.5294398580882884,4.343248959541519, 5.31916490414137, 6.566487002797299, 9.43310363648769};
	float YALICESystLow2[NPointALICE2] = {0.32673807736917837,	0.8711878283414087 ,2.1186463805690146,2.7695299174455883,3.5294398580882884,4.612062495735827, 5.587978440335679, 6.8889267926588005, 9.48686634372655};

	float XALICESystError2[NPointALICE2] = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};	

	float StatErrorALICE2[NPointALICE2];
	float SystErrorALICE2[NPointALICE2];

	for(int i = 0; i < NPointALICE2; i++){

		StatErrorALICE2[i] = YALICEStatLow2[i] - YALICE2[i];
		SystErrorALICE2[i] = YALICESystLow2[i] - YALICE2[i];

	}






	TGraphErrors * STAR = new TGraphErrors(NPointSTAR,XSTAR,YSTAR,XSTARErr,StatErrorSTAR);
	STAR->SetLineColor(kOrange-3);
	STAR->SetMarkerColor(kOrange-3);
	STAR->SetMarkerSize(1);
	STAR->SetMarkerStyle(21);

	TGraphErrors * STARSyst = new TGraphErrors(NPointSTAR,XSTAR,YSTAR,XSTARSystErr,SystErrorSTAR);
	STARSyst->SetFillColorAlpha(kOrange-3,0.5);
	STARSyst->SetLineColor(kOrange-3);



	TGraphErrors * ALICEMidRap = new TGraphErrors(NPointALICE,XALICE,YALICE,XALICEErr,StatErrorALICE);
	ALICEMidRap->SetLineColor(kMagenta-3);
	ALICEMidRap->SetMarkerColor(kMagenta-3);
	ALICEMidRap->SetMarkerSize(1);
	ALICEMidRap->SetMarkerStyle(33);

	TGraphErrors * ALICEMidRapSyst = new TGraphErrors(NPointALICE,XALICE,YALICE,XALICESystError,SystErrorALICE);
	ALICEMidRapSyst->SetFillColorAlpha(kMagenta-3,0.5);
	ALICEMidRapSyst->SetLineColor(kMagenta-3);






	TGraphErrors * ALICEPeri = new TGraphErrors(NPointALICE2,XALICE2,YALICE2,XALICEErr2,StatErrorALICE2);
	ALICEPeri->SetLineColor(kCyan+2);
	ALICEPeri->SetMarkerColor(kCyan+2);
	ALICEPeri->SetMarkerSize(1);
	ALICEPeri->SetMarkerStyle(34);

	TGraphErrors * ALICEPeriSyst = new TGraphErrors(NPointALICE2,XALICE2,YALICE2,XALICESystError2,SystErrorALICE2);
	ALICEPeriSyst->SetFillColorAlpha(kCyan+2,0.5);
	ALICEPeriSyst->SetLineColor(kCyan+2);


	const int NPYTHIAPoints = 12;
	float PYTHIAX[NPYTHIAPoints];
	float PYTHIAMonashY[NPYTHIAPoints] = {0.03953093885979797, 0.5439929198318492, 1.331366619957226, 1.942031123239179, 2.80050151191091,3.517368537502768,4.057231359244784,4.525997492440448,4.676451065712813,4.968508002065052,2.8887086068294145,5.127516778523494};
	float PYTHIADetroitY[NPYTHIAPoints] = {0.048528652555496876, 0.46448853160262615,1.0931484622759804,2.1109226344125673,3.341101851168964,4.217272660225679,5.270447673132235,6.5714285714285685,8.12021535511468,8.111660151928605,9.90795781399808,10.5};
	float PYTHIAXErr[NPYTHIAPoints];
	float PYTHIAMonashYErr[NPYTHIAPoints];
	float PYTHIADetroitYErr[NPYTHIAPoints];

	for(int i =0; i < NPYTHIAPoints; i++){

		PYTHIAX[i] = i * 0.5 + 0.25;
		PYTHIAXErr[i] = 0.25;
		PYTHIAMonashYErr[i] = 0.01 * PYTHIAMonashY[i] * i;
		PYTHIADetroitYErr[i] = 0.01 * PYTHIADetroitY[i] * i;

	}



	TGraphErrors * PYTHIAMonash = new TGraphErrors(NPYTHIAPoints,PYTHIAX,PYTHIAMonashY,PYTHIAXErr,PYTHIAMonashYErr);
	PYTHIAMonash->SetLineColor(kBlack);
	PYTHIAMonash->SetMarkerColor(kBlack);
	PYTHIAMonash->SetMarkerSize(1);
	PYTHIAMonash->SetMarkerStyle(22);




	TGraphErrors * PYTHIADetroit = new TGraphErrors(NPYTHIAPoints,PYTHIAX,PYTHIADetroitY,PYTHIAXErr,PYTHIADetroitYErr);
	PYTHIADetroit->SetLineColor(26);
	PYTHIADetroit->SetMarkerColor(26);
	PYTHIADetroit->SetMarkerSize(1);
	PYTHIADetroit->SetMarkerStyle(23);






	TLegend * leg = new TLegend(0.18,0.58,0.37,0.97,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.034);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	leg->SetLineWidth(1);






	TString infile = "SameUnCorr.root";


	TFile * fin = new TFile(infile.Data());

	TGraphErrors * Inclusive = (TGraphErrors * ) fin->Get("Inclusive");
	TGraphErrors *Syst = (TGraphErrors *) fin->Get("InclusiveSyst");

	Inclusive->SetMarkerColor(kRed);
	Inclusive->SetLineColor(kRed);
	
	Syst->SetFillColorAlpha(kRed-9,0.5);
	Syst->SetLineColor(kRed-9);


	TString infile2 = "SameCorr.root";


	TFile * fin2 = new TFile(infile2.Data());

	TGraphErrors * Inclusive2 = (TGraphErrors * ) fin2->Get("Inclusive");
	TGraphErrors *Syst2 = (TGraphErrors *) fin2->Get("InclusiveSyst");

	Inclusive2->SetMarkerColor(kMagenta);
	Inclusive2->SetLineColor(kMagenta);
	
	Syst2->SetFillColorAlpha(kMagenta-9,0.5);
	Syst2->SetLineColor(kMagenta-9);


	TH2D * EmptyHis = new TH2D("EmptyHis","",100,0,10,100,0.001,20);
	EmptyHis->GetXaxis()->SetTitle("N_{ch}/#LT N_{ch}#GT");
	EmptyHis->GetYaxis()->SetTitle("N_{J/#psi}/#LT N_{J/#psi}#GT");
	EmptyHis->SetTitle("");
	EmptyHis->GetXaxis()->CenterTitle();
	EmptyHis->GetYaxis()->CenterTitle();


	EmptyHis->GetXaxis()->SetLabelSize(0.05);
	EmptyHis->GetXaxis()->SetTitleSize(0.06);

	EmptyHis->GetYaxis()->SetLabelSize(0.05);
	EmptyHis->GetYaxis()->SetTitleSize(0.06);
	EmptyHis->Draw();


	Inclusive->Draw("PSAME");
	Syst->Draw("5SAME");



	Inclusive2->SetMarkerStyle(24);

	Inclusive2->Draw("epSAME");
	Syst2->Draw("5SAME");


	STAR->Draw("epSAME");
	STARSyst->Draw("5SAME");

	ALICEMidRap->Draw("epSAME");
	ALICEMidRapSyst->Draw("5SAME");

	ALICEPeri->Draw("epSAME");
	ALICEPeriSyst->Draw("5SAME");

	//		PYTHIAMonash->Draw("epSAME");
	//		PYTHIADetroit->Draw("epSAME");
		
	leg->AddEntry(Inclusive,DataName.Data(),"LP");
	leg->AddEntry(Inclusive2,DataName2.Data(),"LP");

	leg->AddEntry(STAR,"STAR: #sqrt{s} = 200 GeV, |y| < 1","LP");
	leg->AddEntry(ALICEMidRap,"ALICE: #sqrt{s} = 13 TeV, |y| < 0.9","LP");
	leg->AddEntry(ALICEPeri,"ALICE: #sqrt{s} = 13 TeV, 2.5 < y < 4","LP");
	//		leg->AddEntry(PYTHIAMonash,"PYTHIA 8: Monash Tune (Gen Level)","LP");
	//		leg->AddEntry(PYTHIADetroit,"PYTHIA 8: Detroit Tune (Gen Level)","LP");


	leg->Draw("SAME");
	lat->DrawLatex(0.20,0.55,"N_{ch} #eta range");
	lat->DrawLatex(0.20,0.50,"PHENIX: 1.2 < |#eta| < 2.4");
	lat->DrawLatex(0.20,0.45,"STAR: |#eta| < 1");
	lat->DrawLatex(0.20,0.40,"ALICE: |#eta| < 1");


	c->SaveAs("Fig1.png");
	c->SaveAs("Fig1.pdf");









}




