//////new_analyzer.C
//For use with Ntuples made from ggNtuplizer
//Required arguments: 1 is folder containing input files, 2 is output file path, 3 is maxEvents (-1 to run over all events), 4 is reportEvery
//
//To compile using rootcom to an executable named 'analyze':
//$ ./rootcom new_analyzer analyze
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
#define new_analyzer_cxx
#include "new_analyzer.h"
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
#include <map>
#include <set>
#include "TMath.h" //M_PI is in TMath
#include "TRandom3.h"
#include <TLorentzVector.h>
#include "makeHisto.h" 

using namespace std;
using std::vector;
int main(int argc, const char* argv[])
{
  myMap1 = new map<string, TH1F*>();
  //myMap2 = new map<string, TH2F*>();
  std::string SampleName = argv[5];
  std::string isMC  = argv[6];
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
  new_analyzer t(argv[1],argv[2]);
  t.Loop(maxEvents,reportEvery, SampleName , isMC);
  delete myMap1;
  return 0;
}

void new_analyzer::Loop(Long64_t maxEvents, int reportEvery, string SampleName, string _isMC_)
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
  double nHLTPassed,n_eventWeight, nSingleTrgPassed, nGoodMuonPassed, nElectronPtPassed, nGoodTauPassed, nTauPtPassed,numberOfEvents,nMETPassed, nDPhiPassed, nqcdden,nqcdnum, nMETFiltersPassed,nLeptonVetoPassed,nPassedBjetVeto,nNoisyCrystals,nDPhiJetMETPassed, nGoodMuTauPassed,nDeltaRPassed,nPassedThirdLepVeto,nMtPassed,  nPassedHiggsPtcut, nPassedVisibleMasscut, nPassedMETcut, nFinal_afterSelections, nGoodMuonPassed_qcd, nGoodTauPassed_qcd, nGoodMuTauPassed_qcd, nDeltaRPassed_qcd, nPassedThirdLepVeto_qcd,nPassedBjetVeto_qcd, nPassedHiggsPtcut_qcd, nPassedVisibleMasscut_qcd, nPassedMETcut_qcd, nFinal_afterSelections_qcd ,nPasstottrmass, nPassJetsSelection,nL1PrefiringPassed, nMuonDzPassed, nMuonD0Passed, nMuonIdPassed, nMuonIsoPassed, nTauIsoPassed, nTauDecayModePassed, nTauRejectionPassed;
  nHLTPassed = n_eventWeight = nSingleTrgPassed = nGoodMuonPassed = nElectronPtPassed = nGoodTauPassed = nTauPtPassed= numberOfEvents = nMETPassed = nDPhiPassed = nqcdden= nqcdnum=nMETFiltersPassed= nLeptonVetoPassed=nPassedBjetVeto=nNoisyCrystals=nDPhiJetMETPassed= nGoodMuTauPassed = nDeltaRPassed= nPassedThirdLepVeto=nMtPassed=nPassedHiggsPtcut=nPassedVisibleMasscut=nPassedMETcut=nFinal_afterSelections=nGoodMuonPassed_qcd=nGoodTauPassed_qcd=nGoodMuTauPassed_qcd=nDeltaRPassed_qcd=nPassedThirdLepVeto_qcd=nPassedBjetVeto_qcd=nPassedHiggsPtcut_qcd=nPassedVisibleMasscut_qcd=nPassedMETcut_qcd=nFinal_afterSelections_qcd=nPasstottrmass= nPassJetsSelection=nL1PrefiringPassed=nMuonDzPassed=nMuonD0Passed=nMuonIdPassed=nMuonIsoPassed=nTauIsoPassed=nTauDecayModePassed=nTauRejectionPassed=0;

   std::vector<int> muCand;        muCand.clear();
   std::vector<int> tauCand;       tauCand.clear();

   std::vector<int> higgsCand;     higgsCand.clear();
   std::vector<int> reco_mu;       reco_mu.clear(); 
   std::vector<int> reco_tau;      reco_tau.clear(); 
   
   TString sample = TString(SampleName);
  
   int nHiggs = 0;
   int nHToMuTau = 0;
   int found_mt = 0;
   int muCand_1=0; int muCand_2=0;int muCand_3=0;
   int tauCand_1=0; int tauCand_2=0;int tauCand_3=0;

   bool fill_hist = false;
   bool isMC = false;
   if( _isMC_=="MC" ) { isMC=true; fill_hist=true; }
   else if ( _isMC_=="data" ) { isMC=false; fill_hist=false; }
   //bool debug=true;
   Double_t  Pt_Bins[26]={0.0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 450, 500, 600, 800, 1000};
   Double_t  Pt_Bins_highPt[21]={100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 450, 500, 600, 800, 1000};

   TH1F* h_nEvents=new TH1F("nEvents", "nEvents", 5, 0, 5);h_nEvents->Sumw2();
   TH1F* h_Hpt_gen=new TH1F("Higgs_pt_gen", "Higgs_pt_gen", 25, Pt_Bins);h_Hpt_gen->Sumw2();
   TH1F* h_Hpt_gen_org=new TH1F("Higgs_pt_gen_org", "Higgs_pt_gen_org", 25, Pt_Bins);h_Hpt_gen_org->Sumw2();
   TH1F* h_cutflow=new TH1F("cutflow", "cutflow", 11, 0, 11); 
   TH1F* h_cutflow_n=new TH1F("cutflow_n", "cutflow_n", 9, 0, 9);
  
   Long64_t nentries = fChain->GetEntries();
   if ( isMC==true ) std::cout<<".... MC file ..... "<<std::endl;
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
       higgsCand.clear();
       muCand.clear();
       tauCand.clear();
       reco_mu.clear(); 
       reco_tau.clear();  
       

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
       int report_i=0;
       numberOfEvents+=event_weight;
       event_weight=inspected_event_weight;
       
       if(isMC==true)  {
	 higgsCand = found_higgs(); 
	 if(higgsCand.size() >0 )
	   {
	     h_Hpt_gen_org->Fill(mcPt->at(higgsCand[0]), event_weight); 
	     h_Hpt_gen->Fill(mcPt->at(higgsCand[0]), event_weight*0.23);
	   }
       }
       int leading_muon = -1; float leading_mPt=0;
       int leading_tau = -1;  float leading_tPt=0;
       ////// reco selection begin
       if(metFilters==0)
	 {
	   //fabs(genWeight) > 0.0 ? event_weight *= genWeight/fabs(genWeight) : event_weight = 0;
	   nMETFiltersPassed+=event_weight;
	   if(fill_hist==true )fillHistos(0,event_weight, higgsCand[0]);
	   if( HLTEleMuX>>21&1 == 1 ||
	       HLTEleMuX>>60&1 == 1 ||
	       HLTTau>>0&1  == 1       )
	     {
	       nSingleTrgPassed+=event_weight;
	       if(fill_hist==true )fillHistos(1,event_weight, higgsCand[0]);
	       muCand = getMuCand(20,2.4);  ///// muons selected 
	       if( muCand.size() >0 ) 
		 { 
		   nGoodMuonPassed+=event_weight;
		   if(fill_hist==true )fillHistos(2,event_weight, higgsCand[0]);
		   plotFill("muPt_2",  muPt->at(muCand[0]) , 40 , 0 , 200);
		   plotFill("muEta_2", muEta->at(muCand[0]), 30, -6, 6);
		   plotFill("muDz_2",  muDz->at(muCand[0]), 20, -0.5, 0.5);
		   plotFill("muD0_2",  muD0->at(muCand[0]), 24, -0.06, 0.06);
		   plotFill("muonID_2",muIDbit->at(muCand[0])>>1&1, 4, -2, 2); // muonID
		   plotFill("relMuIso_2", muIDbit->at(muCand[0])>>8&1, 4, -2, 2);
		   plotFill("muCharge_2", muCharge->at(muCand[0]), 8, -2, 2 );
		   
		   tauCand = getTauCand(30,2.3);
		   if( tauCand.size()>0 ) 
		     {
		       nGoodTauPassed+=event_weight;
		       if(fill_hist==true )fillHistos(3,event_weight, higgsCand[0]);
		       plotFill("muPt_3",  muPt->at(muCand[0]) , 40 , 0 , 200);
		       plotFill("muEta_3", muEta->at(muCand[0]), 30, -6, 6);
		       plotFill("muDz_3",  muDz->at(muCand[0]), 20, -0.5, 0.5);
		       plotFill("muD0_3",  muD0->at(muCand[0]), 24, -0.06, 0.06);
		       plotFill("muonID_3",muIDbit->at(muCand[0])>>1&1, 4, -2, 2); // muonID
		       plotFill("relMuIso_3", muIDbit->at(muCand[0])>>8&1, 4, -2, 2);
		       plotFill("muCharge_3", muCharge->at(muCand[0]), 8, -2, 2 );

		       plotFill("tauPt_3",  tau_Pt->at(tauCand[0]) , 40 , 0 , 200);
		       plotFill("tauEta_3", tau_Eta->at(tauCand[0]), 30, -6, 6);
		       plotFill("tauIso_3", tau_IDbits->at(tauCand[0])>>16&1, 4, -2, 2);
		       plotFill("tauDecayMode_3", tau_DecayMode->at(tauCand[0]) , 10, 0, 10);
		       plotFill("tauCharge_3", tau_Charge->at(tauCand[0]), 8, -2, 2 );
		       plotFill("tauAntiEle_3", tau_IDbits->at(tauCand[0])>>3&1==1, 8, -2, 2 );
		       plotFill("tauAntiMu_3", tau_IDbits->at(tauCand[0])>>4&1==1, 8, -2, 2 );

		       reco_mu.clear();reco_tau.clear();
		       //reco_mu.push_back( leading_muon );
		       //reco_tau.push_back( leading_tau );
		       for (int iMu=0; iMu<muCand.size(); iMu++)
			 {
			   for (int iTau=0; iTau<tauCand.size(); iTau++)
			     {
			       if( (muCharge->at(muCand[iMu]))*(tau_Charge->at(tauCand[iTau]))<0 )
				 {
				   reco_mu.push_back(muCand[iMu]);
				   reco_tau.push_back(tauCand[iTau]);
				 }
			     }
			 }

		       if ( reco_mu.size()>0 && reco_tau.size()>0  ) 
			 {
			   nGoodMuTauPassed+=event_weight;
			   if(fill_hist==true )fillHistos(4,event_weight, higgsCand[0]);
			   plotFill("muPt_4",  muPt->at(reco_mu[0]) , 40 , 0 , 200);
			   plotFill("muEta_4", muEta->at(reco_mu[0]), 30, -6, 6);
			   plotFill("muDz_4",  muDz->at(reco_mu[0]), 20, -0.5, 0.5);
			   plotFill("muD0_4",  muD0->at(reco_mu[0]), 24, -0.06, 0.06);
			   plotFill("muonID_4",muIDbit->at(reco_mu[0])>>1&1, 4, -2, 2); // muonID
			   plotFill("relMuIso_4", muIDbit->at(reco_mu[0])>>8&1, 4, -2, 2);
			   plotFill("muCharge_4", muCharge->at(reco_mu[0]), 8, -2, 2 );

			   plotFill("tauPt_4",  tau_Pt->at(reco_tau[0]) , 40 , 0 , 200);
			   plotFill("tauEta_4", tau_Eta->at(reco_tau[0]), 30, -6, 6);
			   plotFill("tauIso_4", tau_IDbits->at(reco_tau[0])>>16&1, 4, -2, 2);
			   plotFill("tauDecayMode_4", tau_DecayMode->at(reco_tau[0]) , 10, 0, 10);
			   plotFill("tauCharge_4", tau_Charge->at(reco_tau[0]), 8, -2, 2 );
			   plotFill("tauAntiEle_4", tau_IDbits->at(reco_tau[0])>>3&1==1, 8, -2, 2 );
			   plotFill("tauAntiMu_4", tau_IDbits->at(reco_tau[0])>>4&1==1, 8, -2, 2 );

			   if( thirdLeptonVeto()==true )
			     {
			       nPassedThirdLepVeto+=event_weight;
			       if(fill_hist==true )fillHistos(5,event_weight, higgsCand[0]);
			       if( passBjetVeto() == true)
				 {
				   nPassedBjetVeto+=event_weight;
				   if(fill_hist==true )fillHistos(6,event_weight, higgsCand[0]);
				   double deltaR = dR(reco_mu[0],reco_tau[0]);
				   if(deltaR > 0.5 )
				     {
				       nDeltaRPassed+=event_weight;
				       if(fill_hist==true )fillHistos(7,event_weight, higgsCand[0]);
				       if ( tau_IDbits->at(reco_tau[0])>>4&1==1 && tau_IDbits->at(reco_tau[0])>>3&1==1)
					 {
					   if(fill_hist==true )fillHistos(7,event_weight, higgsCand[0]);
					   nTauRejectionPassed+=event_weight;
					 }
				     }
				 }
			     }
			 }
		     }
		 }
	     }
	 }
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
   
   h_nEvents->SetBinContent(1, nInspected_genWeighted);
   

   //map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
   //map<string, TH1F*>::const_iterator jMap1 = myMap1->end();
   //   for (iMap1; iMap1 != jMap1; iMap1++)
   //nplot1(iMap1->first)->Write();
   

   std::cout.setf( std::ios::fixed, std:: ios::floatfield );
   if((nentriesToCheck-1)%reportEvery != 0)
     std::cout<<"Finished entry "<<(nentriesToCheck-1)<<"/"<<(nentriesToCheck-1)<<std::endl;
   sw.Stop();
   std::cout<<"All events checked."<<std::endl;
   std::cout<<"*******************************************"<<std::endl;
   std::cout<<"******************Jithin's original*************************"<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"Initial entries "<<numberOfEvents<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"Inspected genWeightd "<<nInspected_genWeighted<<std::setw(10) <<std::right << "   % change= "<<(numberOfEvents-nInspected_genWeighted)*100/numberOfEvents<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"METFiltersPassed "<<nMETFiltersPassed<<std::setw(10) <<std::right << "   % change= "<<(nInspected_genWeighted-nMETFiltersPassed)*100/nInspected_genWeighted<<std::endl;

   std::cout<<std::setw(20) <<std::right <<"SingleTrgPassed "<<nSingleTrgPassed<<std::setw(10) <<std::right << "   % change= "<<(nMETFiltersPassed-nSingleTrgPassed)*100/nMETFiltersPassed<<std::endl;

   std::cout<<std::setw(20) <<std::right <<"GoodMuonPassed "<<nGoodMuonPassed<<std::setw(10) <<std::right << "   % change= "<<(nSingleTrgPassed-nGoodMuonPassed)*100/nSingleTrgPassed<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"GoodTauPassed "<<nGoodTauPassed<<std::setw(10) <<std::right << "   % change= "<<(nGoodMuonPassed-nGoodTauPassed)*100/nGoodMuonPassed<<std::endl;
   //   std::cout<<std::setw(20) <<std::right <<"TauIsoPassed "<<nTauIsoPassed<<std::setw(10) <<std::right << "   % change= "<<(nGoodTauPassed-nTauIsoPassed)*100/nGoodTauPassed<<std::endl;
   //std::cout<<std::setw(20) <<std::right <<"TauDecayModePassed "<<nTauDecayModePassed<<std::setw(10) <<std::right << "   % change= "<<(nTauIsoPassed-nTauDecayModePassed)*100/nTauIsoPassed<<std::endl;

   std::cout<<std::setw(20) <<std::right <<"opp charge "<<nGoodMuTauPassed<<std::setw(10) <<std::right << "   % change= "<<(nGoodTauPassed-nGoodMuTauPassed)*100/nGoodTauPassed<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"PassedThirdLepVeto "<<nPassedThirdLepVeto<<std::setw(10) <<std::right << "   % change= "<<(nGoodMuTauPassed-nPassedThirdLepVeto)*100/nGoodMuTauPassed<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"PassedBjetVeto "<<nPassedBjetVeto<<std::setw(10) <<std::right << "   % change= "<<(nPassedThirdLepVeto-nPassedBjetVeto)*100/nPassedThirdLepVeto<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"DeltaRPassed "<<nDeltaRPassed<<std::setw(10) <<std::right << "   % change= "<<(nPassedBjetVeto-nDeltaRPassed)*100/nPassedBjetVeto<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"TauRejectionPassed "<<nTauRejectionPassed<<std::setw(10) <<std::right << "   % change= "<< (nDeltaRPassed-nTauRejectionPassed)*100/nDeltaRPassed<<std::endl;


   std::cout<<std::setw(20) <<std::right <<"Total change :"<<(numberOfEvents-nTauRejectionPassed)*100/numberOfEvents<<std::endl;
   std::cout<<"*******************************************"<<std::endl;
   std::cout<<"*******************************************"<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"Number of events inspected: " << nInspected <<std::endl;
   std::cout<<std::setw(20) <<std::right << "Number of events inspected (minus negative gen. weights): " << nInspected_genWeighted << std::endl; 
   //double luminosity = 100000.0;
   //double xs = 44.14*0.0627;
   //double lumi_weight = luminosity*xs/nInspected_genWeighted;
   //std::cout<<std::setw(20) <<std::right <<"weight : "<<lumi_weight<<std::endl;
   
   h_cutflow->SetBinContent(1,nInspected_genWeighted );
   //h_cutflow->SetBinContent(1, nHToMuTau );
   h_cutflow->SetBinContent(2, nSingleTrgPassed);
   h_cutflow->SetBinContent(3, nGoodMuonPassed);
   h_cutflow->SetBinContent(4, nGoodTauPassed);
   h_cutflow->SetBinContent(5, nTauIsoPassed);
   h_cutflow->SetBinContent(6, nTauDecayModePassed);
   h_cutflow->SetBinContent(7, nGoodMuTauPassed);
   h_cutflow->SetBinContent(8, nPassedThirdLepVeto);
   h_cutflow->SetBinContent(9, nPassedBjetVeto);
   h_cutflow->SetBinContent(10, nDeltaRPassed);
   h_cutflow->SetBinContent(11, nTauRejectionPassed);
   
   h_cutflow_n->SetBinContent(1,nInspected_genWeighted );
   h_cutflow_n->SetBinContent(2, nSingleTrgPassed);
   h_cutflow_n->SetBinContent(3, nGoodMuonPassed);
   h_cutflow_n->SetBinContent(4, nGoodTauPassed);
   h_cutflow_n->SetBinContent(5, nGoodMuTauPassed);
   h_cutflow_n->SetBinContent(6, nPassedThirdLepVeto);
   h_cutflow_n->SetBinContent(7, nPassedBjetVeto);
   h_cutflow_n->SetBinContent(8, nDeltaRPassed);
   h_cutflow_n->SetBinContent(9, nTauRejectionPassed);
   
   
}

