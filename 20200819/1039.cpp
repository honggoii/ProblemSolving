#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string n;
int k;
int arr[1000001][11];//[n][k]
bool visit[1000001][11];
int ans;//정답
int temp = 0;
int dfs(string n, int cnt) {
	if (cnt == k)
		return stoi(n);
	if (visit[stoi(n)][cnt])
		return temp;
	visit[stoi(n)][cnt] = true;
	for (int i = 0; i < n.size() - 1; i++) {
		for (int j = i + 1; j < n.size(); j++) {
			if (i == 0 && n[j] == 0) continue;//0으로 시작할 수 없음
			swap(n[i], n[j]);//바꾸기
			int temp = dfs(n, cnt + 1);
			if (ans < temp)
				ans = temp;
			swap(n[i], n[j]);//원 위치
		}
	}
	return temp;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	if (n.size() == 1 || (n.size()==2 && n[1]=='0')) //한 자릿수거나 두자릿수면서 뒤에가 0이면
		cout << "-1";
	else {
		dfs(n, 0);//n, 횟수 0
		cout << ans;
	}
	return 0;
}
