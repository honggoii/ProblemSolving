#include <cstdio>
#include <queue>
using namespace std;
bool flag = true;
int m, n, h;
int map[101][101][101];//[높이][행][열]
int visit[101][101][101];
typedef struct {
	int z, x, y;
} Point;
queue<Point> q;
int day;
int dz[] = { -1,1,0,0,0,0 };
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { 0,0,0,0,-1,1 };
int ans;
bool range(Point next) {
	return next.z >= 1 && next.z <= h && next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m;
}
void bfs() {
	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		
		for (int i = 0; i < 6; i++) {
			Point next;
			next.z = cur.z + dz[i];
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && visit[next.z][next.x][next.y] == 0 && map[next.z][next.x][next.y] == 0) {
				ans = visit[next.z][next.x][next.y] = visit[cur.z][cur.x][cur.y] + 1;
				map[next.z][next.x][next.y] = 1;
				q.push(next);
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &m, &n, &h);
	for (int i = 1; i <= h; i++) {//높이
		for (int j = 1; j <= n; j++) {//행
			for (int k = 1; k <= m; k++) {//열
				scanf("%d", &map[i][j][k]);
				if (map[i][j][k] == 1) {
					q.push({ i,j,k });//토마토면 넣기
					visit[i][j][k] = 1;
				}
				else if (map[i][j][k] == 0) {
					//안 익은 토마토가 있으면
					flag = false;
				}
			}
		}
	}
	if (flag) {
		printf("0");//모든 토마토가 처음부터 익어 있는 상황
		return 0;
	}	
	else 
		bfs();	
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (map[i][j][k] == 0) {
					printf("-1");
					return 0;//모두 익지 못하는 상황
				}
			}
		}
	}
	printf("%d", ans - 1);//시작을 1일부터 했으니까 1일을 빼줘야한다.
	return 0;
}