void new_analyzer::BookHistos(const char* file2)
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
  for(int i=0; i<8; i++)
    {
      char ptbins[100];
      sprintf(ptbins, "_%d", i);
      std::string histname(ptbins);
      
      //h_dR[i] = new TH1F(("h_dR"+histname).c_str(),"h_dR",20,0,2.0);h_dR[i]->Sumw2();
      h_HiggsPt[i]= new TH1F(("HiggsPt"+histname).c_str(),"HiggsPt", 100, 0.0, 1000.0);h_HiggsPt[i]->Sumw2();
      //h_VisibleMass[i]= new TH1F(("VisibleMass"+histname).c_str(),"VisibleMass",20, 0, 200);h_VisibleMass[i]->Sumw2();
      
    }
}

//Fill the sequential histos at a particular spot in the sequence


void new_analyzer::fillHistos(int histoNumber, double event_weight, int higgs_Index)
{
  
		h_HiggsPt[histoNumber]->Fill(mcPt->at(higgs_Index),event_weight);

}




//---------------------------------------------------                                                                                                                                
// get a electron candiate based on pt eta and isolation                                                                                                                               
//----------------------------------------------------                                                                                                                               

std::vector<int> new_analyzer::getMuCand(double muPtCut, double muEtaCut){
  std::vector<int> tmpCand;
  tmpCand.clear();
  //Loop over muons                                                                     
   for(int iMu=0;iMu<nMu;iMu++)
     {
       bool kinematic = false;
       bool muonID = false;
       bool muonIso =  false;
       bool trigger = false;
       if( muPt->at(iMu) > muPtCut  && fabs(muEta->at(iMu))< muEtaCut  && fabs(muDz->at(iMu)) < 0.2 && fabs(muD0->at(iMu))<0.045 ) kinematic = true;
       if( muIDbit->at(iMu)>>1&1==1 ) muonID = true;//|| muIDbit->at(iMu)>>8&1==1 || muIDbit->at(iMu)>>17&1==1  ) muonID = true;
       //float relMuIso = ( muPFChIso->at(iMu) + max( muPFNeuIso->at(iMu) + muPFPhoIso->at(iMu) - 0.5 *muPFPUIso->at(iMu) , 0.0 )) / (muPt->at(iMu));
       //if( relMuIso < 0.15 ) muonIso = true;
       if( muIDbit->at(iMu)>>8&1==1 ) muonIso = true;
       //if(  (HLTEleMuX>>21&1 == 1 && muPt->at(iMu)>28) 
       //    || (HLTEleMuX>>60&1 == 1 && muPt->at(iMu)>25) 
       //    || (   HLTTau>>0&1  == 1 && muPt->at(iMu)>21 && muPt->at(iMu)<25 && muEta->at(iMu)<2.4 ) 
       //    )trigger=true;
       
       if( kinematic==true  &&  muonID==true &&  muonIso==true){
	 tmpCand.push_back(iMu);
       }                                                                                      
     }                                                                                       
  return tmpCand;
  
}

