import collections

n = int(input())
data = list(map(int, input().split()))

m = int(input())
num = list(map(int, input().split()))

answer = collections.Counter(data) # 나온 개수 카운트

for i in num:
    print(answer[i], end = ' ')
