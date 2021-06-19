#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		int tmp;
		scanf("%d", &tmp);

		if (tmp == 0) {
			if (pq.empty()){
                printf("0\n");
            }
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(tmp);
		}
	}

	return 0;
}
