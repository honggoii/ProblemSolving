from collections import deque

def solution(priorities, location):
    answer = 1
    q = deque()
    for i in range(len(priorities)):
        q.append((i, priorities[i])) # 큐에 넣는다.
    priorities.sort(reverse= True)
    
    while q:
        now = q.popleft() # 큐 앞
        if now[1] == priorities[0]:
            if now[0] == location:
                break
            priorities = priorities[1:] # 앞을 자른다
            answer += 1
        else:
            q.append(now)
    return answer
