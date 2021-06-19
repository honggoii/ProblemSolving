#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
queue<pair<string, int>> q;
string input;
string ans = "123456780";
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
set<string> visit;
bool range(int nx, int ny) {
	return nx >= 0 && nx < 3 && ny >= 0 && ny < 3;
}
int bfs() {
	q.push({ input, 0 });
	visit.insert(input);
	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second; q.pop();

		if (cur == ans) {
			//정답 찾으면
			return cnt;
		}

		int idx = cur.find('0');//string에서 0의 index
		int x = idx / 3;//실제 board에서 0의 x좌표
		int y = idx % 3;//실제 board에서 0의 y좌표

		for (int i = 0; i < 4; i++) {
			string nxt = cur;
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (range(nx, ny)) {
				swap(nxt[x * 3 + y], nxt[nx * 3 + ny]);//현재(x,y)와 바꿀 (x,y) 교환

				if (visit.find(nxt) == visit.end()) {
					q.push({ nxt,cnt + 1 });
					visit.insert(nxt);
				}

			}
		}
	}

	return -1;
}
void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char a;
			cin >> a;
			input += a;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();//초기화
	cout << bfs();
	
	return 0;
}