std::vector<int> new_analyzer::getTauCand(double tauPtCut, double tauEtaCut){
  std::vector<int> tmpCand;
  tmpCand.clear();
  //Loop over taus      
  for(int iTau=0;iTau<nTau;iTau++)
    {
      bool kinematic = false;
      bool tauId = false;
      bool decayModeCut = false;
      bool tauIsolation = false;
      bool mutau_separation=false;
      bool charge_selection=false;
      bool tau_reject=false;
      if( tau_Pt->at(iTau) > tauPtCut 
	  && fabs( tau_Eta->at(iTau))< tauEtaCut 
	  //&& fabs(tau_Charge->at(iTau))==1   
	  //&& fabs(tau_ZImpact->at(iTau)) < 200 
	  //&& fabs(tau_Dxy->at(iTau)) < 0.2 
	  )kinematic = true;
      if( tau_IDbits->at(iTau)>>16&1==1 ) tauIsolation=true; 
      if( tau_DecayMode->at(iTau)>=0 ) decayModeCut=true;
      if( tau_IDbits->at(iTau)>>3&1==1 && tau_IDbits->at(iTau)>>4&1==1)tau_reject=true;
      //if( muCharge->at(mu_index)*(tau_Charge->at(iTau))<0 )charge_selection=true;
      

      if( kinematic==true    
	  && decayModeCut==true   
	  && tauIsolation==true 
	  && tau_reject==true   )
	//&& charge_selection==true)
	{
	  tmpCand.push_back(iTau);
    	}                                                           
    }                                                                                       
  return tmpCand;
  
}

