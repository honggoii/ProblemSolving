#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i < n; i++) {
        int sum = i;
        for (int j = i+1; j < n; j++) {
            sum += j;
            if (sum == n) {
                answer++;
                break;
            }
            else if (sum > n) {
                break;
            }
        }
    }
    answer++;//자기 자신
    
    return answer;
}
