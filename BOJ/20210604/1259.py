while True:
    data = list(map(int, input()))
    if data[0]==0:
        break
    n = len(data)-1
    flag = True
    i = 0
    for d in data:
        if d != data[n-i]:
            flag = False
        i += 1
    if flag:
        print('yes')
    else:
        print('no')
