#!/bin/bash
read -p "请输入一个整数: " number

if ! [[ "$number" =~ ^-?[0-9]+$ ]];then
	echo "错误，请输入整数，不能是字母或其他字符"
	exit 1
fi

if [ "$number" -gt 0 ]; then
	echo "你输入的是正数"
elif [ "$number" -lt 0 ]; then
	echo "你输入的是负数"
else
	echo "你输入的是0"
fi
