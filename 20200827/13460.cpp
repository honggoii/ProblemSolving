#include <cstdio>
#include <queue>
using namespace std;
int n, m;
char map[11][11];
int visit[11][11][11][11];//[redx][redy][bluex][bluey]
typedef struct {
	int cnt;
	int rx, ry;//빨간 구슬
	int bx, by;//파란 구슬
} Point;
int rx, ry, bx, by;
int hx;
int hy;//구멍 위치
queue<Point> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool flag = false;
int ans;
void bfs() {
	q.push({ 0, rx,ry,bx,by });
	visit[rx][ry][bx][by] = true;//방문 체크
	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		if (cur.cnt > 10)
			break;

		if (cur.rx == hx && cur.ry == hy) {
			//빨간공이 구멍으로 빠져나면 그만하기
			ans = cur.cnt;
			flag = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			Point next;
			next.rx = cur.rx + dx[i];//빨간공
			next.ry = cur.ry + dy[i];//빨간공
			next.bx = cur.bx + dx[i];//파란공
			next.by = cur.by + dy[i];//파란공

			//벽 만날때까지 굴리기(빨간공)
			while (1) {
				if (map[next.rx][next.ry] == '#') {
					next.rx -= dx[i];//벽닿기 전으로
					next.ry -= dy[i];//벽닿기 전으로
					break;
				}
				if (map[next.rx][next.ry] == 'O') {
					//구멍 만나면
					break;
				}
				next.rx += dx[i];//굴리기
				next.ry += dy[i];//굴리기
			}
			//벽 만날때까지 굴리기(파란공)
			while (1) {
				if (map[next.bx][next.by] == '#') {
					next.bx -= dx[i];//벽닿기 전으로
					next.by -= dy[i];//벽닿기 전으로
					break;
				}
				if (map[next.bx][next.by] == 'O') {
					//구멍 만나면
					break;
				}
				next.bx += dx[i];//굴리기
				next.by += dy[i];//굴리기
			}

			//파란공이 구멍에 빠졌으면 이렇게 더이상 하면 안됨
			if (next.bx == hx && next.by == hy) continue;

			//위치가 겹치면 더 늦게 온 구슬을 한칸 뒤로
			if (next.rx == next.bx && next.ry == next.by) {
				switch (i) {
				case 0:
					cur.rx > cur.bx ? next.rx++ : next.bx++;
					break;
				case 1:
					cur.rx < cur.bx ? next.rx-- : next.bx--;
					break;
				case 2:
					cur.ry > cur.by ? next.ry++ : next.by++;
					break;
				case 3:
					cur.ry < cur.by ? next.ry-- : next.by--;
					break;
				}
			}

			//방문 체크하고 큐에넣기
			if (!visit[next.rx][next.ry][next.bx][next.by]) {
				visit[next.rx][next.ry][next.bx][next.by] = true;
				q.push({ cur.cnt + 1,next.rx,next.ry,next.bx,next.by });
			}
		}

		if (flag)
			break;
	}
}
void makeMap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (map[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else if (map[i][j] == 'O') {
				hx = i;
				hy = j;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	makeMap();//맵 만들기
	bfs();//빨간 구슬 굴리기
	if (!flag)
		printf("-1");
	else
		printf("%d", ans);
	return 0;
}
