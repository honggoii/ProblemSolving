#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int arr[101];
int ans[101];
int cnt;
bool visit[101];
void dfs(int start, int idx) {
	visit[idx] = true;
	if (visit[arr[idx]]) {
		if (start == arr[idx]) {
			ans[cnt++] = arr[arr[idx]];
		}		
		return;
	}
	dfs(start, arr[idx]);	
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i, i);
	}	

	printf("%d\n", cnt);
	sort(ans, ans + cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
