#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> vec[1001];//(node, 비용)
bool visit[1001];
int cost[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, m;
int st, des;//시작, 종점
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		vec[a].push_back({ w, b });
	}
	scanf("%d%d", &st, &des);
	pq.push({ 0, st});
	while (1) {
		int cur = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if (visit[cur]) continue;
		
		visit[cur] = true;
		cost[cur] = w;

		if (cur == des)
			break;//탈출 조건

		for (int i = 0; i < vec[cur].size(); i++) {
			int node = vec[cur][i].second;
			int c = vec[cur][i].first;

			pq.push({ cost[cur]+c, node });
		}
	}
	printf("%d", cost[des]);
	
	return 0;
}
