#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    bool check[10];
    memset(check, false, sizeof(check));
    
    for(int i=0; i<arr.size(); i++) {
        if (check[arr[i]]){
            continue;
        }            
        else {
            check[arr[i-1]] = false;
            answer.push_back(arr[i]);
            check[arr[i]] = true;
        }        
    }
    
    return answer;
}
