#include <cstdio>
#include <vector>
using namespace std;
int n, m;
int map[501][501];
int block[20][4][2]{
	{{0,0},{0,1},{0,2},{0,3}},
	{{0,0},{1,0},{2,0},{3,0}},
	{{0,0},{1,0},{0,1},{1,1}},
	{{0,0},{1,0}, {2,0}, {2,1}},
	{{0,0},{0,1}, {0,2}, {1,0}},
	{{0,0},{0,1}, {1,1}, {2,1}},
	{{0,0},{1,0}, {1,-1}, {1,-2}},
	{{0,0},{0,1}, {1,0}, {2,0}},
	{{0,0},{0,1}, {0,2}, {1,2}},
	{{0,0},{0,1}, {-1,1}, {-2,1}},
	{{0,0},{1,0}, {1,1}, {1,2}},
	{{0,0},{0,1}, {-1,1}, {0,2}},
	{{0,0},{0,1}, {1,1}, {0,2}},
	{{0,0},{0,1}, {-1,1}, {1,1}},
	{{0,0},{1,0}, {1,1}, {2,0}},
	{{0,0},{1,0}, {1,1}, {2,1}},
	{{0,0},{1,0}, {1,-1}, {2,-1}},
	{{0,0},{0,1}, {-1,1}, {-1,2}},
	{{0,0},{0,1}, {1,1}, {1,2}},
};
bool visit[501][501];
int ans;
typedef struct {
	int x, y;
}Point;
bool range(Point next) {
	return next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m;
}
int putBlock(int idx) {
	int res = 0;
	int sum;
	Point next;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum = 0;
			vector<int> v;
			for (int k = 0; k < 4; k++) {
				next.x = i + block[idx][k][0];
				next.y = j + block[idx][k][1];

				if (!range(next)) {
					break;//범위 벗어난 경우
				}

				v.push_back(map[next.x][next.y]);
			}	
			if (v.size() == 4) {
				for (int i = 0; i < v.size(); i++)
					sum += v[i];
				if (res < sum)
					res = sum;
			}
		}
	}
	return res;
}
void check() {
	for (int i = 0; i < 19; i++) {
		int res = putBlock(i);//맵에 다 놓아서 최대값 구하기
		if (ans < res)
			ans = res;
	}	
}
void makeMap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	makeMap();//맵 그리기
	check();
	printf("%d", ans);
	return 0;
}
