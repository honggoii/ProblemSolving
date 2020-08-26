#include <cstdio>
#include <deque>
using namespace std;
int h, w;//행 열
typedef struct {
	int x, y;
} Point;
Point one;//첫번째 죄수
Point two;//두번재 죄수
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
char map[105][105];
int visit[3][105][105];//[누군지][x좌표][y좌표]
int ans;
deque<Point> dq;
bool range(Point next) {
	return next.x >= 0 && next.x <= (h + 1) && next.y >= 0 && next.y <= (w + 1);
}
void sum() {
	for (int i = 0; i <= (h + 1); i++) {
		for (int j = 0; j <= (w + 1); j++) {
			if (map[i][j] == '*')
				continue;

			visit[0][i][j] += visit[1][i][j] + visit[2][i][j];
			if (map[i][j] == '#')
				visit[0][i][j] -= 2;

			if (visit[0][i][j] < ans)
				ans = visit[0][i][j];
		}
	}
}
void bfs(int idx, Point p) {

	dq.push_back(p);
	visit[idx][p.x][p.y] = 0;

	while (!dq.empty()) {
		Point cur = dq.front(); dq.pop_front();
		for (int i = 0; i < 4; i++) {
			Point next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && map[next.x][next.y] != '*'
				&& visit[idx][next.x][next.y] == -1) {
				if (map[next.x][next.y] == '#') {
					//문이면
					visit[idx][next.x][next.y] = visit[idx][cur.x][cur.y] + 1;
					dq.push_back(next);
				}
				else if (map[next.x][next.y] == '.') {
					visit[idx][next.x][next.y] = visit[idx][cur.x][cur.y];
					dq.push_front(next);
				}

			}
		}
	}
}
void visitInit() {
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i <= (h + 1); i++) {
			for (int j = 0; j <= (w + 1); j++) {
				visit[k][i][j] = -1;
			}
		}
	}
}
int main() {
	int tc;
	scanf("%d", &tc);//testcase
	while (tc--) {
		scanf("%d%d", &h, &w);//행 열
		visitInit();//visit초기화
		ans = 100000000;
		int cnt = 0;
		for (int i = 0; i <= (h + 1); i++) {
			for (int j = 0; j <= (w + 1); j++) {
				if (i == 0 || j == 0 || i == (h + 1) || j == (w + 1)) {
					map[i][j] = '.';
					continue;
				}
				scanf(" %1c", &map[i][j]);
				if ((cnt == 0) && map[i][j] == '$') {
					//첫번째 죄수
					one.x = i;
					one.y = j;
					cnt++;
					map[i][j] = '.';
				}
				else if ((cnt == 1) && map[i][j] == '$') {
					//두번째 죄수
					two.x = i;
					two.y = j;
					map[i][j] = '.';
				}
			}
		}
		bfs(0, { 0,0 });//상근이
		bfs(1, one);//첫번째 죄수
		bfs(2, two);//두번째 죄수
		sum();//더해주기
		printf("%d\n", ans);
	}
	return 0;
}
