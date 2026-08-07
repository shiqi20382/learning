#!/bin/bash

for file in ./*.txt
do
	if [ -f "$file" ]
	then
		echo "找到普通文件: $file"
	fi
done
