#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	string s = to_string(n);
	int ans = 0;
	while (1) {
		ans += (n - pow(10, s.length() - 1) + 1) * s.length();
		n = pow(10, s.length() - 1) - 1;
		s = to_string(n);

		if (n == 0)
			break;
	}
	printf("%d", ans);
	
	return 0;
}
