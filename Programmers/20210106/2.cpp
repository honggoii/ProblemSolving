#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.second > b.second;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <pair<int, string>> v;
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(make_pair(i, to_string(numbers[i])));
        while (v[i].second.size() <= 4) {
            v[i].second += to_string(numbers[i]);
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        answer += to_string(numbers[v[i].first]);
    }

    if (answer[0] == '0')
        answer = "0";

    return answer;
}
