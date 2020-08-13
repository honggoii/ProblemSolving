#include <cstdio>
#include <queue>
using namespace std;
int r, c;
char graph[251][251];
bool visit[251][251];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int a, b;//양, 늑대
int ans[2];//최종 양, 늑대
typedef struct{
	int x,y;
} Point;
queue<Point> q;
bool range(Point next) {
	return (next.x >= 1 && next.x <= c) && (next.y >= 1 && next.y <= r);
}
void bfs(Point p) {
	Point next;
	visit[p.y][p.x] = true;
	q.push(p);
	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		if (graph[cur.y][cur.x] == 'o')
			a++;
		if (graph[cur.y][cur.x] == 'v')
			b++;
		for (int i = 0; i < 4; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && !visit[next.y][next.x] && graph[next.y][next.x] != '#') {
				visit[next.y][next.x] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %1c", &graph[i][j]);
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (!visit[i][j] && graph[i][j] != '#') {
				a = 0; //양 초기화
				b = 0; //늑대 초기화
				bfs({ j,i });
				if (a <= b) {
					//ans[0] += 0;
					ans[1] += b;
				}
				else {
					ans[0] += a;
				}
			}				
		}
	}
	printf("%d %d", ans[0], ans[1]);
	return 0;
}
