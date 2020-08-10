#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int f, s, g, u, d;
int graph[1000001];
bool visit[1000001];
int cnt;
void bfs(int node) {
	visit[node] = true;
	q.push(node);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == g)
			break;
		if (!visit[cur + u] && (cur + u <= f)) {
			visit[cur + u] = true;
			q.push(cur + u);
			graph[cur + u] = graph[cur] + 1;
		}
		if (!visit[cur - d] && (cur - d >= 1)) {
			visit[cur - d] = true;
			q.push(cur - d);
			graph[cur - d] = graph[cur] + 1;
		}			
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> f >> s >> g >> u >> d;
	graph[s] = cnt;
	if (s != g) {
		bfs(s);
		if (graph[g] > 0)
			cout << graph[g];
		else
			cout << "use the stairs";
	}
	else
		cout << "0";
	return 0;
}
