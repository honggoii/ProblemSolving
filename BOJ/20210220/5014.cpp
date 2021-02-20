#include <cstdio>
#include <queue>
using namespace std;
int arr[1000001];
int visit[1000001];
queue<int> q;
int f, s, g, u, d;
bool range(int next) {
	return next >= 1 && next <= f;
}
void bfs(int s) {
	visit[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == g) {
			printf("%d", visit[cur] - 1);
			return;
		}

		if (range(cur + u) && visit[cur + u] == 0) {
			q.push(cur + u);
			visit[cur + u] = visit[cur] + 1;
		}
		if (range(cur - d) && visit[cur - d] == 0) {
			q.push(cur - d);
			visit[cur - d] = visit[cur] + 1;
		}
	}
	printf("use the stairs");
}
int main() {
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	bfs(s);
	return 0;
}
