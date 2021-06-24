def solution(people, limit):
    answer = 0
    people.sort()
    start = 0
    end = len(people)-1
    
    while start <= end:
        if limit >= (people[start] + people[end]):
            start += 1
        answer += 1
        end -= 1
            
    return answer
