
plottingOn="0"
for arg in "$@"
do
    if [ "$arg" == "-p" ] || [ "$arg" == "--plot" ]
    then 
	echo "plotting ..."
	plottingOn="1"
    else
	echo "not plotting, arguments : $arg"
    fi
done

if [ $plottingOn == "1" ]
then
    echo "plotting on "
fi

for value in {1..4}
do
    echo $value
done
