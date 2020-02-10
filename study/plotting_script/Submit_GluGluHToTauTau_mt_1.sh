

start=`date +%s`
./analyze_mutau_study /hdfs/store/user/jmadhusu/MC2018_Autumn18_monoHiggs_23Jan/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/200122_102019/0000/ study_mt_1.root -1 1000 2018_test
end=`date +%s`
runtime=$((end-start))
echo "Runtime = $runtime"
