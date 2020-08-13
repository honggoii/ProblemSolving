#include <cstdio>
#include <deque>
using namespace std;
int n, m;
deque<int> dq;
int arr[51];
int cnt;
int idx;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr[i]);
	}
	int j = 0;
	while (arr[j]) {
		if (dq.front() == arr[j]) {
			dq.pop_front();
			j++;
			continue;
		}
		
		for (int i = 0; i < dq.size(); i++) {
			if (dq.at(i) == arr[j])
				idx = i;
		}

		if (idx <= (dq.size() / 2)) {
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}
		else {
			dq.push_front(dq.back());
			dq.pop_back();
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
