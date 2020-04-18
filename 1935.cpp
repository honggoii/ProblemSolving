#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char arr[101];
int num[27];

stack<double> st;

int main() {

	int n;

	scanf("%d", &n);
	
	getchar();

	scanf("%[^\n]s", arr);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	for (int j = 0; j < strlen(arr); j++) {
		if ((arr[j] == '+') || (arr[j] == '-') ||
			(arr[j] == '*') || (arr[j] == '/')) {
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();

			if ((arr[j] == '+')) {
				a += b;
				st.push(a);
			}
			else if ((arr[j] == '-')) {
				a -= b;
				st.push(a);
			}
			else if ((arr[j] == '*')) {
				a *= b;
				st.push(a);
			}
			else if ((arr[j] == '/')) {
				a /= b;
				st.push(a);
			}
		}
		else {
			st.push(num[arr[j]-65]);
		}
	}

	printf("%.2f\n", st.top());

	return 0;
}