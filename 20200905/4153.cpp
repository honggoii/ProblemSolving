#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[3];
bool cmp (int a, int b) {
	return a > b;
}
int main() {
	while (1) {
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] == 0)
				cnt++;
		}
		if (cnt == 3)
			return 0;//종료 조건

		sort(arr, arr + 3, cmp);
		if (pow(arr[0], 2) == pow(arr[1], 2) + pow(arr[2], 2))
			printf("right\n");
		else
			printf("wrong\n");
	}
}
