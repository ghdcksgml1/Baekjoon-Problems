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

int dp[1001][1001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a = "", b = "";
    cin>>a>>b;

    for(int i=0;i<=a.size(); i++){
        for(int j=0;j<=b.size(); j++){
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0){
                dp[i][j] = i;
            }else{
                int trigger = a[i-1] == b[j-1] ? 0 : 1;
                dp[i][j] = min(dp[i-1][j-1] + trigger, min(dp[i][j-1] + 1, dp[i-1][j] + 1));
            }
        }
    }

    cout<<dp[a.size()][b.size()];

    return 0;
}