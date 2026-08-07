#!/bin/bash

name="$1"

if [ "$#" -ne 1 ] 
then
	echo "用法： $0 姓名"
	exit 11
fi

echo "你好，$name"

for number in 1 2 3 4 5
do
	echo "当前的数字是 $number"
done

