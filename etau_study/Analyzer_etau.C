////Analyzer_etau.C
//For use with Ntuples made from ggNtuplizer
//Required arguments: 1 is folder containing input files, 2 is output file path, 3 is maxEvents (-1 to run over all events), 4 is reportEvery
//
//To compile using rootcom to an executable named 'analyze':
//$ ./rootcom Analyzer_etau analyze
//
//To run, assuming this is compiled to an executable named 'analyze':
//$ ./analyze /hdfs/store/user/jmadhusu/LatestNtuples/ /afs/hep.wisc.edu/user/ms/CMSSW_9_4_4/src/2017_analysis/etau/output.root -1 10000
//./analyze /hdfs/store/user/jmadhusu/MonoHiggs_MC2017/ZZZ_TuneCP5_13TeV-amcatnlo-pythia8/crab_ZZZ/180603_185329/0000/ /afs/hep.wisc.edu/user/ms/CMSSW_9_4_4/src/2017_analysis/analyzer/output.root -1 10000
//Runs over every event in the folder LatestNtuples, reporting progress every 10000 events
//and storing the resulting histograms in the file output.root.
//
//To plot, for example, single photon trigger efficiency as a function of photon pt:
//$ root -l
//root[0] TFile *f = new TFile("output.root");
//root[1] TGraphAsymmErrors *efficiency = new TGraphAsymmErrors((TH1F*)f->Get("Photon_Et_300_2"),(TH1F*)f->Get("Photon_Et_300_1"));
//root[2] efficiency->Draw("AP")
//root[3] efficiency->SetTitle("Single photon trigger efficiency")
//root[4] efficiency->GetXaxis()->SetTitle("Photon p_{T}")
//root[5] efficiency->Draw("AP")
//
#define Analyzer_etau_cxx
#include "Analyzer_etau.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TH1F.h"
#include <iostream>
#include <bitset>
#include <climits>
#include <cstring>
#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
#include "TStopwatch.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
#include <set>
#include "TMath.h" //M_PI is in TMath
#include "TRandom3.h"
#include <TLorentzVector.h>

using namespace std;
using std::vector;
int main(int argc, const char* argv[])
{

  std::string SampleName = argv[5];

  Long64_t maxEvents = atof(argv[3]);
  if (maxEvents < -1LL)
    {
      std::cout<<"Please enter a valid value for maxEvents (parameter 3)."<<std::endl;
      return 1;
    }
  int reportEvery = atof(argv[4]);
  if (reportEvery < 1)
    {
      std::cout<<"Please enter a valid value for reportEvery (parameter 4) "<<std::endl;
      return 1;
    }
  //std::string SampleName = argv[5];
  Analyzer_etau t(argv[1],argv[2]);
  t.Loop(maxEvents,reportEvery, SampleName);
  return 0;
}

