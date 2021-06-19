def solution(numbers):
    answer = []
    for i in range(len(numbers)-1):
        for j in range(len(numbers)):
            if i == j: 
                pass
            else:
                temp = numbers[i] + numbers[j]
                if temp in answer:
                    pass
                else:
                    answer.append(temp)
    answer.sort()
    return answer
