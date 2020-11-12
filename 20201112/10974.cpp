#include <cstdio>
bool visit[18];
int arr[18];
int n;
void comb(int idx, int cnt) {
	if (cnt == n) {
		for (int i = 0; i < cnt; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		arr[cnt] = i;
		comb(i, cnt + 1);
		visit[i] = false;
	}
}
int main() {
	scanf("%d", &n);
	comb(1, 0);
	return 0;
}
