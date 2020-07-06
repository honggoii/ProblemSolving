#include <cstdio>
#include <queue>

using namespace std;
queue<int> q;
int graph[101][101];
int visit[101];
int n, a, b, m;

void bfs(int cur) {
	visit[cur] = 1;
	q.push(cur);

	while (!q.empty()) {
		int node = q.front(); q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[node][i] && visit[i] == 0) {
				visit[i] = visit[node] + 1;
				q.push(i);
			}
		}
	} 
}

int main() {
	freopen("sample.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &a, &b, &m);

	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	bfs(a);

	/*for (int i = 1; i < n; i++) {

		for (int j = i + 1; j <= n; j++) {
			if (graph[i][j] && visit[i] == 0) {
				bfs(i);
			}
		}
	}*/

	if (visit[b] == 1)
		printf("-1");
	else
		printf("%d", visit[b] - 1);

	return 0;
}