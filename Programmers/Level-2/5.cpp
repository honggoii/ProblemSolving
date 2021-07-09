#include <string>
#include <vector>

using namespace std;
bool visit[30];
int arr[30];
int answer = 0;

void comb(int idx, int cnt, int sz, vector<int> numbers, int target) {
    if (cnt == sz) {
        int sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (visit[i])
                sum += numbers[i];
            else
                sum -= numbers[i];
        }
        if (sum == target)
            answer++;
        return;
    }

    for (int i = idx; i < numbers.size(); i++) {
        if (visit[i])continue;
        visit[i] = true;
        comb(i, cnt+1, sz, numbers, target);
        visit[i] = false;
    }
}

int solution(vector<int> numbers, int target) {
    int sz = numbers.size();
    for (int i = 1; i < sz; i++) {
        comb(0, 0, i, numbers, target);
    }
    
    return answer;
}
