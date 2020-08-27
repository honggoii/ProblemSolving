#include <cstdio>
#include <queue>
using namespace std;
int n;//보드 크기
int board[21][21];//움직일 보드
int ans;//최대값
queue<int> q;
void move(int dir) {
	if (dir == 0) {
		//상
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) {
				if (board[i][j]) {
					q.push(board[i][j]);
					board[i][j] = 0;//이후를 위해 처리
				}
			}
			int i = 1;
			while (!q.empty()) {
				int cur = q.front(); q.pop();

				if (board[i][j] == 0) {
					//값이 0이면 내 값을 전해주기
					board[i][j] = cur;
				}
				else if (board[i][j] == cur) {
					//같으면 합해지는 효과
					board[i++][j] *= 2;//2배				
				}
				else {
					//움직일 방향에 0도 아니고 나랑 같지 않으면 그대로 냅두기
					board[++i][j] = cur;
				}
			}
		}
	}
	else if (dir == 1) {
		//하
		for (int j = 1; j <= n; j++) {
			for (int i = n; i >= 1; i--) {
				if (board[i][j]) {
					q.push(board[i][j]);
					board[i][j] = 0;//이후를 위해 처리
				}
			}
			int i = n;
			while (!q.empty()) {
				int cur = q.front(); q.pop();

				if (board[i][j] == 0) {
					//값이 0이면 내 값을 전해주기
					board[i][j] = cur;
				}
				else if (board[i][j] == cur) {
					//같으면 합해지는 효과
					board[i--][j] *= 2;//2배					
				}
				else {
					//움직일 방향에 0도 아니고 나랑 같지 않으면 그대로 냅두기
					board[--i][j] = cur;
				}
			}
		}
	}
	else if (dir == 2) {
		//좌
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j]) {
					q.push(board[i][j]);
					board[i][j] = 0;//이후를 위해 처리
				}
			}
			int j = 1;
			while (!q.empty()) {
				int cur = q.front(); q.pop();

				if (board[i][j] == 0) {
					//값이 0이면 내 값을 전해주기
					board[i][j] = cur;
				}
				else if (board[i][j] == cur) {
					//같으면 합해지는 효과
					board[i][j++] *= 2;//2배					
				}
				else {
					//움직일 방향에 0도 아니고 나랑 같지 않으면 그대로 냅두기
					board[i][++j] = cur;
				}
			}
		}
	}
	else if (dir == 3) {
		//우
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >= 1; j--) {
				if (board[i][j]) {
					q.push(board[i][j]);
					board[i][j] = 0;//이후를 위해 처리
				}
			}
			int j = n;
			while (!q.empty()) {
				int cur = q.front(); q.pop();

				if (board[i][j] == 0) {
					//값이 0이면 내 값을 전해주기
					board[i][j] = cur;
				}
				else if (board[i][j] == cur) {
					//같으면 합해지는 효과
					board[i][j] = 0;
					board[i][j--] = cur * 2;//2배					
				}
				else {
					//움직일 방향에 0도 아니고 나랑 같지 않으면 그대로 냅두기
					board[i][--j] = cur;
				}
			}
		}
	}
}
int findMax() {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (res < board[i][j])
				res = board[i][j];//최대값 저장
		}
	}
	return res;
}
void permutation(int cnt) {
	if (cnt == 5) {
		int res = findMax();//5개를 뽑았으면 최대값을 찾는다.
		if (ans < res)
			ans = res;//최대값 저장
		return;//중요!!!!!!!!!!!!!!!!
	}
	int temp[21][21];//움직이기 전 모습 기억해두기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		//상하좌우를 중복으로 뽑는다.
		move(i);//해당 방향으로 이동
		permutation(cnt + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				board[i][j] = temp[i][j];
			}
		}
	}
}
void initBoard() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
}
int main() {
	scanf("%d", &n);
	initBoard();//초기 보드 모양 입력받기
	permutation(0);//4방향에서 5개를 뽑는 중복순열
	printf("%d", ans);
	return 0;
}
