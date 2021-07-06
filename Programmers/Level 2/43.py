def solution(n, words):
    history = [] # 이제까지 등장한 단어들
    end = words[0][0] # 끝자리 저장
    idx = 0
    for word in words:
        if word not in history:
            history.append(word) # 단어 저장
        elif word in history or end != word[0]: # 등장한 단어
            return [(idx % n) + 1, (idx // n) + 1]
        
        if end != word[0]: # 끝말잇기가 아니면
            return [(idx % n) + 1, (idx // n) + 1]
        
        end = word[-1]        
        idx += 1
    return [0, 0]
