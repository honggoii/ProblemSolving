#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int r;//반복 횟수
		cin >> r;
		string s;
		cin >> s;
		string ans;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < r; j++)
				ans += s[i];
		}
		cout << ans << "\n";
	}
}
