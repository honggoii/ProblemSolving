#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> fail;
    sort(stages.begin(), stages.end());
    int total = stages.size();//총 인원

    int k = 0;
    for (int i = 1; i <= N; i++) {
        int reach = 0;//stage에 도달한 사람 수
        for (int j = k; j < stages.size(); j++) {
            if (i == stages[j])
                reach++;
            else {
                k = j;
                break;
            }               
        }

        if (reach == 0) {//stage에 도달한 사람 수가 없으면
            fail.push_back(make_pair(0, i));//실패율 0
        }
        else {
            total -= reach;
            fail.push_back(make_pair(((double)reach / total), i));
        }
    }
    sort(fail.begin(), fail.end(), cmp);
    
    for (int i = 0; i < fail.size(); i++) {
        answer.push_back(fail[i].second);
    }

    return answer;
}
