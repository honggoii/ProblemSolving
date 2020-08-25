#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int num;//고유번호
	int x, y, z;//좌표
} Planet;
typedef struct {
	int a, b;//두 행성
	int dis;//거리
}DATA;
int n;//행성 개수
int p[100001];
vector<Planet> vec;
vector<DATA> temp;//x,y,z좌표 임시로 넣어둘 벡터
int ans = 0;
int find(int a) {
	if (p[a] == a)
		return a;
	p[a] = find(p[a]);
	return p[a];
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return false;//같은 집합이면
	p[a] = b;//자식으로 연결
	return true;
}
bool cmpDi(DATA a, DATA b) {
	return a.dis < b.dis;
}
void unionFind() {
	sort(temp.begin(), temp.end(), cmpDi);
	for (int i = 0; i < temp.size(); i++) {
		if (merge(temp[i].a, temp[i].b)) {
			ans += temp[i].dis;
		}
	}
}
bool cmpZ(Planet a, Planet b) {
	return a.z < b.z;
}
void zDistance() {
	sort(vec.begin(), vec.end(), cmpZ);
	for (int i = 0; i < (n - 1); i++) {
		temp.push_back({ vec[i].num, vec[i + 1].num, abs(vec[i].z - vec[i + 1].z) });
	}
}
bool cmpY(Planet a, Planet b) {
	return a.y < b.y;
}
void yDistance() {
	sort(vec.begin(), vec.end(), cmpY);
	for (int i = 0; i < (n - 1); i++) {
		temp.push_back({ vec[i].num, vec[i + 1].num,abs(vec[i].y - vec[i + 1].y) });
	}
}
bool cmpX(Planet a, Planet b) {
	return a.x < b.x;
}
void xDistance() {
	sort(vec.begin(), vec.end(), cmpX);
	for (int i = 0; i < (n-1); i++) {
		temp.push_back({ vec[i].num, vec[i + 1].num,abs(vec[i].x - vec[i + 1].x) });
	}
}
void input() {
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vec.push_back({ i,a,b,c });
	}
}
void pInit() {
	for (int i = 1; i <= n; i++)
		p[i] = i;
}
int main() {
	scanf("%d", &n);//행성 개수
	pInit();//초기화
	input();//입력
	xDistance();//x좌표 오름차순
	yDistance();//y좌표 오름차순
	zDistance();//z좌표 오름차순
	unionFind();//최소 신장 트리 만들러
	printf("%d", ans);
	return 0;
}
