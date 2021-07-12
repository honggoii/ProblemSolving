def check_area(arr, row, col, nn, answer): # 시작 행, 시작 열, 길이    
    n = nn // 2
    data = arr[row][col] # 영역 값
    for r in range(row, row + nn):
        for c in range(col, col + nn):
            if arr[r][c] != data: # 영역 값이랑 같지 않으면
                check_area(arr, row, col, n, answer)
                check_area(arr, row + n, col, n, answer)
                check_area(arr, row, col + n, n, answer)
                check_area(arr, row + n, col + n, n, answer)
                return
                
    answer[data] += 1
    
def solution(arr):
    answer = [0, 0]
    check_area(arr, 0, 0, len(arr), answer)
    return answer
