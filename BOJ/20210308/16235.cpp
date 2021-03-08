#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int x, y;
} Point;
int map[11][11];//map의 양분
vector<pair<int, int>> tree[11][11];//심어진 나무 정보(나이, 양분)
int nutrient[11][11];//양분
bool visit[11][11];//나무 심어져있는지 확인
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int n, m, k;
int ans;
void survive() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j])
				ans += tree[i][j].size();
		}
	}
}
void winter() {
	//양분 map에 뿌리기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] += nutrient[i][j];
		}
	}
}
bool range(int nx, int ny) {
	return nx >= 1 && nx <= n && ny >= 1 && ny <= n;
}
void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j]) {
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k].first % 5 == 0) {
						//나이가 5의 배수면 8방향 번식

						for (int l = 0; l < 8; l++) {
							int nx = i + dx[l];
							int ny = j + dy[l];

							if (range(nx, ny)) {
								tree[nx][ny].push_back({ 1,0 });//나이가 1짜리인 나무
								visit[nx][ny] = true;
							}
						}
					}
				}
			}
		}
	}
}
void spring() {
	//맵 훑기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j]) {
				//나무 심어져 있으면
				for (int k = 0; k < tree[i][j].size(); k++) {
					//양분 먹을 수 있는 지 확인
					if (map[i][j] >= tree[i][j][k].first) {
						//먹을 수 있으면
						tree[i][j][k].second += tree[i][j][k].first;//나이만큼 양분 먹고
						map[i][j] -= tree[i][j][k].first;//양분 감소
						tree[i][j][k].first++;//나이 한 살 증가
					}
					else {
						//시간초과 해결부분!!!!!!!!!!!!
						//못 먹으면 죽음..
						//나이순으로 정렬되어 있어서 한 번 else문에 걸리면 이후 나무들도 양분 못 먹는 게 확실
						for (int l = k; l < tree[i][j].size(); l++) {
							map[i][j] += (tree[i][j][l].first / 2);//나이/2 -> 양분으로 뿌려줌
						}
						tree[i][j].erase(tree[i][j].begin() + k, tree[i][j].end());//나무 제거
						if (tree[i][j].size() == 0)
							visit[i][j] = false;
						break;
					}
				}
			}
		}
	}
}
void treesort() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j]) {
				sort(tree[i][j].begin(), tree[i][j].end());//어린 나이 순서로 정렬
			}
		}
	}
}
void treeinfo() {
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		tree[x][y].push_back({ z,0 });
		visit[x][y] = true;//나무 위치 확인용
	}
}
void initmap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &nutrient[i][j]);
			map[i][j] = 5;//초기에는 map에 양분이 5씩 뿌려져 있어야 함
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	initmap();//(nxn) 양분 setting
	treeinfo();// m개의 나무 정보 setting
	while (k--) {
		//k년 후
		treesort();//나무들 어린 나이로 정렬
		spring();//나이만큼 양분 먹기, 나이+1, 어린 나무부터, 자신 나이만큼 못 먹으면 죽음
		fall();//나이가 5의 배수면 번식, 인접한 8개의 칸에 나이 1 나무
		winter();//양분 추가
	}
	survive();//살아 남은 나무 체크
	printf("%d", ans);
	return 0;
}
