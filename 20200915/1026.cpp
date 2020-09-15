#include <cstdio>
#include <algorithm>
using namespace std;
int a[60];
int b[60];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + n, cmp);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	printf("%d", sum);
	return 0;
}
