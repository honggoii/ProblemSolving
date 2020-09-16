#include <cstdio>
int n, m;
int arr[17];
void comb(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[cnt] = i;
		comb(i, cnt + 1);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	comb(1, 0);
	return 0;
}
