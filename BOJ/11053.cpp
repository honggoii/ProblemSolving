#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[j] + 1,dp[i]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < dp[i])
			ans = dp[i];
	}
	printf("%d", ans);
	
	return 0;
}
