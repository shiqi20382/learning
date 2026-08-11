import csv

high_score_students = []

with open("students.csv","r",encoding="utf-8")as file:
    reader = csv.DictReader(file)

    for row in reader:
        if  float(row["score"]) >= 90:
            high_score_students.append(row)

with open("high_score_students.csv", "w", newline="", encoding="utf-8")as file:
    fieldnames = ["name", "age", "score"]
    writer = csv.DictWriter(file, fieldnames=fieldnames)

    writer.writeheader()
    writer.writerows(high_score_students)

    print("高分学生数量：", len(high_score_students))