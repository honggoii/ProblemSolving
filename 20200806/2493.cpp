#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int i = 1;
	pair<int, int> p;
	vector<pair<int, int>> v;
	stack<pair<int, int>> st;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v.push_back(make_pair(i, a));
	}
	i = 0;
	st.push(v[i++]);
	cout << "0" << ' ';
	while (i < n) {
		while (!st.empty() && (st.top().second < v[i].second)) {
			st.pop();
		}
		if (st.empty()) {
			cout << "0" << ' ';
		}
		else {
			cout << st.top().first << ' ';
		}
		st.push(v[i++]);
	}
	return 0;
}
