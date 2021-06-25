n = int(input())
graph = [[0] * 20 for _ in range(20)]
dp = [0] * 20 # dp 테이블

for i in range(n):
    t, p = list(map(int, input().split()))
    graph[i] = (t, p)

if graph[n-1][0] == 1:
    dp[n-1] = graph[n-1][1]
else:
    dp[n-1] = 0
    
for i in range(n-2, -1, -1): # 거꾸로
    if i + graph[i][0] <= n:
        dp[i] = max(dp[i+1], graph[i][1] + dp[i+graph[i][0]])
    else:
        dp[i] = dp[i+1]

print(dp[0])
