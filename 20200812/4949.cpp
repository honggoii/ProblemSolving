#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		string s;
		stack<char> st;
		bool flag = true;
		getline(cin, s);
		if (s == ".")
			break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '[')
				st.push(s[i]);
			if (s[i] == '(')
				st.push(s[i]);

			if (s[i] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else {
					flag = false;
					break;
				}
			}

			if (s[i] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else {
					flag = false;
					break;
				}
			}
		}

		if (!flag || st.size() > 0)
			cout << "no" << '\n';
		else 
			cout << "yes" << '\n';
	}
	return 0;
}
