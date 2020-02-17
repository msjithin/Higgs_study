# exit when any command fails
set -e
# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" command filed with exit code $?."' EXIT


#./rootcom Analyzer_mutau_updated analyze_mutau_updated
./rootcom new_analyzer analyze_mutau_updated
outFile="study_mutau_110k.root"
start=`date +%s`
nEvents=110000
sample='ggh'
plottingOn=0
while getopts n:s:p option
do
    case "${option}"
	in
	n) nEvents=${OPTARG};;
	p) plottingOn=1 ;;
	s) sample=${OPTARG};;
esac
done
if [ $sample == 'ggh' ] 
then
    outFile="study_mutau_110k_ggh.root"
    echo "ggh sample analysis....."
    ./analyze_mutau_updated /hdfs/store/user/jmadhusu/MC2018_Autumn18_monoHiggs_23Jan/GluGluHToTauTau_M125_13TeV_powheg_pythia8/crab_job_GluGluHToTauTau/200122_102019/0000/ $outFile $nEvents 1000 2018_test
elif [ $sample == 'vbf' ]
then
    outFile="study_mutau_110k_vbf.root"
    echo "vbf sample analysis....."
    ./analyze_mutau_updated /hdfs/store/user/jmadhusu/MC2018_Autumn18_monoHiggs_23Jan/VBFHToTauTau_M125_13TeV_powheg_pythia8/crab_job_VBFHToTauTau/200203_183458/0000/ $outFile $nEvents 1000 2018_test
fi


end=`date +%s`
runtime=$((end-start))
echo "Runtime = $runtime"


if [ "$plottingOn" == 1 ]
then
    echo "plotting ......... "
    cd plotting_script/
    cp ../$outFile .
    bash do_ind_plots.sh $outFile
    bash postAnalyzer_mutau.sh $outFile
    cp plot_* /afs/hep.wisc.edu/home/ms/public_html/boosted_study/study_1/
    cd ..
fi
#
#for arg in "$@"
#do
#    if [ "$arg" == "-p" ] || [ "$arg" == "--plot" ]
#    then
#	echo "plotting ......... "
#	cd plotting_script/
#	cp ../$outFile .
#	bash do_ind_plots.sh $outFile
#	bash postAnalyzer_mutau.sh $outFile
#	cp plot_* /afs/hep.wisc.edu/home/ms/public_html/boosted_study/study_1/
#	cd ..
#	
 #   fi
#done
