#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int temp[20];//입력 받은 n개의 수
int arr[20];//실제 출력 배열
bool visit[20];
void comb(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		arr[cnt] = temp[i];
		visit[i] = true;
		comb(cnt + 1);
		visit[i] = false;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp[i]);
	}
	sort(temp, temp + n);
	comb(0);
	return 0;
}
