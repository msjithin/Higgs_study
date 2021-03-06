#!/usr/bin/env python
import ROOT
import re
from array import array
from sys import argv
import ROOT as Root
import csv
from math import sqrt
from math import pi
import datetime
import argparse


parser = argparse.ArgumentParser()
parser.add_argument("-name",
                    help="name of hist to be plotted")

parser.add_argument("-xaxis",
                    help="x axis label")

parser.add_argument("-lY", "--logYaxis", action="store_true",
                    help="set y axis log scale")

parser.add_argument("-pi", "--piAxis", action="store_true",
                    help="set x axis in intervals of pi")

parser.add_argument("-nL", "--noLegend", action="store_true",
                    help="remove legend from histogram")

parser.add_argument("-cat", "--category",
                    help="pick reco histogram category")

parser.add_argument("-ch", "--channel",
                    help="pick decay channel")

now = datetime.datetime.now()
args =  parser.parse_args()
histoname=args.name
category_=args.category
xaxis_label=args.xaxis
channel_=args.channel

print "Item / histogram name = ", histoname
print "histo 1               = ", histoname+"_gen"
print "histo 2               = ", histoname+"_"+category_

if (args.logYaxis):
  yaxisLog = 1
else :
  yaxisLog = 0

if (args.noLegend):
  noLegend = 1
else :
  noLegend = 0
  
if (args.piAxis):
  piAxis = 1
else :
  piAxis = 0


def add_lumi():
    lowX=0.50
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.50, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   32 )#12
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.05)
    lumi.SetTextFont (   42 )
    if channel_=="combined":
      lumi.AddText("4 channels combined 2018, 100 fb^{-1} (13 TeV)")
    if channel_=="mutau":
      lumi.AddText("#mu#tau_{h} 2018, 100 fb^{-1} (13 TeV)")
    if channel_=="etau":
      lumi.AddText("e#tau_{h} 2018, 100 fb^{-1} (13 TeV)")
    if channel_=="tautau":
      lumi.AddText("#tau_{h}#tau_{h} 2018, 100 fb^{-1} (13 TeV)")
    if channel_=="emu":
      lumi.AddText("e#mu 2018, 100 fb^{-1} (13 TeV)")
    return lumi

def add_CMS():
    lowX=0.21
    lowY=0.70
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.08)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi

def add_Preliminary():
    lowX=0.21
    lowY=0.63
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextFont (   40 )
    lumi.SetTextSize(0.06)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Preliminary")
    return lumi

def make_legend():
        output = ROOT.TLegend(0.75, 0.65, 0.92, 0.84, "", "brNDC")
        #output = ROOT.TLegend(0.2, 0.1, 0.47, 0.65, "", "brNDC")
        output.SetLineWidth(1)
        output.SetLineStyle(1)
        output.SetFillStyle(0)
        output.SetBorderSize(1)
        output.SetTextFont(42)
        return output

ROOT.gStyle.SetFrameLineWidth(1)
ROOT.gStyle.SetLineWidth(2)
ROOT.gStyle.SetOptStat(0)

c=ROOT.TCanvas("canvas","",0,0,1200,1200)
c.cd()

if channel_=="mutau":
  OutFile=ROOT.TFile("ggh_aw_mutau.root","r")
if channel_=="etau":
  OutFile=ROOT.TFile("ggh_aw_etau.root","r") 
if channel_=="tautau":
  OutFile=ROOT.TFile("ggh_aw_tautau.root","r")
if channel_=="emu":
  OutFile=ROOT.TFile("ggh_aw_emu.root","r") 
if channel_=="combined":
  OutFile=ROOT.TFile("GluGluHToTauTau_after_weights.root","r") 

OutFile_1=ROOT.TFile("ggh_aw_mutau.root","r")

adapt=ROOT.gROOT.GetColor(12)
new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)

Histo_org=OutFile_1.Get(histoname+"_gen_org")
Histo_gen=OutFile.Get(histoname+"_gen")
Histo_rec=OutFile.Get(histoname+"_"+category_)
Histo_org.SetLineColor(1)
Histo_gen.SetLineColor(2)
Histo_rec.SetLineColor(4)

Histo_gen.GetXaxis().SetTitle("")
Histo_gen.GetXaxis().SetTitleSize(0)

if piAxis == 1:
  Histo_gen.GetXaxis().SetNdivisions(-405)
elif histoname=='Events_level_':
  Histo_gen.GetXaxis().SetNdivisions(-115)
else :
  Histo_gen.GetXaxis().SetNdivisions(-405)

Histo_gen.GetXaxis().SetLabelSize(0)
Histo_gen.GetYaxis().SetLabelFont(42)
Histo_gen.GetYaxis().SetLabelOffset(0.01)
Histo_gen.GetYaxis().SetLabelSize(0.04)
Histo_gen.GetYaxis().SetTitleSize(0.075)
Histo_gen.GetYaxis().SetTitleOffset(1.04)
Histo_gen.SetTitle("")
Histo_gen.GetYaxis().SetTitle("Events")
Histo_gen.GetYaxis().SetTitle("")

