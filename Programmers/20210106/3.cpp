#include <string>
#include <vector>

using namespace std;
vector<pair<int, int>> v;//다리에 올라온 트럭

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int idx = 0;//트럭 번호
    v.push_back(make_pair(1, truck_weights[idx++]));
    int now = truck_weights[0];//현재 다리 무게
    while (!v.empty()) {
        if (v.front().first >= bridge_length) {
            now -= v.front().second;//현재 다리 무게 - 다 건넌 트럭 무게
            v.erase(v.begin());
        }

        if (idx < truck_weights.size() && (now + truck_weights[idx] <= weight)) {
            now += truck_weights[idx];//현재 다리 무게 + 다리에 올라온 트럭 무게
            v.push_back(make_pair(0, truck_weights[idx]));
            idx++;//다음 트럭으로 이동
        }

        for (int i = 0; i < v.size(); i++)
            v[i].first++;

        answer++;//1초가 흐름
    }

    return answer;
}
