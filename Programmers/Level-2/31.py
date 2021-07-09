def solution(s):
    answer = len(s)

    for i in range(1, len(s) // 2 + 1):
        start = 0
        tmp = []
        while start < len(s):
            tmp.append(s[start:start + i])
            start = start + i
        cnt = 1
        now = ''
        for j in range(1, len(tmp)):
            if tmp[j-1] == tmp[j]:
                cnt += 1
            else:
                if cnt > 1:
                    now += str(tmp[j - 1])
                    now += str(cnt)
                else:
                    now += str(tmp[j - 1])
                cnt = 1
        if cnt > 1:
            now += str(tmp[-1]) + str(cnt)
        else:
            now += str(tmp[-1])
        if len(now) < answer:
            answer = len(now)
    return answer
