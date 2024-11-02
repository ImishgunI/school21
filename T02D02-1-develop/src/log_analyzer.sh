#!/bin/bash

cd ..
read -p "Enter the path to files.log: " path

if [ "$path" != "src/files.log" ]; then
	echo 'No such file in directory'
	exit 1
fi

countline=0
a=0
while IFS= read -r line
do
	if [ -z "$line" ];then
		continue
	else
		(( countline++ ))
	fi

done < $path

changes="$(grep -o '[^ ]*\.txt' $path | sort | uniq | wc -l)"

echo "$countline $changes $countline"

				
