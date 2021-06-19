#include <cstdio>
#include <vector>
using namespace std;
int n;
int ans;
vector<int> v[101];
bool visit[101];
void dfs(int idx) {
	visit[idx] = true;
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visit[v[idx][i]]) {
			dfs(v[idx][i]);
			ans++;
		}
	}
}
int main() {
	scanf("%d", &n);
	int tmp;
	scanf("%d", &tmp);
	for (int i = 0; i < tmp; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}
