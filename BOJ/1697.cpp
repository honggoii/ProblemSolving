#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
queue<int> q;
int visit[100001];
bool range(int nxt) {
	return nxt >= 0 && nxt <= 100000;
}
int n, k;
void bfs(int n) {
	q.push(n);
	visit[n] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		
		if (cur == k)
			return;

		if (range(cur - 1) && visit[cur - 1] == -1) {
			visit[cur - 1] = visit[cur] + 1;
			q.push(cur - 1);
		}
		if (range(cur + 1) && visit[cur + 1] == -1) {
			visit[cur + 1] = visit[cur] + 1;
			q.push(cur + 1);
		}
		if (range(cur * 2) && visit[cur * 2] == -1) {
			visit[cur * 2] = visit[cur] + 1;
			q.push(cur * 2);
		}
	}
}
int main() {
	memset(visit, -1, sizeof(visit));
	scanf("%d%d", &n, &k);
	bfs(n);
	printf("%d", visit[k]-1);
	
	return 0;
}
