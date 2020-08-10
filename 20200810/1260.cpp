#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m, v;
queue<int> q;
int graph[1001][1001];
bool visit[1001];
void dfs(int node) {
	visit[node] = true;
	cout << node << " ";
	for (int next = 1; next <= n; next++)
		if (!visit[next] && graph[node][next])
			dfs(next);
}
void bfs(int node) {
	visit[node] = true;
	q.push(node);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (int next = 1; next <= n; next++) {
			if (!visit[next] && graph[cur][next]) {
				visit[next] = true;
				q.push(next);
			}			
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> v;
	while (m--) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(v);
	cout << '\n';
	memset(visit, 0, sizeof(visit));
	bfs(v);
	return 0;
}
