#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        bool flag = false;
        int now = 0;
        for (int j = 0; j < skill.size(); j++) {
            for (int k = 0; k < skill_trees[i].size(); k++) {
                if (skill[j] == skill_trees[i][k]) {
                    //같은 스킬 발견
                    if (k < now) {
                        //선행 스킬을 무시한 경우
                        flag = true;
                    }
                    else {
                        now = k;//현재 인덱스 저장
                    }
                    break;
                }
                else {
                    //스킬 발견하지 못했는데 스킬 트리 끝까지 갔으면
                    if (k == skill_trees[i].size() - 1) {
                        now = skill_trees[i].size();
                    }
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            answer++;
    }
    
    return answer;
}
