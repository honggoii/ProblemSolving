n = int(input())
tips = []
for i in range(n):
    tips.append(int(input()))
tips.sort(reverse = True)

ans = 0
for i in range(n):
    if tips[i] - i < 0:
        break
    ans += (tips[i]-i)

print(ans)