void Analyzer_etau::Loop(Long64_t maxEvents, int reportEvery, string SampleName)
{

   if (fChain == 0) return;
   int nTotal;
   nTotal = 0;
   int report_=0;
   int report_test=0;
   int nInspected;
   nInspected = 0;
   double nInspected_genWeighted;  
   nInspected_genWeighted = 0.0; 
   bool debug=false;  double netWeight = 1.0;
   int nBackupTriggerEvents, nBTMediumEvents, nBTMediumHLTsinglePhoEvents, nEffPhoptden, nEffPhoptnum, nEffMETden, nEffMETnum;
   nBackupTriggerEvents = nBTMediumEvents = nBTMediumHLTsinglePhoEvents = nEffPhoptden = nEffPhoptnum = nEffMETden = nEffMETnum = 0;
   double nHLTPassed,n_eventWeight, nSingleTrgPassed, nGoodMuonPassed, nElectronPtPassed, nGoodTauPassed, nTauPtPassed,numberOfEvents,nMETPassed, nDPhiPassed, nqcdden,nqcdnum, nMETFiltersPassed,nLeptonVetoPassed,nPassedBjetVeto,nNoisyCrystals,nDPhiJetMETPassed, nGoodMuTauPassed,nDeltaRPassed,nPassedThirdLepVeto,nMtPassed,  nPassedHiggsPtcut, nPassedVisibleMasscut, nPassedMETcut, nFinal_afterSelections, nGoodMuonPassed_qcd, nGoodTauPassed_qcd, nGoodMuTauPassed_qcd, nDeltaRPassed_qcd, nPassedThirdLepVeto_qcd,nPassedBjetVeto_qcd, nPassedHiggsPtcut_qcd, nPassedVisibleMasscut_qcd, nPassedMETcut_qcd, nFinal_afterSelections_qcd ,nPasstottrmass, nPassJetsSelection,nL1PrefiringPassed;
   nHLTPassed = n_eventWeight = nSingleTrgPassed = nGoodMuonPassed = nElectronPtPassed = nGoodTauPassed = nTauPtPassed= numberOfEvents = nMETPassed = nDPhiPassed = nqcdden= nqcdnum=nMETFiltersPassed= nLeptonVetoPassed=nPassedBjetVeto=nNoisyCrystals=nDPhiJetMETPassed= nGoodMuTauPassed = nDeltaRPassed= nPassedThirdLepVeto=nMtPassed=nPassedHiggsPtcut=nPassedVisibleMasscut=nPassedMETcut=nFinal_afterSelections=nGoodMuonPassed_qcd=nGoodTauPassed_qcd=nGoodMuTauPassed_qcd=nDeltaRPassed_qcd=nPassedThirdLepVeto_qcd=nPassedBjetVeto_qcd=nPassedHiggsPtcut_qcd=nPassedVisibleMasscut_qcd=nPassedMETcut_qcd=nFinal_afterSelections_qcd=nPasstottrmass= nPassJetsSelection=nL1PrefiringPassed=0;

   std::vector<int> eleCand;   eleCand.clear();
   std::vector<int> tauCand;   tauCand.clear();

   std::vector<int> higgsCand;   higgsCand.clear();
   std::vector<int> eleGenCand;    eleGenCand.clear();
   std::vector<int> muGenCand;     muGenCand.clear(); 
   std::vector<int> tauGenCand;    tauGenCand.clear(); 
   std::vector<int> tauhGenCand;    tauhGenCand.clear();
   std::vector<int> tauNeuGenCand; tauNeuGenCand.clear(); 
   std::vector<int> mother_;       mother_.clear();   
   std::vector<int> daughter_;     daughter_.clear(); 

   TString sample = TString(SampleName);


   int iphi = 41;
   int ieta = 5;

   int nHiggs = 0;
   int nHToMuTau = 0; int found_et = 0; 
   //   TFile *f_kfactors = new TFile("kfactors.root");
   //TH1D *ewkCorrection = (TH1D*)f_kfactors->Get("EWKcorr/W");
   //TH1D *NNLOCorrection = (TH1D*)f_kfactors->Get("WJets_LO/inv_pt");

   //std::cout<<"Pont 1" << endl;
   //bool debug=true;
   Double_t  Pt_Bins[26]={0.0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 450, 500, 600, 800, 1000};

   TH1F* h_nEvents=new TH1F("nEvents", "nEvents", 5, 0, 5);h_nEvents->Sumw2();
   TH1F* h_Hpt_gen=new TH1F("Higgs_pt_gen", "Higgs_pt_gen", 25, Pt_Bins);h_Hpt_gen->Sumw2();
   TH1F* h_Hpt_gen_org=new TH1F("Higgs_pt_gen_org", "Higgs_pt_gen_org", 25, Pt_Bins);h_Hpt_gen_org->Sumw2();

   TH1F* h_dr_gen=new TH1F("dr_gen", "dr_gen", 20, 0, 2.0); h_dr_gen->Sumw2();
   TH1F* h_mu_pt =new TH1F("mu_pt_gen",  "mu_pt_gen",  20, 0.0, 200);h_mu_pt->Sumw2();
   TH1F* h_mu_phi=new TH1F("mu_phi_gen", "mu_phi_gen", 20, -3.14, 3.14);h_mu_phi->Sumw2();
   TH1F* h_mu_eta=new TH1F("mu_eta_gen", "mu_eta_gen", 50, -6.0, 6.0);h_mu_eta->Sumw2();
   TH1F* h_tau_pt =new TH1F("tau_pt_gen",  "tau_pt_gen",  20, 0.0, 200);h_tau_pt->Sumw2();
   TH1F* h_tau_phi=new TH1F("tau_phi_gen", "tau_phi_gen", 20, -3.14, 3.14);h_tau_phi->Sumw2();
   TH1F* h_tau_eta=new TH1F("tau_eta_gen", "tau_eta_gen", 50, -6.0, 6.0);h_tau_eta->Sumw2();
   TH1F* h_tauMom_pt =new TH1F("tauMom_pt_gen",  "tauMom_pt_gen",  20, 0.0, 200);h_tauMom_pt->Sumw2();

   TH1F* h_visMass_gen=new TH1F("Higgs_mass_gen", "Higgs_mass_gen", 20, 0, 200);h_visMass_gen->Sumw2();
   TH1F* h_cutflow=new TH1F("cutflow", "cutflow", 11, 0, 11);h_cutflow->Sumw2();

   TLorentzVector myMomTau, myTauh,  myNeu, myHiggs;
   int nW_found=0; int nQ_found=0; int nHadrons_found=0;

   Long64_t nentries = fChain->GetEntries();
   std::cout<<"Coming in: "<<std::endl;
   std::cout<<"nentries:"<<nentries<<std::endl;
   //Look at up to maxEvents events, or all if maxEvents == -1.
   Long64_t nentriesToCheck = nentries;
	if (maxEvents != -1LL && nentries > maxEvents)
		nentriesToCheck = maxEvents;
	nTotal = nentriesToCheck;
	Long64_t nbytes = 0, nb = 0;

	std::cout<<"Running over "<<nTotal<<" events."<<std::endl;
	TStopwatch sw;
	sw.Start();
	for (Long64_t jentry=0; jentry<nentriesToCheck;jentry++)
	{
	  
	  event_.clear();
	  event_info.clear();
	  eleCand.clear();
	  tauCand.clear();
	  higgsCand.clear();
	  eleGenCand.clear();   
	  muGenCand.clear();
	  tauGenCand.clear();
	  tauhGenCand.clear();
	  tauNeuGenCand.clear();
	  
	  Long64_t ientry = LoadTree(jentry);
	  if (ientry < 0) break;
	  nb = fChain->GetEntry(jentry);   nbytes += nb;
	  double inspected_event_weight = 1.0; 
	  fabs(genWeight) > 0.0 ? inspected_event_weight *= genWeight/fabs(genWeight) : inspected_event_weight = 0.0;
	  nInspected_genWeighted += inspected_event_weight;  
	  nInspected += 1; 
	  //h_insEvents->SetBinContent(1, nInspected_genWeighted);
	  //=1.0 for real data
	  double event_weight=1.0;
	  double sf_tauID = 1.0; 
	  double sf_IsoEff = 1.0; 
	  double sf_muTrg = 1.0;
	  double sf_muID = 1.0;
	  int report_i=0;
	  numberOfEvents+=event_weight;
	  event_weight=inspected_event_weight;
	  bool found_H=false;
	  higgsCand = found_higgs();
	  muGenCand = found_muon();  
	  eleGenCand = found_electron(); 
	  tauGenCand = found_tau();  
	  tauhGenCand = found_tauh();  
	  tauNeuGenCand = found_tauNeu();   
	  if(!(higgsCand.size() >0 ))continue; 
	  found_H=true;   if (found_H==true)nHiggs++; 
	  h_Hpt_gen_org->Fill(mcPt->at(higgsCand[0]), event_weight);

	  if( tauGenCand.size()>0 )
	 {
	   
	   std::vector<int> index_t1; index_t1.clear();
	   std::vector<int> index_t2; index_t2.clear();
	   std::vector<int> index_m1; index_m1.clear();
	   std::vector<int> index_m2; index_m2.clear();
	   std::vector<int> index_e1; index_e1.clear();
	   std::vector<int> index_e2; index_e2.clear();
	   std::vector<int> index_nu1; index_nu1.clear();
	   std::vector<int> index_nu2; index_nu2.clear();
	   //std::cout<<"tau size:"<<tauGenCand.size()<<", mu size :"<<muGenCand.size()<<" , mom size : "<<mcMotherPID->size()<<", nMC:"<<nMC<<endl;
	   for (int i=0; i<tauGenCand.size(); i++)
	     {
	       if( mcPID->at(tauGenCand[i])==  15 ) index_t1.push_back(tauGenCand[i]);
	       if( mcPID->at(tauGenCand[i])== -15 ) index_t2.push_back(tauGenCand[i]);
	       //std::cout<<"    "<<i<<" . taus "<<mcPID->at(tauGenCand[i])<<endl;
	     }
	   //std::cout<<"tau Index = " <<mcIndex->at(tauGenCand[0])<<" tauSize="<<tauGenCand.size()<< " mother = "<<mcMotherPID->at(tauGenCand[0])<< endl;
	   if(tauNeuGenCand.size()>0)
	     {
	       for(int i=0; i<tauNeuGenCand.size(); i++)
		 {
		   //std::cout<<"   tau nu size"<< tauNeuGenCand.size()<<endl;
		   //std::cout<<"        "<<i<<" . tau nu_mom "<<mcMotherPID->at(tauNeuGenCand[i])<<endl;
		   if(mcMotherPID->at(tauNeuGenCand[i])==  15) index_nu1.push_back(tauNeuGenCand[i]);
                   if(mcMotherPID->at(tauNeuGenCand[i])== -15) index_nu2.push_back(tauNeuGenCand[i]);
		 }
	     }
	   if(eleGenCand.size()>0)
	     {
	       for (int i=0; i<eleGenCand.size(); i++)
		 {
		   //std::cout<<"        "<<i<<" . e_mom "<<mcMotherPID->at(eleGenCand[i])<<endl;
		   if( mcMotherPID->at(eleGenCand[i])==  15 ) index_e1.push_back(eleGenCand[i]);
		   if( mcMotherPID->at(eleGenCand[i])== -15 ) index_e2.push_back(eleGenCand[i]);
		 }
	     }
	   if( muGenCand.size()>0)
	     {
	       for (int i=0; i<muGenCand.size(); i++)
		 {
		   // std::cout<<"        "<<i<<" . mu_mom "<<mcMotherPID->at(muGenCand[i])<<endl;
		   if( mcMotherPID->at(muGenCand[i])==  15 ) index_m1.push_back(muGenCand[i]);
		   if( mcMotherPID->at(muGenCand[i])== -15 ) index_m2.push_back(muGenCand[i]);
		 }
	     }
	   
	   bool found_t1=false; bool found_t2=false; 
	   bool found_m1=false; bool found_m2=false; 
	   bool found_e1=false; bool found_e2=false;
	   bool tauMtauE=false; bool tauEtauE=false; bool tauEtauh=false; bool tauhtauE=false;
	   bool muele=false; bool elemu=false;
	   if(index_e1.size()>0)
	     {
	       found_e1=true;
	       if(index_m2.size()>0) { found_m2=true;  tauEtauM=true; }
	       else if (index_m1.size()>0) muele=true;
	       else if (index_e2.size()>0) tauEtauE=true;
	       else if(mcCharge->at(index_e1[0])*mcCharge->at(index_t2[0])<0) tauEtauh=true;
	       
	     }
	   if(index_e2.size()>0)
             {
	       found_e2=true;
               if (index_m1.size()>0) { found_m1=true; tauMtauE=true; }
	       else if (index_e1.size()>0) tauEtauE=true;
	       else if (index_m2.size()>0) elemu=true;
	       else if(mcCharge->at(index_e2[0])*mcCharge->at(index_t1[0])<0)tauhtauE=true;
             }
	   
	   found_et++;
	   if((tauEtauh==true || tauhtauE==true) && tauEtauE==false && elemu==false && muele==false)
	     {
	       nHToEleTau++;
	       int tauhMom_index=-1; int tauNu_index=-1;
	       if     (tauEtauh==true &&  tauhtauE==false) { tauhMom_index=index_t2[0]; tauNu_index=index_nu2[0]; }
	       else if(tauEtauh==false && tauhtauE==true ) { tauhMom_index=index_t1[0]; tauNu_index=index_nu1[0]; }
	       
	       myMomTau.SetPtEtaPhiM(mcPt->at(tauhMom_index), mcEta->at(tauhMom_index), mcPhi ->at(tauhMom_index), mcMass->at(tauhMom_index));
	       myNeu.SetPtEtaPhiM(mcPt->at(tauNu_index), mcEta->at(tauNu_index), mcPhi->at(tauNu_index), mcMass->at(tauNu_index));		    
	       myTauh = myMomTau - myNeu;
	       
	       h_Hpt_gen->Fill(mcPt->at(higgsCand[0]), event_weight);
	       h_visMass_gen->Fill(mcMass->at(higgsCand[0]), event_weight);
	       h_mu_pt ->Fill( mcPt->at(muGenCand[0]), event_weight);
	       h_mu_phi->Fill(mcPhi->at(muGenCand[0]), event_weight);
	       h_mu_eta->Fill(mcEta->at(muGenCand[0]), event_weight);
	       
	       h_tauMom_pt->Fill( myMomTau.Pt(), event_weight);
	       h_tau_pt ->Fill( myTauh.Pt(), event_weight);
	       h_tau_phi->Fill( myTauh.Phi(), event_weight);
	       h_tau_eta->Fill( myTauh.Eta(), event_weight);
	     }
	 }////// gen level closing
       




















	  higgsCand = found_higgs();
	  if(higgsCand.size() >0)
	    {
	      found_H=true;
	      h_Hpt_gen->Fill(mcPt->at(higgsCand[0]), event_weight);
	      h_visMass_gen->Fill(mcMass->at(higgsCand[0]), event_weight);
	      
	      //double deltaR = delta_R(mcPhi , mcEta, mcPhi, mcEta);
	    }
	  if (found_H==true)nHiggs++;
	  if(higgsCand.size() <0)continue;
	  eleCand = getEleCand(25,2.1); tauCand = getTauCand(30,2.3);
	  if(metFilters==0)
	    {
	      fabs(genWeight) > 0.0 ? event_weight *= genWeight/fabs(genWeight) : event_weight = 0;
	      nMETFiltersPassed+=event_weight;
	      //if(HLTEleMuX>>21&1 == 1 ) // Single muon trigger
	      {
		nSingleTrgPassed+=event_weight;
		if(eleCand.size() >0)
		  {
		    nGoodMuonPassed+=event_weight;
		    if( tauCand.size() >0 )
		      {
			if( HLTTau>>1&1 == 1 )
			  {
			    if(! (tau_Pt->at(tauCand[0]) >32 && fabs( tau_Eta->at(tauCand[0]))<2.1)) continue;
			  } 
			nGoodTauPassed+=event_weight;
			if( (eleCharge->at(eleCand[0]))*(tau_Charge->at(tauCand[0])) < 0 ) 
			  {
			    nGoodMuTauPassed+=event_weight;
			    fillHistos(0,event_weight,eleCand[0], tauCand[0], higgsCand[0]);
			    if( thirdLeptonVeto()==true )
			      {
				nPassedThirdLepVeto+=event_weight;
				fillHistos(1,event_weight,eleCand[0], tauCand[0], higgsCand[0]);
				if( passBjetVeto() == true)
				  {
				    nPassedBjetVeto+=event_weight;
				    fillHistos(2,event_weight,eleCand[0], tauCand[0], higgsCand[0]);
				    
				    double deltaR = dR(eleCand[0],tauCand[0]);
				    if(deltaR < 0.5 )
				      {
					nDeltaRPassed+=event_weight;
					fillHistos(3,event_weight,eleCand[0], tauCand[0], higgsCand[0]);
					if (tau_IDbits->at(tauCand[0])>>2&1==1 && tau_IDbits->at(tauCand[0])>>4&1==1)
					  fillHistos(4,event_weight,eleCand[0], tauCand[0], higgsCand[0]);
				      }
				    if(deltaR > 0.5 )
				      {
					nDeltaRPassed+=event_weight;
					fillHistos(5,event_weight,eleCand[0], tauCand[0], higgsCand[0]);
					if (tau_IDbits->at(tauCand[0])>>2&1==1 && tau_IDbits->at(tauCand[0])>>7&1==1)
					  fillHistos(6,event_weight,eleCand[0], tauCand[0], higgsCand[0]);
					
				      }
				  }
			      }
			  }
		      }
		  }
	      }
	    }
	


	  h_nEvents->SetBinContent(1, nInspected_genWeighted); 
	  report_test = nentriesToCheck/20;
	  while (report_test>10)
	    {
	      report_test=report_test/10;
	      report_i++;
	    }
	  reportEvery = report_test*pow(10,report_i);
	  if (jentry%reportEvery == 0)
	    {
	      std::cout<<"Finished entry "<<jentry<<"/"<<(nentriesToCheck-1)<<std::endl;
	    }
	  
	}
	
	std::cout.setf( std::ios::fixed, std:: ios::floatfield );
	if((nentriesToCheck-1)%reportEvery != 0)
		std::cout<<"Finished entry "<<(nentriesToCheck-1)<<"/"<<(nentriesToCheck-1)<<std::endl;
	sw.Stop();
	std::cout<<"All events checked."<<std::endl;
	std::cout<<"*******************************************"<<std::endl;
	std::cout<<"******************Jithin's original*************************"<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"Initial entries "<<numberOfEvents<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"Inspected genWeightd "<<nInspected_genWeighted<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"METFiltersPassed "<<nMETFiltersPassed<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"SingleTrgPassed "<<nSingleTrgPassed<<std::endl;
       	std::cout<<std::setw(20) <<std::right <<"GoodElectronPassed "<<nGoodMuonPassed<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"GoodTauPassed "<<nGoodTauPassed<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"opp charge "<<nGoodMuTauPassed<<std::endl;
      	std::cout<<std::setw(20) <<std::right <<"PassedThirdLepVeto "<<nPassedThirdLepVeto<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"PassedBjetVeto "<<nPassedBjetVeto<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"DeltaRPassed "<<nDeltaRPassed<<std::endl;

	std::cout<<"*******************************************"<<std::endl;
	std::cout<<"*******************************************"<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"Number of events inspected: " << nInspected <<std::endl;
	std::cout<<std::setw(20) <<std::right << "Number of events inspected (minus negative gen. weights): " << nInspected_genWeighted << std::endl; 
	std::cout<<"*******************************************"<<std::endl;
	std::cout<<std::setw(20) <<std::right <<"n higgs found = " << nHiggs<<std::endl;
	
}

