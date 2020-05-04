#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int graph[26][26];
bool visit[26][26];
int k;
int cnt[1001]; // 단지 내 가구
int block; // 단지 수
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

typedef struct {
	int x, y;
} point;

void dfs(point p) {
	visit[p.y][p.x] = true;
	point next;

	for (int i = 0; i < 4; i++) {
		next.y = p.y + dy[i];
		next.x = p.x + dx[i];

		if (!visit[next.y][next.x] && graph[next.y][next.x] == 1 &&
			next.y >= 0 && next.y <= n && next.x>=0 && next.x <= n) {
			cnt[k]++;
			dfs(next);
		}			
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &graph[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1 && !visit[i][j]) {
				cnt[k]++;
				dfs({ j,i });
				k++;
				block++;
				sort(cnt, cnt + k);
			}				
		}
	}		

	printf("%d\n", block);
	

	for (int i = 0; i < 1001; i++) {
		if (cnt[i] == 0) continue;
		printf("%d\n", cnt[i]);
	}	

	return 0;
}