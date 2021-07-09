from itertools import combinations

def solution(info, query):
    answer = []
    info_dict = {}
    
    # 1. info 분리
    for i in info:
        tmp_info = i.split(' ')
        info_key = tmp_info[:-1] # 정보
        info_value = int(tmp_info[-1]) # 점수
        for j in range(5): # 0 ~ 4개 고르기
            for c in combinations(info_key, j):
                real_key = ''.join(c) # 리스트 -> 문자열
                if real_key in info_dict: # 있는 조건
                    info_dict[real_key].append(info_value)
                else: # 처음 등장
                    info_dict[real_key] = [info_value]
    
    # 2. 점수 오름차순 (이진 탐색을 위해)
    for k, v in info_dict.items():
        v.sort()
    
    # 3. query 분리
    for q in query:
        tmp_q = q.split(' ')
        q_key = tmp_q[:-1] # 쿼리
        q_value = int(tmp_q[-1]) # 점수
        while 'and' in q_key: # 쿼리에서 and 제거
            q_key.remove('and')
        while '-' in q_key: # 쿼리에서 - 제거
            q_key.remove('-')
        q_key = ''.join(q_key)
        if q_key in info_dict: # 쿼리에 있으면
            start, end = 0, len(info_dict[q_key])
            while start < end:
                mid = (start + end) // 2
                if info_dict[q_key][mid] >= q_value: # 찾고자 하는 값보다 크면
                    end = mid # 범위 좁히기
                else: # 찾고자 하는 값보다 크면
                    start = mid + 1 # 범위 넓히기
            answer.append(len(info_dict[q_key]) - start)
        else:
            answer.append(0) # 쿼리에 없으면
    return answer
