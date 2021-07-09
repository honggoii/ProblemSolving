from itertools import combinations


def solution(relation):
    row = len(relation)  # 행
    col = len(relation[0])  # 열

    # 전체 조합
    candidates = []
    for i in range(1, col + 1):
        candidates.extend(combinations(range(col), i))

    # 유일성
    unique = []
    for candidate in candidates:
        tmp = [tuple([item[i] for i in candidate]) for item in relation]
        if len(set(tmp)) == row:
            unique.append(candidate)

    # 최소성
    answer = set(unique)
    for i in range(len(unique)):
        for j in range(i + 1, len(unique)):
            if len(unique[i]) == len(set(unique[i]) & set(unique[j])):
                answer.discard(unique[j])

    return len(answer)
