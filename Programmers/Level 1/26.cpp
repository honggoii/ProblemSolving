#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if (m < n){
        //n이 무조건 작은 수
        int temp = n;
        n = m;
        m = temp;
    }
    
    for (int i = n; i > 0; i--) {
        if((n%i==0) && (m%i==0)){
            answer.push_back(i);
            answer.push_back(i*(n/i)*(m/i));
            break;
        }
    }
    
    
    return answer;
}
