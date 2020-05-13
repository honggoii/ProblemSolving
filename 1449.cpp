#include <cstdio>
#include <algorithm>
int arr[1001];
using namespace std;
int cnt = 1;

int main() {
	int n, l;
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int loc = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - loc + 1 > l) {
			cnt++;
			loc = arr[i];
		}
	}
	printf("%d\n", cnt);
	return 0;
}