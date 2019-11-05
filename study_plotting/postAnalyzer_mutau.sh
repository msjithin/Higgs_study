
./Make.sh postAnalyzer_mutau.C
./postAnalyzer_mutau.exe study_mutau_new.root ggh_aw_mutau.root GluGluHToTauTau GluGluHToTauTau mutau 0
echo "*************** root file made ***************"
FILE=GluGluHToTauTau_after_weights.root
if [ -f "$FILE" ]; then
    echo "$FILE exist"
    rm $FILE
else 
    echo "$FILE does not exist"
fi
hadd GluGluHToTauTau_after_weights.root ggh_aw_mutau.root

python makeplot_mutauh.py -lY -name Higgs_pt -cat 0 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 1 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 2 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 3 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 4 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 5 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 6 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 7 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 8 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 9 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 10 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 11 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 12 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 13 -ch mutau
python makeplot_mutauh.py -lY -name Higgs_pt -cat 14 -ch mutau 
                                                        
cp plot_* /afs/hep.wisc.edu/home/ms/public_html/boosted_study/study/
echo "plots copied....."
echo "*************** plots made ***************"
