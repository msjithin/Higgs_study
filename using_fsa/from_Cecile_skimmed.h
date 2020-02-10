//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Feb  4 04:04:43 2020 by ROOT version 6.10/09
// from TTree Ntuple/Expression Ntuple
// found on file: /hdfs/store/user/caillol/SMHTT_legacy_2018_240419/GluGluHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v2/make_ntuples_cfg-15B232FE-F45E-C641-A2A3-E218BC944DE5.root
//////////////////////////////////////////////////////////

#ifndef from_Cecile_skimmed_h
#define from_Cecile_skimmed_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class from_Cecile_skimmed {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         DoubleMediumHPSTau35Pass;
   Float_t         DoubleMediumHPSTau35TightIDPass;
   Float_t         DoubleMediumHPSTau40Pass;
   Float_t         DoubleMediumHPSTau40TightIDPass;
   Float_t         DoubleMediumTau35Pass;
   Float_t         DoubleMediumTau35TightIDPass;
   Float_t         DoubleMediumTau40Pass;
   Float_t         DoubleMediumTau40TightIDPass;
   Float_t         DoubleTightHPSTau35Pass;
   Float_t         DoubleTightHPSTau35TightIDPass;
   Float_t         DoubleTightHPSTau40Pass;
   Float_t         DoubleTightHPSTau40TightIDPass;
   Float_t         DoubleTightTau35Pass;
   Float_t         DoubleTightTau35TightIDPass;
   Float_t         DoubleTightTau40Pass;
   Float_t         DoubleTightTau40TightIDPass;
   Float_t         Ele24LooseHPSTau30Pass;
   Float_t         Ele24LooseHPSTau30TightIDPass;
   Float_t         Ele24LooseTau30Pass;
   Float_t         Ele24LooseTau30TightIDPass;
   Float_t         Ele27WPTightPass;
   Float_t         Ele32WPTightPass;
   Float_t         Ele35WPTightPass;
   Float_t         Ele38WPTightPass;
   Float_t         Ele40WPTightPass;
   Float_t         EmbPtWeight;
   Float_t         Eta;
   Float_t         Flag_BadChargedCandidateFilter;
   Float_t         Flag_BadPFMuonFilter;
   Float_t         Flag_EcalDeadCellTriggerPrimitiveFilter;
   Float_t         Flag_HBHENoiseFilter;
   Float_t         Flag_HBHENoiseIsoFilter;
   Float_t         Flag_badMuons;
   Float_t         Flag_duplicateMuons;
   Float_t         Flag_ecalBadCalibFilter;
   Float_t         Flag_eeBadScFilter;
   Float_t         Flag_globalSuperTightHalo2016Filter;
   Float_t         Flag_globalTightHalo2016Filter;
   Float_t         Flag_goodVertices;
   Float_t         GenWeight;
   Float_t         Ht;
   Float_t         IsoMu24Pass;
   Float_t         IsoMu27Pass;
   Float_t         LT;
   Float_t         Mass;
   Float_t         MassError;
   Float_t         MassErrord1;
   Float_t         MassErrord2;
   Float_t         MassErrord3;
   Float_t         MassErrord4;
   Float_t         Mt;
   Float_t         Mu20LooseHPSTau27Pass;
   Float_t         Mu20LooseHPSTau27TightIDPass;
   Float_t         Mu20LooseTau27Pass;
   Float_t         Mu20LooseTau27TightIDPass;
   Float_t         Mu50Pass;
   Float_t         NUP;
   Float_t         Phi;
   Float_t         Pt;
   Float_t         Rivet_VEta;
   Float_t         Rivet_VPt;
   Float_t         Rivet_errorCode;
   Float_t         Rivet_higgsEta;
   Float_t         Rivet_higgsPt;
   Float_t         Rivet_nJets25;
   Float_t         Rivet_nJets30;
   Float_t         Rivet_p4decay_VEta;
   Float_t         Rivet_p4decay_VPt;
   Float_t         Rivet_prodMode;
   Float_t         Rivet_stage0_cat;
   Float_t         Rivet_stage1_cat_pTjet25GeV;
   Float_t         Rivet_stage1_cat_pTjet30GeV;
   Float_t         Rivet_stage1p1_cat;
   Float_t         VBFDoubleLooseHPSTau20Pass;
   Float_t         VBFDoubleLooseTau20Pass;
   Float_t         VBFDoubleMediumHPSTau20Pass;
   Float_t         VBFDoubleMediumTau20Pass;
   Float_t         VBFDoubleTightHPSTau20Pass;
   Float_t         VBFDoubleTightTau20Pass;
   Float_t         bjetDeepCSVVeto20Loose_2016_DR0p5;
   Float_t         bjetDeepCSVVeto20Loose_2017_DR0p5;
   Float_t         bjetDeepCSVVeto20Loose_2018_DR0p5;
   Float_t         bjetDeepCSVVeto20Medium_2016_DR0;
   Float_t         bjetDeepCSVVeto20Medium_2016_DR0p5;
   Float_t         bjetDeepCSVVeto20Medium_2017_DR0;
   Float_t         bjetDeepCSVVeto20Medium_2017_DR0p5;
   Float_t         bjetDeepCSVVeto20Medium_2018_DR0;
   Float_t         bjetDeepCSVVeto20Medium_2018_DR0p5;
   Float_t         bjetDeepCSVVeto20Tight_2016_DR0p5;
   Float_t         bjetDeepCSVVeto20Tight_2017_DR0p5;
   Float_t         bjetDeepCSVVeto20Tight_2018_DR0p5;
   Float_t         charge;
   Float_t         dielectronVeto;
   Float_t         dimu9ele9Pass;
   Float_t         dimuonVeto;
   Float_t         doubleE25Pass;
   Float_t         doubleE33Pass;
   Float_t         doubleE_23_12Pass;
   Float_t         doubleMuDZminMass3p8Pass;
   Float_t         doubleMuDZminMass8Pass;
   Float_t         doubleMuSingleEPass;
   Float_t         doubleTau35Pass;
   Float_t         doubleTauCmbIso35RegPass;
   Float_t         eVetoHZZPt5;
   Float_t         eVetoZTTp001dxyz;
   Float_t         eVetoZTTp001dxyzR0;
   ULong64_t       evt;
   Float_t         genEta;
   Float_t         genHTT;
   Float_t         genM;
   Float_t         genMass;
   Float_t         genPhi;
   Float_t         genpT;
   Float_t         genpX;
   Float_t         genpY;
   Int_t           isdata;
   Int_t           isembed;
   Float_t         j1csv;
   Float_t         j1csvWoNoisyJets;
   Float_t         j1eta;
   Float_t         j1etaWoNoisyJets;
   Float_t         j1hadronflavor;
   Float_t         j1hadronflavorWoNoisyJets;
   Float_t         j1phi;
   Float_t         j1phiWoNoisyJets;
   Float_t         j1pt;
   Float_t         j1ptWoNoisyJets;
   Float_t         j1ptWoNoisyJets_JetEC2Down;
   Float_t         j1ptWoNoisyJets_JetEC2Up;
   Float_t         j1ptWoNoisyJets_JetEta0to3Down;
   Float_t         j1ptWoNoisyJets_JetEta0to3Up;
   Float_t         j1ptWoNoisyJets_JetEta0to5Down;
   Float_t         j1ptWoNoisyJets_JetEta0to5Up;
   Float_t         j1ptWoNoisyJets_JetEta3to5Down;
   Float_t         j1ptWoNoisyJets_JetEta3to5Up;
   Float_t         j1ptWoNoisyJets_JetRelativeBalDown;
   Float_t         j1ptWoNoisyJets_JetRelativeBalUp;
   Float_t         j1ptWoNoisyJets_JetRelativeSampleDown;
   Float_t         j1ptWoNoisyJets_JetRelativeSampleUp;
   Float_t         j1pt_JetEC2Down;
   Float_t         j1pt_JetEC2Up;
   Float_t         j1pt_JetEta0to3Down;
   Float_t         j1pt_JetEta0to3Up;
   Float_t         j1pt_JetEta0to5Down;
   Float_t         j1pt_JetEta0to5Up;
   Float_t         j1pt_JetEta3to5Down;
   Float_t         j1pt_JetEta3to5Up;
   Float_t         j1pt_JetRelativeBalDown;
   Float_t         j1pt_JetRelativeBalUp;
   Float_t         j1pt_JetRelativeSampleDown;
   Float_t         j1pt_JetRelativeSampleUp;
   Float_t         j2csv;
   Float_t         j2csvWoNoisyJets;
   Float_t         j2eta;
   Float_t         j2etaWoNoisyJets;
   Float_t         j2hadronflavor;
   Float_t         j2hadronflavorWoNoisyJets;
   Float_t         j2phi;
   Float_t         j2phiWoNoisyJets;
   Float_t         j2pt;
   Float_t         j2ptWoNoisyJets;
   Float_t         j2ptWoNoisyJets_JetEC2Down;
   Float_t         j2ptWoNoisyJets_JetEC2Up;
   Float_t         j2ptWoNoisyJets_JetEta0to3Down;
   Float_t         j2ptWoNoisyJets_JetEta0to3Up;
   Float_t         j2ptWoNoisyJets_JetEta0to5Down;
   Float_t         j2ptWoNoisyJets_JetEta0to5Up;
   Float_t         j2ptWoNoisyJets_JetEta3to5Down;
   Float_t         j2ptWoNoisyJets_JetEta3to5Up;
   Float_t         j2ptWoNoisyJets_JetRelativeBalDown;
   Float_t         j2ptWoNoisyJets_JetRelativeBalUp;
   Float_t         j2ptWoNoisyJets_JetRelativeSampleDown;
   Float_t         j2ptWoNoisyJets_JetRelativeSampleUp;
   Float_t         j2pt_JetEC2Down;
   Float_t         j2pt_JetEC2Up;
   Float_t         j2pt_JetEta0to3Down;
   Float_t         j2pt_JetEta0to3Up;
   Float_t         j2pt_JetEta0to5Down;
   Float_t         j2pt_JetEta0to5Up;
   Float_t         j2pt_JetEta3to5Down;
   Float_t         j2pt_JetEta3to5Up;
   Float_t         j2pt_JetRelativeBalDown;
   Float_t         j2pt_JetRelativeBalUp;
   Float_t         j2pt_JetRelativeSampleDown;
   Float_t         j2pt_JetRelativeSampleUp;
   Float_t         jb1eta_2016;
   Float_t         jb1eta_2017;
   Float_t         jb1eta_2018;
   Float_t         jb1hadronflavor_2016;
   Float_t         jb1hadronflavor_2017;
   Float_t         jb1hadronflavor_2018;
   Float_t         jb1phi_2016;
   Float_t         jb1phi_2017;
   Float_t         jb1phi_2018;
   Float_t         jb1pt_2016;
   Float_t         jb1pt_2017;
   Float_t         jb1pt_2018;
   Float_t         jb2eta_2016;
   Float_t         jb2eta_2017;
   Float_t         jb2eta_2018;
   Float_t         jb2hadronflavor_2016;
   Float_t         jb2hadronflavor_2017;
   Float_t         jb2hadronflavor_2018;
   Float_t         jb2phi_2016;
   Float_t         jb2phi_2017;
   Float_t         jb2phi_2018;
   Float_t         jb2pt_2016;
   Float_t         jb2pt_2017;
   Float_t         jb2pt_2018;
   Float_t         jetVeto20;
   Float_t         jetVeto20_JetEnDown;
   Float_t         jetVeto20_JetEnUp;
   Float_t         jetVeto30;
   Float_t         jetVeto30WoNoisyJets_JetEC2Down;
   Float_t         jetVeto30WoNoisyJets_JetEC2Up;
   Float_t         jetVeto30WoNoisyJets_JetEta0to3Down;
   Float_t         jetVeto30WoNoisyJets_JetEta0to3Up;
   Float_t         jetVeto30WoNoisyJets_JetEta0to5Down;
   Float_t         jetVeto30WoNoisyJets_JetEta0to5Up;
   Float_t         jetVeto30WoNoisyJets_JetEta3to5Down;
   Float_t         jetVeto30WoNoisyJets_JetEta3to5Up;
   Float_t         jetVeto30WoNoisyJets_JetRelativeBalDownWoNoisyJets;
   Float_t         jetVeto30WoNoisyJets_JetRelativeBalUpWoNoisyJets;
   Float_t         jetVeto30WoNoisyJets_JetRelativeSampleDown;
   Float_t         jetVeto30WoNoisyJets_JetRelativeSampleUp;
   Float_t         jetVeto30WoNoisyJets_JetTotalDown;
   Float_t         jetVeto30WoNoisyJets_JetTotalUp;
   Float_t         jetVeto30_JetEC2Down;
   Float_t         jetVeto30_JetEC2Up;
   Float_t         jetVeto30_JetEnDown;
   Float_t         jetVeto30_JetEnUp;
   Float_t         jetVeto30_JetEta0to3Down;
   Float_t         jetVeto30_JetEta0to3Up;
   Float_t         jetVeto30_JetEta0to5Down;
   Float_t         jetVeto30_JetEta0to5Up;
   Float_t         jetVeto30_JetEta3to5Down;
   Float_t         jetVeto30_JetEta3to5Up;
   Float_t         jetVeto30_JetRelativeBalDown;
   Float_t         jetVeto30_JetRelativeBalUp;
   Float_t         jetVeto30_JetRelativeSampleDown;
   Float_t         jetVeto30_JetRelativeSampleUp;
   Float_t         jetVeto30_JetTotalDown;
   Float_t         jetVeto30_JetTotalUp;
   Int_t           lumi;
   Float_t         mBestTrackType;
   Float_t         mCharge;
   Float_t         mChi2LocalPosition;
   Float_t         mComesFromHiggs;
   Float_t         mCutBasedIdGlobalHighPt;
   Float_t         mCutBasedIdLoose;
   Float_t         mCutBasedIdMedium;
   Float_t         mCutBasedIdMediumPrompt;
   Float_t         mCutBasedIdTight;
   Float_t         mCutBasedIdTrkHighPt;
   Float_t         mEcalIsoDR03;
   Float_t         mEffectiveArea2011;
   Float_t         mEffectiveArea2012;
   Float_t         mEta;
   Float_t         mEta_MuonEnDown;
   Float_t         mEta_MuonEnUp;
   Float_t         mGenCharge;
   Float_t         mGenDirectPromptTauDecayFinalState;
   Float_t         mGenEnergy;
   Float_t         mGenEta;
   Float_t         mGenIsPrompt;
   Float_t         mGenMotherPdgId;
   Float_t         mGenParticle;
   Float_t         mGenPdgId;
   Float_t         mGenPhi;
   Float_t         mGenPrompt;
   Float_t         mGenPromptFinalState;
   Float_t         mGenPromptTauDecay;
   Float_t         mGenPt;
   Float_t         mGenTauDecay;
   Float_t         mGenVZ;
   Float_t         mGenVtxPVMatch;
   Float_t         mHcalIsoDR03;
   Float_t         mIP3D;
   Float_t         mIP3DErr;
   Float_t         mIsGlobal;
   Float_t         mIsPFMuon;
   Float_t         mIsTracker;
   Float_t         mIsoDB03;
   Float_t         mIsoDB04;
   Float_t         mJetArea;
   Float_t         mJetBtag;
   Float_t         mJetDR;
   Float_t         mJetEtaEtaMoment;
   Float_t         mJetEtaPhiMoment;
   Float_t         mJetEtaPhiSpread;
   Float_t         mJetHadronFlavour;
   Float_t         mJetPFCISVBtag;
   Float_t         mJetPartonFlavour;
   Float_t         mJetPhiPhiMoment;
   Float_t         mJetPt;
   Float_t         mLowestMll;
   Float_t         mMass;
   Float_t         mMatchedStations;
   Float_t         mMatchesIsoMu19Tau20Filter;
   Float_t         mMatchesIsoMu19Tau20Path;
   Float_t         mMatchesIsoMu19Tau20SingleL1Filter;
   Float_t         mMatchesIsoMu19Tau20SingleL1Path;
   Float_t         mMatchesIsoMu20HPSTau27Filter;
   Float_t         mMatchesIsoMu20HPSTau27Path;
   Float_t         mMatchesIsoMu20Tau27Filter;
   Float_t         mMatchesIsoMu20Tau27Path;
   Float_t         mMatchesIsoMu22Filter;
   Float_t         mMatchesIsoMu22Path;
   Float_t         mMatchesIsoMu22eta2p1Filter;
   Float_t         mMatchesIsoMu22eta2p1Path;
   Float_t         mMatchesIsoMu24Filter;
   Float_t         mMatchesIsoMu24Path;
   Float_t         mMatchesIsoMu27Filter;
   Float_t         mMatchesIsoMu27Path;
   Float_t         mMatchesIsoTkMu22Filter;
   Float_t         mMatchesIsoTkMu22Path;
   Float_t         mMatchesIsoTkMu22eta2p1Filter;
   Float_t         mMatchesIsoTkMu22eta2p1Path;
   Float_t         mMiniIsoLoose;
   Float_t         mMiniIsoMedium;
   Float_t         mMiniIsoTight;
   Float_t         mMiniIsoVeryTight;
   Float_t         mMuonHits;
   Float_t         mMvaLoose;
   Float_t         mMvaMedium;
   Float_t         mMvaTight;
   Float_t         mNearestZMass;
   Float_t         mNormTrkChi2;
   Float_t         mNormalizedChi2;
   Float_t         mPFChargedHadronIsoR04;
   Float_t         mPFChargedIso;
   Float_t         mPFIDLoose;
   Float_t         mPFIDMedium;
   Float_t         mPFIDTight;
   Float_t         mPFIsoLoose;
   Float_t         mPFIsoMedium;
   Float_t         mPFIsoTight;
   Float_t         mPFIsoVeryLoose;
   Float_t         mPFIsoVeryTight;
   Float_t         mPFNeutralHadronIsoR04;
   Float_t         mPFNeutralIso;
   Float_t         mPFPUChargedIso;
   Float_t         mPFPhotonIso;
   Float_t         mPFPhotonIsoR04;
   Float_t         mPFPileupIsoR04;
   Float_t         mPVDXY;
   Float_t         mPVDZ;
   Float_t         mPhi;
   Float_t         mPhi_MuonEnDown;
   Float_t         mPhi_MuonEnUp;
   Float_t         mPixHits;
   Float_t         mPt;
   Float_t         mPt_MuonEnDown;
   Float_t         mPt_MuonEnUp;
   Float_t         mRelPFIsoDBDefault;
   Float_t         mRelPFIsoDBDefaultR04;
   Float_t         mRelPFIsoRho;
   Float_t         mRho;
   Float_t         mSIP2D;
   Float_t         mSIP3D;
   Float_t         mSegmentCompatibility;
   Float_t         mSoftCutBasedId;
   Float_t         mTkIsoLoose;
   Float_t         mTkIsoTight;
   Float_t         mTkLayersWithMeasurement;
   Float_t         mTrkIsoDR03;
   Float_t         mTrkKink;
   Int_t           mTypeCode;
   Float_t         mVZ;
   Float_t         mValidFraction;
   Float_t         mZTTGenMatching;
   Float_t         m_t_DR;
   Float_t         m_t_Mass;
   Float_t         m_t_doubleL1IsoTauMatch;
   Float_t         metSig;
   Float_t         metcov00;
   Float_t         metcov01;
   Float_t         metcov10;
   Float_t         metcov11;
   Float_t         mu12e23DZPass;
   Float_t         mu12e23Pass;
   Float_t         mu23e12DZPass;
   Float_t         mu23e12Pass;
   Float_t         mu8diele12DZPass;
   Float_t         mu8diele12Pass;
   Float_t         mu8e23DZPass;
   Float_t         mu8e23Pass;
   Float_t         muGlbIsoVetoPt10;
   Float_t         muVeto5;
   Float_t         muVetoZTTp001dxyz;
   Float_t         muVetoZTTp001dxyzR0;
   Float_t         nTruePU;
   Float_t         npNLO;
   Float_t         numGenJets;
   Float_t         nvtx;
   Float_t         processID;
   Float_t         puppiMetEt;
   Float_t         puppiMetPhi;
   Float_t         pvChi2;
   Float_t         pvDX;
   Float_t         pvDY;
   Float_t         pvDZ;
   Int_t           pvIsFake;
   Int_t           pvIsValid;
   Float_t         pvNormChi2;
   Float_t         pvRho;
   Float_t         pvX;
   Float_t         pvY;
   Float_t         pvZ;
   Float_t         pvndof;
   Float_t         raw_pfMetEt;
   Float_t         raw_pfMetPhi;
   Float_t         recoilDaught;
   Float_t         recoilWithMet;
   Float_t         rho;
   Int_t           run;
   Float_t         singleE25eta2p1TightPass;
   Float_t         singleIsoMu22Pass;
   Float_t         singleIsoMu22eta2p1Pass;
   Float_t         singleIsoTkMu22Pass;
   Float_t         singleIsoTkMu22eta2p1Pass;
   Float_t         singleMu19eta2p1LooseTau20Pass;
   Float_t         singleMu19eta2p1LooseTau20singleL1Pass;
   Float_t         tAgainstElectronLooseMVA6;
   Float_t         tAgainstElectronLooseMVA62018;
   Float_t         tAgainstElectronMVA6Raw;
   Float_t         tAgainstElectronMVA6Raw2018;
   Float_t         tAgainstElectronMVA6category;
   Float_t         tAgainstElectronMVA6category2018;
   Float_t         tAgainstElectronMediumMVA6;
   Float_t         tAgainstElectronMediumMVA62018;
   Float_t         tAgainstElectronTightMVA6;
   Float_t         tAgainstElectronTightMVA62018;
   Float_t         tAgainstElectronVLooseMVA6;
   Float_t         tAgainstElectronVLooseMVA62018;
   Float_t         tAgainstElectronVTightMVA6;
   Float_t         tAgainstElectronVTightMVA62018;
   Float_t         tAgainstMuonLoose3;
   Float_t         tAgainstMuonTight3;
   Float_t         tByCombinedIsolationDeltaBetaCorrRaw3Hits;
   Float_t         tByIsolationMVArun2v1DBdR03oldDMwLTraw;
   Float_t         tByIsolationMVArun2v1DBnewDMwLTraw;
   Float_t         tByIsolationMVArun2v1DBoldDMwLTraw;
   Float_t         tByLooseCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         tByLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByMediumCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         tByMediumIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByMediumIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByMediumIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByPhotonPtSumOutsideSignalCone;
   Float_t         tByTightCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         tByTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         tCharge;
   Float_t         tChargedIsoPtSum;
   Float_t         tChargedIsoPtSumdR03;
   Float_t         tComesFromHiggs;
   Float_t         tDecayMode;
   Float_t         tDecayModeFinding;
   Float_t         tDecayModeFindingNewDMs;
   Float_t         tDeepTau2017v1VSeraw;
   Float_t         tDeepTau2017v1VSjetraw;
   Float_t         tDeepTau2017v1VSmuraw;
   Float_t         tDpfTau2016v0VSallraw;
   Float_t         tDpfTau2016v1VSallraw;
   Float_t         tEta;
   Float_t         tFootprintCorrection;
   Float_t         tFootprintCorrectiondR03;
   Float_t         tGenCharge;
   Float_t         tGenDecayMode;
   Float_t         tGenEnergy;
   Float_t         tGenEta;
   Float_t         tGenJetEta;
   Float_t         tGenJetPt;
   Float_t         tGenMotherEnergy;
   Float_t         tGenMotherEta;
   Float_t         tGenMotherPdgId;
   Float_t         tGenMotherPhi;
   Float_t         tGenMotherPt;
   Float_t         tGenPdgId;
   Float_t         tGenPhi;
   Float_t         tGenPt;
   Float_t         tGenStatus;
   Float_t         tJetArea;
   Float_t         tJetBtag;
   Float_t         tJetDR;
   Float_t         tJetEtaEtaMoment;
   Float_t         tJetEtaPhiMoment;
   Float_t         tJetEtaPhiSpread;
   Float_t         tJetHadronFlavour;
   Float_t         tJetPFCISVBtag;
   Float_t         tJetPartonFlavour;
   Float_t         tJetPhiPhiMoment;
   Float_t         tJetPt;
   Float_t         tL1IsoTauMatch;
   Float_t         tL1IsoTauPt;
   Float_t         tLeadTrackPt;
   Float_t         tLooseDeepTau2017v1VSe;
   Float_t         tLooseDeepTau2017v1VSjet;
   Float_t         tLooseDeepTau2017v1VSmu;
   Float_t         tLowestMll;
   Float_t         tMass;
   Float_t         tMatchesDoubleMediumCombinedIsoTau35Path;
   Float_t         tMatchesDoubleMediumHPSTau35Filter;
   Float_t         tMatchesDoubleMediumHPSTau35Path;
   Float_t         tMatchesDoubleMediumHPSTau40Filter;
   Float_t         tMatchesDoubleMediumHPSTau40Path;
   Float_t         tMatchesDoubleMediumIsoTau35Path;
   Float_t         tMatchesDoubleMediumTau35Filter;
   Float_t         tMatchesDoubleMediumTau35Path;
   Float_t         tMatchesDoubleMediumTau40Filter;
   Float_t         tMatchesDoubleMediumTau40Path;
   Float_t         tMatchesDoubleTightHPSTau35Filter;
   Float_t         tMatchesDoubleTightHPSTau35Path;
   Float_t         tMatchesDoubleTightHPSTau40Filter;
   Float_t         tMatchesDoubleTightHPSTau40Path;
   Float_t         tMatchesDoubleTightTau35Filter;
   Float_t         tMatchesDoubleTightTau35Path;
   Float_t         tMatchesDoubleTightTau40Filter;
   Float_t         tMatchesDoubleTightTau40Path;
   Float_t         tMatchesEle24HPSTau30Filter;
   Float_t         tMatchesEle24HPSTau30Path;
   Float_t         tMatchesEle24Tau30Filter;
   Float_t         tMatchesEle24Tau30Path;
   Float_t         tMatchesIsoMu19Tau20Filter;
   Float_t         tMatchesIsoMu19Tau20Path;
   Float_t         tMatchesIsoMu19Tau20SingleL1Filter;
   Float_t         tMatchesIsoMu19Tau20SingleL1Path;
   Float_t         tMatchesIsoMu20HPSTau27Filter;
   Float_t         tMatchesIsoMu20HPSTau27Path;
   Float_t         tMatchesIsoMu20Tau27Filter;
   Float_t         tMatchesIsoMu20Tau27Path;
   Float_t         tMediumDeepTau2017v1VSe;
   Float_t         tMediumDeepTau2017v1VSjet;
   Float_t         tMediumDeepTau2017v1VSmu;
   Float_t         tNChrgHadrIsolationCands;
   Float_t         tNChrgHadrSignalCands;
   Float_t         tNGammaSignalCands;
   Float_t         tNNeutralHadrSignalCands;
   Float_t         tNSignalCands;
   Float_t         tNearestZMass;
   Float_t         tNeutralIsoPtSum;
   Float_t         tNeutralIsoPtSumWeight;
   Float_t         tNeutralIsoPtSumWeightdR03;
   Float_t         tNeutralIsoPtSumdR03;
   Float_t         tPVDXY;
   Float_t         tPVDZ;
   Float_t         tPhi;
   Float_t         tPhotonPtSumOutsideSignalCone;
   Float_t         tPhotonPtSumOutsideSignalConedR03;
   Float_t         tPt;
   Float_t         tPuCorrPtSum;
   Float_t         tRerunMVArun2v2DBoldDMwLTLoose;
   Float_t         tRerunMVArun2v2DBoldDMwLTMedium;
   Float_t         tRerunMVArun2v2DBoldDMwLTTight;
   Float_t         tRerunMVArun2v2DBoldDMwLTVLoose;
   Float_t         tRerunMVArun2v2DBoldDMwLTVTight;
   Float_t         tRerunMVArun2v2DBoldDMwLTVVLoose;
   Float_t         tRerunMVArun2v2DBoldDMwLTVVTight;
   Float_t         tRerunMVArun2v2DBoldDMwLTraw;
   Float_t         tTightDeepTau2017v1VSe;
   Float_t         tTightDeepTau2017v1VSjet;
   Float_t         tTightDeepTau2017v1VSmu;
   Float_t         tTightDpfTau2016v0VSall;
   Float_t         tTightDpfTau2016v1VSall;
   Float_t         tVLooseDeepTau2017v1VSe;
   Float_t         tVLooseDeepTau2017v1VSjet;
   Float_t         tVLooseDeepTau2017v1VSmu;
   Float_t         tVTightDeepTau2017v1VSe;
   Float_t         tVTightDeepTau2017v1VSjet;
   Float_t         tVTightDeepTau2017v1VSmu;
   Float_t         tVVLooseDeepTau2017v1VSe;
   Float_t         tVVLooseDeepTau2017v1VSjet;
   Float_t         tVVLooseDeepTau2017v1VSmu;
   Float_t         tVVTightDeepTau2017v1VSe;
   Float_t         tVVTightDeepTau2017v1VSjet;
   Float_t         tVVTightDeepTau2017v1VSmu;
   Float_t         tVVVLooseDeepTau2017v1VSe;
   Float_t         tVVVLooseDeepTau2017v1VSjet;
   Float_t         tVVVLooseDeepTau2017v1VSmu;
   Float_t         tVZ;
   Float_t         tZTTGenDR;
   Float_t         tZTTGenEta;
   Float_t         tZTTGenMatching;
   Float_t         tZTTGenPhi;
   Float_t         tZTTGenPt;
   Float_t         tauVetoPt20Loose3HitsVtx;
   Float_t         tauVetoPt20TightMVALTVtx;
   Float_t         topQuarkPt1;
   Float_t         topQuarkPt2;
   Float_t         tripleEPass;
   Float_t         tripleMu10_5_5Pass;
   Float_t         tripleMu12_10_5Pass;
   Float_t         type1_pfMetEt;
   Float_t         type1_pfMetPhi;
   Float_t         type1_pfMet_shiftedPhi_JetEnDown;
   Float_t         type1_pfMet_shiftedPhi_JetEnUp;
   Float_t         type1_pfMet_shiftedPhi_JetEta0to3Down;
   Float_t         type1_pfMet_shiftedPhi_JetEta0to3Up;
   Float_t         type1_pfMet_shiftedPhi_JetEta0to5Down;
   Float_t         type1_pfMet_shiftedPhi_JetEta0to5Up;
   Float_t         type1_pfMet_shiftedPhi_JetEta3to5Down;
   Float_t         type1_pfMet_shiftedPhi_JetEta3to5Up;
   Float_t         type1_pfMet_shiftedPhi_JetRelativeBalDown;
   Float_t         type1_pfMet_shiftedPhi_JetRelativeBalUp;
   Float_t         type1_pfMet_shiftedPhi_JetRelativeSampleDown;
   Float_t         type1_pfMet_shiftedPhi_JetRelativeSampleUp;
   Float_t         type1_pfMet_shiftedPhi_JetResDown;
   Float_t         type1_pfMet_shiftedPhi_JetResUp;
   Float_t         type1_pfMet_shiftedPhi_JetTotalDown;
   Float_t         type1_pfMet_shiftedPhi_JetTotalUp;
   Float_t         type1_pfMet_shiftedPhi_UnclusteredEnDown;
   Float_t         type1_pfMet_shiftedPhi_UnclusteredEnUp;
   Float_t         type1_pfMet_shiftedPt_JetEnDown;
   Float_t         type1_pfMet_shiftedPt_JetEnUp;
   Float_t         type1_pfMet_shiftedPt_JetEta0to3Down;
   Float_t         type1_pfMet_shiftedPt_JetEta0to3Up;
   Float_t         type1_pfMet_shiftedPt_JetEta0to5Down;
   Float_t         type1_pfMet_shiftedPt_JetEta0to5Up;
   Float_t         type1_pfMet_shiftedPt_JetEta3to5Down;
   Float_t         type1_pfMet_shiftedPt_JetEta3to5Up;
   Float_t         type1_pfMet_shiftedPt_JetRelativeBalDown;
   Float_t         type1_pfMet_shiftedPt_JetRelativeBalUp;
   Float_t         type1_pfMet_shiftedPt_JetRelativeSampleDown;
   Float_t         type1_pfMet_shiftedPt_JetRelativeSampleUp;
   Float_t         type1_pfMet_shiftedPt_JetResDown;
   Float_t         type1_pfMet_shiftedPt_JetResUp;
   Float_t         type1_pfMet_shiftedPt_JetTotalDown;
   Float_t         type1_pfMet_shiftedPt_JetTotalUp;
   Float_t         type1_pfMet_shiftedPt_UnclusteredEnDown;
   Float_t         type1_pfMet_shiftedPt_UnclusteredEnUp;
   Float_t         vbfDeta;
   Float_t         vbfJetVeto20;
   Float_t         vbfJetVeto30;
   Float_t         vbfMass;
   Float_t         vbfMassWoNoisyJets;
   Float_t         vbfMassWoNoisyJets_JetEC2Down;
   Float_t         vbfMassWoNoisyJets_JetEC2Up;
   Float_t         vbfMassWoNoisyJets_JetEta0to3Down;
   Float_t         vbfMassWoNoisyJets_JetEta0to3Up;
   Float_t         vbfMassWoNoisyJets_JetEta0to5Down;
   Float_t         vbfMassWoNoisyJets_JetEta0to5Up;
   Float_t         vbfMassWoNoisyJets_JetEta3to5Down;
   Float_t         vbfMassWoNoisyJets_JetEta3to5Up;
   Float_t         vbfMassWoNoisyJets_JetRelativeBalDown;
   Float_t         vbfMassWoNoisyJets_JetRelativeBalUp;
   Float_t         vbfMassWoNoisyJets_JetRelativeSampleDown;
   Float_t         vbfMassWoNoisyJets_JetRelativeSampleUp;
   Float_t         vbfMassWoNoisyJets_JetTotalDown;
   Float_t         vbfMassWoNoisyJets_JetTotalUp;
   Float_t         vbfMass_JetEC2Down;
   Float_t         vbfMass_JetEC2Up;
   Float_t         vbfMass_JetEta0to3Down;
   Float_t         vbfMass_JetEta0to3Up;
   Float_t         vbfMass_JetEta0to5Down;
   Float_t         vbfMass_JetEta0to5Up;
   Float_t         vbfMass_JetEta3to5Down;
   Float_t         vbfMass_JetEta3to5Up;
   Float_t         vbfMass_JetRelativeBalDown;
   Float_t         vbfMass_JetRelativeBalUp;
   Float_t         vbfMass_JetRelativeSampleDown;
   Float_t         vbfMass_JetRelativeSampleUp;
   Float_t         vbfMass_JetTotalDown;
   Float_t         vbfMass_JetTotalUp;
   Float_t         vbfNJets20;
   Float_t         vbfNJets30;
   Float_t         vbfj1eta;
   Float_t         vbfj1pt;
   Float_t         vbfj2eta;
   Float_t         vbfj2pt;
   Float_t         vispX;
   Float_t         vispY;
   Int_t           idx;

   // List of branches
   TBranch        *b_DoubleMediumHPSTau35Pass;   //!
   TBranch        *b_DoubleMediumHPSTau35TightIDPass;   //!
   TBranch        *b_DoubleMediumHPSTau40Pass;   //!
   TBranch        *b_DoubleMediumHPSTau40TightIDPass;   //!
   TBranch        *b_DoubleMediumTau35Pass;   //!
   TBranch        *b_DoubleMediumTau35TightIDPass;   //!
   TBranch        *b_DoubleMediumTau40Pass;   //!
   TBranch        *b_DoubleMediumTau40TightIDPass;   //!
   TBranch        *b_DoubleTightHPSTau35Pass;   //!
   TBranch        *b_DoubleTightHPSTau35TightIDPass;   //!
   TBranch        *b_DoubleTightHPSTau40Pass;   //!
   TBranch        *b_DoubleTightHPSTau40TightIDPass;   //!
   TBranch        *b_DoubleTightTau35Pass;   //!
   TBranch        *b_DoubleTightTau35TightIDPass;   //!
   TBranch        *b_DoubleTightTau40Pass;   //!
   TBranch        *b_DoubleTightTau40TightIDPass;   //!
   TBranch        *b_Ele24LooseHPSTau30Pass;   //!
   TBranch        *b_Ele24LooseHPSTau30TightIDPass;   //!
   TBranch        *b_Ele24LooseTau30Pass;   //!
   TBranch        *b_Ele24LooseTau30TightIDPass;   //!
   TBranch        *b_Ele27WPTightPass;   //!
   TBranch        *b_Ele32WPTightPass;   //!
   TBranch        *b_Ele35WPTightPass;   //!
   TBranch        *b_Ele38WPTightPass;   //!
   TBranch        *b_Ele40WPTightPass;   //!
   TBranch        *b_EmbPtWeight;   //!
   TBranch        *b_Eta;   //!
   TBranch        *b_Flag_BadChargedCandidateFilter;   //!
   TBranch        *b_Flag_BadPFMuonFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_badMuons;   //!
   TBranch        *b_Flag_duplicateMuons;   //!
   TBranch        *b_Flag_ecalBadCalibFilter;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_Flag_globalSuperTightHalo2016Filter;   //!
   TBranch        *b_Flag_globalTightHalo2016Filter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_GenWeight;   //!
   TBranch        *b_Ht;   //!
   TBranch        *b_IsoMu24Pass;   //!
   TBranch        *b_IsoMu27Pass;   //!
   TBranch        *b_LT;   //!
   TBranch        *b_Mass;   //!
   TBranch        *b_MassError;   //!
   TBranch        *b_MassErrord1;   //!
   TBranch        *b_MassErrord2;   //!
   TBranch        *b_MassErrord3;   //!
   TBranch        *b_MassErrord4;   //!
   TBranch        *b_Mt;   //!
   TBranch        *b_Mu20LooseHPSTau27Pass;   //!
   TBranch        *b_Mu20LooseHPSTau27TightIDPass;   //!
   TBranch        *b_Mu20LooseTau27Pass;   //!
   TBranch        *b_Mu20LooseTau27TightIDPass;   //!
   TBranch        *b_Mu50Pass;   //!
   TBranch        *b_NUP;   //!
   TBranch        *b_Phi;   //!
   TBranch        *b_Pt;   //!
   TBranch        *b_Rivet_VEta;   //!
   TBranch        *b_Rivet_VPt;   //!
   TBranch        *b_Rivet_errorCode;   //!
   TBranch        *b_Rivet_higgsEta;   //!
   TBranch        *b_Rivet_higgsPt;   //!
   TBranch        *b_Rivet_nJets25;   //!
   TBranch        *b_Rivet_nJets30;   //!
   TBranch        *b_Rivet_p4decay_VEta;   //!
   TBranch        *b_Rivet_p4decay_VPt;   //!
   TBranch        *b_Rivet_prodMode;   //!
   TBranch        *b_Rivet_stage0_cat;   //!
   TBranch        *b_Rivet_stage1_cat_pTjet25GeV;   //!
   TBranch        *b_Rivet_stage1_cat_pTjet30GeV;   //!
   TBranch        *b_Rivet_stage1p1_cat;   //!
   TBranch        *b_VBFDoubleLooseHPSTau20Pass;   //!
   TBranch        *b_VBFDoubleLooseTau20Pass;   //!
   TBranch        *b_VBFDoubleMediumHPSTau20Pass;   //!
   TBranch        *b_VBFDoubleMediumTau20Pass;   //!
   TBranch        *b_VBFDoubleTightHPSTau20Pass;   //!
   TBranch        *b_VBFDoubleTightTau20Pass;   //!
   TBranch        *b_bjetDeepCSVVeto20Loose_2016_DR0p5;   //!
   TBranch        *b_bjetDeepCSVVeto20Loose_2017_DR0p5;   //!
   TBranch        *b_bjetDeepCSVVeto20Loose_2018_DR0p5;   //!
   TBranch        *b_bjetDeepCSVVeto20Medium_2016_DR0;   //!
   TBranch        *b_bjetDeepCSVVeto20Medium_2016_DR0p5;   //!
   TBranch        *b_bjetDeepCSVVeto20Medium_2017_DR0;   //!
   TBranch        *b_bjetDeepCSVVeto20Medium_2017_DR0p5;   //!
   TBranch        *b_bjetDeepCSVVeto20Medium_2018_DR0;   //!
   TBranch        *b_bjetDeepCSVVeto20Medium_2018_DR0p5;   //!
   TBranch        *b_bjetDeepCSVVeto20Tight_2016_DR0p5;   //!
   TBranch        *b_bjetDeepCSVVeto20Tight_2017_DR0p5;   //!
   TBranch        *b_bjetDeepCSVVeto20Tight_2018_DR0p5;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_dielectronVeto;   //!
   TBranch        *b_dimu9ele9Pass;   //!
   TBranch        *b_dimuonVeto;   //!
   TBranch        *b_doubleE25Pass;   //!
   TBranch        *b_doubleE33Pass;   //!
   TBranch        *b_doubleE_23_12Pass;   //!
   TBranch        *b_doubleMuDZminMass3p8Pass;   //!
   TBranch        *b_doubleMuDZminMass8Pass;   //!
   TBranch        *b_doubleMuSingleEPass;   //!
   TBranch        *b_doubleTau35Pass;   //!
   TBranch        *b_doubleTauCmbIso35RegPass;   //!
   TBranch        *b_eVetoHZZPt5;   //!
   TBranch        *b_eVetoZTTp001dxyz;   //!
   TBranch        *b_eVetoZTTp001dxyzR0;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_genEta;   //!
   TBranch        *b_genHTT;   //!
   TBranch        *b_genM;   //!
   TBranch        *b_genMass;   //!
   TBranch        *b_genPhi;   //!
   TBranch        *b_genpT;   //!
   TBranch        *b_genpX;   //!
   TBranch        *b_genpY;   //!
   TBranch        *b_isdata;   //!
   TBranch        *b_isembed;   //!
   TBranch        *b_j1csv;   //!
   TBranch        *b_j1csvWoNoisyJets;   //!
   TBranch        *b_j1eta;   //!
   TBranch        *b_j1etaWoNoisyJets;   //!
   TBranch        *b_j1hadronflavor;   //!
   TBranch        *b_j1hadronflavorWoNoisyJets;   //!
   TBranch        *b_j1phi;   //!
   TBranch        *b_j1phiWoNoisyJets;   //!
   TBranch        *b_j1pt;   //!
   TBranch        *b_j1ptWoNoisyJets;   //!
   TBranch        *b_j1ptWoNoisyJets_JetEC2Down;   //!
   TBranch        *b_j1ptWoNoisyJets_JetEC2Up;   //!
   TBranch        *b_j1ptWoNoisyJets_JetEta0to3Down;   //!
   TBranch        *b_j1ptWoNoisyJets_JetEta0to3Up;   //!
   TBranch        *b_j1ptWoNoisyJets_JetEta0to5Down;   //!
   TBranch        *b_j1ptWoNoisyJets_JetEta0to5Up;   //!
   TBranch        *b_j1ptWoNoisyJets_JetEta3to5Down;   //!
   TBranch        *b_j1ptWoNoisyJets_JetEta3to5Up;   //!
   TBranch        *b_j1ptWoNoisyJets_JetRelativeBalDown;   //!
   TBranch        *b_j1ptWoNoisyJets_JetRelativeBalUp;   //!
   TBranch        *b_j1ptWoNoisyJets_JetRelativeSampleDown;   //!
   TBranch        *b_j1ptWoNoisyJets_JetRelativeSampleUp;   //!
   TBranch        *b_j1pt_JetEC2Down;   //!
   TBranch        *b_j1pt_JetEC2Up;   //!
   TBranch        *b_j1pt_JetEta0to3Down;   //!
   TBranch        *b_j1pt_JetEta0to3Up;   //!
   TBranch        *b_j1pt_JetEta0to5Down;   //!
   TBranch        *b_j1pt_JetEta0to5Up;   //!
   TBranch        *b_j1pt_JetEta3to5Down;   //!
   TBranch        *b_j1pt_JetEta3to5Up;   //!
   TBranch        *b_j1pt_JetRelativeBalDown;   //!
   TBranch        *b_j1pt_JetRelativeBalUp;   //!
   TBranch        *b_j1pt_JetRelativeSampleDown;   //!
   TBranch        *b_j1pt_JetRelativeSampleUp;   //!
   TBranch        *b_j2csv;   //!
   TBranch        *b_j2csvWoNoisyJets;   //!
   TBranch        *b_j2eta;   //!
   TBranch        *b_j2etaWoNoisyJets;   //!
   TBranch        *b_j2hadronflavor;   //!
   TBranch        *b_j2hadronflavorWoNoisyJets;   //!
   TBranch        *b_j2phi;   //!
   TBranch        *b_j2phiWoNoisyJets;   //!
   TBranch        *b_j2pt;   //!
   TBranch        *b_j2ptWoNoisyJets;   //!
   TBranch        *b_j2ptWoNoisyJets_JetEC2Down;   //!
   TBranch        *b_j2ptWoNoisyJets_JetEC2Up;   //!
   TBranch        *b_j2ptWoNoisyJets_JetEta0to3Down;   //!
   TBranch        *b_j2ptWoNoisyJets_JetEta0to3Up;   //!
   TBranch        *b_j2ptWoNoisyJets_JetEta0to5Down;   //!
   TBranch        *b_j2ptWoNoisyJets_JetEta0to5Up;   //!
   TBranch        *b_j2ptWoNoisyJets_JetEta3to5Down;   //!
   TBranch        *b_j2ptWoNoisyJets_JetEta3to5Up;   //!
   TBranch        *b_j2ptWoNoisyJets_JetRelativeBalDown;   //!
   TBranch        *b_j2ptWoNoisyJets_JetRelativeBalUp;   //!
   TBranch        *b_j2ptWoNoisyJets_JetRelativeSampleDown;   //!
   TBranch        *b_j2ptWoNoisyJets_JetRelativeSampleUp;   //!
   TBranch        *b_j2pt_JetEC2Down;   //!
   TBranch        *b_j2pt_JetEC2Up;   //!
   TBranch        *b_j2pt_JetEta0to3Down;   //!
   TBranch        *b_j2pt_JetEta0to3Up;   //!
   TBranch        *b_j2pt_JetEta0to5Down;   //!
   TBranch        *b_j2pt_JetEta0to5Up;   //!
   TBranch        *b_j2pt_JetEta3to5Down;   //!
   TBranch        *b_j2pt_JetEta3to5Up;   //!
   TBranch        *b_j2pt_JetRelativeBalDown;   //!
   TBranch        *b_j2pt_JetRelativeBalUp;   //!
   TBranch        *b_j2pt_JetRelativeSampleDown;   //!
   TBranch        *b_j2pt_JetRelativeSampleUp;   //!
   TBranch        *b_jb1eta_2016;   //!
   TBranch        *b_jb1eta_2017;   //!
   TBranch        *b_jb1eta_2018;   //!
   TBranch        *b_jb1hadronflavor_2016;   //!
   TBranch        *b_jb1hadronflavor_2017;   //!
   TBranch        *b_jb1hadronflavor_2018;   //!
   TBranch        *b_jb1phi_2016;   //!
   TBranch        *b_jb1phi_2017;   //!
   TBranch        *b_jb1phi_2018;   //!
   TBranch        *b_jb1pt_2016;   //!
   TBranch        *b_jb1pt_2017;   //!
   TBranch        *b_jb1pt_2018;   //!
   TBranch        *b_jb2eta_2016;   //!
   TBranch        *b_jb2eta_2017;   //!
   TBranch        *b_jb2eta_2018;   //!
   TBranch        *b_jb2hadronflavor_2016;   //!
   TBranch        *b_jb2hadronflavor_2017;   //!
   TBranch        *b_jb2hadronflavor_2018;   //!
   TBranch        *b_jb2phi_2016;   //!
   TBranch        *b_jb2phi_2017;   //!
   TBranch        *b_jb2phi_2018;   //!
   TBranch        *b_jb2pt_2016;   //!
   TBranch        *b_jb2pt_2017;   //!
   TBranch        *b_jb2pt_2018;   //!
   TBranch        *b_jetVeto20;   //!
   TBranch        *b_jetVeto20_JetEnDown;   //!
   TBranch        *b_jetVeto20_JetEnUp;   //!
   TBranch        *b_jetVeto30;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetEC2Down;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetEC2Up;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetEta0to3Down;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetEta0to3Up;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetEta0to5Down;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetEta0to5Up;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetEta3to5Down;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetEta3to5Up;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetRelativeBalDownWoNoisyJets;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetRelativeBalUpWoNoisyJets;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetRelativeSampleDown;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetRelativeSampleUp;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetTotalDown;   //!
   TBranch        *b_jetVeto30WoNoisyJets_JetTotalUp;   //!
   TBranch        *b_jetVeto30_JetEC2Down;   //!
   TBranch        *b_jetVeto30_JetEC2Up;   //!
   TBranch        *b_jetVeto30_JetEnDown;   //!
   TBranch        *b_jetVeto30_JetEnUp;   //!
   TBranch        *b_jetVeto30_JetEta0to3Down;   //!
   TBranch        *b_jetVeto30_JetEta0to3Up;   //!
   TBranch        *b_jetVeto30_JetEta0to5Down;   //!
   TBranch        *b_jetVeto30_JetEta0to5Up;   //!
   TBranch        *b_jetVeto30_JetEta3to5Down;   //!
   TBranch        *b_jetVeto30_JetEta3to5Up;   //!
   TBranch        *b_jetVeto30_JetRelativeBalDown;   //!
   TBranch        *b_jetVeto30_JetRelativeBalUp;   //!
   TBranch        *b_jetVeto30_JetRelativeSampleDown;   //!
   TBranch        *b_jetVeto30_JetRelativeSampleUp;   //!
   TBranch        *b_jetVeto30_JetTotalDown;   //!
   TBranch        *b_jetVeto30_JetTotalUp;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_mBestTrackType;   //!
   TBranch        *b_mCharge;   //!
   TBranch        *b_mChi2LocalPosition;   //!
   TBranch        *b_mComesFromHiggs;   //!
   TBranch        *b_mCutBasedIdGlobalHighPt;   //!
   TBranch        *b_mCutBasedIdLoose;   //!
   TBranch        *b_mCutBasedIdMedium;   //!
   TBranch        *b_mCutBasedIdMediumPrompt;   //!
   TBranch        *b_mCutBasedIdTight;   //!
   TBranch        *b_mCutBasedIdTrkHighPt;   //!
   TBranch        *b_mEcalIsoDR03;   //!
   TBranch        *b_mEffectiveArea2011;   //!
   TBranch        *b_mEffectiveArea2012;   //!
   TBranch        *b_mEta;   //!
   TBranch        *b_mEta_MuonEnDown;   //!
   TBranch        *b_mEta_MuonEnUp;   //!
   TBranch        *b_mGenCharge;   //!
   TBranch        *b_mGenDirectPromptTauDecayFinalState;   //!
   TBranch        *b_mGenEnergy;   //!
   TBranch        *b_mGenEta;   //!
   TBranch        *b_mGenIsPrompt;   //!
   TBranch        *b_mGenMotherPdgId;   //!
   TBranch        *b_mGenParticle;   //!
   TBranch        *b_mGenPdgId;   //!
   TBranch        *b_mGenPhi;   //!
   TBranch        *b_mGenPrompt;   //!
   TBranch        *b_mGenPromptFinalState;   //!
   TBranch        *b_mGenPromptTauDecay;   //!
   TBranch        *b_mGenPt;   //!
   TBranch        *b_mGenTauDecay;   //!
   TBranch        *b_mGenVZ;   //!
   TBranch        *b_mGenVtxPVMatch;   //!
   TBranch        *b_mHcalIsoDR03;   //!
   TBranch        *b_mIP3D;   //!
   TBranch        *b_mIP3DErr;   //!
   TBranch        *b_mIsGlobal;   //!
   TBranch        *b_mIsPFMuon;   //!
   TBranch        *b_mIsTracker;   //!
   TBranch        *b_mIsoDB03;   //!
   TBranch        *b_mIsoDB04;   //!
   TBranch        *b_mJetArea;   //!
   TBranch        *b_mJetBtag;   //!
   TBranch        *b_mJetDR;   //!
   TBranch        *b_mJetEtaEtaMoment;   //!
   TBranch        *b_mJetEtaPhiMoment;   //!
   TBranch        *b_mJetEtaPhiSpread;   //!
   TBranch        *b_mJetHadronFlavour;   //!
   TBranch        *b_mJetPFCISVBtag;   //!
   TBranch        *b_mJetPartonFlavour;   //!
   TBranch        *b_mJetPhiPhiMoment;   //!
   TBranch        *b_mJetPt;   //!
   TBranch        *b_mLowestMll;   //!
   TBranch        *b_mMass;   //!
   TBranch        *b_mMatchedStations;   //!
   TBranch        *b_mMatchesIsoMu19Tau20Filter;   //!
   TBranch        *b_mMatchesIsoMu19Tau20Path;   //!
   TBranch        *b_mMatchesIsoMu19Tau20SingleL1Filter;   //!
   TBranch        *b_mMatchesIsoMu19Tau20SingleL1Path;   //!
   TBranch        *b_mMatchesIsoMu20HPSTau27Filter;   //!
   TBranch        *b_mMatchesIsoMu20HPSTau27Path;   //!
   TBranch        *b_mMatchesIsoMu20Tau27Filter;   //!
   TBranch        *b_mMatchesIsoMu20Tau27Path;   //!
   TBranch        *b_mMatchesIsoMu22Filter;   //!
   TBranch        *b_mMatchesIsoMu22Path;   //!
   TBranch        *b_mMatchesIsoMu22eta2p1Filter;   //!
   TBranch        *b_mMatchesIsoMu22eta2p1Path;   //!
   TBranch        *b_mMatchesIsoMu24Filter;   //!
   TBranch        *b_mMatchesIsoMu24Path;   //!
   TBranch        *b_mMatchesIsoMu27Filter;   //!
   TBranch        *b_mMatchesIsoMu27Path;   //!
   TBranch        *b_mMatchesIsoTkMu22Filter;   //!
   TBranch        *b_mMatchesIsoTkMu22Path;   //!
   TBranch        *b_mMatchesIsoTkMu22eta2p1Filter;   //!
   TBranch        *b_mMatchesIsoTkMu22eta2p1Path;   //!
   TBranch        *b_mMiniIsoLoose;   //!
   TBranch        *b_mMiniIsoMedium;   //!
   TBranch        *b_mMiniIsoTight;   //!
   TBranch        *b_mMiniIsoVeryTight;   //!
   TBranch        *b_mMuonHits;   //!
   TBranch        *b_mMvaLoose;   //!
   TBranch        *b_mMvaMedium;   //!
   TBranch        *b_mMvaTight;   //!
   TBranch        *b_mNearestZMass;   //!
   TBranch        *b_mNormTrkChi2;   //!
   TBranch        *b_mNormalizedChi2;   //!
   TBranch        *b_mPFChargedHadronIsoR04;   //!
   TBranch        *b_mPFChargedIso;   //!
   TBranch        *b_mPFIDLoose;   //!
   TBranch        *b_mPFIDMedium;   //!
   TBranch        *b_mPFIDTight;   //!
   TBranch        *b_mPFIsoLoose;   //!
   TBranch        *b_mPFIsoMedium;   //!
   TBranch        *b_mPFIsoTight;   //!
   TBranch        *b_mPFIsoVeryLoose;   //!
   TBranch        *b_mPFIsoVeryTight;   //!
   TBranch        *b_mPFNeutralHadronIsoR04;   //!
   TBranch        *b_mPFNeutralIso;   //!
   TBranch        *b_mPFPUChargedIso;   //!
   TBranch        *b_mPFPhotonIso;   //!
   TBranch        *b_mPFPhotonIsoR04;   //!
   TBranch        *b_mPFPileupIsoR04;   //!
   TBranch        *b_mPVDXY;   //!
   TBranch        *b_mPVDZ;   //!
   TBranch        *b_mPhi;   //!
   TBranch        *b_mPhi_MuonEnDown;   //!
   TBranch        *b_mPhi_MuonEnUp;   //!
   TBranch        *b_mPixHits;   //!
   TBranch        *b_mPt;   //!
   TBranch        *b_mPt_MuonEnDown;   //!
   TBranch        *b_mPt_MuonEnUp;   //!
   TBranch        *b_mRelPFIsoDBDefault;   //!
   TBranch        *b_mRelPFIsoDBDefaultR04;   //!
   TBranch        *b_mRelPFIsoRho;   //!
   TBranch        *b_mRho;   //!
   TBranch        *b_mSIP2D;   //!
   TBranch        *b_mSIP3D;   //!
   TBranch        *b_mSegmentCompatibility;   //!
   TBranch        *b_mSoftCutBasedId;   //!
   TBranch        *b_mTkIsoLoose;   //!
   TBranch        *b_mTkIsoTight;   //!
   TBranch        *b_mTkLayersWithMeasurement;   //!
   TBranch        *b_mTrkIsoDR03;   //!
   TBranch        *b_mTrkKink;   //!
   TBranch        *b_mTypeCode;   //!
   TBranch        *b_mVZ;   //!
   TBranch        *b_mValidFraction;   //!
   TBranch        *b_mZTTGenMatching;   //!
   TBranch        *b_m_t_DR;   //!
   TBranch        *b_m_t_Mass;   //!
   TBranch        *b_m_t_doubleL1IsoTauMatch;   //!
   TBranch        *b_metSig;   //!
   TBranch        *b_metcov00;   //!
   TBranch        *b_metcov01;   //!
   TBranch        *b_metcov10;   //!
   TBranch        *b_metcov11;   //!
   TBranch        *b_mu12e23DZPass;   //!
   TBranch        *b_mu12e23Pass;   //!
   TBranch        *b_mu23e12DZPass;   //!
   TBranch        *b_mu23e12Pass;   //!
   TBranch        *b_mu8diele12DZPass;   //!
   TBranch        *b_mu8diele12Pass;   //!
   TBranch        *b_mu8e23DZPass;   //!
   TBranch        *b_mu8e23Pass;   //!
   TBranch        *b_muGlbIsoVetoPt10;   //!
   TBranch        *b_muVeto5;   //!
   TBranch        *b_muVetoZTTp001dxyz;   //!
   TBranch        *b_muVetoZTTp001dxyzR0;   //!
   TBranch        *b_nTruePU;   //!
   TBranch        *b_npNLO;   //!
   TBranch        *b_numGenJets;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_processID;   //!
   TBranch        *b_puppiMetEt;   //!
   TBranch        *b_puppiMetPhi;   //!
   TBranch        *b_pvChi2;   //!
   TBranch        *b_pvDX;   //!
   TBranch        *b_pvDY;   //!
   TBranch        *b_pvDZ;   //!
   TBranch        *b_pvIsFake;   //!
   TBranch        *b_pvIsValid;   //!
   TBranch        *b_pvNormChi2;   //!
   TBranch        *b_pvRho;   //!
   TBranch        *b_pvX;   //!
   TBranch        *b_pvY;   //!
   TBranch        *b_pvZ;   //!
   TBranch        *b_pvndof;   //!
   TBranch        *b_raw_pfMetEt;   //!
   TBranch        *b_raw_pfMetPhi;   //!
   TBranch        *b_recoilDaught;   //!
   TBranch        *b_recoilWithMet;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_run;   //!
   TBranch        *b_singleE25eta2p1TightPass;   //!
   TBranch        *b_singleIsoMu22Pass;   //!
   TBranch        *b_singleIsoMu22eta2p1Pass;   //!
   TBranch        *b_singleIsoTkMu22Pass;   //!
   TBranch        *b_singleIsoTkMu22eta2p1Pass;   //!
   TBranch        *b_singleMu19eta2p1LooseTau20Pass;   //!
   TBranch        *b_singleMu19eta2p1LooseTau20singleL1Pass;   //!
   TBranch        *b_tAgainstElectronLooseMVA6;   //!
   TBranch        *b_tAgainstElectronLooseMVA62018;   //!
   TBranch        *b_tAgainstElectronMVA6Raw;   //!
   TBranch        *b_tAgainstElectronMVA6Raw2018;   //!
   TBranch        *b_tAgainstElectronMVA6category;   //!
   TBranch        *b_tAgainstElectronMVA6category2018;   //!
   TBranch        *b_tAgainstElectronMediumMVA6;   //!
   TBranch        *b_tAgainstElectronMediumMVA62018;   //!
   TBranch        *b_tAgainstElectronTightMVA6;   //!
   TBranch        *b_tAgainstElectronTightMVA62018;   //!
   TBranch        *b_tAgainstElectronVLooseMVA6;   //!
   TBranch        *b_tAgainstElectronVLooseMVA62018;   //!
   TBranch        *b_tAgainstElectronVTightMVA6;   //!
   TBranch        *b_tAgainstElectronVTightMVA62018;   //!
   TBranch        *b_tAgainstMuonLoose3;   //!
   TBranch        *b_tAgainstMuonTight3;   //!
   TBranch        *b_tByCombinedIsolationDeltaBetaCorrRaw3Hits;   //!
   TBranch        *b_tByIsolationMVArun2v1DBdR03oldDMwLTraw;   //!
   TBranch        *b_tByIsolationMVArun2v1DBnewDMwLTraw;   //!
   TBranch        *b_tByIsolationMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_tByLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_tByTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tByTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tCharge;   //!
   TBranch        *b_tChargedIsoPtSum;   //!
   TBranch        *b_tChargedIsoPtSumdR03;   //!
   TBranch        *b_tComesFromHiggs;   //!
   TBranch        *b_tDecayMode;   //!
   TBranch        *b_tDecayModeFinding;   //!
   TBranch        *b_tDecayModeFindingNewDMs;   //!
   TBranch        *b_tDeepTau2017v1VSeraw;   //!
   TBranch        *b_tDeepTau2017v1VSjetraw;   //!
   TBranch        *b_tDeepTau2017v1VSmuraw;   //!
   TBranch        *b_tDpfTau2016v0VSallraw;   //!
   TBranch        *b_tDpfTau2016v1VSallraw;   //!
   TBranch        *b_tEta;   //!
   TBranch        *b_tFootprintCorrection;   //!
   TBranch        *b_tFootprintCorrectiondR03;   //!
   TBranch        *b_tGenCharge;   //!
   TBranch        *b_tGenDecayMode;   //!
   TBranch        *b_tGenEnergy;   //!
   TBranch        *b_tGenEta;   //!
   TBranch        *b_tGenJetEta;   //!
   TBranch        *b_tGenJetPt;   //!
   TBranch        *b_tGenMotherEnergy;   //!
   TBranch        *b_tGenMotherEta;   //!
   TBranch        *b_tGenMotherPdgId;   //!
   TBranch        *b_tGenMotherPhi;   //!
   TBranch        *b_tGenMotherPt;   //!
   TBranch        *b_tGenPdgId;   //!
   TBranch        *b_tGenPhi;   //!
   TBranch        *b_tGenPt;   //!
   TBranch        *b_tGenStatus;   //!
   TBranch        *b_tJetArea;   //!
   TBranch        *b_tJetBtag;   //!
   TBranch        *b_tJetDR;   //!
   TBranch        *b_tJetEtaEtaMoment;   //!
   TBranch        *b_tJetEtaPhiMoment;   //!
   TBranch        *b_tJetEtaPhiSpread;   //!
   TBranch        *b_tJetHadronFlavour;   //!
   TBranch        *b_tJetPFCISVBtag;   //!
   TBranch        *b_tJetPartonFlavour;   //!
   TBranch        *b_tJetPhiPhiMoment;   //!
   TBranch        *b_tJetPt;   //!
   TBranch        *b_tL1IsoTauMatch;   //!
   TBranch        *b_tL1IsoTauPt;   //!
   TBranch        *b_tLeadTrackPt;   //!
   TBranch        *b_tLooseDeepTau2017v1VSe;   //!
   TBranch        *b_tLooseDeepTau2017v1VSjet;   //!
   TBranch        *b_tLooseDeepTau2017v1VSmu;   //!
   TBranch        *b_tLowestMll;   //!
   TBranch        *b_tMass;   //!
   TBranch        *b_tMatchesDoubleMediumCombinedIsoTau35Path;   //!
   TBranch        *b_tMatchesDoubleMediumHPSTau35Filter;   //!
   TBranch        *b_tMatchesDoubleMediumHPSTau35Path;   //!
   TBranch        *b_tMatchesDoubleMediumHPSTau40Filter;   //!
   TBranch        *b_tMatchesDoubleMediumHPSTau40Path;   //!
   TBranch        *b_tMatchesDoubleMediumIsoTau35Path;   //!
   TBranch        *b_tMatchesDoubleMediumTau35Filter;   //!
   TBranch        *b_tMatchesDoubleMediumTau35Path;   //!
   TBranch        *b_tMatchesDoubleMediumTau40Filter;   //!
   TBranch        *b_tMatchesDoubleMediumTau40Path;   //!
   TBranch        *b_tMatchesDoubleTightHPSTau35Filter;   //!
   TBranch        *b_tMatchesDoubleTightHPSTau35Path;   //!
   TBranch        *b_tMatchesDoubleTightHPSTau40Filter;   //!
   TBranch        *b_tMatchesDoubleTightHPSTau40Path;   //!
   TBranch        *b_tMatchesDoubleTightTau35Filter;   //!
   TBranch        *b_tMatchesDoubleTightTau35Path;   //!
   TBranch        *b_tMatchesDoubleTightTau40Filter;   //!
   TBranch        *b_tMatchesDoubleTightTau40Path;   //!
   TBranch        *b_tMatchesEle24HPSTau30Filter;   //!
   TBranch        *b_tMatchesEle24HPSTau30Path;   //!
   TBranch        *b_tMatchesEle24Tau30Filter;   //!
   TBranch        *b_tMatchesEle24Tau30Path;   //!
   TBranch        *b_tMatchesIsoMu19Tau20Filter;   //!
   TBranch        *b_tMatchesIsoMu19Tau20Path;   //!
   TBranch        *b_tMatchesIsoMu19Tau20SingleL1Filter;   //!
   TBranch        *b_tMatchesIsoMu19Tau20SingleL1Path;   //!
   TBranch        *b_tMatchesIsoMu20HPSTau27Filter;   //!
   TBranch        *b_tMatchesIsoMu20HPSTau27Path;   //!
   TBranch        *b_tMatchesIsoMu20Tau27Filter;   //!
   TBranch        *b_tMatchesIsoMu20Tau27Path;   //!
   TBranch        *b_tMediumDeepTau2017v1VSe;   //!
   TBranch        *b_tMediumDeepTau2017v1VSjet;   //!
   TBranch        *b_tMediumDeepTau2017v1VSmu;   //!
   TBranch        *b_tNChrgHadrIsolationCands;   //!
   TBranch        *b_tNChrgHadrSignalCands;   //!
   TBranch        *b_tNGammaSignalCands;   //!
   TBranch        *b_tNNeutralHadrSignalCands;   //!
   TBranch        *b_tNSignalCands;   //!
   TBranch        *b_tNearestZMass;   //!
   TBranch        *b_tNeutralIsoPtSum;   //!
   TBranch        *b_tNeutralIsoPtSumWeight;   //!
   TBranch        *b_tNeutralIsoPtSumWeightdR03;   //!
   TBranch        *b_tNeutralIsoPtSumdR03;   //!
   TBranch        *b_tPVDXY;   //!
   TBranch        *b_tPVDZ;   //!
   TBranch        *b_tPhi;   //!
   TBranch        *b_tPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_tPhotonPtSumOutsideSignalConedR03;   //!
   TBranch        *b_tPt;   //!
   TBranch        *b_tPuCorrPtSum;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTLoose;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTMedium;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTTight;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTVLoose;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTVTight;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTVVLoose;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTVVTight;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTraw;   //!
   TBranch        *b_tTightDeepTau2017v1VSe;   //!
   TBranch        *b_tTightDeepTau2017v1VSjet;   //!
   TBranch        *b_tTightDeepTau2017v1VSmu;   //!
   TBranch        *b_tTightDpfTau2016v0VSall;   //!
   TBranch        *b_tTightDpfTau2016v1VSall;   //!
   TBranch        *b_tVLooseDeepTau2017v1VSe;   //!
   TBranch        *b_tVLooseDeepTau2017v1VSjet;   //!
   TBranch        *b_tVLooseDeepTau2017v1VSmu;   //!
   TBranch        *b_tVTightDeepTau2017v1VSe;   //!
   TBranch        *b_tVTightDeepTau2017v1VSjet;   //!
   TBranch        *b_tVTightDeepTau2017v1VSmu;   //!
   TBranch        *b_tVVLooseDeepTau2017v1VSe;   //!
   TBranch        *b_tVVLooseDeepTau2017v1VSjet;   //!
   TBranch        *b_tVVLooseDeepTau2017v1VSmu;   //!
   TBranch        *b_tVVTightDeepTau2017v1VSe;   //!
   TBranch        *b_tVVTightDeepTau2017v1VSjet;   //!
   TBranch        *b_tVVTightDeepTau2017v1VSmu;   //!
   TBranch        *b_tVVVLooseDeepTau2017v1VSe;   //!
   TBranch        *b_tVVVLooseDeepTau2017v1VSjet;   //!
   TBranch        *b_tVVVLooseDeepTau2017v1VSmu;   //!
   TBranch        *b_tVZ;   //!
   TBranch        *b_tZTTGenDR;   //!
   TBranch        *b_tZTTGenEta;   //!
   TBranch        *b_tZTTGenMatching;   //!
   TBranch        *b_tZTTGenPhi;   //!
   TBranch        *b_tZTTGenPt;   //!
   TBranch        *b_tauVetoPt20Loose3HitsVtx;   //!
   TBranch        *b_tauVetoPt20TightMVALTVtx;   //!
   TBranch        *b_topQuarkPt1;   //!
   TBranch        *b_topQuarkPt2;   //!
   TBranch        *b_tripleEPass;   //!
   TBranch        *b_tripleMu10_5_5Pass;   //!
   TBranch        *b_tripleMu12_10_5Pass;   //!
   TBranch        *b_type1_pfMetEt;   //!
   TBranch        *b_type1_pfMetPhi;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEta0to3Down;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEta0to3Up;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEta0to5Down;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEta0to5Up;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEta3to5Down;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEta3to5Up;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetRelativeBalDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetRelativeBalUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetRelativeSampleDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetRelativeSampleUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetResDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetResUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetTotalDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetTotalUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_UnclusteredEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_UnclusteredEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEta0to3Down;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEta0to3Up;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEta0to5Down;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEta0to5Up;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEta3to5Down;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEta3to5Up;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetRelativeBalDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetRelativeBalUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetRelativeSampleDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetRelativeSampleUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetResDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetResUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetTotalDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetTotalUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_UnclusteredEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_UnclusteredEnUp;   //!
   TBranch        *b_vbfDeta;   //!
   TBranch        *b_vbfJetVeto20;   //!
   TBranch        *b_vbfJetVeto30;   //!
   TBranch        *b_vbfMass;   //!
   TBranch        *b_vbfMassWoNoisyJets;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetEC2Down;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetEC2Up;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetEta0to3Down;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetEta0to3Up;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetEta0to5Down;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetEta0to5Up;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetEta3to5Down;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetEta3to5Up;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetRelativeBalDown;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetRelativeBalUp;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetRelativeSampleDown;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetRelativeSampleUp;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetTotalDown;   //!
   TBranch        *b_vbfMassWoNoisyJets_JetTotalUp;   //!
   TBranch        *b_vbfMass_JetEC2Down;   //!
   TBranch        *b_vbfMass_JetEC2Up;   //!
   TBranch        *b_vbfMass_JetEta0to3Down;   //!
   TBranch        *b_vbfMass_JetEta0to3Up;   //!
   TBranch        *b_vbfMass_JetEta0to5Down;   //!
   TBranch        *b_vbfMass_JetEta0to5Up;   //!
   TBranch        *b_vbfMass_JetEta3to5Down;   //!
   TBranch        *b_vbfMass_JetEta3to5Up;   //!
   TBranch        *b_vbfMass_JetRelativeBalDown;   //!
   TBranch        *b_vbfMass_JetRelativeBalUp;   //!
   TBranch        *b_vbfMass_JetRelativeSampleDown;   //!
   TBranch        *b_vbfMass_JetRelativeSampleUp;   //!
   TBranch        *b_vbfMass_JetTotalDown;   //!
   TBranch        *b_vbfMass_JetTotalUp;   //!
   TBranch        *b_vbfNJets20;   //!
   TBranch        *b_vbfNJets30;   //!
   TBranch        *b_vbfj1eta;   //!
   TBranch        *b_vbfj1pt;   //!
   TBranch        *b_vbfj2eta;   //!
   TBranch        *b_vbfj2pt;   //!
   TBranch        *b_vispX;   //!
   TBranch        *b_vispY;   //!
   TBranch        *b_idx;   //!

   from_Cecile_skimmed(TTree *tree=0);
   virtual ~from_Cecile_skimmed();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef from_Cecile_skimmed_cxx
