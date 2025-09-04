#include "Style.h"

void DrawCompPHENIXAndPythia(){

	const bool bSAVE = false;

	gStyle->SetOptStat(0);

	const int nset = 14;
	const int narm = 2;

	const int nmultbin[14] = {
		200, 200, 200, 200, 
		200, 200, 200, 200, 
		200, 200, 200, 200, 
		200, 200};

	string setname[14] = {
		"Monash", "Detroit", "Monash", "Detroit", 
		"Monash", "Detroit", "Monash", "Detroit", 
		"Monash", "Detroit", "Monash", "Detroit",
		"Monash", "Detroit"
	};

	//set0-1, v8.2
	//set2-3, v8.3
	//set4-5, v8.2, w/o MPI
	//set6-7, v8.3, w/o MPI
	//set8-9, v8.3, w/ rescattering
	//set10-11, v8.2, CS
	//set12-13, v8.2, CO

	TFile *infile[nset];

	for (int iset=0; iset<nset; iset++){
		if ( iset<2 ){
			infile[iset] = new TFile(Form("outfile_ScanPythiaJpsi03_pp200GeV_%s_%d.root",setname[iset].c_str(),10),"read");
		}else if ( iset<4 ){
			infile[iset] = new TFile(Form("outfile_ScanPythiaJpsi03_pp200GeV_%s_%d.root",setname[iset].c_str(),11),"read");
		}else if ( iset<6 ){
			infile[iset] = new TFile(Form("outfile_ScanPythiaJpsi03_pp200GeV_%s_%d.root",setname[iset].c_str(),12),"read");
		}else if ( iset<8 ){
			infile[iset] = new TFile(Form("outfile_ScanPythiaJpsi03_pp200GeV_%s_%d.root",setname[iset].c_str(),13),"read");
		}else if ( iset<10 ){
			infile[iset] = new TFile(Form("outfile_ScanPythiaJpsi03_pp200GeV_%s_%d.root",setname[iset].c_str(),14),"read");
		}else if ( iset<12 ){
			infile[iset] = new TFile(Form("outfile_ScanPythiaJpsi03_pp200GeV_%s_%d.root",setname[iset].c_str(),15),"read");
		}else if ( iset<14 ){
			infile[iset] = new TFile(Form("outfile_ScanPythiaJpsi03_pp200GeV_%s_%d.root",setname[iset].c_str(),16),"read");
		}
		cout << "OPEN: " << infile[iset]->GetName() << endl;
	}

	TH2D *heta_pt[nset];
	TH1D *heta[nset];

	TH1D *hnsvx_mb[nset];
	TH1D *hnfvtxs1030_mb[nset];
	TH1D *hnfvtxs1226_mb[nset];
	TH1D *hnfvtxn1030_mb[nset];
	TH1D *hnfvtxn1226_mb[nset];

	TH1D *hnsvx_mb_scaled[nset];
	TH1D *hnfvtxs1030_mb_scaled[nset];
	TH1D *hnfvtxs1226_mb_scaled[nset];
	TH1D *hnfvtxn1030_mb_scaled[nset];
	TH1D *hnfvtxn1226_mb_scaled[nset];

	TH2D *heta_pt_jpsi[nset][narm];
	TH1D *heta_jpsi[nset][narm];

	TH1D *hnsvx[nset][narm];
	TH1D *hnfvtxs1030[nset][narm];
	TH1D *hnfvtxs1226[nset][narm];
	TH1D *hnfvtxn1030[nset][narm];
	TH1D *hnfvtxn1226[nset][narm];
	TH1D *hnfvtxs1030_mu[nset][narm];
	TH1D *hnfvtxs1226_mu[nset][narm];
	TH1D *hnfvtxn1030_mu[nset][narm];
	TH1D *hnfvtxn1226_mu[nset][narm];

	TH1D *hnsvx_scaled[nset][narm];
	TH1D *hnfvtxs1030_scaled[nset][narm];
	TH1D *hnfvtxs1226_scaled[nset][narm];
	TH1D *hnfvtxn1030_scaled[nset][narm];
	TH1D *hnfvtxn1226_scaled[nset][narm];
	TH1D *hnfvtxs1030_mu_scaled[nset][narm];
	TH1D *hnfvtxs1226_mu_scaled[nset][narm];
	TH1D *hnfvtxn1030_mu_scaled[nset][narm];
	TH1D *hnfvtxn1226_mu_scaled[nset][narm];

	TH1D *hrsvx[nset][narm];
	TH1D *hrfvtxs1030[nset][narm];
	TH1D *hrfvtxs1226[nset][narm];
	TH1D *hrfvtxn1030[nset][narm];
	TH1D *hrfvtxn1226[nset][narm];
	TH1D *hrfvtxs1030_mu[nset][narm];
	TH1D *hrfvtxs1226_mu[nset][narm];
	TH1D *hrfvtxn1030_mu[nset][narm];
	TH1D *hrfvtxn1226_mu[nset][narm];

	TH1D *hrsvx_scaled[nset][narm];
	TH1D *hrfvtxs1030_scaled[nset][narm];
	TH1D *hrfvtxs1226_scaled[nset][narm];
	TH1D *hrfvtxn1030_scaled[nset][narm];
	TH1D *hrfvtxn1226_scaled[nset][narm];
	TH1D *hrfvtxs1030_mu_scaled[nset][narm];
	TH1D *hrfvtxs1226_mu_scaled[nset][narm];
	TH1D *hrfvtxn1030_mu_scaled[nset][narm];
	TH1D *hrfvtxn1226_mu_scaled[nset][narm];

	TH1D *hr2svx[nset][narm];
	TH1D *hr2fvtxs1030[nset][narm];
	TH1D *hr2fvtxs1226[nset][narm];
	TH1D *hr2fvtxn1030[nset][narm];
	TH1D *hr2fvtxn1226[nset][narm];
	TH1D *hr2fvtxs1030_mu[nset][narm];
	TH1D *hr2fvtxs1226_mu[nset][narm];
	TH1D *hr2fvtxn1030_mu[nset][narm];
	TH1D *hr2fvtxn1226_mu[nset][narm];

	TH1D *hr2svx_scaled[nset][narm];
	TH1D *hr2fvtxs1030_scaled[nset][narm];
	TH1D *hr2fvtxs1226_scaled[nset][narm];
	TH1D *hr2fvtxn1030_scaled[nset][narm];
	TH1D *hr2fvtxn1226_scaled[nset][narm];
	TH1D *hr2fvtxs1030_mu_scaled[nset][narm];
	TH1D *hr2fvtxs1226_mu_scaled[nset][narm];
	TH1D *hr2fvtxn1030_mu_scaled[nset][narm];
	TH1D *hr2fvtxn1226_mu_scaled[nset][narm];

	float rjpsi_mb[nset][narm];

	for (int iset=0; iset<nset; iset++){
		hnsvx_mb[iset] = (TH1D*)infile[iset]->Get("hnsvx_mb");
		hnfvtxs1030_mb[iset] = (TH1D*)infile[iset]->Get("hnfvtxs1030_mb");
		hnfvtxs1226_mb[iset] = (TH1D*)infile[iset]->Get("hnfvtxs1226_mb");
		hnfvtxn1030_mb[iset] = (TH1D*)infile[iset]->Get("hnfvtxn1030_mb");
		hnfvtxn1226_mb[iset] = (TH1D*)infile[iset]->Get("hnfvtxn1226_mb");

		hnsvx_mb_scaled[iset] = new TH1D(Form("hnsvx_mb_scaled_%d",iset),"",20,0,10);
		hnfvtxs1030_mb_scaled[iset] = new TH1D(Form("hnfvtxs1030_mb_scaled_%d",iset),"",20,0,10);
		hnfvtxs1226_mb_scaled[iset] = new TH1D(Form("hnfvtxs1226_mb_scaled_%d",iset),"",20,0,10);
		hnfvtxn1030_mb_scaled[iset] = new TH1D(Form("hnfvtxn1030_mb_scaled_%d",iset),"",20,0,10);
		hnfvtxn1226_mb_scaled[iset] = new TH1D(Form("hnfvtxn1226_mb_scaled_%d",iset),"",20,0,10);

		float mean_svx = hnsvx_mb[iset]->GetMean();
		float mean_fvtxs1030 = hnfvtxs1030_mb[iset]->GetMean();
		float mean_fvtxs1226 = hnfvtxs1226_mb[iset]->GetMean();
		float mean_fvtxn1030 = hnfvtxn1030_mb[iset]->GetMean();
		float mean_fvtxn1226 = hnfvtxn1226_mb[iset]->GetMean();

		heta_pt[iset] = (TH2D*)infile[iset]->Get("heta_pt");
		heta[iset] = (TH1D*)heta_pt[iset]->ProjectionX(Form("heta_set%d",iset));
		heta[iset]->Scale(1./heta[iset]->GetBinWidth(1));
		heta[iset]->Scale(1./hnsvx_mb[iset]->Integral());

		//cout << iset << " " << mean_svx << " " << mean_fvtxs << " " << mean_fvtxn << endl;

		for (int ii=0; ii<nmultbin[iset]; ii++){
			float xx = hnsvx_mb[iset]->GetBinLowEdge(ii+1);
			float yy = hnsvx_mb[iset]->GetBinContent(ii+1);
			hnsvx_mb_scaled[iset]->Fill(xx/mean_svx, yy);

			xx = hnfvtxs1030_mb[iset]->GetBinLowEdge(ii+1);
			yy = hnfvtxs1030_mb[iset]->GetBinContent(ii+1);
			hnfvtxs1030_mb_scaled[iset]->Fill(xx/mean_fvtxs1030, yy);

			xx = hnfvtxs1226_mb[iset]->GetBinLowEdge(ii+1);
			yy = hnfvtxs1226_mb[iset]->GetBinContent(ii+1);
			hnfvtxs1226_mb_scaled[iset]->Fill(xx/mean_fvtxs1226, yy);

			xx = hnfvtxn1030_mb[iset]->GetBinLowEdge(ii+1);
			yy = hnfvtxn1030_mb[iset]->GetBinContent(ii+1);
			hnfvtxn1030_mb_scaled[iset]->Fill(xx/mean_fvtxn1030, yy);

			xx = hnfvtxn1226_mb[iset]->GetBinLowEdge(ii+1);
			yy = hnfvtxn1226_mb[iset]->GetBinContent(ii+1);
			hnfvtxn1226_mb_scaled[iset]->Fill(xx/mean_fvtxn1226, yy);
		}

		for (int iarm=0; iarm<narm; iarm++){
			hnsvx[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnsvx_%d",iarm));
			hnfvtxs1030[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxs1030_%d",iarm));
			hnfvtxs1226[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxs1226_%d",iarm));
			hnfvtxn1030[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxn1030_%d",iarm));
			hnfvtxn1226[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxn1226_%d",iarm));
			hnfvtxs1030_mu[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxs1030_mu_%d",iarm));
			hnfvtxs1226_mu[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxs1226_mu_%d",iarm));
			hnfvtxn1030_mu[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxn1030_mu_%d",iarm));
			hnfvtxn1226_mu[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxn1226_mu_%d",iarm));

			hnsvx_scaled[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnsvx_scaled_%d",iarm));
			hnfvtxs1030_scaled[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxs1030_scaled_%d",iarm));
			hnfvtxs1226_scaled[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxs1226_scaled_%d",iarm));
			hnfvtxn1030_scaled[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxn1030_scaled_%d",iarm));
			hnfvtxn1226_scaled[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxn1226_scaled_%d",iarm));
			hnfvtxs1030_mu_scaled[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxs1030_mu_scaled_%d",iarm));
			hnfvtxs1226_mu_scaled[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxs1226_mu_scaled_%d",iarm));
			hnfvtxn1030_mu_scaled[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxn1030_mu_scaled_%d",iarm));
			hnfvtxn1226_mu_scaled[iset][iarm] = (TH1D*)infile[iset]->Get(Form("hnfvtxn1226_mu_scaled_%d",iarm));

			hrsvx[iset][iarm] = (TH1D*)hnsvx[iset][iarm]->Clone(Form("hrsvx_%d_%d",iset,iarm));
			hrfvtxs1030[iset][iarm] = (TH1D*)hnfvtxs1030[iset][iarm]->Clone(Form("hrfvtxs1030_%d_%d",iset,iarm));
			hrfvtxs1226[iset][iarm] = (TH1D*)hnfvtxs1226[iset][iarm]->Clone(Form("hrfvtxs1226_%d_%d",iset,iarm));
			hrfvtxn1030[iset][iarm] = (TH1D*)hnfvtxn1030[iset][iarm]->Clone(Form("hrfvtxn1030_%d_%d",iset,iarm));
			hrfvtxn1226[iset][iarm] = (TH1D*)hnfvtxn1226[iset][iarm]->Clone(Form("hrfvtxn1226_%d_%d",iset,iarm));
			hrfvtxs1030_mu[iset][iarm] = (TH1D*)hnfvtxs1030_mu[iset][iarm]->Clone(Form("hrfvtxs1030_mu_%d_%d",iset,iarm));
			hrfvtxs1226_mu[iset][iarm] = (TH1D*)hnfvtxs1226_mu[iset][iarm]->Clone(Form("hrfvtxs1226_mu_%d_%d",iset,iarm));
			hrfvtxn1030_mu[iset][iarm] = (TH1D*)hnfvtxn1030_mu[iset][iarm]->Clone(Form("hrfvtxn1030_mu_%d_%d",iset,iarm));
			hrfvtxn1226_mu[iset][iarm] = (TH1D*)hnfvtxn1226_mu[iset][iarm]->Clone(Form("hrfvtxn1226_mu_%d_%d",iset,iarm));

			hrsvx_scaled[iset][iarm] = (TH1D*)hnsvx_scaled[iset][iarm]->Clone(Form("hrsvx_scaled_%d_%d",iset,iarm));
			hrfvtxs1030_scaled[iset][iarm] = (TH1D*)hnfvtxs1030_scaled[iset][iarm]->Clone(Form("hrfvtxs1030_scaled_%d_%d",iset,iarm));
			hrfvtxs1226_scaled[iset][iarm] = (TH1D*)hnfvtxs1226_scaled[iset][iarm]->Clone(Form("hrfvtxs1226_scaled_%d_%d",iset,iarm));
			hrfvtxn1030_scaled[iset][iarm] = (TH1D*)hnfvtxn1030_scaled[iset][iarm]->Clone(Form("hrfvtxn1030_scaled_%d_%d",iset,iarm));
			hrfvtxn1226_scaled[iset][iarm] = (TH1D*)hnfvtxn1226_scaled[iset][iarm]->Clone(Form("hrfvtxn1226_scaled_%d_%d",iset,iarm));
			hrfvtxs1030_mu_scaled[iset][iarm] = (TH1D*)hnfvtxs1030_mu_scaled[iset][iarm]->Clone(Form("hrfvtxs1030_mu_scaled_%d_%d",iset,iarm));
			hrfvtxs1226_mu_scaled[iset][iarm] = (TH1D*)hnfvtxs1226_mu_scaled[iset][iarm]->Clone(Form("hrfvtxs1226_mu_scaled_%d_%d",iset,iarm));
			hrfvtxn1030_mu_scaled[iset][iarm] = (TH1D*)hnfvtxn1030_mu_scaled[iset][iarm]->Clone(Form("hrfvtxn1030_mu_scaled_%d_%d",iset,iarm));
			hrfvtxn1226_mu_scaled[iset][iarm] = (TH1D*)hnfvtxn1226_mu_scaled[iset][iarm]->Clone(Form("hrfvtxn1226_mu_scaled_%d_%d",iset,iarm));

			hrsvx[iset][iarm]->Sumw2();
			hrfvtxs1030[iset][iarm]->Sumw2();
			hrfvtxs1226[iset][iarm]->Sumw2();
			hrfvtxn1030[iset][iarm]->Sumw2();
			hrfvtxn1226[iset][iarm]->Sumw2();
			hrfvtxs1030_mu[iset][iarm]->Sumw2();
			hrfvtxs1226_mu[iset][iarm]->Sumw2();
			hrfvtxn1030_mu[iset][iarm]->Sumw2();
			hrfvtxn1226_mu[iset][iarm]->Sumw2();

			hrsvx_scaled[iset][iarm]->Sumw2();
			hrfvtxs1030_scaled[iset][iarm]->Sumw2();
			hrfvtxs1226_scaled[iset][iarm]->Sumw2();
			hrfvtxn1030_scaled[iset][iarm]->Sumw2();
			hrfvtxn1226_scaled[iset][iarm]->Sumw2();
			hrfvtxs1030_mu_scaled[iset][iarm]->Sumw2();
			hrfvtxs1226_mu_scaled[iset][iarm]->Sumw2();
			hrfvtxn1030_mu_scaled[iset][iarm]->Sumw2();
			hrfvtxn1226_mu_scaled[iset][iarm]->Sumw2();


			for (int ii=0; ii<nmultbin[iset]; ii++){
				float yy = hrsvx[iset][iarm]->GetBinContent(ii+1);
				float yy_err = hrsvx[iset][iarm]->GetBinError(ii+1);
				float norm = hnsvx_mb[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrsvx[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrsvx[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxs1030[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxs1030[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxs1030_mb[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxs1030[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxs1030[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxn1030[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxn1030[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxn1030_mb[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxn1030[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxn1030[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxs1226[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxs1226[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxs1226_mb[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxs1226[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxs1226[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxn1226[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxn1226[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxn1226_mb[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxn1226[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxn1226[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxs1030_mu[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxs1030_mu[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxs1030_mb[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxs1030_mu[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxs1030_mu[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxn1030_mu[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxn1030_mu[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxn1030_mb[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxn1030_mu[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxn1030_mu[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxs1226_mu[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxs1226_mu[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxs1226_mb[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxs1226_mu[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxs1226_mu[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxn1226_mu[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxn1226_mu[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxn1226_mb[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxn1226_mu[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxn1226_mu[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				//scaled
				yy = hrsvx_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrsvx_scaled[iset][iarm]->GetBinError(ii+1);
				norm = hnsvx_mb_scaled[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrsvx_scaled[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrsvx_scaled[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxs1030_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxs1030_scaled[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxs1030_mb_scaled[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxs1030_scaled[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxs1030_scaled[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxn1030_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxn1030_scaled[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxn1030_mb_scaled[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxn1030_scaled[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxn1030_scaled[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxs1226_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxs1226_scaled[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxs1226_mb_scaled[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxs1226_scaled[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxs1226_scaled[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxn1226_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxn1226_scaled[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxn1226_mb_scaled[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxn1226_scaled[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxn1226_scaled[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxs1030_mu_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxs1030_mu_scaled[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxs1030_mb_scaled[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxs1030_mu_scaled[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxs1030_mu_scaled[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxn1030_mu_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxn1030_mu_scaled[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxn1030_mb_scaled[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxn1030_mu_scaled[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxn1030_mu_scaled[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxs1226_mu_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxs1226_mu_scaled[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxs1226_mb_scaled[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxs1226_mu_scaled[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxs1226_mu_scaled[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

				yy = hrfvtxn1226_mu_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hrfvtxn1226_mu_scaled[iset][iarm]->GetBinError(ii+1);
				norm = hnfvtxn1226_mb_scaled[iset]->GetBinContent(ii+1);
				if ( yy>0 ){
					hrfvtxn1226_mu_scaled[iset][iarm]->SetBinContent(ii+1, yy/norm);
					hrfvtxn1226_mu_scaled[iset][iarm]->SetBinError(ii+1, yy_err/norm);
				}

			}//ii

			float njpsi = hnsvx[iset][iarm]->Integral();
			float nevent = hnsvx_mb[iset]->Integral();

			rjpsi_mb[iset][iarm] = njpsi/nevent;

			cout << iset << " " << iarm << " " << njpsi << " " << nevent << " " << rjpsi_mb[iset][iarm] << endl;

			hr2svx[iset][iarm] = (TH1D*)hrsvx[iset][iarm]->Clone(Form("hr2svx_%d_%d",iset,iarm));
			hr2fvtxs1030[iset][iarm] = (TH1D*)hrfvtxs1030[iset][iarm]->Clone(Form("hr2fvtxs1030_%d_%d",iset,iarm));
			hr2fvtxs1226[iset][iarm] = (TH1D*)hrfvtxs1226[iset][iarm]->Clone(Form("hr2fvtxs1226_%d_%d",iset,iarm));
			hr2fvtxn1030[iset][iarm] = (TH1D*)hrfvtxn1030[iset][iarm]->Clone(Form("hr2fvtxn1030_%d_%d",iset,iarm));
			hr2fvtxn1226[iset][iarm] = (TH1D*)hrfvtxn1226[iset][iarm]->Clone(Form("hr2fvtxn1226_%d_%d",iset,iarm));
			hr2fvtxs1030_mu[iset][iarm] = (TH1D*)hrfvtxs1030_mu[iset][iarm]->Clone(Form("hr2fvtxs1030_mu_%d_%d",iset,iarm));
			hr2fvtxs1226_mu[iset][iarm] = (TH1D*)hrfvtxs1226_mu[iset][iarm]->Clone(Form("hr2fvtxs1226_mu_%d_%d",iset,iarm));
			hr2fvtxn1030_mu[iset][iarm] = (TH1D*)hrfvtxn1030_mu[iset][iarm]->Clone(Form("hr2fvtxn1030_mu_%d_%d",iset,iarm));
			hr2fvtxn1226_mu[iset][iarm] = (TH1D*)hrfvtxn1226_mu[iset][iarm]->Clone(Form("hr2fvtxn1226_mu_%d_%d",iset,iarm));

			hr2svx_scaled[iset][iarm] = (TH1D*)hrsvx_scaled[iset][iarm]->Clone(Form("hr2svx_scaled_%d_%d",iset,iarm));
			hr2fvtxs1030_scaled[iset][iarm] = (TH1D*)hrfvtxs1030_scaled[iset][iarm]->Clone(Form("hr2fvtxs1030_scaled_%d_%d",iset,iarm));
			hr2fvtxs1226_scaled[iset][iarm] = (TH1D*)hrfvtxs1226_scaled[iset][iarm]->Clone(Form("hr2fvtxs1226_scaled_%d_%d",iset,iarm));
			hr2fvtxn1030_scaled[iset][iarm] = (TH1D*)hrfvtxn1030_scaled[iset][iarm]->Clone(Form("hr2fvtxn1030_scaled_%d_%d",iset,iarm));
			hr2fvtxn1226_scaled[iset][iarm] = (TH1D*)hrfvtxn1226_scaled[iset][iarm]->Clone(Form("hr2fvtxn1226_scaled_%d_%d",iset,iarm));
			hr2fvtxs1030_mu_scaled[iset][iarm] = (TH1D*)hrfvtxs1030_mu_scaled[iset][iarm]->Clone(Form("hr2fvtxs1030_mu_scaled_%d_%d",iset,iarm));
			hr2fvtxs1226_mu_scaled[iset][iarm] = (TH1D*)hrfvtxs1226_mu_scaled[iset][iarm]->Clone(Form("hr2fvtxs1226_mu_scaled_%d_%d",iset,iarm));
			hr2fvtxn1030_mu_scaled[iset][iarm] = (TH1D*)hrfvtxn1030_mu_scaled[iset][iarm]->Clone(Form("hr2fvtxn1030_mu_scaled_%d_%d",iset,iarm));
			hr2fvtxn1226_mu_scaled[iset][iarm] = (TH1D*)hrfvtxn1226_mu_scaled[iset][iarm]->Clone(Form("hr2fvtxn1226_mu_scaled_%d_%d",iset,iarm));

			hr2svx[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxs1030[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxs1226[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxn1030[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxn1226[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxs1030_mu[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxs1226_mu[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxn1030_mu[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxn1226_mu[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);

			hr2svx_scaled[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxs1030_scaled[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxs1226_scaled[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxn1030_scaled[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxn1226_scaled[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxs1030_mu_scaled[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxs1226_mu_scaled[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxn1030_mu_scaled[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);
			hr2fvtxn1226_mu_scaled[iset][iarm]->Scale(1./rjpsi_mb[iset][iarm]);

			heta_pt_jpsi[iset][iarm] = (TH2D*)infile[iset]->Get(Form("heta_pt_jpsi_%d",iarm));
			heta_jpsi[iset][iarm] = (TH1D*)heta_pt_jpsi[iset][iarm]->ProjectionX(Form("heta_jpsi_%d_%d",iset,iarm));
			heta_jpsi[iset][iarm]->Scale(1./heta_jpsi[iset][iarm]->GetBinWidth(1));
			heta_jpsi[iset][iarm]->Scale(1./hnsvx[iset][iarm]->Integral());

		}//iarm
	}//iset

	for (int iset=0; iset<nset; iset++){
		//for (int iset=0; iset<4; iset++){

		//style
		hnfvtxs1030_mb[iset]->SetLineColor(2);
		hnfvtxs1030_mb[iset]->SetLineWidth(2);
		hnfvtxs1226_mb[iset]->SetLineColor(2);
		hnfvtxs1226_mb[iset]->SetLineStyle(2);
		hnfvtxs1226_mb[iset]->SetLineWidth(2);

		hnfvtxn1030_mb[iset]->SetLineColor(4);
		hnfvtxn1030_mb[iset]->SetLineWidth(2);
		hnfvtxn1226_mb[iset]->SetLineColor(4);
		hnfvtxn1226_mb[iset]->SetLineStyle(2);
		hnfvtxn1226_mb[iset]->SetLineWidth(2);

		hnsvx_mb[iset]->SetLineColor(1);
		hnsvx_mb[iset]->SetLineWidth(2);

		hnsvx_mb_scaled[iset]->SetLineColor(1);
		hnsvx_mb_scaled[iset]->SetLineWidth(2);

		hnfvtxs1030_mb_scaled[iset]->SetLineColor(2);
		hnfvtxs1030_mb_scaled[iset]->SetLineWidth(2);
		hnfvtxs1226_mb_scaled[iset]->SetLineColor(2);
		hnfvtxs1226_mb_scaled[iset]->SetLineStyle(2);
		hnfvtxs1226_mb_scaled[iset]->SetLineWidth(2);

		hnfvtxn1030_mb_scaled[iset]->SetLineColor(4);
		hnfvtxn1030_mb_scaled[iset]->SetLineWidth(2);
		hnfvtxn1226_mb_scaled[iset]->SetLineColor(4);
		hnfvtxn1226_mb_scaled[iset]->SetLineStyle(2);
		hnfvtxn1226_mb_scaled[iset]->SetLineWidth(2);

		hnsvx[iset][0]->SetLineColor(1);
		hnsvx[iset][0]->SetLineWidth(2);

		hnfvtxs1030[iset][0]->SetLineColor(2);
		hnfvtxs1030[iset][0]->SetLineWidth(2);
		hnfvtxs1226[iset][0]->SetLineColor(2);
		hnfvtxs1226[iset][0]->SetLineStyle(2);
		hnfvtxs1226[iset][0]->SetLineWidth(2);

		hnfvtxn1030[iset][0]->SetLineColor(4);
		hnfvtxn1030[iset][0]->SetLineWidth(2);
		hnfvtxn1226[iset][0]->SetLineColor(4);
		hnfvtxn1226[iset][0]->SetLineStyle(2);
		hnfvtxn1226[iset][0]->SetLineWidth(2);

		hnfvtxs1030_mu[iset][0]->SetLineColor(8);
		hnfvtxs1030_mu[iset][0]->SetLineWidth(2);
		hnfvtxs1226_mu[iset][0]->SetLineColor(8);
		hnfvtxs1226_mu[iset][0]->SetLineStyle(2);
		hnfvtxs1226_mu[iset][0]->SetLineWidth(2);

		hnfvtxn1030_mu[iset][0]->SetLineColor(6);
		hnfvtxn1030_mu[iset][0]->SetLineWidth(2);
		hnfvtxn1226_mu[iset][0]->SetLineColor(6);
		hnfvtxn1226_mu[iset][0]->SetLineStyle(2);
		hnfvtxn1226_mu[iset][0]->SetLineWidth(2);

		hrsvx[iset][0]->SetLineColor(1);
		hrsvx[iset][0]->SetLineWidth(2);

		hrfvtxs1030[iset][0]->SetLineColor(2);
		hrfvtxs1030[iset][0]->SetLineWidth(2);
		hrfvtxs1226[iset][0]->SetLineColor(2);
		hrfvtxs1226[iset][0]->SetLineStyle(2);
		hrfvtxs1226[iset][0]->SetLineWidth(2);

		hrfvtxn1030[iset][0]->SetLineColor(4);
		hrfvtxn1030[iset][0]->SetLineWidth(2);
		hrfvtxn1226[iset][0]->SetLineColor(4);
		hrfvtxn1226[iset][0]->SetLineStyle(2);
		hrfvtxn1226[iset][0]->SetLineWidth(2);

		hrfvtxs1030_mu[iset][0]->SetLineColor(8);
		hrfvtxs1030_mu[iset][0]->SetLineWidth(2);
		hrfvtxs1226_mu[iset][0]->SetLineColor(8);
		hrfvtxs1226_mu[iset][0]->SetLineStyle(2);
		hrfvtxs1226_mu[iset][0]->SetLineWidth(2);

		hrfvtxn1030_mu[iset][0]->SetLineColor(6);
		hrfvtxn1030_mu[iset][0]->SetLineWidth(2);
		hrfvtxn1226_mu[iset][0]->SetLineColor(6);
		hrfvtxn1226_mu[iset][0]->SetLineStyle(2);
		hrfvtxn1226_mu[iset][0]->SetLineWidth(2);

		hrsvx_scaled[iset][0]->SetLineColor(1);
		hrsvx_scaled[iset][0]->SetLineWidth(2);

		hrfvtxs1030_scaled[iset][0]->SetLineColor(2);
		hrfvtxs1030_scaled[iset][0]->SetLineWidth(2);
		hrfvtxs1226_scaled[iset][0]->SetLineColor(2);
		hrfvtxs1226_scaled[iset][0]->SetLineStyle(2);
		hrfvtxs1226_scaled[iset][0]->SetLineWidth(2);

		hrfvtxn1030_scaled[iset][0]->SetLineColor(4);
		hrfvtxn1030_scaled[iset][0]->SetLineWidth(2);
		hrfvtxn1226_scaled[iset][0]->SetLineColor(4);
		hrfvtxn1226_scaled[iset][0]->SetLineStyle(2);
		hrfvtxn1226_scaled[iset][0]->SetLineWidth(2);

		hrfvtxs1030_mu_scaled[iset][0]->SetLineColor(8);
		hrfvtxs1030_mu_scaled[iset][0]->SetLineWidth(2);
		hrfvtxs1226_mu_scaled[iset][0]->SetLineColor(8);
		hrfvtxs1226_mu_scaled[iset][0]->SetLineStyle(2);
		hrfvtxs1226_mu_scaled[iset][0]->SetLineWidth(2);

		hrfvtxn1030_mu_scaled[iset][0]->SetLineColor(6);
		hrfvtxn1030_mu_scaled[iset][0]->SetLineWidth(2);
		hrfvtxn1226_mu_scaled[iset][0]->SetLineColor(6);
		hrfvtxn1226_mu_scaled[iset][0]->SetLineStyle(2);
		hrfvtxn1226_mu_scaled[iset][0]->SetLineWidth(2);

		hr2svx[iset][0]->SetLineColor(1);
		hr2svx[iset][0]->SetLineWidth(2);

		hr2fvtxs1030[iset][0]->SetLineColor(2);
		hr2fvtxs1030[iset][0]->SetLineWidth(2);
		hr2fvtxs1226[iset][0]->SetLineColor(2);
		hr2fvtxs1226[iset][0]->SetLineStyle(2);
		hr2fvtxs1226[iset][0]->SetLineWidth(2);

		hr2fvtxn1030[iset][0]->SetLineColor(4);
		hr2fvtxn1030[iset][0]->SetLineWidth(2);
		hr2fvtxn1226[iset][0]->SetLineColor(4);
		hr2fvtxn1226[iset][0]->SetLineStyle(2);
		hr2fvtxn1226[iset][0]->SetLineWidth(2);

		hr2fvtxs1030_mu[iset][0]->SetLineColor(8);
		hr2fvtxs1030_mu[iset][0]->SetLineWidth(2);
		hr2fvtxs1226_mu[iset][0]->SetLineColor(8);
		hr2fvtxs1226_mu[iset][0]->SetLineStyle(2);
		hr2fvtxs1226_mu[iset][0]->SetLineWidth(2);

		hr2fvtxn1030_mu[iset][0]->SetLineColor(6);
		hr2fvtxn1030_mu[iset][0]->SetLineWidth(2);
		hr2fvtxn1226_mu[iset][0]->SetLineColor(6);
		hr2fvtxn1226_mu[iset][0]->SetLineStyle(2);
		hr2fvtxn1226_mu[iset][0]->SetLineWidth(2);

		hr2svx_scaled[iset][0]->SetLineColor(1);
		hr2svx_scaled[iset][0]->SetLineWidth(2);

		hr2fvtxs1030_scaled[iset][0]->SetLineColor(2);
		hr2fvtxs1030_scaled[iset][0]->SetLineWidth(2);
		hr2fvtxs1226_scaled[iset][0]->SetLineColor(2);
		hr2fvtxs1226_scaled[iset][0]->SetLineStyle(2);
		hr2fvtxs1226_scaled[iset][0]->SetLineWidth(2);

		hr2fvtxn1030_scaled[iset][0]->SetLineColor(4);
		hr2fvtxn1030_scaled[iset][0]->SetLineWidth(2);
		hr2fvtxn1226_scaled[iset][0]->SetLineColor(4);
		hr2fvtxn1226_scaled[iset][0]->SetLineStyle(2);
		hr2fvtxn1226_scaled[iset][0]->SetLineWidth(2);

		hr2fvtxs1030_mu_scaled[iset][0]->SetLineColor(8);
		hr2fvtxs1030_mu_scaled[iset][0]->SetLineWidth(2);
		hr2fvtxs1226_mu_scaled[iset][0]->SetLineColor(8);
		hr2fvtxs1226_mu_scaled[iset][0]->SetLineStyle(2);
		hr2fvtxs1226_mu_scaled[iset][0]->SetLineWidth(2);

		hr2fvtxn1030_mu_scaled[iset][0]->SetLineColor(6);
		hr2fvtxn1030_mu_scaled[iset][0]->SetLineWidth(2);
		hr2fvtxn1226_mu_scaled[iset][0]->SetLineColor(6);
		hr2fvtxn1226_mu_scaled[iset][0]->SetLineStyle(2);
		hr2fvtxn1226_mu_scaled[iset][0]->SetLineWidth(2);
	}


	TGraphErrors *gr2svx_scaled[nset][narm];
	TGraphErrors *gr2fvtxs_scaled[nset][narm];
	TGraphErrors *gr2fvtxn_scaled[nset][narm];
	TGraphErrors *gr2fvtxn_mu_scaled[nset][narm];

	for (int iset=0; iset<nset; iset++){
		for (int iarm=0; iarm<narm; iarm++){
			gr2svx_scaled[iset][iarm] = new TGraphErrors;
			gr2fvtxs_scaled[iset][iarm] = new TGraphErrors;
			gr2fvtxn_scaled[iset][iarm] = new TGraphErrors;
			gr2fvtxn_mu_scaled[iset][iarm] = new TGraphErrors;

			gr2svx_scaled[iset][iarm]->SetLineStyle(1);
			gr2svx_scaled[iset][iarm]->SetLineWidth(4);
			gr2svx_scaled[iset][iarm]->SetLineColorAlpha(1,0.3);
			gr2svx_scaled[iset][iarm]->SetFillColorAlpha(1,0.3);

			gr2fvtxs_scaled[iset][iarm]->SetLineStyle(1);
			gr2fvtxs_scaled[iset][iarm]->SetLineWidth(4);
			gr2fvtxs_scaled[iset][iarm]->SetLineColorAlpha(4,0.3);
			gr2fvtxs_scaled[iset][iarm]->SetFillColorAlpha(4,0.3);

			gr2fvtxn_scaled[iset][iarm]->SetLineStyle(1);
			gr2fvtxn_scaled[iset][iarm]->SetLineWidth(4);
			gr2fvtxn_scaled[iset][iarm]->SetLineColorAlpha(2,0.3);
			gr2fvtxn_scaled[iset][iarm]->SetFillColorAlpha(2,0.3);

			gr2fvtxn_scaled[iset][iarm]->SetLineColorAlpha(6,0.3);
			gr2fvtxn_scaled[iset][iarm]->SetFillColorAlpha(6,0.3);


			gr2fvtxn_mu_scaled[iset][iarm]->SetLineStyle(1);
			gr2fvtxn_mu_scaled[iset][iarm]->SetLineWidth(4);
			gr2fvtxn_mu_scaled[iset][iarm]->SetLineColorAlpha(6,0.3);
			gr2fvtxn_mu_scaled[iset][iarm]->SetFillColorAlpha(6,0.3);


			gr2fvtxn_mu_scaled[iset][iarm]->SetLineColorAlpha(2,0.3);
			gr2fvtxn_mu_scaled[iset][iarm]->SetFillColorAlpha(2,0.3);



			for (int ii=0; ii<hr2svx_scaled[iset][iarm]->GetNbinsX(); ii++){

				float xx = hr2svx_scaled[iset][iarm]->GetBinCenter(ii+1);

				if ( xx>5.5 ) continue;

				float yy = hr2svx_scaled[iset][iarm]->GetBinContent(ii+1);
				float yy_err = hr2svx_scaled[iset][iarm]->GetBinError(ii+1);
				gr2svx_scaled[iset][iarm]->SetPoint(ii, xx, yy);
				gr2svx_scaled[iset][iarm]->SetPointError(ii, 0, yy_err);

				yy = hr2fvtxs1226_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hr2fvtxs1226_scaled[iset][iarm]->GetBinError(ii+1);
				gr2fvtxs_scaled[iset][iarm]->SetPoint(ii, xx, yy);
				gr2fvtxs_scaled[iset][iarm]->SetPointError(ii, 0, yy_err);

				yy = hr2fvtxn1226_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hr2fvtxn1226_scaled[iset][iarm]->GetBinError(ii+1);
				gr2fvtxn_scaled[iset][iarm]->SetPoint(ii, xx, yy);
				gr2fvtxn_scaled[iset][iarm]->SetPointError(ii, 0, yy_err);

				yy = hr2fvtxn1226_mu_scaled[iset][iarm]->GetBinContent(ii+1);
				yy_err = hr2fvtxn1226_mu_scaled[iset][iarm]->GetBinError(ii+1);
				gr2fvtxn_mu_scaled[iset][iarm]->SetPoint(ii, xx, yy);
				gr2fvtxn_mu_scaled[iset][iarm]->SetPointError(ii, 0, yy_err);

			}//ii

		}//iarm
	}//iset
	 //


	/*
	   float phenix_xx[10] = {0.295, 0.885, 1.46, 2.05, 2.63, 3.22, 4.10, 5.27, 6.43, 9.05};
	   float phenix_yy[10] = {0.403, 0.452, 0.974, 1.85, 2.96, 4.36, 5.76, 8.51, 8.32, 14.8};
	   float phenix_yy_err[10] = {0.427, 0.499, 1.02, 2.04, 3.27, 4.86, 6.59, 9.98, 10.1, 17.9};

	   float phenix_yy2[10] = {0.734, 0.902, 1.21, 1.47, 1.92, 2.37, 2.47, 2.05, 1.48, 3.88};
	   float phenix_yy2_err[10] = {0.829, 0.996, 1.35, 1.64, 2.11, 2.66, 2.80, 2.40, 1.77, 4.68};

	   TGraphErrors *gphenix1 = new TGraphErrors;
	   TGraphErrors *gphenix2 = new TGraphErrors;

	   for (int ii=0; ii<10; ii++){
	   gphenix1->SetPoint(ii, phenix_xx[ii], phenix_yy[ii]);
	   gphenix1->SetPointError(ii, 0.1, phenix_yy_err[ii]-phenix_yy[ii]);

	   gphenix2->SetPoint(ii, phenix_xx[ii], phenix_yy2[ii]);
	   gphenix2->SetPointError(ii, 0.1, phenix_yy2_err[ii]-phenix_yy2[ii]);
	   }
	   */

	//	TString infile1 = "/sphenix/user/zshi/PHENIX/FinalStyleMacros/MakeFinalPlots/UnCorr/SaveFiles/RefAll_0.root";
	//	TString infile2 = "/sphenix/user/zshi/PHENIX/FinalStyleMacros/MakeFinalPlots/Corr/SaveFiles/RefAll_0.root";

	TString infile1 = "/Users/zhaozhongshi/Desktop/TempDownload/PHENIXFinal/FinalVersion/Fig1/SameUnCorr.root";
	TString infile2 = "/Users/zhaozhongshi/Desktop/TempDownload/PHENIXFinal/FinalVersion/Fig1/SameCorr.root";


	TFile * fin1 = new TFile(infile1.Data());
	TFile * fin2 = new TFile(infile2.Data());


	TGraphErrors *gphenix1 = (TGraphErrors *) fin1->Get("Inclusive");
	TGraphErrors * PHENIXSystError1 = (TGraphErrors *) fin1->Get("InclusiveSyst");

	TGraphErrors *gphenix2 = (TGraphErrors *) fin2->Get("Inclusive");
	TGraphErrors * PHENIXSystError2 = (TGraphErrors *) fin2->Get("InclusiveSyst");



//	gphenix1->SetMarkerStyle(24);
	gphenix1->SetMarkerStyle(47);
	
	gphenix1->SetMarkerColor(6);
	gphenix1->SetFillStyle(0);
	gphenix1->SetLineColor(6);

	gphenix1->SetMarkerColor(2);
	gphenix1->SetLineColor(2);



	PHENIXSystError1->SetFillColorAlpha(kMagenta-9,0.5);
	PHENIXSystError1->SetLineColor(kMagenta-9);


	PHENIXSystError1->SetFillColorAlpha(kRed-9,0.5);
	PHENIXSystError1->SetLineColor(kRed-9);


	gphenix2->SetMarkerStyle(24);
	gphenix2->SetMarkerColor(2);
	gphenix2->SetFillStyle(0);
	gphenix2->SetLineColor(2);


	gphenix2->SetMarkerColor(6);
	gphenix2->SetLineColor(6);

	PHENIXSystError2->SetFillColorAlpha(kRed-9,0.5);
	PHENIXSystError2->SetFillColorAlpha(kRed-9,0.5);

	PHENIXSystError2->SetFillColorAlpha(kMagenta-9,0.5);
	PHENIXSystError2->SetLineColor(kMagenta-9);

	TCanvas *c5a = new TCanvas("c5a","c5a",1.2*2*500,1*500);
	c5a->Divide(2,1);

	for (int iset=2; iset<4; iset++){
		c5a->cd(iset-2+1);
		SetPadStyle();
		gPad->SetTicks();
			
		htmp = (TH1D*)gPad->DrawFrame(0,0,5.5,12);
		SetHistoStyle("N_{ch} / #LTN_{ch}#GT","dN_{J/#psi}/dy / #LTdN_{J/#psi}/dy#GT","",24,20);
		htmp->GetXaxis()->SetTitleOffset(1.0);
		htmp->GetYaxis()->SetTitleOffset(1.25);

		htmp->GetXaxis()->CenterTitle();
		htmp->GetYaxis()->CenterTitle();




		gphenix1->Draw("ep");
		PHENIXSystError1->Draw("5SAME");
		gphenix2->Draw("epSAME");
		PHENIXSystError2->Draw("5SAME");

		gr2svx_scaled[iset][1]->Draw("L3");
		gr2fvtxs_scaled[iset][1]->Draw("L3");
		gr2fvtxn_scaled[iset][1]->Draw("L3");
		gr2fvtxn_mu_scaled[iset][1]->Draw("L3");

		TLegend *leg = new TLegend(0.16,0.93-0.048*12,0.6,0.93);
		leg->SetFillStyle(0);
		leg->SetBorderSize(0);
		leg->SetTextSize(0.04);
		leg->AddEntry("","PYTHIA8 pp 200 GeV","h");
		leg->AddEntry("",Form("%s Tune",setname[iset].c_str()),"h");
		leg->AddEntry("","J/#psi, 1.2<|y|<2.2","h");
		leg->AddEntry(gr2svx_scaled[iset][1],"N_{ch}: -1<#eta<1","LF");
		leg->AddEntry(gr2fvtxs_scaled[iset][1],"N_{ch}: -2.6<|#eta|<-1.2","LF");
		leg->AddEntry("","N_{ch}: 1.2<#eta<2.6","");
		leg->AddEntry(gr2fvtxn_mu_scaled[iset][1],"muon unsubtracted","LF");
		leg->AddEntry(gr2fvtxn_scaled[iset][1],"muon subtracted","LF");
		leg->AddEntry("","","");
		leg->AddEntry("","PHENIX Data","h");
		leg->AddEntry(gphenix1,"muon unsubtracted","PF");
		leg->AddEntry(gphenix2,"muon subtracted","PF");
		leg->Draw();
	}

	TCanvas *c5b = new TCanvas("c5b","c5b",1.2*2*500,1*500);
	c5b->Divide(2,1);

	for (int iset=6; iset<8; iset++){
		c5b->cd(iset-6+1);
		SetPadStyle();
		gPad->SetTicks();

		htmp = (TH1D*)gPad->DrawFrame(0,0,5.5,12);
	//	SetHistoStyle("N_{J/#psi}/#LTdN_{J/#psi}/dy#GT","",24,20);
		htmp->GetXaxis()->SetTitleOffset(1.0);
		htmp->GetYaxis()->SetTitleOffset(1.25);

		htmp->GetXaxis()->CenterTitle();
		htmp->GetYaxis()->CenterTitle();

		gphenix1->SetMarkerStyle(20);
		gphenix1->Draw("ep");
		PHENIXSystError1->Draw("5SAME");
		gphenix2->Draw("epSAME");
		PHENIXSystError2->Draw("5SAME");

		gr2svx_scaled[iset][1]->Draw("L3");
		gr2fvtxs_scaled[iset][1]->Draw("L3");
		gr2fvtxn_scaled[iset][1]->Draw("L3");
		gr2fvtxn_mu_scaled[iset][1]->Draw("L3");

		TLegend *leg = new TLegend(0.16,0.93-0.048*12,0.6,0.93);
		leg->SetFillStyle(0);
		leg->SetBorderSize(0);
		leg->SetTextSize(0.04);
		leg->AddEntry("","PYTHIA8 pp 200 GeV","h");
		leg->AddEntry("",Form("%s Tune w/o MPI",setname[iset].c_str()),"h");
		leg->AddEntry("","J/#psi, 1.2<|y|<2.2","h");
		leg->AddEntry(gr2svx_scaled[iset][1],"N_{ch}: -1<#eta<1","LF");
		leg->AddEntry(gr2fvtxs_scaled[iset][1],"N_{ch}: -2.6<#eta<-1.2","LF");
		leg->AddEntry("","N_{ch}: 1.2<|#eta|<2.6","");
		leg->AddEntry(gr2fvtxn_mu_scaled[iset][1],"muon unsubtracted","LF");
		leg->AddEntry(gr2fvtxn_scaled[iset][1],"muon subtracted","LF");
		leg->AddEntry("","","");
		leg->AddEntry("","PHENIX Data","h");
		leg->AddEntry(gphenix1,"muon unsubtracted","PF");
		leg->AddEntry(gphenix2,"muon subtracted","PF");
		leg->Draw();
	}
	c5a->SaveAs("JpsiPYTHIA1.png"); 
	c5b->SaveAs("JpsiPYTHIA2.png"); 


	//	TCanvas *c5c = new TCanvas("c5c","c5c",1.2*2*500,1*500);
	//c5c->Divide(2,1);

	const int NSet=2;

	int SetNum[NSet]={7,3};
	TString MPINote[NSet] = {"Without MPI","With MPI"};



	TLatex *lat = new TLatex();
	lat->SetNDC();
	lat->SetTextSize(0.05);

	TCanvas *c5c = new TCanvas("c5c","c5c",600,600);

	c5c->cd();
	TPad *pad[2];

	pad[0] = new TPad("pad1","left pad",0.0,0.0,1.0,1.0);
	pad[0]->SetTopMargin(0.04);
	pad[0]->SetBottomMargin(0.14);
	pad[0]->SetRightMargin(0.06);
	pad[0]->SetLeftMargin(0.15);
	pad[0]->Draw();

/*


	pad[1] = new TPad("pad2","right pad",0.52,0.0,0.99,1.0);
	pad[1]->SetTopMargin(0.04);
	pad[1]->SetBottomMargin(0.14);
	pad[1]->SetRightMargin(0.02);
	pad[1]->SetLeftMargin(0.0);
	pad[1]->Draw();
*/
	c5c->cd();

	for (int q=0; q<NSet-1; q++){
		int iset = SetNum[q];
		int iset2 = SetNum[q+1];
		
		//c5c->cd(q+1);
	//	SetPadStyle();
	//	gPad->SetTicks();
		pad[0]->cd();
	//	htmp = (TH1D*)gPad->DrawFrame(0+0.001*q,0,5.5,12);
	//	SetHistoStyle("N_{ch} / #LTN_{ch}#GT","dN_{J/#psi}/dy / #LTdN_{J/#psi}/dy#GT","",24,20);
	
	
		 
		htmp = (TH1D*)gPad->DrawFrame(0+0.001*q,0,5.5,20);
		htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_{ch}#GT");
		htmp->GetXaxis()->SetLabelSize(0.05);
		htmp->GetXaxis()->SetTitleSize(0.06);
		htmp->GetXaxis()->SetNdivisions(9,4,0);
		htmp->GetXaxis()->SetTitleOffset(1.0);
		htmp->GetXaxis()->SetTitleOffset(1.0);
	
		if(q==0){
			//htmp->GetYaxis()->SetTitle("(N_{#psi(2S)}/N_{J/#psi}) #scale[1.5]{/} #LTN_{#psi(2S)}/N_{J/#psi}#GT");	
//			htmp->GetXaxis()->SetTitle("N_{ch} / #LTN_N_{J/#psi}#GT");
			htmp->GetYaxis()->SetTitle("N_{J/#psi} #scale[1.5]{/} #LTN_{J/#psi}#GT");	

			htmp->GetYaxis()->SetLabelSize(0.05);
			htmp->GetYaxis()->SetTitleSize(0.06);
			htmp->GetYaxis()->SetTitleOffset(1.1);
		}




		htmp->GetXaxis()->CenterTitle();
		htmp->GetYaxis()->CenterTitle();

		gphenix1->Draw("ep");
		PHENIXSystError1->Draw("5SAME");
		gphenix2->SetMarkerStyle(47);
		
		gphenix2->Draw("epSAME");
		PHENIXSystError2->Draw("5SAME");

//		gr2svx_scaled[iset][1]->Draw("L3");
//		gr2fvtxs_scaled[iset][1]->Draw("L3");
		gr2fvtxn_scaled[iset][1]->SetLineStyle(2);		
		gr2fvtxn_scaled[iset][1]->Draw("L3");
		gr2fvtxn_scaled[iset2][1]->Draw("L3");
	
		gr2fvtxn_mu_scaled[iset][1]->SetLineStyle(2);		
		gr2fvtxn_mu_scaled[iset][1]->Draw("L3");
		gr2fvtxn_mu_scaled[iset2][1]->Draw("L3");
		
	//	gr2fvtxn_mu_scaled[iset][1]->Draw("L3");

		if(q==0){

			TLegend *leg = new TLegend(0.22,0.75,0.52,0.95);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(0.04);
	//		leg->AddEntry("","PYTHIA8 pp 200 GeV","h");
	//		leg->AddEntry("",Form("%s Tune",setname[iset].c_str()),"h");
			leg->AddEntry("","N_{J/#psi}, 1.2<|y|<2.2","h");
			leg->AddEntry("","N_{ch}: 1.2<|#eta|<2.6","h");

//			leg->AddEntry(gr2svx_scaled[iset][1],"N_{ch}: -1<#eta<1","LF");
//			leg->AddEntry(gr2fvtxs_scaled[iset][1],"N_{ch}: -2.6<#eta<-1.2","LF");
		
			TLegend *leg2 = new TLegend(0.57,0.75,0.98,0.95);
			leg2->SetFillStyle(0);
			leg2->SetBorderSize(0);
			leg2->SetTextSize(0.04);
			leg2->AddEntry("","PYTHIA8 (Detroit) pp","h");
			leg2->AddEntry("","#sqrt{s} = 200 GeV","h");			
		//	leg2->AddEntry("",Form("%s Tune",setname[iset].c_str()),"h");

	//		leg->AddEntry("","","");




			leg->Draw();
			leg2->Draw("SAME");

/*		
			TLegend *leg2 = new TLegend(0.38,0.70,0.82,0.92);
			leg2->SetFillStyle(0);
			leg2->SetBorderSize(0);
			leg2->SetTextSize(0.04);

			leg2->AddEntry("","PHENIX Data","h");
			leg2->AddEntry(gphenix1,"muon unsubtracted","PF");
			leg2->AddEntry(gphenix2,"muon subtracted","PF");
			leg2->Draw();
*/
		}


		TLegend *legMain = new TLegend(0.18,0.43,0.42,0.75);
		legMain->SetFillStyle(0);
		legMain->SetBorderSize(0);
		legMain->SetTextSize(0.04);

		legMain->AddEntry("","","h");
		legMain->AddEntry("","PHENIX Data","h");
		legMain->AddEntry("","With MPI","h");		
		legMain->AddEntry("","Without MPI","h");
		legMain->Draw();
	

		gphenix1->SetTitle("");
		gphenix2->SetTitle("");



		TLegend *legMu = new TLegend(0.28,0.43,0.45,0.75);
		legMu->SetFillStyle(0);
		legMu->SetBorderSize(0);
		legMu->SetTextSize(0.04);

		legMu->AddEntry("","muon unsubtracted","h");
		legMu->AddEntry("","","h");
		legMu->AddEntry("","","h");
		legMu->AddEntry("","","h");
		
		legMu->Draw();


		TLegend *legBefore = new TLegend(0.45,0.43,0.62,0.75);
		legBefore->SetFillStyle(0);
		legBefore->SetBorderSize(0);
		legBefore->SetTextSize(0.04);

		legBefore->AddEntry("","","h");
		legBefore->AddEntry(gphenix1,"","LP");
		legBefore->AddEntry(gr2fvtxn_mu_scaled[iset2][1],"","LF");		
		legBefore->AddEntry(gr2fvtxn_mu_scaled[iset][1],"","LF");
		legBefore->Draw();


		TLegend *legMu2 = new TLegend(0.63,0.43,1.0,0.75);
		legMu2->SetFillStyle(0);
		legMu2->SetBorderSize(0);
		legMu2->SetTextSize(0.04);

		legMu2->AddEntry("","muon subtracted","h");
		legMu2->AddEntry("","","h");
		legMu2->AddEntry("","","h");
		legMu2->AddEntry("","","h");
	
		legMu2->Draw();


		TLegend *legAfter = new TLegend(0.73,0.43,0.90,0.75);
		legAfter->SetFillStyle(0);
		legAfter->SetBorderSize(0);
		legAfter->SetTextSize(0.04);

		legAfter->AddEntry("","","h");
		legAfter->AddEntry(gphenix2,"","LP");
		legAfter->AddEntry(gr2fvtxn_scaled[iset2][1],"","LF");		
		legAfter->AddEntry(gr2fvtxn_scaled[iset][1],"","LF");
		legAfter->Draw();



	//	lat->DrawLatex(0.65,0.82,MPINote[q].Data());


		c5c->Update();

	}

	//	c5c->SaveAs("JpsiPYTHIA.png"); 

	c5c->SaveAs("JpsiPYTHIANew.png"); 
	c5c->SaveAs("JpsiPYTHIANew.pdf"); 

	return;

	TFile *outfile = new TFile("outfile_PHENIX_PYTHIA.root","recreate");
	for (int iset=2; iset<4; iset++){
		gr2svx_scaled[iset][1]->Write(Form("g%s_SVX",setname[iset].c_str()));
		gr2fvtxs_scaled[iset][1]->Write(Form("g%s_FVTXS",setname[iset].c_str()));
		gr2fvtxn_mu_scaled[iset][1]->Write(Form("g%s_FVTXN",setname[iset].c_str()));
		gr2fvtxn_scaled[iset][1]->Write(Form("g%s_FVTXN_sub",setname[iset].c_str()));
	}

	for (int iset=6; iset<8; iset++){
		gr2svx_scaled[iset][1]->Write(Form("g%s_woMPI_SVX",setname[iset].c_str()));
		gr2fvtxs_scaled[iset][1]->Write(Form("g%s_woMPI_FVTXS",setname[iset].c_str()));
		gr2fvtxn_mu_scaled[iset][1]->Write(Form("g%s_woMPI_FVTXN",setname[iset].c_str()));
		gr2fvtxn_scaled[iset][1]->Write(Form("g%s_woMPI_FVTXN_sub",setname[iset].c_str()));
	}

	return;

	}
