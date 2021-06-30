n = int(input())
dp = [int(1e9)] * 5001
dp[3] = dp[5] = 1
for i in range(6, n+1):
    if i % 5 == 0:
        dp[i] = dp[i - 5] + 1
    else:
        dp[i] = dp[i-3] + 1

if dp[n] >= 1e9:
    print(-1)
else:
    print(dp[n])
