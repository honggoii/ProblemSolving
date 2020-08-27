#include <cstdio>
#include <deque>
#include <vector>
using namespace std;
typedef struct {
	int x, y;
	int dir;//방향
} Point;
deque<Point> dq;
vector<pair<int, char>> v;//(시간,방향) 정보 저장
int n;//보드 크기(2~100)
int k;//사과 개수(0~100)
int l;//방향 변환 횟수(1~100)
int board[101][101];//사과 위치 1, 뱀 위치 2
int time = 1;//시간초
int dx[] = { -1,1,0, 0 };
int dy[] = { 0,0,-1,1 };
bool range(int x, int y) {
	return x >= 1 & x <= n && y >= 1 && y <= n;
}
void start(Point p) {
	int i = 0;
	while (1) {
		//해당 방향으로 이동, 덱 앞에 추가
		int x = dq.front().x + dx[dq.front().dir];
		int y = dq.front().y + dy[dq.front().dir];
		int dir = dq.front().dir;
		dq.push_front({ x,y,dir });

		//이동한 곳이 뱀 자리거나 범위 넘어서면 탈락
		if (board[x][y] == 2 || !range(x, y))
			break;

		//이동한 곳에 사과가 있으면 그대로
		if (board[x][y] == 1) {
			board[x][y] = 2;//뱀 자리로 갱신
		}
		else if (board[x][y] == 0) {
			//사과가 없으면 뱀 자리 0으로 바꾸고 덱 뒤에 자르기
			board[x][y] = 2;//뱀 자리로 갱신
			board[dq.back().x][dq.back().y] = 0;
			dq.pop_back();
		}

		//방향 바꿀 시간
		if (i < v.size()) {
			if (time == v[i].first) {
				if (v[i].second == 'L') {
					//왼쪽 90도
					if (dir == 0) dq.front().dir = 2;
					else if (dir == 1) dq.front().dir = 3;
					else if (dir == 2) dq.front().dir = 1;
					else if (dir == 3) dq.front().dir = 0;
				}
				else if (v[i].second == 'D') {
					//오른쪽 90도
					if (dir == 0) dq.front().dir = 3;
					else if (dir == 3) dq.front().dir = 1;
					else if (dir == 1) dq.front().dir = 2;
					else if (dir == 2) dq.front().dir = 0;
				}
				i++;
			}
		}

		time++;//시간 증가
	}
}
void appleBoard() {
	for (int l = 0; l < k; l++) {
		int a, b;
		scanf("%d%d", &a, &b);
		board[a][b] = 1;
	}
}
int main() {
	scanf("%d", &n);//보드 크기
	scanf("%d", &k);//사과 개수
	appleBoard();//사과 얹어서 보드 생성
	scanf("%d", &l);//방향 변환 횟수
	for (int i = 0; i < l; i++) {
		int a;
		char b;
		scanf("%d %c", &a, &b);
		v.push_back(make_pair(a, b));
	}
	board[1][1] = 2;//뱀 초기 위치
	dq.push_back({ 1,1,3 });
	start({ 1,1,3 });//시작
	printf("%d", time);
	return 0;
}
