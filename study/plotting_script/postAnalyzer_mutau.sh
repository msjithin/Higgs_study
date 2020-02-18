
inputFile=$1
./Make.sh postAnalyzer_mutau.C
./postAnalyzer_mutau.exe $inputFile ggh_aw_mutau.root GluGluHToTauTau GluGluHToTauTau mutau 0
echo "*************** root file made ***************"
inFile=ggh_aw_mutau.root

python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 0 -ch mutau
python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 1 -ch mutau
python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 2 -ch mutau
python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 3 -ch mutau
python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 4 -ch mutau
python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 5 -ch mutau
python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 6 -ch mutau

python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 7 -ch mutau
#python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 8 -ch mutau
#python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 9 -ch mutau
#python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 10 -ch mutau
#python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 11 -ch mutau
#python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 12 -ch mutau
#python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 15 -ch mutau
#python makeplot_mutauh.py -in $inFile -lY -name Higgs_pt -cat 16 -ch mutau


#mv plot_* /afs/hep.wisc.edu/home/ms/public_html/boosted_study/study_1/

