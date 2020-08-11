#include <cstdio>
#include <algorithm>
int graph[14];
int cnt;
using namespace std;
int arr[14];
int j;
void init() {
	for (int i = 0; i < 14; i++) {
		graph[i] = 0;
	}	
}
void dfs(int idx, int k) {
	if (cnt == 6) {		
		sort(arr, arr + 6);
		for (int i = 0; i < 6; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = idx; i < k; i++) {
		arr[cnt] = graph[i];
		cnt++;
		dfs(i+1, k);
		cnt--;
	}	
}
int main() {
	while (1) {
		int k;
		scanf("%d", &k);
		if (k == 0)
			break;
		init();
		for (int i = 0; i < k; i++) {
			scanf("%d", &graph[i]);
		}
		cnt = 0;
		dfs(0, k);
		printf("\n");
	}
	return 0;
}
