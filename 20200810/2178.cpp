#include <cstdio>
#include <queue>
using namespace std;
int graph[101][101];
bool visit[101][101];
typedef struct {
	int x, y;
}Point;
queue<Point> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;
void bfs(Point p) {
	Point next;
	visit[p.y][p.x] = true;
	q.push(p);
	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			next.x = dx[i] + cur.x;
			next.y = dy[i] + cur.y;
			if (!visit[next.y][next.x] && graph[next.y][next.x]
				&& (next.y>=1 && next.y<=n && next.x>=1 && next.x<=m)) {
				visit[next.y][next.x] = true;
				graph[next.y][next.x] = graph[cur.y][cur.x] + 1;
				q.push(next);
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	bfs({ 1,1 });
	printf("%d", graph[n][m]);
	return 0;
}
