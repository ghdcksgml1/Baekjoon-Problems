// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <unordered_map>

using namespace std;
typedef long long Int;

Int N,P,Q;

unordered_map<Int, Int> um;

Int dp(Int x){
    if(x == 0) return 1;
    if(um.find(x) != um.end()) return um[x];
    return um[x] = dp(x/P) + dp(x/Q);
}


int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>P>>Q;

    cout<<dp(N)<<'\n';

    return 0;
}