#include <cstdio>
int main() {
	int n, m;
	int arr[101] = { 0, };
	int dif = 1e9;
	int ans;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum <= m && (m - sum) < dif) {
					dif = (m - sum);
					ans = sum;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
