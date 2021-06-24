def solution(citations):
    answer = 0
    citations.sort()
    n = len(citations)
    for i in range(citations[-1]):
        for j in range(n-1):
            if i <= citations[j] and i <= n-j:
                answer = max(answer, i)
    return answer
