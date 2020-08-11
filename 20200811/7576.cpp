#include <cstdio>
#include <queue>
using namespace std;
int m, n;
int graph[1001][1001];
bool visit[1001][1001];
typedef struct {
	int x, y;
}Point;
queue<Point> q;
int day;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool flag;
bool range(Point p) {
	if (p.x >= 1 && p.x <= m && p.y >= 1 && p.y <= n)
		return true;
	else
		return false;
}
void bfs() {
	Point next;
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			Point cur = q.front(); q.pop();
			
			for (int i = 0; i < 4; i++) {
				next.x = cur.x + dx[i];
				next.y = cur.y + dy[i];

				if (range(next) && !visit[next.y][next.x] && graph[next.y][next.x] == 0) {
					graph[next.y][next.x] = 1;
					visit[next.y][next.x] = true;
					q.push(next);
				}

			}
		}
		day++;
	}
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 0)
				flag = true;
		}
	}

	if (flag) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (graph[i][j] == 1) {
					q.push({ j,i });
				}
			}
		}
		bfs();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (graph[i][j] == 0) {
					printf("-1");
					return 0;
				}
			}
		}
		printf("%d", --day);
	}
	else {
		// 처음부터 다 익어있는 경우
		printf("0");
	}	
	return 0;
}
