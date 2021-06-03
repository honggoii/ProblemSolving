#include <cstdio>
int l, p, v;
int i;
int main() {
	while (1) {
		int ans = 0;
		scanf("%d%d%d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0)
			break;
		ans = ((v / p) * l);

		if (v % p > l) {
			ans += l;
		}
		else {
			ans += (v % p);
		}
		printf("Case %d: %d\n", ++i, ans);
	}
	return 0;
}
