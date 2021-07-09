def solution(N, stages):
    answer = {}
    people = [0 for i in range(N + 2)]
    for i in stages:
        people[i] += 1

    total = len(stages)
    for i in range(1, N + 1):
        if people[i] == 0:
            answer[i] = 0
        else:
            answer[i] = people[i] / total
        total -= people[i]

    answer = sorted(answer.items(), key=lambda item: item[1], reverse = True)

    return list(dict(answer).keys())
