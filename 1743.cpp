#include <cstdio>
#include <cstring>

int n, m, k;
int r, c;
int cnt;
int max;
int graph[101][101];
int trash[101][101];
bool visit[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };


typedef struct {
	int x, y;
} point;

void dfs(point p) {
	visit[p.y][p.x] = true;
	point next;

	for (int i = 0; i < 4; i++) {
		next.x = p.x + dx[i];
		next.y = p.y + dy[i];

		if ( !visit[next.y][next.x] && graph[next.y][next.x] == 1&&
			next.x > 0 && next.x <= m && next.y > 0 && next.y <= n) {
			cnt++;
			dfs(next);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	while (k--) {
		scanf("%d%d", &r, &c);
		graph[r][c] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] == 1 && !visit[i][j]) {
				cnt = 1;
				dfs({ j,i });
				if (max <= cnt)
					max = cnt;
			}				
		}
	}

	printf("%d\n", max);

	return 0;
}