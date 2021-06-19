#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int ans;
vector<pair<int, int>> v;//(마감일, 점수)
int day[1001];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d, w;
		scanf("%d%d", &d, &w);
		v.push_back({ d, w });
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		if (day[v[i].first] == 0) {
			day[v[i].first] = v[i].second;
		}
		else {
			for (int j = v[i].first; j > 0; j--) {
				if (day[j] == 0) {
					day[j] = v[i].second;
					break;
				}
			}
		}
	}

	for (int i = 1; i < 1001; i++) {
		if (day[i] != 0)
			ans += day[i];
	}

	printf("%d", ans);
	
	return 0;
}
