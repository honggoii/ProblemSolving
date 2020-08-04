#include <iostream>
using namespace std;
int n;
int dat[100001];
int pos;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (!s.compare("push")) {
            int x;
            cin >> x;
            dat[pos++] = x;
        } 
        else if (!s.compare("pop")) {
            if (pos != 0)
                cout << dat[--pos] << '\n';
            else
                cout << -1 << '\n';
        }
        else if (!s.compare("size")) {
            cout << pos << '\n';
        }
        else if (!s.compare("empty")) {
            if (pos != 0)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
        else if (!s.compare("top")) {
            if (pos != 0)
                cout << dat[pos - 1] << '\n';
            else
                cout << -1 << '\n';
        }
    }
    return 0;
}
