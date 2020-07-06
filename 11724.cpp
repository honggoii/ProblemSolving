#include <cstdio>

int graph[1001][1001];
bool visit[1001];
int cnt;
int n, m;

void dfs(int cur) {
	visit[cur] = true;

	for (int next = 1; next <= n; next++) {
		if (graph[cur][next] && !visit[next])
			dfs(next);
	}
}

int main() {
	freopen("sample.txt", "r", stdin);
	scanf("%d%d", &n, &m);

	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {
			graph[i][j] = 1;
			if (graph[i][j] && !visit[j]) {
				dfs(j);
				cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}