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
PASSED=$3

if [ "$3" ]
	then COUNT="$3"
	else COUNT=1
fi

while [ "$COUNT" -gt 0 ];
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
		let PASSED--
		if ! [ "$3" ]
		then
			print_status
			break
		fi
	fi
	echo "$LC"
	if [ "$3" ]
		then let COUNT--
	fi
done < <(true)

echo "$PASSED/$3"
