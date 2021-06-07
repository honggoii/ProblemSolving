def solution(new_id):
    answer = ''
    new_id = new_id.lower() # 1. 소문자 치환
    
    # 2. 소문자, 숫자, -, _, . 제외 문자 제거 
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    digit = '0123456789'
    characters = '-_.'
    #characters = "~!@#$%^&*()+=`\|"
    #new_id = ''.join(x for x in new_id if x not in characters)
    for i in new_id:
        if i in alpha or i in digit or i in characters:
            answer += i
    new_id = ""
    cnt = 0
    # 3. 마침표 2번 이상 -> 마침표 하나로
    for i in answer:
        if i == '.':
            cnt += 1
        else:
            if cnt >= 1:
                new_id += '.'
                new_id += i
                cnt = 0
            else:
                new_id += i
    
    # 4. 마침표가 처음이나 끝이면 제거
    if len(new_id) != 0 and new_id[0] == '.':
        new_id = new_id[1:len(new_id)]
    if len(new_id) != 0 and new_id[len(new_id)-1] == '.':
        new_id = new_id[0:len(new_id)]
    
    # 5. 빈 문자열이면 "a" 대입
    if len(new_id) == 0:
        new_id += 'a'
        
    # 7. 길이가 2자 이하, 길이가 3될 때까지 마지막 문자 반복
    if len(new_id) <= 2:
        tmp = new_id[len(new_id)-1]
        for i in range(len(new_id), 3):
            new_id += tmp
    # 6. 길이가 16자 이상, 15개 문자외 제거, 마침표가 맨 끝이면 제거
    elif len(new_id) >= 16:
        new_id = new_id[0:15]
        if new_id[14] == '.':
            new_id = new_id[:14]
    
    answer = new_id
    return answer
