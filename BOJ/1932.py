n = int(input())
graph = [[] * 501 for _ in range(501)]
dp = [[0] * 501 for _ in range(501)] # dp 테이블

for i in range(n):
    graph[i] = list(map(int, input().split())) # map 그리기

for i in range(n):
    for j in range(i+1):
        dp[i][j] = graph[i][j]

for i in range(1, n):
    for j in range(i+1):

        up = dp[i-1][j]

        if j == 0: # 1열이면 왼쪽 위 없음
            left_up = 0
        else:
            left_up = dp[i-1][j-1]

        dp[i][j] = dp[i][j] + max(up, left_up)

print(max(dp[n-1]))
