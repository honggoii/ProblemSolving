#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
vector<long long> ans;
bool cmp(long long a, long long b) {
	return a < b;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int j = s.length() - 1;
		while (s[j] == '0') {
			j--;
		}
		s = s.substr(0, j+1);
		reverse(s.begin(), s.end());
		ans.push_back(stoll(s));
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
	
	return 0;
}
