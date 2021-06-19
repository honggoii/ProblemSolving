#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

char s[2001];
int main() {
	int idx = 1;
	while (1) {
		stack<char> st;
		memset(s, 0, sizeof(s));
		scanf("%s", s);
		int ans = 0;
		if (s[0] == '-')
			break; //탈출 조건

		for (int i = 0; s[i]; i++) {
			if (s[i] == '{') {
				st.push(s[i]);
			}
			else if (s[i] == '}') {
				if (st.empty() || st.top()=='}') {
					st.push(s[i]);
				}
				else if (st.top()=='{'){
					st.pop();
				}
			}
		}
		while(!st.empty()) {
			char tmp = st.top(); st.pop();
			if (st.top() == tmp)
				ans += 1;
			else
				ans += 2;
			st.pop();
		}
		printf("%d. %d\n", idx, ans);
		idx++;
	}
	
	return 0;
}
