#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int sz = s.size();
    if (sz % 2 == 0) {
       //짝수
        answer += s.at(sz/2-1);
        answer += s.at(sz/2);
    }
    else {
        //홀수
        answer = s.at(sz/2);
    }
    return answer;
}
