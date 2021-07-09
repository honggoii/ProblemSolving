import heapq

def solution(operations):
    answer = []
    minq = [] # 최소힙
    maxq = [] # 최대힙
    
    visited = [False] * 1000001
    idx = 0
    
    for operation in operations:
        op, num = operation.split(' ')
        if op == 'I': 
            heapq.heappush(minq, (int(num), idx))
            heapq.heappush(maxq, (-int(num), idx))
            idx += 1
        elif op == 'D':
            if int(num) < 0:
                while minq:
                    n, i = heapq.heappop(minq)
                    if not visited[i]:
                        visited[i] = True
                        break
            else:
                while maxq:
                    n, i = heapq.heappop(maxq)
                    if not visited[i]:
                        visited[i] = True
                        break
    
    if maxq and minq:
        while maxq:
            n, i = heapq.heappop(maxq)
            if not visited[i]:
                answer.append(-n)
                break
        while minq:
            n, i = heapq.heappop(minq)
            if not visited[i]:
                answer.append(n)
                break
    else:
        answer = [0, 0]
    return answer
