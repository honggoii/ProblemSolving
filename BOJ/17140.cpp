#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, k;
int arr[101][101];
int time;
int rcnt = 3; // 행 개수
int ccnt = 3; // 열 개수
int num[101]; // index: 수 value: 횟수
vector<pair<int, int>> v;
void drawmap(int i, int check, int tmp) {
	int idx = 0;

	if (check == 1) {
		// R 연산
		for (int j = 1; j <= tmp; ) {
			arr[i][j++] = v[idx].second;
			arr[i][j++] = v[idx].first;
			idx++;
		}
	}
	else if (check == 2) {
		// C 연산
		for (int j = 1; j <= tmp;) {
			arr[j++][i] = v[idx].second; 
			arr[j++][i] = v[idx].first;
			idx++;
		}
	}
}
void input() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}
int main() {
	scanf("%d%d%d", &r, &c, &k);
	input(); // 처음 입력
	while (1) {
		int tmp = 0;
		if (arr[r][c] == k || time > 100)
			break;
		if (rcnt >= ccnt) {
			// R 연산
			for (int i = 1; i <= rcnt; i++) {
				memset(num, 0, sizeof(num)); // 초기화
				v.clear();
				for (int j = 1; j <= ccnt; j++) {
					num[arr[i][j]]++;// 수들의 등장 횟수 구하기
					arr[i][j] = 0;
				}
				// 벡터에 넣어주기
				for (int j = 1; j < 101; j++) {
					if (num[j] == 0) continue;
					v.push_back({ num[j], j });
				}
				sort(v.begin(), v.end());
				
				if (tmp < (v.size() * 2))
					tmp = v.size() * 2;
				// 새로운 맵 그리기
				drawmap(i, 1, v.size() * 2);
			}
			ccnt = tmp;
		}
		else {
			// C 연산
			for (int i = 1; i <= ccnt; i++) {
				memset(num, 0, sizeof(num)); // 초기화
				v.clear();
				for (int j = 1; j <= rcnt; j++) {
					num[arr[j][i]]++;// 수들의 등장 횟수 구하기
					arr[j][i] = 0;
				}

				// 벡터에 넣어주기
				for (int j = 1; j < 101; j++) {
					if (num[j] == 0) continue;
					v.push_back({ num[j], j});
				}
				sort(v.begin(), v.end());

				if (tmp < (v.size() * 2))
					tmp = v.size() * 2;
				// 새로운 맵 그리기
				drawmap(i, 2, v.size() * 2);
			}
			rcnt = tmp;
		}
		time++;
	}

	if (time <= 100)
		printf("%d", time);
	else
		printf("-1");
	return 0;
}
