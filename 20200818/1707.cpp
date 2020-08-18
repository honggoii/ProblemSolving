#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int k;//테스트 케이스 개수
vector<int> node[20001];//정점 번호
int group[20001];//그룹 번호
bool visit[20001];
bool flag;
void dfs(int idx, int num) {
	visit[idx] = true;
	group[idx] = num;

	for (int i = 0; i < node[idx].size(); i++) {
		int next = node[idx][i];
		
		if (group[next] == 0) {
			if (num == 1)
				dfs(next, 2);
			else
				dfs(next, 1);
		}

		if (group[idx] == group[next]) {
			flag = false;
			return;
		}
	}
}
int main() {
	scanf("%d", &k);
	while (k--) {
		flag = true;//flag 초기화
		memset(visit, false, sizeof(visit));
		memset(node, 0, sizeof(node));
		memset(group, 0, sizeof(group));
		int v, e;//정점 개수, 간선 개수
		scanf("%d%d", &v, &e);
		for (int i = 0; i < e; i++) {//정점 연결
			int a, b;
			scanf("%d%d", &a, &b);
			node[a].push_back(b);
			node[b].push_back(a);
		}
		//dfs(1, 1);
		for (int i = 1; i <= v; i++) {//정점 탐색
			if (!visit[i]) {
			dfs(i, 1);
			}
		}

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
