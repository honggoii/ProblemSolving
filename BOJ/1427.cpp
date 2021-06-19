#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string s;
vector<int> v;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i] - '0');
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
	}
	return 0;
}
