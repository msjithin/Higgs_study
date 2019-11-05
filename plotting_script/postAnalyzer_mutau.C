#include <TH2.h>
//#include "ComputeWG1Unc.h"

#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include "TMultiGraph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <TF1.h>
#include <TDirectoryFile.h>
#include <TRandom3.h>
#include "TLorentzVector.h"
#include "TString.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TKey.h"
#include "THashList.h"
#include "THStack.h"
#include "TPaveLabel.h"
#include "TFile.h"
//#include "myHelper.h"
//#include "tr_Tree.h"
//#include "ScaleFactor.h"
//#include "ZmmSF.h"
//#include "LumiReweightingStandAlone.h"
//#include "btagSF.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooFunctor.h"
#include "TGraph2D.h"
#include "TColor.h"
#include <vector>
typedef std::vector<double> NumV;

using namespace std;
Double_t Luminosity = 100000.0;//Lumi for inclusive
int main(int argc, char** argv)
{
  //std::cout<<"XXXXXXXXXXXXX This worked P1  XXXXXXXXXXXXX "<<'\n';
  std::string input = *(argv + 1);
  std::string output = *(argv + 2);
  std::string sample = *(argv + 3);
  std::string name = *(argv + 4);
  std::string channel = *(argv + 5);
  float tes=0;
  if (argc > 1) {
    tes = atof(argv[6]);
  }
  TFile *f_input = new TFile(input.c_str(), "READ");
  cout<<"************* "<<" Input file         "<<"************ "<<endl;
  cout<<"               "<< input.c_str()<<" "<<endl;
  cout<<"************* "<<" Output written to  "<<"************ "<<endl;
  cout<<"               "<<output.c_str()<<" "<<endl;
  cout<<"****************************************************** "<<endl;
  
  TH1F* nbevt = (TH1F*) f_input->Get("nEvents" );
  Double_t ngen = nbevt->GetBinContent(1);
  //  Double_t nFinal = nbevt->GetBinContent(12);

  std::cout<<"************* "<<"ngen = "<< ngen<<" ************* "<<'\n';
  if (ngen<1)  std::cout<<"XXXXXXXXXXXXX  "<<" check this one !!" << input.c_str()<<"  XXXXXXXXXXXXX "<<'\n';

  Double_t xs=1.0; Double_t weight=1.0; Double_t luminosity=Luminosity;
  Double_t LOtoNNLO_DY = 5765.4/4954.0;
  Double_t LOtoNNLO_Wjets = 61526.7/50380; 
  if (sample=="ZL" || sample=="ZTT" || sample=="ZJ" || sample=="ZLL"){ xs=LOtoNNLO_DY*4954.0; weight=luminosity*xs/ngen;}
  else if (sample=="DY_LO" || sample=="DY_LOext"){ xs=5765.4; weight=luminosity*xs/ngen;}
  else if (sample=="ZTT1"){ xs=LOtoNNLO_DY*1012.5; weight=luminosity*xs/ngen;}
  else if (sample=="ZTT2"){ xs=LOtoNNLO_DY*332.8; weight=luminosity*xs/ngen;}
  else if (sample=="ZTT3"){ xs=LOtoNNLO_DY*101.8; weight=luminosity*xs/ngen;}
  else if (sample=="ZTT4"){ xs=LOtoNNLO_DY*54.8; weight=luminosity*xs/ngen;}
  else if (sample=="TTJets") {xs=831.76; weight=luminosity*xs/ngen;}
  else if (sample=="TTTo2L2Nu" ) {xs=88.29; weight=luminosity*xs/ngen;}
  else if (sample=="TTToHadronic" ) {xs=377.96; weight=luminosity*xs/ngen;}
  else if (sample=="TTToSemiLeptonic" ) {xs=365.35; weight=luminosity*xs/ngen;}

  /*  else if (sample=="ZTTinc"){ xs=LOtoNNLO_DY*5765.4; weight=2.458677925;}
  else if (sample=="ZTT1jet"){ xs=LOtoNNLO_DY*1012.5; weight=0.893891808;}
  else if (sample=="ZTT2jet"){ xs=LOtoNNLO_DY*332.8; weight=0.990764241;}
  else if (sample=="ZTT3jet"){ xs=LOtoNNLO_DY*101.8; weight=1.562190668;}
  else if (sample=="ZTT4jet"){ xs=LOtoNNLO_DY*54.8; weight=0.488914871;}
  */
  else if (sample=="ZTTinc"){ xs=LOtoNNLO_DY*4954.0; weight=4.877;}
  else if (sample=="ZTT1jet"){ xs=LOtoNNLO_DY*1012.5; weight=1.09;}
  else if (sample=="ZTT2jet"){ xs=LOtoNNLO_DY*332.8; weight=1.23;}
  else if (sample=="ZTT3jet"){ xs=LOtoNNLO_DY*101.8; weight=2.28;}
  else if (sample=="ZTT4jet"){ xs=LOtoNNLO_DY*54.8; weight=0.54;}
  
  else if (sample=="WJetsToLNu_inc") {xs=61526.7; weight=57.29;}
  else if (sample=="W1JetsToLNu") {xs=11778.3638; weight=7.81;}
  else if (sample=="W2JetsToLNu") {xs=3849.21974; weight=17.047;}
  else if (sample=="W3JetsToLNu") {xs=1166.04787; weight=2.36;}
  else if (sample=="W4JetsToLNu") {xs=593.055246; weight=2.098;}

  //else if (sample=="WJetsToLNu_inc") {xs=61526.7; weight=luminosity*xs/ngen;}
  else if (sample=="WJetsToLNu_2J" || sample=="WJetsToLNu"){xs=LOtoNNLO_Wjets*50380; weight=luminosity*xs/ngen;} // {xs=50380.0; weight=luminosity*xs/ngen;}
  else if (sample=="WJetsToLNu_HT100To200") {xs=LOtoNNLO_Wjets*1345.0; weight=luminosity*xs/ngen;}
  else if (sample=="WJetsToLNu_HT200To400") {xs=LOtoNNLO_Wjets*359.7; weight=luminosity*xs/ngen;}
  else if (sample=="WJetsToLNu_HT400To600") {xs=LOtoNNLO_Wjets*48.91; weight=luminosity*xs/ngen;}
  else if (sample=="WJetsToLNu_HT600To800") {xs=LOtoNNLO_Wjets*12.04; weight=luminosity*xs/ngen;}
  else if (sample=="WJetsToLNu_HT800To1200") {xs=LOtoNNLO_Wjets*5.52; weight=luminosity*xs/ngen;}
  else if (sample=="WJetsToLNu_HT1200To2500") {xs=LOtoNNLO_Wjets*1.33; weight=luminosity*xs/ngen;}
  else if (sample=="WJetsToLNu_HT2500ToInf") {xs=LOtoNNLO_Wjets*0.0322; weight=luminosity*xs/ngen;}

  else if (sample=="GluGluHToTauTau") {xs=44.14*0.0627; weight=luminosity*xs/ngen;}
  else if (sample=="VBFHToTauTau") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
  else if (sample=="ZHToTauTau") {xs=0.884*0.0627; weight=luminosity*xs/ngen;}
  else if (sample=="WplusH125" || sample=="WPlusHToTauTau") {xs=0.052; weight=luminosity*xs/ngen;}
  else if (sample=="WminusH125" || sample=="WMinusHToTauTau") {xs=0.0334; weight=luminosity*xs/ngen;}
  else if (sample=="GluGluHToWWTo2L2Nu") {xs=1.001; weight=luminosity*xs/ngen;}
  else if (sample=="VBFHToWWTo2L2Nu") {xs=0.0858; weight=luminosity*xs/ngen;}

  else if (sample=="QCD") {xs=720648000*0.00042; weight=luminosity*xs/ngen;}
  else if (sample=="data_obs"){weight=1.0;}


  else if (sample=="dataset_1"){weight=1.0;}
  else if (sample=="dataset_2"){weight=1.0;}
  else if (sample=="dataset_3"){weight=1.0;}
  else if (sample=="dataset_4"){weight=1.0;}
  else if (sample=="dataset_5"){weight=1.0;} 
   
 
  else if (sample=="ZJetsToNuNu_HT100To200") {xs=280.92; weight=luminosity*xs/ngen;}
  else if (sample=="ZJetsToNuNu_HT200To400") {xs=77.64; weight=luminosity*xs/ngen;}
  else if (sample=="ZJetsToNuNu_HT400To600") {xs=10.671; weight=luminosity*xs/ngen;}
  else if (sample=="ZJetsToNuNu_HT600To800") {xs=2.5611; weight=luminosity*xs/ngen;}
  else if (sample=="ZJetsToNuNu_HT800To1200") {xs=1.1778; weight=luminosity*xs/ngen;}
  else if (sample=="ZJetsToNuNu_HT1200To2500") {xs=0.2874; weight=luminosity*xs/ngen;}
  else if (sample=="ZJetsToNuNu_HT2500ToInf") {xs=0.006933; weight=luminosity*xs/ngen;}
  
  else if (sample=="WZTo1L3Nu") {xs=3.05; weight=luminosity*xs/ngen;}
  else if (sample=="WZTo1L1Nu2Q") {xs=10.71; weight=luminosity*xs/ngen;}
  else if (sample=="WZTo2L2Q") {xs=5.595; weight=luminosity*xs/ngen;}
  else if (sample=="WZTo3LNu") {xs=4.43; weight=luminosity*xs/ngen;}
  
  else if (sample=="ST_tW_antitop") {xs=35.6; weight=luminosity*xs/ngen;}
  else if (sample=="ST_tW_top") {xs=35.6; weight=luminosity*xs/ngen;}
  else if (sample=="ST_t-channel_antitop") {xs=80.95*3*0.105; weight=luminosity*xs/ngen;}
  else if (sample=="ST_t-channel_top") {xs=136.02*3*0.105; weight=luminosity*xs/ngen;}
  
  else if (sample=="WWTo1L1Nu2Q" || sample=="WWToLNuQQ") {xs=10.71; weight=luminosity*xs/ngen;}
  else if (sample=="WWTo2L2Nu") {xs=12.178; weight=luminosity*xs/ngen;}
  else if (sample=="GluGluWWTo2L2Nu") {xs=0.59; weight=luminosity*xs/ngen;}
  else if (sample=="WWTo2L2Nu_DoubleScattering") {xs=1.62; weight=luminosity*xs/ngen;} //WWTo2L2Nu_DoubleScattering
  else if (sample=="WpWpJJ_EWK_QCD") {xs=0.02615; weight=luminosity*xs/ngen;}
  else if (sample=="WpWpJJ_EWK") {xs=0.02615; weight=luminosity*xs/ngen;}
  else if (sample=="WpWpJJ_QCD") {xs=0.02615; weight=luminosity*xs/ngen;}

  else if (sample=="ZZTo2L2Q") {xs=3.22; weight=luminosity*xs/ngen;}
  else if (sample=="ZZTo2Q2Nu") {xs=4.03; weight=luminosity*xs/ngen;}
  else if (sample=="ZZTo4L") {xs=1.212; weight=luminosity*xs/ngen;}
  else if (sample=="ZZTo2L2Nu") {xs=0.564; weight=luminosity*xs/ngen;}
  
  else if (sample=="WWW") {xs=0.2086; weight=luminosity*xs/ngen;}
  else if (sample=="WWZ") {xs=0.1651; weight=luminosity*xs/ngen;}
  else if (sample=="WZZ") {xs=0.05565; weight=luminosity*xs/ngen;}
  else if (sample=="ZZZ") {xs=0.01398; weight=luminosity*xs/ngen;}

  else if (sample=="ggH125") {xs=48.58*0.0627; weight=luminosity*xs/ngen;}
  else if (sample=="VBF125") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
  else if (sample=="ggH120") {xs=52.22*0.0698; weight=luminosity*xs/ngen;}
  else if (sample=="VBF120") {xs=3.935*0.0698; weight=luminosity*xs/ngen;}
  else if (sample=="ggH130") {xs=45.31*0.0541; weight=luminosity*xs/ngen;}
  else if (sample=="VBF130") {xs=3.637*0.0541; weight=luminosity*xs/ngen;}
  else if (sample=="ggH110") {xs=57.90*0.0791; weight=luminosity*xs/ngen;}
  else if (sample=="VBF110") {xs=4.434*0.0791; weight=luminosity*xs/ngen;}
  else if (sample=="ggH140") {xs=36.0*0.0360; weight=luminosity*xs/ngen;}
  else if (sample=="VBF140") {xs=3.492*0.0360; weight=luminosity*xs/ngen;}
  else if (sample=="ggH_WW125") {xs=48.58*0.2137*0.3258; weight=luminosity*xs/ngen;}
  else if (sample=="VBF_WW125") {xs=3.782*0.2137*0.3258; weight=luminosity*xs/ngen;}
  else if (sample=="WplusH120") {xs=0.9558*0.0698; weight=luminosity*xs/ngen;}
  else if (sample=="WplusH130") {xs=0.7414*0.0541; weight=luminosity*xs/ngen;}
  else if (sample=="WplusH110") {xs=1.335*0.0791; weight=luminosity*xs/ngen;}
  else if (sample=="WplusH140") {xs=0.6308*0.0360; weight=luminosity*xs/ngen;}
  else if (sample=="WminusH120") {xs=0.6092*0.0698; weight=luminosity*xs/ngen;}
  else if (sample=="WminusH130") {xs=0.4676*0.0541; weight=luminosity*xs/ngen;}
  else if (sample=="WminusH110") {xs=0.8587*0.0791; weight=luminosity*xs/ngen;}
  else if (sample=="WminusH140") {xs=0.394*0.0360; weight=luminosity*xs/ngen;}
  else if (sample=="ZH120") {xs=0.9939*0.0698; weight=luminosity*xs/ngen;}
  else if (sample=="ZH125") {xs=0.8839*0.0627; weight=luminosity*xs/ngen;}
  else if (sample=="ZH130") {xs=0.7899*0.0541; weight=luminosity*xs/ngen;}
  else if (sample=="ZH110") {xs=1.309*0.0791; weight=luminosity*xs/ngen;}
  else if (sample=="ZH140") {xs=0.6514*0.0360; weight=luminosity*xs/ngen;}
  else if (sample=="WGLNu") {xs=489.0; weight=luminosity*xs/ngen;}
  else if (sample=="WGstarMuMu") {xs=2.793; weight=luminosity*xs/ngen;}
  else if (sample=="WGstarEE") {xs=3.526; weight=luminosity*xs/ngen;}

  else if (sample=="EWKWMinus" || sample=="EWKWMinus2Jets") {xs=20.25; weight=luminosity*xs/ngen;}
  else if (sample=="EWKWPlus" || sample=="EWKWPlus2Jets") {xs=25.62; weight=luminosity*xs/ngen;}
  else if (sample=="EWKZLL" || sample=="EWKZ2Jets_ZToLL" || sample=="EWKZLL_TT" || sample=="EWKZLL_J" || sample=="EWKZLL_L" || sample=="EWKZLL_LL") {xs=3.987; weight=luminosity*xs/ngen;}
  else if (sample=="EWKZNuNu" || sample=="EWKZ2Jets_ZToNuNu" || sample=="EWKZNuNu_TT" || sample=="EWKZNuNu_J" || sample=="EWKZNuNu_L" || sample=="EWKZNuNu_LL") {xs=10.01; weight=luminosity*xs/ngen;}

  else {
    cout<<"Attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    cout<<"***********                                  *****************"<<endl;
    cout<<"***********"<<sample.c_str()<<"  NOT found in sample list ************"<<endl;
    cout<<"***********                                  *****************"<<endl;
    cout<<"Attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
  }
  
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(10);
  //std::cout<<"XXXXXXXXXXXXX  line 213   XXXXXXXXXXXXX "<<'\n';
  std::cout<<" weight = " << weight<<endl;
  TFile* outputFile = new TFile(output.c_str(), "RECREATE");
  //outputFile->cd();
  //std::cout<<"XXXXXXXXXXXXX  line 217   XXXXXXXXXXXXX "<<'\n';
  
  Double_t net_weight = weight;
  TH1F* histo_Hpt_gen = (TH1F*)((TH1F*)f_input->Get("Higgs_pt_gen"))->Clone("Higgs_pt_gen_orgBinning");
  TH1F* histo_nEvents = (TH1F*)((TH1F*)f_input->Get("nEvents"))->Clone();
  TH1F* histo_dr_gen  = (TH1F*)((TH1F*)f_input->Get("dr_gen"))->Clone();
  TH1F* histo_Higgs_mass_gen = (TH1F*)((TH1F*)f_input->Get("Higgs_mass_gen"))->Clone();
  TH1F* histo_HiggsPt_0 = (TH1F*)((TH1F*)f_input->Get("HiggsPt_0"))->Clone();
  TH1F* histo_HiggsPt_1 = (TH1F*)((TH1F*)f_input->Get("HiggsPt_1"))->Clone();
  TH1F* histo_HiggsPt_2 = (TH1F*)((TH1F*)f_input->Get("HiggsPt_2"))->Clone();
  TH1F* histo_HiggsPt_3 = (TH1F*)((TH1F*)f_input->Get("HiggsPt_3"))->Clone();
  TH1F* histo_HiggsPt_4 = (TH1F*)((TH1F*)f_input->Get("HiggsPt_4"))->Clone();
  TH1F* histo_HiggsPt_5 = (TH1F*)((TH1F*)f_input->Get("HiggsPt_5"))->Clone();
  TH1F* histo_HiggsPt_6 = (TH1F*)((TH1F*)f_input->Get("HiggsPt_6"))->Clone();

  //Double_t  Pt_Bins[36]={0.0, 10,  20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 450, 500, 600, 800, 1000};
  Double_t  Pt_Bins[26]={0.0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 450, 500, 600, 800, 1000};

  //TH1F* h_Hpt_gen=histo_Hpt_gen->Rebin(35, Pt_Bins);
  //h_Hpt_gen->Scale(net_weight);
  TH1F *h_Hpt_gen_org = (TH1F*)histo_Hpt_gen->Rebin(25,"Higgs_pt_gen_org", Pt_Bins);  
  TH1F *h_Hpt_gen   = (TH1F*)histo_Hpt_gen->Rebin(25,"Higgs_pt_gen", Pt_Bins);
  TH1F *h_HiggsPt_0 = (TH1F*)histo_HiggsPt_0->Rebin(25,"Higgs_pt_0", Pt_Bins);
  TH1F *h_HiggsPt_1 = (TH1F*)histo_HiggsPt_1->Rebin(25,"Higgs_pt_1", Pt_Bins);
  TH1F *h_HiggsPt_2 = (TH1F*)histo_HiggsPt_2->Rebin(25,"Higgs_pt_2", Pt_Bins);
  TH1F *h_HiggsPt_3 = (TH1F*)histo_HiggsPt_3->Rebin(25,"Higgs_pt_3", Pt_Bins);
  TH1F *h_HiggsPt_4 = (TH1F*)histo_HiggsPt_4->Rebin(25,"Higgs_pt_4", Pt_Bins);
  TH1F *h_HiggsPt_5 = (TH1F*)histo_HiggsPt_5->Rebin(25,"Higgs_pt_5", Pt_Bins);
  TH1F *h_HiggsPt_6 = (TH1F*)histo_HiggsPt_6->Rebin(25,"Higgs_pt_6", Pt_Bins);

  histo_nEvents->Scale(net_weight);
  histo_dr_gen->Scale(net_weight);
  histo_Higgs_mass_gen->Scale(net_weight);
  h_HiggsPt_0->Scale(net_weight);
  h_HiggsPt_1->Scale(net_weight);
  h_HiggsPt_2->Scale(net_weight);
  h_HiggsPt_3->Scale(net_weight);
  h_HiggsPt_4->Scale(net_weight);
  h_HiggsPt_5->Scale(net_weight);
  h_HiggsPt_6->Scale(net_weight);

  h_Hpt_gen_org->Scale(net_weight);
  if (channel!="mutau")  h_Hpt_gen_org->Scale(0);

  if (channel=="mutau")  h_Hpt_gen->Scale(net_weight*0.23);
  if (channel=="etau")   h_Hpt_gen->Scale(net_weight*0.23);
  if (channel=="tautau") h_Hpt_gen->Scale(net_weight*0.41);
  if (channel=="emu")    h_Hpt_gen->Scale(net_weight*0.06);
  
  //histo_Hpt_gen->Write();
  //histo_nEvents->Write();
  //histo_dr_gen->Write();
  //histo_Higgs_mass_gen->Write();

  h_Hpt_gen_org->Write();
  h_Hpt_gen->Write();
  h_HiggsPt_0->Write();
  h_HiggsPt_1->Write();
  h_HiggsPt_2->Write();
  h_HiggsPt_3->Write();
  h_HiggsPt_4->Write();
  h_HiggsPt_5->Write();
  h_HiggsPt_6->Write();

  //std::cout<<"XXXXXXXXXXXXX  line 223   XXXXXXXXXXXXX "<<'\n';
  f_input->Close();
  outputFile->Close();
}


