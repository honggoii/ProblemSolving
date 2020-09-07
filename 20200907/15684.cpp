#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, h;//세로선, 가로선, 놓을 수 있는 가로선
bool visit[11][30];//[b][a] => b선이 가로선 a에 연결
int ans = 1e9;//정답(최소값으로)
bool test() {
	int cur = 0;//현재 번호
	for (int i = 1; i <= n; i++) {//세로선
		cur = i;//시작 번호
		for (int j = 1; j <= h; j++) {//놓을 수 있는 가로선
			if (visit[cur][j]) {
				//후랑 연결되어 있으면 
				cur++;//다음으로
			}
			else if (visit[cur - 1][j]) {
				//전이랑 연결되어 있으면
				cur--;//앞으로
			}
		}
		if (cur != i) {
			return false;//자기 자신으로 안 갔다는거임
		}		
	}
	return true;//모두가 제자리를 찾았다
}
void Combination(int idx, int cnt) {
	if (cnt > 3) {
		//종료 조건
		return;
	}

	//진행해 봐야함
	if (test()) {
		ans = min(ans, cnt);//연결된 가로선 개수, 최소값으로 갱신
		return;
	}	
		
	for (int i = idx; i <= h; i++) {//놓을 수 있는 가로선
		for (int j = 1; j <= n - 1; j++) {//세로선
			if (visit[j][i]) continue;//연결되어있으면 패스
			if (visit[j - 1][i]) continue;//그 전이 연결되어있으면 이어서 못함(두 가로선이 연속 X)
			if (visit[j + 1][i]) continue;//그 후가 연결되어있으면 이어서 못함(두 가로선이 연속 X)
			visit[j][i] = true;
			Combination(i, cnt + 1);
			visit[j][i] = false;
		}
	}
}
void initCon() {
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		visit[b][a] = true;//연결
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &h);
	initCon();//기본 가로선
	Combination(1, 0);//조합으로 가로선 개수 뽑기
	if (ans == 1e9)
		printf("-1");
	else
		printf("%d", ans);
	return 0;
}
