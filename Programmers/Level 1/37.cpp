#include <string>
#include <vector>

using namespace std;
bool isPrime[1000000];

int solution(int n) {
    int answer = 0;
    for (int i=2; i<=n; i++) {
        if (isPrime[i]) continue;
        else {
            answer++;
            for (int j=2; j*i<=n; j++) {
                isPrime[i*j] = true;
            }
        }
    }
    return answer;
}
