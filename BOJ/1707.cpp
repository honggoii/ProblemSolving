#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v[21000];
queue<int> q;
int visit[21000];
bool flag;
void bfs(int V) {
	q.push(V);
	visit[V] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int color = 0;//칠할 색

		//서로 다른 색 칠하기
		if (visit[cur] == 1)
			color = 2;
		else
			color = 1;

		for (int i = 0; i < v[cur].size(); i++) {
			if (visit[cur] != visit[v[cur][i]]) {
				if (visit[v[cur][i]] == 0)
					q.push(v[cur][i]);
				visit[v[cur][i]] = color;
			}
			else {
				flag = false;
				return;
			}
		}
	}
}
void init() {
	while (!q.empty())
		q.pop();

	for (int i = 0; i < 21000; i++) {
		v[i].clear();
	}
}
int main() {
	int k;
	scanf("%d", &k);
	while (k--) {
		memset(visit, 0, sizeof(visit));
		flag = true;
		init();//초기화

		int V, E;
		scanf("%d%d", &V, &E);

		//간선 연결
		for (int i = 0; i < E; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= V; i++) {
			if (visit[i] == 0) {
				//아직 방문안 한 정점이면
				bfs(i);
			}
		}

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
