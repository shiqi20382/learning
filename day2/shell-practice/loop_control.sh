#!/bin/bash

for number in 1 2 3 4 5                         # 依次遍历 1 到 5
do                                              # 开始 for 循环体
    if [ "$number" -eq 3 ]                       # 如果当前数字等于 3
    then                                        # 条件成立时执行下面的代码
        echo "跳过数字：$number"                  # 输出跳过提示
        continue                                 # 跳过本次循环剩余代码，直接进入下一次循环
    fi                                          # 结束数字等于 3 的判断

    if [ "$number" -eq 5 ]                       # 如果当前数字等于 5
    then                                        # 条件成立时执行下面的代码
        echo "循环到数字 5，结束循环"             # 输出结束提示
        break                                    # 立即结束整个循环
    fi                                          # 结束数字等于 5 的判断

    echo "正在处理数字：$number"                  # 输出没有被跳过的数字
done                                            # 结束 for 循环