void Analyzer_etau::BookHistos(const char* file2)
{
	fileName = new TFile(file2, "RECREATE");
	tree = new TTree("ADD","ADD");
	tree->Branch("event_","std::vector<unsigned int>",&event_);
	tree->Branch("event_info","std::vector<double>",&event_info);
	fileName->cd();

	Float_t Pt_Bins[36]={0.0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 450, 500, 600, 800, 1000};
	
	Float_t MetBins[15]={0.0, 20, 40, 60, 80, 100, 120, 140, 160,180., 200, 300., 400., 600.0,800.0};
	Float_t TrMassBins[24]={0.0, 20, 40, 60, 80, 100, 120, 140, 160,180., 200, 220, 240,260,280,300.,320,340,360,380, 400., 600.0,800.0, 1000.0};


	//Set up the histos to be filled with method fillHistos
	for(int i=0; i<10; i++)
	  {
	    char ptbins[100];
		sprintf(ptbins, "_%d", i);
		std::string histname(ptbins);
		
		h_dR[i] = new TH1F(("h_dR"+histname).c_str(),"h_dR",20,0,2.0);h_dR[i]->Sumw2();
		h_HiggsPt[i]= new TH1F(("HiggsPt"+histname).c_str(),"HiggsPt", 100, 0.0, 1000.0);h_HiggsPt[i]->Sumw2();
		h_VisibleMass[i]= new TH1F(("VisibleMass"+histname).c_str(),"VisibleMass",20, 0, 200);h_VisibleMass[i]->Sumw2();

	}
}

