#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<pair<int, int>> dq;//(값, 인덱스)
vector<pair<int, int>> v;//(인덱스, 답)

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    dq.push_back(make_pair(prices[0], 0));
    for (int i = 1; i < prices.size(); i++) {
        while (!dq.empty() && (dq.back().first > prices[i])) {
            v.push_back(make_pair(dq.back().second, i - dq.back().second));
            dq.pop_back();
        }
        dq.push_back(make_pair(prices[i], i));
    }
    while (!dq.empty()) {
        v.push_back(make_pair(dq.front().second, prices.size() - 1 - dq.front().second));
        dq.pop_front();
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].second);
    }
    return answer;
}
