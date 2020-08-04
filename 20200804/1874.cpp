#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<int> st;
queue<char> q;
int i = 1;
int main(void) {   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        while (i <= a) {
            st.push(i++);
            q.push('+');
        }
        
        if (st.top() == a) {
            st.pop();
            q.push('-');
        }

        if (!st.empty() && st.top() > a) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    while (!q.empty()) {
        cout << q.front() << '\n';
        q.pop();
    }
    return 0;
}
