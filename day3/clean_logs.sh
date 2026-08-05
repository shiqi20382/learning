#!/bin/bash

log_dir="$1"
days="$2"

if [ "$#" -ne 2 ]
then
	ehco "用法：$0 日志目录 保留天数"
	exit 1
fi

if [ ! -d  "$log_dir" ]
then
	echo  "目标目录不存在： $log_dir"
	exit 1
fi

if ! [[ "$days" =~ ^[0-9]+$ ]]
then
	echo "错误：保留天数必须是非负整数"
	exit 1
fi

echo  "以下 .log 文件超过 $days 天，将被删除:"

find "$log_dir" -type f -name "*.log" -mtime +"$days" -print

read -p "请确认删除" answer

if [ "$answer" = "y" ]
then
	find "$log_dir" -type f -name "*.log" -mtime +"$days" -print -delete
	echo "日志清理完成"
else
	echo "已取消删除"
fi
