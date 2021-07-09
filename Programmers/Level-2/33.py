def solution(str1, str2):
    answer = 0
    str1 = str1.upper()
    str2 = str2.upper()
    a = {}
    b = {}
    
    for i in range(len(str1) - 1):
        if str1[i].isalpha() and str1[i+1].isalpha():  
            a[str1[i] + str1[i+1]] = a.get(str1[i] + str1[i+1], 0) + 1
    for i in range(len(str2) - 1):
        if str2[i].isalpha() and str2[i+1].isalpha():    
            b[str2[i] + str2[i + 1]] = b.get(str2[i] + str2[i+1], 0) + 1
        
    cnt = 0 # 교집합 갯수
    for tmp in a:
        if tmp in b:
            cnt += min(a[tmp], b[tmp])
            
    # (교집합/합집합) * 65536
    # 합집합 = a길이 + b길이 - cnt
    union = sum(a.values()) + sum(b.values()) - cnt
    if union == 0:
        answer = 65536
    else:
        answer = int((cnt/union)*65536)
    return answer
