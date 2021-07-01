#include <cstdio>
int dp[31][31];

int main() {
	int tc;
	int n, m;

	for (int i = 1; i < 31; i++) {
		dp[1][i] = i;
	}

	for (int r = 2; r < 31; r++) {
		for (int c = 2; c < 31; c++) {
			for (int k = c - 1; k > 0; k--) {
				dp[r][c] += dp[r - 1][k];
			}
		}
	}

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", dp[n][m]);
	}

	return 0;
}
