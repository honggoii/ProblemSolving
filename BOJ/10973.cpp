#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n;
bool flag;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}

	while (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; i++) {
			flag = true;
			printf("%d ", v[i]);
		}
		break;
	}

	if (!flag)
		printf("-1");
	
	return 0;
}
