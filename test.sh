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
FAILED=0
TOTAL=1
COUNT=0

if [ "$3" ]
	then TOTAL="$3"
fi

trap 'echo "$((COUNT-FAILED))"/"$COUNT"; exit' INT

while [ $COUNT -lt $TOTAL ];
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
		let FAILED++
		if ! [ "$3" ]
		then
			print_status
			break
		fi
	fi
	echo "$LC"
	if [ "$3" ]
		then let COUNT++
	fi
done < <(true)

if [ "$3" ]
	then echo "$((COUNT-FAILED))"/"$COUNT"
fi
