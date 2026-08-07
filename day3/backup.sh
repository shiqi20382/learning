#!/bin/bash

source_dir="$1"
backup_dir="/mnt/ssd/learning/day3/backups"
backup_name="backup_$(date +%F_+%H-%M-%S).tar.gz"

if [ "$#" -ne 1  ]
then
	echo "用法：$0 要备份的目录名"
	exit  1
fi

if [ ! -d "$source_dir" ]  
then
	echo "错误：目标目录不存在"
	exit 1
fi

mkdir -p "$backup_dir"

tar -czf "$backup_dir/$backup_name" "$source_dir"

if [ "$?" -eq 0 ] 
then
	echo "备份成功：$backup_dir/$backup_name"
else
	echo  "错误：备份失败"
	exit 1
fi

