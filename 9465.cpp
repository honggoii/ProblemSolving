#include <cstdio>

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	freopen("sample.txt", "r", stdin);
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		int arr[2][100001] = { 0, };
		int dp[2][100001] = { 0, };
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int j = 2; j <= n; j++) {
			dp[0][j] = arr[0][j] + max(dp[1][j - 2], dp[1][j - 1]);
			dp[1][j] = arr[1][j] + max(dp[0][j - 2], dp[0][j - 1]);
		}

		printf("%d\n", max(dp[0][n], dp[1][n]));
	}

	return 0;
}