#include <cstdio>
int arr[26];
int main() {
	char s[101];
	scanf(" %s", &s);

	for (int i = 0; ; i++) {
		if (s[i] == '\0')
			break;
		arr[s[i] - 97]++;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);

	return 0;
}