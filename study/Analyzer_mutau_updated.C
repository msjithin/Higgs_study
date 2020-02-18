////Analyzer_mutau_updated.C
//For use with Ntuples made from ggNtuplizer
//Required arguments: 1 is folder containing input files, 2 is output file path, 3 is maxEvents (-1 to run over all events), 4 is reportEvery
//
//To compile using rootcom to an executable named 'analyze':
//$ ./rootcom Analyzer_mutau_updated analyze
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
#define Analyzer_mutau_updated_cxx
#include "Analyzer_mutau_updated.h"
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
  Analyzer_mutau_updated t(argv[1],argv[2]);
  t.Loop(maxEvents,reportEvery, SampleName);
  delete myMap1;
  return 0;
}

void Analyzer_mutau_updated::Loop(Long64_t maxEvents, int reportEvery, string SampleName)
{

  //myMap1 = new map<string, TH1F*>();
  //myMap2 = new map<string, TH2F*>();
  
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
   std::vector<int> eleGenCand;    eleGenCand.clear();
   std::vector<int> muGenCand;     muGenCand.clear();   
   std::vector<int> tauGenCand;    tauGenCand.clear();
   std::vector<int> tauhGenCand;   tauhGenCand.clear();
   std::vector<int> tauNeuGenCand; tauNeuGenCand.clear();
   std::vector<int> mother_;       mother_.clear();
   std::vector<int> daughter_;     daughter_.clear();
   std::vector<int> reco_mu;       reco_mu.clear(); 
   std::vector<int> reco_tau;      reco_tau.clear(); 
   
   TString sample = TString(SampleName);
   int iphi = 41;
   int ieta = 5;

   int nHiggs = 0;
   int nHToMuTau = 0;
   int found_mt = 0;
   int muCand_1=0; int muCand_2=0;int muCand_3=0;
   int tauCand_1=0; int tauCand_2=0;int tauCand_3=0;
  
   //bool debug=true;
   Double_t  Pt_Bins[26]={0.0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 450, 500, 600, 800, 1000};
   Double_t  Pt_Bins_highPt[21]={100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 450, 500, 600, 800, 1000};

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
   TH1F* h_nMu = new TH1F("nMu", "nMu", 3, 0, 3); h_nMu->Sumw2();
   TH1F* h_nTau = new TH1F("nTau", "nTau", 3, 0, 3); h_nTau->Sumw2();
   TH1F* h_muPt_Hpt_1=new TH1F("muPt_Hpt_1", "muPt_Hpt_1", 20, 0.0, 200); h_muPt_Hpt_1->Sumw2();
   TH1F* h_muPt_Hpt_2=new TH1F("muPt_Hpt_2", "muPt_Hpt_2", 20, 0.0, 200); h_muPt_Hpt_2->Sumw2();
   TH1F* h_muPt_Hpt_3=new TH1F("muPt_Hpt_3", "muPt_Hpt_3", 20, 0.0, 200); h_muPt_Hpt_3->Sumw2();
   TH1F* h_muPt_Hpt_4=new TH1F("muPt_Hpt_4", "muPt_Hpt_4", 20, 0.0, 200); h_muPt_Hpt_4->Sumw2();
   TH1F* h_muPt_Hpt_5=new TH1F("muPt_Hpt_5", "muPt_Hpt_5", 20, 0.0, 200); h_muPt_Hpt_5->Sumw2();
   TH1F* h_muPt_Hpt_6=new TH1F("muPt_Hpt_6", "muPt_Hpt_6", 20, 0.0, 200); h_muPt_Hpt_6->Sumw2();
   TH1F* h_muPt_Hpt_7=new TH1F("muPt_Hpt_7", "muPt_Hpt_7", 20, 0.0, 200); h_muPt_Hpt_7->Sumw2();
   TH1F* h_muEta_Hpt_1=new TH1F("muEta_Hpt_1", "muEta_Hpt_1", 50, -6.0, 6.0); h_muEta_Hpt_1->Sumw2();
   TH1F* h_muEta_Hpt_2=new TH1F("muEta_Hpt_2", "muEta_Hpt_2", 50, -6.0, 6.0); h_muEta_Hpt_2->Sumw2();
   TH1F* h_muEta_Hpt_3=new TH1F("muEta_Hpt_3", "muEta_Hpt_3", 50, -6.0, 6.0); h_muEta_Hpt_3->Sumw2();
   TH1F* h_muEta_Hpt_4=new TH1F("muEta_Hpt_4", "muEta_Hpt_4", 50, -6.0, 6.0); h_muEta_Hpt_4->Sumw2();
   TH1F* h_muEta_Hpt_5=new TH1F("muEta_Hpt_5", "muEta_Hpt_5", 50, -6.0, 6.0); h_muEta_Hpt_5->Sumw2();
   TH1F* h_muEta_Hpt_6=new TH1F("muEta_Hpt_6", "muEta_Hpt_6", 50, -6.0, 6.0); h_muEta_Hpt_6->Sumw2();
   TH1F* h_muEta_Hpt_7=new TH1F("muEta_Hpt_7", "muEta_Hpt_7", 50, -6.0, 6.0); h_muEta_Hpt_7->Sumw2();
   
   TH1F* h_muCharge_1=new TH1F("mu_Charge_1", "mu_Charge_1", 4, -2, 2); h_muCharge_1->Sumw2();
   TH1F* h_muCharge_2=new TH1F("mu_Charge_2", "mu_Charge_2", 4, -2, 2); h_muCharge_2->Sumw2();
   TH1F* h_muCharge_3=new TH1F("mu_Charge_3", "mu_Charge_3", 4, -2, 2); h_muCharge_3->Sumw2();
   TH1F* h_tauCharge_1=new TH1F("tau_Charge_1", "tau_Charge_1", 4, -2, 2); h_tauCharge_1->Sumw2();
   TH1F* h_tauCharge_2=new TH1F("tau_Charge_2", "tau_Charge_2", 4, -2, 2); h_tauCharge_2->Sumw2();
   TH1F* h_tauCharge_3=new TH1F("tau_Charge_3", "tau_Charge_3", 4, -2, 2); h_tauCharge_3->Sumw2();

   TH2F* h_muPt_Hpt_2D  =new TH2F("muPt_Hpt_2D","muPt_Hpt_2D",20, 0.0, 200, 25, Pt_Bins);
   TH2F* h_muPt_Hpt_2D_highPt  =new TH2F("muPt_Hpt_2D_highPt","muPt_Hpt_2D_highPt",16, 50, 200, 25, Pt_Bins);


   TH1F* h_visMass_gen=new TH1F("Higgs_mass_gen", "Higgs_mass_gen", 20, 0, 200);h_visMass_gen->Sumw2();
   TH1F* h_cutflow=new TH1F("cutflow", "cutflow", 11, 0, 11);h_cutflow->Sumw2();
   TH1F* h_cutflow_n=new TH1F("cutflow_n", "cutflow_n", 9, 0, 9);h_cutflow_n->Sumw2();

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
       muCand.clear();
       tauCand.clear();
       higgsCand.clear();
       eleGenCand.clear();   
       muGenCand.clear();
       tauGenCand.clear();
       tauhGenCand.clear();
       tauNeuGenCand.clear();
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
       //mother_=found_mother();
       //daughter_=found_daughter();
       if(!(higgsCand.size() >0 ))continue;	   
       found_H=true;
       //std::cout<<jentry <<" : Higgs cand size = "<<higgsCand.size()<< endl;
       //for (int i=0; i< higgsCand.size(); i++)
       //	 std::cout<<"    "<<higgsCand[i]<<"mc status :"<<mcStatus->at(higgsCand[i])<<endl;
       if (found_H==true)nHiggs++;
       h_Hpt_gen_org->Fill(mcPt->at(higgsCand[0]), event_weight);
       //std::cout<<"jentry = "<< jentry<<  endl;
       //for(int i=0; i<mcMotherPID->size();i++)
       //std::cout<<i<<".      mother pid : "<< mcMotherPID->at(i)<<endl;
       //std::cout<<" nMC = "<< nMC<< " mcIndex = " <<mcIndex->size()<< "mother size = "<<mcMotherPID->size()<< endl;
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
	   bool tauMtauE=false; bool tauMtauM=false; bool tauMtauh=false; bool tauhtauM=false;
	   bool muele=false; bool elemu=false;
	   if(index_m1.size()>0)
	     {
	       found_m1=true;
	       if(index_e2.size()>0) { found_e2=true;  tauMtauE=true; }
	       else if (index_e1.size()>0) muele=true;
	       else if (index_m2.size()>0) tauMtauM=true;
	       else if(mcCharge->at(index_m1[0])*mcCharge->at(index_t2[0])<0) tauMtauh=true;
	       
	     }
	   if(index_m2.size()>0)
             {
	       found_m2=true;
               if (index_e1.size()>0) { found_e1=true; tauMtauE=true; }
	       else if (index_m1.size()>0) tauMtauM=true;
	       else if (index_e2.size()>0) elemu=true;
	       else if(mcCharge->at(index_m2[0])*mcCharge->at(index_t1[0])<0)tauhtauM=true;
             }
	   
	   found_mt++;
	   if((tauMtauh==true || tauhtauM==true) && tauMtauM==false && elemu==false && muele==false)
	     {
	       nHToMuTau++;
	       int tauhMom_index=-1; int tauNu_index=-1;
	       if     (tauMtauh==true &&  tauhtauM==false) { tauhMom_index=index_t2[0]; tauNu_index=index_nu2[0]; }
	       else if(tauMtauh==false && tauhtauM==true ) { tauhMom_index=index_t1[0]; tauNu_index=index_nu1[0]; }
	       
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
	       if( mcPt->at(higgsCand[0])<100 ) 
		 { h_muPt_Hpt_1->Fill( mcPt->at(muGenCand[0]), event_weight); h_muEta_Hpt_1->Fill( mcEta->at(muGenCand[0]), event_weight); }
	       if( mcPt->at(higgsCand[0])>100 && mcPt->at(higgsCand[0])<200)  
		 { h_muPt_Hpt_2->Fill( mcPt->at(muGenCand[0]), event_weight); h_muEta_Hpt_2->Fill( mcEta->at(muGenCand[0]), event_weight); }
               if( mcPt->at(higgsCand[0])>200 && mcPt->at(higgsCand[0])<300)  
		 { h_muPt_Hpt_3->Fill( mcPt->at(muGenCand[0]), event_weight); h_muEta_Hpt_3->Fill( mcEta->at(muGenCand[0]), event_weight); }
	       if( mcPt->at(higgsCand[0])>300 && mcPt->at(higgsCand[0])<400)  
		 { h_muPt_Hpt_4->Fill( mcPt->at(muGenCand[0]), event_weight); h_muEta_Hpt_4->Fill( mcEta->at(muGenCand[0]), event_weight); }
	       if( mcPt->at(higgsCand[0])>400 && mcPt->at(higgsCand[0])<500)  
		 { h_muPt_Hpt_5->Fill( mcPt->at(muGenCand[0]), event_weight); h_muEta_Hpt_5->Fill( mcEta->at(muGenCand[0]), event_weight); }
	       if( mcPt->at(higgsCand[0])>500 && mcPt->at(higgsCand[0])<600)  
		 { h_muPt_Hpt_6->Fill( mcPt->at(muGenCand[0]), event_weight); h_muEta_Hpt_6->Fill( mcEta->at(muGenCand[0]), event_weight); }
	       if( mcPt->at(higgsCand[0])>600 )  
		 { h_muPt_Hpt_7->Fill( mcPt->at(muGenCand[0]), event_weight); h_muEta_Hpt_7->Fill( mcEta->at(muGenCand[0]), event_weight); }
	       
	       h_muPt_Hpt_2D->Fill(mcPt->at(muGenCand[0]), mcPt->at(higgsCand[0]), event_weight);
	       h_muPt_Hpt_2D_highPt->Fill(mcPt->at(muGenCand[0]), mcPt->at(higgsCand[0]), event_weight);

	     }
	 }////// gen level closing
       
       plotFill("nMu_reco",  nMu ,  5 , 0 , 5);
       plotFill("nTau_reco", nTau , 5 , 0 , 5);

       ////// reco selection begin
       if(metFilters==0)
	 {
	   //fabs(genWeight) > 0.0 ? event_weight *= genWeight/fabs(genWeight) : event_weight = 0;
	   nMETFiltersPassed+=event_weight;
	   fillHistos(0,event_weight, higgsCand[0]);
	   
	   if(! (HLTEleMuX>>21&1 == 1 ||
		 HLTEleMuX>>60&1 == 1 ||
		 HLTTau>>0&1  == 1      ))continue;
	   fillHistos(1,event_weight, higgsCand[0]);
           nSingleTrgPassed+=event_weight;
	   plotFill("nMu_1",  nMu ,  5 , 0 , 5);
	   plotFill("nTau_1", nTau , 5 , 0 , 5);
	   //plotFill("muCand_size_1", muCand.size() , 5 , 0 , 5);
	   //plotFill("muCand_size_1", muCand.size() , 5 , 0 , 5);
	   
	   


	   muCand = getMuCand(20,2.4);  ///// muons selected 
	   if( (muCand.size()==0) ) continue;
	   nGoodMuonPassed+=event_weight;
	   fillHistos(2,event_weight, higgsCand[0]);
	   //if ( muCand.size()==1)muCand_1++;
	   //if ( muCand.size()==2)muCand_2++;
	   //if ( muCand.size()==3)muCand_3++;
	   h_muCharge_1->Fill(muCharge->at(muCand[0]));
	   plotFill("nMu_2",  nMu ,  5 , 0 , 5);
	   plotFill("nTau_2", nTau , 5 , 0 , 5);
	   
	   plotFill("muCand_size", muCand.size() , 5 , 0 , 5);
	   for (int iMu=0; iMu<muCand.size(); iMu++)
	     {
	       plotFill("muPt_2",  muPt->at(iMu) , 40 , 0 , 200);
	       plotFill("muEta_2", muEta->at(iMu), 30, -6, 6);
	       plotFill("muDz_2",  muDz->at(iMu), 20, -0.5, 0.5);
	       plotFill("muD0_2",  muD0->at(iMu), 24, -0.06, 0.06);
	       plotFill("muonID_2",muIDbit->at(iMu)>>1&1, 4, -2, 2); // muonID
	       //float relMuIso = ( muPFChIso->at(iMu) + max( muPFNeuIso->at(iMu) + muPFPhoIso->at(iMu) - 0.5 *muPFPUIso->at(iMu) , 0.0 )) / (muPt->at(iMu));
	       plotFill("relMuIso_2", muIDbit->at(iMu)>>8&1, 4, -2, 2);
	       plotFill("muCharge_2", muCharge->at(iMu), 8, -2, 2 );
	     }
	   for (int iTau=0; iTau<nTau; iTau++)
	     {
	       plotFill("tauPt_2",  tau_Pt->at(iTau) , 40 , 0 , 200);
	       plotFill("tauEta_2", tau_Eta->at(iTau), 30, -6, 6);
	       plotFill("tauIso_2", tau_IDbits->at(iTau)>>16&1, 4, -2, 2);
	       plotFill("tauDecayMode_2", tau_DecayMode->at(iTau) , 10, 0, 10);
	       plotFill("tauCharge_2", tau_Charge->at(iTau), 8, -2, 2 );

	     }

	   //plotFill("gen_H_pT",  mcPt->at(higgsCand[0]) , 100 , 0 , 1000);
	   

	   //cout<<" muCand.size() :"<<  muCand.size() << endl;
	   int mu_selected=-1;
	   tauCand = getTauCand(30,2.3, muCand[0], mu_selected);
	   //if( tauCand.size()==0 && muCand.size()>1 ) tauCand = getTauCand(30,2.3, muCand[1], mu_selected);
	   //if( tauCand.size()==0 && muCand.size()>2 ) tauCand = getTauCand(30,2.3, muCand[2], mu_selected);
	   
	   

	   if( tauCand.size()>0 ) 
	     {
	       //cout<<" tauCand.size() :"<<  tauCand.size() << endl;
	       //cout<<"mu selected = "<< mu_selected<<endl;
	       plotFill("tauCand_size", tauCand.size() , 5 , 0 , 5);
	       nGoodTauPassed+=event_weight;
	       fillHistos(3,event_weight, higgsCand[0]);
	       h_muCharge_2->Fill(muCharge->at(muCand[0]));
	       h_tauCharge_2->Fill(tau_Charge->at(tauCand[0])); 
	       plotFill("nMu_3",  nMu ,  5 , 0 , 5);
	       plotFill("nTau_3", nTau , 5 , 0 , 5);
	       
	       for (int iTau=0; iTau<tauCand.size(); iTau++)
		 {
		   plotFill("tauPt_3",  tau_Pt->at(iTau) , 40 , 0 , 200);
                   plotFill("tauEta_3", tau_Eta->at(iTau), 30, -6, 6);
		   plotFill("tauIso_3", tau_IDbits->at(iTau)>>16&1, 4, -2, 2);
		   plotFill("tauDecayMode_3", tau_DecayMode->at(iTau) , 10, 0, 10);
		   plotFill("tauCharge_3", tau_Charge->at(iTau),8, -2, 2 );
		   
		 }
	       for (int iMu=0; iMu<muCand.size(); iMu++)
		 {
		   plotFill("muPt_3",  muPt->at(iMu) , 40 , 0 , 200);
		   plotFill("muEta_3", muEta->at(iMu), 30, -6, 6);
		   plotFill("muDz_3",  muDz->at(iMu), 20, -0.5, 0.5);
		   plotFill("muD0_3",  muD0->at(iMu),  24, -0.06, 0.06);
		   plotFill("muonID_3",muIDbit->at(iMu)>>1&1, 4, -2, 2); // muonID
		   float relMuIso = ( muPFChIso->at(iMu) + max( muPFNeuIso->at(iMu) + muPFPhoIso->at(iMu) - 0.5 *muPFPUIso->at(iMu) , 0.0 )) / (muPt->at(iMu));
		   plotFill("relMuIso_3", relMuIso, 10, 0.0, 0.5);
		   plotFill("muCharge_3", muCharge->at(iMu), 8, -2, 2 );
		 }

	       //if ( tauCand.size()==1)tauCand_1++;
	       //if ( tauCand.size()==2)tauCand_2++;
	       //if ( tauCand.size()==3)tauCand_3++;
	       
	       //if(!(  tau_IDbits->at(tauCand[0])>>16&1==1) )continue; // tau isolation
	       fillHistos(8,event_weight, higgsCand[0]);
	       nTauIsoPassed+=event_weight;
	       
	       //if(!( tau_DecayMode->at(tauCand[0])==0 || tau_DecayMode->at(tauCand[0])==1 || tau_DecayMode->at(tauCand[0])==10  )) continue;
	       fillHistos(9,event_weight, higgsCand[0]);
	       nTauDecayModePassed+=event_weight;
	       
	       reco_mu.clear();reco_tau.clear();
	       //if ( muCand.size()>1 || tauCand.size()>1 )std::cout<<"   mu: "<<muCand.size()<<" , tau:"<<tauCand.size()<<endl;
	       for (int iMu=0; iMu<muCand.size(); iMu++)
		 {
		   for (int iTau=0; iTau<tauCand.size(); iTau++)
		     {
		       //double deltaR_ = dR(muCand[iMu], tauCand[iTau]); 
		       if( (muCharge->at(muCand[iMu]))*(tau_Charge->at(tauCand[iTau]))<0 )// && tau_IDbits->at(tauCand[iTau])>>4&1==1 && tau_IDbits->at(tauCand[iTau])>>2&1==1 ) 
			 {
			   reco_mu.push_back(muCand[iMu]);
			   reco_tau.push_back(tauCand[iTau]);
			 }
		     }
		 }
	       
	       //reco_mu.push_back(muCand[0]);
	       //reco_tau.push_back(tauCand[0]);
	       //std::cout<<jentry<<", event:"<<event <<", run:"<<run<<", lumi:"<<lumis<<" :   mu: "<<muCand.size()<<", charge:"<<muCharge->at(muCand[0])<<" , tau:"<<tauCand.size()<<", charge:"<<tau_Charge->at(tauCand[0])<<endl;
	       //std::cout<<jentry<<", event:"<<event <<", run:"<<run<<", lumi:"<<lumis<<", reco_mu :"<<reco_mu.size() <<", reco_tau :"<<reco_tau.size() <<endl; 
	       if (  reco_tau.size() >0 && reco_mu.size() >0 ) 
		 {
		   if(reco_mu.size()>1 || reco_tau.size()>1)
		     std::cout<<jentry<<", event:"<<event <<", run:"<<run<<", lumi:"<<lumis<<", reco_mu :"<<reco_mu.size() <<", reco_tau :"<<reco_tau.size() <<endl;
	   
		   plotFill("nMu_4",  nMu ,  5 , 0 , 5);
		   plotFill("nTau_4", nTau , 5 , 0 , 5);
		   //plotFill("muCand_4",  reco_mu.size() ,  5 , 0 , 5);
		   //plotFill("tauCand_4",  reco_tau.size() ,  5 , 0 , 5);
		   for (int iMu=0; iMu<muCand.size(); iMu++)
		     {
		       plotFill("muPt_4",  muPt->at(iMu) , 40 , 0 , 200);
		       plotFill("muEta_4", muEta->at(iMu), 30, -6, 6);
		       plotFill("muDz_4",  muDz->at(iMu), 20, -0.5, 0.5);
		       plotFill("muD0_4",  muD0->at(iMu), 24, -0.06, 0.06);
		       plotFill("muonID_4",muIDbit->at(iMu)>>1&1, 4, -2, 2); // muonID
		       float relMuIso = ( muPFChIso->at(iMu) + max( muPFNeuIso->at(iMu) + muPFPhoIso->at(iMu) - 0.5 *muPFPUIso->at(iMu) , 0.0 )) / (muPt->at(iMu));
		       plotFill("relMuIso_4", relMuIso, 10, 0, 0.5);
		       plotFill("muCharge_4", muCharge->at(iMu), 8, -2, 2 );
		     }
		   for (int iTau=0; iTau<tauCand.size(); iTau++)
		     {
		       plotFill("tauPt_4",  tau_Pt->at(iTau) , 40 , 0 , 200);
		       plotFill("tauEta_4", tau_Eta->at(iTau), 30, -6, 6);
		       plotFill("tauIso_4", tau_IDbits->at(iTau)>>16&1, 4, -2, 2);
		       plotFill("tauDecayMode_4", tau_DecayMode->at(iTau) , 10, 0, 10);
		       plotFill("tauCharge_4", tau_Charge->at(iTau), 8, -2, 2 );

		     }

		   //std::cout<<"   mu: "<<reco_mu.size()<<", charge:"<<muCharge->at(reco_mu[0])
		   //<<" , tau:"<<reco_tau.size()<<", charge:"<<tau_Charge->at(reco_tau[0])
		   //<<",   charge product = "<< muCharge->at(reco_mu[0])*tau_Charge->at(reco_tau[0])<<endl;
		   h_muCharge_3->Fill(muCharge->at(reco_mu[0]));
		   h_tauCharge_3->Fill(tau_Charge->at(reco_tau[0]));
		   
		   if ( reco_mu.size()==1)muCand_1++;
		   if ( reco_mu.size()==2)muCand_2++; 
		   if ( reco_tau.size()==1)tauCand_1++;
		   if ( reco_tau.size()==2)tauCand_2++; 
		   nGoodMuTauPassed+=event_weight;
		   fillHistos(10,event_weight, higgsCand[0]);
		   if( thirdLeptonVeto()==true )
		     {
		       nPassedThirdLepVeto+=event_weight;
		       fillHistos(11,event_weight, higgsCand[0]);
		       if( passBjetVeto() == true)
			 {
			   nPassedBjetVeto+=event_weight;
			   fillHistos(12,event_weight, higgsCand[0]);
			   double deltaR = dR(reco_mu[0],reco_tau[0]);
			   //if (deltaR<0.5 && tauCand.size() >1)deltaR = dR(muCand[0],tauCand[1]);
			   /* if(deltaR < 0.5 )
			      {
			      //nDeltaRPassed+=event_weight;
			      fillHistos(13,event_weight, higgsCand[0]);
			      if (tau_IDbits->at(tauCand[0])>>2&1==1 && tau_IDbits->at(tauCand[0])>>4&1==1)
			      fillHistos(14,event_weight, higgsCand[0]);
			      }*/
			   if(deltaR > 0.5 )
			     {
			       nDeltaRPassed+=event_weight;
			       fillHistos(15,event_weight, higgsCand[0]);
			       if ( tau_IDbits->at(reco_tau[0])>>4&1==1 && tau_IDbits->at(reco_tau[0])>>3&1==1)
				 {
				   fillHistos(16,event_weight, higgsCand[0]);
				   nTauRejectionPassed+=event_weight;
				   h_nMu->Fill( nMu, event_weight);
				   h_nTau->Fill( nTau, event_weight);
				   
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
   

   map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
   map<string, TH1F*>::const_iterator jMap1 = myMap1->end();
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
   std::cout<<"*******************************************"<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"n higgs found = " << nHiggs<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"n found_mt    = " << found_mt<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"n h->mutau    = " << nHToMuTau<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"n expected    = " << nHiggs*0.65*0.17*2<<std::endl;
   std::cout<<std::setw(20) <<std::right <<"percent change =" << (nHToMuTau-(nHiggs*0.65*0.17*2))*100/(nHiggs*0.65*0.17*2)<<" % "<<std::endl;
   std::cout<<"nMuCand_1="<<muCand_1<< " nMuCand_2="<<muCand_2<< " nMuCand_3="<<muCand_3<<std::endl;
   std::cout<<"nTauCand_1="<<tauCand_1<< " nTauCand_2="<<tauCand_2<< " nTauCand_3="<<tauCand_3<<std::endl;
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

void Analyzer_mutau_updated::BookHistos(const char* file2)
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
  for(int i=0; i<17; i++)
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


void Analyzer_mutau_updated::fillHistos(int histoNumber, double event_weight, int higgs_Index)
{
  
		h_HiggsPt[histoNumber]->Fill(mcPt->at(higgs_Index),event_weight);

}




//---------------------------------------------------                                                                                                                                
// get a electron candiate based on pt eta and isolation                                                                                                                               
//----------------------------------------------------                                                                                                                               

std::vector<int> Analyzer_mutau_updated::getMuCand(double muPtCut, double muEtaCut){
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
       float relMuIso = ( muPFChIso->at(iMu) + max( muPFNeuIso->at(iMu) + muPFPhoIso->at(iMu) - 0.5 *muPFPUIso->at(iMu) , 0.0 )) / (muPt->at(iMu));
       //if( relMuIso < 0.15 ) muonIso = true;
       if( muIDbit->at(iMu)>>8&1==1 ) muonIso = true;
       if(  (HLTEleMuX>>21&1 == 1 && muPt->at(iMu)>28) 
	    || (HLTEleMuX>>60&1 == 1 && muPt->at(iMu)>25) 
	    || (   HLTTau>>0&1  == 1 && muPt->at(iMu)>21 && muPt->at(iMu)<25 && muEta->at(iMu)<2.4 ) 
	    )trigger=true;
       
       if( kinematic==true && trigger==true &&  muonID==true &&  muonIso==true){
	 tmpCand.push_back(iMu);
       }                                                                                      
     }                                                                                       
  return tmpCand;
  
}
std::vector<int> Analyzer_mutau_updated::found_higgs(){ 
  std::vector<int> tmpCand;    tmpCand.clear();   
  bool found_H=false;
  for(int i=0; i<nMC;i++){
    if (fabs(mcPID->at(i))==25 && mcStatus->at(i)==22  )
      {
	tmpCand.push_back(i);
      }
  }
  return tmpCand; 
}
std::vector<int> Analyzer_mutau_updated::found_daughter(){
  std::vector<int> tmpCand;    tmpCand.clear();
  for(int i=0; i<mcDaughterPID->size();i++){
    if (fabs(mcDaughterPID->at(i))==13 || fabs(mcDaughterPID->at(i))<=6 ||  fabs(mcDaughterPID->at(i))>100 ) tmpCand.push_back(i); 
  }
  return tmpCand;
}
std::vector<int> Analyzer_mutau_updated::found_mother(){
  std::vector<int> tmpCand;    tmpCand.clear();
  for(int i=0; i<mcMotherPID->size();i++){
    if (fabs(mcMotherPID->at(i))==15)tmpCand.push_back(i);
  }
  return tmpCand;
}

std::vector<int> Analyzer_mutau_updated::found_muon(){
  std::vector<int> tmpCand;    tmpCand.clear();
  for(int i=0; i<nMC;i++){
    if (fabs(mcPID->at(i))==13  )tmpCand.push_back(i); ///&& mcStatus->at(i)==1 
  }
  return tmpCand;
}
std::vector<int> Analyzer_mutau_updated::found_electron(){
  std::vector<int> tmpCand;    tmpCand.clear();
  for(int i=0; i<nMC;i++){
    if (fabs(mcPID->at(i))==11 )tmpCand.push_back(i); ///&& mcStatus->at(i)==1
  }
  return tmpCand;
}

std::vector<int> Analyzer_mutau_updated::found_tau(){
  std::vector<int> tmpCand;    tmpCand.clear(); 
  for(int i=0; i<nMC;i++){
    if ( fabs(mcPID->at(i)) ==15 )tmpCand.push_back(i);
  }
  return tmpCand;
}
std::vector<int> Analyzer_mutau_updated::found_tauh(){
  std::vector<int> tmpCand;    tmpCand.clear();
  bool found_T=false;
  bool found_d=false;
  for(int i=0; i<nMC;i++){
    if ( fabs(mcPID->at(i))==15  ) found_T=true;
    if ( mcTauDecayMode->at(i)>>2&1==1 || mcTauDecayMode->at(i)>>3&1==1 || mcTauDecayMode->at(i)>>4&1==1 || mcTauDecayMode->at(i)>>5&1==1
	 || mcTauDecayMode->at(i)>>6&1==1 || mcTauDecayMode->at(i)>>7&1==1 || mcTauDecayMode->at(i)>>8&1==1 
	 || mcTauDecayMode->at(i)>>9&1==1 || mcTauDecayMode->at(i)>>10&1==1 || mcTauDecayMode->at(i)>>11&1==1) found_d=true;
    if (found_d==true )tmpCand.push_back(i);
  }
  return tmpCand;
}

std::vector<int> Analyzer_mutau_updated::found_tauNeu(){
  std::vector<int> tmpCand;    tmpCand.clear();
  for(int i=0; i<nMC;i++){
    if (fabs(mcPID->at(i))==16)tmpCand.push_back(i);
  }
  return tmpCand;
}

std::vector<int> Analyzer_mutau_updated::getTauCand(double tauPtCut, double tauEtaCut, int mu_index, int &mu_selected){
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
      if( muCharge->at(mu_index)*(tau_Charge->at(iTau))<0 )charge_selection=true;
      

      if( kinematic==true    
	  && decayModeCut==true   
	  && tauIsolation==true )
	//&& tau_reject==true   )
	//&& charge_selection==true)
	{
	  tmpCand.push_back(iTau);
	  mu_selected = mu_index;
	}                                                           
    }                                                                                       
  return tmpCand;
  
}
std::vector<int> Analyzer_mutau_updated::getASRTauCand(double tauPtCut, double tauEtaCut){
  std::vector<int> tmpCand;
  tmpCand.clear();
  /*  //Loop over taus
  for(int iTau=0;iTau<nTau;iTau++)
    {
      bool kinematic = false;
      bool tauId = false;
      bool decayModeCut = false;
      bool tauIsolation = false;

      if( tauPt->at(iTau) > tauPtCut  && fabs( tauEta->at(iTau))< tauEtaCut && taudz->at(iTau)<0.2 )kinematic = true;
      if( tauByTightMuonRejection3->at(iTau) == 1 && tauByMVA6VLooseElectronRejection->at(iTau) == 1) tauId = true;
      if( (taubyTightIsolationMVArun2017v2DBoldDMwLT2017->at(iTau)!=1 && taubyVLooseIsolationMVArun2017v2DBoldDMwLT2017->at(iTau)==1)) tauIsolation = true;
      if( tauDecayMode->at(iTau)==0 || tauDecayMode->at(iTau)==1 || tauDecayMode->at(iTau)==10) decayModeCut = true;

      if(tauId==true && kinematic==true && tauIsolation==true && decayModeCut==true)
        //if(tauId==true && kinematic==true && decayModeCut==true)
        {
          tmpCand.push_back(iTau);
        }
    }
  return tmpCand;
  */
}


bool Analyzer_mutau_updated::thirdLeptonVeto(){
  
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




//Veto failed if a electron is found that passes Loose Muon ID, Loose Muon Isolation, and elePtcut, and does not overlap the candidate photon within dR of 0.5                                                                                                                                                                    

double Analyzer_mutau_updated::dR(int mu_index, int tau_index)
{
  double deltaeta = abs(muEta->at(mu_index) - tau_Eta->at(tau_index));
  double muonPhi = muPhi->at(mu_index);
  double tauPhi = tau_Phi->at(tau_index);

  double deltaphi = DeltaPhi(muonPhi, tauPhi);
  double deltar = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
  
}

double Analyzer_mutau_updated::delta_R(float phi1, float eta1, float phi2, float eta2)
{
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar   = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
  
}



double Analyzer_mutau_updated::DeltaPhi(double phi1, double phi2)
//Gives the (minimum) separation in phi between the specified phi values
//Must return a positive value
{
  double pi = TMath::Pi();
  double dphi = phi1-phi2;
  if(dphi>pi) dphi = 2.0*pi - dphi;
  if(dphi<= -1*pi) dphi =  2.0*pi +dphi;
  return fabs(dphi);
}

float Analyzer_mutau_updated::TMass_F(float LepPt, float LepPhi , float met, float metPhi) {
    return sqrt(pow(LepPt + met, 2) - pow(LepPt* cos(LepPhi) + met * cos(metPhi), 2) - pow(LepPt * sin(LepPhi) + met * sin(metPhi), 2));
}

float Analyzer_mutau_updated::TotTMass_F(TLorentzVector a, TLorentzVector b, TLorentzVector met) {
  float totalTMass = (a + b+ met).M();
  return totalTMass;
}


float Analyzer_mutau_updated::VisMass_F(TLorentzVector a, TLorentzVector b){
  float visibleMass = (a + b).M();
  return visibleMass;
}

float Analyzer_mutau_updated::pTvecsum_F(float pt1, float pt2, float phi1, float phi2) {
  float pt_vecSum = sqrt( pow(pt1*cos(phi1) + pt2*cos(phi2), 2) + pow(pt1*sin(phi1) + pt2*sin(phi2), 2));
  return pt_vecSum;
}

bool Analyzer_mutau_updated::passBjetVeto()
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

bool Analyzer_mutau_updated::check_jets()
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

double Analyzer_mutau_updated::prefiring_weight(TH2F* prefiring_photon, TH2F* prefiring_jet)
{ 
}

