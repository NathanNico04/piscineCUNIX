#!/bin/sh

walk()
{
    dir="$1"
    prefix="$2"
    set -- "$dir"/*
    while [ "$#" -gt 0 ]
    do
        entry="$1"
        shift
        name=${entry##*/}
        printf '%s+-- %s\n' "$prefix" "$name"
        if [ "$#" -eq 0 ]
        then
            newprefix="$prefix    "
        else
            newprefix="$prefix|   "
        fi
        if [ -d "$entry" ]
        then
            (walk "$entry" "$newprefix")
        fi
    done
}

if [ "$#" -eq 0 ]
then
    set -- "."
fi

for arg in "$@"
do
    if [ -d "$arg" ]
    then
        printf '%s\n' "$arg"
        (walk "$arg" "")
    else
        printf '%s [error opening dir]\n' "$arg"
    fi
done
