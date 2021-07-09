from collections import defaultdict

def solution(arrows):
    answer = 0
    visited = defaultdict(int)
    edges = defaultdict(int)
    visited[(0,0)] = True
    x, y = 0, 0
    dx = [-1, -1, 0, 1, 1, 1, 0, -1]
    dy = [0, 1, 1, 1, 0, -1, -1, -1]
    for arrow in arrows:
        for i in range(2):
            nx = x + dx[arrow]
            ny = y + dy[arrow]
            if visited[(nx, ny)] == True and edges[(x, y, nx, ny)] == False:
                edges[(x, y, nx, ny)] = True
                edges[(nx, ny, x, y)] = True
                answer += 1
            else:
                edges[(x, y, nx, ny)] = True
                edges[(nx, ny, x, y)] = True
                visited[(nx, ny)] = True
            x, y = nx, ny
        
    return answer
