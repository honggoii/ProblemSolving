#include <cstdio>
int man[7];
int woman[7];
int n, k;
int s, g;//성별, 학년
int room;
int main() {
	scanf("%d%d", &n, &k);
	while (n--) {
		scanf("%d%d", &s, &g);
		if (s)
			man[g]++;
		else
			woman[g]++;
	}
	for (int i = 1; i <= 6; i++) {
		if (man[i] % k == 0)
			room += man[i] / k;
		else
			room += man[i] / k + 1;
		if (woman[i] % k == 0)
			room += woman[i] / k;
		else
			room += woman[i] / k + 1;
	}
	printf("%d", room);
	return 0;
}