//Fill the sequential histos at a particular spot in the sequence
void Analyzer_etau::fillHistos(int histoNumber, double event_weight,int eleIndex, int tauIndex, int higgs_Index)
{
  
		double dR_mutau = dR(eleIndex,tauIndex);
		h_dR[histoNumber]->Fill(dR_mutau,event_weight);

		TLorentzVector myTau; 
		myTau.SetPtEtaPhiE(tau_Pt->at(tauIndex),tau_Eta->at(tauIndex),tau_Phi->at(tauIndex), tau_Energy->at(tauIndex));		
		TLorentzVector myEle; 
		myEle.SetPtEtaPhiE(elePt->at(eleIndex),eleEta->at(eleIndex),elePhi->at(eleIndex), eleE->at(eleIndex));
		double visMass_mutau = VisMass_F(myTau, myEle);
		h_VisibleMass[histoNumber]->Fill(visMass_mutau,event_weight);

		double HiggsPt = pTvecsum_F(elePt->at(eleIndex),tau_Pt->at(tauIndex),elePhi->at(eleIndex),tau_Phi->at(tauIndex) );
		h_HiggsPt[histoNumber]->Fill(mcPt->at(higgs_Index),event_weight);
		
}




//---------------------------------------------------                                                                                                                                
// get a electron candiate based on pt eta and isolation                                                                                                                               
//----------------------------------------------------                                                                                                                               

