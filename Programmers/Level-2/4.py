def solution(name):
    answer = 0
    correct = [] # 정답
    original = [] # 원본
    cnt = [] # 위아래 조작 횟수
    
    for i in range(len(name)):
        cnt.append(min(ord(name[i])-ord('A'), ord('Z') - ord(name[i]) + 1)) # 위, 아래 조작 중 최소값
        correct.append('A')
        original.append(name[i])
        
    original[0] = 'A'
    answer = cnt[0]
    
    idx = 0
    i, j = 0, 0
    while original != correct:# 모든 문자가 A가 될 때까지
        lcnt, rcnt = 0, 0
        
        # A를 만날 때까지 왼쪽으로 이동
        for i in range(idx - 1, -2, -1):
            if i < 0: # 맨처음에서 왼쪽으로 이동하고 싶으면
                i = len(name) - 1
            lcnt += 1
            if original[i] != 'A':
                break
            
        # A를 만날 때까지 오른쪽으로 이동
        for j in range(idx + 1, len(name) + 1):
            if j >= len(name): # 마지막까지 못만나면 무한대값
                j = idx
                rcnt = int(1e9)
                break
            rcnt += 1
            if original[j] != 'A':
                break
        
        if rcnt <= lcnt:
            answer += (rcnt + cnt[j])
            idx = j
            original[j] = 'A'
        else:
            answer += (lcnt + cnt[i])
            idx = i
            original[i] = 'A'
                
    return answer
