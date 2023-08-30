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

int dp[1000006];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<1000006; i++) dp[i] = 987654321;

    dp[1] = 0;
    for (int i=1; i<=n; i++){
        if (dp[i] != 987654321) {
            if ((i+1) <= n) {
                dp[i+1] = min(dp[i+1], dp[i] + 1);
            }
            if ((i*2) <= n) {
                dp[i*2] = min(dp[i*2], dp[i] + 1);
            }
            if ((i*3) <= n) {
                dp[i*3] = min(dp[i*3], dp[i] + 1);
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}