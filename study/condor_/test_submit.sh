

./Make.sh skim_mutau.cc
start=`date +%s`
./skim_mutau.exe data data_test.root /hdfs/store/user/jmadhusu/_data2018_monoHiggs_11Sept/SingleMuon/crab_job_sMu2018A/190911_115053/0000/Ntuple_data2018_39.root 0
./skim_mutau.exe mc mc_test.root /hdfs/store/user/jmadhusu/_MC2018_Autumn18_monoHiggs_16Sept_2/DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/crab_job_DY1JetsToLL/190917_101433/0000/Ntuple_mc_1.root Z

if [ $? -eq 0 ]; then
    echo OK
    echo Completed new_test.root
else
    echo FAIL
fi
end=`date +%s`

runtime=$((end-start))

echo "Runtime = $runtime"
