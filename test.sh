#!/bin/bash

echo Let\'s test this shit

echo ASCII ART THE MODULE

NC="\033[0m"

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
CYAN="\033[0;36m"
WHITE="\033[0;37m"

if (( $# == 0 )) ; then 
	echo No module given. Try for example : ./test.sh cpp00
	exit
else
	export module=$@
fi 

echo Exercices to test : $exercices

sleep 1

pretty_output() {
	echo 
	echo
	case $2 in
		"SUCCESS") echo -e "$GREEN [OK] $NC $1 $GREEN HAS COMPILED AND WAS TESTED WITH SUCCESS !$NC" ;;
		"FAILED")  echo -e "$RED [KO] $NC $1 $RED HAS FAILED, RETRY...$NC" ;;
		"NORM") echo -e "$RED [KO] $NC $YELLOW NORM ERROR $RED YOU SUCK $NC" ;;
	esac
	echo 
	echo
}

for ex in {0..6}
do
	path="$module/ex0$ex"
	prog="prog_$module"_"ex0$ex"
	if [ -f "$path/tests/main.cpp" ] ; then
		echo TESTING ex0$ex
		echo COMPILING
		make -C $path > make.log	
		if [ $? -ne 0 ]; then
			echo "$YELLOW [WARNING] : Compilation failed$NC"
			pretty_output Exercice0$ex FAILED
			continue
		fi
		./$prog >> user.log
		./$pcorr $program >> corr.log
		nombre_de_traces=$(ls traces | wc -l)
		trace_name="trace_$program"_"$nombre_de_traces".log""
		diff user.log corr.log > $trace_name
		echo $program
		rm user.log
		rm corr.log
		ok=$(cat $trace_name | wc -l)
		mv $trace_name traces
		if (( ok == 0 )) ; then
			pretty_output $ARGS SUCCESS
		else
			pretty_output $ARGS FAILED
			echo Check the difference in traces
		fi
		rm $puser
		rm $pcorr
	fi
done


