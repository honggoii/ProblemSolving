def solution(number, k):
    answer = ''
    stack = [number[0]]
    
    for i in range(1, len(number)):
        while len(stack) > 0 and k > 0 and stack[-1] < number[i]:
            k -= 1
            stack.pop()
        stack.append(number[i])
    
    if k > 0:
        stack.pop()
        
    answer = ''.join(stack)
    return answer
