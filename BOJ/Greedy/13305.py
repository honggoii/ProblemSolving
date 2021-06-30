n = int(input())
ans = 0

distance = list(map(int, input().split()))
price = list(map(int, input().split()))

max_price = int(1e9) # 최댓값
for i in range(n-1):
    if price[i] < max_price:
        max_price = price[i]
    ans += (max_price * distance[i])

print(ans)
