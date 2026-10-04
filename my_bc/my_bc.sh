#!/bin/sh

if [ "$#" -ge 1 ]
then
    echo "$(($1))"
    exit 0
fi

while IFS= read -r line
do
    echo "$(($line))"
done

exit 0
