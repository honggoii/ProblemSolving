#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, k;
int map[110][110];
bool visit[110][110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef struct {
	int x;
	int y;
} Point;
queue<Point> q;
int ans;
vector<int> area;
int cnt;
bool range(Point next) {
	return next.x >= 0 && next.x < m&& next.y >= 0 && next.y < n;
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

			if (range(next) && !visit[next.x][next.y] && map[next.x][next.y] == 0) {
				visit[next.x][next.y] = true;
				q.push(next);
				cnt++;
			}
		}
	}
}
void init() {
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for (int i = b; i < d; i++) {
			for (int j = a; j < c; j++) {
				map[i][j] = 1;//막힌 공간
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &m, &n, &k);
	init();//map init
	
	//bfs
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && !visit[i][j]) {
				ans++;
				cnt = 1;
				bfs({ i, j });
				area.push_back(cnt);
			}
		}
	}
	sort(area.begin(), area.end());
	printf("%d\n", ans);
	for (int i = 0; i < area.size(); i++)
		printf("%d ", area[i]);
	return 0;
}
