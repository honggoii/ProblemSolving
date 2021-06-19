#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v; //(한 변의 길이, 갯수)
bool flag = true;
int ans;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;//내림차순 정렬
}

void divide(int l, int w, int h, int idx) {
	if (l == 0 || w == 0 || h == 0)
		return;
	
	for (int i = idx; i < v.size(); i++) {
		if ((v[i].second > 0) && (l >= v[i].first && w >= v[i].first && h >= v[i].first)) {
			ans++;
			v[i].second--;
			divide(l - v[i].first, w, h, i);
			divide(v[i].first, w - v[i].first, h, i);
			divide(v[i].first, v[i].first, h - v[i].first, i);
			return;
		}
	}

	flag = false;
}

int main() {

	int l, w, h;
	scanf("%d%d%d", &l, &w, &h);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back({ pow(2, a),b });
	}
	sort(v.begin(), v.end(), cmp);
	divide(l, w, h, 0);
	if (flag)
		printf("%d", ans);
	else
		printf("-1");
	return 0;
}
