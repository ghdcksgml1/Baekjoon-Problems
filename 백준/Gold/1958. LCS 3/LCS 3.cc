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

int dp[101][101][101];
vector<char> v[3];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s[3]; cin>>s[0]>>s[1]>>s[2];
    for(int i=0; i<3; i++){
        v[i].push_back(' ');
        for(int j=0; j<s[i].size(); j++){
            v[i].push_back(s[i][j]);
        }
    }

    for(int i=1; i<v[0].size(); i++){
        for(int j=1; j<v[1].size(); j++){
            for(int k=1; k<v[2].size(); k++){
                if(v[0][i] == v[1][j] && v[0][i] == v[2][k] && v[1][j] == v[2][k]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }else
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
            }
        }
    }

    cout<<dp[v[0].size()-1][v[1].size()-1][v[2].size()-1]<<'\n';

    return 0;
}