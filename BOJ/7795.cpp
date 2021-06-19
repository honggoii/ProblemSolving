#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[20001];
int b[20001];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &b[i]);
		}
		sort(a, a + n, cmp);
		sort(b, b + m, cmp);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] > b[j]) {
					ans += (m - j);
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
