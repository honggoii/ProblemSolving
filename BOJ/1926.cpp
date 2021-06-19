#include <cstdio>
#include <queue>
using namespace std;
int m, n;
int graph[501][501];
bool visit[510][510];
int cnt;
int area;
int tmp;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef struct {
	int x;
	int y;
} Point;
queue<Point> q;
bool range(Point next) {
	return next.x >= 0 && next.x < n && next.y >= 0 && next.y < m;
}
void bfs(Point p) {
	visit[p.x][p.y] = true;
	q.push(p);
	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		Point next;
		for (int i = 0; i < 4; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && !visit[next.x][next.y] && graph[next.x][next.y] == 1) {
				tmp++;
				visit[next.x][next.y] = true;
				q.push(next);
			}
		}	
	}
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &graph[i][j]);
		}
	}
}
int main() {

	scanf("%d%d", &n, &m);//행 열
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 1 && !visit[i][j]) {
				cnt++;
				tmp = 1;
				bfs({ i,j });
				if (area < tmp)
					area = tmp;//최대 넓이 갱신
			}
		}
	}
	printf("%d\n%d", cnt, area);
	
	return 0;
}
