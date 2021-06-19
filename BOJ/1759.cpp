#include <cstdio>
#include <algorithm>
using namespace std;
int l, c;
bool visit[20];
char arr[20];
char ans[20];
void comb(int idx, int cnt) {
	if (cnt == l) {
		int tmp = 0;//모음
		int tmp2 = 0;//자음
		for (int i = 0; i < cnt; i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				tmp++;
			else
				tmp2++;
		}
		if (tmp >= 1 && tmp2 >= 2) {
			for (int i = 0; i < cnt; i++)
				printf("%c", ans[i]);
			printf("\n");
		}		
		return;
	}
	for (int i = idx; i < c; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		ans[cnt] = arr[i];
		comb(i, cnt + 1);
		visit[i] = false;
	}
}
int main() {
	scanf("%d%d", &l, &c);
	for (int i = 0; i < c; i++) {
		scanf(" %1c", &arr[i]);
	}
	sort(arr, arr + c);
	comb(0, 0);
	
	return 0;
}
