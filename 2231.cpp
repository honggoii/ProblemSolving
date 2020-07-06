#include <cstdio>

int main() {
	freopen("sample.txt", "r", stdin);
	int n;
	int answer;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a = i;
		int k = i;

		while (1) {
			a += k % 10;
			k /= 10;

			if (k == 0)
				break;
		}

		if (a == n) {
			answer = i;
			break;
		}
		else
			answer = 0;
	}

	printf("%d", answer);
	return 0;
}