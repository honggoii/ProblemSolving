#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[2000001];
char ch[101];
int head, tail;
int main(void) {
	//freopen("sample.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n;
	while (n--) {
		cin >> ch;
		if (!strcmp(ch, "push")) {
			int a;
			cin >> a;
			arr[tail++] = a;
		}
		else if (!strcmp(ch, "pop")) {
			if (head != tail) {
				cout << arr[head] << '\n';
				head++;
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (!strcmp(ch, "size")) {
			cout << tail - head << '\n';
		}
		else if (!strcmp(ch, "empty")) {
			if (head == tail)
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (!strcmp(ch, "front")) {
			if (head == tail)
				cout << "-1" << '\n';
			else
				cout << arr[head] << '\n';
		}
		else if (!strcmp(ch, "back")) {
			if (head == tail)
				cout << "-1" << '\n';
			else
				cout << arr[tail - 1] << '\n';
		}
	}
	return 0;
}
