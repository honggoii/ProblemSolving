#include <cstdio>
#include <queue>
using namespace std;
int n;
int map[130][130];
bool visit[130][130];
int w[130][130];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef struct {
	int x, y;
} Point;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
bool range(Point next) {
	return next.x >= 0 && next.x < n&& next.y >= 0 && next.y < n;
}
void dijkstra() {
	pq.push({ map[0][0], {0,0} });
	while (!pq.empty()) {
		int weight = pq.top().first;
		Point cur;
		cur.x = pq.top().second.first;
		cur.y = pq.top().second.second;
		pq.pop();
		if (visit[cur.x][cur.y])
			continue;//

		visit[cur.x][cur.y] = true;//방문 체크, 거리 확정
		w[cur.x][cur.y] = weight;

		if (cur.x == n - 1 && cur.y == n - 1)
			break;//종료
		
		Point next;
		for (int i = 0; i < 4; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && !visit[next.x][next.y]) {
				pq.push({ w[cur.x][cur.y] + map[next.x][next.y], {next.x, next.y} });
			}
		}
	}
}
void drawmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
void initvisit() {
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			visit[i][j] = false;
		}
	}
}
void initmap() {
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			map[i][j] = 0;
		}
	}
}
int main() {
	int idx = 1;
	while (1) {
		while (!pq.empty())
			pq.pop();
		scanf("%d", &n);
		if (n == 0)
			break;
		initmap();//맵 초기화
		initvisit();//visit 초기화
		drawmap();//맵 입력
		dijkstra();
		printf("Problem %d: %d\n", idx++, w[n - 1][n - 1]);
	}	
	return 0;
}
