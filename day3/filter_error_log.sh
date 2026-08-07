#!/bin/bash

input_file="$1"
output_file="errors_$(date +%F).log"
if [ "$#" -ne 1 ]
then
	echo "用法：$0 日志文件路径"
	exit 1
fi

if [ ! -f "$input_file" ]
then
	echo "错误：日志文件不存在：$input_file"
	exit 1
fi

grep "ERROR" "$input_file" > "$output_file"

if [ "$?" -eq 0 ]
then
	echo "筛选完成，结果已写入： $output_file"
else
	echo "没有找到 ERROR日志"
fi
