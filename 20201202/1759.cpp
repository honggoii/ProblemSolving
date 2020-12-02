#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int L, C;//L개 뽑기, C개의 소문자
char alpha[30];//입력받은 소문자
char sel[30];//선택받은 소문자
bool visit[30];
vector<string> v;
void permut(int idx, int cnt) {
	if (cnt == L) {
		//다 뽑았으면
		int m = 0, z = 0;//모음, 자음
		for (int i = 0; i < L; i++) {
			if (sel[i] == 'a' || sel[i] == 'e' || sel[i] == 'i'
				|| sel[i] == 'o' || sel[i] == 'u') {
				m++;
			}
			else
				z++;
		}
		if (m >= 1 && z >= 2)
			v.push_back(sel);	
		return;
	}

	for (int i = idx; i < C; i++) {
		if (visit[i]) continue;
		sel[cnt] = alpha[i];
		visit[i] = true;			
		permut(i, cnt + 1);
		visit[i] = false;
	}
}
int main() {
    scanf("%d%d", &L, &C);
	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	}
	sort(alpha, alpha + C);
	permut(0, 0);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	return 0;
}
