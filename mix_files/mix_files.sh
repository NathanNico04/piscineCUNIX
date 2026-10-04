#!/bin/sh

if [ "$#" -ne 2 ]
then
    echo "Usage: mix_files file1 file2" >&2
    exit 1
fi

if [ ! -r "$1" ] || [ ! -r "$2" ]
then
    exit 1
fi

exec 3< "$1"
exec 4< "$2"

while :
do
    ok1=1
    ok2=1
    IFS= read -r line1 <&3 || ok1=0
    IFS= read -r line2 <&4 || ok2=0
    if [ "$ok1" -eq 0 ] && [ "$ok2" -eq 0 ]
    then
        break
    fi
    [ "$ok1" -eq 1 ] && printf '%s\n' "$line1"
    [ "$ok2" -eq 1 ] && printf '%s\n' "$line2"
done

exec 3<&-
exec 4<&-

exit 0
