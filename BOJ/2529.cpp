#include <iostream>
#include <string>
using namespace std;
int k;
char sign[20];
bool num[20];
int arr[20];
string large = "";//최댓값
string small = "9999999999";//최솟값
void permutation(int cnt) {
	if (cnt == (k + 1)) {
		int j = 0;
		string tmp = to_string(arr[0]);
		bool flag = true;
		for (int i = 1; i < cnt; i++) {
			if (sign[j] == '<') {
				if (arr[i - 1] < arr[i]) {
					tmp += to_string(arr[i]);
				}
				else {
					flag = false;
					break;
				}
			}
			else if (sign[j] == '>') {
				if (arr[i - 1] > arr[i]) {
					tmp += to_string(arr[i]);
				}
				else {
					flag = false;
					break;
				}
			}
			j++;
		}

		if (flag) {
			if (tmp > large)
				large = tmp;
			if (tmp < small)
				small = tmp;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (num[i]) continue;
		num[i] = true;
		arr[cnt] = i;
		permutation(cnt + 1);
		num[i] = false;
	}
}
int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> sign[i];
	}
	permutation(0);
	cout << large << "\n";
	cout << small << "\n";
	
	return 0;
}
