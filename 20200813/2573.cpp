#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n, m;
int graph[301][301];
bool visit[301][301];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int age;//분리 최초 시간
int cnt;
typedef struct {
	int x,y;
} Point;
queue<Point> q;
bool range(Point p) {
	return (p.x >= 0 && p.x < m) && (p.y >= 0 && p.y < n);
}
void dfs(Point p) {
	Point next;
	visit[p.y][p.x] = true;

	for (int i = 0; i < 4; i++) {
		next.y = p.y + dy[i];
		next.x = p.x + dx[i];

		if (range(next) && graph[next.y][next.x] == 0
			&& graph[p.y][p.x] != 0 && !visit[next.y][next.x])
			graph[p.y][p.x]--;
	}

	for (int i = 0; i < 4; i++) {
		next.y = p.y + dy[i];
		next.x = p.x + dx[i];

		if (range(next) && !visit[next.y][next.x] &&
			graph[next.y][next.x] > 0)
			dfs(next);
	}
}
void bfs(Point p) {
	Point next;
	q.push(p);
	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			next.y = cur.y + dy[i];
			next.x = cur.x + dx[i];

			if (range(next) && graph[next.y][next.x] > 0
				&& !visit[next.y][next.x]) {
				visit[next.y][next.x] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	while (1) {
		cnt = 0;//빙산 개수
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && graph[i][j] > 0) {
					dfs({ j,i });
					cnt++;
				}
					
			}
		}
		if (cnt >= 2) //처음부터 빙산이 2개였으면 더이상 할 필요 없음
			break;
		cnt = 0; //빙산 다시 카운트
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && graph[i][j] > 0) {
					bfs({ j,i }); //빙산 개수 확인
					cnt++;
				}
			}
		}

		age++;//1년 추가
		if (cnt >= 2) { //덩어리가 2개가 넘으면
			printf("%d", age);
			return 0;
		}
		if (cnt == 0) //덩어리가 하나도 없으면
			break;
	}

	printf("0");

	return 0;
}
