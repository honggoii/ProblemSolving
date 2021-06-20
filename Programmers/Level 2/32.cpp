#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
        
    for(int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!pq.empty()) {
        if (pq.top() == q.front().second) {
            answer++;
            if (q.front().first == location) {
                break;
            }
            else {
                pq.pop();
                q.pop();
            }   
        }
        else {
            //answer++;
            q.push(q.front());
            q.pop(); 
        }              
    }
    
    return answer;
}
