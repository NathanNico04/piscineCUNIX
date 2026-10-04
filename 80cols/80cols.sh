#!/bin/sh

if [ "$#" -ne 1 ] || [ ! -f "$1" ] || [ ! -r "$1" ]
then
    exit 1
fi

while IFS= read -r line || [ -n "$line" ]
do
    if [ "${#line}" -ge 80 ]
    then
        printf '%s\n' "$line"
    fi
done < "$1"

exit 0
