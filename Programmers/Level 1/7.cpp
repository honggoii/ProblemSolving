#include <string>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    deque<int> dq;
    
    while(n != 0) {
        int temp = n%3;
        dq.push_front(temp);
        n/=3;
    }
    
    int i=0;
    while(!dq.empty()) {
        int temp = dq.front();
        dq.pop_front();
        answer += temp*pow(3,i++);
    }
    
    return answer;
}
