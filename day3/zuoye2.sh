#!/bin/bash

read -p "请输入你的年龄：" user_age

if ! [[ "$user_age" =~ ^[0-9]+$ ]]
then
	echo "错误，年龄必须是非负整数"
	exit 1
fi

if [ "$user_age" -ge 18 ]
then
	echo "已成年"
else
	echo "未成年"
fi
