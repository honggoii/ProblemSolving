#include <cstdio>
#include <queue>
using namespace std;
int n;
char map[51][51];//[x좌표][y좌표]
int visit[4][51][51];//[방향][x좌표][y좌표]=>거울 개수 저장
typedef struct {
	int x, y;
	int dir;//방향
} Point;
Point start;//시작점
Point finish;//도착점
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<Point> q;
bool range(Point next) {
	return next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= n;
}
void bfs() {
	for (int i = 0; i < 4; i++) {
		q.push({ start.x,start.y,i });//시작점에서 모든 방향 탐색
		visit[i][start.x][start.y] = 0;//시작점에서 거울개수는 0개
	}
	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		Point next;
		next.x = cur.x + dx[cur.dir];//진행 방향으로만 이동
		next.y = cur.y + dy[cur.dir];
		next.dir = cur.dir;

		if (range(next) && map[next.x][next.y] != '*') {
			if (map[next.x][next.y] == '.') {
				//빈 곳이면 그대로 진행
				if (visit[cur.dir][cur.x][cur.y] < visit[next.dir][next.x][next.y]) {
					visit[next.dir][next.x][next.y] = visit[cur.dir][cur.x][cur.y];
					q.push({ next.x,next.y,next.dir });
				}
			}
			else if (map[next.x][next.y] == '!') {
				//거울이면
				//1. 거울 설치 O => 거울개수+1, 방향 바꾸기
				if (cur.dir == 0 || cur.dir == 1) {
					if (visit[cur.dir][cur.x][cur.y] + 1 < visit[2][next.x][next.y]) {
						visit[2][next.x][next.y] = visit[cur.dir][cur.x][cur.y] + 1;
						q.push({ next.x,next.y,2 });
					}						
					if (visit[cur.dir][cur.x][cur.y] + 1 < visit[3][next.x][next.y]) {
						visit[3][next.x][next.y] = visit[cur.dir][cur.x][cur.y] + 1;
						q.push({ next.x,next.y,3 });
					}						
				}
				if (cur.dir == 2 || cur.dir == 3) {
					if (visit[cur.dir][cur.x][cur.y] + 1 < visit[0][next.x][next.y]) {
						visit[0][next.x][next.y] = visit[cur.dir][cur.x][cur.y] + 1;
						q.push({ next.x,next.y,0 });
					}
					if (visit[cur.dir][cur.x][cur.y] + 1 < visit[1][next.x][next.y]) {
						visit[1][next.x][next.y] = visit[cur.dir][cur.x][cur.y] + 1;
						q.push({ next.x,next.y,1 });
					}						
				}
				//2. 거울 설치 X => 거울개수유지, 방향 유지
				if (visit[cur.dir][cur.x][cur.y] < visit[next.dir][next.x][next.y]) {
					visit[next.dir][next.x][next.y] = visit[cur.dir][cur.x][cur.y];
					q.push({ next.x,next.y,next.dir });
				}
			}
			else if (map[next.x][next.y] == '#') {
				if (visit[cur.dir][cur.x][cur.y] < visit[next.dir][next.x][next.y])
					visit[next.dir][next.x][next.y] = visit[cur.dir][cur.x][cur.y];
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %1c", &map[i][j]);
			if (temp == 0 && map[i][j] == '#') {
				start.x = i;
				start.y = j;
				temp++;
			}
			if (temp == 1 && map[i][j] == '#') {
				finish.x = i;
				finish.y = j;
			}
			for (int k = 0; k < 4; k++)
				visit[k][i][j] = 100000000;//거울 개수 최대로 설정
		}
	}
	bfs();
	int ans = 100000000;
	for (int i = 0; i < 4; i++) {
		if (visit[i][finish.x][finish.y] < ans)
			ans = visit[i][finish.x][finish.y];
	}
	printf("%d", ans);
	return 0;
}
