import heapq

def solution(jobs):
    answer = 0
    time = 0
    q = []
    flag = True
    idx = 0
    jobs.sort()
    cnt = 0
    while (1):
        while flag and jobs[idx][0] <= time:
            heapq.heappush(q, (jobs[idx][1], jobs[idx][0]))
            idx += 1
            if idx == len(jobs):
                flag = False
        
        if q:
            required, request = heapq.heappop(q)
            time += required
            answer += (time - request)
            cnt += 1
        else:
            time += 1
            
        if cnt == len(jobs):
            break
        
    return (answer//len(jobs))
