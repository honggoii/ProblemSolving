def solution(cacheSize, cities):
    answer = 0
    cache = []
    cities = [city.lower() for city in cities] # 소문자로 변환
    if cacheSize == 0: 
        return len(cities) * 5
    else:
        for city in cities:
            if city in cache: # 캐시에 데이터가 있으면 (cache hit)
                cache.pop(cache.index(city)) # 캐시에서 해당 도시를 없애고 
                cache.append(city) # 맨 뒤에 추가
                answer += 1
            else: # 캐시에 데이터가 없으면 (cache miss)
                if len(cache) == cacheSize: # 캐시가 꽉 찼으면
                    cache.pop(0) # 맨 앞 제거
                cache.append(city) # 맨 뒤 추가
                answer += 5
    return answer
