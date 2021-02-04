#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int r, c;
char map[1100][1100];
char tmp[1100][1100];
int fireTime[1100][1100];//불이 퍼지는 시간
int jihunTime[1100][1100];//지훈이가 가는 시간
typedef struct {
	int x, y;
} Point;
Point jihun;
Point fire;
queue<Point> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans;
bool range(Point next) {
	return next.x >= 1 && next.x <= r && next.y >= 0 && next.y <= c;
}
int bfs(Point p) {
	jihunTime[p.x][p.y] = 1;
	q.push(p);
	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		Point next;
		for (int i = 0; i < 4; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && jihunTime[next.x][next.y] == 0 && (map[next.x][next.y] == '.'
				|| map[next.x][next.y] == 'J')) {
				jihunTime[next.x][next.y] = jihunTime[cur.x][cur.y] + 1;
				if (fireTime[next.x][next.y]==0 || jihunTime[next.x][next.y] <= fireTime[next.x][next.y]) {
					//지훈이가 갈 수 있으면
					q.push(next);

					if (next.x == 1 || next.x == r || next.y == 1 || next.y == c) {
						return jihunTime[next.x][next.y];
					}
				}


			}

		}
	}
	return 0;
}
void bfsFire() {
	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		Point next;
		for (int i = 0; i < 4; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && fireTime[next.x][next.y] == 0 && (map[next.x][next.y] == '.'
				|| map[next.x][next.y] == 'J')) {
				fireTime[next.x][next.y] = fireTime[cur.x][cur.y] + 1;
				q.push(next);
			}

		}
	}
}
void mapinit() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}
void init() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %1c", &map[i][j]);
			tmp[i][j] = map[i][j];//맵 복사
			if (map[i][j] == 'J') {
				jihun.x = i;
				jihun.y = j;
			}
			else if (map[i][j] == 'F') {
				q.push({ i,j });
				fireTime[i][j] = 0;
			}
		}
	}
}
int main() {
	scanf("%d%d", &r, &c);

	init();
	if (!q.empty()) {
		//불이 있는경우만 계산
		bfsFire();//불 퍼트리기
	}
	while (!q.empty())
		q.pop();
	if (jihun.x == 1 || jihun.x == r || jihun.y == 1 || jihun.y == c) {
		ans = 1;
	}
	else {
		ans = bfs(jihun);
	}

	if (ans != 0)
		printf("%d", ans);
	else
		printf("IMPOSSIBLE");

	return 0;
}
