#include <cstdio>
#include <queue>
using namespace std;
int n, k;//수빈, 동생
int map[100011];
int visit[100011];
int dx[] = { -1,1 };
queue<int> q;
bool range(int next) {
	return next >= 0 && next <= 100000;
}
void bfs(int n) {
	visit[n] = 1;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (range(2 * cur)) {
			visit[2 * cur] = visit[cur];
			q.push(2 * cur);
		}		
		if (2 * cur == k || cur == k)
			break;
		for (int i = 0; i < 2; i++) {
			int next = cur + dx[i];
			if (range(next) && !visit[next]) {
				q.push(next);
				visit[next] = visit[cur] + 1;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	bfs(n);
	printf("%d", visit[k]-1);
	return 0;
}
