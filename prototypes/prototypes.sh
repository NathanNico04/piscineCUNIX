#!/bin/sh

sed -n '/^[a-zA-Z_].*)$/{s/$/;/;p}' "$1"
