#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    for (int i=0; s[i]; i++) {
        if (s[i] == ' '){
             flag = true;
        }
        else if (flag && ('a' <= s[i] && s[i] <= 'z')) {
            //첫 문자면 대문자로
            s[i] -= 32;
            flag = false;
        }
        else if (!flag && ('A' <= s[i] && s[i] <= 'Z')) {
            //나머지는 소문자로
            s[i] += 32;
        }
        else {
            flag = false;//숫자면
        }
        answer += s[i];
    }
    
    return answer;
}
