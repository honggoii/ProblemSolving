def solution(N, number):
    answer = -1
    DP = []

    for i in range(1, 9): # 8번 반복
        numbers = set() # 중복 제거
        numbers.add(int(str(N) * i)) # 본인 붙이기
        
        for j in range(0, i-1):
            for x in DP[j]:
                for y in DP[-j-1]:
                    numbers.add(x + y)
                    numbers.add(x - y)
                    numbers.add(x * y)
                    
                    if y != 0:
                        numbers.add(x // y)

        if number in numbers:
            answer = i
            break
        
        DP.append(numbers)

    return answer
