def solution(numbers, hand):
    answer = ''
    board = {1:(0,0), 2:(0,1), 3:(0,2),
            4:(1,0), 5:(1,1), 6:(1,2),
            7:(2,0), 8:(2,1), 9:(2,2),
            '*':(3,0), 0:(3,1), '#':(3,2)}
    
    left = [1, 4, 7]
    right = [3, 6, 9]
    lhand = '*'
    rhand = '#'
    
    for i in numbers:
        if i in left:
            answer += 'L'
            lhand = i
        elif i in right:
            answer += 'R'
            rhand = i
        else:
            ldis = abs(board[lhand][0]-board[i][0]) + abs(board[lhand][1]-board[i][1])
            rdis = abs(board[rhand][0]-board[i][0]) + abs(board[rhand][1]-board[i][1])
            
            if ldis < rdis:
                answer += 'L'
                lhand = i
            elif rdis < ldis:
                answer += 'R'
                rhand = i
            else:
                if hand == 'right':
                    answer += 'R'
                    rhand = i
                else:
                    answer += 'L'
                    lhand = i
            
    return answer
