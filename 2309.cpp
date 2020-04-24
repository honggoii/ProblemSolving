#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10];

int main() {
	freopen("sample.txt", "r", stdin);
	int sum = 0;
	int lie1, lie2;

	for (int i = 1; i <= 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	for (int i = 1; i <= 9; i++) {
		int lie = arr[i]; // °ÅÁþ ³­ÀïÀÌ
		for (int j = i+1; j <= 9; j++) {
			lie += arr[j];
			if ((sum - lie) == 100) {
				lie1 = arr[i];
				lie2 = arr[j];
				break;
			}
			else {
				lie = arr[i];
			}
		}			
	}

	sort(arr, arr + 10);

	for (int i = 1; i <= 9; i++) {
		if ((arr[i] == lie1) || arr[i] == lie2)
			continue;
		printf("%d\n", arr[i]);
	}
	return 0;
}