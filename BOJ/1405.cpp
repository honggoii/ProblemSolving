#include <cstdio>
int n;
double percent[4];
double tmp[20];
double ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[100][100];
bool visit[100][100];
void permutation(int x, int y, int cnt, double p) {
	if (cnt == n) {
		ans += p;
		return;
	}

	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visit[nx][ny]) {
			if (percent[i] == 0)
				continue;
			p *= percent[i];
			permutation(nx, ny, cnt + 1, p);
			p /= percent[i];
			visit[nx][ny] = false;
		}		
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		scanf("%lf", &percent[i]);
		percent[i] /= 100;//백분율
	}
	permutation(50, 50, 0, 1.0);
	printf("%.10f", ans);
	
	return 0;
}
