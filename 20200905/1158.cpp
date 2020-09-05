#include <cstdio>
#include <queue>
using namespace std;
queue<int> q;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	printf("<");
	int qsize = q.size();
	for (int i = 0; i < qsize - 1; i++) {
		for (int j = 0; j < k - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>",q.front());
	return 0;
}
