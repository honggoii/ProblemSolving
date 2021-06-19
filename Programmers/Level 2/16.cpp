#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int sz = scoville.size();
    for (int i = 0; i < sz; i++)
            pq.push(scoville[i]);//우선순위 큐에 넣는다.

        while (1) {
            int temp1 = pq.top(); pq.pop();
            int temp2 = 0;
            if (pq.empty()) {
                answer = -1;
                break;
            }
            else {
                temp2 = pq.top(); pq.pop();
                int temp = temp1 + (temp2 * 2);//공식
                pq.push(temp);//결과 넣기
                answer++;
            }              

            if (pq.top() >= K)
                break;
        }
    
    return answer;
}
