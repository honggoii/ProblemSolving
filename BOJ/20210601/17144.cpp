#include <cstdio>
int map[51][51];
int diffmap[51][51];//확산 후 map
int r, c, t;
int ans;
typedef struct {
	int x, y;
} Point;
Point cw, ccw; // 시계방향, 반시계방향
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
bool range(int ny, int nx) {
	return ny >= 1 && ny <= r && nx >= 1 && nx <= c;
}
void dwind() {
	// 위로
	for (int i = cw.x + 2; i <= r; i++) {
		map[i - 1][1] = map[i][1];
	}
	// 왼쪽으로
	for (int j = 2; j <= c; j++) {
		map[r][j - 1] = map[r][j];
	}
	// 아래로
	for (int i = r + 1; i > cw.x; i--) {
		map[i][c] = map[i - 1][c];
	}
	// 오른쪽으로
	for (int j = c+1; j > 2; j--) {
		map[cw.x][j] = map[cw.x][j-1];
	}		
	map[cw.x][cw.y + 1] = 0;
}
void uwind() {
	// 아래로
	for (int i = ccw.x - 2; i >= 1; i--) {
		map[i+1][1] = map[i][1];
	}
	// 왼쪽으로
	for (int j = 2; j <= c; j++) {
		map[1][j-1] = map[1][j];
	}
	// 위로
	for (int i = 2; i <= ccw.x; i++) {
		map[i-1][c] = map[i][c];
	}
	// 오른쪽으로
	for (int j = c-1; j >= 2; j--) {
		map[ccw.x][j+1] = map[ccw.x][j];
	}
	map[ccw.x][ccw.y + 1] = 0;
}
void remap() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			map[i][j] += diffmap[i][j];
		}
	}
}
void diffusion() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (range(ny, nx) && map[ny][nx] != -1) {
					diffmap[ny][nx] += (map[i][j] / 5);
					cnt++;
				}
			}
			map[i][j] -= ((map[i][j] / 5) * cnt);
		}
	}
}
void init() {
	bool flag = true;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				// 공기청정기 자리
				if (flag) {
					ccw = { i,j };
					flag = false;
				}
				else {
					cw = { i,j };
				}
			}
		}
	}
}
void check() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == -1)
				continue; // 공기청정기 자리
			ans += map[i][j];
		}
	}
}
void initdiffmap() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			diffmap[i][j] = 0;
		}
	}
}
int main() {
	scanf("%d%d%d", &r, &c, &t);
	init();
	while (t--) {
		initdiffmap();// 확산맵 초기화
		diffusion();// 확산
		remap();// 확산 후 남은 양
		uwind();// 위바람
		dwind();// 아래바람
	}
	check();
	printf("%d", ans);
	return 0;
}
