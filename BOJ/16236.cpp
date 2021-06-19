#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n;
int map[21][21];
bool visit[21][21];
class com {
	public:	bool operator() (const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b) {
		if (a.second == b.second) {
			// 최단 거리이면
			if (a.first.first == b.first.first)
				return a.first.second > b.first.second;//y좌표가 같으면 x좌표 비교
			else
				return a.first.first > b.first.first;
		}			
		else
			return a.second > b.second;//최단 거리순으로
	}
};
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, com> pq;
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, com> eat;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int time;//최종 값
int cnt;//아기상어가 먹은 물고기 수
int sz = 2;//아기상어 초기 크기
bool range(int nx, int ny) {
	return nx >= 1 && nx <= n && ny >= 1 && ny <= n;
}
void initVisit() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[i][j] = false;
		}
	}
}
void bfs() {
	while (1) {
		initVisit();
		visit[pq.top().first.first][pq.top().first.second] = true;
		// 지나갈 수 있는 경우 체크
		while (!pq.empty()) {
			int cury = pq.top().first.first;
			int curx = pq.top().first.second;
			int dist = pq.top().second;
			pq.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cury + dy[i];
				int nx = curx + dx[i];

				if (range(ny, nx) && !visit[ny][nx] && map[ny][nx] <= sz) {
					visit[ny][nx] = true;
					pq.push({ {ny, nx} , dist + 1 });
					//아기상어가 먹을 수 있는 경우
					if (map[ny][nx] < sz && map[ny][nx] != 0) {
						eat.push({ { ny, nx }, dist + 1 });
					}
				}
			}
		}

		if (eat.empty())
			break;//엄마 상어 요청

		int y = eat.top().first.first;
		int x = eat.top().first.second;
		time += eat.top().second;
		map[y][x] = 0;
		pq.push({ { y, x }, 0 });//아기상어 이동
		while (!eat.empty())
			eat.pop();
		cnt++;
		if (cnt == sz) {
			cnt = 0;//먹은 물고기 초기화
			sz++;//크기 증가
		}
		
	}

}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 9) {
				// 아기상어 초기 위치
				pq.push({ { i,j }, 0 });
				map[i][j] = 0;
			}
		}
	}
	bfs();
	printf("%d", time);
}
