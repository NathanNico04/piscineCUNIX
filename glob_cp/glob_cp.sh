#!/bin/sh

for f in *.?; do
    if [ -e "$f" ]; then
        keep=0
        for arg in "$@"; do
            case "$f" in
                *."$arg") 
		   keep=1 ;;
            esac
        done

        if [ "$keep" -eq 0 ]; then
            mv -- "$f" trash/
        fi
    fi
done

