#!/bin/bash

read -p "请输入要检查的文件或目录路径：" path

if [ -f "$path" ]; then
	echo "$path 是一个文件"
elif [ -d "$path" ]; then
	echo "$path 是一个目录"

elif [ -e "$path" ]; then
	echo "$path  存在，但不是一个普通文件或目录"
else
	echo "$path 不存在"
fi
