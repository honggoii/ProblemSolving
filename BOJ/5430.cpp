#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[400001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		deque<int> dq;
		memset(arr, 0, sizeof(arr));
		string s;
		cin >> s;
		int n;
		cin >> n;
		cin >> arr;

		char* ptr = strtok(arr, "[],");

		while (ptr != NULL) {
			dq.push_back(stoi(ptr));
			ptr = strtok(NULL, "[],");
		}
		bool flag = true;
		bool error = false;
		for (int i = 0; s[i]; i++) {
			if (s[i] == 'R') {
				//뒤집기면
				if (flag)
					flag = false;
				else
					flag = true;
			}
			else if (s[i] == 'D') {
				//버리기면
				if (dq.empty()) {
					error = true;
					break;
				}

				if (flag) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (error) {
			cout << "error" << "\n";
		}
		else {
			cout << "[";
			if (!dq.empty()) {
				if (!flag) {
					reverse(dq.begin(), dq.end());
				}

				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];

					if (i != dq.size() - 1)
						cout << ",";
				}
			}
			cout << "]" << '\n';
		}
	}
	
	return 0;
}
