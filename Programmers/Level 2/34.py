from collections import deque
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y, visited, n, m, maps):
    global dx, dy
    
    q = deque()
    q.append((x, y))
    visited[x][y] = 1
    
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < n and 0 <= ny < m:
                if visited[nx][ny] == -1 and maps[nx][ny] == 1:
                    q.append((nx, ny))
                    visited[nx][ny] = visited[x][y] + 1
                    

def solution(maps):
    n = len(maps) # 행
    m = len(maps[0]) # 열
    visited = [[-1] * (m + 1) for _ in range(n + 1)]
    bfs(0, 0, visited, n, m, maps)
    if visited[n-1][m-1] == -1:
        return -1
    else:
        return visited[n-1][m-1]
