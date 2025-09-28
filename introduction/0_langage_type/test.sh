#!/bin/bash

echo Let\'s test this shit

NC="\033[0m"

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
CYAN="\033[0;36m"
WHITE="\033[0;37m"

if (( $# == 0 )) ; then 
	echo Testing for all
	export to_test="ft_strlen.c ft_memcpy.c ft_strToLower.c isHot.c ft_strToUpper.c"
else
	export to_test=$@
fi 

echo Functions to test : $to_test

sleep 1

pretty_output() {
	case $2 in
		"SUCCESS") echo -e "$1 $GREEN HAS COMPILED AND WAS TESTED WITH SUCCESS !$NC" ;;
		"FAILED")  echo -e "$1 $RED HAS FAILED, RETRY...$NC" ;;
	esac
}

for ARGS in \
	"ft_strlen.c" \
	"ft_strToUpper.c" \
	"ft_strToLower.c" \
	"ft_memcpy.c" \
	"isHot.c"
do
	for i in $to_test
	do
		if [ $i == $ARGS ] ; then
			echo TESTING $i
			program=$(echo $i | tr -d ".c")
			puser="User$program"
			pcorr="Corr$program"
			gcc -Wall -Wextra -Werror pastouche/main.c $i -o $puser > user.log
			if [ $? -ne 0 ]; then
				echo "$YELLOW [WARNING] : Compilation failed$NC"
				pretty_output $ARGS FAILED
				continue
			fi
			gcc -Wall -Wextra -Werror pastouche/main.c $i -o $pcorr > corr.log
			./$puser >> user.log
			./$pcorr >> corr.log
			nombre_de_traces=$(ls traces/* | wc -l)
			trace_name="trace_$program'_'$nombre_de_traces'.log'"
			diff -q user.log corr.log > $trace_name
			rm user.log
			rm corr.log
			n=$(cat $trace_name | wc -l)
			mv $trace_name traces
			if (( n == 0 )) ; then
				pretty_output $ARGS SUCCESS
			else
				pretty_output $ARGS FAILED
				echo Check the difference in traces
			fi
			rm $puser
			rm $pcorr
		fi
	done
done
