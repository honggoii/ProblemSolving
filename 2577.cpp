#include <cstdio>
int a, b, c;
int res;
int arr[10];
int main() {
	scanf("%d%d%d", &a, &b, &c);
	res = a * b * c;
	while (1) {
		arr[res % 10]++;
		res /= 10;
		if (res == 0)
			break;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return 0;
}