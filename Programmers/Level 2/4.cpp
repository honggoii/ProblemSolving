#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int cnt[21];
int solution(string name) {
    int answer = min(name[0] - 'A', 'Z' + 1 - name[0]);
    name[0] = 'A';
    string ans;//정답

    for (int i = 0; i < name.size(); i++) {
        ans += 'A';
        cnt[i] = min(name[i] - 'A', 'Z' + 1 - name[i]);//위,아래로 움직일 경우 최솟값
    }

    int idx = 0;
    int i = 0;
    int j = 0;

    while (1) {
        if (name == ans)
            break;

        int rcnt = 0;//오른쪽 이동횟수
        int lcnt = 0;//왼쪽 이동횟수
        for (i = idx + 1; ; i++) {
            if (i >= name.length()) {
                i = idx;
                rcnt = 1e9;
                break;
            }
            rcnt++;
            if (name[i] != 'A') {
                break;
            }
        }
        for (j = idx - 1; ; j--) {   
            if (j < 0)
                j = name.length() - 1;
            lcnt++;
            if (name[j] != 'A') {
                
                break;
            }
        }

        if (rcnt <= lcnt) {
            //오른쪽으로 이동하는게 이득
            answer += (cnt[i] + rcnt);
            name[i] = 'A';
            idx = i;
        }
        else {
            answer += (cnt[j] + lcnt);
            name[j] = 'A';
            idx = j;
        }
    }

    return answer;
}
