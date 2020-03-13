#include <cstdio>
#include <algorithm>

using namespace std;

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int coin[101];
int dp[10001];

int main() {
	freopen("sample.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	fill(dp + 1, dp + 10001, 100001);

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 100001)
		printf("-1");
	else
		printf("%d", dp[k]);

	return 0;
}