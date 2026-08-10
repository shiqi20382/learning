import pandas as pd

data = pd.read_csv("students.csv")

high_score_data = data[data["score"] > 90]

print("成绩大于90分的学生数据:")
print(high_score_data)

shnaghai_data = data[data["city"] == "上海"]
print("\n上海学生数据:")
print(shnaghai_data)

high_score_data.to_csv("high_score_students.csv", index=False)

print("\n已生成文件: high_score_students.csv")