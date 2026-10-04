#!/bin/sh

touch -- ' '
chmod 0644 -- ' '

touch -- '\'
chmod 0644 -- '\'

touch -- '--'
chmod 0644 -- '--'

touch -- '|'
chmod 0644 -- '|'

touch -- '"'
chmod 0644 -- '"'

touch -- "'"
chmod 0644 -- "'"

touch -- "--\$i*'\"\\"
chmod 0644 -- "--\$i*'\"\\"

touch -- '# Exams are fun!'
chmod 0644 -- '# Exams are fun!'

touch -- ';`kill -9 0`'
chmod 0644 -- ';`kill -9 0`'

path=""

for i in $(seq 1 50); do
    path="${path}${i}/"
done

mkdir -p "$path"
touch -- "${path}farfaraway"
chmod 0644 -- "${path}farfaraway"
