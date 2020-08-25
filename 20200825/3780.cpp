#include <cstdio>
#include <cmath>
using namespace std;
int n;
typedef struct {
	int p;//통솔자
	int dis;//거리
} DATA;
DATA info[20001];
int find(int u) {
	if (info[u].p == u)
		return u;//통솔자가 본인이면
	int temp = find(info[u].p);//통솔자 찾으러
	info[u].dis += info[info[u].p].dis;
	info[u].p = temp;//통솔자 갱신
	return temp;
}
void merge(int u, int v) {
	info[u].dis = abs(u - v) % 1000;//거리를 저장하고
	info[u].p = v;//연결
}
void pInit() {
	for (int i = 1; i <= n; i++) {
		info[i].p = i;
		info[i].dis = 0;
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);//기업 수
		pInit();//통솔자 초기화
		while (1) {
			char c;
			scanf(" %c", &c);
			if (c == 'O')
				break;//그만
			else if (c == 'E') {
				//거리 출력
				int a;
				scanf("%d", &a);
				find(a);
				printf("%d\n", info[a].dis);
			}
			else if (c == 'I') {
				//연결
				int a, b;
				scanf("%d%d", &a, &b);
				merge(a, b);
			}
		}
	}
	return 0;
}
