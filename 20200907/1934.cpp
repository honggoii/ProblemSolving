#include <cstdio>
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a, b;
		int lcm = 1;//초기화
		scanf("%d%d", &a, &b);
		//a가 무조건 작은수가 되도록
		if (b < a) {
			int temp = a;
			a = b;
			b = temp;
		}
		for (int i = a; i > 0; i--) {
			if ((a % i == 0) && (b % i == 0)) {
				lcm = i * (a / i) * (b / i);
				break;
			}
		}
		printf("%d\n", lcm);
	}
	return 0;
}
