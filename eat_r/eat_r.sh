#!/bin/sh

result=""
first=1

for arg in "$@"
do
    clean=$(printf '%s' "$arg" | tr -d 'rR')
    if [ "$first" -eq 1 ]
    then
        result="$clean"
        first=0
    else
        result="$result,$clean"
    fi
done

printf '%s\n' "$result"
