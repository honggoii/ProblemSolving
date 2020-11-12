#include <cstdio>

int main() {
	int a = 1, b = 1, c = 1;
	int E, S, M;
	int year = 1;
	scanf("%d%d%d", &E, &S, &M);
	while (1) {
		if (E == a && S == b && M == c)
			break;

		a++;
		b++;
		c++;

		if (a > 15)
			a = 1;
		if (b > 28)
			b = 1;
		if (c > 19)
			c = 1;

		year++;
	}
	printf("%d", year);
	return 0;
}
