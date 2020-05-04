#include <cstdio>
#include <cstring>

int m, n, k;
int graph[51][51];
int visit[51][51];
int cnt;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

typedef struct {
	int x, y;
} point;

void dfs(point p) {
	visit[p.y][p.x] = true;
	point next;

	for (int i = 0; i < 4; i++) {
		next.y = p.y + dy[i];
		next.x = p.x + dx[i];

		if (!visit[next.y][next.x] && graph[next.y][next.x] &&
			next.x >= 0 && next.x < m && next.y >= 0 && next.y < n) {
			dfs(next);
		}
	}
}

int main() {
	freopen("sample.txt", "r", stdin);
	int t;
	scanf("%d", &t);

	while (t--) {
		cnt = 0;
		memset(visit, false, sizeof(visit));
		memset(graph, 0, sizeof(graph));
		scanf("%d%d%d", &m, &n, &k);

		while (k--) {
			int a, b;
			scanf("%d%d", &a, &b);
			graph[b][a] = 1;
		}		
		

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == 1 && !visit[i][j]) {
					dfs({ j,i });
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}
	
	

	return 0;
}