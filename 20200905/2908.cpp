#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	if (stoi(a) > stoi(b))
		cout << a;
	else
		cout << b;
	return 0;
}
