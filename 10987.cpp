#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
	freopen("sample.txt", "r", stdin);
	
	string str;
	cin >> str;
	int cnt = 0;

	for (int i = 0; i < str.length(); i++) {
		if ((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i')
			|| (str[i] == 'o') || (str[i] == 'u'))
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}