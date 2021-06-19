def solution(n):
    answer = []
    number = ['1','2','4']
    while n != 0:
        if n % 3 == 1:
            answer.append('1')
            n //= 3
        elif n % 3 == 2:
            answer.append('2')
            n //= 3
        else:
            answer.append('4')
            n = (n//3) - 1
    answer.reverse()
    answer = ''.join(answer)
    return answer
