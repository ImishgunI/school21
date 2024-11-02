#!/bin/bash

cd ..
echo 'Enter way: '
read way
read -p "Enter sentence: " sentence1
read -p "Enter new sentence: " new_sentence
sed -i "s|$sentence1|$new_sentence|g" $way
file="$way"
size="$(stat -c %s $way)"
time="$(date '+%Y-%m-%d %H:%M')"
sum="$(sha256sum $way | awk '{print $1}')"
cd src
echo "$file -  $size - $time - $sum - sha256" >> files.log

