#include <iostream>
#include <cstring>
#include <string>
using namespace std;
bool prime[2000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < 2000001; i++) {
		if (!prime[i]) continue;
		else {
			for (int j = 2; i * j < 2000001; j++) {
				prime[i * j] = false;
			}
		}
	}

	string s = "";
	for (int i = n; i < 2000001; i++) {
		int cnt = 0;
		s = to_string(i);
		if (prime[i]) {			
			int k = s.length() - 1;
			for (int j = 0; j < (s.length() / 2); j++) {
				if (s[j] == s[k]) {
					cnt++;
					k--;
				}
				else {
					break;
				}
			}
			if (cnt == s.length() / 2) {
				break;
			}
		}		
	}
	cout << stoi(s);
	return 0;
}
