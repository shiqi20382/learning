#!/bin/bash

get_max(){
	local firstnum="$1"
	local secondnum="$2"
if  [ "$firstnum" -ge "$secondnum" ]
then
	echo "$firstnum"
else
	echo "$secondnum"
fi
}

max_number=$(get_max "$1" "$2")
echo "较大的数是：$max_number"

