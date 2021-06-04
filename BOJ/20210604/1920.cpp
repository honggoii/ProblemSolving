#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[100001];
int m;
int num[100001];
bool flag;
void binarysearch(int idx) {
	int left = 0;
	int right = n - 1;
	int mid = n / 2;

	while (left <= right) {
		if (arr[mid] == num[idx]) {
			flag = true;
			break;
		}
		else if (arr[mid] > num[idx]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		mid = (left + right) / 2;
	}

	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &num[i]);

	for (int i = 0; i < m; i++) {
		flag = false;
		binarysearch(i);

		if (flag)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
