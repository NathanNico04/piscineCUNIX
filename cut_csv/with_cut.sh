#!/bin/sh

if [ "$#" -ne 2 ]
then
    exit 1
fi

case "$2" in
    ''|*[!0-9]*)
        exit 1
        ;;
esac

if [ ! -f "$1" ]
then
    exit 1
fi

total=$(wc -l < "$1")

if [ "$2" -lt 1 ] || [ "$2" -gt "$total" ]
then
    exit 1
fi

line=$(head -n "$2" "$1" | tail -n 1)
col2=$(printf '%s\n' "$line" | cut -d';' -f2)
col3=$(printf '%s\n' "$line" | cut -d';' -f3)

echo "$col2 is $col3"

exit 0
