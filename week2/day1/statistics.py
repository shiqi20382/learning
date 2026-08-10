import pandas as pd
data = pd.read_csv("students.csv")

print("平均年龄:",data["age"].mean())
print("平均分数:",data["score"].mean())
print("最高分:",data["score"].max())
print("最低分:",data["score"].min())
print("\n各城市学生人数:")
print(data["city"].value_counts())
print("\n各城市平均分数:")
print(data.groupby("city")["score"].mean())