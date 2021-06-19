#include <cstdio>
#include <queue>
using namespace std;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int map[110][110];
bool visit[110][110];
int ans[110][110];
int n, m;//row, col
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool range(int nx, int ny) {
	return nx >= 1 && nx <= n && ny >= 1 && ny <= m;
}
void dikstra() {
	pq.push({ 0, {1,1} });

	while (!pq.empty()) {
		int curx = pq.top().second.first;
		int cury = pq.top().second.second;
		int w = pq.top().first;
		pq.pop();

		if (visit[curx][cury])
			continue;
		visit[curx][cury] = true;
		ans[curx][cury] = w;

		if (curx == n && cury == m)
			break;//탈출 조건

		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (range(nx, ny) && !visit[nx][ny]) {
				if (map[nx][ny] == 1) {
					//벽 부셔야하면
					pq.push({ ans[curx][cury] + 1, {nx, ny} });
				}
				else if (map[nx][ny] == 0) {
					//벽 안 부셔도 되면
					pq.push({ ans[curx][cury],{nx, ny} });
				}
			}
		}
	}
}
void inputmap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}
int main() {
	scanf("%d%d", &m, &n);
	inputmap();
	dikstra();
	printf("%d", ans[n][m]);
	return 0;
}
