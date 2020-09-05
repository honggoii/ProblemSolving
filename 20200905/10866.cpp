#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		if (!s.compare("push_front")) {
			int a;
			cin >> a;
			dq.push_front(a);
		}
		else if (!s.compare("push_back")) {
			int a;
			cin >> a;
			dq.push_back(a);
		}
		else if (!s.compare("pop_front")) {
			if (dq.empty())
				cout << "-1" << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (!s.compare("pop_back")) {
			if (dq.empty())
				cout << "-1" << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (!s.compare("size")) {
			cout << dq.size() << "\n";
		}
		else if (!s.compare("empty")) {
			if (dq.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if (!s.compare("front")) {
			if (dq.empty())
				cout << "-1" << "\n";
			else
				cout << dq.front() << "\n";
		}
		else if (!s.compare("back")) {
			if (dq.empty())
				cout << "-1" << "\n";
			else
				cout << dq.back() << "\n";
		}
	}
	return 0;
}
