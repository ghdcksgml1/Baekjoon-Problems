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

void solve(int N, int M){
    if(N == 1 || M == 1){
        cout<<1<<"\n";
    }else if(N>=3 && M>=7){
        cout<<(M-2)<<"\n";
    }else if(N == 2 && M >= 7){
        cout<<4<<"\n";
    }else if(N == 2 && M >= 5){
        cout<<3<<"\n";
    }else if(N == 2 && M >= 3){
        cout<<2<<"\n";
    }else if(N == 2 && M >= 1){
        cout<<1<<"\n";
    }else if(N >= 3 && M >= 4){
        cout<<4<<"\n";
    }else if(N >= 3 && M == 3){
        cout<<3<<"\n";
    }else if(N >= 3 && M == 2){
        cout<<2<<"\n";
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;

    solve(N,M);

    return 0;
}