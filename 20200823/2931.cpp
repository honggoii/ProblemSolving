#include <cstdio>
int r, c;//행,열
char map[26][26];
typedef struct {
	int x, y;
	int dir;//방향
} Point;
Point start;//모스크바 위치
Point finish;//자그레브 위치
Point hack;//해킹당한 자리
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
char shape[] = { '|','-','+','1','2','3','4' };
bool flag;
bool range(Point p) {
	return p.x >= 1 && p.x <= r && p.y >= 1 && p.y <= c;
}
int changeDir(int dir, char pipe) {
	int res = -1;
	if (pipe == '|') {
		if (dir == 2 || dir == 3)
			res = dir;//방향 그대로
	}
	else if (pipe == '-') {
		if (dir == 0 || dir == 1)
			res = dir;//방향 그대로
	}
	else if (pipe == '+') {
		res = dir;//방향 그대로
	}
	else if (pipe == '1') {
		if (dir == 2)
			res = 1;
		else if (dir == 0)
			res = 3;
	}
	else if (pipe == '2') {
		if (dir == 3)
			res = 1;
		else if (dir == 0)
			res = 2;
	}
	else if (pipe == '3') {
		if (dir == 1)
			res = 2;
		else if (dir == 3)
			res = 0;
	}
	else if (pipe == '4') {
		if (dir == 1)
			res = 3;
		else if (dir == 2)
			res = 0;
	}
	return res;
}
void flow(Point p) {
	Point next;
	next.x = p.x + dx[p.dir];
	next.y = p.y + dy[p.dir];
	next.dir = changeDir(p.dir, map[next.x][next.y]);

	if (next.x == finish.x && next.y == finish.y) {
		return;
	}

	if (next.dir == -1) {
		//해당 파이프 불가
		flag = false;
		return;
	}
	else {
		flow(next);
	}
}
void dfs(Point p) {
	Point next;
	next.x = p.x + dx[p.dir];
	next.y = p.y + dy[p.dir];
	next.dir = changeDir(p.dir, map[next.x][next.y]);//파이프 모양에 따라 방향 전환
	if (map[next.x][next.y] == '.') {
		hack.x = next.x;
		hack.y = next.y;
		hack.dir = -1;
		return;
	}
	dfs(next);
}
int main() {
	scanf("%d%d", &r, &c);//행,열
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'M') {//모스크바 좌표
				start.x = i;
				start.y = j;
				start.dir = -1;
			}
			else if (map[i][j] == 'Z') {//자그레브 좌표
				finish.x = i;
				finish.y = j;
				finish.dir = -1;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		//모스크바에서 시작
		Point next;
		next.x = start.x + dx[i];
		next.y = start.y + dy[i];
		if (range(next) && map[next.x][next.y] != '.' 
			&& map[next.x][next.y] != 'Z') {
			start.dir = i;
			break;
		}
	}
	dfs(start);//해킹당한 좌표 찾기
	printf("%d %d", hack.x, hack.y);
	for (int i = 0; i < 7; i++) {
		flag = true;
		map[hack.x][hack.y] = shape[i];
		flow(start);
		if (flag) {
			printf(" %c", shape[i]);
			break;
		}
	}
	return 0;
}
