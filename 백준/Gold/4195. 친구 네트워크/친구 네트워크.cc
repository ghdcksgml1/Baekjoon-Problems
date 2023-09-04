// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

struct Node {
    string p; // 부모
    int x = 0; // 개수
    bool y = false; // 네트워크 이어졌는지
};

vector<pair<string, string>> v;
map<string, Node> m;

string f_p(string s) {
    if (m[s].p == s) return s;
    else {
        return m[s].p = f_p(m[s].p);
    }
}

int connect(string s1, string s2) {
    string tmp1 = f_p(s1);
    string tmp2 = f_p(s2);
    if (!m[tmp1].y && !m[tmp2].y) {
        if (tmp1 < tmp2) {
            m[tmp2].p = tmp1;
            m[tmp2].y = true;
            m[tmp1].x += m[tmp2].x;

            return m[tmp1].x;
        }
        if (tmp1 > tmp2){
            m[tmp1].p = tmp2;
            m[tmp1].y = true;
            m[tmp2].x += m[tmp1].x;

            return m[tmp2].x;
        }
    }
    return m[tmp1].x;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int T;
    cin >> T;

    while (T--) {
        int F;
        cin >> F;

        v.clear();
        m.clear();

        for (int i=0; i<F; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            v.push_back({s1, s2});
            // 초기 세팅
            m[s1] = {s1, 1, false};
            m[s2] = {s2, 1, false};
        }

        for (auto t : v) {
            cout << connect(t.xx, t.yy) << '\n';
        }
    }

    return 0;
}