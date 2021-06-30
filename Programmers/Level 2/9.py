from collections import deque


def solution(bridge_length, weight, truck_weights):
    answer = 1
    q = deque()
    q.append([1, truck_weights[0]])
    idx = 1
    now = truck_weights[0]  # 현재 다리 위 트럭 무게

    while q:
        answer += 1

        if q[0][0] >= bridge_length:
            now -= q[0][1]
            q.popleft() # 트럭 나갈차례

        if idx < len(truck_weights) and (now + truck_weights[idx]) <= weight:
            now += truck_weights[idx]
            q.append([0, truck_weights[idx]])
            idx += 1
        
        for i in q:
            i[0] += 1

    return answer
