#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, int>> v;
int cnt = 1;
int standard;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	freopen("sample.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), cmp);

	standard = v[0].second;

	for (int i = 1; i < n; i++) {
		if (standard > v[i].first) {
			continue;
		}			
		else {
			cnt++;
			standard = v[i].second;
		}
	}

	printf("%d\n", cnt);

	return 0;
}