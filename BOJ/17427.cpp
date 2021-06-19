#include <cstdio>
int ans;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ans += i * (n / i);
	}
	printf("%d", ans);
	
	return 0;
}
