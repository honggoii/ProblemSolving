#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int r, c;//행 열
int map[102][102];
int visit[102][102];
int n;//던진 횟수
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef struct {
	int x, y;
} Point;
queue<Point> q;
vector<int> v[102];
bool range(Point next) {
	return next.x >= 0 && next.x <= r && next.y >= 0 && next.y < c;
}
bool cmp(int a, int b) {
	return a > b;
}
void move() {
	//열 마다 정렬
	for (int i = 0; i < c; i++) {
		if (v[i].size() > 0) {
			sort(v[i].begin(), v[i].end(), cmp);
		}
	}
	//얼만큼 내려야 하는지
	int height = 1e9;//가장 최소 높이 찾기
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int res = 0;
			for (int k = v[i][j] + 1; k < r; k++) {
				if (map[k][i] == 'x' && visit[k][i] == 1)
					break;
				res++;//내릴 수 있는 높이 증가
			}
			if (res < height)
				height = res;
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			map[v[i][j]][i] = '.';
			map[v[i][j] + height][i] = 'x';
		}
	}
}
void solve(int x, int y, int num) {
	//num = 1(땅)
	//num = 2(뜬 거)
	q.push({ x,y });
	visit[x][y] = num;
	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		if (visit[cur.x][cur.y] == 2) {
			//내려야하는 클러스터면
			v[cur.y].push_back(cur.x);
		}
		for (int i = 0; i < 4; i++) {
			Point next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if (range(next) && visit[next.x][next.y] == 0 && map[next.x][next.y] == 'x') {
				//범위 내 && 방문한 적 없고 && 미네랄이면
				visit[next.x][next.y] = num;//방문체크 하고
				q.push(next);//큐에 넣기
			}
		}
	}
}
void vclear() {
	for (int i = 0; i < c; i++) {
		v[i].clear();
	}
}
void check() {
	memset(visit, 0, sizeof(visit));//visit 초기화
	vclear();//벡터 초기화
	solve(r, 0, 1);//첫번째 클러스터 탐색
	//땅과 연결되지 않은 미네랄 위치 찾기
	bool flag = false;
	int x = 0;
	int y = 0;
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'x' && visit[i][j] == 0) {
				//공중에 뜬 미네랄 발견!
				x = i;
				y = j;
				flag = true;//플래그 처리
				//v[y].push_back(x);//열마다 검사 열->행
			}
		}
		if (flag)
			break;//미네랄 발견했으면 더이상 볼 것도 없다
	}
	if (!flag)
		return;//분리된 클리스터가 없다!
	else {
		//두번째 클러스터 탐색
		solve(x, y, 2);
		move();//클러스터 내리기
	}
}
void throwStick() {
	for (int i = 0; i < n; i++) {
		int h;
		scanf("%d", &h);
		if (i % 2 == 0) {
			//왼쪽 -> 오른쪽
			for (int j = 0; j < c; j++) {
				if (map[r - h][j] == 'x') {
					map[r - h][j] = '.';//클러스터 때리기
					break;//한 번만
				}
			}
		}
		else {
			//오른쪽 -> 왼쪽
			for (int j = c - 1; j >= 0; j--) {
				if (map[r - h][j] == 'x') {
					map[r - h][j] = '.';//클러스터 때리기
					break;//한 번만
				}
			}
		}
		check();//클러스터가 분리되었는지 체크 
	}
}
void mapInit() {
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == r)
				map[i][j] = 'x';//클러스타 바닥에 깔기
			else
				scanf(" %1c", &map[i][j]);//입력받기
		}
	}
}
void ansPrint() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
int main() {
	scanf("%d%d", &r, &c);
	mapInit();//맵 초기화
	scanf("%d", &n);
	throwStick();//막대 던지러
	ansPrint();//결과 출력
	return 0;
}
