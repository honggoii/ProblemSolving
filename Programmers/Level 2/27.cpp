#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    char* cptr = new char[s.size()];
    strcpy(cptr, s.c_str());
    char* ptr = strtok(cptr, " ");
    while (ptr != NULL) {
        v.push_back(stoi(ptr));
        ptr = strtok(NULL, " ");
    }
    sort(v.begin(), v.end());
    answer += to_string(v[0]) + " " + to_string(v[v.size() - 1]);
    
    return answer;
}
