def changecode(m):
    m = m.replace('C#', 'c')
    m =  m.replace('D#', 'd')
    m = m.replace('F#', 'f')
    m = m.replace('G#', 'g')
    m = m.replace('A#', 'a')
    return m

def solution(m, musicinfos):
    answer = []
    m = changecode(m)
    
    for musicinfo in musicinfos:
        # 1. 시작시간, 끝시간, 제목, 악보 분리
        music = musicinfo.split(',')
        start = music[0].split(':')  # 시작시간
        end = music[1].split(':')  # 끝시간
        start_time = int(start[0]) * 60 + int(start[1])
        end_time = int(end[0]) * 60 + int(end[1])
        play_time = end_time - start_time

        music[3] = changecode(music[3])
        
        if play_time < len(music[3]): # 2. 음악 길이가 시간보다 긴 경우
            sheet = music[3][:play_time]
        else: # 3. (끝 시간 - 시작 시간) 길이 만큼 악보 붙이기
            sheet = music[3] * (play_time // len(music[3]))
            sheet += music[3][:play_time % len(music[3])]
            
        if m in sheet: # 4. m in 악보
            answer.append([play_time, music[2]]) # 정답 후보
    
    if len(answer) != 0:
        answer = sorted(answer, key=lambda x: (-x[0]))# 재생 시간 내림차순
        return answer[0][1]
    return "(None)" # 조건에 일치하는 음악이 없는 경우
