#include <cstdio>

long long arr[1000001];

int main() {
	freopen("sample.txt", "r", stdin);
	long long n, b, c;
	long long cnt = 0;
	scanf("%lld", &n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	scanf("%lld%lld", &b, &c);

	for (int i = 0; i < n; i++) {
		if (arr[i] - b > 0) {
			arr[i] -= b;
		}
		else {
			continue;
		}
		
		if (arr[i] % c == 0) {
			cnt += arr[i] / c;
		}
		else {
			cnt += arr[i] / c + 1;
		}		

		//while (arr[i] > 0) {
		//	cnt++;
		//	arr[i] -= c;
		//}		
	}

	printf("%lld\n", cnt + n);

	return 0;
}