#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[1100];
int n, m;
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		memset(v, 0, sizeof(v));
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
		}
		printf("%d\n", n - 1);
	}
	return 0;
}
