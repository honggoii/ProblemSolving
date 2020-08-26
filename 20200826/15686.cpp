#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int map[51][51];
typedef struct {
	int x, y;
} Point;
Point house[3000];//집 좌표를 넣어두는 배열
Point chicken[14];//치킨집 좌표를 넣어두는 배열
bool visit[14];//치킨집 체크
vector<Point> v;//선택된 치킨집
int k = 0;//집 인덱스
int c = 0;//치킨집 인덱스
int sum;
int ans = 100000000;
int distance() {
	sum = 0;//총 거리
	for (int i = 0; i < k; i++) {
		int temp = 100000000;//무한 놓고
		for (int j = 0; j < v.size(); j++) {
			int dis = abs(house[i].x - v[j].x) + abs(house[i].y - v[j].y);//치킨집 거리
			if (dis < temp)
				temp = dis;
		}
		sum += temp;
	}
	return sum;
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		distance();
		if (sum < ans)
			ans = sum;
		return;
	}

	for (int i = idx; i < c; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		v.push_back(chicken[i]);
		dfs(i, cnt + 1);
		v.pop_back();
		visit[i] = false;
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				//집이면
				house[k].x = i;
				house[k].y = j;
				k++;
			}
			else if (map[i][j] == 2) {
				//치킨집이면
				chicken[c].x = i;
				chicken[c].y = j;
				c++;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	init();//맵 초기화
	dfs(0, 0);//치킨집 뽑기
	printf("%d", ans);
	return 0;
}
