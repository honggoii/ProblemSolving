n = int(input())
data = []
for i in range(n):
    data.append(int(input()))
data.sort(reverse = True) # 내림차순 정렬

ans = 0
for i in range(n):
    if i % 3 == 2: continue
    ans += data[i]

print(ans)
