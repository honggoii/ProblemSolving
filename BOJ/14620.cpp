#include <cstdio>
int n;
int map[20][20];
bool visit[20][20];
int ans = 1e9;
void comb(int cnt) {
	if (cnt == 3) {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j]) {
					tmp += map[i][j]; //체크된 곳 값 계산
				}
			}
		}
		if (tmp < ans)
			ans = tmp;//최소비용 갱신
		return;
	}


	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			//씨앗을 못 심는 경우
			if (visit[i - 1][j] || visit[i][j - 1] || visit[i][j] || visit[i + 1][j] || visit[i][j + 1]) continue;

			//심을 수 있으면 상하좌우중심 방문 체크
			visit[i][j] = true;
			visit[i - 1][j] = true;
			visit[i + 1][j] = true;
			visit[i][j - 1] = true;
			visit[i][j + 1] = true;
			comb(cnt + 1);
			visit[i][j] = false;
			visit[i - 1][j] = false;
			visit[i + 1][j] = false;
			visit[i][j - 1] = false;
			visit[i][j + 1] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	comb(0);//(1,1)부터 심어나가기
	printf("%d", ans);
	
	return 0;
}
