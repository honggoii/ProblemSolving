#include <cstdio>
#include <vector>
using namespace std;
int n;
int num[12];
int op[4];
vector<int> v;
int ansMax = -1000000000;
int ansMin = 1000000000;
void Permutation(int cnt) {
	if (cnt == n - 1) {
		//연산자 다 뽑았으면
		int ans = num[0];
		int k = 1;
		for (int i = 0; i < v.size(); i++) {
			int tmp = v[i];
			if (tmp == 0) {
				//덧셈
				ans += num[k++];
			}
			else if (tmp == 1) {
				//뺄셈
				ans -= num[k++];
			}
			else if (tmp == 2) {
				//곱셈
				ans *= num[k++];
			}
			else if (tmp == 3) {
				//나눗셈
				ans /= num[k++];
			}
		}
		if (ans > ansMax) {
			ansMax = ans;
		}
		if (ans < ansMin) {
			ansMin = ans;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;//연산자 뽑을 수 없음
		op[i] -= 1;//한 개 사용
		v.push_back(i);
		Permutation(cnt + 1);
		op[i] += 1;
		v.pop_back();
	}
}
int main() {
	scanf("%d", &n);
	//수열 입력
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	
	//연산자 입력
	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}

	Permutation(0);//순열
	printf("%d\n%d\n", ansMax, ansMin);
	return 0;
}
