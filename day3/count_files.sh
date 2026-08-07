#!/bin/bash

if [ "$#" -ne 1 ]
then
	echo "用法: $0 目录路径"
	exit 1
fi

target_dir="$1"

if [ ! -d "$target_dir" ]
then
	echo "错误: 目录不存在:  $target_dir"
	exit 1
fi

file_count=$(find "$target_dir" -maxdepth 1 -type f | wc  -l)

echo "目录: $target_dir"
echo "普通文件数量: $file_count"

exit 0
