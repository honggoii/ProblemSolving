#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<int> s;
vector<int> v;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		s.insert(a);
	}
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		v.push_back(*it);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	
	return 0;
}
