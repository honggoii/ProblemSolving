#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<string> v;
bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0] << "\n";
	for (int i = 1; i < n; i++) {
		if (v[i-1] != v[i])
			cout << v[i] << "\n";
	}
	
	return 0;
}
