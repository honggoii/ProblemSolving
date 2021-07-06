def solution(n):
    ans = 0
    while n != 0:
        if n % 2 == 0: # 짝수면
            n //= 2 # 2로 나눈다.
        else: # 홀수면
            n -= 1 # 1을 빼주고
            ans += 1 # 점프
    return ans
