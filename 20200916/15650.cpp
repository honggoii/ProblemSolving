#include <cstdio>
int n, m;
int arr[20];
bool visit[20];
void comb(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= n; i++) {
			if (visit[i])
				printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		comb(i, cnt + 1);
		visit[i] = false;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	comb(1, 0);
	return 0;
}
