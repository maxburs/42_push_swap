#!/bin/bash

awk -v loop=$1 'BEGIN{
  srand()
  do {
    numb = 1 + int(rand() * 4294967296 - 2147483649)
    if (!(numb in prev)) {
       print numb
       prev[numb] = 1
       count++
    }
  } while (count<loop)
}' | tr '\n' ' '

#shuf() { awk 'BEGIN {srand(); OFMT="%.17f"} {print rand(), $0}' "$@" |sort -k1,1n | cut -d ' ' -f2-; };
#seq 1 $1 | shuf | tr '\n' ' '