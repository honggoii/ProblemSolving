#include <cstdio>
#include <cmath>
int row[15];//한 행에는 하나의 퀸만
int n;
int ans;
bool check(int cnt) {
	for (int j = 0; j < cnt; j++) {//해당 행까지 열 탐색
		//퀸이 놓인 행(row[cnt]), 열(row[j])에는 놓을 수 없음
		//행의 차이 row[cnt]-row[j]
		//열의 차이 cnt-j
		//행의 차이와 열의 차이가 같으면 대각선
		if (row[j] == row[cnt] || abs(row[cnt] - row[j]) == (cnt - j))
			return false;
	}
	return true;
}
void nqueen(int cnt) {
	if (cnt == n) {
		ans++;//행마다 하나의 퀸을 뽑았으면
		return;
	}

	for (int i = 0; i < n; i++) {
		row[cnt] = i;//cnt행 i번째에 퀸을 놓음
		if(check(cnt))//놓을 수 있는지 확인
			nqueen(cnt + 1);
	}
}
int main() {
	scanf("%d", &n);
	nqueen(0);
	printf("%d", ans);
	
	return 0;
}
