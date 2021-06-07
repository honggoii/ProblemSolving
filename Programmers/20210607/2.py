import itertools

def solution(nums):
    answer = 0
    sel = len(nums)//2
    num = list(set(nums))
    if len(num) < sel:
        answer = len(num)
    else:
        answer = sel
    return answer
