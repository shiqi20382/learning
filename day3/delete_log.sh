#!/bin/bash

find . -name  "*.log"

read -p "是否删除(yes/no):" answer

if [[ "$answer" == "yes" ]]
then
	rm -i ./*.log
else
	echo "已取消删除"
fi
