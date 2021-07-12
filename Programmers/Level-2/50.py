import re

def solution(files):
    answer = [re.split(r"([\d]+)", file) for file in files]
    answer.sort(key=lambda x:(x[0].lower(), int(x[1])))
    return [''.join(a) for a in answer]
