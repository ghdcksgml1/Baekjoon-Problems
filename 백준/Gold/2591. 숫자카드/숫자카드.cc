// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int dp[41][2];
vector<int> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        v.push_back(s[i]-'0');
    }

    if(v[1] != 0) dp[0][0] = 1;
    for(int i=1;i<v.size();i++){
        int concat = v[i-1]*10 + v[i];
        if(v[i] != 0) dp[i][0] = dp[i-1][0] + dp[i-1][1];
        if(concat <= 34 && concat>=1 && v[i-1] != 0){
            dp[i][1] = (i-2)<0 ? 1 :dp[i-2][0] + dp[i-2][1];
        }
    }

    cout<<dp[v.size()-1][0] + dp[v.size()-1][1]<<'\n';

    return 0;
}