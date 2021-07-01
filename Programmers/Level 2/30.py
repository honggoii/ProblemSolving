def solution(phone_book):
    answer = True
    hashmap = {}
    for phone in phone_book:
        hashmap[phone] = 1 # 접두사가 될 수 있는 후보
    for phone in phone_book:
        tmp = ''
        for number in phone:
            tmp += number
            if tmp in phone_book and tmp != phone:
                return False
    return answer
