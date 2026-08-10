import pandas as pd

data = pd.read_csv("sales.csv")

print("\n数据行数:")
print(len(data))

print("\n数据列名:")
print(data.columns.tolist())

print("\n前五行数据:")
print(data.head(5))

data["price"] = pd.to_numeric(data["price"], errors="coerce")
data["quantity"] = pd.to_numeric(data["quantity"], errors="coerce")

data["amount"] = data["quantity"] * data["price"]
data["amount"] = data["amount"].round(2)

print("\n销售总额:")
print(data["amount"].sum())

print("\n总销售数量:")
print(data["quantity"].sum())

product_amount_summary = (data.groupby("product", as_index=False)["amount"].sum())
max_amount_product = product_amount_summary["amount"].max()
max_amount_product_name = product_amount_summary[product_amount_summary["amount"] == max_amount_product]
print("\n销售额最高的商品:")
print(max_amount_product_name)

city_sales_count = data.groupby("city")["amount"].sum().reset_index()

print("\n各城市的销售数量:")
print(city_sales_count)

product_sales_count = data.groupby("product")["amount"].sum().reset_index()
print("\n各商品销售数量:")
print(product_sales_count)

category_sales_count = data.groupby("category")["amount"].mean().reset_index()
category_sales_count["amount"] = category_sales_count["amount"].round(2)

print("\n各类别销售数量:")
print(category_sales_count)

high_amount_sales = data[data["amount"] >= 10000]
print("\n销售额超过10000的商品:")
print(high_amount_sales)

high_amount_sales.to_csv("result/high_amount_sales.csv", index=False)

city_sales_count.to_csv("result/city_sales_count.csv", index=True)

product_sales_count.to_csv("result/product_sales_count.csv", index=True)    

category_sales_count.to_csv("result/category_sales_count.csv", index=True)


print("\n销售额大于等于 10000 的记录已保存到 result/high_amount_sales.csv")

print("\n各城市销售数量已保存到 result/city_sales_count.csv")

print("\n各商品销售数量已保存到 result/product_sales_count.csv")

print("\n各类别销售数量已保存到 result/category_sales_count.csv")