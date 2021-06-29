inputs = list(input())

ans = ''
a = 'AAAA'
b = 'BB'

cnt = 0

def answer(cnt):
    global ans
    if cnt % 2 == 0:
        ans += a * (cnt // 4)
        cnt %= 4
        if cnt != 0:
            ans += b
    else:
        ans = '-1'
        return

for input in inputs:
    if input == 'X':
        cnt += 1
    else:
        if cnt != 0:
            answer(cnt)
        if ans == '-1':
            break
        ans += '.'
        cnt = 0

if ans == '-1':
    print('-1')
else:
    if cnt != 0:
        answer(cnt)
    print(ans)