std::vector<int> Analyzer_etau::getEleCand(double elePtCut, double eleEtaCut){
  std::vector<int> tmpCand;
  tmpCand.clear();
  //Loop over muons                                                                     
   for(int iEle=0;iEle<nEle;iEle++)
    {
      bool kinematic = false;
      if( (*elePt)[iEle] > elePtCut  && fabs((*eleEta)[iEle])< eleEtaCut && fabs(eleDz->at(iEle)) < 0.2 && fabs(eleD0->at(iEle))<0.045 &&   eleMissHits->at(iEle) <=1 &&  eleConvVeto->at(iEle)==1 && eleIDbit->at(iEle)>>8&1==1 ) kinematic = true;
	  
      // eleMVAnoIsoID ->  eleIDbit->at(iEle)>>8&1==1
      
      bool muTirgger = false;
      if( (HLTEleMuX>>59&1 == 1 && elePt->at(iEle)>33) || (HLTEleMuX>>5&1 == 1 && elePt->at(iEle)>36)  || (HLTTau>>1&1 == 1 && elePt->at(iEle)>25 && elePt->at(iEle)<33) )muTirgger=true;
      
      bool muonId =false;
      if( eleIDbit->at(iEle)>>1&1==1) muonId =true;
      bool relative_iso = false;
     
      float relMuIso = ( elePFChIso->at(iEle) + max( elePFNeuIso->at(iEle) + elePFPhoIso->at(iEle) - 0.5 *elePFPUIso->at(iEle) , 0.0 )) / (elePt->at(iEle));

      if( relMuIso < 0.1 ) relative_iso = true;
      if( kinematic && muTirgger &&  relative_iso){
	tmpCand.push_back(iEle);
      }                                                                                      
    }                                                                                       
  return tmpCand;
  
}
std::vector<int> Analyzer_etau::found_higgs(){ 
  std::vector<int> tmpCand;    tmpCand.clear();   
  bool found_H=false;
  for(int i=0; i<nMC;i++){
    if (fabs((*mcPID)[i])==25)found_H=true;
    
    if (found_H==true)tmpCand.push_back(i);
  }
  return tmpCand; 
}

