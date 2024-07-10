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



void MergeSame(int Opt){


	const int NTypes = 2;
	const int NDir = 2;
	TString infile;
	
	int Color[NTypes] = {2,4};

	TString InName[NTypes] = {"UnCorr","Corr"};

	TString OutName = Form("Same%s.root",InName[Opt].Data());

	TFile * fout = new TFile(OutName.Data(),"RECREATE");

	fout->cd();

	
	const int NPoints = 10;
	float Nch[NPoints];
	float NJpsi[NPoints];
	float NJpsiStatErr[NPoints];
	float NJpsiErr[NPoints];
	float NchSystErr[NPoints];
	float NJpsiSystErr[NPoints];
	float NchErr[NPoints];


	float NchN[NPoints];
	float NJpsiN[NPoints];
	float NchNErr[NPoints];
	float NJpsiNStatErr[NPoints];
	
	float NJpsiNErr[NPoints];
	float NchNSystErr[NPoints];
	float NJpsiNSystErr[NPoints];


	float NchS[NPoints];
	float NJpsiS[NPoints];
	float NchSErr[NPoints];
	float NJpsiSStatErr[NPoints];
	
	float NJpsiSErr[NPoints];
	float NchSSystErr[NPoints];
	float NJpsiSSystErr[NPoints];


	float wtotalStat[NPoints];
	float wtotalSyst[NPoints];
	float wtotal[NPoints];







	TString infile1 = Form("%s/JPsiR_0_0.root",InName[Opt].Data());
	TFile * fin1 = new TFile(infile1.Data());
	TH1D * RatioScaledCorr1 = (TH1D * ) fin1->Get("RatioScaledCorr");
	TGraphAsymmErrors *Syst1 = (TGraphAsymmErrors *) fin1->Get("Graph");




	TString infile2 = Form("%s/JPsiR_1_1.root",InName[Opt].Data());
	TFile * fin2 = new TFile(infile2.Data());
	TH1D * RatioScaledCorr2 = (TH1D * ) fin2->Get("RatioScaledCorr");
	TGraphAsymmErrors *Syst2 = (TGraphAsymmErrors *) fin2->Get("Graph");
	



	for(int i = 0; i < NPoints; i++){

		NchN[i] = RatioScaledCorr1->GetBinCenter(i+1);
		NJpsiN[i] = RatioScaledCorr1->GetBinContent(i+1);
		NJpsiNStatErr[i] = RatioScaledCorr1->GetBinError(i+1);

		NchS[i] = RatioScaledCorr2->GetBinCenter(i+1);
		NJpsiS[i] = RatioScaledCorr2->GetBinContent(i+1);
		NJpsiSStatErr[i] = RatioScaledCorr2->GetBinError(i+1);
	
		NJpsiNSystErr[i] = Syst1->GetErrorY(i);
		NJpsiSSystErr[i] = Syst2->GetErrorY(i);


		Nch[i] = (NchN[i] + NchS[i])/2;

		NJpsiNErr[i] = sqrt(NJpsiNStatErr[i] * NJpsiNStatErr[i] + NJpsiNSystErr[i] * NJpsiNSystErr[i]);
		NJpsiSErr[i] = sqrt(NJpsiSStatErr[i] * NJpsiSStatErr[i] + NJpsiSSystErr[i] * NJpsiSSystErr[i]);

		wtotalStat[i] = 1/(NJpsiNStatErr[i] * NJpsiNStatErr[i]) + 1/(NJpsiSStatErr[i] * NJpsiSStatErr[i]);
		wtotalSyst[i] = 1/(NJpsiNSystErr[i] * NJpsiNSystErr[i]) + 1/(NJpsiSSystErr[i] * NJpsiSSystErr[i]);
		wtotal[i] = 1/(NJpsiNErr[i] * NJpsiNErr[i]) + 1/(NJpsiSErr[i] * NJpsiSErr[i]);


		cout << "wtotal[i]  = " << wtotal[i]  << endl;

		NJpsi[i] = (NJpsiN[i]/(NJpsiNErr[i] * NJpsiNErr[i]) + NJpsiS[i]/(NJpsiSErr[i] * NJpsiSErr[i]))/wtotal[i];
		NJpsiStatErr[i] = 1/sqrt(wtotalStat[i]);
		NJpsiSystErr[i] = 1/sqrt(wtotalSyst[i]);

		cout <<  "i: " << i << "   Nch[i] = " << Nch[i] << "   NJpsi[i] = " << NJpsi[i] << "   NJpsiStatErr[i] = " << NJpsiStatErr[i] << "  NJpsiSystErr[i] = " << NJpsiSystErr[i] << endl;

		NchErr[i] = 0.00;
		NchSystErr[i] = 0.1;
		
	}






	TLatex *lat = new TLatex();
	lat->SetNDC();
	lat->SetTextSize(0.032);




	gStyle->SetOptStat(0);
	TCanvas * c = new TCanvas("c","c",600,600);
	c->cd();


	TGraphErrors * Inclusive = new TGraphErrors(NPoints,Nch,NJpsi,NchErr,NJpsiStatErr);
	TGraphErrors * InclusiveSyst = new TGraphErrors(NPoints,Nch,NJpsi,NchSystErr,NJpsiSystErr);

	Inclusive->SetName("Inclusive");
	InclusiveSyst->SetName("InclusiveSyst");


	Inclusive->SetMarkerStyle(20);
	Inclusive->SetMarkerSize(1);
	Inclusive->SetMarkerColor(1);
	Inclusive->SetLineColor(1);
	

	TH2D * EmptyHis = new TH2D("EmptyHis","",100,0,11,100,0,20);
	EmptyHis->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
	EmptyHis->GetYaxis()->SetTitle("R(J/#psi)");

	EmptyHis->Draw();
	Inclusive->Draw("epSAME");
	

	c->SaveAs(Form("%sMerge.png",InName[Opt].Data()));

	fout->cd();
	Inclusive->Write();
	InclusiveSyst->Write();


	fout->Close();

}




