////Analyzer_mutau.C
//For use with Ntuples made from ggNtuplizer
//Required arguments: 1 is folder containing input files, 2 is output file path, 3 is maxEvents (-1 to run over all events), 4 is reportEvery
//
//To compile using rootcom to an executable named 'analyze':
//$ ./rootcom Analyzer_mutau analyze
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
#define Analyzer_mutau_cxx
#include "Analyzer_mutau.h"
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
  Analyzer_mutau t(argv[1],argv[2]);
  t.Loop(maxEvents,reportEvery, SampleName);
  return 0;
}

void Analyzer_mutau::Loop(Long64_t maxEvents, int reportEvery, string SampleName)
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

   std::vector<int> muCand;
   muCand.clear();
   std::vector<int> tauCand;
   tauCand.clear();

   std::vector<int> higgsCand;
   higgsCand.clear();

   TString sample = TString(SampleName);


   int iphi = 41;
   int ieta = 5;

   int nHiggs = 0;
   //   TFile *f_kfactors = new TFile("kfactors.root");
   //TH1D *ewkCorrection = (TH1D*)f_kfactors->Get("EWKcorr/W");
   //TH1D *NNLOCorrection = (TH1D*)f_kfactors->Get("WJets_LO/inv_pt");

   //std::cout<<"Pont 1" << endl;
   //bool debug=true;
   Float_t Pt_Bins[36]={0.0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 450, 500, 600, 800, 1000};
   TH1F* h_nEvents=new TH1F("nEvents", "nEvents", 5, 0, 5);h_nEvents->Sumw2();
   TH1F* h_Hpt_gen=new TH1F("Higgs_pt_gen", "Higgs_pt_gen", 100, 0, 1000);h_Hpt_gen->Sumw2();
   TH1F* h_dr_gen=new TH1F("dr_gen", "dr_gen", 20, 0, 2.0); h_dr_gen->Sumw2();
   TH1F* h_visMass_gen=new TH1F("Higgs_mass_gen", "Higgs_mass_gen", 20, 0, 200);h_visMass_gen->Sumw2();
   

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
	  if(higgsCand.size() >0)
	    {
	      found_H=true;
	      h_Hpt_gen->Fill(mcPt->at(higgsCand[0]), event_weight);
	      h_visMass_gen->Fill(mcMass->at(higgsCand[0]), event_weight);
	      
	      //double deltaR = delta_R(mcPhi , mcEta, mcPhi, mcEta);
	    }
	  if (found_H==true)nHiggs++;
	  if(higgsCand.size() <0)continue;
	  muCand = getMuCand(20,2.4); tauCand = getTauCand(30,2.3);
	  if(metFilters==0)
	    {
	      fabs(genWeight) > 0.0 ? event_weight *= genWeight/fabs(genWeight) : event_weight = 0;
	      nMETFiltersPassed+=event_weight;
	      //if(HLTEleMuX>>21&1 == 1 ) // Single muon trigger
	      {
		nSingleTrgPassed+=event_weight;
		if(muCand.size() >0)
		  {
		    nGoodMuonPassed+=event_weight;
		    if( tauCand.size() >0 )
		      {
			nGoodTauPassed+=event_weight;
			if( (muCharge->at(muCand[0]))*(tau_Charge->at(tauCand[0])) < 0 ) 
			  {
			    nGoodMuTauPassed+=event_weight;
			    fillHistos(0,event_weight,muCand[0], tauCand[0], higgsCand[0]);
			    if( thirdLeptonVeto()==true )
			      {
				nPassedThirdLepVeto+=event_weight;
				fillHistos(1,event_weight,muCand[0], tauCand[0], higgsCand[0]);
				if( passBjetVeto() == true)
				  {
				    nPassedBjetVeto+=event_weight;
				    fillHistos(2,event_weight,muCand[0], tauCand[0], higgsCand[0]);
				    double deltaR = dR(muCand[0],tauCand[0]);
				    if(deltaR < 0.5 )
                                      {
                                        nDeltaRPassed+=event_weight;
                                        fillHistos(3,event_weight,muCand[0], tauCand[0], higgsCand[0]);
                                        if (tau_IDbits->at(tauCand[0])>>2&1==1 && tau_IDbits->at(tauCand[0])>>4&1==1)
                                          fillHistos(4,event_weight,muCand[0], tauCand[0], higgsCand[0]);
                                      }
                                    if(deltaR > 0.5 )
                                      {
                                        nDeltaRPassed+=event_weight;
                                        fillHistos(5,event_weight,muCand[0], tauCand[0], higgsCand[0]);
                                        if ( tau_IDbits->at(tauCand[0])>>4&1==1 && tau_IDbits->at(tauCand[0])>>3&1==1)
                                          fillHistos(6,event_weight,muCand[0], tauCand[0], higgsCand[0]);

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

void Analyzer_mutau::BookHistos(const char* file2)
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
void Analyzer_mutau::fillHistos(int histoNumber, double event_weight,int muIndex, int tauIndex, int higgs_Index)
{
  
		double dR_mutau = dR(muIndex,tauIndex);
		h_dR[histoNumber]->Fill(dR_mutau,event_weight);

		TLorentzVector myTau; 
		myTau.SetPtEtaPhiE(tau_Pt->at(tauIndex),tau_Eta->at(tauIndex),tau_Phi->at(tauIndex), tau_Energy->at(tauIndex));		
		TLorentzVector myMu; 
		myMu.SetPtEtaPhiE(muPt->at(muIndex),muEta->at(muIndex),muPhi->at(muIndex), muE->at(muIndex));
		double visMass_mutau = VisMass_F(myTau, myMu);
		h_VisibleMass[histoNumber]->Fill(visMass_mutau,event_weight);

		//double HiggsPt = pTvecsum_F(muPt->at(muIndex),tau_Pt->at(tauIndex),muPhi->at(muIndex),tau_Phi->at(tauIndex) );
		//h_HiggsPt[histoNumber]->Fill(HiggsPt,event_weight);
		h_HiggsPt[histoNumber]->Fill(mcPt->at(higgs_Index),event_weight);

}




//---------------------------------------------------                                                                                                                                
// get a electron candiate based on pt eta and isolation                                                                                                                               
//----------------------------------------------------                                                                                                                               

std::vector<int> Analyzer_mutau::getMuCand(double muPtCut, double muEtaCut){
  std::vector<int> tmpCand;
  tmpCand.clear();
  //Loop over muons                                                                     
   for(int iMu=0;iMu<nMu;iMu++)
     {
       bool kinematic = false;
       if( (*muPt)[iMu] > muPtCut  && fabs((*muEta)[iMu])< muEtaCut && fabs(muDz->at(iMu)) < 0.2 && fabs(muD0->at(iMu))<0.045 ) kinematic = true;
       bool muTirgger = false;
       if( (HLTEleMuX>>60&1 == 1 && muPt->at(iMu)>25) || (HLTEleMuX>>20&1 == 1 && muPt->at(iMu)>25) || (HLTEleMuX>>21&1 == 1 && muPt->at(iMu)>28)  || (HLTTau>>0&1 == 1 && muPt->at(iMu)>21 && muPt->at(iMu)<25) )muTirgger=true;
       
       bool muonId =false;
       if( muIDbit->at(iMu)>>1&1==1) muonId =true;
       bool relative_iso = false;
       
       float relMuIso = ( muPFChIso->at(iMu) + max( muPFNeuIso->at(iMu) + muPFPhoIso->at(iMu) - 0.5 *muPFPUIso->at(iMu) , 0.0 )) / (muPt->at(iMu));
       
       if( relMuIso < 0.15 ) relative_iso = true;
       if( kinematic && muTirgger && muonId && relative_iso){
	 tmpCand.push_back(iMu);
       }                                                                                      
     }                                                                                       
  return tmpCand;
  
}
std::vector<int> Analyzer_mutau::found_higgs(){ 
  std::vector<int> tmpCand;    tmpCand.clear();   
  bool found_H=false;
  for(int i=0; i<nMC;i++){
    if (fabs((*mcPID)[i])==25)found_H=true;
    
    if (found_H==true)tmpCand.push_back(i);
  }
  return tmpCand; 
}

std::vector<int> Analyzer_mutau::getTauCand(double tauPtCut, double tauEtaCut){
  std::vector<int> tmpCand;
  tmpCand.clear();
  //Loop over taus      
  for(int iTau=0;iTau<nTau;iTau++)
    {
      bool kinematic = false;
      bool tauId = false;
      bool decayModeCut = false;
      bool tauIsolation = false;

      if( tau_Pt->at(iTau) > tauPtCut  && fabs( tau_Eta->at(iTau))< tauEtaCut && fabs(tau_Charge->at(iTau))==1 && fabs(tau_ZImpact->at(iTau)) < 200 )kinematic = true;
      if(  tau_IDbits->at(iTau)>>4&1==1 && tau_IDbits->at(iTau)>>3&1==1) tauId = true;
      if(  tau_IDbits->at(iTau)>>16&1==1 ) tauIsolation = true;
      if( tau_DecayMode->at(iTau)==0 || tau_DecayMode->at(iTau)==1 || tau_DecayMode->at(iTau)==10 ) decayModeCut = true;
      
      if( kinematic==true && tauIsolation==true && decayModeCut==true)
	//if(tauId==true && kinematic==true && decayModeCut==true)
	{
	  tmpCand.push_back(iTau);
	}                                                           
    }                                                                                       
  return tmpCand;
  
}
std::vector<int> Analyzer_mutau::getASRTauCand(double tauPtCut, double tauEtaCut){
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


bool Analyzer_mutau::thirdLeptonVeto(){
  
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

double Analyzer_mutau::dR(int mu_index, int tau_index)
{
  double deltaeta = abs(muEta->at(mu_index) - tau_Eta->at(tau_index));
  double muonPhi = muPhi->at(mu_index);
  double tauPhi = tau_Phi->at(tau_index);

  double deltaphi = DeltaPhi(muonPhi, tauPhi);
  double deltar = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
  
}

double Analyzer_mutau::delta_R(float phi1, float eta1, float phi2, float eta2)
{
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar   = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
  
}



double Analyzer_mutau::DeltaPhi(double phi1, double phi2)
//Gives the (minimum) separation in phi between the specified phi values
//Must return a positive value
{
  double pi = TMath::Pi();
  double dphi = phi1-phi2;
  if(dphi>pi) dphi = 2.0*pi - dphi;
  if(dphi<= -1*pi) dphi =  2.0*pi +dphi;
  return fabs(dphi);
}

float Analyzer_mutau::TMass_F(float LepPt, float LepPhi , float met, float metPhi) {
    return sqrt(pow(LepPt + met, 2) - pow(LepPt* cos(LepPhi) + met * cos(metPhi), 2) - pow(LepPt * sin(LepPhi) + met * sin(metPhi), 2));
}

float Analyzer_mutau::TotTMass_F(TLorentzVector a, TLorentzVector b, TLorentzVector met) {
  float totalTMass = (a + b+ met).M();
  return totalTMass;
}


float Analyzer_mutau::VisMass_F(TLorentzVector a, TLorentzVector b){
  float visibleMass = (a + b).M();
  return visibleMass;
}

float Analyzer_mutau::pTvecsum_F(float pt1, float pt2, float phi1, float phi2) {
  float pt_vecSum = sqrt( pow(pt1*cos(phi1) + pt2*cos(phi2), 2) + pow(pt1*sin(phi1) + pt2*sin(phi2), 2));
  return pt_vecSum;
}

bool Analyzer_mutau::passBjetVeto()
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

bool Analyzer_mutau::check_jets()
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

double Analyzer_mutau::prefiring_weight(TH2F* prefiring_photon, TH2F* prefiring_jet)
{ 
}
