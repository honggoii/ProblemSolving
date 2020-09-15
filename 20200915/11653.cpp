#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
void primeFac(int n) {
	if (n == 1)
		return;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
			primeFac(n / i);
			return;
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	primeFac(n);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
	return 0;
}
