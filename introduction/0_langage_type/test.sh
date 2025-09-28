#!/bin/bash

echo Let\'s test this shit

NC="\033[0m"

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
CYAN="\033[0;36m"
WHITE="\033[0;37m"


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
	for i in $@
	do
		if [ $i == $ARGS ] ; then
			echo TESTING $i
			program=$(echo $i | tr -d ".c")
			puser="User$program"
			pcorr="Corr$program"
			gcc -Wall -Wextra -Werror pastouche/main.c $i -o $puser
			if [ $? -ne 0 ]; then
				echo "$YELLOW [WARNING] : Compilation failed$NC"
				pretty_output $ARGS FAILED
				continue
			fi
			gcc -Wall -Wextra -Werror pastouche/main.c $i -o $pcorr
			./puser > user.log
			./pcorr > corr.log
			nombre_de_traces=(ls traces/* | wc -l)
			diff -q user.log corr.log > trace_$program'_'$nombre_de_traces'.log'
			rm user.log
			rm corr.log
			n=$(cat trace_$program'_'$nombre_de_traces'.log' | wc -l)
			if (( n == 0 )) ; then
				pretty_output $ARGS SUCCESS
			else
				pretty_output $ARGS FAILED
				echo Check the difference in traces
			fi
		fi
	done
done
