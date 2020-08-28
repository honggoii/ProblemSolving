#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;//명령 넣을 벡터
typedef struct {
	int x, y;
} Point;
int n, m;//행 열
Point p;//주사위 좌표
int k;//명령 개수
int map[21][21];//지도
int dice[7];//주사위
/* 동(0) 서(1) 북(2) 남(3)*/
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool range(Point next) {
	return next.x >= 0 && next.x < n && next.y >= 0 && next.y < m;
}
void diceChange(int dir) {
	int d1, d2, d3, d4, d5, d6;//주사위 6면
	d1 = dice[1]; d2 = dice[2]; d3 = dice[3]; 
	d4 = dice[4]; d5 = dice[5]; d6 = dice[6];
	if (dir == 0) {
		//동
		dice[3] = d6;
		dice[6] = d4;
		dice[4] = d1;
		dice[1] = d3;
	}
	else if (dir == 1) {
		//서
		dice[3] = d1;
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
	}
	else if (dir == 2) {
		//북
		dice[6] = d5;
		dice[5] = d1;
		dice[1] = d2;
		dice[2] = d6;
	}
	else if (dir == 3) {
		//남
		dice[6] = d2;
		dice[2] = d1;
		dice[1] = d5;
		dice[5] = d6;
	}
}
void rollDice() {
	for (int i = 0; i < v.size(); i++) {//명령 개수만큼 실행
		Point next;
		next.x = p.x + dx[v[i]];
		next.y = p.y + dy[v[i]];

		if (!range(next)) continue;//범위 벗어나면 아무것도 하지말기
		diceChange(v[i]);//주사위 굴리기

		if (map[next.x][next.y] == 0) {
			//지도가 0이면 내 값 복사
			map[next.x][next.y] = dice[6];
		}
		else {
			//지도가 0이 아니면
			//주사위 바닥에 복사하고 지도는 0으로
			dice[6] = map[next.x][next.y];
			map[next.x][next.y] = 0;
		}
		
		printf("%d\n", dice[1]);

		p.x = next.x;
		p.y = next.y;
	}
}
void makeMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a - 1);//인덱스가 0부터 시작
	}
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &p.x, &p.y, &k);
	makeMap();//지도 생성
	rollDice();//주사위 굴리기
	return 0;
}
