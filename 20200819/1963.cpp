#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
int tc;//test case
bool prime[10000];//소수(true), 소수 아니면(false)
int visit[10000];
int num[4];//네자릿수
int a, b;//a -> b
int ans;
void bfs(int a) {
	queue<int> q;
	q.push(a);
	visit[a] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int idx = 3;//일의 자리부터 숫자 넣으려고
		if (cur == b) {
			ans = visit[cur] - 1;
			return;
		}
		int temp = cur;
		while (1) {//천, 백, 십, 일 자릿수 구해서 
			num[idx--] = temp % 10;
			temp /= 10;
			if (idx == -1)
				break;
		}
		for (int i = 0; i < 4; i++) {
			//천,백,십,일 자릿수에
			//다른 숫자를 넣어보고
			for (int j = 0; j < 10; j++) {
				//if (num[i] == j) continue;//같은 수면 하지말자
				if (i == 0 && j == 0) continue;//천의 자리숫자에는 0이 못오니까
				int next = 0;//임시 숫자
				for (int k = 0; k < 4; k++) {
					if (i == k)
						next += j * pow(10, 3 - k);
					else
						next += num[k] * pow(10, 3 - k);
				}

				//소수인지 판별
				if (prime[next] && visit[next] == 0) {
					visit[next] = visit[cur] + 1;
					q.push(next);
				}
			}
		}
	}
}
int main() {
	scanf("%d", &tc);
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;//소수가 아님
	for (int i = 2; i < 10000; i++) {
		if (prime[i]) { //소수면
			for (int j = 2; j * i < 10000; j++) {
				prime[i * j] = false; //소수의 배수들은 소수가 아님
			}
		}
		
	}
	while (tc--) {
		ans = -1;
		memset(visit, 0, sizeof(visit));
		scanf("%d%d", &a, &b);

		bfs(a);
		if (ans == -1)
			printf("Impossible\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
