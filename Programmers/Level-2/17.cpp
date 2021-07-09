#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
bool prime[10000000];
int arr[7];
int temp[7];
bool visit[7];
int answer;
int sz;

void permutation(int cnt, int size) {
    if (cnt == size) {
        int num = 0;
        for (int i = 0; i < size; i++) {
            num += (pow(10, size - 1 - i) * temp[i]);
        }
        if (prime[num]) {
            prime[num] = false;//중복 방지
            answer++;
        }
        return;
    }

    for (int i = 0; i < sz; i++) {
        if (visit[i]) continue;
        if (cnt == 0 && arr[i] == 0) continue;
        visit[i] = true;
        temp[cnt] = arr[i];
        permutation(cnt + 1, size);
        visit[i] = false;
    }
}

int solution(string numbers) {
    //에라토스테네스의 체로 소수 거르기
    memset(prime, true, sizeof(prime));//false로 초기화
    prime[0] = prime[1] = false;
    for (int i = 2; i < 10000000; i++) {
        if (!prime[i]) continue;//소수가 아니면 pass
        else {
            //소수의 배수들 false
            for (int j = 2; j*i < 10000000; j++) {
                prime[i * j] = false;
            }
        }        
    }

    sz = numbers.size();
    for (int i = 0; i < sz; i++) {
        arr[i] = numbers[i] - '0';
    }

    for (int i = 1; i <= sz; i++) {
        permutation(0, i);//순열
    }
    return answer;
}
