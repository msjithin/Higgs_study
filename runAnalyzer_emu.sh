
./rootcom Analyzer_Emu analyze_Emu
start=`date +%s`
./analyze_Emu /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_11Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191011_085057/0000/ ggh_em_new00.root -1 1000 2018_test
./analyze_Emu /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_11Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191011_085057/0001/ ggh_em_new11.root -1 1000 2018_test
end=`date +%s`
runtime=$((end-start))
echo "Runtime = $runtime"
FILE=GGHtoTauTau_em_new00.root
if [ -f "$FILE" ]; then
    echo "$FILE exist"
    rm $FILE
else
    echo "$FILE does not exist"
fi
hadd GGHtoTauTau_em_new00.root ggh_em_new00.root ggh_em_new11.root
