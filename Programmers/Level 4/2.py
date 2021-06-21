def find_max(money):
    dp = [0] * 1000001
    dp[0] = money[0]
    dp[1] = max(money[0], money[1])
    for i in range(2, len(money) - 1): # 첫 집 무조건 터는 경우
        dp[i] = max(money[i]+dp[i-2], dp[i-1])
    return max(dp)

def solution(money):
    answer = find_max(money)
        
    money.reverse()
    
    answer = max(answer, find_max(money))
        
    return answer
