#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> v;
int main() {
	int tc;
	scanf("%d", &tc);
	string s;
	getline(cin, s);
	while (tc--) {
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ')
				v.push_back(s[i]);
			else {
				for (int j = v.size() - 1; j >= 0; j--) {
					cout << v[j];
				}
				cout << ' ';
				v.clear();
			}			
		}
		for (int j = v.size() - 1; j >= 0; j--) {
			cout << v[j];
		}
		cout << ' ';
		v.clear();
		cout << "\n";
	}
	return 0;
}
