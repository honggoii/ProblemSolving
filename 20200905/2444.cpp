#include <cstdio>

int main() {
	int a;
	scanf("%d", &a);

	for (int i = 1; i <= (a * 2 - 1); i++) {
		if (i <= a) {
			for (int j = 1; j <= (a - i); j++)
				printf(" ");
			for (int j = 1; j <= (2 * i - 1); j++)
				printf("*");
		}
		else {
			for (int j = 1; j <= (i - a); j++)
				printf(" ");
			for (int j = 1; j <= (2 * (2*a - i) - 1); j++)
				printf("*");
		}
		printf("\n");
	}
}
