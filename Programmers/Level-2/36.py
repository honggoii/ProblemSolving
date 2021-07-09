from collections import deque

def solution(n,a,b):
    answer = 1
    q = deque()
    for i in range(n):
        q.append(i+1)
    
    if b < a:
        a, b = b, a # a가 작은 수가 되도록
    
    while q:
        first = q.popleft()
        second = q.popleft()
        if first == a and second == b:
            break
        
        if first == a or second == a:
            q.append(a)
            answer += 1 # 라운드 증가
        elif first == b or second == b:
            q.append(b)
        else:
            q.append(first)
    return answer
  
  
  '''
  재풀이
  '''
  def solution(n,a,b):
    answer = 0
    while a != b:
        answer += 1
        a, b = (a+1)//2, (b+1)//2

    return answer
