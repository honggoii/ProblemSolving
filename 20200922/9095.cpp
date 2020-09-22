#include <cstdio>
int dp[100];
int main() {
	int tc;
	scanf("%d", &tc);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
