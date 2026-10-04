#!/bin/sh

while IFS= read -r line
do
    if printf '%s\n' "$line" | grep -Eq '^[[:space:]]*$'
    then
        echo "it is empty"
    elif printf '%s\n' "$line" | grep -Eq '^[a-zA-Z]+$'
    then
        echo "it is a word"
    elif printf '%s\n' "$line" | grep -Eq '^[0-9]$'
    then
        echo "it is a digit"
    elif printf '%s\n' "$line" | grep -Eq '^[0-9]{2,}$'
    then
        echo "it is a number"
    elif printf '%s\n' "$line" | grep -Eq '^[a-zA-Z0-9]+$'
    then
        echo "it is an alphanum"
    else
        echo "it is too complicated"
        exit 0
    fi
done

exit 0
