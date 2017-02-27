#!/bin/bash


print_status () {
	echo "list:"
	echo "$ARG"
	echo "is sorted:"
	echo "$RES"
	echo "line count:"
	echo "$LC"
}

RANGE=$(seq "$1")

while true;
do
	ARG=$(echo "$RANGE" | tr " " "\n" | perl -MList::Util=shuffle -e 'print shuffle<STDIN>' | tr "\n" " ")
	INSTR=$(./push_swap "$ARG")
	RES=$(echo "$INSTR" | ./checker "$ARG")
	LC=$(echo "$INSTR" | wc -l | tr -d " ")
	if [ "$RES" != "OK" ]
	then
		print_status
		break
	fi
	if [ "$LC" -gt $2 ]
	then
		print_status
		break
	fi
	echo "$LC"
done