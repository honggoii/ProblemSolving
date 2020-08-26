#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m;//크기, 놓을 바이러스
int map[51][51];//초기 map
vector<pair<int, int>> v;//바이러스 놓을 수 있는 좌표 저장
bool putVisit[11];//바이러스 놓았는 지 확인하는 배열
vector<pair<int, int>> virus;//바이러스 놓을 좌표
int temp[51][51];//바이러스를 놓을 임시 맵
int visit[51][51];//방문체크
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q;
int ans = 100000000;
int cnt1 = 0;
int cnt2 = 0;
bool range(int nx, int ny) {
	return nx >= 1 && nx <= n && ny >= 1 && ny <= n;
}
bool checkMap() {
	int num = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (temp[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}
int virusSpread() {
	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (range(nx, ny) && temp[nx][ny] == 0 && visit[nx][ny] == -1) {
				temp[nx][ny] = 2;
				q.push({ nx,ny });
				visit[nx][ny] = visit[x][y] + 1;
			}
		}
	}
	return visit[x][y];
}
void virusMap() {
	//바이러스 놓기
	for (int i = 0; i < virus.size(); i++) {
		temp[virus[i].first][virus[i].second] = 2;
		q.push({ virus[i].first, virus[i].second });
		visit[virus[i].first][virus[i].second] = 0;
	}
}
void visitInit() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (temp[i][j] == 1)//벽인 경우
				visit[i][j] = 0;
			else
				visit[i][j] = -1;			
		}
	}
}
void virusPut(int idx, int cnt) {
	if (cnt == m) {
		cnt1++;
		//바이러스를 다 놓았으면
		//맵 복사
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				temp[i][j] = map[i][j];
			}
		}
		visitInit();//visit초기화	
		virusMap();//바이러스 놓기
		int num = virusSpread();//바이러스 퍼트리기	
		bool flag = checkMap();
		if (flag) {
			if (num < ans)
				ans = num;
		}
		else {
			//바이러스를 못 퍼트리는 경우
			cnt2++;
		}
	}

	for (int i = idx; i < v.size(); i++) {
		if (putVisit[i])continue;
		putVisit[i] = true;
		virus.push_back({ v[i].first, v[i].second });
		virusPut(i, cnt + 1);
		virus.pop_back();
		putVisit[i] = false;
	}
}
void initMap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				//바이러스를 놓을 수 있는 공간이면 저장
				v.push_back(make_pair(i, j));
				map[i][j] = 0;//좌표 저장했으니 빈칸이라고 생각
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);//크기, 놓을 바이러스
	initMap();//초기 맵 입력
	virusPut(0, 0);//조합 사용해서 바이러스 놓기
	if (cnt1 == cnt2)
		printf("-1");
	else
		printf("%d", ans);
	return 0;
}
