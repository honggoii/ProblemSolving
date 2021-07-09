from collections import deque
visited = [False] * 20001
graph = [[] for x in range(20001)]
answer = []
def bfs(node, n):
    global answer
    q = deque()
    q.append((0, node))
    visited[node] = True
    
    while q:
        now = q.popleft()
        
        for i in graph[now[1]]:
            if visited[i] == False:
                visited[i] = True
                q.append((now[0] + 1, i))
                answer.append(now[0] + 1)

def solution(n, edge):
    global answer
    for e in edge:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    bfs(1, n)
    answer.sort(reverse=True)
    
    flag = answer[0]
    cnt = 1
    for a in range(1, len(answer)):
        if answer[a] == flag:
            cnt += 1
    
    return cnt
