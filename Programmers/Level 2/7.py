def solution(clothes):
    answer = 1
    hashmap = {} # dictionary
    for cloth in clothes:
        if cloth[1] in hashmap:
            hashmap[cloth[1]] += 1
        else:
            hashmap[cloth[1]] = 2 # 입는 경우(1) + 안 입는 경우(1)
            
    for key in hashmap:
        answer *= hashmap[key]
    
    return answer - 1
