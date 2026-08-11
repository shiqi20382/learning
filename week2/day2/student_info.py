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
    "name": "李四",
    "age": 21,
    "score": 91
}

level = get_level(student["score"])

print("姓名：", student["name"],"年龄：", student["age"],"分数：", student["score"],"等级：", level)