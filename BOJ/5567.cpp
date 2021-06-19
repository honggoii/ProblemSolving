#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[510];
queue<pair<int, int>> q;
bool visit[510];
int n, m;
int ans;//answer
void wedding() {
	q.push({ 1, 0 });//1번
	visit[1] = true;
	while (1) {
		if (q.empty())
			break;//1번이 아예 친구가 없는경우..
		int cur = q.front().first; 
		int cnt = q.front().second;
		q.pop();
		
		if (cnt == 3)
			break;//결혼식 올 수 없음

		ans++;

		for (int i = 0; i < v[cur].size(); i++) {
			if (!visit[v[cur][i]]) {
				visit[v[cur][i]] = true;
				q.push({ v[cur][i], cnt+1});
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	wedding();
	printf("%d", ans-1);
	return 0;
}
