#!/bin/bash

for module in {0..7}
do
	for ex in {0..6}
	do
		sup="cpp0$module/ex0$ex/main.cpp"
		if [ -f "$sup" ] ; then
			echo removing $sup
			rm $sup
		fi
	done
done
