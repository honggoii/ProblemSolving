#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int,int>>, compare> pq;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a < b;
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(), cmp);//요청시간 오름차순정렬
    pair<int, int> now = { jobs[0][0], jobs[0][1] };//현재 요청중인 애
    int time = now.first;//전체시간
    int check = 0;//소요시간 check
    int idx = 1;
    int num = 0;//계산횟수
    while (1) {
        while ((idx < jobs.size()) && (time == jobs[idx][0])) {
            pq.push({ jobs[idx][0],jobs[idx][1] });
            idx++;
        }

        if ((check == now.second)) {
            answer += now.second;
            if (!pq.empty()) {
                //큐가 비어있지 않으면
                now = { pq.top().first, pq.top().second }; //그 다음으로 now 초기화
                pq.pop();
                answer += (time - now.first);
            }
            else {
                //큐가 비어있으면
                if (idx < jobs.size()) {
                    now = { jobs[idx][0],jobs[idx][1] };
                    idx++;
                }                
            }
            check = 0;//초기화
            num++;
        }

        if (jobs.size() == num)
            break; //처리다했으면 탈출

        time++; check++;//시간이 흐른다
    }
    
    answer /= jobs.size();//평균구하기

    return answer;
}
