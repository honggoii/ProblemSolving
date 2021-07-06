import heapq

def dijkstra(graph, distance, answer, K):
    q = []
    heapq.heappush(q, (0, 1))
    distance[1] = 0
    
    while q:
        dist, now = heapq.heappop(q)
        if K < dist: # K 시간내에 배달 할 수 없음
            break
            
        if distance[now] < dist: # 이미 방문
            continue
        answer += 1
        
        for i in graph[now]: # 인접 노드 확인
            cost = dist + i[0]
            if cost < distance[i[1]]: # 더 짧은 거리 확인되면
                distance[i[1]] = cost # 최소값으로 갱신
                heapq.heappush(q, (cost, i[1]))
    return answer

def solution(N, road, K):
    graph = [[] for _ in range(52)] # 그래프
    distance = [int(1e9)] * 52 # 최단거리 테이블 초기화
    
    for r in road:
        a, b, c = r # a, b는 마을번호 c는 시간
        graph[a].append((c, b)) # 양방향 연결
        graph[b].append((c, a)) # 양방향 연결
    
    answer = dijkstra(graph, distance, 0, K)

    return answer
