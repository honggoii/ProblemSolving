def solution(skill, skill_trees):
    answer = 0
    for tree in skill_trees:
        tmp = [t for t in tree if t in skill]
        for i in range(len(tmp)):
            if i < skill.index(tmp[i]):
                break
        else:
            answer += 1
    return answer
