#include <cstdio>
int arr1[101];//양수
int arr2[101];//음수
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a >= 0)
			arr1[a]++;
		else
			arr2[a*(-1)]++;
	}
	int v;
	scanf("%d", &v);
	if (v >= 0)
		printf("%d",arr1[v]);
	else
		printf("%d", arr2[v*(-1)]);
	return 0;
}