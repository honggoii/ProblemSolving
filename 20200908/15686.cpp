#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n, m;//맵 크키, 치킨집 개수
typedef struct {
	int x, y;
} Point;
vector<Point> h;//집 좌표
vector<Point> c;//치킨 집 좌표
int map[60][60];
int visit[60][60];
int ans = 1e9;
void distance() {
	int temp;
	int cnt;
	int cnt2 = 0;
	for (int i = 0; i < h.size(); i++) {
		temp = 0;
		cnt = 1e9;
		for (int j = 0; j < c.size(); j++) {
			if (visit[c[j].x][c[j].y]) {
				temp = abs(c[j].x - h[i].x) + abs(c[j].y - h[i].y);
				if (temp < cnt)
					cnt = temp;
			}
		}
		cnt2 += cnt;
	}
	if (cnt2 < ans)
		ans = cnt2;
}
void comb(int idx, int cnt) {
	if (cnt > m)
		return;

	if(cnt != 0)
		distance();//거리 세주기

	for (int i = idx; i < c.size(); i++) {
		if (visit[c[i].x][c[i].y]) continue;
		visit[c[i].x][c[i].y] = true;
		comb(i, cnt + 1);
		visit[c[i].x][c[i].y] = false;
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				h.push_back({ i,j });
			else if (map[i][j] == 2)
				c.push_back({ i,j });
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	init();//초기화
	comb(0, 0);//조합
	printf("%d", ans);
	return 0;
}
