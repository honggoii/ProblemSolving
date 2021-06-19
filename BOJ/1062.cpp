#include <iostream>
#include <string>
using namespace std;
int n, k;
bool alpha[30];
string arr[51];
int ans;
void comb(int idx, int cnt) {
	if (k - 5 == cnt) {
		//다 뽑았으면
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			bool flag = true;
			for (int j = 0; j < arr[i].size(); j++) {
				if (!alpha[arr[i][j]-97]) {
					flag = false;
					break;
				}					
			}
			if (flag)
				tmp++;
		}
		if (tmp > ans)
			ans = tmp;
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alpha[i]) continue;
		alpha[i] = true;
		comb(i, cnt + 1);
		alpha[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	alpha['a' - 97] = alpha['n' - 97] = alpha['t' - 97] = alpha['i' - 97] = alpha['c' - 97] = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (k < 5) {
		ans = 0;
	}
	else {
		comb(0, 0);
	}
	printf("%d", ans);
	
	return 0;
}
