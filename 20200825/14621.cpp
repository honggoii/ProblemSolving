#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int u, v, w;
} DATA;
vector<DATA> vec;
int p[2000];//통솔자
char arr[2000];//남초인지 여초인지
int find(int u) {
	if (p[u] == u)//나의 통솔자가 나면
		return u;
	else //아니면
		return p[u] = find(p[u]);//통솔자를 찾으러
}
bool merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;//사이클

	p[u] = v;
	return true;
}
bool cmp(DATA a, DATA b) {
	return a.w < b.w;
}
int main() {
	int n, m;//학교 수, 도로 수
	int cnt = 0;
	int ans = 0;
	

	scanf("%d%d", &n, &m);//학교 수, 도로 수
	for (int i = 1; i <= n; i++) {
		char c;
		scanf(" %c", &c);
		arr[i] = c;
		p[i] = i;
	}

	//도로 연결
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vec.push_back({ a,b,c });		
	}

	sort(vec.begin(), vec.end(), cmp);//정렬

	for (int i = 0; i < vec.size(); i++) {
		if (arr[vec[i].u] != arr[vec[i].v]) {//남초-여초 끼리만
			if (merge(vec[i].u, vec[i].v)) {
				ans += vec[i].w;
				cnt++;
			}
		}
	}

	if (cnt < n - 1) ans = -1;
	printf("%d", ans);
	return 0;
}
