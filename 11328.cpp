#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int arr[26];
char c1[1001];
char c2[1001];
bool flag;
int main() {
	freopen("sample.txt", "r", stdin);
	scanf("%d", &n);
	while(n--) {
		flag = true;
		fill(arr, arr + 26, 0);
		scanf(" %s", c1);
		scanf(" %s", c2);
		if (strlen(c1) != strlen(c2)) {
			flag = false;
		}
		else {
			for (int i = 0; i < strlen(c1); i++) {
				arr[c1[i] - 'a']++;
			}
			for (int i = 0; i < strlen(c2); i++) {
				arr[c2[i] - 'a']--;
				if (arr[c2[i] - 'a'] < 0) {
					flag = false;
					break;
				}
			}
		}		
		if (flag)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	return 0;
}