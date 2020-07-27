#include <cstdio>
#include <cstring>
char c1[1001];
char c2[1002];
int arr[26];
int res;
int main() {
	scanf(" %s", c1);
	scanf(" %s", c2);
	for (int i = 0; i < strlen(c1); i++) {
		arr[c1[i] - 'a']++;
	}
	for (int i = 0; i < strlen(c2); i++) {
		arr[c2[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] < 0)
			res += arr[i] * (-1);
		else
			res += arr[i];
	}
	printf("%d", res);
	return 0;
}