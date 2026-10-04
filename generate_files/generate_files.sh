#!/bin/sh

filename="default"
number=1
extension="txt"

while [ $# -gt 0 ]; do
    case "$1" in
        -f|--filename)
            if [ -z "$2" ]; then
                exit 1
            fi
            filename="$2"
            shift 2;;
        -n|--number)
            if [ -z "$2" ]; then
                exit 1
            fi
            number="$2"
            shift 2;;
        -e|--extension)
            if [ -z "$2" ]; then
                exit 1
            fi
            extension="$2"
            shift 2;;
        *)
            exit 1;;
    esac
done

for i in $(seq 1 "$number"); do
    touch -- "$filename-$i.$extension"
done