std::vector<int> Analyzer_etau::getTauCand(double tauPtCut, double tauEtaCut){
  std::vector<int> tmpCand;
  tmpCand.clear();
  //Loop over taus      
  for(int iTau=0;iTau<nTau;iTau++)
    {
      bool kinematic = false;
      bool tauId = false;
      bool decayModeCut = false;
      bool tauIsolation = false;
     
      if( tau_Pt->at(iTau) > tauPtCut  && fabs( tau_Eta->at(iTau))< tauEtaCut && fabs(tau_ZImpact->at(iTau))<200 && fabs(tau_Charge->at(iTau))==1 )kinematic = true;
      if(  tau_IDbits->at(iTau)>>2&1==1 && tau_IDbits->at(iTau)>>7&1==1) tauId = true;
      if(  tau_IDbits->at(iTau)>>16&1==1 ) tauIsolation = true;
      if( tau_DecayMode->at(iTau)==0 || tau_DecayMode->at(iTau)==1 || tau_DecayMode->at(iTau)==10 ) decayModeCut = true;
      
      if( kinematic==true &&  decayModeCut==true && tauIsolation==true )
	//if(tauId==true && kinematic==true && decayModeCut==true)
	{
	  tmpCand.push_back(iTau);
	}                                                           
    }                                                                                       
  return tmpCand;
  
}


