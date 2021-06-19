#include <string>
#include <vector>

using namespace std;
bool visit[210];

void dfs(int n, int node, vector<vector<int>> computers) {
    visit[node] = true;
    for(int i=0; i<n; i++) {
        if (computers[node][i] == 1 && !visit[i])
            dfs(n, i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++) {
        if (!visit[i]){
            dfs(n, i, computers);
            answer++;
        }
    }
    
    return answer;
}
