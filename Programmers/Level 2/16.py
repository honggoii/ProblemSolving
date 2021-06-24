import heapq
def solution(scoville, k):
    answer = 0
    scoville.sort()
    heap = []
    for s in scoville:
        heapq.heappush(heap, s)

    while heap:
        first = heapq.heappop(heap)
        if len(heap) == 0 and first < k:
            answer = -1
            break
        if first >= k:
            break    
            
        second = heapq.heappop(heap)
        mix = first + (second * 2)
        answer += 1
        heapq.heappush(heap, mix)            

    return answer
