#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, d1, d2;
int map[21][21]; // map
int district[21][21]; // 1번 ~ 5번구
int population[6]; // 1번 ~ 5번구 인구수
int total; // 전체 인구수
int ans =  1e9; // 정답
void drawBoundary(int x, int y, int d1, int d2) {
	for (int i = 0; i <= d1; i++) {
		district[x + i][y - i] = 5;
		district[x + d2 + i][y + d2 - i] = 5;
	}

	for (int i = 0; i <= d2; i++) {
		district[x + i][y + i] = 5;
		district[x + d1 + i][y - d1 + i] = 5;
	}
}
void districtDivide(int x, int y, int d1, int d2) {
	
	drawBoundary(x, y, d1, d2);// 경계선 그리기

	// 1번구 1 ≤ r < x+d1, 1 ≤ c ≤ y
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (district[i][j] == 5) break;
			district[i][j] = 1;
			population[1] += map[i][j];
		}
	}

	// 2번구 1 ≤ r ≤ x+d2, y < c ≤ N
	for (int i = 1; i <= x + d2; i++) {
		for (int j = n; j >= y + 1; j--) {
			if (district[i][j] == 5) break;
			district[i][j] = 2;
			population[2] += map[i][j];
		}
	}

	// 3번구 x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
	for (int i = n; i >= x + d1; i--) {
		for (int j = 1; j < y - d1 + d2; j++) {
			if (district[i][j] == 5) break;
			district[i][j] = 3;
			population[3] += map[i][j];
		}
	}

	// 4번구  x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
	for (int i = n; i > x + d2; i--) {
		for (int j = n; j >= y - d1 + d2; j--) {
			if (district[i][j] == 5) break;
			district[i][j] = 4;
			population[4] += map[i][j];
		}
	}
}

bool checkBoundary(int x, int y, int d1, int d2) {
	if (x + d1 > n || y - d1 < 1) return false;
	if (x + d2 > n || y + d2 > n) return false;
	if (x + d1 + d2 > n || y - d1 + d2 > n) return false; 

	return true;
}

void initdsitrict() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			district[i][j] = 0;
		}
	}
}

void calc() {
	// d1과 d2선정
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; d1 <= n - x; d1++) {
				for (int d2 = 1; d2 <= n - y; d2++) {
					// 경계선 구할 수 있는지 확인
					if (checkBoundary(x, y, d1, d2)) {
						initdsitrict();// district 초기화
						memset(population, 0, sizeof(population));// population 초기화
						districtDivide(x, y, d1, d2);// 5개 구로 나누기
						population[5] = total - (population[1] + population[2] + population[3] + population[4]);// 5번 구 인구수 구하기
						sort(population + 1, population + 6);
						int tmp = population[5] - population[1];
						if (ans > tmp)
							ans = tmp;
					}
				}
			}
		}
	}
}

void input() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			total += map[i][j];
		}
	}
}

int main() {
	scanf("%d", &n); // 크기 입력
	input();// 맵 입력
	calc();// 완탐으로 인구 차이 구하기
	printf("%d", ans);
	return 0;
}
