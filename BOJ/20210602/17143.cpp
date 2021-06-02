#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
int R, C, M;
pair<pair<int, int>, pair<int, int>> map[110][110];// 속력, 방향, 크기, 번호
pair<pair<int, int>, pair<int, int>> tmpmap[110][110];// 속력, 방향, 크기, 번호
bool visit[100000];// 상어 관리
int dir[5][2] = { {0,0},{-1,0},{1,0},{0,1},{0,-1} };
int ans;
int change(int d) {
	if (d == 1) return 2;
	if (d == 2) return 1;
	if (d == 3) return 4;
	if (d == 4) return 3;
}
bool range(int nr, int nc) {
	return nr >= 1 && nr <= R && nc >= 1 && nc <= C;
}
void moveshark() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!visit[map[i][j].second.second] && map[i][j].second.first != 0) {
				int r = i;
				int c = j;
				int s = map[i][j].first.first; // 속력
				int tmp = s;
  				int d = map[i][j].first.second; // 방향
				int z = map[i][j].second.first; // 크기
				int num = map[i][j].second.second; // 상어 번호
				visit[num] = true;				
				map[i][j] = { {0,0},{0,0} };// 현재 상어 삭제

				int nr = 0;
				int nc = 0;
				while (tmp--) {
					nr = r + dir[d][0];
					nc = c + dir[d][1];

					if (!range(nr, nc)) {
						d = change(d);
					}

					r += dir[d][0];
					c += dir[d][1];
				}

				// 상어 경쟁
				if (tmpmap[r][c].second.first < z) {
					tmpmap[r][c] = { {s,d},{z,num} };
				}
				
			}
		}
	}
}
void catchshark(int col) {
	for (int i = 1; i <= R; i++) {
		if (map[i][col].second.first != 0) {
			ans += map[i][col].second.first;
			map[i][col] = { {0,0}, {0, 0} }; // 상어 잡음
			break;
		}
	}
}
void shark() {
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		scanf("%d%d%d%d%d", &r, &c, &s, &d, &z);
		if (d == 1 || d == 2) {
			s %= ((R - 1) * 2);
		}
		else if (d == 3 || d == 4) {
			s %= ((C - 1) * 2);
		}
		map[r][c] = { {s,d},{z,i} };
	}
}
void copymap() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j] = tmpmap[i][j];
		}
	}
}
void inittmpmap() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			tmpmap[i][j] = { {0,0},{0,0} };
		}
	}
}
int main() {
	scanf("%d%d%d", &R, &C, &M);
	shark();//상어 정보 입력
	for (int i = 1; i <= C; i++) {
		memset(visit, false, sizeof(visit));
		inittmpmap();
		catchshark(i);// 땅에서 가장 가까운 상어 잡기
		moveshark();// 상어 이동
		copymap();// 맵 복사
	}
	printf("%d", ans);
	return 0;
}
