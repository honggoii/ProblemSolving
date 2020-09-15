#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= sqrt(n); i++) {
		if (i == sqrt(n)) {
			v.push_back(i);
		}
		else if (n % i == 0) {
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	sort(v.begin(), v.end());
	if (v.size() < k)
		printf("0");
	else
		printf("%d", v.at(k-1));

	return 0;
}
