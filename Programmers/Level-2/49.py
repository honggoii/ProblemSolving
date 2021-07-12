def solution(numbers):
    answer = []
    for number in numbers:
        if number % 2 == 0: # 짝수면
            answer.append(number + 1)
        else: # 홀수면
            binary = list('0' + bin(number)[2:]) # 0b로 시작하니까 두 개 지워줌
            for i in range(len(binary) - 1, -1 , -1):
                if binary[i] == '0': # 맨 오른쪽에서 처음 만나는 0 -> 1, 그 뒤 1-> 0
                    binary[i] = '1'
                    binary[i + 1] = '0'
                    answer.append(int('0b' + "".join(binary), 2))
                    break
    return answer
