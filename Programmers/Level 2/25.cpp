#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int i = 0; i < arr1.size(); i++) {
        answer.push_back(vector<int>());
        vector<int> temp = arr1[i];
        int row = arr2[0].size();
        for (int j = 0; j < row; j++) {
            int num = 0;
            for (int k = 0; k < temp.size(); k++) {
                num += (temp[k] * arr2[k][j]);
            }
            answer[i].push_back(num);
        }
    }
    
    return answer;
}
