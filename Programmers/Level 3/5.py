def solution(n, times):
    answer = 0
    times.sort() 
    
    start = 1
    end = times[-1] * n
    
    while start <= end:
        mid = (start + end) // 2
        total = 0
        
        for time in times:
            total += (mid // time)
        
        if total >= n:
            end = mid - 1
        else:
            start = mid + 1
    answer = start
    return answer
