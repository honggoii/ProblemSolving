#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
bool prime[1004001];
int ans;

int main() {
	memset(prime, true, sizeof(prime));
	int n;
	scanf("%d", &n);
	prime[0] = prime[1] = false;
	for (int i = 2; i < 1004001; i++) {
		if (!prime[i]) continue;
		else {
			prime[i] = true;
			for (int j = 2; j * i < 1004001; j++)
				prime[i * j] = false;
		}
	}
	
	for (int i = n; i < 1004001; i++) {
		if (prime[i]) {
			string s = to_string(i);
			int sz = s.size() / 2;
			int j = s.length() - 1;
			int cnt = 0;
			for (int i = 0; i < sz; i++) {
				if (s[i] == s[j]) {
					cnt++;
					j--;
				}
				else
					break;
			}

			if (cnt == sz) {
				ans = i;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
