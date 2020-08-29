#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int n;
int arr[12];
int op[4];//+ - * /
int ansMin = 1000000000;
int ansMax = -1000000000;
void permutation(int cnt) {
	if (cnt == n - 1) {
		int ans = arr[0];
		int j = 1;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) {
				//덧셈
				ans += arr[j];
			}
			else if (v[i] == 1) {
				//뺄셈
				ans -= arr[j];
			}
			else if (v[i] == 2) {
				//곱셈
				ans *= arr[j];
			}
			else if (v[i] == 3) {
				//나눗셈
				ans /= arr[j];
			}
			j++;
		}
		if (ansMax < ans)
			ansMax = ans;
		if (ans < ansMin)
			ansMin = ans;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;//다 뽑았으면
		op[i]--;
		v.push_back(i);
		permutation(cnt + 1);
		v.pop_back();
		op[i]++;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &op[i]);//연산자 개수
	permutation(0);//순열
	printf("%d\n%d", ansMax, ansMin);
	return 0;
}
