#!/bin/sh

for f in "$1"/* "$1"/.[!.]*
do
    [ -e "$f" ] || continue
    file "$f" | grep ASCII
done
