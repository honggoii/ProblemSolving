#include <cstdio>
int k;
int arr[13];
int lotto[6];
bool visit[13];
void comb(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", lotto[i]);
		}
		printf("\n");
		return;
	}

	for (int i = idx; i < k; i++) {
		if (visit[i])continue;
		visit[i] = true;
		lotto[cnt] = arr[i];
		comb(i, cnt + 1);
		visit[i] = false;
	}
}
int main() {
	while (1) {
		scanf("%d", &k);
		if (k == 0)
			break;
		for (int i = 0; i < k; i++) {
			scanf("%d", &arr[i]);
		}
		comb(0, 0);
		printf("\n");
	}
	
	return 0;
}
