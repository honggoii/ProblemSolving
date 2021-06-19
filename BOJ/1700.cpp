#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
bool visit[101];//꽂혀있는지 체크
int goods[101];//전기 용품
int tap[101];//멀티탭에 꽂은 전기 용품
int ans;
vector<pair<int, int>>v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &goods[i]);
	}

	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (visit[goods[i]]) {
			//멀티탭에 꽂혀있으면
			continue;
		}
		else {
			//멀티탭에 꽂혀 있지 않으면
			if (cnt < n) {
				//멀티탭이 남으면 
				visit[goods[i]] = true; //꼽는다.
				tap[cnt] = goods[i];
				cnt++;
			}
			else {
				//멀티탭이 안 남으면 나중에 사용할 것을 뽑는다.
				v.clear();
				for (int j = 0; j < cnt; j++) {
					v.push_back({ j,1e9 });
					for (int l = i + 1; l < k; l++) {
						if (goods[l] == tap[j]) {
							v[j].second = l;
							break;
						}
					}
					
				}
				sort(v.begin(), v.end(), cmp);
				visit[tap[v[0].first]] = false;//뽑기
				tap[v[0].first] = goods[i];//내꺼 꼽기
				visit[goods[i]] = true;
				ans++;//뽑은 횟수
			}
		}
	}
	printf("%d", ans);
	
	return 0;
}
