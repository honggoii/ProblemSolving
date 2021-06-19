#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];
vector<int> v;
int ans;

bool cmp(int a, int b) {
	return a > b;
}

int main() {

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);//오름차순 정렬
	for (int i = 1; i < n; i++) {
		v.push_back(arr[i] - arr[i - 1]);
	}
	sort(v.begin(), v.end(), cmp);//내림차순 정렬

	if (k <= n) {
		for (int i = 0; i < k - 1; i++) {
			v.erase(v.begin());
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		ans += v[i];
	}
	printf("%d", ans);
	
	return 0;
}
