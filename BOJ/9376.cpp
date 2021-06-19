#include <cstdio>
#include <queue>
using namespace std;
typedef struct {
	int x, y;
} Point;
deque<Point> dq;
char map[110][110];
int visit[3][110][110];//[사람][행][열]
int h, w;
int ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool range(Point next) {
	return next.x >= 0 && next.x <= (h + 1) && next.y >= 0 && next.y <= (w + 1);
}
void sum() {
	for (int i = 0; i <= (h + 1); i++) {
		for (int j = 0; j <= (w + 1); j++) {
			if (map[i][j] == '*')
				continue;
			visit[0][i][j] += (visit[1][i][j] + visit[2][i][j]);
			if (map[i][j] == '#')
				visit[0][i][j] -= 2;
			if (visit[0][i][j] < 0)
				continue;
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
		Point next;
		for (int i = 0; i < 4; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && visit[idx][next.x][next.y] == -1 && map[next.x][next.y] != '*') {
				if (map[next.x][next.y] == '#') {
					//문이면 나중에 탐색
					visit[idx][next.x][next.y] = visit[idx][cur.x][cur.y] + 1;
					dq.push_back(next);
				}
				else if (map[next.x][next.y] == '.') {
					//빈 공간이면 먼저 탐색
					visit[idx][next.x][next.y] = visit[idx][cur.x][cur.y];
					dq.push_front(next);
				}
			}
		}
	}
}
void initVisit() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 110; j++) {
			for (int k = 0; k < 110; k++) {
				visit[i][j][k] = -1;
			}
		}
	}
}
void initMap() {
	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
			map[i][j] = ' ';
		}
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		initMap();//map초기화
		initVisit();//visit초기화
		ans = 1e9;
		scanf("%d%d", &h, &w);
		int cnt = 1;
		Point one;//죄수 1번
		Point two;//죄수 2번
		//맵 입력+맵 확장
		for (int i = 0; i <= (h+1); i++) {
			for (int j = 0; j <= (w+1); j++) {
				if (i == 0 || j == 0 || i == (h + 1) || j == (w + 1))
					map[i][j] = '.';
				else {
					scanf(" %1c", &map[i][j]);
					if (map[i][j] == '$') {
						if (cnt == 1) {
							//죄수 1번
							one.x = i;
							one.y = j;
							cnt++;
							map[i][j] = '.';
						}
						else {
							//죄수 2번
							two.x = i;
							two.y = j;
							map[i][j] = '.';
						}
					}
				}					
			} 
		}
		bfs(0, { 0,0 });//상근이 bfs
		bfs(1, one);//죄수1 bfs
		bfs(2, two);//죄수2 bfs
		sum();//정답 구하기
		printf("%d\n", ans);
	}
	return 0;
}
