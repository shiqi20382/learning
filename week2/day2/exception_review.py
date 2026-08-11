try:
    with  open("not_exit.txt","r",encoding="utf-8")as file:
        content = file.read()
        print(content)

except FileNotFoundError:
    print("错误，文件不存在")
except Exception as error:
    print("发生未知错误：",error)