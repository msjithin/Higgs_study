
./rootcom Analyzer_mutau_study analyze_mutau_study
start=`date +%s`
./analyze_mutau_study /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_08Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191008_134724/0000/ study_mt_1.root -1 1000 2018_test
./analyze_mutau_study /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_08Oct/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191008_134724/0001/ study_mt_2.root -1 1000 2018_test
end=`date +%s`
runtime=$((end-start))
echo "Runtime = $runtime"
FILE=study_mutau_new.root
if [ -f "$FILE" ]; then
    echo "$FILE exist"
    rm $FILE
else
    echo "$FILE does not exist"
fi
hadd study_mutau_new.root study_mt_1.root study_mt_2.root
