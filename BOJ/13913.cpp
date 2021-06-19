#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> v;
int n, k;
int visit[100100];
int map[100100];
int discover[100100];
bool range(int nxt) {
	return nxt >= 0 && nxt <= 100000;
}
void bfs(int n) {
	visit[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == k) {
			return;
		}

		if (range(cur - 1) && visit[cur-1] == 0) {
			q.push(cur - 1);
			discover[cur - 1] = cur;
			visit[cur - 1] = visit[cur] + 1;
		}
		if (range(cur + 1) && visit[cur + 1] == 0) {
			q.push(cur + 1);
			discover[cur + 1] = cur;
			visit[cur + 1] = visit[cur] + 1;
		}
		if (range(cur * 2) && visit[cur * 2] == 0) {
			q.push(cur * 2);
			discover[cur * 2] = cur;
			visit[cur * 2] = visit[cur] + 1;
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	bfs(n);
	printf("%d\n", visit[k]);
	int idx = k;
	v.push_back(k);
	while (idx != n) {
		v.push_back(discover[idx]);
		idx = discover[idx];
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		printf("%d ", v[i]);
	}
	return 0;
}
