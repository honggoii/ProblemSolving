#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> nation[1100];
bool visit[1100];
int n, m;//국가, 비행기
int ans;
void airplan(int idx) {
	visit[idx] = true;

	for (int i = 0; i < nation[idx].size(); i++) {
		if (visit[nation[idx][i]]) continue;
		ans++;
		airplan(nation[idx][i]);
	}
}
void connect() {
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		nation[a].push_back(b);
		nation[b].push_back(a);
	}
}
void init() {
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < 1100; i++) {
		nation[i].clear();
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		ans = 0;
		init();//초기화
		connect();//비행기로 나라 연결
		for (int i = 1; i <= n; i++) {
			if (visit[i]) continue;
			airplan(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