pad1 = ROOT.TPad("pad1","pad1",0,0.35,1,1)
pad1.Draw()
pad1.cd()
pad1.SetFillColor(0)
pad1.SetBorderMode(0)
pad1.SetBorderSize(1)
pad1.SetTickx(1)
pad1.SetTicky(1)
pad1.SetGridx()
pad1.SetLeftMargin(0.18)
pad1.SetRightMargin(0.05)
pad1.SetTopMargin(0.122)
pad1.SetBottomMargin(0.026)
pad1.SetFrameFillStyle(0)
pad1.SetFrameLineStyle(0)
pad1.SetFrameLineWidth(1)
pad1.SetFrameBorderMode(0)
pad1.SetFrameBorderSize(1)
if yaxisLog == 1 :
  pad1.SetLogy()  

#for k in range(1,Data.GetSize()-1):
    #s=ZH125.GetBinContent(k)
    ##b=VV.GetBinContent(k)+Fake.GetBinContent(k)
    #b=VV.GetBinContent(k)+ggH125.GetBinContent(k)+W.GetBinContent(k)
    #if (b<0):
	#b=0.000001
    #if (s/(0.00001+0.05*s+b)**0.5 > 0.8):
	#Data.SetBinContent(k,-1)
	#Data.SetBinError(k,-1)
Histo_gen.SetMarkerStyle(20)
Histo_rec.SetMarkerStyle(20)
Histo_org.SetMarkerStyle(29)

Histo_gen.SetMarkerSize(1.0)
Histo_rec.SetMarkerSize(1.0)
Histo_gen.SetMarkerColor(2)
Histo_rec.SetMarkerColor(4)
Histo_org.SetMarkerColor(1)

Histo_gen.GetXaxis().SetTitle("")
Histo_gen.GetYaxis().SetTitle("Events")
if yaxisLog == 1 :
  Histo_gen.SetMaximum(10*max(Histo_org.GetMaximum(),Histo_gen.GetMaximum()))
  Histo_gen.SetMinimum(0.01)
else :
  Histo_gen.SetMaximum(1.35*max(Histo_gen.GetMaximum(),Histo_rec.GetMaximum()))
  Histo_gen.SetMinimum(0.0)
#stack.SetLineColor(9)
Histo_gen.Draw("e1")
Histo_rec.Draw("e1same")
#Histo_org.Draw("e1same")

#errorBand.Draw("e2same")
#ZH125_mc.Draw("histsame")

#Histo_gen.Draw("e1same")
#errorBand.Draw("e2same")

legende=make_legend()
legende.AddEntry(Histo_gen,"gen","elp")
legende.AddEntry(Histo_rec,"reco","elp")

if noLegend == 0:
  legende.Draw()

l1=add_lumi()
l1.Draw("same")
l2=add_CMS()
l2.Draw("same")
l3=add_Preliminary()
l3.Draw("same")

pad1.RedrawAxis()
#print "Line 217 is okay"
categ  = ROOT.TPaveText(0.21, 0.5+0.013, 0.43, 0.70+0.155, "NDC")
categ.SetBorderSize(   0 )
categ.SetFillStyle(    0 )
categ.SetTextAlign(   12 )
categ.SetTextSize ( 0.06 )
categ.SetTextColor(    1 )
categ.SetTextFont (   42 )


