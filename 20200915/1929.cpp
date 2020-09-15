#include <cstdio>
#include <cstring>
bool prime[1000010];
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (!prime[i]) continue;
		
		for (int j = 2; i * j <= n; j++) {
			prime[i * j] = false;
		}
	}

	for (int i = m; i <= n; i++) {
		if (prime[i])
			printf("%d\n", i);
	}

	return 0;
}
