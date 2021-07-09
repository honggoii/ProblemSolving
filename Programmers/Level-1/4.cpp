#include <string>
#include <vector>

using namespace std;

typedef struct {
    int x, y;
} Point;

int distance(Point handloc, Point num) {
    return abs(handloc.x - num.x) + abs(handloc.y - num.y);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    Point lhand = { 3,0 };//왼손 시작점
    Point rhand = { 3,2 };//오른손 시작점

    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        switch(num) {
        case 1:
            lhand = { 0,0 };
            answer += 'L';
            break;
        case 3:
            rhand = { 0,2 };
            answer += 'R';
            break;
        case 4:
            lhand = { 1,0 };
            answer += 'L';
            break;
        case 6:
            rhand = { 1,2 };
            answer += 'R';
            break;
        case 7:
            lhand = { 2,0 };
            answer += 'L';
            break;
        case 9:
            rhand = { 2,2 };
            answer += 'R';
            break;
        default:
            Point temp;
            if (num == 0) {
                temp = { 3,1 };
            }
            else {
                temp = { num / 3, num % 3 - 1 };
            }

            int ldis = distance(lhand, temp);
            int rdis = distance(rhand, temp);

            if (ldis > rdis) {
                rhand = temp;
                answer += 'R';
            }
            else if (ldis < rdis) {
                lhand = temp;
                answer += 'L';
            }
            else {
                if (hand == "right") {
                    rhand = temp;
                    answer += 'R';
                }
                else {
                    lhand = temp;
                    answer += 'L';
                }                    
            }

            break;
        }
    }
    return answer;
}
