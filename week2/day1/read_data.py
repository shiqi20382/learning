import pandas as pd

data = pd.read_csv("students.csv")

print("前三行数据:")
print(data.head(3))

print("\n列名:")
print(data.columns.tolist())

print("\n数据行数:")
print(len(data))

print("\n数据类型:")
print(data.dtypes)