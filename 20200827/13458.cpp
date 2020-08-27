#include <cstdio>
long long exam[1000001];//시험장
long long ans;
int main() {
	long long n;
	scanf("%lld", &n);//n개의 시험장
	for (int i = 1; i <= n; i++) {
		//각 시험장 별 응시자 수 
		scanf("%lld", &exam[i]);
	}
	long long b, c;//총, 부 감독이 감시 할 수 있는 응시자
	scanf("%lld %lld", &b, &c);
	for (int i = 1; i <= n; i++) {
		if (exam[i] > b)
			exam[i] -= b;
		else
			continue;//총감독만 있으면 됨

		if (exam[i] % c == 0) {
			ans += (exam[i] / c);
		}
		else {
			ans += (exam[i] / c) + 1;
		}
	}
	printf("%lld", ans + n);//부감독+총감독
	return 0;
}
