#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n;
int ans = 1e9;
vector<pair<int, int>> v;
pair<int, int> arr[100];
int visit[100];
void comb(int idx, int cnt, int pick) {
	if (cnt == pick) {
		int s = 1;
		int b = 0;
		for (int i = 0; i < cnt; i++) {
			s *= arr[i].first;
			b += arr[i].second;
		}
		if (abs(s - b) < ans)
			ans = abs(s - b);
		return;
	}

	for (int i = idx; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		arr[cnt] = { v[i].first, v[i].second };
		comb(i, cnt + 1, pick);
		visit[i] = false;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int s, b;
		scanf("%d%d", &s, &b);
		v.push_back({ s,b });
	}
	for (int i = 1; i <= n; i++) {
		comb(0, 0, i);
	}
	printf("%d", ans);
	return 0;
}
