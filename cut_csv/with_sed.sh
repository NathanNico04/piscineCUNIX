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

sed -n "${2}s/^[^;]*;\([^;]*\);\([^;]*\);.*/\1 is \2/p" "$1"

exit 0
