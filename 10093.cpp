#include <cstdio>

unsigned long long a, b;

int main() {
	scanf("%lld%lld", &a, &b);
	if (b < a) {
		unsigned long long tmp = a;
		a = b;
		b = tmp;
	}
	else if (a == b) {
		printf("0\n");
		return 0;
	}

	printf("%lld\n", b - a - 1);

	for (unsigned long long i = a + 1; i < b; i++) {
		printf("%lld ", i);
	}

	return 0;
}