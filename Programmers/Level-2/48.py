from collections import deque

game = [[] * 40 for _ in range(40)]


def change_board(game, m, n):
    for j in range(n):  # 한 열씩 확인하기
        for i in range(m - 1, -1, -1):  # 행을 올라가면서
            k = i
            if game[i][j] == '.':
                while 0 < k and game[k][j] == '.':
                    k -= 1
                game[i][j] = game[k][j]  # 알파벳 내려주기
                game[k][j] = '.'


def remove_block(game, coord):
    for i in coord:
        game[i[0]][i[1]] = '.'  # 지우기


def start_game(x, y, char, visited, m, n):
    q = deque()
    q.append((x, y))
    coord = [(x, y)]  # 좌표들
    visited[x][y] = True

    dx = [0, 1, 1]  # 오, 아, 왼쪽 대각선
    dy = [1, 0, 1]  # 오, 아, 왼쪽 대각선

    while q:
        x, y = q.popleft()
        visited[x][y] = True

        if 0 <= x + 1 < m and 0 <= y + 1 < n:  # 범위 안에 있으면서
            if game[x][y + 1] == char and game[x + 1][y] == char and game[x + 1][y + 1] == char:
                if not visited[x][y + 1] and not visited[x + 1][y] and not visited[x + 1][y + 1]:
                    q.append((x, y + 1))
                    q.append((x + 1, y))
                    q.append((x + 1, y + 1))
                    coord.append((x, y + 1))
                    coord.append((x + 1, y))
                    coord.append((x + 1, y + 1))
                    #visited[x][y + 1] = True
                    #visited[x + 1][y] = True
                    #visited[x + 1][y + 1] = True

    if 4 <= len(coord):  # 지워져야 할 블록
        remove_block(game, coord)
        change_board(game, m, n)  # 아래로 당겨주기
        return len(set(coord))
    '''
    if 4 == len(coord):
        remove_block(game, coord)
        change_board(game, m, n)  # 아래로 당겨주기
        return len(coord)
    '''

    return 0


def solution(m, n, board):
    answer = 0
    global game
    # 문자들 넣기
    row = 0
    for b in board:
        for i in b:
            game[row].append(i)
        row += 1

    while 1:
        visited = [[False] * 40 for _ in range(40)]  # 방문 체크
        tmp = answer
        for i in range(m):
            for j in range(n):
                if not visited[i][j] and game[i][j] != '.':
                    answer += start_game(i, j, game[i][j], visited, m, n)  # bfs 시작
        if tmp == answer:
            break
    return answer
