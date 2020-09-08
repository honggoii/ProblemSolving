#include <cstdio>
int n, m, h;//세로선, 가로선, 놓을 수 있는 위치
bool visit[50][50];
int ans = 1e9;
bool ladder() {
	int cur;
	for (int i = 1; i <= n; i++) {
		cur = i;
		for (int j = 1; j <= h; j++) {
			if (visit[cur][j])
				cur++;
			else if (visit[cur - 1][j])
				cur--;
		}
		if (cur != i)
			return false;
	}
	return true;
}
void comb(int idx, int cnt) {
	if (cnt > 3)
		return;
	//사다리 타주기
	if (ladder()) {
		//사다리를 타서 모든 세로선이 자기 자신으로 가면
		//현재 설치한 사다리 개수가 최솟값인지 ans를 갱신
		if (cnt < ans)
			ans = cnt;
		return;
	}

	for (int i = idx; i <= h; i++) {
		for (int j = 1; j <= n - 1; j++) {
			if (visit[j][i]) continue;
			if (visit[j - 1][i])continue;
			if (visit[j + 1][i])continue;

			visit[j][i] = true;
			comb(i, cnt + 1);
			visit[j][i] = false;
		}
	}
}
void init() {
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		visit[b][a] = true;//b번 세로선이 a번 가로선에 연결되어있다.
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &h); //입력
	init();//초기화 해주기
	comb(1, 0);//조합
	if (ans == 1e9)
		ans = -1;
	printf("%d", ans);
	return 0;
}
