#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int chess[301][301];
bool visit[301][301];
int l;
typedef struct {
	int x, y;
} Point;
queue<Point> q;
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { 1,-1,2,-2,2,-2,1,-1 };
bool range(Point next) {
	return next.x >= 0 && next.x < l&& next.y >= 0 && next.y < l;
}
void bfs(Point p) {
	Point next;
	q.push(p);
	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		for (int i = 0; i < 8; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && !visit[next.y][next.x]) {
				visit[next.y][next.x] = true;
				if (chess[next.y][next.x] == 1e9) {
					chess[next.y][next.x] = chess[cur.y][cur.x];
					return;
				}
				chess[next.y][next.x] = chess[cur.y][cur.x] + 1;
				q.push(next);
			}
		}		
	}	
}
int main() {
	int tc; //text case
	scanf("%d", &tc);
	while (tc--) {
		memset(chess, 0, sizeof(chess));
		memset(visit, 0, sizeof(visit));
		while (!q.empty())
			q.pop();
		scanf("%d", &l);
		int x, y;
		scanf("%d%d", &x, &y);
		chess[x][y] = 1;
		int endx, endy; //이동하려는 칸
		scanf("%d%d", &endx, &endy);
		chess[endx][endy] = 1e9;

		if (x == endx && y == endy) //시작부터 끝나는 경우
			printf("0\n");
		else {
			bfs({ y,x });
			printf("%d\n", chess[endx][endy]);
		}
	}
	return 0;
}
