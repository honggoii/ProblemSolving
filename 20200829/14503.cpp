#include <cstdio>
int n, m;//행 열
int r, c, dir;//시작 좌표, 방향
int map[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ans;//닦은 구역
bool range(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
int rotate(int dir) {
	if (dir == 0)
		return 3;
	else if (dir == 3)
		return 2;
	else if (dir == 2)
		return 1;
	else if (dir == 1)
		return 0;
}
void clean() {
	map[r][c] = 2;//닦은 곳은 2
	ans++;//일단 닦고 시작
	
	int nr, nc, ndir;
	while (1) {
		int cnt = 0;//회전 횟수
		bool flag = false;//청소 플래그
		for (int i = 0; i < 4; i++) {//네 방향 탐색
			ndir = rotate(dir);//왼쪽으로 회전
			nr = r + dx[ndir];
			nc = c + dy[ndir];

			if (map[nr][nc] == 0) {
				//현재 방향에서 왼쪽이 청소 안됐으면 청소하러
				flag = true;
				break;
			}

			if (range(nr, nc) && map[nr][nc] != 0) {
				dir = ndir;
				cnt++;
			}
				
		}
		if (flag) {
			//청소
			map[nr][nc] = 2;
			ans++;//청소 횟수 증가
			dir = ndir;
		}
		
		if (cnt == 4) {
			//네방향 모두 청소했거나 벽이면 후진
			nr = r - dx[dir];
			nc = c - dy[dir];
			if (range(nr, nc) && map[nr][nc] == 1)
				return;
		}

		r = nr;
		c = nc;
	}
}
void initMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);//행 열
	scanf("%d%d%d", &r, &c, &dir);
	initMap();//맵 입력 받기
	clean();//청소 시작
	printf("%d", ans);
	return 0;
}