from_Cecile_skimmed::from_Cecile_skimmed(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/hdfs/store/user/caillol/SMHTT_legacy_2018_240419/GluGluHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v2/make_ntuples_cfg-15B232FE-F45E-C641-A2A3-E218BC944DE5.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/hdfs/store/user/caillol/SMHTT_legacy_2018_240419/GluGluHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v2/make_ntuples_cfg-15B232FE-F45E-C641-A2A3-E218BC944DE5.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/hdfs/store/user/caillol/SMHTT_legacy_2018_240419/GluGluHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v2/make_ntuples_cfg-15B232FE-F45E-C641-A2A3-E218BC944DE5.root:/mt/final");
      dir->GetObject("Ntuple",tree);

   }
   Init(tree);
}

from_Cecile_skimmed::~from_Cecile_skimmed()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t from_Cecile_skimmed::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t from_Cecile_skimmed::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void from_Cecile_skimmed::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("DoubleMediumHPSTau35Pass", &DoubleMediumHPSTau35Pass, &b_DoubleMediumHPSTau35Pass);
   fChain->SetBranchAddress("DoubleMediumHPSTau35TightIDPass", &DoubleMediumHPSTau35TightIDPass, &b_DoubleMediumHPSTau35TightIDPass);
   fChain->SetBranchAddress("DoubleMediumHPSTau40Pass", &DoubleMediumHPSTau40Pass, &b_DoubleMediumHPSTau40Pass);
   fChain->SetBranchAddress("DoubleMediumHPSTau40TightIDPass", &DoubleMediumHPSTau40TightIDPass, &b_DoubleMediumHPSTau40TightIDPass);
   fChain->SetBranchAddress("DoubleMediumTau35Pass", &DoubleMediumTau35Pass, &b_DoubleMediumTau35Pass);
   fChain->SetBranchAddress("DoubleMediumTau35TightIDPass", &DoubleMediumTau35TightIDPass, &b_DoubleMediumTau35TightIDPass);
   fChain->SetBranchAddress("DoubleMediumTau40Pass", &DoubleMediumTau40Pass, &b_DoubleMediumTau40Pass);
   fChain->SetBranchAddress("DoubleMediumTau40TightIDPass", &DoubleMediumTau40TightIDPass, &b_DoubleMediumTau40TightIDPass);
   fChain->SetBranchAddress("DoubleTightHPSTau35Pass", &DoubleTightHPSTau35Pass, &b_DoubleTightHPSTau35Pass);
   fChain->SetBranchAddress("DoubleTightHPSTau35TightIDPass", &DoubleTightHPSTau35TightIDPass, &b_DoubleTightHPSTau35TightIDPass);
   fChain->SetBranchAddress("DoubleTightHPSTau40Pass", &DoubleTightHPSTau40Pass, &b_DoubleTightHPSTau40Pass);
   fChain->SetBranchAddress("DoubleTightHPSTau40TightIDPass", &DoubleTightHPSTau40TightIDPass, &b_DoubleTightHPSTau40TightIDPass);
   fChain->SetBranchAddress("DoubleTightTau35Pass", &DoubleTightTau35Pass, &b_DoubleTightTau35Pass);
   fChain->SetBranchAddress("DoubleTightTau35TightIDPass", &DoubleTightTau35TightIDPass, &b_DoubleTightTau35TightIDPass);
   fChain->SetBranchAddress("DoubleTightTau40Pass", &DoubleTightTau40Pass, &b_DoubleTightTau40Pass);
   fChain->SetBranchAddress("DoubleTightTau40TightIDPass", &DoubleTightTau40TightIDPass, &b_DoubleTightTau40TightIDPass);
   fChain->SetBranchAddress("Ele24LooseHPSTau30Pass", &Ele24LooseHPSTau30Pass, &b_Ele24LooseHPSTau30Pass);
   fChain->SetBranchAddress("Ele24LooseHPSTau30TightIDPass", &Ele24LooseHPSTau30TightIDPass, &b_Ele24LooseHPSTau30TightIDPass);
   fChain->SetBranchAddress("Ele24LooseTau30Pass", &Ele24LooseTau30Pass, &b_Ele24LooseTau30Pass);
   fChain->SetBranchAddress("Ele24LooseTau30TightIDPass", &Ele24LooseTau30TightIDPass, &b_Ele24LooseTau30TightIDPass);
   fChain->SetBranchAddress("Ele27WPTightPass", &Ele27WPTightPass, &b_Ele27WPTightPass);
   fChain->SetBranchAddress("Ele32WPTightPass", &Ele32WPTightPass, &b_Ele32WPTightPass);
   fChain->SetBranchAddress("Ele35WPTightPass", &Ele35WPTightPass, &b_Ele35WPTightPass);
   fChain->SetBranchAddress("Ele38WPTightPass", &Ele38WPTightPass, &b_Ele38WPTightPass);
   fChain->SetBranchAddress("Ele40WPTightPass", &Ele40WPTightPass, &b_Ele40WPTightPass);
   fChain->SetBranchAddress("EmbPtWeight", &EmbPtWeight, &b_EmbPtWeight);
   fChain->SetBranchAddress("Eta", &Eta, &b_Eta);
   fChain->SetBranchAddress("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter, &b_Flag_BadChargedCandidateFilter);
   fChain->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, &b_Flag_BadPFMuonFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("Flag_badMuons", &Flag_badMuons, &b_Flag_badMuons);
   fChain->SetBranchAddress("Flag_duplicateMuons", &Flag_duplicateMuons, &b_Flag_duplicateMuons);
   fChain->SetBranchAddress("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter, &b_Flag_ecalBadCalibFilter);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter, &b_Flag_globalSuperTightHalo2016Filter);
   fChain->SetBranchAddress("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter, &b_Flag_globalTightHalo2016Filter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("GenWeight", &GenWeight, &b_GenWeight);
   fChain->SetBranchAddress("Ht", &Ht, &b_Ht);
   fChain->SetBranchAddress("IsoMu24Pass", &IsoMu24Pass, &b_IsoMu24Pass);
   fChain->SetBranchAddress("IsoMu27Pass", &IsoMu27Pass, &b_IsoMu27Pass);
   fChain->SetBranchAddress("LT", &LT, &b_LT);
   fChain->SetBranchAddress("Mass", &Mass, &b_Mass);
   fChain->SetBranchAddress("MassError", &MassError, &b_MassError);
   fChain->SetBranchAddress("MassErrord1", &MassErrord1, &b_MassErrord1);
   fChain->SetBranchAddress("MassErrord2", &MassErrord2, &b_MassErrord2);
   fChain->SetBranchAddress("MassErrord3", &MassErrord3, &b_MassErrord3);
   fChain->SetBranchAddress("MassErrord4", &MassErrord4, &b_MassErrord4);
   fChain->SetBranchAddress("Mt", &Mt, &b_Mt);
   fChain->SetBranchAddress("Mu20LooseHPSTau27Pass", &Mu20LooseHPSTau27Pass, &b_Mu20LooseHPSTau27Pass);
   fChain->SetBranchAddress("Mu20LooseHPSTau27TightIDPass", &Mu20LooseHPSTau27TightIDPass, &b_Mu20LooseHPSTau27TightIDPass);
   fChain->SetBranchAddress("Mu20LooseTau27Pass", &Mu20LooseTau27Pass, &b_Mu20LooseTau27Pass);
   fChain->SetBranchAddress("Mu20LooseTau27TightIDPass", &Mu20LooseTau27TightIDPass, &b_Mu20LooseTau27TightIDPass);
   fChain->SetBranchAddress("Mu50Pass", &Mu50Pass, &b_Mu50Pass);
   fChain->SetBranchAddress("NUP", &NUP, &b_NUP);
   fChain->SetBranchAddress("Phi", &Phi, &b_Phi);
   fChain->SetBranchAddress("Pt", &Pt, &b_Pt);
   fChain->SetBranchAddress("Rivet_VEta", &Rivet_VEta, &b_Rivet_VEta);
   fChain->SetBranchAddress("Rivet_VPt", &Rivet_VPt, &b_Rivet_VPt);
   fChain->SetBranchAddress("Rivet_errorCode", &Rivet_errorCode, &b_Rivet_errorCode);
   fChain->SetBranchAddress("Rivet_higgsEta", &Rivet_higgsEta, &b_Rivet_higgsEta);
   fChain->SetBranchAddress("Rivet_higgsPt", &Rivet_higgsPt, &b_Rivet_higgsPt);
   fChain->SetBranchAddress("Rivet_nJets25", &Rivet_nJets25, &b_Rivet_nJets25);
   fChain->SetBranchAddress("Rivet_nJets30", &Rivet_nJets30, &b_Rivet_nJets30);
   fChain->SetBranchAddress("Rivet_p4decay_VEta", &Rivet_p4decay_VEta, &b_Rivet_p4decay_VEta);
   fChain->SetBranchAddress("Rivet_p4decay_VPt", &Rivet_p4decay_VPt, &b_Rivet_p4decay_VPt);
   fChain->SetBranchAddress("Rivet_prodMode", &Rivet_prodMode, &b_Rivet_prodMode);
   fChain->SetBranchAddress("Rivet_stage0_cat", &Rivet_stage0_cat, &b_Rivet_stage0_cat);
   fChain->SetBranchAddress("Rivet_stage1_cat_pTjet25GeV", &Rivet_stage1_cat_pTjet25GeV, &b_Rivet_stage1_cat_pTjet25GeV);
   fChain->SetBranchAddress("Rivet_stage1_cat_pTjet30GeV", &Rivet_stage1_cat_pTjet30GeV, &b_Rivet_stage1_cat_pTjet30GeV);
   fChain->SetBranchAddress("Rivet_stage1p1_cat", &Rivet_stage1p1_cat, &b_Rivet_stage1p1_cat);
   fChain->SetBranchAddress("VBFDoubleLooseHPSTau20Pass", &VBFDoubleLooseHPSTau20Pass, &b_VBFDoubleLooseHPSTau20Pass);
   fChain->SetBranchAddress("VBFDoubleLooseTau20Pass", &VBFDoubleLooseTau20Pass, &b_VBFDoubleLooseTau20Pass);
   fChain->SetBranchAddress("VBFDoubleMediumHPSTau20Pass", &VBFDoubleMediumHPSTau20Pass, &b_VBFDoubleMediumHPSTau20Pass);
   fChain->SetBranchAddress("VBFDoubleMediumTau20Pass", &VBFDoubleMediumTau20Pass, &b_VBFDoubleMediumTau20Pass);
   fChain->SetBranchAddress("VBFDoubleTightHPSTau20Pass", &VBFDoubleTightHPSTau20Pass, &b_VBFDoubleTightHPSTau20Pass);
   fChain->SetBranchAddress("VBFDoubleTightTau20Pass", &VBFDoubleTightTau20Pass, &b_VBFDoubleTightTau20Pass);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Loose_2016_DR0p5", &bjetDeepCSVVeto20Loose_2016_DR0p5, &b_bjetDeepCSVVeto20Loose_2016_DR0p5);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Loose_2017_DR0p5", &bjetDeepCSVVeto20Loose_2017_DR0p5, &b_bjetDeepCSVVeto20Loose_2017_DR0p5);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Loose_2018_DR0p5", &bjetDeepCSVVeto20Loose_2018_DR0p5, &b_bjetDeepCSVVeto20Loose_2018_DR0p5);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Medium_2016_DR0", &bjetDeepCSVVeto20Medium_2016_DR0, &b_bjetDeepCSVVeto20Medium_2016_DR0);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Medium_2016_DR0p5", &bjetDeepCSVVeto20Medium_2016_DR0p5, &b_bjetDeepCSVVeto20Medium_2016_DR0p5);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Medium_2017_DR0", &bjetDeepCSVVeto20Medium_2017_DR0, &b_bjetDeepCSVVeto20Medium_2017_DR0);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Medium_2017_DR0p5", &bjetDeepCSVVeto20Medium_2017_DR0p5, &b_bjetDeepCSVVeto20Medium_2017_DR0p5);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Medium_2018_DR0", &bjetDeepCSVVeto20Medium_2018_DR0, &b_bjetDeepCSVVeto20Medium_2018_DR0);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Medium_2018_DR0p5", &bjetDeepCSVVeto20Medium_2018_DR0p5, &b_bjetDeepCSVVeto20Medium_2018_DR0p5);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Tight_2016_DR0p5", &bjetDeepCSVVeto20Tight_2016_DR0p5, &b_bjetDeepCSVVeto20Tight_2016_DR0p5);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Tight_2017_DR0p5", &bjetDeepCSVVeto20Tight_2017_DR0p5, &b_bjetDeepCSVVeto20Tight_2017_DR0p5);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Tight_2018_DR0p5", &bjetDeepCSVVeto20Tight_2018_DR0p5, &b_bjetDeepCSVVeto20Tight_2018_DR0p5);
   fChain->SetBranchAddress("charge", &charge, &b_charge);
   fChain->SetBranchAddress("dielectronVeto", &dielectronVeto, &b_dielectronVeto);
   fChain->SetBranchAddress("dimu9ele9Pass", &dimu9ele9Pass, &b_dimu9ele9Pass);
   fChain->SetBranchAddress("dimuonVeto", &dimuonVeto, &b_dimuonVeto);
   fChain->SetBranchAddress("doubleE25Pass", &doubleE25Pass, &b_doubleE25Pass);
   fChain->SetBranchAddress("doubleE33Pass", &doubleE33Pass, &b_doubleE33Pass);
   fChain->SetBranchAddress("doubleE_23_12Pass", &doubleE_23_12Pass, &b_doubleE_23_12Pass);
   fChain->SetBranchAddress("doubleMuDZminMass3p8Pass", &doubleMuDZminMass3p8Pass, &b_doubleMuDZminMass3p8Pass);
   fChain->SetBranchAddress("doubleMuDZminMass8Pass", &doubleMuDZminMass8Pass, &b_doubleMuDZminMass8Pass);
   fChain->SetBranchAddress("doubleMuSingleEPass", &doubleMuSingleEPass, &b_doubleMuSingleEPass);
   fChain->SetBranchAddress("doubleTau35Pass", &doubleTau35Pass, &b_doubleTau35Pass);
   fChain->SetBranchAddress("doubleTauCmbIso35RegPass", &doubleTauCmbIso35RegPass, &b_doubleTauCmbIso35RegPass);
   fChain->SetBranchAddress("eVetoHZZPt5", &eVetoHZZPt5, &b_eVetoHZZPt5);
   fChain->SetBranchAddress("eVetoZTTp001dxyz", &eVetoZTTp001dxyz, &b_eVetoZTTp001dxyz);
   fChain->SetBranchAddress("eVetoZTTp001dxyzR0", &eVetoZTTp001dxyzR0, &b_eVetoZTTp001dxyzR0);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("genEta", &genEta, &b_genEta);
   fChain->SetBranchAddress("genHTT", &genHTT, &b_genHTT);
   fChain->SetBranchAddress("genM", &genM, &b_genM);
   fChain->SetBranchAddress("genMass", &genMass, &b_genMass);
   fChain->SetBranchAddress("genPhi", &genPhi, &b_genPhi);
   fChain->SetBranchAddress("genpT", &genpT, &b_genpT);
   fChain->SetBranchAddress("genpX", &genpX, &b_genpX);
   fChain->SetBranchAddress("genpY", &genpY, &b_genpY);
   fChain->SetBranchAddress("isdata", &isdata, &b_isdata);
   fChain->SetBranchAddress("isembed", &isembed, &b_isembed);
   fChain->SetBranchAddress("j1csv", &j1csv, &b_j1csv);
   fChain->SetBranchAddress("j1csvWoNoisyJets", &j1csvWoNoisyJets, &b_j1csvWoNoisyJets);
   fChain->SetBranchAddress("j1eta", &j1eta, &b_j1eta);
   fChain->SetBranchAddress("j1etaWoNoisyJets", &j1etaWoNoisyJets, &b_j1etaWoNoisyJets);
   fChain->SetBranchAddress("j1hadronflavor", &j1hadronflavor, &b_j1hadronflavor);
   fChain->SetBranchAddress("j1hadronflavorWoNoisyJets", &j1hadronflavorWoNoisyJets, &b_j1hadronflavorWoNoisyJets);
   fChain->SetBranchAddress("j1phi", &j1phi, &b_j1phi);
   fChain->SetBranchAddress("j1phiWoNoisyJets", &j1phiWoNoisyJets, &b_j1phiWoNoisyJets);
   fChain->SetBranchAddress("j1pt", &j1pt, &b_j1pt);
   fChain->SetBranchAddress("j1ptWoNoisyJets", &j1ptWoNoisyJets, &b_j1ptWoNoisyJets);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetEC2Down", &j1ptWoNoisyJets_JetEC2Down, &b_j1ptWoNoisyJets_JetEC2Down);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetEC2Up", &j1ptWoNoisyJets_JetEC2Up, &b_j1ptWoNoisyJets_JetEC2Up);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetEta0to3Down", &j1ptWoNoisyJets_JetEta0to3Down, &b_j1ptWoNoisyJets_JetEta0to3Down);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetEta0to3Up", &j1ptWoNoisyJets_JetEta0to3Up, &b_j1ptWoNoisyJets_JetEta0to3Up);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetEta0to5Down", &j1ptWoNoisyJets_JetEta0to5Down, &b_j1ptWoNoisyJets_JetEta0to5Down);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetEta0to5Up", &j1ptWoNoisyJets_JetEta0to5Up, &b_j1ptWoNoisyJets_JetEta0to5Up);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetEta3to5Down", &j1ptWoNoisyJets_JetEta3to5Down, &b_j1ptWoNoisyJets_JetEta3to5Down);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetEta3to5Up", &j1ptWoNoisyJets_JetEta3to5Up, &b_j1ptWoNoisyJets_JetEta3to5Up);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetRelativeBalDown", &j1ptWoNoisyJets_JetRelativeBalDown, &b_j1ptWoNoisyJets_JetRelativeBalDown);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetRelativeBalUp", &j1ptWoNoisyJets_JetRelativeBalUp, &b_j1ptWoNoisyJets_JetRelativeBalUp);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetRelativeSampleDown", &j1ptWoNoisyJets_JetRelativeSampleDown, &b_j1ptWoNoisyJets_JetRelativeSampleDown);
   fChain->SetBranchAddress("j1ptWoNoisyJets_JetRelativeSampleUp", &j1ptWoNoisyJets_JetRelativeSampleUp, &b_j1ptWoNoisyJets_JetRelativeSampleUp);
   fChain->SetBranchAddress("j1pt_JetEC2Down", &j1pt_JetEC2Down, &b_j1pt_JetEC2Down);
   fChain->SetBranchAddress("j1pt_JetEC2Up", &j1pt_JetEC2Up, &b_j1pt_JetEC2Up);
   fChain->SetBranchAddress("j1pt_JetEta0to3Down", &j1pt_JetEta0to3Down, &b_j1pt_JetEta0to3Down);
   fChain->SetBranchAddress("j1pt_JetEta0to3Up", &j1pt_JetEta0to3Up, &b_j1pt_JetEta0to3Up);
   fChain->SetBranchAddress("j1pt_JetEta0to5Down", &j1pt_JetEta0to5Down, &b_j1pt_JetEta0to5Down);
   fChain->SetBranchAddress("j1pt_JetEta0to5Up", &j1pt_JetEta0to5Up, &b_j1pt_JetEta0to5Up);
   fChain->SetBranchAddress("j1pt_JetEta3to5Down", &j1pt_JetEta3to5Down, &b_j1pt_JetEta3to5Down);
   fChain->SetBranchAddress("j1pt_JetEta3to5Up", &j1pt_JetEta3to5Up, &b_j1pt_JetEta3to5Up);
   fChain->SetBranchAddress("j1pt_JetRelativeBalDown", &j1pt_JetRelativeBalDown, &b_j1pt_JetRelativeBalDown);
   fChain->SetBranchAddress("j1pt_JetRelativeBalUp", &j1pt_JetRelativeBalUp, &b_j1pt_JetRelativeBalUp);
   fChain->SetBranchAddress("j1pt_JetRelativeSampleDown", &j1pt_JetRelativeSampleDown, &b_j1pt_JetRelativeSampleDown);
   fChain->SetBranchAddress("j1pt_JetRelativeSampleUp", &j1pt_JetRelativeSampleUp, &b_j1pt_JetRelativeSampleUp);
   fChain->SetBranchAddress("j2csv", &j2csv, &b_j2csv);
   fChain->SetBranchAddress("j2csvWoNoisyJets", &j2csvWoNoisyJets, &b_j2csvWoNoisyJets);
   fChain->SetBranchAddress("j2eta", &j2eta, &b_j2eta);
   fChain->SetBranchAddress("j2etaWoNoisyJets", &j2etaWoNoisyJets, &b_j2etaWoNoisyJets);
   fChain->SetBranchAddress("j2hadronflavor", &j2hadronflavor, &b_j2hadronflavor);
   fChain->SetBranchAddress("j2hadronflavorWoNoisyJets", &j2hadronflavorWoNoisyJets, &b_j2hadronflavorWoNoisyJets);
   fChain->SetBranchAddress("j2phi", &j2phi, &b_j2phi);
   fChain->SetBranchAddress("j2phiWoNoisyJets", &j2phiWoNoisyJets, &b_j2phiWoNoisyJets);
   fChain->SetBranchAddress("j2pt", &j2pt, &b_j2pt);
   fChain->SetBranchAddress("j2ptWoNoisyJets", &j2ptWoNoisyJets, &b_j2ptWoNoisyJets);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetEC2Down", &j2ptWoNoisyJets_JetEC2Down, &b_j2ptWoNoisyJets_JetEC2Down);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetEC2Up", &j2ptWoNoisyJets_JetEC2Up, &b_j2ptWoNoisyJets_JetEC2Up);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetEta0to3Down", &j2ptWoNoisyJets_JetEta0to3Down, &b_j2ptWoNoisyJets_JetEta0to3Down);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetEta0to3Up", &j2ptWoNoisyJets_JetEta0to3Up, &b_j2ptWoNoisyJets_JetEta0to3Up);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetEta0to5Down", &j2ptWoNoisyJets_JetEta0to5Down, &b_j2ptWoNoisyJets_JetEta0to5Down);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetEta0to5Up", &j2ptWoNoisyJets_JetEta0to5Up, &b_j2ptWoNoisyJets_JetEta0to5Up);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetEta3to5Down", &j2ptWoNoisyJets_JetEta3to5Down, &b_j2ptWoNoisyJets_JetEta3to5Down);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetEta3to5Up", &j2ptWoNoisyJets_JetEta3to5Up, &b_j2ptWoNoisyJets_JetEta3to5Up);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetRelativeBalDown", &j2ptWoNoisyJets_JetRelativeBalDown, &b_j2ptWoNoisyJets_JetRelativeBalDown);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetRelativeBalUp", &j2ptWoNoisyJets_JetRelativeBalUp, &b_j2ptWoNoisyJets_JetRelativeBalUp);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetRelativeSampleDown", &j2ptWoNoisyJets_JetRelativeSampleDown, &b_j2ptWoNoisyJets_JetRelativeSampleDown);
   fChain->SetBranchAddress("j2ptWoNoisyJets_JetRelativeSampleUp", &j2ptWoNoisyJets_JetRelativeSampleUp, &b_j2ptWoNoisyJets_JetRelativeSampleUp);
   fChain->SetBranchAddress("j2pt_JetEC2Down", &j2pt_JetEC2Down, &b_j2pt_JetEC2Down);
   fChain->SetBranchAddress("j2pt_JetEC2Up", &j2pt_JetEC2Up, &b_j2pt_JetEC2Up);
   fChain->SetBranchAddress("j2pt_JetEta0to3Down", &j2pt_JetEta0to3Down, &b_j2pt_JetEta0to3Down);
   fChain->SetBranchAddress("j2pt_JetEta0to3Up", &j2pt_JetEta0to3Up, &b_j2pt_JetEta0to3Up);
   fChain->SetBranchAddress("j2pt_JetEta0to5Down", &j2pt_JetEta0to5Down, &b_j2pt_JetEta0to5Down);
   fChain->SetBranchAddress("j2pt_JetEta0to5Up", &j2pt_JetEta0to5Up, &b_j2pt_JetEta0to5Up);
   fChain->SetBranchAddress("j2pt_JetEta3to5Down", &j2pt_JetEta3to5Down, &b_j2pt_JetEta3to5Down);
   fChain->SetBranchAddress("j2pt_JetEta3to5Up", &j2pt_JetEta3to5Up, &b_j2pt_JetEta3to5Up);
   fChain->SetBranchAddress("j2pt_JetRelativeBalDown", &j2pt_JetRelativeBalDown, &b_j2pt_JetRelativeBalDown);
   fChain->SetBranchAddress("j2pt_JetRelativeBalUp", &j2pt_JetRelativeBalUp, &b_j2pt_JetRelativeBalUp);
   fChain->SetBranchAddress("j2pt_JetRelativeSampleDown", &j2pt_JetRelativeSampleDown, &b_j2pt_JetRelativeSampleDown);
   fChain->SetBranchAddress("j2pt_JetRelativeSampleUp", &j2pt_JetRelativeSampleUp, &b_j2pt_JetRelativeSampleUp);
   fChain->SetBranchAddress("jb1eta_2016", &jb1eta_2016, &b_jb1eta_2016);
   fChain->SetBranchAddress("jb1eta_2017", &jb1eta_2017, &b_jb1eta_2017);
   fChain->SetBranchAddress("jb1eta_2018", &jb1eta_2018, &b_jb1eta_2018);
   fChain->SetBranchAddress("jb1hadronflavor_2016", &jb1hadronflavor_2016, &b_jb1hadronflavor_2016);
   fChain->SetBranchAddress("jb1hadronflavor_2017", &jb1hadronflavor_2017, &b_jb1hadronflavor_2017);
   fChain->SetBranchAddress("jb1hadronflavor_2018", &jb1hadronflavor_2018, &b_jb1hadronflavor_2018);
   fChain->SetBranchAddress("jb1phi_2016", &jb1phi_2016, &b_jb1phi_2016);
   fChain->SetBranchAddress("jb1phi_2017", &jb1phi_2017, &b_jb1phi_2017);
   fChain->SetBranchAddress("jb1phi_2018", &jb1phi_2018, &b_jb1phi_2018);
   fChain->SetBranchAddress("jb1pt_2016", &jb1pt_2016, &b_jb1pt_2016);
   fChain->SetBranchAddress("jb1pt_2017", &jb1pt_2017, &b_jb1pt_2017);
   fChain->SetBranchAddress("jb1pt_2018", &jb1pt_2018, &b_jb1pt_2018);
   fChain->SetBranchAddress("jb2eta_2016", &jb2eta_2016, &b_jb2eta_2016);
   fChain->SetBranchAddress("jb2eta_2017", &jb2eta_2017, &b_jb2eta_2017);
   fChain->SetBranchAddress("jb2eta_2018", &jb2eta_2018, &b_jb2eta_2018);
   fChain->SetBranchAddress("jb2hadronflavor_2016", &jb2hadronflavor_2016, &b_jb2hadronflavor_2016);
   fChain->SetBranchAddress("jb2hadronflavor_2017", &jb2hadronflavor_2017, &b_jb2hadronflavor_2017);
   fChain->SetBranchAddress("jb2hadronflavor_2018", &jb2hadronflavor_2018, &b_jb2hadronflavor_2018);
   fChain->SetBranchAddress("jb2phi_2016", &jb2phi_2016, &b_jb2phi_2016);
   fChain->SetBranchAddress("jb2phi_2017", &jb2phi_2017, &b_jb2phi_2017);
   fChain->SetBranchAddress("jb2phi_2018", &jb2phi_2018, &b_jb2phi_2018);
   fChain->SetBranchAddress("jb2pt_2016", &jb2pt_2016, &b_jb2pt_2016);
   fChain->SetBranchAddress("jb2pt_2017", &jb2pt_2017, &b_jb2pt_2017);
   fChain->SetBranchAddress("jb2pt_2018", &jb2pt_2018, &b_jb2pt_2018);
   fChain->SetBranchAddress("jetVeto20", &jetVeto20, &b_jetVeto20);
   fChain->SetBranchAddress("jetVeto20_JetEnDown", &jetVeto20_JetEnDown, &b_jetVeto20_JetEnDown);
   fChain->SetBranchAddress("jetVeto20_JetEnUp", &jetVeto20_JetEnUp, &b_jetVeto20_JetEnUp);
   fChain->SetBranchAddress("jetVeto30", &jetVeto30, &b_jetVeto30);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetEC2Down", &jetVeto30WoNoisyJets_JetEC2Down, &b_jetVeto30WoNoisyJets_JetEC2Down);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetEC2Up", &jetVeto30WoNoisyJets_JetEC2Up, &b_jetVeto30WoNoisyJets_JetEC2Up);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetEta0to3Down", &jetVeto30WoNoisyJets_JetEta0to3Down, &b_jetVeto30WoNoisyJets_JetEta0to3Down);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetEta0to3Up", &jetVeto30WoNoisyJets_JetEta0to3Up, &b_jetVeto30WoNoisyJets_JetEta0to3Up);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetEta0to5Down", &jetVeto30WoNoisyJets_JetEta0to5Down, &b_jetVeto30WoNoisyJets_JetEta0to5Down);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetEta0to5Up", &jetVeto30WoNoisyJets_JetEta0to5Up, &b_jetVeto30WoNoisyJets_JetEta0to5Up);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetEta3to5Down", &jetVeto30WoNoisyJets_JetEta3to5Down, &b_jetVeto30WoNoisyJets_JetEta3to5Down);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetEta3to5Up", &jetVeto30WoNoisyJets_JetEta3to5Up, &b_jetVeto30WoNoisyJets_JetEta3to5Up);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetRelativeBalDownWoNoisyJets", &jetVeto30WoNoisyJets_JetRelativeBalDownWoNoisyJets, &b_jetVeto30WoNoisyJets_JetRelativeBalDownWoNoisyJets);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetRelativeBalUpWoNoisyJets", &jetVeto30WoNoisyJets_JetRelativeBalUpWoNoisyJets, &b_jetVeto30WoNoisyJets_JetRelativeBalUpWoNoisyJets);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetRelativeSampleDown", &jetVeto30WoNoisyJets_JetRelativeSampleDown, &b_jetVeto30WoNoisyJets_JetRelativeSampleDown);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetRelativeSampleUp", &jetVeto30WoNoisyJets_JetRelativeSampleUp, &b_jetVeto30WoNoisyJets_JetRelativeSampleUp);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetTotalDown", &jetVeto30WoNoisyJets_JetTotalDown, &b_jetVeto30WoNoisyJets_JetTotalDown);
   fChain->SetBranchAddress("jetVeto30WoNoisyJets_JetTotalUp", &jetVeto30WoNoisyJets_JetTotalUp, &b_jetVeto30WoNoisyJets_JetTotalUp);
   fChain->SetBranchAddress("jetVeto30_JetEC2Down", &jetVeto30_JetEC2Down, &b_jetVeto30_JetEC2Down);
   fChain->SetBranchAddress("jetVeto30_JetEC2Up", &jetVeto30_JetEC2Up, &b_jetVeto30_JetEC2Up);
   fChain->SetBranchAddress("jetVeto30_JetEnDown", &jetVeto30_JetEnDown, &b_jetVeto30_JetEnDown);
   fChain->SetBranchAddress("jetVeto30_JetEnUp", &jetVeto30_JetEnUp, &b_jetVeto30_JetEnUp);
   fChain->SetBranchAddress("jetVeto30_JetEta0to3Down", &jetVeto30_JetEta0to3Down, &b_jetVeto30_JetEta0to3Down);
   fChain->SetBranchAddress("jetVeto30_JetEta0to3Up", &jetVeto30_JetEta0to3Up, &b_jetVeto30_JetEta0to3Up);
   fChain->SetBranchAddress("jetVeto30_JetEta0to5Down", &jetVeto30_JetEta0to5Down, &b_jetVeto30_JetEta0to5Down);
   fChain->SetBranchAddress("jetVeto30_JetEta0to5Up", &jetVeto30_JetEta0to5Up, &b_jetVeto30_JetEta0to5Up);
   fChain->SetBranchAddress("jetVeto30_JetEta3to5Down", &jetVeto30_JetEta3to5Down, &b_jetVeto30_JetEta3to5Down);
   fChain->SetBranchAddress("jetVeto30_JetEta3to5Up", &jetVeto30_JetEta3to5Up, &b_jetVeto30_JetEta3to5Up);
   fChain->SetBranchAddress("jetVeto30_JetRelativeBalDown", &jetVeto30_JetRelativeBalDown, &b_jetVeto30_JetRelativeBalDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativeBalUp", &jetVeto30_JetRelativeBalUp, &b_jetVeto30_JetRelativeBalUp);
   fChain->SetBranchAddress("jetVeto30_JetRelativeSampleDown", &jetVeto30_JetRelativeSampleDown, &b_jetVeto30_JetRelativeSampleDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativeSampleUp", &jetVeto30_JetRelativeSampleUp, &b_jetVeto30_JetRelativeSampleUp);
   fChain->SetBranchAddress("jetVeto30_JetTotalDown", &jetVeto30_JetTotalDown, &b_jetVeto30_JetTotalDown);
   fChain->SetBranchAddress("jetVeto30_JetTotalUp", &jetVeto30_JetTotalUp, &b_jetVeto30_JetTotalUp);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("mBestTrackType", &mBestTrackType, &b_mBestTrackType);
   fChain->SetBranchAddress("mCharge", &mCharge, &b_mCharge);
   fChain->SetBranchAddress("mChi2LocalPosition", &mChi2LocalPosition, &b_mChi2LocalPosition);
   fChain->SetBranchAddress("mComesFromHiggs", &mComesFromHiggs, &b_mComesFromHiggs);
   fChain->SetBranchAddress("mCutBasedIdGlobalHighPt", &mCutBasedIdGlobalHighPt, &b_mCutBasedIdGlobalHighPt);
   fChain->SetBranchAddress("mCutBasedIdLoose", &mCutBasedIdLoose, &b_mCutBasedIdLoose);
   fChain->SetBranchAddress("mCutBasedIdMedium", &mCutBasedIdMedium, &b_mCutBasedIdMedium);
   fChain->SetBranchAddress("mCutBasedIdMediumPrompt", &mCutBasedIdMediumPrompt, &b_mCutBasedIdMediumPrompt);
   fChain->SetBranchAddress("mCutBasedIdTight", &mCutBasedIdTight, &b_mCutBasedIdTight);
   fChain->SetBranchAddress("mCutBasedIdTrkHighPt", &mCutBasedIdTrkHighPt, &b_mCutBasedIdTrkHighPt);
   fChain->SetBranchAddress("mEcalIsoDR03", &mEcalIsoDR03, &b_mEcalIsoDR03);
   fChain->SetBranchAddress("mEffectiveArea2011", &mEffectiveArea2011, &b_mEffectiveArea2011);
   fChain->SetBranchAddress("mEffectiveArea2012", &mEffectiveArea2012, &b_mEffectiveArea2012);
   fChain->SetBranchAddress("mEta", &mEta, &b_mEta);
   fChain->SetBranchAddress("mEta_MuonEnDown", &mEta_MuonEnDown, &b_mEta_MuonEnDown);
   fChain->SetBranchAddress("mEta_MuonEnUp", &mEta_MuonEnUp, &b_mEta_MuonEnUp);
   fChain->SetBranchAddress("mGenCharge", &mGenCharge, &b_mGenCharge);
   fChain->SetBranchAddress("mGenDirectPromptTauDecayFinalState", &mGenDirectPromptTauDecayFinalState, &b_mGenDirectPromptTauDecayFinalState);
   fChain->SetBranchAddress("mGenEnergy", &mGenEnergy, &b_mGenEnergy);
   fChain->SetBranchAddress("mGenEta", &mGenEta, &b_mGenEta);
   fChain->SetBranchAddress("mGenIsPrompt", &mGenIsPrompt, &b_mGenIsPrompt);
   fChain->SetBranchAddress("mGenMotherPdgId", &mGenMotherPdgId, &b_mGenMotherPdgId);
   fChain->SetBranchAddress("mGenParticle", &mGenParticle, &b_mGenParticle);
   fChain->SetBranchAddress("mGenPdgId", &mGenPdgId, &b_mGenPdgId);
   fChain->SetBranchAddress("mGenPhi", &mGenPhi, &b_mGenPhi);
   fChain->SetBranchAddress("mGenPrompt", &mGenPrompt, &b_mGenPrompt);
   fChain->SetBranchAddress("mGenPromptFinalState", &mGenPromptFinalState, &b_mGenPromptFinalState);
   fChain->SetBranchAddress("mGenPromptTauDecay", &mGenPromptTauDecay, &b_mGenPromptTauDecay);
   fChain->SetBranchAddress("mGenPt", &mGenPt, &b_mGenPt);
   fChain->SetBranchAddress("mGenTauDecay", &mGenTauDecay, &b_mGenTauDecay);
   fChain->SetBranchAddress("mGenVZ", &mGenVZ, &b_mGenVZ);
   fChain->SetBranchAddress("mGenVtxPVMatch", &mGenVtxPVMatch, &b_mGenVtxPVMatch);
   fChain->SetBranchAddress("mHcalIsoDR03", &mHcalIsoDR03, &b_mHcalIsoDR03);
   fChain->SetBranchAddress("mIP3D", &mIP3D, &b_mIP3D);
   fChain->SetBranchAddress("mIP3DErr", &mIP3DErr, &b_mIP3DErr);
   fChain->SetBranchAddress("mIsGlobal", &mIsGlobal, &b_mIsGlobal);
   fChain->SetBranchAddress("mIsPFMuon", &mIsPFMuon, &b_mIsPFMuon);
   fChain->SetBranchAddress("mIsTracker", &mIsTracker, &b_mIsTracker);
   fChain->SetBranchAddress("mIsoDB03", &mIsoDB03, &b_mIsoDB03);
   fChain->SetBranchAddress("mIsoDB04", &mIsoDB04, &b_mIsoDB04);
   fChain->SetBranchAddress("mJetArea", &mJetArea, &b_mJetArea);
   fChain->SetBranchAddress("mJetBtag", &mJetBtag, &b_mJetBtag);
   fChain->SetBranchAddress("mJetDR", &mJetDR, &b_mJetDR);
   fChain->SetBranchAddress("mJetEtaEtaMoment", &mJetEtaEtaMoment, &b_mJetEtaEtaMoment);
   fChain->SetBranchAddress("mJetEtaPhiMoment", &mJetEtaPhiMoment, &b_mJetEtaPhiMoment);
   fChain->SetBranchAddress("mJetEtaPhiSpread", &mJetEtaPhiSpread, &b_mJetEtaPhiSpread);
   fChain->SetBranchAddress("mJetHadronFlavour", &mJetHadronFlavour, &b_mJetHadronFlavour);
   fChain->SetBranchAddress("mJetPFCISVBtag", &mJetPFCISVBtag, &b_mJetPFCISVBtag);
   fChain->SetBranchAddress("mJetPartonFlavour", &mJetPartonFlavour, &b_mJetPartonFlavour);
   fChain->SetBranchAddress("mJetPhiPhiMoment", &mJetPhiPhiMoment, &b_mJetPhiPhiMoment);
   fChain->SetBranchAddress("mJetPt", &mJetPt, &b_mJetPt);
   fChain->SetBranchAddress("mLowestMll", &mLowestMll, &b_mLowestMll);
   fChain->SetBranchAddress("mMass", &mMass, &b_mMass);
   fChain->SetBranchAddress("mMatchedStations", &mMatchedStations, &b_mMatchedStations);
   fChain->SetBranchAddress("mMatchesIsoMu19Tau20Filter", &mMatchesIsoMu19Tau20Filter, &b_mMatchesIsoMu19Tau20Filter);
   fChain->SetBranchAddress("mMatchesIsoMu19Tau20Path", &mMatchesIsoMu19Tau20Path, &b_mMatchesIsoMu19Tau20Path);
   fChain->SetBranchAddress("mMatchesIsoMu19Tau20SingleL1Filter", &mMatchesIsoMu19Tau20SingleL1Filter, &b_mMatchesIsoMu19Tau20SingleL1Filter);
   fChain->SetBranchAddress("mMatchesIsoMu19Tau20SingleL1Path", &mMatchesIsoMu19Tau20SingleL1Path, &b_mMatchesIsoMu19Tau20SingleL1Path);
   fChain->SetBranchAddress("mMatchesIsoMu20HPSTau27Filter", &mMatchesIsoMu20HPSTau27Filter, &b_mMatchesIsoMu20HPSTau27Filter);
   fChain->SetBranchAddress("mMatchesIsoMu20HPSTau27Path", &mMatchesIsoMu20HPSTau27Path, &b_mMatchesIsoMu20HPSTau27Path);
   fChain->SetBranchAddress("mMatchesIsoMu20Tau27Filter", &mMatchesIsoMu20Tau27Filter, &b_mMatchesIsoMu20Tau27Filter);
   fChain->SetBranchAddress("mMatchesIsoMu20Tau27Path", &mMatchesIsoMu20Tau27Path, &b_mMatchesIsoMu20Tau27Path);
   fChain->SetBranchAddress("mMatchesIsoMu22Filter", &mMatchesIsoMu22Filter, &b_mMatchesIsoMu22Filter);
   fChain->SetBranchAddress("mMatchesIsoMu22Path", &mMatchesIsoMu22Path, &b_mMatchesIsoMu22Path);
   fChain->SetBranchAddress("mMatchesIsoMu22eta2p1Filter", &mMatchesIsoMu22eta2p1Filter, &b_mMatchesIsoMu22eta2p1Filter);
   fChain->SetBranchAddress("mMatchesIsoMu22eta2p1Path", &mMatchesIsoMu22eta2p1Path, &b_mMatchesIsoMu22eta2p1Path);
   fChain->SetBranchAddress("mMatchesIsoMu24Filter", &mMatchesIsoMu24Filter, &b_mMatchesIsoMu24Filter);
   fChain->SetBranchAddress("mMatchesIsoMu24Path", &mMatchesIsoMu24Path, &b_mMatchesIsoMu24Path);
   fChain->SetBranchAddress("mMatchesIsoMu27Filter", &mMatchesIsoMu27Filter, &b_mMatchesIsoMu27Filter);
   fChain->SetBranchAddress("mMatchesIsoMu27Path", &mMatchesIsoMu27Path, &b_mMatchesIsoMu27Path);
   fChain->SetBranchAddress("mMatchesIsoTkMu22Filter", &mMatchesIsoTkMu22Filter, &b_mMatchesIsoTkMu22Filter);
   fChain->SetBranchAddress("mMatchesIsoTkMu22Path", &mMatchesIsoTkMu22Path, &b_mMatchesIsoTkMu22Path);
   fChain->SetBranchAddress("mMatchesIsoTkMu22eta2p1Filter", &mMatchesIsoTkMu22eta2p1Filter, &b_mMatchesIsoTkMu22eta2p1Filter);
   fChain->SetBranchAddress("mMatchesIsoTkMu22eta2p1Path", &mMatchesIsoTkMu22eta2p1Path, &b_mMatchesIsoTkMu22eta2p1Path);
   fChain->SetBranchAddress("mMiniIsoLoose", &mMiniIsoLoose, &b_mMiniIsoLoose);
   fChain->SetBranchAddress("mMiniIsoMedium", &mMiniIsoMedium, &b_mMiniIsoMedium);
   fChain->SetBranchAddress("mMiniIsoTight", &mMiniIsoTight, &b_mMiniIsoTight);
   fChain->SetBranchAddress("mMiniIsoVeryTight", &mMiniIsoVeryTight, &b_mMiniIsoVeryTight);
   fChain->SetBranchAddress("mMuonHits", &mMuonHits, &b_mMuonHits);
   fChain->SetBranchAddress("mMvaLoose", &mMvaLoose, &b_mMvaLoose);
   fChain->SetBranchAddress("mMvaMedium", &mMvaMedium, &b_mMvaMedium);
   fChain->SetBranchAddress("mMvaTight", &mMvaTight, &b_mMvaTight);
   fChain->SetBranchAddress("mNearestZMass", &mNearestZMass, &b_mNearestZMass);
   fChain->SetBranchAddress("mNormTrkChi2", &mNormTrkChi2, &b_mNormTrkChi2);
   fChain->SetBranchAddress("mNormalizedChi2", &mNormalizedChi2, &b_mNormalizedChi2);
   fChain->SetBranchAddress("mPFChargedHadronIsoR04", &mPFChargedHadronIsoR04, &b_mPFChargedHadronIsoR04);
   fChain->SetBranchAddress("mPFChargedIso", &mPFChargedIso, &b_mPFChargedIso);
   fChain->SetBranchAddress("mPFIDLoose", &mPFIDLoose, &b_mPFIDLoose);
   fChain->SetBranchAddress("mPFIDMedium", &mPFIDMedium, &b_mPFIDMedium);
   fChain->SetBranchAddress("mPFIDTight", &mPFIDTight, &b_mPFIDTight);
   fChain->SetBranchAddress("mPFIsoLoose", &mPFIsoLoose, &b_mPFIsoLoose);
   fChain->SetBranchAddress("mPFIsoMedium", &mPFIsoMedium, &b_mPFIsoMedium);
   fChain->SetBranchAddress("mPFIsoTight", &mPFIsoTight, &b_mPFIsoTight);
   fChain->SetBranchAddress("mPFIsoVeryLoose", &mPFIsoVeryLoose, &b_mPFIsoVeryLoose);
   fChain->SetBranchAddress("mPFIsoVeryTight", &mPFIsoVeryTight, &b_mPFIsoVeryTight);
   fChain->SetBranchAddress("mPFNeutralHadronIsoR04", &mPFNeutralHadronIsoR04, &b_mPFNeutralHadronIsoR04);
   fChain->SetBranchAddress("mPFNeutralIso", &mPFNeutralIso, &b_mPFNeutralIso);
   fChain->SetBranchAddress("mPFPUChargedIso", &mPFPUChargedIso, &b_mPFPUChargedIso);
   fChain->SetBranchAddress("mPFPhotonIso", &mPFPhotonIso, &b_mPFPhotonIso);
   fChain->SetBranchAddress("mPFPhotonIsoR04", &mPFPhotonIsoR04, &b_mPFPhotonIsoR04);
   fChain->SetBranchAddress("mPFPileupIsoR04", &mPFPileupIsoR04, &b_mPFPileupIsoR04);
   fChain->SetBranchAddress("mPVDXY", &mPVDXY, &b_mPVDXY);
   fChain->SetBranchAddress("mPVDZ", &mPVDZ, &b_mPVDZ);
   fChain->SetBranchAddress("mPhi", &mPhi, &b_mPhi);
   fChain->SetBranchAddress("mPhi_MuonEnDown", &mPhi_MuonEnDown, &b_mPhi_MuonEnDown);
   fChain->SetBranchAddress("mPhi_MuonEnUp", &mPhi_MuonEnUp, &b_mPhi_MuonEnUp);
   fChain->SetBranchAddress("mPixHits", &mPixHits, &b_mPixHits);
   fChain->SetBranchAddress("mPt", &mPt, &b_mPt);
   fChain->SetBranchAddress("mPt_MuonEnDown", &mPt_MuonEnDown, &b_mPt_MuonEnDown);
   fChain->SetBranchAddress("mPt_MuonEnUp", &mPt_MuonEnUp, &b_mPt_MuonEnUp);
   fChain->SetBranchAddress("mRelPFIsoDBDefault", &mRelPFIsoDBDefault, &b_mRelPFIsoDBDefault);
   fChain->SetBranchAddress("mRelPFIsoDBDefaultR04", &mRelPFIsoDBDefaultR04, &b_mRelPFIsoDBDefaultR04);
   fChain->SetBranchAddress("mRelPFIsoRho", &mRelPFIsoRho, &b_mRelPFIsoRho);
   fChain->SetBranchAddress("mRho", &mRho, &b_mRho);
   fChain->SetBranchAddress("mSIP2D", &mSIP2D, &b_mSIP2D);
   fChain->SetBranchAddress("mSIP3D", &mSIP3D, &b_mSIP3D);
   fChain->SetBranchAddress("mSegmentCompatibility", &mSegmentCompatibility, &b_mSegmentCompatibility);
   fChain->SetBranchAddress("mSoftCutBasedId", &mSoftCutBasedId, &b_mSoftCutBasedId);
   fChain->SetBranchAddress("mTkIsoLoose", &mTkIsoLoose, &b_mTkIsoLoose);
   fChain->SetBranchAddress("mTkIsoTight", &mTkIsoTight, &b_mTkIsoTight);
   fChain->SetBranchAddress("mTkLayersWithMeasurement", &mTkLayersWithMeasurement, &b_mTkLayersWithMeasurement);
   fChain->SetBranchAddress("mTrkIsoDR03", &mTrkIsoDR03, &b_mTrkIsoDR03);
   fChain->SetBranchAddress("mTrkKink", &mTrkKink, &b_mTrkKink);
   fChain->SetBranchAddress("mTypeCode", &mTypeCode, &b_mTypeCode);
   fChain->SetBranchAddress("mVZ", &mVZ, &b_mVZ);
   fChain->SetBranchAddress("mValidFraction", &mValidFraction, &b_mValidFraction);
   fChain->SetBranchAddress("mZTTGenMatching", &mZTTGenMatching, &b_mZTTGenMatching);
   fChain->SetBranchAddress("m_t_DR", &m_t_DR, &b_m_t_DR);
   fChain->SetBranchAddress("m_t_Mass", &m_t_Mass, &b_m_t_Mass);
   fChain->SetBranchAddress("m_t_doubleL1IsoTauMatch", &m_t_doubleL1IsoTauMatch, &b_m_t_doubleL1IsoTauMatch);
   fChain->SetBranchAddress("metSig", &metSig, &b_metSig);
   fChain->SetBranchAddress("metcov00", &metcov00, &b_metcov00);
   fChain->SetBranchAddress("metcov01", &metcov01, &b_metcov01);
   fChain->SetBranchAddress("metcov10", &metcov10, &b_metcov10);
   fChain->SetBranchAddress("metcov11", &metcov11, &b_metcov11);
   fChain->SetBranchAddress("mu12e23DZPass", &mu12e23DZPass, &b_mu12e23DZPass);
   fChain->SetBranchAddress("mu12e23Pass", &mu12e23Pass, &b_mu12e23Pass);
   fChain->SetBranchAddress("mu23e12DZPass", &mu23e12DZPass, &b_mu23e12DZPass);
   fChain->SetBranchAddress("mu23e12Pass", &mu23e12Pass, &b_mu23e12Pass);
   fChain->SetBranchAddress("mu8diele12DZPass", &mu8diele12DZPass, &b_mu8diele12DZPass);
   fChain->SetBranchAddress("mu8diele12Pass", &mu8diele12Pass, &b_mu8diele12Pass);
   fChain->SetBranchAddress("mu8e23DZPass", &mu8e23DZPass, &b_mu8e23DZPass);
   fChain->SetBranchAddress("mu8e23Pass", &mu8e23Pass, &b_mu8e23Pass);
   fChain->SetBranchAddress("muGlbIsoVetoPt10", &muGlbIsoVetoPt10, &b_muGlbIsoVetoPt10);
   fChain->SetBranchAddress("muVeto5", &muVeto5, &b_muVeto5);
   fChain->SetBranchAddress("muVetoZTTp001dxyz", &muVetoZTTp001dxyz, &b_muVetoZTTp001dxyz);
   fChain->SetBranchAddress("muVetoZTTp001dxyzR0", &muVetoZTTp001dxyzR0, &b_muVetoZTTp001dxyzR0);
   fChain->SetBranchAddress("nTruePU", &nTruePU, &b_nTruePU);
   fChain->SetBranchAddress("npNLO", &npNLO, &b_npNLO);
   fChain->SetBranchAddress("numGenJets", &numGenJets, &b_numGenJets);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("processID", &processID, &b_processID);
   fChain->SetBranchAddress("puppiMetEt", &puppiMetEt, &b_puppiMetEt);
   fChain->SetBranchAddress("puppiMetPhi", &puppiMetPhi, &b_puppiMetPhi);
   fChain->SetBranchAddress("pvChi2", &pvChi2, &b_pvChi2);
   fChain->SetBranchAddress("pvDX", &pvDX, &b_pvDX);
   fChain->SetBranchAddress("pvDY", &pvDY, &b_pvDY);
   fChain->SetBranchAddress("pvDZ", &pvDZ, &b_pvDZ);
   fChain->SetBranchAddress("pvIsFake", &pvIsFake, &b_pvIsFake);
   fChain->SetBranchAddress("pvIsValid", &pvIsValid, &b_pvIsValid);
   fChain->SetBranchAddress("pvNormChi2", &pvNormChi2, &b_pvNormChi2);
   fChain->SetBranchAddress("pvRho", &pvRho, &b_pvRho);
   fChain->SetBranchAddress("pvX", &pvX, &b_pvX);
   fChain->SetBranchAddress("pvY", &pvY, &b_pvY);
   fChain->SetBranchAddress("pvZ", &pvZ, &b_pvZ);
   fChain->SetBranchAddress("pvndof", &pvndof, &b_pvndof);
   fChain->SetBranchAddress("raw_pfMetEt", &raw_pfMetEt, &b_raw_pfMetEt);
   fChain->SetBranchAddress("raw_pfMetPhi", &raw_pfMetPhi, &b_raw_pfMetPhi);
   fChain->SetBranchAddress("recoilDaught", &recoilDaught, &b_recoilDaught);
   fChain->SetBranchAddress("recoilWithMet", &recoilWithMet, &b_recoilWithMet);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("singleE25eta2p1TightPass", &singleE25eta2p1TightPass, &b_singleE25eta2p1TightPass);
   fChain->SetBranchAddress("singleIsoMu22Pass", &singleIsoMu22Pass, &b_singleIsoMu22Pass);
   fChain->SetBranchAddress("singleIsoMu22eta2p1Pass", &singleIsoMu22eta2p1Pass, &b_singleIsoMu22eta2p1Pass);
   fChain->SetBranchAddress("singleIsoTkMu22Pass", &singleIsoTkMu22Pass, &b_singleIsoTkMu22Pass);
   fChain->SetBranchAddress("singleIsoTkMu22eta2p1Pass", &singleIsoTkMu22eta2p1Pass, &b_singleIsoTkMu22eta2p1Pass);
   fChain->SetBranchAddress("singleMu19eta2p1LooseTau20Pass", &singleMu19eta2p1LooseTau20Pass, &b_singleMu19eta2p1LooseTau20Pass);
   fChain->SetBranchAddress("singleMu19eta2p1LooseTau20singleL1Pass", &singleMu19eta2p1LooseTau20singleL1Pass, &b_singleMu19eta2p1LooseTau20singleL1Pass);
   fChain->SetBranchAddress("tAgainstElectronLooseMVA6", &tAgainstElectronLooseMVA6, &b_tAgainstElectronLooseMVA6);
   fChain->SetBranchAddress("tAgainstElectronLooseMVA62018", &tAgainstElectronLooseMVA62018, &b_tAgainstElectronLooseMVA62018);
   fChain->SetBranchAddress("tAgainstElectronMVA6Raw", &tAgainstElectronMVA6Raw, &b_tAgainstElectronMVA6Raw);
   fChain->SetBranchAddress("tAgainstElectronMVA6Raw2018", &tAgainstElectronMVA6Raw2018, &b_tAgainstElectronMVA6Raw2018);
   fChain->SetBranchAddress("tAgainstElectronMVA6category", &tAgainstElectronMVA6category, &b_tAgainstElectronMVA6category);
   fChain->SetBranchAddress("tAgainstElectronMVA6category2018", &tAgainstElectronMVA6category2018, &b_tAgainstElectronMVA6category2018);
   fChain->SetBranchAddress("tAgainstElectronMediumMVA6", &tAgainstElectronMediumMVA6, &b_tAgainstElectronMediumMVA6);
   fChain->SetBranchAddress("tAgainstElectronMediumMVA62018", &tAgainstElectronMediumMVA62018, &b_tAgainstElectronMediumMVA62018);
   fChain->SetBranchAddress("tAgainstElectronTightMVA6", &tAgainstElectronTightMVA6, &b_tAgainstElectronTightMVA6);
   fChain->SetBranchAddress("tAgainstElectronTightMVA62018", &tAgainstElectronTightMVA62018, &b_tAgainstElectronTightMVA62018);
   fChain->SetBranchAddress("tAgainstElectronVLooseMVA6", &tAgainstElectronVLooseMVA6, &b_tAgainstElectronVLooseMVA6);
   fChain->SetBranchAddress("tAgainstElectronVLooseMVA62018", &tAgainstElectronVLooseMVA62018, &b_tAgainstElectronVLooseMVA62018);
   fChain->SetBranchAddress("tAgainstElectronVTightMVA6", &tAgainstElectronVTightMVA6, &b_tAgainstElectronVTightMVA6);
   fChain->SetBranchAddress("tAgainstElectronVTightMVA62018", &tAgainstElectronVTightMVA62018, &b_tAgainstElectronVTightMVA62018);
   fChain->SetBranchAddress("tAgainstMuonLoose3", &tAgainstMuonLoose3, &b_tAgainstMuonLoose3);
   fChain->SetBranchAddress("tAgainstMuonTight3", &tAgainstMuonTight3, &b_tAgainstMuonTight3);
   fChain->SetBranchAddress("tByCombinedIsolationDeltaBetaCorrRaw3Hits", &tByCombinedIsolationDeltaBetaCorrRaw3Hits, &b_tByCombinedIsolationDeltaBetaCorrRaw3Hits);
   fChain->SetBranchAddress("tByIsolationMVArun2v1DBdR03oldDMwLTraw", &tByIsolationMVArun2v1DBdR03oldDMwLTraw, &b_tByIsolationMVArun2v1DBdR03oldDMwLTraw);
   fChain->SetBranchAddress("tByIsolationMVArun2v1DBnewDMwLTraw", &tByIsolationMVArun2v1DBnewDMwLTraw, &b_tByIsolationMVArun2v1DBnewDMwLTraw);
   fChain->SetBranchAddress("tByIsolationMVArun2v1DBoldDMwLTraw", &tByIsolationMVArun2v1DBoldDMwLTraw, &b_tByIsolationMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("tByLooseCombinedIsolationDeltaBetaCorr3Hits", &tByLooseCombinedIsolationDeltaBetaCorr3Hits, &b_tByLooseCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("tByLooseIsolationMVArun2v1DBdR03oldDMwLT", &tByLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_tByLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByLooseIsolationMVArun2v1DBnewDMwLT", &tByLooseIsolationMVArun2v1DBnewDMwLT, &b_tByLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByLooseIsolationMVArun2v1DBoldDMwLT", &tByLooseIsolationMVArun2v1DBoldDMwLT, &b_tByLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByMediumCombinedIsolationDeltaBetaCorr3Hits", &tByMediumCombinedIsolationDeltaBetaCorr3Hits, &b_tByMediumCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("tByMediumIsolationMVArun2v1DBdR03oldDMwLT", &tByMediumIsolationMVArun2v1DBdR03oldDMwLT, &b_tByMediumIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByMediumIsolationMVArun2v1DBnewDMwLT", &tByMediumIsolationMVArun2v1DBnewDMwLT, &b_tByMediumIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByMediumIsolationMVArun2v1DBoldDMwLT", &tByMediumIsolationMVArun2v1DBoldDMwLT, &b_tByMediumIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByPhotonPtSumOutsideSignalCone", &tByPhotonPtSumOutsideSignalCone, &b_tByPhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("tByTightCombinedIsolationDeltaBetaCorr3Hits", &tByTightCombinedIsolationDeltaBetaCorr3Hits, &b_tByTightCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("tByTightIsolationMVArun2v1DBdR03oldDMwLT", &tByTightIsolationMVArun2v1DBdR03oldDMwLT, &b_tByTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByTightIsolationMVArun2v1DBnewDMwLT", &tByTightIsolationMVArun2v1DBnewDMwLT, &b_tByTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByTightIsolationMVArun2v1DBoldDMwLT", &tByTightIsolationMVArun2v1DBoldDMwLT, &b_tByTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByVLooseIsolationMVArun2v1DBdR03oldDMwLT", &tByVLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_tByVLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByVLooseIsolationMVArun2v1DBnewDMwLT", &tByVLooseIsolationMVArun2v1DBnewDMwLT, &b_tByVLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByVLooseIsolationMVArun2v1DBoldDMwLT", &tByVLooseIsolationMVArun2v1DBoldDMwLT, &b_tByVLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByVTightIsolationMVArun2v1DBdR03oldDMwLT", &tByVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_tByVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByVTightIsolationMVArun2v1DBnewDMwLT", &tByVTightIsolationMVArun2v1DBnewDMwLT, &b_tByVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByVTightIsolationMVArun2v1DBoldDMwLT", &tByVTightIsolationMVArun2v1DBoldDMwLT, &b_tByVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByVVTightIsolationMVArun2v1DBdR03oldDMwLT", &tByVVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_tByVVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByVVTightIsolationMVArun2v1DBnewDMwLT", &tByVVTightIsolationMVArun2v1DBnewDMwLT, &b_tByVVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByVVTightIsolationMVArun2v1DBoldDMwLT", &tByVVTightIsolationMVArun2v1DBoldDMwLT, &b_tByVVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tCharge", &tCharge, &b_tCharge);
   fChain->SetBranchAddress("tChargedIsoPtSum", &tChargedIsoPtSum, &b_tChargedIsoPtSum);
   fChain->SetBranchAddress("tChargedIsoPtSumdR03", &tChargedIsoPtSumdR03, &b_tChargedIsoPtSumdR03);
   fChain->SetBranchAddress("tComesFromHiggs", &tComesFromHiggs, &b_tComesFromHiggs);
   fChain->SetBranchAddress("tDecayMode", &tDecayMode, &b_tDecayMode);
   fChain->SetBranchAddress("tDecayModeFinding", &tDecayModeFinding, &b_tDecayModeFinding);
   fChain->SetBranchAddress("tDecayModeFindingNewDMs", &tDecayModeFindingNewDMs, &b_tDecayModeFindingNewDMs);
   fChain->SetBranchAddress("tDeepTau2017v1VSeraw", &tDeepTau2017v1VSeraw, &b_tDeepTau2017v1VSeraw);
   fChain->SetBranchAddress("tDeepTau2017v1VSjetraw", &tDeepTau2017v1VSjetraw, &b_tDeepTau2017v1VSjetraw);
   fChain->SetBranchAddress("tDeepTau2017v1VSmuraw", &tDeepTau2017v1VSmuraw, &b_tDeepTau2017v1VSmuraw);
   fChain->SetBranchAddress("tDpfTau2016v0VSallraw", &tDpfTau2016v0VSallraw, &b_tDpfTau2016v0VSallraw);
   fChain->SetBranchAddress("tDpfTau2016v1VSallraw", &tDpfTau2016v1VSallraw, &b_tDpfTau2016v1VSallraw);
   fChain->SetBranchAddress("tEta", &tEta, &b_tEta);
   fChain->SetBranchAddress("tFootprintCorrection", &tFootprintCorrection, &b_tFootprintCorrection);
   fChain->SetBranchAddress("tFootprintCorrectiondR03", &tFootprintCorrectiondR03, &b_tFootprintCorrectiondR03);
   fChain->SetBranchAddress("tGenCharge", &tGenCharge, &b_tGenCharge);
   fChain->SetBranchAddress("tGenDecayMode", &tGenDecayMode, &b_tGenDecayMode);
   fChain->SetBranchAddress("tGenEnergy", &tGenEnergy, &b_tGenEnergy);
   fChain->SetBranchAddress("tGenEta", &tGenEta, &b_tGenEta);
   fChain->SetBranchAddress("tGenJetEta", &tGenJetEta, &b_tGenJetEta);
   fChain->SetBranchAddress("tGenJetPt", &tGenJetPt, &b_tGenJetPt);
   fChain->SetBranchAddress("tGenMotherEnergy", &tGenMotherEnergy, &b_tGenMotherEnergy);
   fChain->SetBranchAddress("tGenMotherEta", &tGenMotherEta, &b_tGenMotherEta);
   fChain->SetBranchAddress("tGenMotherPdgId", &tGenMotherPdgId, &b_tGenMotherPdgId);
   fChain->SetBranchAddress("tGenMotherPhi", &tGenMotherPhi, &b_tGenMotherPhi);
   fChain->SetBranchAddress("tGenMotherPt", &tGenMotherPt, &b_tGenMotherPt);
   fChain->SetBranchAddress("tGenPdgId", &tGenPdgId, &b_tGenPdgId);
   fChain->SetBranchAddress("tGenPhi", &tGenPhi, &b_tGenPhi);
   fChain->SetBranchAddress("tGenPt", &tGenPt, &b_tGenPt);
   fChain->SetBranchAddress("tGenStatus", &tGenStatus, &b_tGenStatus);
   fChain->SetBranchAddress("tJetArea", &tJetArea, &b_tJetArea);
   fChain->SetBranchAddress("tJetBtag", &tJetBtag, &b_tJetBtag);
   fChain->SetBranchAddress("tJetDR", &tJetDR, &b_tJetDR);
   fChain->SetBranchAddress("tJetEtaEtaMoment", &tJetEtaEtaMoment, &b_tJetEtaEtaMoment);
   fChain->SetBranchAddress("tJetEtaPhiMoment", &tJetEtaPhiMoment, &b_tJetEtaPhiMoment);
   fChain->SetBranchAddress("tJetEtaPhiSpread", &tJetEtaPhiSpread, &b_tJetEtaPhiSpread);
   fChain->SetBranchAddress("tJetHadronFlavour", &tJetHadronFlavour, &b_tJetHadronFlavour);
   fChain->SetBranchAddress("tJetPFCISVBtag", &tJetPFCISVBtag, &b_tJetPFCISVBtag);
   fChain->SetBranchAddress("tJetPartonFlavour", &tJetPartonFlavour, &b_tJetPartonFlavour);
   fChain->SetBranchAddress("tJetPhiPhiMoment", &tJetPhiPhiMoment, &b_tJetPhiPhiMoment);
   fChain->SetBranchAddress("tJetPt", &tJetPt, &b_tJetPt);
   fChain->SetBranchAddress("tL1IsoTauMatch", &tL1IsoTauMatch, &b_tL1IsoTauMatch);
   fChain->SetBranchAddress("tL1IsoTauPt", &tL1IsoTauPt, &b_tL1IsoTauPt);
   fChain->SetBranchAddress("tLeadTrackPt", &tLeadTrackPt, &b_tLeadTrackPt);
   fChain->SetBranchAddress("tLooseDeepTau2017v1VSe", &tLooseDeepTau2017v1VSe, &b_tLooseDeepTau2017v1VSe);
   fChain->SetBranchAddress("tLooseDeepTau2017v1VSjet", &tLooseDeepTau2017v1VSjet, &b_tLooseDeepTau2017v1VSjet);
   fChain->SetBranchAddress("tLooseDeepTau2017v1VSmu", &tLooseDeepTau2017v1VSmu, &b_tLooseDeepTau2017v1VSmu);
   fChain->SetBranchAddress("tLowestMll", &tLowestMll, &b_tLowestMll);
   fChain->SetBranchAddress("tMass", &tMass, &b_tMass);
   fChain->SetBranchAddress("tMatchesDoubleMediumCombinedIsoTau35Path", &tMatchesDoubleMediumCombinedIsoTau35Path, &b_tMatchesDoubleMediumCombinedIsoTau35Path);
   fChain->SetBranchAddress("tMatchesDoubleMediumHPSTau35Filter", &tMatchesDoubleMediumHPSTau35Filter, &b_tMatchesDoubleMediumHPSTau35Filter);
   fChain->SetBranchAddress("tMatchesDoubleMediumHPSTau35Path", &tMatchesDoubleMediumHPSTau35Path, &b_tMatchesDoubleMediumHPSTau35Path);
   fChain->SetBranchAddress("tMatchesDoubleMediumHPSTau40Filter", &tMatchesDoubleMediumHPSTau40Filter, &b_tMatchesDoubleMediumHPSTau40Filter);
   fChain->SetBranchAddress("tMatchesDoubleMediumHPSTau40Path", &tMatchesDoubleMediumHPSTau40Path, &b_tMatchesDoubleMediumHPSTau40Path);
   fChain->SetBranchAddress("tMatchesDoubleMediumIsoTau35Path", &tMatchesDoubleMediumIsoTau35Path, &b_tMatchesDoubleMediumIsoTau35Path);
   fChain->SetBranchAddress("tMatchesDoubleMediumTau35Filter", &tMatchesDoubleMediumTau35Filter, &b_tMatchesDoubleMediumTau35Filter);
   fChain->SetBranchAddress("tMatchesDoubleMediumTau35Path", &tMatchesDoubleMediumTau35Path, &b_tMatchesDoubleMediumTau35Path);
   fChain->SetBranchAddress("tMatchesDoubleMediumTau40Filter", &tMatchesDoubleMediumTau40Filter, &b_tMatchesDoubleMediumTau40Filter);
   fChain->SetBranchAddress("tMatchesDoubleMediumTau40Path", &tMatchesDoubleMediumTau40Path, &b_tMatchesDoubleMediumTau40Path);
   fChain->SetBranchAddress("tMatchesDoubleTightHPSTau35Filter", &tMatchesDoubleTightHPSTau35Filter, &b_tMatchesDoubleTightHPSTau35Filter);
   fChain->SetBranchAddress("tMatchesDoubleTightHPSTau35Path", &tMatchesDoubleTightHPSTau35Path, &b_tMatchesDoubleTightHPSTau35Path);
   fChain->SetBranchAddress("tMatchesDoubleTightHPSTau40Filter", &tMatchesDoubleTightHPSTau40Filter, &b_tMatchesDoubleTightHPSTau40Filter);
   fChain->SetBranchAddress("tMatchesDoubleTightHPSTau40Path", &tMatchesDoubleTightHPSTau40Path, &b_tMatchesDoubleTightHPSTau40Path);
   fChain->SetBranchAddress("tMatchesDoubleTightTau35Filter", &tMatchesDoubleTightTau35Filter, &b_tMatchesDoubleTightTau35Filter);
   fChain->SetBranchAddress("tMatchesDoubleTightTau35Path", &tMatchesDoubleTightTau35Path, &b_tMatchesDoubleTightTau35Path);
   fChain->SetBranchAddress("tMatchesDoubleTightTau40Filter", &tMatchesDoubleTightTau40Filter, &b_tMatchesDoubleTightTau40Filter);
   fChain->SetBranchAddress("tMatchesDoubleTightTau40Path", &tMatchesDoubleTightTau40Path, &b_tMatchesDoubleTightTau40Path);
   fChain->SetBranchAddress("tMatchesEle24HPSTau30Filter", &tMatchesEle24HPSTau30Filter, &b_tMatchesEle24HPSTau30Filter);
   fChain->SetBranchAddress("tMatchesEle24HPSTau30Path", &tMatchesEle24HPSTau30Path, &b_tMatchesEle24HPSTau30Path);
   fChain->SetBranchAddress("tMatchesEle24Tau30Filter", &tMatchesEle24Tau30Filter, &b_tMatchesEle24Tau30Filter);
   fChain->SetBranchAddress("tMatchesEle24Tau30Path", &tMatchesEle24Tau30Path, &b_tMatchesEle24Tau30Path);
   fChain->SetBranchAddress("tMatchesIsoMu19Tau20Filter", &tMatchesIsoMu19Tau20Filter, &b_tMatchesIsoMu19Tau20Filter);
   fChain->SetBranchAddress("tMatchesIsoMu19Tau20Path", &tMatchesIsoMu19Tau20Path, &b_tMatchesIsoMu19Tau20Path);
   fChain->SetBranchAddress("tMatchesIsoMu19Tau20SingleL1Filter", &tMatchesIsoMu19Tau20SingleL1Filter, &b_tMatchesIsoMu19Tau20SingleL1Filter);
   fChain->SetBranchAddress("tMatchesIsoMu19Tau20SingleL1Path", &tMatchesIsoMu19Tau20SingleL1Path, &b_tMatchesIsoMu19Tau20SingleL1Path);
   fChain->SetBranchAddress("tMatchesIsoMu20HPSTau27Filter", &tMatchesIsoMu20HPSTau27Filter, &b_tMatchesIsoMu20HPSTau27Filter);
   fChain->SetBranchAddress("tMatchesIsoMu20HPSTau27Path", &tMatchesIsoMu20HPSTau27Path, &b_tMatchesIsoMu20HPSTau27Path);
   fChain->SetBranchAddress("tMatchesIsoMu20Tau27Filter", &tMatchesIsoMu20Tau27Filter, &b_tMatchesIsoMu20Tau27Filter);
   fChain->SetBranchAddress("tMatchesIsoMu20Tau27Path", &tMatchesIsoMu20Tau27Path, &b_tMatchesIsoMu20Tau27Path);
   fChain->SetBranchAddress("tMediumDeepTau2017v1VSe", &tMediumDeepTau2017v1VSe, &b_tMediumDeepTau2017v1VSe);
   fChain->SetBranchAddress("tMediumDeepTau2017v1VSjet", &tMediumDeepTau2017v1VSjet, &b_tMediumDeepTau2017v1VSjet);
   fChain->SetBranchAddress("tMediumDeepTau2017v1VSmu", &tMediumDeepTau2017v1VSmu, &b_tMediumDeepTau2017v1VSmu);
   fChain->SetBranchAddress("tNChrgHadrIsolationCands", &tNChrgHadrIsolationCands, &b_tNChrgHadrIsolationCands);
   fChain->SetBranchAddress("tNChrgHadrSignalCands", &tNChrgHadrSignalCands, &b_tNChrgHadrSignalCands);
   fChain->SetBranchAddress("tNGammaSignalCands", &tNGammaSignalCands, &b_tNGammaSignalCands);
   fChain->SetBranchAddress("tNNeutralHadrSignalCands", &tNNeutralHadrSignalCands, &b_tNNeutralHadrSignalCands);
   fChain->SetBranchAddress("tNSignalCands", &tNSignalCands, &b_tNSignalCands);
   fChain->SetBranchAddress("tNearestZMass", &tNearestZMass, &b_tNearestZMass);
   fChain->SetBranchAddress("tNeutralIsoPtSum", &tNeutralIsoPtSum, &b_tNeutralIsoPtSum);
   fChain->SetBranchAddress("tNeutralIsoPtSumWeight", &tNeutralIsoPtSumWeight, &b_tNeutralIsoPtSumWeight);
   fChain->SetBranchAddress("tNeutralIsoPtSumWeightdR03", &tNeutralIsoPtSumWeightdR03, &b_tNeutralIsoPtSumWeightdR03);
   fChain->SetBranchAddress("tNeutralIsoPtSumdR03", &tNeutralIsoPtSumdR03, &b_tNeutralIsoPtSumdR03);
   fChain->SetBranchAddress("tPVDXY", &tPVDXY, &b_tPVDXY);
   fChain->SetBranchAddress("tPVDZ", &tPVDZ, &b_tPVDZ);
   fChain->SetBranchAddress("tPhi", &tPhi, &b_tPhi);
   fChain->SetBranchAddress("tPhotonPtSumOutsideSignalCone", &tPhotonPtSumOutsideSignalCone, &b_tPhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("tPhotonPtSumOutsideSignalConedR03", &tPhotonPtSumOutsideSignalConedR03, &b_tPhotonPtSumOutsideSignalConedR03);
   fChain->SetBranchAddress("tPt", &tPt, &b_tPt);
   fChain->SetBranchAddress("tPuCorrPtSum", &tPuCorrPtSum, &b_tPuCorrPtSum);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTLoose", &tRerunMVArun2v2DBoldDMwLTLoose, &b_tRerunMVArun2v2DBoldDMwLTLoose);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTMedium", &tRerunMVArun2v2DBoldDMwLTMedium, &b_tRerunMVArun2v2DBoldDMwLTMedium);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTTight", &tRerunMVArun2v2DBoldDMwLTTight, &b_tRerunMVArun2v2DBoldDMwLTTight);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTVLoose", &tRerunMVArun2v2DBoldDMwLTVLoose, &b_tRerunMVArun2v2DBoldDMwLTVLoose);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTVTight", &tRerunMVArun2v2DBoldDMwLTVTight, &b_tRerunMVArun2v2DBoldDMwLTVTight);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTVVLoose", &tRerunMVArun2v2DBoldDMwLTVVLoose, &b_tRerunMVArun2v2DBoldDMwLTVVLoose);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTVVTight", &tRerunMVArun2v2DBoldDMwLTVVTight, &b_tRerunMVArun2v2DBoldDMwLTVVTight);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTraw", &tRerunMVArun2v2DBoldDMwLTraw, &b_tRerunMVArun2v2DBoldDMwLTraw);
   fChain->SetBranchAddress("tTightDeepTau2017v1VSe", &tTightDeepTau2017v1VSe, &b_tTightDeepTau2017v1VSe);
   fChain->SetBranchAddress("tTightDeepTau2017v1VSjet", &tTightDeepTau2017v1VSjet, &b_tTightDeepTau2017v1VSjet);
   fChain->SetBranchAddress("tTightDeepTau2017v1VSmu", &tTightDeepTau2017v1VSmu, &b_tTightDeepTau2017v1VSmu);
   fChain->SetBranchAddress("tTightDpfTau2016v0VSall", &tTightDpfTau2016v0VSall, &b_tTightDpfTau2016v0VSall);
   fChain->SetBranchAddress("tTightDpfTau2016v1VSall", &tTightDpfTau2016v1VSall, &b_tTightDpfTau2016v1VSall);
   fChain->SetBranchAddress("tVLooseDeepTau2017v1VSe", &tVLooseDeepTau2017v1VSe, &b_tVLooseDeepTau2017v1VSe);
   fChain->SetBranchAddress("tVLooseDeepTau2017v1VSjet", &tVLooseDeepTau2017v1VSjet, &b_tVLooseDeepTau2017v1VSjet);
   fChain->SetBranchAddress("tVLooseDeepTau2017v1VSmu", &tVLooseDeepTau2017v1VSmu, &b_tVLooseDeepTau2017v1VSmu);
   fChain->SetBranchAddress("tVTightDeepTau2017v1VSe", &tVTightDeepTau2017v1VSe, &b_tVTightDeepTau2017v1VSe);
   fChain->SetBranchAddress("tVTightDeepTau2017v1VSjet", &tVTightDeepTau2017v1VSjet, &b_tVTightDeepTau2017v1VSjet);
   fChain->SetBranchAddress("tVTightDeepTau2017v1VSmu", &tVTightDeepTau2017v1VSmu, &b_tVTightDeepTau2017v1VSmu);
   fChain->SetBranchAddress("tVVLooseDeepTau2017v1VSe", &tVVLooseDeepTau2017v1VSe, &b_tVVLooseDeepTau2017v1VSe);
   fChain->SetBranchAddress("tVVLooseDeepTau2017v1VSjet", &tVVLooseDeepTau2017v1VSjet, &b_tVVLooseDeepTau2017v1VSjet);
   fChain->SetBranchAddress("tVVLooseDeepTau2017v1VSmu", &tVVLooseDeepTau2017v1VSmu, &b_tVVLooseDeepTau2017v1VSmu);
   fChain->SetBranchAddress("tVVTightDeepTau2017v1VSe", &tVVTightDeepTau2017v1VSe, &b_tVVTightDeepTau2017v1VSe);
   fChain->SetBranchAddress("tVVTightDeepTau2017v1VSjet", &tVVTightDeepTau2017v1VSjet, &b_tVVTightDeepTau2017v1VSjet);
   fChain->SetBranchAddress("tVVTightDeepTau2017v1VSmu", &tVVTightDeepTau2017v1VSmu, &b_tVVTightDeepTau2017v1VSmu);
   fChain->SetBranchAddress("tVVVLooseDeepTau2017v1VSe", &tVVVLooseDeepTau2017v1VSe, &b_tVVVLooseDeepTau2017v1VSe);
   fChain->SetBranchAddress("tVVVLooseDeepTau2017v1VSjet", &tVVVLooseDeepTau2017v1VSjet, &b_tVVVLooseDeepTau2017v1VSjet);
   fChain->SetBranchAddress("tVVVLooseDeepTau2017v1VSmu", &tVVVLooseDeepTau2017v1VSmu, &b_tVVVLooseDeepTau2017v1VSmu);
   fChain->SetBranchAddress("tVZ", &tVZ, &b_tVZ);
   fChain->SetBranchAddress("tZTTGenDR", &tZTTGenDR, &b_tZTTGenDR);
   fChain->SetBranchAddress("tZTTGenEta", &tZTTGenEta, &b_tZTTGenEta);
   fChain->SetBranchAddress("tZTTGenMatching", &tZTTGenMatching, &b_tZTTGenMatching);
   fChain->SetBranchAddress("tZTTGenPhi", &tZTTGenPhi, &b_tZTTGenPhi);
   fChain->SetBranchAddress("tZTTGenPt", &tZTTGenPt, &b_tZTTGenPt);
   fChain->SetBranchAddress("tauVetoPt20Loose3HitsVtx", &tauVetoPt20Loose3HitsVtx, &b_tauVetoPt20Loose3HitsVtx);
   fChain->SetBranchAddress("tauVetoPt20TightMVALTVtx", &tauVetoPt20TightMVALTVtx, &b_tauVetoPt20TightMVALTVtx);
   fChain->SetBranchAddress("topQuarkPt1", &topQuarkPt1, &b_topQuarkPt1);
   fChain->SetBranchAddress("topQuarkPt2", &topQuarkPt2, &b_topQuarkPt2);
   fChain->SetBranchAddress("tripleEPass", &tripleEPass, &b_tripleEPass);
   fChain->SetBranchAddress("tripleMu10_5_5Pass", &tripleMu10_5_5Pass, &b_tripleMu10_5_5Pass);
   fChain->SetBranchAddress("tripleMu12_10_5Pass", &tripleMu12_10_5Pass, &b_tripleMu12_10_5Pass);
   fChain->SetBranchAddress("type1_pfMetEt", &type1_pfMetEt, &b_type1_pfMetEt);
   fChain->SetBranchAddress("type1_pfMetPhi", &type1_pfMetPhi, &b_type1_pfMetPhi);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEnDown", &type1_pfMet_shiftedPhi_JetEnDown, &b_type1_pfMet_shiftedPhi_JetEnDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEnUp", &type1_pfMet_shiftedPhi_JetEnUp, &b_type1_pfMet_shiftedPhi_JetEnUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEta0to3Down", &type1_pfMet_shiftedPhi_JetEta0to3Down, &b_type1_pfMet_shiftedPhi_JetEta0to3Down);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEta0to3Up", &type1_pfMet_shiftedPhi_JetEta0to3Up, &b_type1_pfMet_shiftedPhi_JetEta0to3Up);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEta0to5Down", &type1_pfMet_shiftedPhi_JetEta0to5Down, &b_type1_pfMet_shiftedPhi_JetEta0to5Down);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEta0to5Up", &type1_pfMet_shiftedPhi_JetEta0to5Up, &b_type1_pfMet_shiftedPhi_JetEta0to5Up);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEta3to5Down", &type1_pfMet_shiftedPhi_JetEta3to5Down, &b_type1_pfMet_shiftedPhi_JetEta3to5Down);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEta3to5Up", &type1_pfMet_shiftedPhi_JetEta3to5Up, &b_type1_pfMet_shiftedPhi_JetEta3to5Up);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetRelativeBalDown", &type1_pfMet_shiftedPhi_JetRelativeBalDown, &b_type1_pfMet_shiftedPhi_JetRelativeBalDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetRelativeBalUp", &type1_pfMet_shiftedPhi_JetRelativeBalUp, &b_type1_pfMet_shiftedPhi_JetRelativeBalUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetRelativeSampleDown", &type1_pfMet_shiftedPhi_JetRelativeSampleDown, &b_type1_pfMet_shiftedPhi_JetRelativeSampleDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetRelativeSampleUp", &type1_pfMet_shiftedPhi_JetRelativeSampleUp, &b_type1_pfMet_shiftedPhi_JetRelativeSampleUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetResDown", &type1_pfMet_shiftedPhi_JetResDown, &b_type1_pfMet_shiftedPhi_JetResDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetResUp", &type1_pfMet_shiftedPhi_JetResUp, &b_type1_pfMet_shiftedPhi_JetResUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetTotalDown", &type1_pfMet_shiftedPhi_JetTotalDown, &b_type1_pfMet_shiftedPhi_JetTotalDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetTotalUp", &type1_pfMet_shiftedPhi_JetTotalUp, &b_type1_pfMet_shiftedPhi_JetTotalUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_UnclusteredEnDown", &type1_pfMet_shiftedPhi_UnclusteredEnDown, &b_type1_pfMet_shiftedPhi_UnclusteredEnDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_UnclusteredEnUp", &type1_pfMet_shiftedPhi_UnclusteredEnUp, &b_type1_pfMet_shiftedPhi_UnclusteredEnUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEnDown", &type1_pfMet_shiftedPt_JetEnDown, &b_type1_pfMet_shiftedPt_JetEnDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEnUp", &type1_pfMet_shiftedPt_JetEnUp, &b_type1_pfMet_shiftedPt_JetEnUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEta0to3Down", &type1_pfMet_shiftedPt_JetEta0to3Down, &b_type1_pfMet_shiftedPt_JetEta0to3Down);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEta0to3Up", &type1_pfMet_shiftedPt_JetEta0to3Up, &b_type1_pfMet_shiftedPt_JetEta0to3Up);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEta0to5Down", &type1_pfMet_shiftedPt_JetEta0to5Down, &b_type1_pfMet_shiftedPt_JetEta0to5Down);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEta0to5Up", &type1_pfMet_shiftedPt_JetEta0to5Up, &b_type1_pfMet_shiftedPt_JetEta0to5Up);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEta3to5Down", &type1_pfMet_shiftedPt_JetEta3to5Down, &b_type1_pfMet_shiftedPt_JetEta3to5Down);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEta3to5Up", &type1_pfMet_shiftedPt_JetEta3to5Up, &b_type1_pfMet_shiftedPt_JetEta3to5Up);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetRelativeBalDown", &type1_pfMet_shiftedPt_JetRelativeBalDown, &b_type1_pfMet_shiftedPt_JetRelativeBalDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetRelativeBalUp", &type1_pfMet_shiftedPt_JetRelativeBalUp, &b_type1_pfMet_shiftedPt_JetRelativeBalUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetRelativeSampleDown", &type1_pfMet_shiftedPt_JetRelativeSampleDown, &b_type1_pfMet_shiftedPt_JetRelativeSampleDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetRelativeSampleUp", &type1_pfMet_shiftedPt_JetRelativeSampleUp, &b_type1_pfMet_shiftedPt_JetRelativeSampleUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetResDown", &type1_pfMet_shiftedPt_JetResDown, &b_type1_pfMet_shiftedPt_JetResDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetResUp", &type1_pfMet_shiftedPt_JetResUp, &b_type1_pfMet_shiftedPt_JetResUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetTotalDown", &type1_pfMet_shiftedPt_JetTotalDown, &b_type1_pfMet_shiftedPt_JetTotalDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetTotalUp", &type1_pfMet_shiftedPt_JetTotalUp, &b_type1_pfMet_shiftedPt_JetTotalUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_UnclusteredEnDown", &type1_pfMet_shiftedPt_UnclusteredEnDown, &b_type1_pfMet_shiftedPt_UnclusteredEnDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_UnclusteredEnUp", &type1_pfMet_shiftedPt_UnclusteredEnUp, &b_type1_pfMet_shiftedPt_UnclusteredEnUp);
   fChain->SetBranchAddress("vbfDeta", &vbfDeta, &b_vbfDeta);
   fChain->SetBranchAddress("vbfJetVeto20", &vbfJetVeto20, &b_vbfJetVeto20);
   fChain->SetBranchAddress("vbfJetVeto30", &vbfJetVeto30, &b_vbfJetVeto30);
   fChain->SetBranchAddress("vbfMass", &vbfMass, &b_vbfMass);
   fChain->SetBranchAddress("vbfMassWoNoisyJets", &vbfMassWoNoisyJets, &b_vbfMassWoNoisyJets);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetEC2Down", &vbfMassWoNoisyJets_JetEC2Down, &b_vbfMassWoNoisyJets_JetEC2Down);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetEC2Up", &vbfMassWoNoisyJets_JetEC2Up, &b_vbfMassWoNoisyJets_JetEC2Up);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetEta0to3Down", &vbfMassWoNoisyJets_JetEta0to3Down, &b_vbfMassWoNoisyJets_JetEta0to3Down);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetEta0to3Up", &vbfMassWoNoisyJets_JetEta0to3Up, &b_vbfMassWoNoisyJets_JetEta0to3Up);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetEta0to5Down", &vbfMassWoNoisyJets_JetEta0to5Down, &b_vbfMassWoNoisyJets_JetEta0to5Down);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetEta0to5Up", &vbfMassWoNoisyJets_JetEta0to5Up, &b_vbfMassWoNoisyJets_JetEta0to5Up);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetEta3to5Down", &vbfMassWoNoisyJets_JetEta3to5Down, &b_vbfMassWoNoisyJets_JetEta3to5Down);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetEta3to5Up", &vbfMassWoNoisyJets_JetEta3to5Up, &b_vbfMassWoNoisyJets_JetEta3to5Up);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetRelativeBalDown", &vbfMassWoNoisyJets_JetRelativeBalDown, &b_vbfMassWoNoisyJets_JetRelativeBalDown);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetRelativeBalUp", &vbfMassWoNoisyJets_JetRelativeBalUp, &b_vbfMassWoNoisyJets_JetRelativeBalUp);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetRelativeSampleDown", &vbfMassWoNoisyJets_JetRelativeSampleDown, &b_vbfMassWoNoisyJets_JetRelativeSampleDown);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetRelativeSampleUp", &vbfMassWoNoisyJets_JetRelativeSampleUp, &b_vbfMassWoNoisyJets_JetRelativeSampleUp);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetTotalDown", &vbfMassWoNoisyJets_JetTotalDown, &b_vbfMassWoNoisyJets_JetTotalDown);
   fChain->SetBranchAddress("vbfMassWoNoisyJets_JetTotalUp", &vbfMassWoNoisyJets_JetTotalUp, &b_vbfMassWoNoisyJets_JetTotalUp);
   fChain->SetBranchAddress("vbfMass_JetEC2Down", &vbfMass_JetEC2Down, &b_vbfMass_JetEC2Down);
   fChain->SetBranchAddress("vbfMass_JetEC2Up", &vbfMass_JetEC2Up, &b_vbfMass_JetEC2Up);
   fChain->SetBranchAddress("vbfMass_JetEta0to3Down", &vbfMass_JetEta0to3Down, &b_vbfMass_JetEta0to3Down);
   fChain->SetBranchAddress("vbfMass_JetEta0to3Up", &vbfMass_JetEta0to3Up, &b_vbfMass_JetEta0to3Up);
   fChain->SetBranchAddress("vbfMass_JetEta0to5Down", &vbfMass_JetEta0to5Down, &b_vbfMass_JetEta0to5Down);
   fChain->SetBranchAddress("vbfMass_JetEta0to5Up", &vbfMass_JetEta0to5Up, &b_vbfMass_JetEta0to5Up);
   fChain->SetBranchAddress("vbfMass_JetEta3to5Down", &vbfMass_JetEta3to5Down, &b_vbfMass_JetEta3to5Down);
   fChain->SetBranchAddress("vbfMass_JetEta3to5Up", &vbfMass_JetEta3to5Up, &b_vbfMass_JetEta3to5Up);
   fChain->SetBranchAddress("vbfMass_JetRelativeBalDown", &vbfMass_JetRelativeBalDown, &b_vbfMass_JetRelativeBalDown);
   fChain->SetBranchAddress("vbfMass_JetRelativeBalUp", &vbfMass_JetRelativeBalUp, &b_vbfMass_JetRelativeBalUp);
   fChain->SetBranchAddress("vbfMass_JetRelativeSampleDown", &vbfMass_JetRelativeSampleDown, &b_vbfMass_JetRelativeSampleDown);
   fChain->SetBranchAddress("vbfMass_JetRelativeSampleUp", &vbfMass_JetRelativeSampleUp, &b_vbfMass_JetRelativeSampleUp);
   fChain->SetBranchAddress("vbfMass_JetTotalDown", &vbfMass_JetTotalDown, &b_vbfMass_JetTotalDown);
   fChain->SetBranchAddress("vbfMass_JetTotalUp", &vbfMass_JetTotalUp, &b_vbfMass_JetTotalUp);
   fChain->SetBranchAddress("vbfNJets20", &vbfNJets20, &b_vbfNJets20);
   fChain->SetBranchAddress("vbfNJets30", &vbfNJets30, &b_vbfNJets30);
   fChain->SetBranchAddress("vbfj1eta", &vbfj1eta, &b_vbfj1eta);
   fChain->SetBranchAddress("vbfj1pt", &vbfj1pt, &b_vbfj1pt);
   fChain->SetBranchAddress("vbfj2eta", &vbfj2eta, &b_vbfj2eta);
   fChain->SetBranchAddress("vbfj2pt", &vbfj2pt, &b_vbfj2pt);
   fChain->SetBranchAddress("vispX", &vispX, &b_vispX);
   fChain->SetBranchAddress("vispY", &vispY, &b_vispY);
   fChain->SetBranchAddress("idx", &idx, &b_idx);
   Notify();
}

Bool_t from_Cecile_skimmed::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void from_Cecile_skimmed::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t from_Cecile_skimmed::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef from_Cecile_skimmed_cxx
