#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(auto c : completion) {
        m[c] += 1;
    }
    
    
    for(auto c : participant) {
        m[c] -= 1;
        if (m[c] < 0) {
            answer = c;
            break;
        }
    }
    
    return answer;
}
