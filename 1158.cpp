#include <iostream>
#include <list>
using namespace std;
int n, k;
list<int> L;
list<int>::iterator cur = L.begin();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		L.insert(cur, i);//insert의 첫번째 원소 type은 iterator
	}

	printf("<");
	while (L.size() != 1){
		for (int i = 1; i < k; i++) {
			int tmp = L.front();
			L.pop_front();
			L.push_back(tmp);
		}
		printf("%d, ", L.front());
		L.pop_front();
	}
	printf("%d>", L.front());
	return 0;
}