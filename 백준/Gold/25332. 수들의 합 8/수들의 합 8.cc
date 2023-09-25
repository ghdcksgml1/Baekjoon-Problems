// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <map>

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

vector<int> v1;
vector<int> v;
vector<int> num;
map<ll, ll> m;

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp1;
        cin >> tmp1;
        v1.push_back(tmp1);
    }

    for (int i = 0; i < n; i++) {
        int tmp2;
        cin >> tmp2;
        v.push_back(v1[i] - tmp2);
    }

    for (int i = 1; i < v.size(); i++) {
        v[i] += v[i - 1];
    }

    m[0] = 1;
    num.push_back(0);
    for (int i = 0; i < v.size(); i++) {
        if (m.find(v[i]) != m.end()) m[v[i]] += 1;
        else {
            m[v[i]] = 1;
            num.push_back(v[i]);
        }
    }

    ll ans = 0;
    for (int tmp : num) {
        if (m[tmp] >= 2) {
            ans += ((m[tmp] * (m[tmp]-1)) / 2);
        }
    }

    cout << ans << '\n';

    return 0;
}