c.cd()
pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.35);
pad2.SetTopMargin(0.05);
pad2.SetBottomMargin(0.35);
pad2.SetLeftMargin(0.18);
pad2.SetRightMargin(0.05);
pad2.SetTickx(1)
pad2.SetTicky(1)
pad2.SetFrameLineWidth(1)
#pad2.SetGridx()
pad2.SetGridy()
#pad2.SetLogy()
pad2.Draw()
pad2.cd()
h1=Histo_rec.Clone()
h3=Histo_gen.Clone()
#h1.SetMaximum(2.0)#FIXME(1.5)
#h1.SetMinimum(0.0)#FIXME(0.5)
h1.SetMarkerStyle(20)
h1.SetMarkerSize(1.0)
#h3.Sumw2()
#h1.Sumw2()
h1.SetStats(0)
h1.Divide(h3)
h1.GetXaxis().SetTitle("Higgs pt [GeV]")#(#vec{p_{T}}(#tau_{1})+#vec{p_{T}}(#tau_{2}))/(p_{T}(#tau_{1})+p_{T}(#tau_{2}))")#("m_{vis} (GeV)")#(#vec{p_{T}(#mu)}+#vec{p_{T}(#tau)})/(p_{T}(#mu)+p_{T}(#tau))")
#if (i+1==1 or i+1==2 or i+1==7 or i+1==8):
#	h1.GetXaxis().SetTitle("Electron p_{T} (GeV)")
#if (i+1==4 or i+1==10):
#     h1.GetXaxis().SetTitle("Muon p_{T} (GeV)")
#if (i+1==6 or i+1==12 or i+1==3 or i+1==5 or i+1==9 or i+1==11):
#     h1.GetXaxis().SetTitle("Tau p_{T} (GeV)")
h1.SetMarkerColor(1)
h1.SetLineColor(1)
h1.SetTitle("")
h1.GetXaxis().SetLabelSize(0.1)
h1.GetYaxis().SetTitle("ratio")
h1.GetYaxis().SetLabelSize(0.08)
print "ratio maximum = " , h1.GetMaximum()
#if ( h1.GetMaximum() > 0.15):
#  h1.SetMaximum(0.5)
#else :
#  h1.SetMaximum(0.15)
h1.SetMaximum(h1.GetMaximum())
h1.SetMinimum(0.0)#FIXME(0.5)
if piAxis ==1 :
  if firstarg == "Tau_phi_" or firstarg == "Muon_phi_" :
    h1.GetXaxis().SetBinLabel(21,"#pi");
    h1.GetXaxis().SetBinLabel(16,"#frac{#pi}{2}");
    h1.GetXaxis().SetBinLabel(11,"0");
    h1.GetXaxis().SetBinLabel(6,"#frac{-#pi}{2}");
    h1.GetXaxis().SetBinLabel(1,"-#pi");
  else :
    h1.GetXaxis().SetBinLabel(20,"#pi");
    h1.GetXaxis().SetBinLabel(15,"#frac{3#pi}{4}");
    h1.GetXaxis().SetBinLabel(10,"#frac{#pi}{2}");
    h1.GetXaxis().SetBinLabel(5,"#frac{#pi}{4}");
    h1.GetXaxis().SetBinLabel(1,"0");

if piAxis == 1:
  h1.GetXaxis().SetLabelOffset(0.01)
  h1.GetXaxis().SetLabelSize(0.15)
  h1.GetXaxis().SetNdivisions(-405)

elif histoname=='Events_level_':
  
  h1.GetXaxis().SetBinLabel(13,"METcut");
  h1.GetXaxis().SetBinLabel(12,"VisibleMass");
  h1.GetXaxis().SetBinLabel(11,"HiggsPt");
  h1.GetXaxis().SetBinLabel(10,"Mt cut");
  h1.GetXaxis().SetBinLabel(9,"BjetVeto");
  h1.GetXaxis().SetBinLabel(8,"ThirdLepVeto");
  h1.GetXaxis().SetBinLabel(7,"DeltaR");
  h1.GetXaxis().SetBinLabel(6,"opp. charge");
  h1.GetXaxis().SetBinLabel(5,"GoodTau");
  h1.GetXaxis().SetBinLabel(4,"GoodMuon");
  h1.GetXaxis().SetBinLabel(3,"mu Trg");
  h1.GetXaxis().SetBinLabel(2,"MET Filters");
  h1.GetXaxis().SetBinLabel(1,"No cuts");
  h1.GetXaxis().SetNdivisions(-115)
  h1.GetXaxis().LabelsOption("v")
  h1.GetXaxis().SetTitle(" cut flow")
  h1.SetMaximum(1.2)#FIXME(1.2)
  h1.SetMinimum(0.8)#FIXME(0.8)

elif histoname=='Cutflow_':

  h1.GetXaxis().SetBinLabel(6,"BjetVeto");
  h1.GetXaxis().SetBinLabel(5,"ThirdLepVeto");
  h1.GetXaxis().SetBinLabel(4,"DeltaR");
  h1.GetXaxis().SetBinLabel(3,"opp. charge");
  h1.GetXaxis().SetBinLabel(2,"GoodTau");
  h1.GetXaxis().SetBinLabel(1,"GoodMu");
  h1.GetXaxis().SetNdivisions(-115)
  h1.GetXaxis().LabelsOption("v")
  h1.GetXaxis().SetTitle(" cut flow")
  h1.SetMaximum(1.2)#FIXME(1.2)
  h1.SetMinimum(0.8)#FIXME(0.8)

else :
  h1.GetXaxis().SetNdivisions(-405)

  
h1.GetYaxis().SetNdivisions(5)
h1.GetXaxis().SetTitleFont(42)
h1.GetYaxis().SetTitleFont(42)


h1.GetXaxis().SetTitleSize(0.15)
h1.GetYaxis().SetTitleSize(0.15)
h1.GetYaxis().SetTitleOffset(0.56)
h1.GetXaxis().SetTitleOffset(1.1)






h1.Draw("e0p")
#h3.Draw("e2same")

c.cd()
#  pad1.Draw()

ROOT.gPad.RedrawAxis()

c.Modified()
#c.SaveAs("plots/"+firstarg+"_fr.pdf")
c.SaveAs("plot_"+histoname+"_"+channel_+"_"+category_+".png")


