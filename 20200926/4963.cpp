#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int w, h;
int map[51][51];//map
bool visit[51][51];//방문
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
typedef struct {
	int x, y;
}Point;
bool range(Point next) {
	return next.x >= 0 && next.x < w&& next.y >= 0 && next.y < h;
}
void bfs(Point p) {
	queue<Point> q;
	q.push(p);
	visit[p.y][p.x] = true;
	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		Point next;
		for (int i = 0; i < 8; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if (range(next) && map[next.y][next.x] == 1 && !visit[next.y][next.x]) {
				visit[next.y][next.x] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	while (1) {
		scanf("%d%d", &w, &h);//너비, 높이
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		int cnt = 0;//섬 개수
		if (w == 0 && h == 0)
			break;//무한 loop 종료 조건
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j] && map[i][j] == 1) {
					bfs({ j,i });
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
