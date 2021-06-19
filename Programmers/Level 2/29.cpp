#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num = bitset<20>(n).count();
    while (num != bitset<20>(++n).count());
    answer = n;
    return answer;
}
