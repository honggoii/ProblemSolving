def solution(phone_book):
    phone_book.sort() # 오름차순 정렬
    
    phone = {} # {번호:1}
    for p in phone_book:
        phone[p] = 1
    
    for i in range(len(phone_book)-1):
        sz = len(phone_book[i]) #번호 길이
        tmp = phone_book[i+1][:sz]
        if tmp == phone_book[i]:
            return False
            
    return True
