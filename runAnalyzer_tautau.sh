
./rootcom Analyzer_tautau analyze_tautau
start=`date +%s`
./analyze_tautau /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_08Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191008_134724/0000/ ggh_tt_new0.root -1 1000 2018_test
./analyze_tautau /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_08Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191008_134724/0001/ ggh_tt_new1.root -1 1000 2018_test
end=`date +%s`
runtime=$((end-start))
echo "Runtime = $runtime"
FILE=GGHtoTauTau_tautau_new.root
if [ -f "$FILE" ]; then
    echo "$FILE exist"
    rm $FILE
else
    echo "$FILE does not exist"
fi

hadd GGHtoTauTau_tautau_new.root ggh_tt_new0.root ggh_tt_new1.root



#./analyze_tautau /nfs_scratch/jmadhusu/test_/ ggh_tt_new0.root -1 1000 2018_test
