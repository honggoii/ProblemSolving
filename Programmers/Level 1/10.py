import itertools
visit = []
for i in range(3001):
    visit.append(True)
    
def eratos():
    for i in range(2, 3001):
        if visit[i] == False: continue
        visit[i] = True
        for j in range(i*2, 3001 , i):
            visit[j] = False

def solution(nums):
    answer = 0
    eratos()
    combs = list(itertools.combinations(nums, 3))
    for comb in combs:
        a, b, c = comb
        tmp = a + b + c
        if visit[tmp] == True: # 소수면
            answer += 1
        
    return answer
