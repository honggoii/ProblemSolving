#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
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
int ans = 1e9;
int WhiteCheck(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x+8; i++) {
		for (int j = y; j < y+8; j++) {
			if (white[i-x][j-y] != board[i][j])
				cnt++;
		}
	}
	return cnt;
}
int BlackCheck(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (black[i-x][j-y] != board[i][j])
				cnt++;
		}
	}
	return cnt;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			ans = min(ans, min(WhiteCheck(i, j), BlackCheck(i, j)));
		}
	}
	printf("%d", ans);
	return 0;
}
