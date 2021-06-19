#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<pair<int, int>> dq;//(값, 인덱스)

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    dq.push_back(make_pair(prices[0], 0));
    for (int i = 1; i < prices.size(); i++) {
        while (!dq.empty() && (dq.back().first > prices[i])) {
            answer[dq.back().second] = i - dq.back().second;
            dq.pop_back();
        }
        dq.push_back(make_pair(prices[i], i));
    }
    while (!dq.empty()) {
        answer[dq.front().second] = prices.size() - 1 - dq.front().second;
        dq.pop_front();
    }
    
    return answer;
}
