#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    vector<int> solo;//혼자 타야하는 애들
    int i = 0;
    int j = people.size() - 1;//뒤에서
    while (1) {
        if (people[i] + people[j] <= limit) {
            answer++;//구명보트 한 개 사용
            i++;
            j--;
        }
        else if (people[i] + people[j] > limit) {
            solo.push_back(people[j]);//j는 무조건 혼자, i는 아직 가능성 있음
            j--;//j는 무조건 혼자 
        }

        if (i >= j)
            break;
    }
    if (i == j) 
        solo.push_back(people[i]);
    answer += solo.size();
    
    return answer;
}
