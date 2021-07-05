def balanced(p): # 균형잡힌 괄호 문자열
    left = 0 # ( 개수
    right = 0 # ) 개수
    
    for i in range(len(p)):
        if p[i] == '(':
            left += 1
        elif p[i] == ')':
            right += 1
            
        if left == right:
            return i # 균형잡힌 괄호
        
def alright(p): # 올바른 괄호 문자열
    cnt = 0 # 여는 괄호면 +, 닫는 괄호면 -
    for i in p:
        if i == '(':
            cnt += 1
        elif i == ')':
            if cnt == 0: # 닫는 괄호가 더 많은 경우
                return False
            cnt -= 1
            
    return True # 짝이 맞는 경우

def solution(p):
    answer = ''
    if p == '':
        return answer
    idx = balanced(p)
    u = p[:idx+1]
    v = p[idx+1:]

    if alright(u): # u가 올바른 괄호 문자열이면
        answer = u + solution(v)
    else: # u가 올바른 괄호가 아니면
        answer = '('
        answer += solution(v)
        answer += ')'
        u = list(u[1:-1]) # 처음과 마지막 제거
        for i in range(len(u)): # u 뒤집기
            if u[i] == '(':
                answer += ')'
            elif u[i] == ')':
                answer += '('
    return answer
