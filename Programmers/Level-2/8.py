import functools

def comparator(a,b):
    first = a + b
    second = b + a
    
    if first > second:
        return 1
    elif first < second:
        return -1
    else:
        return 0

def solution(numbers):
    answer = ''
    number = [str(x) for x in numbers] # int -> strng
    number = sorted(number, key = functools.cmp_to_key(comparator), reverse = True)
    if number[0] == '0':
        answer = '0'
    else:
        answer = ''.join(number)
    return answer
