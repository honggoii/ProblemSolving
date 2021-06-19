def solution(phone_number):
    answer = ''
    phone_number = phone_number + ''
    a = len(phone_number)

    answer = ('*' * (a-4)) + phone_number[a-4:]
        
    return answer
