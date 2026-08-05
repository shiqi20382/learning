#!/bin/bash

pwd_log="$1"

if [ "$pwd_log" -ne 1 ]
then
	echo "用法：$0 日志文件路径"
	exit 1
fi

if [ ! -f "$pwd_log" ]
then
	echo "错误： $pwd_log日志文件不存在"
	exit 1
fi

info_count=$(grep -c  "INFO" "$pwd_log")
warning_count=$( grep -c  "WAR" "$pwd_log" )
error_count=$( grep -c  "ERROR" "$pwd_log")

echo "INFO出现 $info_count 次，WAR出现 $warning_count 次，ERROR出现 $error_count 次"

error_log="errors_$(date +%F).log"
grep "ERROR" "$pwd_log" > "$error_log"
echo "错误日志已写入  $error_log"