bool new_analyzer::thirdLeptonVeto(){
  
  //  std::vector<int> tmpCand;
  //tmpCand.clear();
  int tmpCand = 0;
  bool thirdLep = false;
  bool thirdLepVeto=true;
   //Loop over muons                                                                                                                       

   for(int iEle=0; iEle < nEle;iEle++)
     {
       bool kinematic = false;
       if( (*elePt)[iEle] > 10.0  && fabs((*eleEta)[iEle])< 2.5 && (*eleD0)[iEle] < 0.045 && (*eleDz)[iEle] < 0.2 ) kinematic = true;
       bool electronId =false;
       if( eleIDbit->at(iEle)>>8&1==1) electronId =true;
       bool relative_iso = false;

       float relEleIso = ( elePFChIso->at(iEle) + max( elePFNeuIso->at(iEle) + elePFPhoIso->at(iEle) - 0.5 *elePFPUIso->at(iEle) , 0.0 )) / (elePt->at(iEle));
       if( relEleIso < 0.3 ) relative_iso = true;
       if(electronId==true && kinematic==true && relative_iso==true){
	 //tmpCand.push_back(iEle);
	 tmpCand++;
       }                                                                                                                                                    
     }                                                                                                                      
   if(tmpCand > 0){ thirdLep = true; thirdLepVeto=false;}
   //   if( thirdLep = true ) thirdLepVeto=false;
   //if( tmpCand = 0 ) thirdLepVeto=true;

   return thirdLepVeto;
   
}
                                                                                    

