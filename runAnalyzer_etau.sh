
./rootcom Analyzer_etau analyze_etau
start=`date +%s`
./analyze_etau /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_08Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191008_134724/0000/ ggh_et_new0.root -1 1000 2018_test
./analyze_etau /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_08Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191008_134724/0001/ ggh_et_new1.root -1 1000 2018_test
end=`date +%s`
runtime=$((end-start))
echo "Runtime = $runtime"
FILE=GGHtoTauTau_etau_new.root
if [ -f "$FILE" ]; then
    echo "$FILE exist"
    rm $FILE
else
    echo "$FILE does not exist"
fi
hadd GGHtoTauTau_etau_new.root ggh_et_new0.root ggh_et_new1.root
