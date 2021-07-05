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
        
        for result in pick_order: # 만든 조합이 몇개 뽑혔는지
            if pick_order[result] == max([pick_order[x] for x in pick_order]):
                if pick_order[result] > 1:
                    answer.append(result)
                    
    return sorted(answer)
