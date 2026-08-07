#!/bin/bash

target_path="${1:-/}"
threshold="${2:-80}"

if ! [[ "$threshold" =~ ^[0-9]+$ ]]
then
	echo "错误：报告阈值必须是整数"
	exit 1
fi

usage=$(df -P "$target_path" | awk 'NR == 2 {gsub(/%/, "", $5); print $5}')

if [ -z "$usage" ] 
then
	echo "错误：无法获取磁盘使用率"
	exit 1
fi

echo "当前磁盘使用率：${usage}%"

if [ "$usage" -ge "$threshold" ]
then
	echo "警告：磁盘使用率已达到或超过 ${threshold}%"
else
	echo "正常：磁盘使用率低于${threshold}%"
fi
