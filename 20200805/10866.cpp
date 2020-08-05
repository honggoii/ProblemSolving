#include <iostream>
#include <cstring>
#define MAX 10000
using namespace std;
char ch[101];
int deq[MAX];
int front = MAX / 2;
int rear = front + 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		cin >> ch;
		if (!strcmp(ch, "push_front")) {
			int a;
			cin >> a;
			deq[front--] = a;
		}
		else if (!strcmp(ch, "push_back")) {
			int a;
			cin >> a;
			deq[rear++] = a;
		}
		else if (!strcmp(ch, "pop_front")) {
			if (rear - front == 1)
				cout << "-1" << '\n';
			else
				cout << deq[++front] << '\n';
		}
		else if (!strcmp(ch, "pop_back")) {
			if (rear - front == 1)
				cout << "-1" << '\n';
			else
				cout << deq[--rear] << '\n';
		}
		else if (!strcmp(ch, "size")) {
			cout << (rear - front) - 1 << '\n';
		}
		else if (!strcmp(ch, "empty")) {
			if (rear - front == 1)
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (!strcmp(ch, "front")) {
			if (rear - front == 1)
				cout << "-1" << '\n';
			else
				cout << deq[front + 1] << '\n';
		}
		else if (!strcmp(ch, "back")) {
			if (rear - front == 1)
				cout << "-1" << '\n';
			else
				cout << deq[rear - 1] << '\n';
		}
	}
	return 0;
}
