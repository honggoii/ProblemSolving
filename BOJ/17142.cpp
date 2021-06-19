#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int map[51][51];
pair<bool, int> tmpmap[51][51];
int visit[51][51];
typedef struct {
	int y, x;
} Point;
vector<pair<int, Point>> v; // 바이러스 {번호, 위치}
queue<Point> q;
bool virus[12];
int ans = 1e9;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
bool nosearch = true;
int blank;
int check() {
	int time = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] != 1e9 && visit[i][j] > time) {
				if (map[i][j] == 2)
					time = visit[i][j] - 1;
				else
					time = visit[i][j];
			}	
			if (tmpmap[i][j].second == 0) {
				// 바이러스가 다 퍼지지 않음
				return -1;
			}
		}
	}
	return time;
}
bool range(int nx, int ny) {
	return nx >= 1 && nx <= n && ny >= 1 && ny <= n;
}
void bfs(int blank) {
	int cnt = blank;
	while (!q.empty()) {
		if (cnt == 0)
			return;
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (range(nx, ny)) {
				if (tmpmap[ny][nx].second == 0) {
					// 빈 칸이면
					cnt--;
					tmpmap[ny][nx].second = 2;
					tmpmap[ny][nx].first = true;
					if (visit[ny][nx] > visit[y][x] + 1)
						visit[ny][nx] = visit[y][x] + 1;
					q.push({ ny, nx });
				}
				else if (tmpmap[ny][nx].second == 2 && tmpmap[ny][nx].first == false) {
					// 비활성 바이러스면
					visit[ny][nx] = visit[y][x] + 1;
					tmpmap[ny][nx].first = true;
					q.push({ ny, nx });
				}
			}
		}
	}
}
void copymap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tmpmap[i][j].second = map[i][j];
			tmpmap[i][j].first = false;
			visit[i][j] = 1e9; // visit 초기화
		}
	}
}
void comb(int idx, int cnt) {
	if (cnt == m) {
		// m개 뽑았으면
		copymap();// tmpmap <- 원본 map 복사
		for (int i = 0; i < v.size(); i++) {
			if (virus[v[i].first]) {
				// 활성 바이러스만
				q.push({ v[i].second.y,v[i].second.x });
				tmpmap[v[i].second.y][v[i].second.x].first = true;
				visit[v[i].second.y][v[i].second.x] = 0;
			}
		}		
		bfs(blank);// tmpmap에 바이러스 퍼뜨리기 (bfs)
		while (!q.empty())
			q.pop();
		int time = check();// 최소값 찾기
		if (time != -1) {
			if (time < ans)
				ans = time;
		}		
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (virus[v[i].first]) continue; // 뽑혔으면
		virus[v[i].first] = true;
		comb(i, cnt+1);
		virus[v[i].first] = false;
	}
}
void init() {
	int num = 0; // 바이러스 번호
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &map[i][j]);
			if (map[i][j] == 2) {
				v.push_back({ num++, { i,j } }); // 바이러스 위치
			}				
			else if (map[i][j] == 0) {
				nosearch = false;
				blank++;
			}				
		}
	}
}
int main() {
	// 0: 빈칸 1: 벽 2: 바이러스
	scanf("%d%d", &n, &m);
	
	init();// 맵 입력
	if (nosearch) {
		printf("0"); // 처음부터 맵에 바이러스가 다 퍼져있는경우
	}
	else {
		comb(0, 0); // 전체 바이러스 중 m개 뽑기(조합)

		if (ans != 1e9)
			printf("%d", ans);
		else
			printf("-1");
	}
	
	return 0;
}
