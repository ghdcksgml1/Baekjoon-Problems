// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <stack>
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

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        stack<int> st;

        string s;
        cin >> s;
        vector<char> result;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<' || s[i] == '>' || s[i] == '-') {
                switch (s[i]) {
                    case '<':
                        if (result.size() > 0) {
                            st.push(result.back());
                            result.pop_back();
                        }
                        break;
                    case '>':
                        if (st.size() > 0) {
                            result.push_back(st.top());
                            st.pop();
                        }
                        break;
                    case '-':
                        if (result.size() > 0)
                            result.pop_back();
                        break;
                }
            } else {
                result.push_back(s[i]);
            }
        }

        while (st.size() > 0) {
            result.push_back(st.top());
            st.pop();
        }

        for (auto cur: result)
            cout << cur;

        cout << "\n";
    }

    return 0;
}