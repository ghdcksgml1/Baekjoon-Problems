#include<iostream>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b; cin >> a >> b;
        a %= 10;
        int tmp = a % 10;
        for (int j = 1; j < b; j++) {
            a *= tmp;
            a = a % 10;
        }
        if (a == 0) {
            cout << 10 << '\n';
        }
        else {
            cout << a % 10 << '\n';
        }
    }
    return 0;
}