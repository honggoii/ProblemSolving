#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while (!progresses.empty()) {
        int cnt = 0;
        bool flag = false;
        while (!progresses.empty() && progresses[0] >= 100) {
            flag = true;
            //진도가 100이 넘으면
            progresses.erase(progresses.begin());//지우고
            speeds.erase(speeds.begin());
            cnt++;
        }
        
        if (flag)
            answer.push_back(cnt);

        for (int i = 0; i < progresses.size(); i++) {
            //각 작업별로 개발 속도 증가
            progresses[i] += speeds[i];
        }
    }
    
    return answer;
}
