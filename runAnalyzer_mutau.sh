
./rootcom Analyzer_mutau analyze_mutau
start=`date +%s`
./analyze_mutau /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_08Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191008_134724/0000/ ggh_mt_new0.root -1 1000 2018_test
./analyze_mutau /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_08Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191008_134724/0001/ ggh_mt_new1.root -1 1000 2018_test
end=`date +%s`
runtime=$((end-start))
echo "Runtime = $runtime"
FILE=GGHtoTauTau_mt_new.root
if [ -f "$FILE" ]; then
    echo "$FILE exist"
    rm $FILE
else
    echo "$FILE does not exist"
fi
hadd GGHtoTauTau_mt_new.root ggh_mt_new0.root ggh_mt_new1.root
