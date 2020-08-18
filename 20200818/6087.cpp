#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int w, h;//열, 행
char graph[101][101];
int visit[101][101];//해당 좌표의 거울 개수
typedef struct {
	int x, y;//좌표
	int dir;//방향
	int mir;//거울개수
} Point;
Point start;//레이저 시작 지점
Point finish;//레이저 끝 지점
queue<Point> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool range(Point next) {
	return next.x >= 1 && next.x <= h && next.y >= 1 && next.y <= w;
}
void bfs() {
	for (int i = 0; i < 4; i++) {
		q.push({ start.x,start.y,i,0 });//동서남북방향 다 넣기
	}
	visit[start.x][start.y] = 0;

	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			Point next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];		
			next.dir = cur.dir;
			next.mir = cur.mir;

			if (range(next) && graph[next.x][next.y] != '*') {
				//범위 내에 있고 벽이 아니면 이동 가능하다.
				//진행중인 방향이었는지 확인
				//진행중인 방향 == i
				if (cur.dir != i)
					next.mir = cur.mir + 1; //방향이 다르다면 거울 한개 증가
				if (next.mir <= visit[next.x][next.y]) {
					visit[next.x][next.y] = next.mir; //최소 개수
					q.push({ next.x,next.y,i,next.mir });
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &w, &h);//열, 행
	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf(" %1c", &graph[i][j]);
			if (graph[i][j] == 'C') {
				start.x = i;
				start.y = j;
				cnt++;
			}
			if (cnt == 1 && graph[i][j] == 'C') {
				finish.x = i;
				finish.y = j;
			}
			visit[i][j] = 100000000;//거울이 무수히 많이 필요하다고 가정
		}
	}
	bfs();
	printf("%d", visit[finish.x][finish.y]);
	return 0;
}
