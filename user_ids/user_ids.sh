#!/bin/sh

cut -d: -f3 /etc/passwd | sort -rn -u

exit 0
