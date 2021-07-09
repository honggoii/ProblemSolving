def solution(routes):
    answer = 0
    routes.sort(key=lambda x:x[1]) # 나간 지점 오름차순
    camera = -1e9
    
    for route in routes:
        if camera < route[0]:
            answer += 1
            camera = route[1]
    return answer
