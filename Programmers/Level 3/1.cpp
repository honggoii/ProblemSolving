#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<string, int> m;//<장르, 총 재생 수>
map<string, int>::iterator it;

bool cmp_genre(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;//고유번호 오름차순
    else
        return a.second > b.second;//plays 내림차순
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int sz = genres.size();
    for (int i = 0; i < sz; i++) {
        m[genres[i]] += plays[i];
    }

    vector<pair<string, int>> temp;//map을 정렬하기 전에 vector에 복사
    for (it = m.begin(); it != m.end(); ++it) {
        temp.push_back(make_pair(it->first, it->second));
    }
    sort(temp.begin(), temp.end(), cmp_genre);

    for (int i = 0; i < temp.size(); i++) {
        vector<pair<int, int>> v;//<idx, plays>
        for (int j = 0; j < sz; j++) {
            if (temp[i].first == genres[j]) {
                v.push_back(make_pair(j, plays[j]));
            }
        }
        sort(v.begin(), v.end(), cmp);
        answer.push_back(v[0].first);
        if (v.size() >= 2) {
            answer.push_back(v[1].first);
        }
    }

    return answer;
}
