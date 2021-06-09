def solution(s):
    answer = ''
    if len(s) % 2: #홀수
        answer += s[len(s)//2]
    else:
        answer += s[len(s)//2-1:len(s)//2+1]
    return answer
