#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    int midx = arr.size() - 1;
    sort(arr.begin(), arr.end());
    for (int i = 2; i <= arr[midx]; ) {
        int cnt = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] % i == 0) {
                arr[j] /= i;
            }                
            else if ((arr[j] % i != 0) || (arr[j] == 1)) {
                cnt++;
            }
        }
        sort(arr.begin(), arr.end());
        if (cnt == arr.size()) {
            i++;
        }
        else {
            answer *= i;
        }
    }
    
    for(int i = 0; i < arr.size(); i++)
        answer *= arr[i];
    return answer;
}
