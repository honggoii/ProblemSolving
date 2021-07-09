answer = ["ICN"]
visited = [False] * 11000

def dfs(now, cnt, tickets):
    tmp = 0
    if cnt == len(tickets):
        return True 
    
    for i in range(len(tickets)):
        if tickets[i][0] == now and visited[i] == False:
            tmp += 1
            visited[i] = True            
            answer.append(tickets[i][1])
            flag = dfs(tickets[i][1], cnt+1, tickets)
            if flag == False:
                tmp = 0
                visited[i] = False
                answer.pop()

    if tmp == 0 and cnt != len(tickets):
        return False
    
def solution(tickets):
    global answer
    tickets.sort(key=lambda x:x[1]) # 알파벳 순 정렬
    dfs("ICN", 0, tickets)
    return answer
