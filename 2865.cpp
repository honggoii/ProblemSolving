#include <cstdio>
#include <algorithm>

double arr[101];

using namespace std;

bool cmp(double a, double b) {
	return a > b;
}


int main() {
	freopen("sample.txt", "r", stdin);

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	while (m--) {
		int num;
		double abl;

		for (int i = 0; i < n; i++) {
			scanf("%d%lf", &num, &abl);

			if (arr[num-1] < abl) {
				arr[num-1] = abl;
			}
		}
		
	}

	sort(arr, arr + n, cmp);

	double sum = 0.0;

	for (int i = 0; i < k; i++) {
		sum += arr[i];
	}

	printf("%.1f\n", sum);


	return 0;
}