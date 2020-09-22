#include <cstdio>
int n, s;//n개, 합이 s
int temp[30];
int arr[30];
bool visit[30];
int ans;
void comb(int idx, int cnt, int lim) {
	if (cnt == lim) {
		int sum = 0;
		for (int i = 0; i < cnt; i++)
			sum += arr[i];
		if (sum == s)
			ans++;
		return;
	}

	for (int i = idx; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		arr[cnt] = temp[i];
		comb(i, cnt + 1, lim);
		visit[i] = false;
	}
}
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &temp[i]);
	for (int i = 1; i <= n; i++) {
		comb(0, 0, i);
	}
	printf("%d", ans);
	return 0;
}
