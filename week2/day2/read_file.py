with open("input.txt","r",encoding="utf-8")as file:
    lines = file.readlines()

for line in lines:
    print(line.strip())