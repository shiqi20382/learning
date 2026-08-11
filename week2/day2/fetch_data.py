import json                                              
import os                                                
import requests                                         
import pandas as pd   

url = "https://jsonplaceholder.typicode.com/users"
result_dir = "result"
json_file = "result/users.json" 
csv_file = "result/users.csv"  

os.makedirs(result_dir, exist_ok=True) 

try:
    response = requests.get(url, timeout=10)
    response.raise_for_status()
    users = response.json()
except requests.RequestException as error:
    print("请求数据失败：",error)
    raise SystemExit(1)

print("HTTP 状态码：", response.status_code) 
print("数据条数：", len(users))

with open(json_file,"w",encoding="utf-8")as file:
    json.dump(users,file,ensure_ascii=False,indent=2)

data = pd.DataFrame(users)

print("\n前五行数据:")
print(data.head())

data.to_csv(csv_file,index=False,encoding="utf-8-sig")

print("\n已生成文件:")
print(json_file)
print(csv_file)