def correct(s, i, length):
    stack = []
    flag = False
    
    for i in range(i, i + length):
        if s[i] == '[' or s[i] == '(' or s[i] == '{':
            stack.append(s[i])
            flag = True  
        if len(stack) != 0:
            if s[i] == ']' and stack[-1] == '[':
                stack.pop()
            elif s[i] == ')' and stack[-1] == '(':
                stack.pop()
            elif s[i] == '}' and stack[-1] == '{':
                stack.pop()
    
    if flag and len(stack) == 0:
        return 1 # 올바른 괄호
    else:
        return 0

def solution(s):
    answer = 0
    length = len(s) # 원본 문자열 길이
    s += s # 이어 붙이기
    for i in range(length):
        answer += correct(s, i, length)
    return answer
