import csv

scores = []

with open("students.csv", "r", encoding="utf-8")as file:
    reader = csv.DictReader(file)


    for row in reader:
        row["age"] = int(row["age"])
        row["score"] = float(row["score"])
        scores.append(row["score"])
        print(row["name"],row["score"])

average = sum(scores) / len(scores)

print("平均成绩：",average)