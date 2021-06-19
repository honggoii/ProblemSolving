#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    string temp = "Kim";
    int idx = 0; //김서방 위치
    for (int i=0; i < seoul.size(); i++) {
        if (seoul[i] == temp) {
            idx = i;
            break;
        }
    }
    
    answer = "김서방은 " + to_string(idx) +"에 있다";
    return answer;
}
