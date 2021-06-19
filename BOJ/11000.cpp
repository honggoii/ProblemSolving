#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;//(시작, 끝), 시작을 기준으로 오름차순 정렬
priority_queue<int, vector<int>, greater<int>> pq;//수업 중인 방, 끝나는 시간을 가지고 있음

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	freopen("sample.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		v.push_back({ s,t });
	}
	sort(v.begin(), v.end(), cmp);
	pq.push(v[0].second);
	
	for (int i = 1; i < n; i++) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);//새로운 강의실
		}
	}
	printf("%d", pq.size());//강의실 갯수
	
	return 0;
}
