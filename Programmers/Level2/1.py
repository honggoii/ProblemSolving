def solution(record):
    answer = []
    order = []
    user = {}
    for r in record:
        tmp = r.split()
        if tmp[0] == 'Enter':
            user[tmp[1]] = tmp[2]
            order.append(1) # '{}님이 들어왔습니다.'
            answer.append(tmp[1])
        elif tmp[0] == 'Leave':
            order.append(2) # '{}님이 나갔습니다.
            answer.append(tmp[1])
        elif tmp[0] == 'Change':
            user[tmp[1]] = tmp[2]

    i = 0
    for o in order:
        if o == 1:
            answer[i] = '{}님이 들어왔습니다.'.format(user[answer[i]])
        elif o == 2:
            answer[i] = '{}님이 나갔습니다.'.format(user[answer[i]])
        i += 1
    return answer
