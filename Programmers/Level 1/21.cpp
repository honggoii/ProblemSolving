#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long target = sqrt(n);
    if (n % target == 0)
        answer = pow(target+1, 2);
    else
        answer = -1;
    return answer;
}
