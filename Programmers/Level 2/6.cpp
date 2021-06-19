#include <vector>
#include <algorithm>

using namespace std;
int dp[100001][4];
int solution(vector<vector<int>> land)
{
    int answer = 0;
    int n = land.size();

    for (int i = 1; i < n; i++) {
        land[i][0] = land[i][0] + max(land[i - 1][1], max(land[i - 1][2], land[i - 1][3]));
        land[i][1] = land[i][1] + max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
        land[i][2] = land[i][2] + max(land[i - 1][0], max(land[i - 1][1], land[i - 1][3]));
        land[i][3] = land[i][3] + max(land[i - 1][0], max(land[i - 1][1], land[i - 1][2]));
    }

    answer = max(land[n - 1][0], max(land[n - 1][1], max(dp[n - 1][2], land[n - 1][3])));
    return answer;
}
