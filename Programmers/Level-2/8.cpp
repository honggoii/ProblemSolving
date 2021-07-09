#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.second > b.second;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<pair<int, string>> temp;

    for (int i = 0; i < numbers.size(); i++) {
        string num = to_string(numbers[i]);
        while (num.size() <= 4)
            num += num;
        temp.push_back(make_pair(i, num));
    }

    sort(temp.begin(), temp.end(), cmp);

    if (numbers[temp[0].first] == 0) {
        answer = to_string(0);
    } 
    else {
        for (int i = 0; i < temp.size(); i++) {
            answer += to_string(numbers[temp[i].first]);
        }
    }           
    return answer;
}
