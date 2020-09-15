#include <cstdio>
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int g = gcd(a, b);//최대공약수
	printf("%d\n",g);
	printf("%d\n", g * (a / g) * (b / g));
	return 0;
}
