#include <cstdio>

int main() {
	int n;
	
	while (scanf("%d", &n) != EOF) {
		int i = 1;
		int cnt = 1;
		while (1) {
			if (i % n == 0) {
				printf("%d\n", cnt);
				break;
			}
			else {
				i = (i % n) * 10 + 1;
				cnt++;
			}
		}
	}
	
	return 0;
}
