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
			norminette $i | grep "Error!" > norm.log
			n=$(cat norm.log | wc -l)
			if (( n == 0 )) ; then
				pretty_output $ARGS NORM
			fi
			rm norm.log
			echo TESTING $i
			program=$(echo $i | tr -d ".c")
			puser="User$program"
			pcorr="Corr$program"
			gcc -Wall -Wextra -Werror pastouche/main.c *.c -o $puser > user.log
			if [ $? -ne 0 ]; then
				echo "$YELLOW [WARNING] : Compilation failed$NC"
				pretty_output $ARGS FAILED
				continue
			fi
			gcc -Wall -Wextra -Werror pastouche/main.c pastouche/srcs/*.c -o $pcorr > corr.log
			echo LS
			ls
			echo EXECUTION
			./$puser >> user.log
			./$pcorr >> corr.log
			echo USER LOG
			cat user.log
			echo CORR LOG
			cat corr.log
			nombre_de_traces=$(ls traces | wc -l)
			trace_name="trace_$program'_'$nombre_de_traces'.log'"
			diff -q user.log corr.log > $trace_name
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
done
