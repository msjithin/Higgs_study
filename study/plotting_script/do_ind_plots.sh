


#inFile=study_mutau_110k.root
inFile=$1
cp ../$inFile .

python make_ind_plot_mutauh.py -in $inFile -cat gen_org -lY -name Higgs_pt -ch mutau -xaxis "Higgs pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat gen -lY -name Higgs_pt -ch mutau -xaxis "Higgs pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name mu_pt -ch mutau -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name mu_phi -ch mutau -xaxis "muon phi"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name mu_eta -ch mutau -xaxis "muon eta"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name tau_pt -ch mutau -xaxis "tau pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name tau_phi -ch mutau -xaxis "tau phi "
python make_ind_plot_mutauh.py -in $inFile -cat gen -name tau_eta -ch mutau -xaxis "tau eta"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name tauMom_pt -ch mutau -xaxis "tau pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name cutflow -ch mutau -lY -xaxis "cutflow"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name cutflow_n -ch mutau -lY -xaxis "cutflow_"
#python make_ind_plot_mutauh.py -in $inFile -cat gen -name nMu -ch mutau -xaxis "nMu"
#python make_ind_plot_mutauh.py -in $inFile -cat gen -name nTau -ch mutau -xaxis "nTau"
python make_ind_plot_mutauh.py -in $inFile -cat 1 -name mu_Charge -ch mutau -xaxis "mu Charge"
python make_ind_plot_mutauh.py -in $inFile -cat 2 -name mu_Charge -ch mutau -xaxis "mu Charge"
python make_ind_plot_mutauh.py -in $inFile -cat 3 -name mu_Charge -ch mutau -xaxis "mu Charge"
python make_ind_plot_mutauh.py -in $inFile -cat 1 -name tau_Charge -ch mutau -xaxis "tau Charge"
python make_ind_plot_mutauh.py -in $inFile -cat 2 -name tau_Charge -ch mutau -xaxis "tau Charge"
python make_ind_plot_mutauh.py -in $inFile -cat 3 -name tau_Charge -ch mutau -xaxis "tau Charge"


python make_ind_plot_mutauh.py -in $inFile -cat reco -name nMu -ch mutau -xaxis "nMu"
python make_ind_plot_mutauh.py -in $inFile -cat reco -name nTau -ch mutau -xaxis "nTau"
python make_ind_plot_mutauh.py -in $inFile -cat 1 -name nMu -ch mutau -xaxis "nMu"
python make_ind_plot_mutauh.py -in $inFile -cat 1 -name nTau -ch mutau -xaxis "nTau"
python make_ind_plot_mutauh.py -in $inFile -cat 2 -name nMu -ch mutau -xaxis "nMu"
python make_ind_plot_mutauh.py -in $inFile -cat 2 -name nTau -ch mutau -xaxis "nTau"
python make_ind_plot_mutauh.py -in $inFile -cat 3 -name nMu -ch mutau -xaxis "nMu"
python make_ind_plot_mutauh.py -in $inFile -cat 3 -name nTau -ch mutau -xaxis "nTau"
python make_ind_plot_mutauh.py -in $inFile -cat 4 -name nMu -ch mutau -xaxis "nMu"
python make_ind_plot_mutauh.py -in $inFile -cat 4 -name nTau -ch mutau -xaxis "nTau"
python make_ind_plot_mutauh.py -in $inFile -cat size -name muCand -ch mutau -xaxis "muCand size"
python make_ind_plot_mutauh.py -in $inFile -cat size -name tauCand -ch mutau -xaxis "tauCand size"

for value in {1..4}
do
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name muPt -ch mutau -xaxis "muPt"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name muEta -ch mutau -xaxis "muEta"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name muDz -ch mutau -xaxis "muDz"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name muD0 -ch mutau -xaxis "muD0"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name muonID -ch mutau -xaxis "muonID"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name relMuIso -ch mutau -xaxis "relMuIso"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name muCharge -ch mutau -xaxis "muCharge"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name tauPt -ch mutau -xaxis "tauPt"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name tauEta -ch mutau -xaxis "tauEta"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name tauIso -ch mutau -xaxis "tauIso"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name tauDecayMode -ch mutau -xaxis "tauDecayMode"
    python make_ind_plot_mutauh.py -in $inFile -cat $value -name tauCharge -ch mutau -xaxis "tauCharge"
done

python make_ind_plot_mutauh.py -in $inFile -cat 1 -name muPt_Hpt -ch mutau -lY -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat 2 -name muPt_Hpt -ch mutau -lY -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat 3 -name muPt_Hpt -ch mutau -lY -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat 4 -name muPt_Hpt -ch mutau -lY -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat 5 -name muPt_Hpt -ch mutau -lY -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat 6 -name muPt_Hpt -ch mutau -lY -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat 7 -name muPt_Hpt -ch mutau -lY -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name muPt_Hpt_2D -ch mutau -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat gen -name muPt_Hpt_2D_highPt -ch mutau -xaxis "muon pt GeV"
python make_ind_plot_mutauh.py -in $inFile -cat 1 -name muEta_Hpt -ch mutau -lY -xaxis "muon eta"
python make_ind_plot_mutauh.py -in $inFile -cat 2 -name muEta_Hpt -ch mutau -lY -xaxis "muon eta"
python make_ind_plot_mutauh.py -in $inFile -cat 3 -name muEta_Hpt -ch mutau -lY -xaxis "muon eta"
python make_ind_plot_mutauh.py -in $inFile -cat 4 -name muEta_Hpt -ch mutau -lY -xaxis "muon eta"
python make_ind_plot_mutauh.py -in $inFile -cat 5 -name muEta_Hpt -ch mutau -lY -xaxis "muon eta"
python make_ind_plot_mutauh.py -in $inFile -cat 6 -name muEta_Hpt -ch mutau -lY -xaxis "muon eta"
python make_ind_plot_mutauh.py -in $inFile -cat 7 -name muEta_Hpt -ch mutau -lY -xaxis "muon eta"

#mv plot_* /afs/hep.wisc.edu/home/ms/public_html/boosted_study/study_1/

#echo "*************** plots made ***************"
#echo "plots moved to boosted_study/study_1/ .... "
