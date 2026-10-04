#!/bin/sh

if [ "$#" -ne 1 ]
then
    echo "Usage: copy_save.sh file.csv" >&2
    exit 1
fi

if [ ! -f "$1" ]
then
    exit 1
fi

line=$(cat "$1")
old_ifs="$IFS"
IFS=','
set -- $line
IFS="$old_ifs"

for raw in "$@"
do
    f="$raw"
    while :; do
        case "$f" in
            ' '*) f="${f# }" ;;
            '	'*) f="${f#	}" ;;
            *) break ;;
        esac
    done
    while :; do
        case "$f" in
            * ' ') f="${f% }" ;;
            * '	') f="${f%	}" ;;
            *) break ;;
        esac
    done

    if [ -z "$f" ]
    then
        continue
    fi

    if [ ! -f "$f" ]
    then
        echo "$f: invalid file" >&2
        exit 2
    fi
done

mkdir -p save

for raw in "$@"
do
    f="$raw"
    while :; do
        case "$f" in
            ' '*) f="${f# }" ;;
            '	'*) f="${f#	}" ;;
            *) break ;;
        esac
    done
    while :; do
        case "$f" in
            * ' ') f="${f% }" ;;
            * '	') f="${f%	}" ;;
            *) break ;;
        esac
    done

    if [ -n "$f" ]
    then
        cp "$f" save/
    fi
done

exit 0
