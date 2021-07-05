from itertools import permutations
import math

def operation(op, a, b):
    if op == '-':
        return a - b
    elif op == '+':
        return a + b
    elif op == '*':
        return a * b

def split_expression(expression):
    number = []
    ops = []
    
    tmp = ''
    for e in expression:
        if e.isdigit(): # 숫자면
            tmp += e
        else: # 연산자면
            ops.append(e)
            number.append(int(tmp))
            tmp = ''
            
    number.append(int(tmp)) # 마지막 숫자도 넣어주기
    return number, ops

def solution(expression):
    answer = 0
    number, ops = split_expression(expression) # 숫자, 연산자 리스트
    ex_permu = list(permutations(['-','+','*'], 3)) # 연산자 순열
    
    for ex in ex_permu: # 연산자 우선순위 하나씩 확인
        tmp_ops = ops # 원본 연산자 리스트를 훼손하지 않도록 복사
        tmp_nums = number # 원본 숫자 리스트를 훼손하지 않도록 복사
        for e in ex: # 연산자 우선순위 높은 것부터 하나씩
            tmp = [tmp_nums[0]] # 스택 용도
            idx = 1
            for op in tmp_ops:
                if e == op: # 지금 우선순위면
                    num = tmp.pop()
                    tmp.append(operation(op, num, tmp_nums[idx])) # 계산 결과 넣기
                else: # 지금 우선순위 아니면
                    tmp.append(tmp_nums[idx]) # 지금 숫자만 리스트에 저장
                idx += 1
            tmp_ops = list(filter(lambda a: a != e, tmp_ops))
            tmp_nums = tmp
        if answer < abs(tmp_nums[0]):
            answer = abs(tmp_nums[0])
    return answer
