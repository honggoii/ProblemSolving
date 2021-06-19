def solution(w,h):
    answer = 0
    while w != h:
        # h를 큰 수로
        if h < w:
            w, h = h, w
        answer += (w * w - w)
        h -= w
    answer += (w * w - w)
    return answer
