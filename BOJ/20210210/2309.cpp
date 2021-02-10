#include <cstdio>
#include <algorithm>
using namespace std;
bool visit[10];
int arr[10];
int ans[10];
void comb(int idx, int cnt) {
	if (cnt == 7) {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += ans[i];
		}

		if (sum == 100) {
			sort(ans, ans + 7);
			for (int i = 0; i < 7; i++) {
				printf("%d\n", ans[i]);
			}
			return;
		}
		return;
	}
	for (int i = idx; i < 9; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		ans[cnt] = arr[i];
		comb(i, cnt + 1);
		visit[i] = false;
	}
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + 9, cmp);
	comb(0, 0);
	return 0;
}
