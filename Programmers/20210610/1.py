import math


def solution(dartResult):
    answer = 0
    star = False  # 해당 점수, 앞 점수 x2
    ten = False
    dart = list(dartResult)

    prev = 1e9
    now = 1e9

    for i in range(len(dart)):
        if dart[i].isdigit():
            prev = now
            if dart[i+1].isdigit():
                ten = True
            else:
                if(ten):
                    now = 10
                    ten = False
                else:
                    now = int(dart[i])
            star = False
        elif dart[i] == 'S':
            answer += now
        elif dart[i] == 'D':
            now = pow(now, 2)
            answer += now
        elif dart[i] == 'T':
            now = pow(now, 3)
            answer += now
        elif dart[i] == '*':
            answer += now
            now *= 2
            if prev != 1e9:
                if star:
                    answer += (prev * 2)
                else:
                    answer += prev
            star = True
        elif dart[i] == '#':
            now = -now
            if star:
                answer += (now * 3)
            else:
                answer += (now * 2)

    return answer
