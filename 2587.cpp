#include <cstdio>

int arr[5];
int sum;

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("%d\n", sum/5);
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 5; j++) {
			if (arr[j] > arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	printf("%d\n", arr[2]);
	return 0;
}