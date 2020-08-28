#include <cstdio>
int n;//퇴사 날짜
int dp[17];
int t[17];//시간
int p[17];//금액
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int main() {
	scanf("%d", &n);//퇴사 날짜
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &t[i], &p[i]);
	}
	for (int i = n; i >= 1; i--) {
		if (n + 1 < i + t[i]) {
			dp[i] = dp[i + 1];//일을 못 하는 경우
		}
		else {
			dp[i] = max(dp[i+1], dp[i+t[i]]+p[i]);//(일 안 할건지, 할 건지)
		}
	}
	printf("%d", dp[1]);
	return 0;
}
