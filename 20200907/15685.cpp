#include <cstdio>
#include <vector>
using namespace std;
int n;//드래곤 커브 개수
int visit[101][101];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
vector<int> v;//진행 방향 push
int ans;//정답
int main() {
	scanf("%d", &n);//드래곤 커브 개수
	while (n--) {
		int x, y, d, g;//x, y, 방향, 세대
		scanf("%d%d%d%d", &y, &x, &d, &g);
		v.clear();
		
		visit[x][y] = 1;//시작점 체크
		x = x + dx[d];//진행
		y = y + dy[d];//진행
		visit[x][y] = 1;//0세대는 무조건
		v.push_back(d);

		//1세대 이후로 처리
		for (int i = 1; i <= g; i++) {
			//g세대까지 진행
			int sz = v.size();
			for (int j = sz - 1; j >= 0; j--) {
				int nd = (v[j] + 1) % 4;
				x = x + dx[nd];
				y = y + dy[nd];
				visit[x][y] = 1;

				v.push_back(nd);
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (visit[i][j] == 1 && visit[i][j + 1] == 1
				&& visit[i + 1][j] == 1 && visit[i + 1][j + 1] == 1) {
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
