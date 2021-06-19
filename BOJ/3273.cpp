#include <cstdio>
#include <algorithm>

using namespace std;
int arr[100001];

int main() {
	int ans = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int x;
	scanf("%d", &x);

	int i = 0;
	int j = n - 1;
	while (1) {
		if ((arr[i] + arr[j]) == x) {
			i++;
			j--;
			ans++;
		}
		else if ((arr[i] + arr[j] > x)) {
			j--;
		}
		else {
			i++;
		}

		if (i >= j)
			break;
	}
	printf("%d", ans);
	
	return 0;
}
