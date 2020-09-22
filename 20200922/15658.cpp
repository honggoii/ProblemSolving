#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int op[4];//+,-,*,/ 수
int arr[22];
int n;
int ansMax = -1000000000;//최대값
int ansMin = 1000000000;//최소값
void per(int cnt) {
	if (cnt == n - 1) {
		int temp = arr[0];//결과값
		int j = 1;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) {
				//덧셈
				temp += arr[j];
			}
			else if (v[i] == 1) {
				//뺄셈
				temp -= arr[j];
			}
			else if (v[i] == 2) {
				//곱셈
				temp *= arr[j];
			}
			else if (v[i] == 3) {
				//나눗셈
				temp /= arr[j];
			}
			j++;
		}
	
		if (temp > ansMax)
			ansMax = temp;
		if (temp < ansMin)
			ansMin = temp;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0)continue;
		op[i]--;
		v.push_back(i);
		per(cnt + 1);
		v.pop_back();
		op[i]++;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);//피연산자
	for (int i = 0; i < 4; i++)
		scanf("%d", &op[i]);//연산자 개수
	per(0);
	printf("%d\n", ansMax);
	printf("%d\n", ansMin);
	return 0;
}
