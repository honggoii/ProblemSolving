#include <cstdio>

int main() {
	freopen("sample.txt", "r", stdin);
	int L, A, B, C, D;
	int day = 0;
	scanf("%d %d %d %d %d", &L, &A, &B, &C, &D);

	if ((A % C == 0) && (B % D == 0)) {
		day = (A / C) > (B / D) ? (A / C) : (B / D);
	}
	else {
		day = (A / C) > (B / D) ? (A / C) : (B / D);
		if ((A % C == 0) || (B % D == 0)) {

		}
		else {
			day++;
		}
	}

	L -= day;

	if (L < 0)
		printf("0\n");
	else
		printf("%d\n", L);

	return 0;
}