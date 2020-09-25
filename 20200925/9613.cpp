#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[111];
int temp[3];
bool visit[111];
int n;
long long ans;
void comb(int idx, int cnt) {
	if (cnt == 2) {
		for (int i = temp[0]; i > 0; i--) {
			if (temp[0]%i == 0 && temp[1] % i == 0) {
				ans += i;
				break;
			}
		}
		return;
	}

	for (int i = idx; i < n; i++) {
		if (visit[i])continue;
		visit[i] = true;
		temp[cnt] = num[i];
		comb(i, cnt + 1);
		visit[i] = false;
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		memset(num, 0, sizeof(num));
		memset(visit, false, sizeof(visit));
		ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		sort(num, num + n);
		comb(0, 0);
		printf("%lld\n", ans);
	}
	return 0;
}
