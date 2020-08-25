#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int u, v, w;
} DATA;
vector<DATA> vec;
vector<int> temp;
int p[100001];
int n, m;//집 수, 길 수
bool cmp(DATA a, DATA b) {
	return a.w < b.w;
}
void output() {
	int ans = 0;
	for (int i = 0; i < temp.size() - 1; i++) {
		//temp맨 끝에 있는 건 가장 비싼 값
		ans += temp[i];
	}
	printf("%d", ans);
}
int find(int u) {
	if (p[u] == u)//통솔자가 본인이면
		return u;
	p[u] = find(p[u]);//통솔자 찾으러
	return p[u];
}
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;//같은 집합
	p[u] = v;//다른 집합의 자식으로
	return true;
}
void unionFind() {
	for (int i = 0; i < vec.size(); i++) {
		if (merge(vec[i].u, vec[i].v)) { //같은 집합이 아니면
			temp.push_back(vec[i].w);
		}
	}
}
void input() { 
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vec.push_back({ a,b,c });
	}
}
void pInit() {
	for (int i = 1; i <= n; i++)
		p[i] = i;//통솔자를 자신으로
}
int main() {
	scanf("%d%d", &n, &m);

	pInit();//통솔자를 자신으로
	input();//간선 연결, 가중치 부여
	sort(vec.begin(), vec.end(), cmp); //간선 오름차순 정렬
	unionFind();//하나의 트리로 묶으러
	output();//출력
	return 0;
}
