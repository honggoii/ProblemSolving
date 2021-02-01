#include <cstdio>
int ans;
char map[51][51];
int n;
void col() {
	for (int i = 0; i < n; i++) {
		int cnt = 1;//열별로 검사
		for (int j = 1; j < n; j++) {
			if (map[i][j] == map[i][j - 1]) {
				cnt++;
			}
			else {
				if (ans < cnt)
					ans = cnt;
				cnt = 1;
			}
		}
		if (ans < cnt)
			ans = cnt;
	}
}
void row() {
	for (int j = 0; j < n; j++) {
		int cnt = 1;//행별로 검사
		for (int i = 1; i < n; i++) {
			if (map[i][j] == map[i - 1][j]) {
				cnt++;
			}
			else {
				if (ans < cnt)
					ans = cnt;
				cnt = 1;
			}
		}
		if (ans < cnt)
			ans = cnt;
	}
}
void init() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
}
int main() {
	init();//map 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			row();
			col();
			//왼쪽이랑 다르면
			if ((j!= 0) && map[i][j] != map[i][j - 1]) {
				char temp = map[i][j];
				map[i][j] = map[i][j - 1];
				map[i][j - 1] = temp;
				row();//행마다 최댓값
				col();//열마다 최댓값
				//원위치
				temp = map[i][j];
				map[i][j] = map[i][j - 1];
				map[i][j - 1] = temp;
			}
			//위랑 다르면
			if ((i!= 0) &&map[i][j] != map[i - 1][j]) {
				char temp = map[i][j];
				map[i][j] = map[i - 1][j];
				map[i - 1][j] = temp;
				row();//행 체크
				col();//열 체크
				//원위치
				temp = map[i][j];
				map[i][j] = map[i - 1][j];
				map[i - 1][j] = temp;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
