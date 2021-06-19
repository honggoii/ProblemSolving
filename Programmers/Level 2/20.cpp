#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int sz = s.size();
    stack<char> st;

    for (int i = 0; i < sz; i++) {
        if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')') {
            if (st.empty()) {
                answer = false;
                break;
            }
            st.pop();
        }
    }

    if (!st.empty())
        answer = false;
    return answer;
}