bool Analyzer_etau::thirdLeptonVeto(){
  
  //  std::vector<int> tmpCand;
  //tmpCand.clear();
  int tmpCand = 0;
  bool thirdLep = false;
  bool thirdLepVeto=true;
   //Loop over muons                                                                                                                       

   for(int iMu=0; iMu < nMu;iMu++)
     {
       bool kinematic = false;
       if( (*muPt)[iMu] > 10.0  && fabs((*muEta)[iMu])< 2.4 && (*muD0)[iMu] < 0.045 && (*muDz)[iMu] < 0.2 ) kinematic = true;
       bool electronId =false;
       if( muIDbit->at(iMu)>>1&1==1) electronId =true;
       bool relative_iso = false;

       float relEleIso = ( muPFChIso->at(iMu) + max( muPFNeuIso->at(iMu) + muPFPhoIso->at(iMu) - 0.5 *muPFPUIso->at(iMu) , 0.0 )) / (muPt->at(iMu));
       if( relEleIso < 0.3 ) relative_iso = true;
       if(electronId==true && kinematic==true && relative_iso==true){
	 //tmpCand.push_back(iMu);
	 tmpCand++;
       }                                                                                                                                                    
     }                                                                                                                      
   if(tmpCand > 0){ thirdLep = true; thirdLepVeto=false;}
   //   if( thirdLep = true ) thirdLepVeto=false;
   //if( tmpCand = 0 ) thirdLepVeto=true;

   return thirdLepVeto;
   
}




