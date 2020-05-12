#include <cstdio>
int arr[11];
int cnt;

int main() {
	int n, k;	
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = n - 1; i >= 0; i--) {
		if (k < arr[i])
			continue;
		else {
			cnt += k / arr[i];
			k %= arr[i];
		}
	}

	printf("%d\n", cnt);

	return 0;
}