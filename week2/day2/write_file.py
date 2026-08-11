result = ["bob,85\n","alice,92\n"]

with open("result.txt","w",encoding="utf-8")as file:
    file.writelines(result)

print("文件写入完成")