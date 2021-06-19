#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<int> station[3100];
bool visit[3100];
bool circular[3100];
queue<pair<int, int>> q;//{역, 거리}
int n;
int bfs(int cur) {
	q.push({ cur, 0 });
	visit[cur] = true;
	int cnt = 0;

	while (!q.empty()) {
		int cur = q.front().first; 
		cnt = q.front().second;
		q.pop();

		if (circular[cur])
			return cnt;

		for (int i = 0; i < station[cur].size(); i++) {
			if (!visit[station[cur][i]]) {
				q.push({ station[cur][i], cnt + 1 });
				visit[station[cur][i]] = true;
			}
		}
	}
}
void check(int cur, int target, int dep) {
	if (cur == target && dep >= 2) {
		//현재 역이 check 함수를 시작한 역(target)이고
		//2번 이상 깊이가 들어 갔으면
		circular[cur] = true;//순환선 확정
		return;
	}
	
	visit[cur] = true;

	for (int i = 0; i < station[cur].size(); i++) {
		if (!visit[station[cur][i]])
			check(station[cur][i], target, dep + 1);//방문 안 했으면 깊이 1 증가
		else if (station[cur][i] == target && dep >= 2)
			check(station[cur][i], target, dep);//방문 했던 적 있으면 깊이 증가 시키지 않음
	}
}
void connect() {
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		station[a].push_back(b);
		station[b].push_back(a);
	}
}
int main() {
	scanf("%d", &n);
	connect();//역 연결
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		check(i, i, 0);//순환선 체크
	}
	
	for (int i = 1; i <= n; i++) {
		if (circular[i]) {
			//순환선이면 거리 0
			printf("0 ");
			continue;
		}
		memset(visit, false, sizeof(visit));
		while (!q.empty())
			q.pop();
		printf("%d ", bfs(i));//각 역마다 순환선 거리 체크
	}
	return 0;
}
