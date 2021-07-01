def solution(genres, plays):
    answer = []
    genre = {}
    music = {}
    for i in range(len(genres)):
        if genres[i] not in genre:
            genre[genres[i]] = plays[i]
            music[genres[i]] = []
            music[genres[i]].append(i)
        else:
            genre[genres[i]] += plays[i]
            music[genres[i]].append(i)
    genre = sorted(genre.items(), key=(lambda x: x[1]), reverse=True) # 많이 재생된 장르 순

    for key in genre: # 장르 하나를 뽑고
        cnt = 0
        tmp = [] # 
        for i in music[key[0]]:
            tmp.append((plays[i], i)) # 재생시간, 인덱스
        tmp.sort(key=lambda x:(-x[0], x[1])) # 재생시간 내림차순, 인덱스 오름차순
        
        for t in tmp:
            cnt += 1
            answer.append(t[1])
            if cnt == 2: # 장르별 두 개씩만
                break

    return answer
