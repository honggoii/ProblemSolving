#include <cstdio>

int coin[101]; // 코인 가치
int dp[10001]; // 경우의 수 

int main() {
	freopen("sample.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	dp[0] = 1; // 0원을 만들수 있는 경우의 수는 0원을 1개 사용, 1가지

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	printf("%d", dp[k]);

	return 0;
}