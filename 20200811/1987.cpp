#include <cstdio>
#include <cstring>
using namespace std;
typedef struct {
	int x, y;
} Point;
int r, c;
int graph[21][21];
bool visit[21][21];
bool alpha[26];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt = 1;
int ans;
bool range(Point p) {
	if (p.x >= 1 && p.x <= c && p.y >= 1 && p.y <= r)
		return true;
	else
		return false;
}
void dfs(Point p) {
	Point next;
	visit[p.y][p.x] = true;
	alpha[graph[p.y][p.x] - 65] = true;
	for (int i = 0; i < 4; i++) {
		next.y = p.y + dy[i];
		next.x = p.x + dx[i];

		if (range(next) && !visit[next.y][next.x]
			&& !alpha[graph[next.y][next.x] - 65]) {
			cnt++;
			dfs(next);
			alpha[graph[next.y][next.x] - 65] = false;
			visit[next.y][next.x] = false;
			/*if (ans < cnt)
				ans = cnt;*/
			cnt--;
		}
	}
	if (ans < cnt)
		ans = cnt;
}
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &graph[i][j]);
		}
	}
	if (r == 1 && c == 1)
		printf("1");
	else {
		dfs({ 1,1 });
		printf("%d", ans);
	}	
	return 0;
}
