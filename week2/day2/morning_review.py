name = str(input("请输入姓名："))
age = int(input("请输入年龄："))
score = float(input("请输入成绩："))
if score >= 100 or score <= 0:
    print("成绩必须在0_100之间")

def get_level(score):
    if score >=90:
        return "优秀"
    elif score >= 80:
        return "良好"
    elif score >= 60:
        return "及格"
    else:
        return "不及格"

student = {
    "name": name,
    "age": age,
    "score": score,
}

level = get_level(student["score"])

print("姓名：", student["name"])
print("年龄：", student["age"])
print("成绩：", student["score"])
print("区间：", level)