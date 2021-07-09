from itertools import permutations

prime = [True] * 10000000
def find_prime():
    prime[0] = False
    prime[1] = False
    for i in range(2, 10000000):
        if prime[i] == False:
            continue
        for j in range(i * 2, 10000000, i):
            prime[j] = False

def solution(numbers):
    answer = 0
    find_prime()
    number = []
    for i in numbers:
        number.append(i)
    combs = []
    for i in range(1, len(numbers) + 1):
        combs += list(set(map(''.join, permutations(number, i)))) #숫자 조합
    for comb in combs:
        for c in comb:
            if c != '0':
                break
            comb = comb[1:]
        if comb == '': continue
        if prime[int(comb)]: 
            answer += 1
            prime[int(comb)] = False # 중복제거
    return answer
