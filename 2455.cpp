#include <cstdio>

int main() {
	freopen("sample.txt", "r", stdin);
	int out, in;
	int max = 0;
	int people = 0;

	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &out, &in);
		people -= out;
		people += in;

		if (max < people)
			max = people;
	}	

	printf("%d\n", max);
	return 0;
}