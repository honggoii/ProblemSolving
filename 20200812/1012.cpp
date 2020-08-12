#include <cstdio>
#include <cstring>
using namespace std;
int m, n, k;
int graph[51][51];
bool visit[51][51];
int cnt;//지렁이 수
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef struct {
	int x, y;
} Point;
bool range(Point p) {
	if (p.x >= 0 && p.x < m && p.y >= 0 && p.y < n)
		return true;
	else
		return false;
}
void dfs(Point p) {
	Point next;
	visit[p.y][p.x] = true;

	for (int i = 0; i < 4; i++) {
		next.x = p.x + dx[i];
		next.y = p.y + dy[i];

		if (range(next) && !visit[next.y][next.x] && graph[next.y][next.x]) {
			dfs(next);
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(graph, 0, sizeof(graph));
		memset(visit, 0, sizeof(visit));
		scanf("%d%d%d", &m, &n, &k);

		while (k--) {
			int x, y;
			scanf("%d%d", &x, &y);
			graph[y][x] = 1;
		}		
		
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && graph[i][j]) {
					dfs({ j,i });
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);

	}
	return 0;
}
