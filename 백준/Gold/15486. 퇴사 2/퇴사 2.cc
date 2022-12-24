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

int dp[1600001];
vector<pii > v;

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int t, p;
        cin >> t >> p;
        v.push_back({t, p});
    }

    for (int i = 0; i <= N; i++) {
        if(i != 0) dp[i] = max(dp[i], dp[i-1]);
        if(i == N) break;
        dp[i + v[i].first] = max(dp[i + v[i].first], dp[i] + v[i].second);
//        cout<<"dp[i]: "<<dp[i]<<","<<i + v[i].first - 1<<"\n";
    }

    cout<<dp[N];

    return 0;
}