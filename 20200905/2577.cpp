#include <cstdio>
int arr[10];
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int res;
	res = a * b * c;
	while (1) {
		if (res == 0)
			break;
		arr[res % 10]++;
		res /= 10;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return 0;
}
