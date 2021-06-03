#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[100001];
int tmp[100001];
bool cmp(int &a, int &b) {
	return a > b;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n, cmp);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		tmp[i] = arr[i] * (++cnt);
	}
	sort(tmp, tmp + n);
	printf("%d", tmp[n - 1]);
	return 0;
}
