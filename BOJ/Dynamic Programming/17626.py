import math

n = int(input())
dp = [int(1e9)] * 50001

for i in range(1, int(math.sqrt(n)) + 1):
    dp[i * i] = 1

for i in range(1, n + 1):
    for j in range(1, int(math.sqrt(i)) + 1):
        dp[i] = min(dp[i], dp[j * j] + dp[i - j * j])

print(dp[n])