//Veto failed if a electron is found that passes Loose Muon ID, Loose Muon Isolation, and elePtcut, and does not overlap the candidate photon within dR of 0.5                                                                                                                                                                    

double Analyzer_etau::dR(int ele_index, int tau_index)
{
  double deltaeta = abs(eleEta->at(ele_index) - tau_Eta->at(tau_index));
  double electronPhi = elePhi->at(ele_index);
  double tauPhi = tau_Phi->at(tau_index);

  double deltaphi = DeltaPhi(electronPhi, tauPhi);
  double deltar = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
  
}

double Analyzer_etau::delta_R(float phi1, float eta1, float phi2, float eta2)
{
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar   = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
  
}



double Analyzer_etau::DeltaPhi(double phi1, double phi2)
//Gives the (minimum) separation in phi between the specified phi values
//Must return a positive value
{
  double pi = TMath::Pi();
  double dphi = phi1-phi2;
  if(dphi>pi) dphi = 2.0*pi - dphi;
  if(dphi<= -1*pi) dphi =  2.0*pi +dphi;
  return fabs(dphi);
}

float Analyzer_etau::TMass_F(float LepPt, float LepPhi , float met, float metPhi) {
    return sqrt(pow(LepPt + met, 2) - pow(LepPt* cos(LepPhi) + met * cos(metPhi), 2) - pow(LepPt * sin(LepPhi) + met * sin(metPhi), 2));
}

float Analyzer_etau::TotTMass_F(TLorentzVector a, TLorentzVector b, TLorentzVector met) {
  float totalTMass = (a + b+ met).M();
  return totalTMass;
}


float Analyzer_etau::VisMass_F(TLorentzVector a, TLorentzVector b){
  float visibleMass = (a + b).M();
  return visibleMass;
}

float Analyzer_etau::pTvecsum_F(float pt1, float pt2, float phi1, float phi2) {
  float pt_vecSum = sqrt( pow(pt1*cos(phi1) + pt2*cos(phi2), 2) + pow(pt1*sin(phi1) + pt2*sin(phi2), 2));
  return pt_vecSum;
}

bool Analyzer_etau::passBjetVeto()
{
  int tmpCand = 0;
  bool veto = true;
  bool foundBjet = false;
  for(int iJets=0; iJets<nJet ; iJets++){
    if(jetCSV2BJetTags->at(iJets) > 0.8838) tmpCand++;
    // CSV B jet tag for selecting bJets is medium WP (jetCSV2BJetTags > 0.8838.)
  }
  if(tmpCand>0){ veto = false; foundBjet = true; } 
  return veto;
}

bool Analyzer_etau::check_jets()
{
  int tmpCand=0;
  bool found_event = false;
  /*  for (int iJets=0; iJets < nJet; iJets++)
    {
      if ( (jetPt->at(iJets)>100) && (fabs(jetEta->at(iJets)) < 3.0) && (fabs(jetEta->at(iJets) >2.25)))
        {
          tmpCand++;
        }
	}*/
  if(tmpCand>0)  found_event=true;
  return found_event;
}

double Analyzer_etau::prefiring_weight(TH2F* prefiring_photon, TH2F* prefiring_jet)
{ 
}
