parent = [0] * 110

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

def solution(n, costs):
    answer = 0
    edges = []
    # 부모를 자기 자신으로 초기화
    for i in range(n):
        parent[i] = i
    for cost in costs:
        a, b, c = cost
        edges.append((c, a, b))
    edges.sort() # 비용 오름차순
    
    for edge in edges:
        c, a, b = edge
        if find_parent(parent, a) != find_parent(parent, b): # 같은 집합 아니면
            union_parent(parent, a, b)
            answer += c
    return answer
