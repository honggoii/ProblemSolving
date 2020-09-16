#include <cstdio>
using namespace std;
int arr[20];
bool visit[20];
int n, m;
void comb(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;//체크
		arr[cnt] = i;
		comb(i, cnt + 1);
		visit[i] = false;//체크 해제
	}
}
int main() {
	scanf("%d%d", &n, &m);
	comb(1, 0);
	return 0;
}
