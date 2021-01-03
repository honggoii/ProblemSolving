int solution(string dartResult) {
    int answer = 0;
    int num = 0;
    int idx = 0;
    int check = 0;
    for (int i = 0; i < dartResult.size(); i++) {
        int temp = dartResult[i] - '0';

        if (0 <= temp && temp <= 9) {
            if (dartResult[i + 1] == '0') {
                //숫자 10처리
                temp = 10;
                i++;
            }
            num = temp;
        }
        else {
            char bonus = dartResult[i];
            switch (bonus) {
            case 'S':
                score[idx++] = pow(num, 1);
                break;
            case 'D':
                score[idx++] = pow(num, 2);
                break;
            case 'T':
                score[idx++] = pow(num, 3);
                break;
            }

            if (i < (dartResult.size()-1) && 
                dartResult[i + 1] == '*' || dartResult[i + 1] == '#') {
                char op = dartResult[i + 1];
                int cnt = 2;
                switch (op) {
                case '*':
                    check = idx - 1;
                    cnt = 2;
                    while (cnt>0 && idx>=0) {
                        score[idx-1] *= 2;
                        idx--;
                        cnt--;
                    }
                    idx = check + 1;
                    break;
                case '#':
                    score[idx-1] *= -1;
                    break;
                }
                i++;
            }
        }
    }

    for (int i = 0; i < 4; i++)
        answer += score[i];


    return answer;
}
