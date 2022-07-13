// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

unordered_map<string,int> um;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;

    for(int i=1;i<=s.size();i++){
        for(int j=0;j<s.size()-i+1;j++){
            um[s.substr(j,i)] = 1;
        }
    }

    cout<<um.size()<<'\n';

    return 0;
}