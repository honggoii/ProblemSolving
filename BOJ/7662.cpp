#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int tc;
int k;
bool visit[1000001];
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &k);
		memset(visit, false, sizeof(visit));
		priority_queue<pair<int, int>> pq_des; // 내림차순
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_asc; // 오름차순
		int num = 0;
		while (k--) {
			char op;
			scanf(" %1c", &op);
			int tmp;
			if (op == 'I') {				
				scanf("%d", &tmp);
				pq_des.push({ tmp, num }); // {번호, 숫자}
				pq_asc.push({ tmp, num++ }); // {번호, 숫자}
			}
			else if (op == 'D') {
				scanf("%d", &tmp);
				if (tmp == 1) {
					// 최댓값 삭제
					while (!pq_des.empty() && visit[pq_des.top().second])
						pq_des.pop();

					if (!pq_des.empty()) {
						visit[pq_des.top().second] = true;
						pq_des.pop();
					}					
				}
				else if (tmp == -1) {
					// 최솟값 삭제
					while (!pq_asc.empty() && visit[pq_asc.top().second])
						pq_asc.pop();

					if (!pq_asc.empty()) {
						visit[pq_asc.top().second] = true;
						pq_asc.pop();
					}
				}
			}
		}

		while (!pq_des.empty() && visit[pq_des.top().second])
			pq_des.pop();
		while (!pq_asc.empty() && visit[pq_asc.top().second])
			pq_asc.pop();


		if (pq_asc.empty() || pq_des.empty()) {
			printf("EMPTY\n");
		}
		else {
			printf("%d ", pq_des.top()); // 최댓값
			printf("%d\n", pq_asc.top()); // 최솟값
		}
	}
	return 0;
}
