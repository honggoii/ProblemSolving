#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
bool prime[1000001]; //true면 소수이면서 홀수
vector<int> v;
int main() {
	memset(prime, true, sizeof(prime));//true로 다 초기화
	prime[1] = false;

	//에라토스테네스 체로 소수 거르기
	for (int i = 2; i < 1000001; i++) {
		if (!prime[i]) continue; //소수가 아니면 pass
		if (i % 2 == 0) {
			//짝수인 홀수들도 pass
			prime[i] = false;
			continue;
		}


		//홀수이면서 소수면 자신의 배수들 다 체크
		v.push_back(i);//소수들만 담는 벡터
		for (int j = 2; i * j < 1000001; j++) {
			prime[i * j] = false;//소수가 아님
		}
	}

	while (1) {
		int n;
		int a = 0, b = 0;
		bool flag = false;
		scanf("%d", &n);
		
		if (n == 0)
			break;//종료 조건

		for (int i = 0; i < v.size(); i++) {
			if (prime[n - v[i]]) {
				flag = true;
				a = v[i];
				b = n - v[i];
				break;
			}
		}

		if (flag)
			printf("%d = %d + %d\n", n, a, b);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}
