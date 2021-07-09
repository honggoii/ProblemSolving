#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
priority_queue<int> pq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;
    int last = 0;
    for (int i = 0; i < operations.size(); i++) {
        int sz = operations[i].size();
        priority_queue<int> pq2;
        if (operations[i][0] == 'I') {
            string s = operations[i].substr(2, sz - 1);//숫자 추출
            int num = stoi(s);//string -> int
            pq.push(num);
        }
        else if ((operations[i][0] == 'D') && (!pq.empty())) {
            if (operations[i].size() == 3) {
                //D 1의 길이는 3
                //최댓값 삭제
                pq.pop();
            }
            else {
                //D -1의 길이는 4
                int cnt = pq.size() - 1;
                while (cnt--) {
                    pq2.push(pq.top());
                    pq.pop();  
                }
                pq.pop();
                pq = pq2;
            }
        }
    }

    if (pq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if ((pq.size() == 1) && (pq.top() < 0)) {
        answer.push_back(0);
        answer.push_back(pq.top());
    }
    else {
        answer.push_back(pq.top());
        while (pq.size()>1) {
            pq.pop();
        }
        answer.push_back(pq.top());
    }
        
    return answer;
}
