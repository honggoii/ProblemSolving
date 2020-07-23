#include <cstdio>
int card[22] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
int cnt = 10;
int a, b;
int time;
int main() {
	while (cnt--) {
		scanf("%d%d", &a, &b);
		time = (b - a) / 2 + 1;
		for (int i = 0; i < time; i++) {
			int tmp = card[a];
			card[a] = card[b];
			card[b] = tmp;
			a++; b--;
		}
	}
	for (int i = 1; i < 21; i++) {
		printf("%d ", card[i]);
	}
	return 0;
}