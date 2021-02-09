#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<string, int>> v;
bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.first.length() != b.first.length()) {
		return a.first.length() < b.first.length();
	}
	else {
		if (a.second == b.second)
			return a < b;
		else 
			return a.second < b.second;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;

		int sum = 0;
		for (int j = 0; j < tmp.size(); j++) {
			if ((0 <= (tmp[j] - '0')) && ((tmp[j] - '0') <= 9)) {
				sum += (tmp[j] - '0');
			}
		}
		v.push_back({ tmp, sum });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << v[i].first << '\n';
	}
	return 0;
}
