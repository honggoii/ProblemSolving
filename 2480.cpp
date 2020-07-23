#include <cstdio>

int a, b, c;
int won = 0; // »ó±Ý

int main() {
	scanf("%d%d%d", &a, &b, &c);

	if (a == b && b == c) {
		won = 10000 + a * 1000;
	}
	else if (a == b && b != c) {
		won = 1000 + a * 100;
	}
	else if (a == c && c != b) {
		won = 1000 + a * 100;
	}
	else if (b == c && c != a) {
		won = 1000 + b * 100;
	}
	else {
		int max = (a > b) ? a : ((b > c) ? b : c);
		won = max * 100;
	}

	printf("%d", won);

	return 0;
}