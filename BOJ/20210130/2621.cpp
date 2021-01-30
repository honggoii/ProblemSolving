#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int color[4];//R, Y, B, G
int number[10];
bool isContinue = true;//연속적인지
bool fiveColor;//색 5개인지
bool threeColor;//색 3개인지
int fourValue;//4개가 같은 값
int threeValue;//3개가 같은 값
int twoValue;//2개가 같은 값
int value;
int two[2];
int j;
int ans;

void numCnt() {
	for (int i = 1; i < 10; i++) {
		if (number[i] == 4) {
			fourValue++;
			value = i;
		}
		else if (number[i] == 3) {
			threeValue++;
			value = i;
		}
		else if (number[i] == 2) {
			twoValue++;
			two[j++] = i;
		}
	}
}

void colorCnt() {
	for (int i = 0; i < 4; i++) {
		if (color[i] == 5) {
			fiveColor = true;
			break;
		}			
		else if (color[i] == 3) {
			threeColor = true;
			break;
		}			
	}
}

void continous() {
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - v[i - 1] != 1) {
			isContinue = false;
			break;
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		char c;
		int a;
		scanf(" %1c %d", &c, &a);

		switch (c) {
		case 'R': color[0]++; break;
		case 'Y': color[1]++; break;
		case 'B': color[2]++; break;
		case 'G': color[3]++; break;
		}

		number[a]++;

		v.push_back(a);
	}
	sort(v.begin(), v.end());//수 오름차순 정렬
	continous();//연속적인 수인지 판단
	colorCnt();//같은 색이 몇인지 판단
	numCnt();//같은 숫자 몇개인지 판단
	sort(two, two + 2);

	if (fiveColor && isContinue) {
		ans = 900 + v[4];
	}
	else if (fourValue == 1) {
		ans = 800 + value;
	}
	else if ((threeValue == 1) && (twoValue == 1)) {
		ans = (value * 10) + two[1] + 700;
	}
	else if (fiveColor) {
		ans = 600 + v[4];
	}
	else if (isContinue) {
		ans = 500 + v[4];
	}
	else if (threeValue == 1) {
		ans = 400 + value;
	}
	else if (twoValue == 2) {
		ans = (two[0] + 300) + (two[1] * 10);
	}
	else if (twoValue == 1) {
		ans = 200 + two[1];
	}
	else {
		ans = 100 + v[4];
	}

	printf("%d", ans);
	return 0;
}
