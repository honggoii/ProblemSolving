#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    int arr[3] = { 4,1,2 };
    //arr[0] = 4
    //arr[1] = 1
    //arr[2] = 2
    
    while (n != 0) {
        answer += to_string(arr[n % 3]);
        if (n % 3 == 0)
            n = (n/3) - 1;
        else
            n /= 3;
    }

    reverse(answer.begin(), answer.end());
    return answer;
}
