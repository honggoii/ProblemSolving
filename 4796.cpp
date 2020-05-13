#include <cstdio>

int main() {
	freopen("sample.txt", "r", stdin);
	int i = 1;
	while (1) {
		int p, l, v;
		int result = 0;
		scanf("%d%d%d", &l, &p, &v);
		if ((l == 0) && (p == 0) && (v == 0))
			break;
		//if (v % p != 0) {
			result = (v / p) * l;
			if (v % p > l)
				result += l;
			else
				result += (v % p);
		//}
		printf("Case %d: %d\n", i++, result);
	}
	
	return 0;
}