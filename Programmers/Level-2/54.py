def solution(dirs):
    answer = 0
    d = {'U': (-1, 0), 'D': (1,0), 'R': (0, 1), 'L': (0, -1)}
    road = []
    x, y = 5, 5
    nx, ny = x, y
    for dir in dirs:
        nx, ny = x + d[dir][0], y + d[dir][1]

        if nx < 0 or nx > 10 or ny < 0 or ny > 10:  # 영역 벗어난 경우
            nx, ny = x, y # 제자리로
            continue
        if (x, y, nx, ny) in road:  # 이미 왔던 길
            x, y = nx, ny # 다음으로
            continue

        road.append((x, y, nx, ny))
        road.append((nx, ny, x, y))
        x, y = nx, ny
        answer += 1
    return answer
