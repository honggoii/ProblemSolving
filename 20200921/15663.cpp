#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int temp[30];
int arr[30];
bool visit[30];

int cnt;
void comb(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	bool check[10010];
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++) {
		if (check[temp[i]] || visit[i]) continue;
		visit[i] = true;
		check[temp[i]] = true;
		arr[cnt] = temp[i];
		comb(cnt + 1);
		visit[i] = false;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp[i]);
	}
	sort(temp, temp+n);
	comb(0);
	return 0;
}
