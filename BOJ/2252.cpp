#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[32100];
queue<int> q;
int indegree[32100];//각 vertex의 indegree 계산
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	//1. 각 vertex의 현재 indegree 저장
	for (int i = 0; i < m; i++) {
		int a, b;//a->b
		scanf("%d%d", &a, &b);
		v[a].push_back(b);//연결
		indegree[b]++;//b에는 indegree가 1 증가
	}

	//2. indegree가 0인 vertex모두 enqueue
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		printf("%d ", cur);
		for (int i = 0; i < v[cur].size(); i++) {
			indegree[v[cur].at(i)]--;//indegree 1감소
			if (indegree[v[cur].at(i)] == 0) {
				q.push(v[cur].at(i));//indegree가 0이면 enqueue
			}
		}
	}
	return 0;
}
