#include <cstdio>
char room[200][200];
int row;
int col;
int main() {
	freopen("sample.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &room[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (room[i][j] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2)
					row++;
				cnt = 0;
			}
		}
		if (cnt >= 2)
			row++;
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (room[j][i] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2)
					col++;
				cnt = 0;
			}
		}

		if (cnt >= 2) {
			col++;
		}
	}

	printf("%d %d", row, col);
	
	return 0;
}
