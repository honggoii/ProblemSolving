n = int(input())
data = list(map(int, input().split(' ')))
data.sort()

prefix = [0]
tmp = 0
for i in data:
    tmp += i
    prefix.append(tmp)

print(sum(prefix))
