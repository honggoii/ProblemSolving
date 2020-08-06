#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	stack<int> st;
	long long cnt = 0;
	while (n--) {
		int cur;
		cin >> cur;
		
		while (!st.empty() && st.top() <= cur)
			st.pop();

		cnt += st.size();
		st.push(cur);
	}

	cout << cnt;
	return 0;
}
