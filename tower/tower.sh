#!/bin/sh

if [ "$#" -ne 2 ]
then
    exit 1
fi

case "$1" in
    ''|*[!0-9]*)
        exit 1
        ;;
esac

if [ "$2" != "square" ] && [ "$2" != "triangle" ]
then
    exit 1
fi

printf ' _________________\n'

if [ "$1" -gt 0 ]
then
    for i in $(seq 1 "$1")
    do
        if [ "$2" = "square" ]
        then
            printf '|  ___       ___  |\n'
            printf '| |_|_|     |_|_| |\n'
            printf '| |_|_|     |_|_| |\n'
            printf '|                 |\n'
        else
            printf '|                 |\n'
            printf '|   /\\       /\\   |\n'
            printf '|  /__\\     /__\\  |\n'
            printf '|                 |\n'
        fi
    done
fi

printf '|        _        |\n'
printf '|       | |       |\n'
printf '|       | |       |\n'
printf '|_______| |_______|\n'

exit 0
