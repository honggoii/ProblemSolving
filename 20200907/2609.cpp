#include <cstdio>
int main() {
	int a, b;
	int gcd;//최대공약수
	int lcm = 1;//최소공배수
	scanf("%d%d", &a, &b);
	if (b < a) {
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i = a; i > 1; i--) {
		if ((a % i == 0) && (b % i == 0)) {
			gcd = i;
			lcm = i * (a / i) * (b / i);
			break;
		}
	}
	printf("%d\n", gcd);
	printf("%d\n", lcm);
	return 0;
}
