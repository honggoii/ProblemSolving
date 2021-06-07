def two(new_id):
    tmp = ''
    characters = '-_.'
    for i in new_id:
        if i.isalpha() or i.isdigit() or i in characters:
            tmp += i
    return tmp

def three(new_id):
    while '..' in new_id:
        new_id = new_id.replace('..', '.')
    return new_id

def four(new_id):
    if len(new_id) != 0 and new_id[0] == '.':
        new_id = new_id[1:]
    if len(new_id) != 0 and new_id[-1] == '.':
        new_id = new_id[:-1]
    return new_id

def five(new_id):
    if len(new_id) == 0:
        new_id += 'a'
    return new_id

def six(new_id):
    new_id = new_id[:15]
    if new_id[-1] == '.':
        new_id = new_id[:-1]
    return new_id

def seven(new_id):
    while len(new_id) < 3:
        new_id += new_id[-1]
    return new_id

def solution(new_id):
    answer = ''
    new_id = new_id.lower() # 1. 소문자 치환
    new_id = two(new_id) # 2. 소문자, 숫자, -, _, . 제외 문자 제거 
    new_id = three(new_id) # 3. 마침표 2번 이상 -> 마침표 하나로 
    new_id = four(new_id) # 4. 마침표가 처음이나 끝이면 제거
    new_id = five(new_id) # 5. 빈 문자열이면 "a" 대입
    
    if len(new_id) <= 2:
        new_id = seven(new_id) # 7. 길이가 2자 이하, 길이가 3될 때까지 마지막 문자 반복    
    elif len(new_id) >= 16:
        new_id = six(new_id) # 6. 길이가 16자 이상, 15개 문자외 제거, 마침표가 맨 끝이면 제거      
    answer = new_id
    
    return answer
