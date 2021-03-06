#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
int n, l, r;
int map[60][60];
bool visit[60][60];
typedef struct {
	int x, y;
} Point;
pair<int, int> people;//(인구 수, 칸 수)
queue<Point> q;
queue<Point> tmp;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool range(Point next) {
	return next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= n;
}
int ans;
void peoplemove() {
	int num = people.first / people.second;

	while (!tmp.empty()) {
		Point cur = tmp.front(); tmp.pop();
		map[cur.x][cur.y] = num;
	}
}
void check(Point p) {
	q.push(p);
	tmp.push(p);
	visit[p.x][p.y] = true;
	people.first = map[p.x][p.y];
	people.second++;

	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		Point next;

		for (int i = 0; i < 4; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			int diff = abs(map[cur.x][cur.y] - map[next.x][next.y]);
			if (range(next) && ((l <= diff) && (diff <= r)) && !visit[next.x][next.y]) {
				visit[next.x][next.y] = true;
				q.push(next);
				tmp.push(next);

				people.first += map[next.x][next.y];
				people.second++;
			}
		}
	}
}
void drawmap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
void initvisit() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[i][j] = false;
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &l, &r);
	drawmap();//맵 입력
	while (1) {
		bool flag = false;
		initvisit();//초기화
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int tmpl = 0;
				int tmpd = 0;
				people.first = 0;
				people.second = 0;
				
				while (!tmp.empty())
					tmp.pop();
				
				if (i != n)
					tmpd = abs(map[i][j] - map[i + 1][j]);
				if (j != n)
					tmpl = abs(map[i][j] - map[i][j + 1]);

				if ((!visit[i][j]) && ((l <= tmpl && tmpl <= r) || (l <= tmpd && tmpd <= r))) {
					check({ i,j });//인구 차이 l명~r명 확인
					if (people.second > 1) {
						flag = true;
						peoplemove();//인구이동
					}
						
				}
			}
		}	

		if (!flag)
			break;//인구이동이 일어나지 않음
		ans++;
	}
	printf("%d", ans);
	return 0;
}
