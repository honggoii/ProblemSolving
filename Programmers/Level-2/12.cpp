using namespace std;

long long solution(int w, int h) {
    long long answer = 0;
    
    while ((w != 0) && (h != 0)) {
        long long side = (w >= h) ? h : w;//w와 h중 작은 값으로 한 변의 정사각형을 만든다.
        answer += ((side * side) - side);
        //남은 거로 또 정사각형을 만든다.
        if (w == side) {
            //w가 작은 값이었으면
            h -= side;//큰 길이의 값을 빼준다.
        }
        else {
            w -= side;
        }
    }
    
    return answer;
}
