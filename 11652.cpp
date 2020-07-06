#include <cstdio>
#include <algorithm>

using namespace std;
long long arr[100001];
int cnt = 1;
int maxcnt = 1;
long long answer;

int main() {
	freopen("sample.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr + n);

	answer = arr[0];
	for (int i = 1; i < n; i++) {

		if (arr[i] == arr[i - 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}

		if (maxcnt < cnt) {
			maxcnt = cnt;
			answer = arr[i];
		}
	}

	printf("%lld", answer);

	return 0;
}