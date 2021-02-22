#include <cstdio>
#include <queue>
using namespace std;
int h, w;
typedef struct {
	int x, y;
} Point;
queue<Point> q;
int ans;
int map[1001][1001];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
bool range(Point nxt) {
	return nxt.x >= 0 && nxt.x < h&& nxt.y >= 0 && nxt.y < w;
}
void bfs() {
	while (1) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			Point cur = q.front(); q.pop();
			Point nxt;
			
			for (int j = 0; j < 8; j++) {
				nxt.x = cur.x + dx[j];
				nxt.y = cur.y + dy[j];

				if (range(nxt) && map[nxt.x][nxt.y] > 0) {
					map[nxt.x][nxt.y]--;//모래깍고

					if (map[nxt.x][nxt.y] == 0) {
						q.push(nxt);
					}
				}
			}
		}
		if (q.empty())
			break;
		ans++;
	}
}
int main() {
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c;
			scanf(" %1c", &c);
			if (c == '.') {
				q.push({ i,j });
				map[i][j] = 0;//모래가 없음
			}
			else {
				map[i][j] = c - '0';//char를 int로 변환
			}
		}
	}
	bfs();
	printf("%d", ans);
	return 0;
}
