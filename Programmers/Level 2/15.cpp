#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size() - 1;
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations[n]; i++) {
        for (int j = 0; j < n; j++) {
            if ((i <= citations[j]) && (i <= (n - j + 1))) {
                if (answer <= i)
                    answer = i;
            }                
        }
    }
    return answer;
}
