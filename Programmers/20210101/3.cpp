#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            continue;
        }

        if ('a' <= s[i] && s[i] <= 'z')
            answer += (s[i] + n - 'a') % 26 + 'a';
        else if ('A' <= s[i] && s[i] <= 'Z')
            answer += (s[i] + n - 'A') % 26 + 'A';

    }
    return answer;
}
