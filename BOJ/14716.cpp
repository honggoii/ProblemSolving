#include <cstdio>
int m, n;
int map[260][260];
bool visit[260][260];
int ans;
typedef struct {
	int x, y;
} Point;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
bool range(Point nxt) {
	return nxt.x >= 0 && nxt.x < m&& nxt.y >= 0 && nxt.y < n;
}
void dfs(Point p) {
	visit[p.x][p.y] = true;
	Point nxt;
	for (int i = 0; i < 8; i++) {
		nxt.x = p.x + dx[i];
		nxt.y = p.y + dy[i];

		if (range(nxt) && !visit[nxt.x][nxt.y] && map[nxt.x][nxt.y] == 1)
			dfs(nxt);
	}
}
void inputmap() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int main() {
	scanf("%d%d", &m, &n);
	inputmap();//맵 입력
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				ans++;
				dfs({ i,j });
			}
		}
	}
	printf("%d", ans);
	
	return 0;
}
