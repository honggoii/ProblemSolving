#include <cstdio>
#include <algorithm>
using namespace std;
int graph[26][26];
bool visit[26][26];
int n;
int house[10000];
typedef struct {
	int x, y;
} Point;
int dx[] = { -1,1,0,0 };
int dy[]{ 0,0,-1,1 };
int k;
int cnt;
void dfs(Point p) {
	Point next;
	visit[p.y][p.x] = true;
	for (int i = 0; i < 4; i++) {
		next.y = p.y + dy[i];
		next.x = p.x + dx[i];
		if (!visit[next.y][next.x] && graph[next.y][next.x]
			&& (next.y >= 1 && next.y <= n && next.x >= 1 && next.x <= n)) {
			cnt++;
			dfs(next);
		}
	}
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j] && graph[i][j]) {
				cnt = 1;
				dfs({ j,i });
				house[k++] = cnt;
			}				
		}
	}

	sort(house, house + k, cmp);

	printf("%d\n", k);
	while (k--) {
		printf("%d\n", house[k]);
	}
	return 0;
}
