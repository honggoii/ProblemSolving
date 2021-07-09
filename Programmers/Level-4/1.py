def solution(distance, rocks, n):
    answer = 0 
    rocks.append(distance)
    rocks.sort()
    start = 1
    end = distance
    
    while start <= end:
        mid = (start + end) // 2
        prev = 0 # 이전 돌
        cnt = 0 # 제거 돌
        for rock in rocks:
            if abs(prev - rock) < mid:
                cnt += 1
            else:
                prev = rock
        
        if cnt > n:
            end = mid - 1
        else:
            answer = mid
            start = mid + 1
    return answer
