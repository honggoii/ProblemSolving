#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> v[1100];
vector<int> tmp;
vector<int> ans;
int indegree[1100];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		tmp.clear();
		for (int i = 0; i < a; i++) {
			int b;
			scanf("%d", &b);
			tmp.push_back(b);
		}

		for (int i = 1; i < a; i++) {
			v[tmp[i - 1]].push_back(tmp[i]);
			indegree[tmp[i]]++;
		}
	}

	//inegree 0인애들 넣기
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (int i = 0; i < v[cur].size(); i++) {
			indegree[v[cur][i]]--;
			if (indegree[v[cur][i]] == 0)
				q.push(v[cur][i]);
		}
		cnt++;
	}

	if (cnt == n) {
		for (int i = 0; i < ans.size(); i++) {
			printf("%d\n", ans[i]);
		}
	}
	else {
		printf("0");
	}
	return 0;
}
