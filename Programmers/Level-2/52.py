'''
1번째 방법
'''
def solution(s):
    cnt = 0 # 이진 변환 횟수
    zero = 0 # 제거된 모든 0 개수
    
    while s != '1':
        zero += s.count('0') # 제거된 0 개수 추가
        s = list(filter(lambda x: x != '0', s)) # 모든 0 제거
        s = ''.join(s) # 리스트 -> 문자열
        s = bin(len(s))[2:]
        cnt += 1 # 변환 횟수 추가
    return [cnt, zero]

'''
2번째 방법
'''
def solution(s):
    cnt = 0 # 이진 변환 횟수
    zero = 0 # 제거된 모든 0 개수
    
    while s != '1':
        zero += s.count('0') # 제거된 0 개수 추가
        s = '1' * (len(s) - s.count('0')) # 남은 길이 1로 만들기
        s = bin(len(s))[2:]
        cnt += 1 # 변환 횟수 추가
    return [cnt, zero]
