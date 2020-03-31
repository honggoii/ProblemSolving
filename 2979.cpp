#include <cstdio>
#include <algorithm>

using namespace std;

int arr[101];

int main() {
	freopen("sample.txt", "r", stdin);
	int a, b, c;
	int in, out;
	int max = 0;
	int fee = 0;
	scanf("%d %d %d", &a, &b, &c);

	for (int i = 1; i <= 3; i++) {
		scanf("%d %d", &in, &out);
		if (max < out)
			max = out;
		for (int j = in; j < out; j++) {
			arr[j]++;
		}
	}

	for (int i = 1; i <= max; i++) {
		if (arr[i] == 1) {
			fee += a;
		}
		else if (arr[i] == 2) {
			fee += 2 * b;
		}
		else if (arr[i] == 3) {
			fee += 3 * c;
		}
	}

	printf("%d\n", fee);

	return 0;
}