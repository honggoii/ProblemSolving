#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;
stack<int> st;

string solution(string number, int k) {
    string answer = "";
    st.push(number[0] - '0');
    int cnt = number.size() - k;
    for (int i = 1; i < number.size(); i++) {
        int num = number[i] - '0';
        while (!st.empty() && (k > 0) && st.top() < num) {
            st.pop();
            k--;
        }            
        st.push(num);
    }

    int i = 0;
    while (!st.empty()) {
        answer += to_string(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    answer = answer.substr(0, cnt);
    
    return answer;
}