double new_analyzer::dR(int mu_index, int tau_index)
{
  double deltaeta = abs(muEta->at(mu_index) - tau_Eta->at(tau_index));
  double muonPhi = muPhi->at(mu_index);
  double tauPhi = tau_Phi->at(tau_index);

  double deltaphi = DeltaPhi(muonPhi, tauPhi);
  double deltar = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
  
}

double new_analyzer::delta_R(float phi1, float eta1, float phi2, float eta2)
{
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar   = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
  
}



double new_analyzer::DeltaPhi(double phi1, double phi2)
//Gives the (minimum) separation in phi between the specified phi values
//Must return a positive value
{
  double pi = TMath::Pi();
  double dphi = phi1-phi2;
  if(dphi>pi) dphi = 2.0*pi - dphi;
  if(dphi<= -1*pi) dphi =  2.0*pi +dphi;
  return fabs(dphi);
}

float new_analyzer::TMass_F(float LepPt, float LepPhi , float met, float metPhi) {
    return sqrt(pow(LepPt + met, 2) - pow(LepPt* cos(LepPhi) + met * cos(metPhi), 2) - pow(LepPt * sin(LepPhi) + met * sin(metPhi), 2));
}

float new_analyzer::TotTMass_F(TLorentzVector a, TLorentzVector b, TLorentzVector met) {
  float totalTMass = (a + b+ met).M();
  return totalTMass;
}


float new_analyzer::VisMass_F(TLorentzVector a, TLorentzVector b){
  float visibleMass = (a + b).M();
  return visibleMass;
}

float new_analyzer::pTvecsum_F(float pt1, float pt2, float phi1, float phi2) {
  float pt_vecSum = sqrt( pow(pt1*cos(phi1) + pt2*cos(phi2), 2) + pow(pt1*sin(phi1) + pt2*sin(phi2), 2));
  return pt_vecSum;
}

bool new_analyzer::passBjetVeto()
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
std::vector<int> new_analyzer::found_higgs(){ 
  std::vector<int> tmpCand;    tmpCand.clear();   
  bool found_H=false;
  for(int i=0; i<nMC;i++){
    if (fabs(mcPID->at(i))==25  )
      {
	//cout<<i<<" mcStatus: "<<mcStatus->at(i)<<" mcStatusFlag:"<<mcStatusFlag->at(i)<<" mcMass: "<<mcMass->at(i)<<" higgs pt = "<<mcPt->at(i)<<endl;
	if( mcStatus->at(i)==62)
	  tmpCand.push_back(i);
      }
  }
  return tmpCand; 
}
