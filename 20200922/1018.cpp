#include <cstdio>
#include <algorithm>
using namespace std;
char board[61][61];
char white[9][9] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};
char black[9][9] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};
int checkwhite(int x, int y) {
	int res = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (board[i][j] != white[i-x][j-y])
				res++;
		}
	}
	return res;
}
int checkblack(int x, int y) {
	int res = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (board[i][j] != black[i-x][j-y])
				res++;
		}
	}
	return res;
}
int ans = 1e9;
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			ans = min(ans, min(checkwhite(i, j), checkblack(i, j)));
		}
	}
	printf("%d", ans);
	return 0;
}
