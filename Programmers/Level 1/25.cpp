#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> student1 {1,2,3,4,5};
    vector<int> student2 {2,1,2,3,2,4,2,5};
    vector<int> student3 {3,3,1,1,2,2,4,4,5,5};
    
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        int j = i % 5;
        int k = i % 8;
        int l = i % 10;
        
        if(answers[i] == student1[j]) cnt1++;
        if(answers[i] == student2[k]) cnt2++;
        if(answers[i] == student3[l]) cnt3++;
    }
    
    int ans = max(cnt1, max(cnt2, cnt3));
    
    if(ans == cnt1) answer.push_back(1);
    if(ans == cnt2) answer.push_back(2);
    if(ans == cnt3) answer.push_back(3);
    
    return answer;
}
