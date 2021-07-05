import itertools

def solution(orders, course):
    answer = []
    
    for cnt in course: # 구성할 수 있는 단품메뉴 갯수 뽑기
        pick_order = {} # 뽑은 메뉴
        pick_combination = [] # 뽑은 조합
        
        for order in orders: # 각 메뉴마다 갯수만큼 조합으로 뽑는다.
            pick_combination.extend(list(itertools.combinations(sorted(order), cnt)))
            
        for pick in pick_combination:
            tmp_order = ''.join(pick) # 리스트 -> 문자열
            if tmp_order in pick_order:
                pick_order[tmp_order] += 1
            else:
                pick_order[tmp_order] = 1
        
        pick_order = sorted(pick_order.items(), key=lambda x:x[1], reverse = True) # 내림차순 정렬
        tmp_max = 0
        
        for result in pick_order: # 만든 조합이 몇개 뽑혔는지
            if result[1] <= 1: continue# 1번 이상 뽑히지 않으면 탈락
            if tmp_max <= result[1]:
                tmp_max = result[1]
                answer.append(result[0])
    return sorted(answer)
