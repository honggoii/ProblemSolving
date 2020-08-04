#include <iostream>
#include <stack>
using namespace std;
int k;
stack<int> st;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    while (k--) {
        int a;
        cin >> a;
        if (a == 0) {
            st.pop();
        }
        else {
            st.push(a);
        }
    }
    long long sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum;
    return 0;
}
