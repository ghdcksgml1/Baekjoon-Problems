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

vector<pii> v;

bool cmp(pii v1, pii v2) {
    if (v1.xx == v2.xx) {
        return v1.yy < v2.yy;
    }

    return v1.xx < v2.xx;
}

int dp[102];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back({tmp1, tmp2});
    }

    sort(v.begin(), v.end(), cmp);

    // 가장 긴 증가하는 부분 수열
    int mx = 0;
    for (int i=0; i<n; i++) {
        int tmp = 0;
        for (int j=0; j<i; j++) {
            if (v[i].yy > v[j].yy) {
                tmp = max(tmp, dp[j]);
            }
        }
        dp[i] = tmp + 1;
        mx = max(mx, dp[i]);
    }

    cout << n - mx << '\n';

    return 0;
}