#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int num;
	int cost;
} Country;
typedef struct {
	int u, v, w;
} DATA;
vector<DATA> vec;
int country[10001];//나라 정보
int n, p;//나라 수, 길 수 
int pa[10001];
int ans = 0;
int minCount = 100000000;
int find(int u) {
	if (pa[u] == u)
		return u;//통솔자가 본인이면
	pa[u] = find(pa[u]);
	return pa[u];
}
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)return false;//같은 집합
	pa[u] = v;//u를 v집합의 자식으로
	return true;
}
void unionFind() {
	for (int i = 0; i < vec.size(); i++) {
		if (merge(vec[i].u, vec[i].v)) {
			ans += vec[i].w;
		}
	}
}
bool cmp(DATA& a, DATA& b) {
	return a.w < b.w;
}
void pInit() {
	for (int i = 1; i <= n; i++)
		pa[i] = i;
}
void streetCost() {
	for (int i = 1; i <= p; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		c += country[a] + country[b] + c;//나라 방문비용+거리비용
		vec.push_back({ a,b,c });
	}
}
bool cmpCost(Country& a, Country& b) {
	return a.cost < b.cost;
}
void countryCost() {
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &country[i]);
		if (country[i] < minCount)
			minCount = country[i];
	}
}
int main() {
	scanf("%d%d", &n, &p);
	countryCost();//나라 비용 초기화
	streetCost();//거리 비용 초기화
	pInit();//통솔자 초기화
	sort(vec.begin(), vec.end(), cmp);//거리 비용 오름차순 정렬
	unionFind();//크루스칼
	printf("%d", ans + minCount);
	return 0;
}
