import pandas as pd
data = pd.read_csv("clean_students.csv")

high_score = data[data["score"] >=90]

print("高分学生数据:")
print(high_score)

high_score.to_csv("high_score_students.csv", index=False)

city_summary = data.groupby("city").agg(

    student_count=("name", "count"),
    average_score=("score", "mean")
).reset_index()

city_summary["average_score"] = city_summary["average_score"].round(2)

print("\n按城市汇总数据:")
print(city_summary)

city_summary.to_csv("city_summary.csv", index=False)
