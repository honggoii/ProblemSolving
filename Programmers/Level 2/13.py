def solution(progresses, speeds):
    answer = []
    time = []
    for i in range(len(progresses)):
        remain = 100 - progresses[i]
        if remain % speeds[i] == 0:
            time.append(remain//speeds[i])
        else:
            time.append(remain//speeds[i]+1)
            
    tmp = time[0]
    cnt = 1
    for i in range(1, len(time)):
        if tmp >= time[i]:
            cnt += 1
        else:
            answer.append(cnt)
            cnt = 1
            tmp = time[i]
    answer.append(cnt)
    return answer
