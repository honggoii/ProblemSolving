from itertools import combinations

vowels = ('a', 'e', 'i', 'o', 'u')
l, c = map(int, input().split(' '))

array = input().split(' ')
array.sort() # 사전순 출력

# l개뽑는 조합
for password in combinations(array, l):
    # 모음 개수 확인
    count = 0
    for i in password:
        if i in vowels:
            count += 1
    
    # 최소 1개의 모음과 최소 2개의 자음
    if count >=1 and count <= (l-2):
        print(''.join(password))
