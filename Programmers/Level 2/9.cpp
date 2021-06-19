#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<pair<int, int>> v;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int i = 1;
    int now = truck_weights[0];//현재 다리에 올라온 트럭 무게
    v.push_back(make_pair(1, truck_weights[0]));
    while (!v.empty()) {
        if (v.front().first >= bridge_length) {
            //맨 앞 트럭 나갈 차례
            now -= v.front().second;//나갈 트럭 무게 빼주고
            v.erase(v.begin());//트럭 내보내기         
        }

        if (i < truck_weights.size()) {
            //인덱스 범위 안에 있고
            if ((now + truck_weights[i] <= weight)) {
                //다음 트럭 올라와도 될때
                v.push_back(make_pair(0, truck_weights[i]));
                now += truck_weights[i];//올라온 트럭 무게 더하기
                i++;//다음 트럭으로
            }
        }
        for (int i = 0; i < v.size(); i++) {
            v[i].first++;//벡터 모두 1초씩 증가
        }

        answer++;
    }

    return answer;
}
