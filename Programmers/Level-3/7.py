from collections import defaultdict

winner = defaultdict(set)
loser = defaultdict(set)

def solution(n, results):
    global winner, loser
    answer = 0
    for result in results:
        winner[result[0]].add(result[1])
        loser[result[1]].add(result[0])
        
    for i in range(1, n + 1):
        for w in winner[i]:
            loser[w].update(loser[i])
        for l in loser[i]:
            winner[l].update(winner[i])
    
    for i in range(1, n + 1):
        total = len(winner[i]) + len(loser[i])
        if total == n - 1:
            answer += 1
    return answer
