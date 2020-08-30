#include <cstdio>
#include <cmath>
bool p[22];//팀 구분
int start[11];//스타트팀
int link[11];//링크팀
int graph[22][22];
int n;//사람 수
int ans = 10000000;
void combination(int idx, int cnt) {
	if (cnt == n / 2) {
		int k = 0;
		for (int i = 1; i <= n; i++) {
			if (!p[i])
				link[k++] = i;
		}

		int a = 0;//스타트팀
		int b = 0;//링크팀
		for (int i = 0; i < n / 2; i++) {
			//반만 계산
			for (int j = 1; j <= n; j++) {
				if (p[j] && start[i] != j)
					a += graph[start[i]][j];
				else if (!p[j] && link[i] != j)
					b += graph[link[i]][j];
			}
		}

		int temp = abs(a - b);
		if (temp < ans)
			ans = temp;
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (p[i]) continue;
		p[i] = true;//스타트팀
		start[cnt] = i;
		combination(i, cnt + 1);
		p[i] = false;//링크팀
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
}
int main() {
	scanf("%d", &n);//사람 수
	init();//입력
	combination(1,0);
	printf("%d", ans);
	return 0;
}
