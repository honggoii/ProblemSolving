#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
char map[13][7];
int visit[13][7];
typedef struct {
	int x, y;
} Point;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<Point> q;//임시 큐
queue<char> gravity;//중력받아 내려올 뿌요
queue<Point> pu;//터트릴 뿌요 담아놓는 큐
bool flag;
bool range(Point next) {
	return next.x >= 1 && next.x <= 6 && next.y >= 1 && next.y <= 12;
}
void bfs(Point p) {
	int cnt = 1;//같은 색 개수
	char color = map[p.y][p.x];
	visit[p.y][p.x] = true;
	q.push(p);
	pu.push(p);

	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			Point next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && !visit[next.y][next.x] && color == map[next.y][next.x]) {
				visit[next.y][next.x] = true;
				q.push(next);
				pu.push(next);
				cnt++;
			}
		}
	}

	while (!pu.empty()) {
		if (cnt >= 4) {
			map[pu.front().y][pu.front().x] = '.';
			flag = true;
		}
		pu.pop();
	}
}
void blowUp() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			if (range({ j,i }) && map[i][j] != '.' && !visit[i][j]) {
				bfs({ j,i });
			}
		}
	}	
}
void downPuyo() {
	for (int j = 1; j <= 6; j++) {
		for (int k = 12; k >= 1; k--) {
			if (map[k][j] != '.') {
				gravity.push(map[k][j]);
				map[k][j] = '.';
			}
		}
		int k = 12;
		while (!gravity.empty()) {
			map[k--][j] = gravity.front();
			gravity.pop();
		}
	}
}
int main() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}

	int ans = 0;//정답
	while (1) {
		memset(visit, false, sizeof(visit));//방문초기화
		flag = false;
		blowUp();//뿌요 터트리러
		if (!flag) break;
		downPuyo();//내리는 부분
		ans++;
	}
	printf("%d", ans);
	
	return 0;
}
