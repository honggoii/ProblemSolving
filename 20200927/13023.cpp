#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[2011];
bool visit[2011];
int n, m;
bool flag;
void dfs(int node, int cnt) {
	visit[node] = true;
	if (cnt == 4) {
		flag = true;
		return;
	}	
		
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visit[next]) 
			dfs(next, cnt+1);
	}
	visit[node] = false;
}
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		//memset(visit, false, sizeof(visit));
		if(!visit[i])
			dfs(i, 0);
		if (flag)
			break;
	}
	if (flag)
		printf("1");
	else
		printf("0");
	return 0;
}
