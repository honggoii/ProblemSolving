#include <cstdio>
int n;
int arr[10];
int max;
int main() {
	scanf("%d", &n);
	while (1) {
		if (n % 10 == 9)
			arr[6]++;
		else
			arr[n % 10]++;
		n /= 10;
		if (n == 0)
			break;
	}
	if (arr[6] % 2 == 0)
		arr[6] /= 2;
	else
		arr[6] = (arr[6] / 2) + 1;
	max = arr[0];
	for (int i = 1; i < 9; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	printf("%d", max);
	return 0;
}