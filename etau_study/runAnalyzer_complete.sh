set -e

outFile="study_mutau_complete.root"
if [ -f "$outFile" ]; then
    rm $outFile
fi
hadd $outFile study_mt_1.root study_mt_2.root
cd plotting_script/
cp ../$outFile .
bash do_ind_plots.sh $outFile
bash postAnalyzer_mutau.sh $outFile
cd ..
