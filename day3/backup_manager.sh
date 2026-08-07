#!/bin/bash

source_dir="$1"
backup_dir="$2"

if [ "$#" -ne 2 ]
then
	echo "用法：$0 要备份的目录 备份保存目录"
	exit 1
fi

if [ ! -d "$source_dir" ]
then
	echo "$source_dir 不存在"
	exit 1
fi

mkdir -p "$backup_dir"
backup_name="backup_$(date +%F_%H-%M-%S).tar.gz" 
backup_file="$backup_dir/$backup_name"
tar -czf "$backup_file" "$source_dir"

if [ "$?" -eq 0 ]
then
	echo "已备份到$backup_file"
else
	echo "备份失败"
	exit 1
fi

backup_count=$(find "$backup_dir" -maxdepth 1 -type f -name "*.tar.gz" | wc -l)

echo "当前备份文件数量：$backup_count"


if [ "$backup_count" -gt 5 ] 
then

oldest_file=$(find "$backup_dir" -maxdepth 1 -type f -name "*.tar.gz" -printf "%T@ %p\n" | sort -n | head -n 1 | cut -d " " -f 2-)
	echo "最早的备份文件是：$oldest_file"
	read -p "备份超过 5 个，确认删除最早文件请输入 yes：" answer

	if [ "$answer" = "yes" ]
	then
		rm -i "$oldest_file"
		echo "已执行删除操作"
	else
		echo "已取消删除操作"
	fi
fi
exit 0


