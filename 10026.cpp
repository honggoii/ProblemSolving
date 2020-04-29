#include <cstdio>
#include <cstring>

char graph[101][101];
int visit[101][101];
int person[2];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n;

typedef struct {
	int x, y;
} point;

bool cor(point p) {
	return p.x >= 0 && p.x < n && p.y >= 0 && p.y < n;
}

void dfs(point p) {
	point next;
	visit[p.y][p.x] = true;

	for (int i = 0; i < 4; i++) {
		next.x = p.x + dx[i];
		next.y = p.y + dy[i];

		if (!visit[next.y][next.x] && graph[next.y][next.x] == graph[p.y][p.x]
			&& cor(next)) {
			dfs(next);
		}	
	}
}

int main() {
	freopen("sample.txt", "r", stdin);
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < n; j++) {
			scanf("%c", &graph[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j])continue;
			dfs({ j,i });
			person[0]++;
		}
	}

	
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[j][i] == 'R' ||graph[j][i] == 'G')
				graph[j][i] = 'R';
		}
	}	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j])continue;
			dfs({ j,i });
			person[1]++;
		}
	}

	printf("%d %d\n", person[0], person[1]);

	return 0;
}