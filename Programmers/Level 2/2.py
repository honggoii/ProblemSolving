def solution(s):
    answer = -1
    stack = []
    for i in s:
        if len(stack) != 0:
            if stack[-1] == i:
                stack.pop()
            else:
                stack.append(i)
        else:
            stack.append(i)

    if len(stack) == 0:
        answer = 1
    else:
        answer = 0
    return answer
