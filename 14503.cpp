#include <cstdio>

int arr[51][51];

int main() {
	freopen("sample.txt", "r", stdin);
	int n, m;
	int r, c, d;
	int cnt = 0;
	int flag = 0;

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (1) {
		if (arr[r][c] == 0) {
			arr[r][c] = 2;
			cnt++;
		}
		
		while (1) {
			if (d == 0) {
				if (arr[r][c - 1] == 0) {
					d = 3;
					--c;
					break;
				}
				else if ((arr[r - 1][c] > 0) && (arr[r + 1][c] > 0) &&
					(arr[r][c - 1] > 0) && (arr[r][c + 1] > 0)) {
					if (arr[r + 1][c] == 1) {
						flag = 1;
						break;
					}
					else {
						++r;
					}
				}
				else if (arr[r][c - 1] > 0) {
					d = 3;
				}
			}
			else if (d == 1) {
				if (arr[r - 1][c] == 0) {
					d = 0;
					--r;
					break;
				}
				else if ((arr[r][c + 1] > 0) && (arr[r][c - 1] > 0) &&
					(arr[r - 1][c] > 0) && (arr[r + 1][c] > 0)) {
					if (arr[r][c - 1] == 1) {
						flag = 1;
						break;
					}
					else {
						--c;
					}
				}			
				else if (arr[r - 1][c] > 0) {
					d = 0;
				}
			}
			else if (d == 2) {
				if (arr[r][c + 1] == 0) {
					d = 1;
					++c;
					break;
				}
				else if ((arr[r + 1][c] > 0) && (arr[r - 1][c] > 0) &&
					(arr[r][c - 1] > 0) && (arr[r][c + 1] > 0)) {
					if (arr[r - 1][c] == 1) {
						flag = 1;
						break;
					}
					else {
						--r;
					}
				}
				else if (arr[r][c + 1] > 0) {
					d = 1;
				}
			}
			else if (d == 3) {
				if (arr[r + 1][c] == 0) {
					d = 2;
					++r;
					break;
				}
				else if ((arr[r][c - 1] > 0) && (arr[r][c + 1] > 0) &&
					(arr[r - 1][c] > 0) && (arr[r + 1][c] > 0)) {
					if (arr[r][c + 1] == 1) {
						flag = 1;
						break;
					}
					else {
						++c;
					}
				}
				else if (arr[r + 1][c] > 0) {
					d = 2;
				}
			}
		}

		if (flag == 1)
			break;
	}

	printf("%d\n", cnt);

	return 0;
}