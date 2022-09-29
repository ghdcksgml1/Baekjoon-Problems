// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

int alphabet[26];

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        alphabet[s[i] - 'A']++;
    }

    int cnt_o = 0;
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] % 2 == 1) {
            cnt_o++;
        }
    }

    if (cnt_o > 1) {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > 0) {
            for (int j = 0; j < alphabet[i] / 2; j++) {
                char c = 'A' + i;
                cout << c;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] % 2 == 1) {
            char c = 'A' + i;
            cout << c;
        }
    }

    for (int i = 25; i >= 0; i--) {
        if (alphabet[i] > 0) {
            for (int j = 0; j < alphabet[i] / 2; j++) {
                char c = 'A' + i;
                cout << c;
            }
        }
    }

    return 0;
}