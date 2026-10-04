#!/bin/sh

if [ "$#" -ne 2 ]
then
    echo "Usage: extchange.sh 'ext1' 'ext2'" >&2
    exit 1
fi

found=0

for f in *
do
    [ -e "$f" ] || continue
    case "$f" in
        *.*.*)
            continue
            ;;
    esac
    case "$f" in
        *."$1") ;;
        *)
            continue
            ;;
    esac
    base=${f%.*}
    found=1
    echo "mv $f $base.$2"
    mv "$f" "$base.$2"
done

if [ "$found" -eq 0 ]
then
    exit 2
fi

exit 0
