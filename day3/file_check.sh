#!/bin/bash

read -p "请输入要检查的文件名：" file_name

if [ ! -f "$file_name" ]
then
	echo "$file_name 文件不存在"
	exit 1
else
	echo "$file_name 在 $(pwd)"
fi
