def solution(answers):
    answer = []
    
    one = [1, 2, 3, 4, 5]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    s1 = 0 # 수포자1
    s2 = 0 # 수포자2
    s3 = 0 # 수포자3
    for i in range(len(answers)):
        if one[i%5] == answers[i]:
            s1 += 1
        if two[i%8] == answers[i]:
            s2 += 1
        if three[i%10] == answers[i]:
            s3 += 1
    total = max(s1, max(s2, s3))
    if total == s1:
        answer.append(1)
    if total == s2:
        answer.append(2)
    if total == s3:
        answer.append(3)
    return answer
