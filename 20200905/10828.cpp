#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		if (!s.compare("push")) {
			int a;
			cin >> a;
			st.push(a);
		}
		else if (!s.compare("pop")) {
			if (st.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (!s.compare("size")) {
			cout << st.size() << "\n";
		}
		else if (!s.compare("empty")) {
			if (st.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (!s.compare("top")) {
			if (st.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << st.top() << "\n";
			}
		}
	}
	return 0;
}
