#!/bin/bash

distory="$1"

if [ "$#" -ne 1 ] 
then
	echo "用法： $0 目录路径"
	exit 1
fi

if [ ! -d "$distory" ] 
then
	echo "错误：目录不存在"
	exit 1
fi

echo "找到目录: $distory"
