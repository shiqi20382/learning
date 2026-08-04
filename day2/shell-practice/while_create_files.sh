#!/bin/bash

count=1

while [ "$count" -le 10 ]
do
	touch "file_$count.txt"
	echo "已创建文件: file_$count.txt"
count=$((count + 1))
done
