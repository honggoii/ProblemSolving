#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map<int, int> m;  
    for (auto c : reserve) {
        m[c] += 1;
        
        for (int i = 0; i < lost.size(); i++) {
            if (m[lost[i]]) {
                m[lost[i]] -= 1;
                lost.erase(lost.begin()+i);
            }
        }
    }
    
   
    for (int i = 0; i < lost.size(); i++) {       
        if (m[lost[i]-1] || m[lost[i]+1]) {
            if(m[lost[i]-1])
                m[lost[i]-1] -= 1;
            else
                m[lost[i]+1] -= 1;
        }        
        else
            n--;
    }
    answer = n;
    
    return answer;
}
