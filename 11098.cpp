#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int,string> b) {
	return a > b;
}

int main() {
	freopen("sample.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	while (n--) {
		int p;
		scanf("%d", &p);
		v.clear();

		for (int i = 0; i < p; i++) {
			int c;
			string name;
			cin >> c >> name;
			v.push_back(make_pair(c,name));
		}

		sort(v.begin(), v.end(), cmp);

		cout << v[0].second << endl;
	}

	return 0;
}