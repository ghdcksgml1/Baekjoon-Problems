// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 60480 KB , 시간 : 52ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

ll mem[1500000]; // 피사노 주기

ll dp(int x){
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(mem[x] != 0) return mem[x];
    return mem[x] = (dp(x-1) + dp(x-2))%1000000;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n; cin>>n;
    cout<<dp(n%1500000)<<'\n';

    return 0;
}