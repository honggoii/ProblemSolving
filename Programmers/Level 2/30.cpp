#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());//짧은 순서로 정렬
    for(int i = 0; i < phone_book.size() - 1; i++) {
        string temp = phone_book[i+1].substr(0, phone_book[i].size());
        if(phone_book[i] == temp){
            answer = false;
            break;
        }
    }
    return answer;
}
