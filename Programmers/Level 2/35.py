def solution(rows, columns, queries):
    answer = []
    board = [[0] * (columns+2) for _ in range(rows+2)]
    
    # 행렬 초기화 1~(rows*columns)
    for i in range(1, rows + 1):
        for j in range(1, columns + 1):
            board[i][j] = (i - 1) * columns + j
            
    for query in queries:
        a, b, c, d = query # a행 b열 ~ c행 d열
        tmp = board[a][b]
        rotation = [tmp]
        
        # a행 ~ (c-1)행까지
        for i in range(a, c):
            board[i][b] = board[i+1][b]
            rotation.append(board[i][b])
        # b열 ~ (d-1)열까지
        for i in range(b, d):
            board[c][i] = board[c][i+1]
            rotation.append(board[c][i])
        # c행 ~ a행까지
        for i in range(c, a, -1):
            board[i][d] = board[i-1][d]
            rotation.append(board[i][d])
        # d열 ~ b열까지
        for i in range(d, b, -1):
            board[a][i] = board[a][i-1]
            rotation.append(board[a][i])
        board[a][b+1] = tmp
        answer.append(min(rotation))
    return answer
