#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}

	if (next_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; i++) {
			printf("%d ", v[i]);
		}
	}
	else {
		printf("-1");
	}
	
	return 0;
}
