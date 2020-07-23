#include <cstdio>

int arr[7];
int odd[7];
int sum;
int j;
int min;

int main() {
	for (int i = 0; i < 7; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] % 2 != 0) {
			sum += arr[i];
			odd[j++] = arr[i];
		}
	}

	min = odd[0];

	if (sum == 0) {
		printf("-1");
	}
	else {
		printf("%d\n", sum);
		for (int i = 1; i < 7; i++) {
			if (odd[i] == 0)
				break;
			if (min > odd[i])
				min = odd[i];
		}
		printf("%d\n", min);
	}

	return 0;
}