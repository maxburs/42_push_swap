#!/bin/bash


print_status () {
	echo "list:"
	echo "$ARG"
	echo "is sorted:"
	echo "$RES"
	echo "line count:"
	echo "$LC"
}

while true;
do
	ARG=$(./range_gen.sh 13)
	INSTR=$(./push_swap "$ARG")
	RES=$(echo "$INSTR" | ./checker "$ARG")
	LC=$(echo "$INSTR" | wc -l)
	if [ "$RES" != "OK" ]
	then
		print_status
		break
	fi
	if [ "$LC" -gt 5300 ]
	then
		print_status
		break
	fi
	echo "$LC"
	sleep 1
done