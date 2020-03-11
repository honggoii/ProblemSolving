#include <cstdio>

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

using namespace std;

int dp[1000001];

int main() {
	int n;
	scanf("%d", &n);

	dp[1] = 0;
	dp[2] = dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		if ((i % 2 == 0) && (i % 3 == 0)) {
			dp[i] = min(dp[i / 2] + 1, dp[i / 3] + 1);
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}