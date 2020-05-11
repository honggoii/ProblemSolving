#include <cstdio>
#include <cstring>
#include <queue>

int graph[1001][1001];
bool visit[1001];
int n, m, v;
using namespace std;
queue<int> q;

void dfs(int node) {
	visit[node] = true;
	printf("%d ", node);

	for (int i = 1; i <= n; i++) {
		if (!visit[i] && graph[node][i])
			dfs(i);
	}
}

void bfs(int node) {
	visit[node] = true;
	q.push(node);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		printf("%d ", cur);
		for (int i = 1; i <= n; i++) {
			if (!visit[i] && graph[cur][i]) {
				visit[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	freopen("sample.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &m, &v);

	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(v);
	printf("\n");
	memset(visit, false, sizeof(visit));
	bfs(v);
	printf("\n");

	return 0;
}