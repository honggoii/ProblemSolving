#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int temp[20];
int arr[20];
bool visit[20];
void comb(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = idx; i < n; i++) {
		arr[cnt] = temp[i];
		comb(i, cnt + 1);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &temp[i]);
	sort(temp, temp + n);
	comb(0, 0);
	return 0;
}
