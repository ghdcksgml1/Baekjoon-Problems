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

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;
    vector<int> v0;
    vector<int> v1;

    char prev = s[0];
    for(int i=1;i<s.size();i++){
        if(prev == s[i]) continue;
        else{
            if(prev == '0') v0.push_back(0);
            else if(prev == '1') v1.push_back(1);
            prev = s[i];
        }
    }
    if(prev == '0') v0.push_back(0);
    else if(prev == '1') v1.push_back(1);

    int res = min(v0.size(),v1.size());
    cout<<res<<'\n';

    return 0;
}