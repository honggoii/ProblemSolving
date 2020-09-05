#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int main() {
	freopen("sample.txt", "r", stdin);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		if (s == "push_front") {
			int a;
			cin >> a;
			dq.push_front(a);
		}
		else if (s == "push_back") {
			int a;
			cin >> a;
			dq.push_back(a);
		}
		else if (s == "pop_front") {
			if (dq.empty())
				cout << "-1" << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty())
				cout << "-1" << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size() << "\n";
		}
		else if (s == "empty") {
			if (dq.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if (s == "front") {
			if (dq.empty())
				cout << "-1" << "\n";
			else
				cout << dq.front() << "\n";
		}
		else if (s == "back") {
			if (dq.empty())
				cout << "-1" << "\n";
			else
				cout << dq.back() << "\n";
		}
	}
	return 0;
}
