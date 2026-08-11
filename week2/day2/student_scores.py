scores = [85, 92, 78, 88, 95]

total = 0

for score in scores:
    print("当前成绩：",score)
    total += score

average = total / len(scores)

print("总分：",total)
print("平均分：",average)