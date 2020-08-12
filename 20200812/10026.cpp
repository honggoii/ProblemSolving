#include <cstdio>
#include <cstring>
using namespace std;
int n;
char graph[101][101];
bool visit[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef struct {
	int x, y;
} Point;
bool range(Point next) {
	if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= n)
		return true;
	else
		return false;
}
void dfs(Point p) {
	Point next;
	visit[p.y][p.x] = true;

	for (int i = 0; i < 4; i++) {
		next.y = p.y + dy[i];
		next.x = p.x + dx[i];

		if (range(next) && !visit[next.y][next.x]
			&& graph[p.y][p.x] == graph[next.y][next.x])
			dfs(next);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %1c", &graph[i][j]);
		}
	}
	
	//적록색약 아닌사람
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j]) {
				dfs({ j,i });
				cnt++;
			}
		}
	}
	printf("%d ", cnt);

	//적록색약인 사람
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 'G')
				graph[i][j] = 'R';
		}
	}
	memset(visit, 0, sizeof(visit));
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j]) {
				dfs({ j,i });
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
