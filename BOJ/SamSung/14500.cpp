#include <cstdio>
int n, m;
int map[501][501];
int block[20][4][2]{
	{{0,0},{0,1}, {0,2},{0,3}},
	{{0,0},{1,0}, {2,0},{3,0}},
	{{0,0},{0,1}, {1,0},{1,1}},
	{{0,0},{1,0}, {2,0},{2,1}},
	{{0,0},{0,1}, {0,2},{1,0}},
	{{0,0},{0,1}, {1,1},{2,1}},
	{{0,2},{1,0}, {1,1},{1,2}},
	{{2,0},{0,1}, {1,1},{2,1}},
	{{0,0},{0,1}, {0,2},{1,2}},
	{{0,0},{1,0}, {2,0},{0,1}},
	{{0,0},{1,0}, {1,1},{1,2}},
	{{0,0},{1,0}, {1,1},{2,1}},
	{{1,0},{1,1}, {0,1},{0,2}},
	{{0,1},{1,1}, {1,0},{2,0}},
	{{0,0},{0,1}, {1,1},{1,2}},
	{{0,0},{0,1}, {0,2},{1,1}},
	{{1,0},{0,1}, {1,1},{2,1}},
	{{0,1},{1,0}, {1,1},{1,2}},
	{{0,0},{1,0}, {2,0},{1,1}}
};
int ans;
bool range(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
void tetromino(int idx) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = 0;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = block[idx][k][0] + i;
				int ny = block[idx][k][1] + j;

				if (range(nx, ny)) {
					cnt++;
					tmp += map[nx][ny];
				}					
			}
			
			if (cnt == 4) {
				if (tmp > ans)
					ans = tmp;
			}			
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	for (int i = 0; i < 19; i++) {
		tetromino(i);
	}	
	
	printf("%d", ans);
	
	return 0;
}