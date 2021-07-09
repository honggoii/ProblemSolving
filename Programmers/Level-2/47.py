def solution(n):
    answer = []
    result = [[0] * n for _ in range(n)]
    x, y = -1, 0
    num = 1
    for i in range(n):
        for j in range(i, n):
            if i % 3 == 0: # 아래로
                x += 1
            elif i % 3 == 1: # 오른쪽
                y += 1
            elif i % 3 == 2: # 
                x -= 1
                y -= 1
            result[x][y] = num
            num += 1
    
    for i in result:
        for j in i:
            if j != 0:
                answer.append(j)
            
    return answer
