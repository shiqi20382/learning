import pandas as pd

input_file = "dirty_students.csv"
output_file = "clean_students.csv"

data = pd.read_csv(input_file)

print("原始数据:")
print(data)

print("\n原始缺失值数量:")
print(data.isnull().sum())

data = data.drop_duplicates()

data["age"] = pd.to_numeric(data["age"], errors="coerce")

data["score"] = pd.to_numeric(data["score"], errors="coerce")

data["age"] = data["age"].fillna(data["age"].median())

data["score"] = data["score"].fillna(data["score"].mean())

data = data.dropna(subset=["name", "city"])

data["age"] = data["age"].astype(int)

data["score"] = data["score"].round(2)

data.to_csv(output_file, index=False)

print("\n清洗后的数据:")
print(data)

print("\n已生成文件: output_file")