def solution(s):
    answer = []
    
    # 맨앞 {{ 과 맨뒤 }}를 제거
    # },{를 기준으로 분리
    datas = s.lstrip('{').rstrip('}').split('},{')
    datas.sort(key=len) # 길이 기준 오름차순 정렬
    
    for data in datas: # 분리한 리스트 원소를
        data_split = data.split(',') # 다시 ,로 분리
        for i in data_split:
            if int(i) not in answer:
                answer.append(int(i))
    return answer
