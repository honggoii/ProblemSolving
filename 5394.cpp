#include <iostream>
#include <list>
using namespace std;
int tc;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		string s;
		list<char> li;
		cin >> s;
		auto cur = li.begin();
		for (auto c : s) {
			if (c == '-') {
				if (cur != li.begin()) {
					cur--;
					cur = li.erase(cur);
				}
			}
			else if (c == '<') {
				if (cur != li.begin())
					cur--;
			}
			else if (c == '>') {
				if (cur != li.end())
					cur++;
			}
			else {
				li.insert(cur, c);
			}
		}

		for (auto cur = li.begin(); cur != li.end(); cur++)
			cout << *cur;

		cout << '\n';
	}
	return 0;
}
