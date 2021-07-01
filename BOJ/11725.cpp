#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[100001];
int parent[100001];
bool visited[100001];

void dfs(int node) {
	visited[node] = true;

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i]; // 자식
		if (!visited[next]) {
			parent[next] = node;
			dfs(next);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	parent[1] = 1; // 1은 루트 
	dfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}

	return 0;
}
