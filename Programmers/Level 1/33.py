def solution(strings, n):
    answer = []
    strings.sort()
    answer = sorted(strings, key=lambda temp: temp[n])
    return answer
