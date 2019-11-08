# exit when any command fails
set -e

# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" command filed with exit code $?."' EXIT

./rootcom Analyzer_mutau_study analyze_mutau_study
start=`date +%s`
./analyze_mutau_study /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_07Nov/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191107_195327/0000/ study_mutau_110k.root 110000 100 2018_test
#./analyze_mutau_study /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_07Nov/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/191107_195327/0001/ study_mt_2.root -1 1000 2018_test
end=`date +%s`
runtime=$((end-start))
echo "Runtime = $runtime"
