from collections import deque

def solution(begin, target, words):
    if target not in words:
        return 0
    q = deque()
    visited = [False] * len(words)
    q.append((begin, 0)) # 단어, 횟수
    
    while q:
        now, cnt = q.popleft()
        
        if now == target:
            break
        
        for i in range(len(words)):
            diff = 0 # 다른 단어 개수
            if visited[i] == True: 
                continue
            for j in range(len(now)):
                if now[j] != words[i][j]:
                    diff += 1
            
            if diff == 1: # 다른게 하나 일때만
                visited[i] = True
                q.append((words[i], cnt + 1))
        
    return cnt
