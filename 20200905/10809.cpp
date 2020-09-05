#include <iostream>
#include <cstring>
using namespace std;
int arr[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(arr, -1, sizeof(arr));
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (arr[s[i] - 'a'] == -1)
			//처음 등장 할 때만
			arr[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";
	return 0;
}
