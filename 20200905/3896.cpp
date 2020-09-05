#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		string s;
		cin >> s;
		stack<char> st;
		st.push(s[0]);
		for (int i = 1; i < s.length(); i++) {
			if (!st.empty()) {
				if (st.top() == s[i])
					st.pop();
                else
                    st.push(s[i]);
			}
			else
				st.push(s[i]);
		}
		if (st.empty())
			ans++;
	}
	printf("%d", ans);
	return 0;
}
