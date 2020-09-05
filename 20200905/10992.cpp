#include <cstdio>

int main() {
	int a;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		if (i == 1) {
			for (int j = 0; j < (a - i); j++)
				printf(" ");
			printf("*\n");
		}
		else if (i == a) {
			for (int j = 0; j < (2 * i - 1); j++)
				printf("*");
			printf("\n");
		}
		else {
			for (int j = 0; j < (a - i); j++)
				printf(" ");
			printf("*");
			for (int j = 0; j < (2 * (i - 1) - 1); j++) {
				printf(" ");
			}
			printf("*\n");
		}
	}
	return 0;
}
