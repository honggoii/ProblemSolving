def solution(s):    
    cnt = 0
    for i in s:
        if i == '(': # 여는 괄호
            cnt += 1
        else: # 닫는 괄호
            if cnt == 0:
                return False
            cnt -= 1
    if cnt == 0:
        return True
    else:
        return False
