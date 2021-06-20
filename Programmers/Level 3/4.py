visited = [False] * 201

def dfs(node, n, computers):
    visited[node] = True
    
    for i in range(n):
        if computers[node][i] == 1 and visited[i] == False:
            dfs(i, n, computers)

def solution(n, computers):
    answer = 0
    for i in range(n):
        if visited[i]: continue
        dfs(i, n, computers)
        answer += 1
    return answer
