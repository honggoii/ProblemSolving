#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef struct {
	int x, y;
}Point;
vector<Point> virus;//바이러스 초기 위치
vector<Point> blank;//빈 칸 위치
queue<Point> q;
int n, m;
int map[10][10];
bool visit[10][10];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans;
int safezon() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}
bool range(Point next) {
	return next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m;
}
void bfs() {
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		visit[virus[i].x][virus[i].y] = true;
	}
	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			Point next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && !visit[next.x][next.y] && map[next.x][next.y] == 0) {
				visit[next.x][next.y] = true;
				map[next.x][next.y] = 2;
				q.push(next);
			}
		}
	}
}
void Combination(int idx, int cnt) {
	
	if (cnt == 3) {
		//3개 뽑았으면
		memset(visit, false, sizeof(visit));
		bfs();//바이러스 퍼트리기
		int cnt = safezon();//안전영역 개수 세기
		//최대값이랑 비교
		if (ans < cnt)
			ans = cnt;
		return;
	}
	
	int origin[10][10];//바이러스 퍼트리기전 맵 저장
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			origin[i][j] = map[i][j];
		}
	}


	//3개뽑으러
	for (int i = idx; i < blank.size(); i++) {
		if (map[blank[i].x][blank[i].y] == 1) continue;//벽 세웠으면 통과
		map[blank[i].x][blank[i].y] = 1;//벽 세우기
		Combination(idx, cnt + 1);
		map[blank[i].x][blank[i].y] = 0;//세운 벽 허물기
		//바이러스 퍼트리기 전 맵 복원
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				map[i][j] = origin[i][j];
			}
		}
	}
}
void initMap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				//빈 칸 좌표 넣기
				blank.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				//바이러스 좌표 넣기 
				virus.push_back({ i,j });
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	initMap();//맵 입력
	Combination(0, 0);//총 빈 칸 개수에서 3개 뽑기
	printf("%d", ans);
	return 0;
}
