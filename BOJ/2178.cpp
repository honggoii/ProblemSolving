#include <cstdio>
#include <queue>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[110][110];
int visit[110][110];
typedef struct {
	int x, y;
} Point;
queue<Point> q;
bool range(Point nxt) {
	return nxt.x >= 1 && nxt.x <= 100 && nxt.y >= 1 && nxt.y <= 100;
}
int n, m;
void bfs(Point p) {
	q.push(p);
	visit[p.x][p.y] = 1;
	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		if (cur.x == n && cur.y == m)
			return;//종료 조건
		Point nxt;
		for (int i = 0; i < 4; i++) {
			nxt.x = cur.x + dx[i];
			nxt.y = cur.y + dy[i];

			if (range(nxt) && visit[nxt.x][nxt.y] == 0 && map[nxt.x][nxt.y] == 1) {
				visit[nxt.x][nxt.y] = visit[cur.x][cur.y] + 1;
				q.push(nxt);
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs({ 1,1 });
	printf("%d", visit[n][m]);
	
	return 0;
}
