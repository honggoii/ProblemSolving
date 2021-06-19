#include <cstdio>
#include <cstring>
#include <cmath>
bool visit[21];
int map[21][21];
int n;
int ans = 1e9;
void permu(int idx, int num, int cnt) {
	if (num == cnt) {
		int s = 0;//스타트팀
		int l = 0;//링크팀
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visit[i] && visit[j]) {
					//스타트팀
					s += map[i][j];
				}
				else if (!visit[i] && !visit[j]) {
					//링크 팀
					l += map[i][j];
				}
			}
		}
		if (ans > abs(s - l))
			ans = abs(s - l);
	}

	for (int i = idx; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		permu(i, num, cnt + 1);
		visit[i] = false;
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int main() {
	
	scanf("%d", &n);
	init();//map 입력
	for (int i = 2; i < (n-1); i++) {
		memset(visit, false, sizeof(visit));
		permu(1, i, 0);
	}
	printf("%d", ans);
	return 0;
}
