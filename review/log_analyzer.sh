#!/bin/bash

log_file="$1"

if [ "$#" -ne 1 ]
then
	echo "用法：$0 日志文件路径"
	exit 1
fi

if [ ! -f "$log_file" ]
then
	echo "日志文件不存在"
	exit 1
fi

count_keyword()
{
	local keyword="$1"
	local  file="$2"
	grep -c "$keyword" "$file"

}

INFO_count=$(count_keyword "INFO" "$log_file")
WARNING_count=$(count_keyword "WARNING" "$log_file")
ERROR_count=$(count_keyword "ERROR" "$log_file")

ERROR_file="error_$(date +%F).log"

grep "ERROR" "$log_file" >"$ERROR_file"

if [ "$?" -eq 0 ]
then
	echo "INFO出现了 $INFO_count 次"
	echo "WARNING出现了 $WARNING_count 次"
	echo "ERROR出现了 $ERROR_count 次"
	echo "所有ERROR信息日志已写入 $ERROR_file"
else
	echo "分析失败"
	exit 1
fi
