#!/bin/sh

seconds=$1

min=$((seconds / 60))
sec=$((seconds % 60))

printf "%d:%02d\n" "$min" "$sec"
