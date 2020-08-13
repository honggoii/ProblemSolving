#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int graph[101][101];
int visit[101];
queue<int> q;
int arr[101];
int cnt;
int ans = 1e9;
int idx;
void bfs(int node) {
	q.push(node);
	visit[node] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 1; i <= n; i++) {
			if (cur == i)
				continue;
			if (graph[cur][i] && visit[i] == 0) {
				visit[i] = visit[cur] + 1;
				q.push(i);
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		bfs(i);

		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			arr[i] += visit[j];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans > arr[i]) {
			ans = arr[i];
			idx = i;
		}			
	}
	printf("%d", idx);
	return 0;
}
