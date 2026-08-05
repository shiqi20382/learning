#!/bin/bash

add_numbers()
{
	local first_number="$1"
	local second_number="$2"
	local result=$((first_number + second_number))
	echo "$result"
}

if [ "$#" -ne 2 ]
then
	echo "用法：$0 第一个整数 第二个整数"
	exit 1
fi

if ! [[ "$1" =~ ^-?[0-9]+$ ]] || ! [[ "$2" =~ ^-?[0-9]+$ ]]
then
	echo "错误：请输入两个整数"
	exit 1
fi

sum=$(add_numbers "$1" "$2")

echo "$1 + $2 = $sum"
exit 0
