#include <cstdio>
#include <vector>
using namespace std;
int n, m;//행, 열
int map[10][10];
int temp[10][10];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef struct {
	int x, y;
	int num;//cctv 번호
	int dir;//방향
} Point;
vector<Point> v;
int vsize;
int ans = 10000000;
int blind() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (temp[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}
void dirRight(int x, int y) {
	//오른쪽
	for (int i = y; i <= m; i++) {
		if (temp[x][i] == 6)
			break;//벽 만나면 탈출
		if (temp[x][i] == 0)
			temp[x][i] = -1;//체크
		if (temp[x][i] >= 1 && temp[x][i] <= 5)
			continue;//cctv 통과
	}
}
void dirLeft(int x, int y) {
	//왼쪽
	for (int i = y; i >= 1; i--) {
		if (temp[x][i] == 6)
			break;//벽 만나면 탈출
		if (temp[x][i] == 0)
			temp[x][i] = -1;//체크
		if (temp[x][i] >= 1 && temp[x][i] <= 5)
			continue;//cctv 통과
	}
}
void dirDown(int x, int y) {
	//아래
	for (int i = x; i <= n; i++) {
		if (temp[i][y] == 6)
			break;//벽 만나면 탈출

		if (temp[i][y] == 0)
			temp[i][y] = -1;//체크

		if (temp[i][y] >= 1 && temp[i][y] <= 5)
			continue;//cctv통과
	}
}
void dirTop(int x, int y) {
	//위
	for (int i = x; i >= 1; i--) {
		if (temp[i][y] == 6)
			break;//벽 만나면 탈출

		if (temp[i][y] == 0)
			temp[i][y] = -1;//체크

		if (temp[i][y] >= 1 && temp[i][y] <= 5)
			continue;//cctv통과
	}
}
void cctvStart() {
	for (int i = 0; i < vsize; i++) {
		if (v[i].num == 1) {
			//1번 카메라
			if (v[i].dir == 0) {
				//상
				dirTop(v[i].x, v[i].y);
			}
			else if (v[i].dir == 1) {
				//하
				dirDown(v[i].x, v[i].y);
			}
			else if (v[i].dir == 2) {
				//좌
				dirLeft(v[i].x, v[i].y);
			}
			else if (v[i].dir == 3) {
				//우
				dirRight(v[i].x, v[i].y);
			}
		}
		else if (v[i].num == 2) {
			//2번 카메라
			if (v[i].dir == 0 || v[i].dir == 1) {
				//상, 하
				dirTop(v[i].x, v[i].y);
				dirDown(v[i].x, v[i].y);
			}
			else if (v[i].dir == 2 || v[i].dir == 3) {
				//좌, 우
				dirLeft(v[i].x, v[i].y);
				dirRight(v[i].x, v[i].y);
			}
		}
		else if (v[i].num == 3) {
			//3번 카메라
			if (v[i].dir == 0) {
				dirTop(v[i].x, v[i].y);
				dirRight(v[i].x, v[i].y);
			}
			else if (v[i].dir == 1) {
				dirDown(v[i].x, v[i].y);
				dirLeft(v[i].x, v[i].y);
			}
			else if (v[i].dir == 2) {
				dirLeft(v[i].x, v[i].y);
				dirTop(v[i].x, v[i].y);
			}
			else if (v[i].dir == 3) {
				dirRight(v[i].x, v[i].y);
				dirDown(v[i].x, v[i].y);
			}
		}
		else if (v[i].num == 4) {
			//4번 카메라
			if (v[i].dir == 0) {
				dirLeft(v[i].x, v[i].y);
				dirTop(v[i].x, v[i].y);
				dirRight(v[i].x, v[i].y);
			}
			else if (v[i].dir == 1) {
				dirLeft(v[i].x, v[i].y);
				dirDown(v[i].x, v[i].y);
				dirRight(v[i].x, v[i].y);
			}
			else if (v[i].dir == 2) {
				dirTop(v[i].x, v[i].y);
				dirLeft(v[i].x, v[i].y);
				dirDown(v[i].x, v[i].y);
			}
			else if (v[i].dir == 3) {
				dirTop(v[i].x, v[i].y);
				dirRight(v[i].x, v[i].y);
				dirDown(v[i].x, v[i].y);
			}
		}
		else if (v[i].num == 5) {
			//5번 카메라
			dirTop(v[i].x, v[i].y);
			dirRight(v[i].x, v[i].y);
			dirDown(v[i].x, v[i].y);
			dirLeft(v[i].x, v[i].y);
		}
	}
}
void mapCopy() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = map[i][j];
		}
	}
}
void cctvDir(int num) {
	if (num == vsize) {
		mapCopy();//map복사
		cctvStart();//cctv작동
		int cnt = blind();//사각지대 찾기
		if (cnt < ans)
			ans = cnt;
		return;
	}

	v[num].dir = 0;//상
	cctvDir(num + 1);

	v[num].dir = 1;//하
	cctvDir(num + 1);

	v[num].dir = 2;//좌
	cctvDir(num + 1);

	v[num].dir = 3;//우
	cctvDir(num + 1);
}
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 5)
				v.push_back({ i,j,map[i][j],-1 });//cctv 좌표 넣기
		}
	}
	vsize = v.size();
}
int main() {
	scanf("%d%d", &n, &m);
	init();//맵 초기화
	cctvDir(0);//cctv 방향 설정
	printf("%d", ans);
	return 0;
}
