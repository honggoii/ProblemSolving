#include <cstdio>
#include <cmath>
int n;//지도 길이
int l;//경사로 길이
int map[102][102];
int map2[102][102];
int ans;
bool road(int a[][102], int x, int y) {
	int temp = a[x][y + 1];
	for (int i = y + 1; i < y + 1 + l; i++) {
		//경사로 길이만큼 설치할 수 있는지
		if (a[x][i] != temp)
			return false;
	}
	return true;
}
void findRoad(int a[][102]) {

	for (int i = 1; i <= n; i++) {
		int load = 1;
		bool flag = true;
		for (int j = 1; j <= n - 1; j++) {
			if (abs(a[i][j] - a[i][j + 1]) > 1) {
				flag = false;
				break;// 높이차가 2이상이면 볼 것도 없음
			}

			if (a[i][j] == a[i][j + 1])
				load++;//높이가 같은 경우 일단 설치
			else if (a[i][j] == a[i][j + 1] + 1) {
				//내가 다음보다 높은 경우(내리막)

				//경로를 설치할 수 있는지 확인
				if (road(a, i, j)) {//설치할 수 있으면
					j = j + l - 1;
					load = 0;
				}
				else {//설치할 수 없으면
					flag = false;
					break;
				}
			}
			else if (a[i][j] + 1 == a[i][j + 1]) {
				//내가 다음보다 낮은 경우(오르막)
				if (l > load) {
					//예비로 설치한 길이 경사로 길이보다 작으면 설치 불가
					flag = false;
					break;
				}
				else
					load = 1;//초기화
			}
		}

		if (flag)
			ans++;//길 가능
	}
}
void check() {
	findRoad(map);//행
	findRoad(map2);//열
}
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			map2[j][i] = map[i][j];//행,열 바꾸기
		}
	}
}
int main() {
	scanf("%d%d", &n, &l);
	init();//맵 초기화
	check();//행,열 검사
	printf("%d", ans);
	return 0;
}
