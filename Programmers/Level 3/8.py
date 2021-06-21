dp = []

def solution(triangle):
    answer = 0
    for t in triangle:
        dp.append(t)
    n = len(triangle)    
    for i in range(1, n):
        for j in range(i+1):
            if j == 0:
                up_left = 0 # 왼쪽 위 없음
            else:
                up_left = dp[i-1][j-1] # 왼쪽 위
                
            if j == i:
                up = 0 # 바로 위 없음
            else:
                up = dp[i-1][j] # 바로 위
                
            dp[i][j] = dp[i][j] + max(up_left, up) # 바로 위, 왼쪽 위 중 최댓값 더하기
    return max(dp[n-1]) # 마지막 행에서 최댓값 반환
