#include <iostream>
#include <string>
#include <list>
using namespace std;
int m;
char op; //명령어
char ch; //추가할 문자
string s;
list<char> li;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (auto cur : s) {
		li.push_back(cur);
	}
	auto cur = li.end();
	cin >> m;
	while (m--) {
		cin >> op;
		if (op == 'L') {
			//왼쪽으로
			//맨 앞이면 무시
			if (cur != li.begin())
				cur--;
		}
		else if (op == 'D') {
			//오른쪽으로
			//맨 뒤면 무시
			if (cur != li.end())
				cur++;
		}
		else if (op == 'B') {
			//왼쪽 삭제
			//맨 앞이면 무시
			if (cur != li.begin()) {
				cur--;
				cur = li.erase(cur);
			}
			
		}
		else if (op == 'P') {
			//왼쪽에 문자 추가
			cin >> ch;
			li.insert(cur, ch);
		}
	}

	for (auto cur : li) {
		cout << cur;
	}

	return 0;
}