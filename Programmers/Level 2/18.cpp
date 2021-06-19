#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int num = brown + yellow;
    vector<int> v;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            v.push_back(i);
    }
    int sz = v.size();
    int j = 1;
    bool flag = true;
    for (int i = (sz / 2); i <= sz; i++) {
        if ((sz % 2 != 0) && flag) {
            // 홀수면
            if (((v[i] - 2) * (v[i] - 2)) == yellow) {
                answer.push_back(v[i]);
                answer.push_back(v[i]);
                break;
            }
            flag = false;
        }
        else {
            if (((v[i] - 2) * (v[i - j] - 2)) == yellow) {
                answer.push_back(v[i]);
                answer.push_back(v[i - j]);
                break;
            }
            j += 2;
        }
    }
    
    return answer;
}
