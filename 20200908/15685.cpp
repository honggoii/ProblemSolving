#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int visit[200][200];
int n;//드래곤 커브 개수
int ans;//정사각형 개수
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
void check() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (visit[i][j] && visit[i + 1][j]
				&& visit[i][j + 1] && visit[i + 1][j + 1])
				ans++;
		}
	}
}
int main() {
	scanf("%d", &n);
	while (n--) {
		int x, y, d, g;
		scanf("%d%d%d%d", &y, &x, &d, &g);
		v.clear();
		visit[x][y] = true;
		x = x + dx[d];//진행
		y = y + dy[d];//진행
		visit[x][y] = true;
		v.push_back(d);

		//1세대 이후로
		for (int i = 1; i <= g; i++) {
			int sz = v.size();
			for (int j = sz - 1; j >= 0; j--) {
				int nd = (v[j] + 1) % 4;
				x = x + dx[nd];
				y = y + dy[nd];
				visit[x][y] = true;
				v.push_back(nd);
			}
		}
	}
	check();//정사각형 체크
	printf("%d", ans);
	return 0;
}
