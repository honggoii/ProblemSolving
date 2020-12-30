#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> a;
        vector<int> b;
        for (int j = 0; j < n; j++) {
            a.push_back(arr1[i] % 2);
            b.push_back(arr2[i] % 2);
            arr1[i] /= 2;
            arr2[i] /= 2;
        }
        string temp;
        for (int j = n-1; j >= 0; j--) {
            if (a[j] == 0 && b[j] == 0)
                temp += " ";
            else
                temp += "#";
        }
        answer.push_back(temp);
    }
    return answer;
}
