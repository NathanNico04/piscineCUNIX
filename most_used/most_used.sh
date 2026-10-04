#!/bin/sh

cut -d' ' -f1 ~/.bash_history | sort | uniq -c | sort -rn | head -n 10
