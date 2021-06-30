from itertools import product

def solution(numbers, target):
    number = [(x, -x) for x in numbers]
    answer = list(map(sum, product(*number)))
    return answer.count(target)

'''
조합 직접 구현
'''
visited = [False] * 21
answer = 0

def combination(idx, cnt, sel, sz, numbers, target):
    global answer
    if cnt == sel:
        total = 0
        for i in range(0, sz):
            if visited[i]:
                total -= numbers[i]
            else:
                total += numbers[i]
                
        if total == target:
            answer += 1
        return
        
    for i in range(idx, sz):
        if (visited[i]): continue
        visited[i] = True
        permutation(i, cnt+1, sel, sz, numbers, target)
        visited[i] = False

def solution(numbers, target):
    # global answer
    sz = len(numbers)
    for i in range(1, sz):
        combination(0, 0, i, sz, numbers, target)
    return answer
