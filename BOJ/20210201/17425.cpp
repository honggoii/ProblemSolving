#include <cstdio>
long long dp[1000001];
int main() {
	dp[1] = 1;
	for (int i = 2; i < 1000001; i++) {
		for (int j = 1; j*i < 1000001; j++) {
			dp[i * j] += i;
		}
		dp[i] += (dp[i - 1] + 1);
	}
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	
	return 0;
}
