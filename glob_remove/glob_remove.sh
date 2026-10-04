#!/bin/sh

ext="$1"
if [ -z "$ext" ]; then
    ext="txt"
fi

found=0

for f in *."$ext"; do
    if [ -e "$f" ]; then
        rm -- "$f"
        found=1
    fi
done

if [ "$found" -eq 0 ]; then
    exit 1
fi
